//========= FF Grenade Port ===============================================//
//
// Ported from ff-src/mp/src/game/client/ff/fx/ff_fx_napalm_emitter.cpp AND
// ff_fx_grenades.cpp (FF_FX_NapalmBurst/NapalmBurstCallback specifically --
// that file also has concussion/EMP effects that belong to their own
// grenade types, not ported here). Original: FF, Shawn Smith "L0ki",
// Apr. 30 2005.
//
// This whole system was orphaned in ff-src's current state: the emitter
// class and its "NapalmBurst" named effect both exist and are complete,
// but nothing in ff-src's own server-side grenade code actually dispatches
// "NapalmBurst" anymore (checked the whole server+shared tree, confirmed
// zero matches) -- likely lost during FF's own SDK2006->SDK2013CE port,
// which barely touched anything fire-related (see the c_fire_smoke.cpp
// history from the napalm particle investigation). The dispatch is added
// back in ff_grenade_napalm.cpp's Explode(), matching how
// CFFGrenadeConcussion::Explode() already dispatches its own effect in
// this exact port (DispatchEffect(CONCUSSION_EFFECT, data)) -- same
// pattern, not a new one.
//
// Changed from FF's real source: dropped m_hHeatwaveMaterial and the
// heat-shimmer particle it would drive -- see the .h for why (the code
// using it is commented out in FF's own real source, and the material
// has no .vmt in ff-game, only a .vtf). Everything else -- the emitter
// class, the burst pattern, the flame sprite-sheet animation -- is
// unchanged from FF's real, original implementation.
//
//===========================================================================//

#include "cbase.h"
#include "clienteffectprecachesystem.h"
#include "particles_simple.h"
#include "particle_util.h"
#include "c_te_effect_dispatch.h"
#include "cliententitylist.h"
#include "ff_fx_napalm_emitter.h"

//========================================================================
// Static material handles
//========================================================================
PMaterialHandle CNapalmEmitter::m_hMaterial		= INVALID_MATERIAL_HANDLE;
PMaterialHandle CNapalmEmitter::m_hFlameMaterial	= INVALID_MATERIAL_HANDLE;

//========================================================================
// material strings
//========================================================================
#define NAPALM_PARTICLE_MATERIAL	"particle/fire"
#define NAPALM_FLAME_MATERIAL		"sprites/napalm_flame2"

//========================================================================
// texture coordinates for the flame
//							  minX  maxX   minY  maxY
//========================================================================
float flame_tex_coords[][4] =
{
	{ 0.0f,		0.125f,	0.0f, 0.5f},	//frame 0
	{ 0.125f,	0.25f,	0.0f, 0.5f},	//frame 1
	{ 0.25f,	0.375f,	0.0f, 0.5f},	//frame 2
	{ 0.375f,	0.5f,	0.0f, 0.5f},	//frame 3
	{ 0.5f,		0.625f,	0.0f, 0.5f},	//frame 4
	{ 0.625f,	0.75f,	0.0f, 0.5f},	//frame 5
	{ 0.75f,	0.875f,	0.0f, 0.5f},	//frame 6
	{ 0.875f,	1.0f,	0.0f, 0.5f},	//frame 7
	{ 0.0f,		0.125f,	0.5f, 1.0f},	//frame 8
	{ 0.125f,	0.25f,	0.5f, 1.0f},	//frame 9
	{ 0.25f,	0.375f,	0.5f, 1.0f},	//frame 10
	{ 0.375f,	0.5f,	0.5f, 1.0f},	//frame 11
	{ 0.5f,		0.625f,	0.5f, 1.0f},	//frame 12
	{ 0.625f,	0.75f,	0.5f, 1.0f}		//frame 13
};
#define NUM_FLAME_FRAMES	14
ConVar nap_burst_flame_framerate("ffdev_nap_burst_flame_framerate","12", FCVAR_CHEAT,"Framerate of the fire \"sprites\".");

//========================================================================
// Client effect precache table
//========================================================================
CLIENTEFFECT_REGISTER_BEGIN( PrecacheNapalmBurst )
	CLIENTEFFECT_MATERIAL( NAPALM_PARTICLE_MATERIAL )
	CLIENTEFFECT_MATERIAL( NAPALM_FLAME_MATERIAL )
CLIENTEFFECT_REGISTER_END()

//========================================================================
// Development ConVars
//========================================================================
ConVar nap_burst_scale("ffdev_nap_burst_scale","10", FCVAR_CHEAT,"Napalm burst scale");
ConVar nap_burst_dietime("ffdev_nap_burst_dietime","3.0", FCVAR_CHEAT,"Napalm burst particle dietime");
ConVar nap_burst_flame_scale("ffdev_nap_burst_flame_scale","16.0", FCVAR_CHEAT,"Scale of the flame sprites");
ConVar nap_burst_flame_time("ffdev_nap_burst_flame_time","5.0", FCVAR_CHEAT,"Burn time for flames");
ConVar nap_burst_gravity("ffdev_nap_burst_gravity","-500.0", FCVAR_CHEAT,"Gravity magnitude for the napalm burst");
ConVar nap_burst_vel("ffdev_nap_burst_vel","475", FCVAR_CHEAT,"Velocity of the napalm particles.");
ConVar nap_burst_vel_z_divisor("ffdev_nap_burst_vel_z_divisor","2.0", FCVAR_CHEAT,"How much to divide the linear velocity for napalm particles by for the vertical velocity.");

//========================================================================
// CNapalmEmitter constructor
//========================================================================
CNapalmEmitter::CNapalmEmitter( const char *pDebugName ) : CParticleEffect( pDebugName )
{
	m_pDebugName = pDebugName;

	m_flNearClipMin	= 16.0f;
	m_flNearClipMax	= 64.0f;
	m_vGravity = Vector(0,0,0);
	m_flGravityMagnitude = 0;
}

//========================================================================
// CNapalmEmitter destructor
//========================================================================
CNapalmEmitter::~CNapalmEmitter()
{
}

//========================================================================
// CNapalmEmitter::Create
// ----------------------
// Purpose: Creates a new instance of a CNapalmEmitter object
//========================================================================
CSmartPtr<CNapalmEmitter> CNapalmEmitter::Create( const char *pDebugName )
{
	CNapalmEmitter *pRet = new CNapalmEmitter( pDebugName );
	pRet->SetDynamicallyAllocated( true );
	if(m_hMaterial == INVALID_MATERIAL_HANDLE)
		m_hMaterial = pRet->GetPMaterial(NAPALM_PARTICLE_MATERIAL);
	if(m_hFlameMaterial == INVALID_MATERIAL_HANDLE)
		m_hFlameMaterial = pRet->GetPMaterial(NAPALM_FLAME_MATERIAL);
	return pRet;
}

//========================================================================
// AddNapalmParticle
// -----------------
// Purpose: Adds a new NapalmParticle to the system
//========================================================================
NapalmParticle*	CNapalmEmitter::AddNapalmParticle( const Vector &vOrigin )
{
	NapalmParticle *pRet = (NapalmParticle*)AddParticle( sizeof( NapalmParticle ), m_hMaterial, vOrigin );
	if ( pRet )
	{
		pRet->m_iType = eNapalmParticle;
		pRet->m_vVelocity.Init();
		pRet->m_flDieTime = nap_burst_dietime.GetFloat();
		pRet->m_flLifetime = 0;
		pRet->m_uchColor[0] = 255;
		pRet->m_uchColor[1] = 160;
		pRet->m_uchColor[2] = 0;
		pRet->m_bStartFire = true;
		pRet->m_bIsAttachedFlame = false;
	}

	return pRet;
}

//========================================================================
// SetGravity
// ----------
// Purpose: Sets the gravity vector and magnitude for this system
//========================================================================
void CNapalmEmitter::SetGravity(const Vector &vGravity, float flGravityMagnitude)
{
	m_vGravity = vGravity;
	VectorNormalize(m_vGravity);
	m_flGravityMagnitude = flGravityMagnitude;
}

//========================================================================
// ApplyGravity
// --------------
// Purpose: Applies gravity to the specified particle's velocity
//========================================================================
void CNapalmEmitter::ApplyGravity( NapalmParticle *pParticle, float timeDelta )
{
	if(pParticle->m_iType == eNapalmFlame)
		return;
	// apply gravity to this particle
	Vector vGravity = (m_vGravity * (m_flGravityMagnitude * timeDelta));
	pParticle->m_vVelocity += vGravity;
}

//========================================================================
// SimulateParticles
// ----------
// Purpose: Handles adjusting particle properties as time progresses as
//			well as removing dead particles
//========================================================================
void CNapalmEmitter::SimulateParticles( CParticleSimulateIterator *pIterator )
{
	float timeDelta = pIterator->GetTimeDelta();

	NapalmParticle *pParticle = (NapalmParticle*)pIterator->GetFirst();
	while ( pParticle )
	{
		pParticle->m_flLifetime += timeDelta;

		// Kill this particle if it's hit water
		if (UTIL_PointContents(pParticle->m_Pos) & (CONTENTS_SLIME|CONTENTS_WATER))
		{
			pParticle->m_flLifetime = pParticle->m_flDieTime;
		}

		if ( pParticle->m_flLifetime >= pParticle->m_flDieTime )
		{
			pIterator->RemoveParticle( pParticle );
		}
		else if ( pParticle->m_bIsAttachedFlame )
		{
			// FF Grenade Port: gib-attached flame -- track the entity's current
			// position every frame instead of the normal ember simulation below
			// (this particle is already a flame, not falling debris). No fixed
			// lifetime for these; removed the instant the entity they're
			// following is gone, whatever that entity's own lifetime turns out
			// to be (m_flDieTime is set very high as a safety net only).
			CBaseEntity *pFollowEntity = pParticle->m_hFollowEntity.Get();
			if ( pFollowEntity )
			{
				pParticle->m_Pos = pFollowEntity->GetAbsOrigin();
			}
			else
			{
				pIterator->RemoveParticle( pParticle );
			}
		}
		else
		{
			if(pParticle->m_iType == eNapalmParticle)
			{
				ApplyGravity( pParticle, timeDelta );
				//if this particle has moved outside of the grenade explosion readius, make it drop straight down
				// yes, its lame, but it works
				Vector displacement = m_vSortOrigin - (pParticle->m_Pos + pParticle->m_vVelocity * timeDelta);
				if(displacement.Length() > 180.0f)
				{
					pParticle->m_vVelocity.x = 0;
					pParticle->m_vVelocity.y = 0;
				}
				pParticle->m_Pos += pParticle->m_vVelocity * timeDelta;

				trace_t tr;
				UTIL_TraceLine(
					pParticle->m_Pos,
					pParticle->m_Pos + (pParticle->m_vVelocity * 0.1),
					MASK_SOLID,
					NULL,
					COLLISION_GROUP_NONE,
					&tr
					);
				if(tr.fraction != 1.0)
				{
					pParticle->m_vVelocity.x = 0;
					pParticle->m_vVelocity.y = 0;
					if(pParticle->m_bStartFire)
					{
						pIterator->RemoveParticle(pParticle);
						StartFire(tr.endpos);
					}
				}
			}
		}

		pParticle = (NapalmParticle*)pIterator->GetNext();
	}
}

// Render a quad on the screen where you pass in color and size.
inline void RenderParticle_ColorSizeFrame(
									 ParticleDraw* pDraw,									
									 const Vector &pos,
									 const unsigned char ubColor[4],
									 const float size,
									 const int frame
									 )
{
	// Don't render totally transparent particles.
	if (ubColor[3] < 1)
		return;

	CMeshBuilder *pBuilder = pDraw->GetMeshBuilder();
	if( !pBuilder )
		return;

	// Add the 4 corner vertices.
	pBuilder->Position3f( pos.x-size, pos.y, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->TexCoord2f( 0, flame_tex_coords[frame][0], flame_tex_coords[frame][3] );
	pBuilder->AdvanceVertex();

	pBuilder->Position3f( pos.x-size, pos.y+size * 4, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->TexCoord2f( 0, flame_tex_coords[frame][0], flame_tex_coords[frame][2] );
	pBuilder->AdvanceVertex();

	pBuilder->Position3f( pos.x+size, pos.y+size * 4, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->TexCoord2f( 0, flame_tex_coords[frame][1], flame_tex_coords[frame][2] );
	pBuilder->AdvanceVertex();

	pBuilder->Position3f( pos.x+size, pos.y, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->TexCoord2f( 0, flame_tex_coords[frame][1], flame_tex_coords[frame][3] );
	pBuilder->AdvanceVertex();
}

//========================================================================
// RenderParticles
// ----------
// Purpose: Renders all the particles in the system
//========================================================================
void CNapalmEmitter::RenderParticles( CParticleRenderIterator *pIterator )
{
	const NapalmParticle *pParticle = (const NapalmParticle *)pIterator->GetFirst();
	while ( pParticle )
	{
		//Render
		Vector	tPos;

		TransformParticle( ParticleMgr()->GetModelView(), pParticle->m_Pos, tPos );
		float sortKey = (int) tPos.z;

		//Render it
		if (pParticle->m_iType == eNapalmParticle)
		{
			Vector vColor = Vector(pParticle->m_uchColor[0] / 255.0f,
				pParticle->m_uchColor[1] / 255.0f,
				pParticle->m_uchColor[2] / 255.0f);

			RenderParticle_ColorSize(
				pIterator->GetParticleDraw(),
				tPos,
				vColor,
				192,
				nap_burst_scale.GetFloat()
				);
		}
		else if(pParticle->m_iType == eNapalmFlame)
		{
			int frame = Float2Int(pParticle->m_flLifetime * nap_burst_flame_framerate.GetFloat());

			// Is this quicker than modulas?
			while (frame >= NUM_FLAME_FRAMES)
				frame -= NUM_FLAME_FRAMES;

			float flDie = clamp(pParticle->m_flDieTime - pParticle->m_flLifetime, 0.0f, 1.0f);

			RenderParticle_ColorSizeFrame(
				pIterator->GetParticleDraw(),
				tPos,
				pParticle->m_uchColor,
				pParticle->m_flScale * flDie,
				frame
				);
		}
		// FF Grenade Port: eHeatwave case dropped along with m_hHeatwaveMaterial --
		// see .h. The enum value stays (harmless, and matches FF's real enum) but
		// nothing ever creates a particle of that type anymore.

		pParticle = (const NapalmParticle *)pIterator->GetNext( sortKey );
	}
}

void CNapalmEmitter::StartFire(const Vector &pos)
{
	NapalmParticle *pFireParticle = (NapalmParticle*)AddParticle( sizeof( NapalmParticle ), m_hFlameMaterial,pos );
	if ( pFireParticle )
	{
		pFireParticle->m_iType = eNapalmFlame;
		pFireParticle->m_Pos = pos;
		pFireParticle->m_vVelocity.Init();
		pFireParticle->m_flLifetime = 0;
		pFireParticle->m_flDieTime = nap_burst_flame_time.GetFloat() * random->RandomFloat(0.7f, 1.3f);
		pFireParticle->m_uchColor[0] = 255;
		pFireParticle->m_uchColor[1] = 
		pFireParticle->m_uchColor[2] = random->RandomInt(160, 255);
		pFireParticle->m_uchColor[3] = random->RandomInt(230, 250);
		pFireParticle->m_bStartFire = false;
		pFireParticle->m_bIsAttachedFlame = false;
		pFireParticle->m_flScale = nap_burst_flame_scale.GetFloat() * random->RandomFloat(0.7f, 1.3f);
	}
}

//========================================================================
// StartAttachedFire
// ------------------
// Purpose: same visual as StartFire, but tracks pFollowEntity's position
// every frame (see SimulateParticles) instead of sitting still. Used for
// napalmlet gibs -- see ff_grenade_napalmlet.cpp for the dispatch side.
//========================================================================
void CNapalmEmitter::StartAttachedFire( CBaseEntity *pFollowEntity )
{
	if ( !pFollowEntity )
		return;

	Vector pos = pFollowEntity->GetAbsOrigin();
	NapalmParticle *pFireParticle = (NapalmParticle*)AddParticle( sizeof( NapalmParticle ), m_hFlameMaterial, pos );
	if ( pFireParticle )
	{
		pFireParticle->m_iType = eNapalmFlame;
		pFireParticle->m_Pos = pos;
		pFireParticle->m_vVelocity.Init();
		pFireParticle->m_flLifetime = 0;
		// FF Grenade Port: not tied to nap_burst_flame_time like a ground fire --
		// this should burn as long as the gib exists. Set generously high; actual
		// removal happens the instant m_hFollowEntity goes invalid (see
		// SimulateParticles), this is just a safety net against a particle
		// leaking forever if that somehow doesn't happen.
		pFireParticle->m_flDieTime = 60.0f;
		pFireParticle->m_uchColor[0] = 255;
		pFireParticle->m_uchColor[1] = 
		pFireParticle->m_uchColor[2] = random->RandomInt(160, 255);
		pFireParticle->m_uchColor[3] = random->RandomInt(230, 250);
		pFireParticle->m_bStartFire = false;
		pFireParticle->m_bIsAttachedFlame = true;
		pFireParticle->m_hFollowEntity = pFollowEntity;
		pFireParticle->m_flScale = nap_burst_flame_scale.GetFloat() * random->RandomFloat(0.7f, 1.3f);
	}
}

//========================================================================
// FF_FX_NapalmBurst / NapalmBurstCallback
// ----------------------------------------
// Ported from ff_fx_grenades.cpp (the concussion/EMP effects in that same
// file belong to their own grenade types and aren't ported here). This is
// what ff_grenade_napalm.cpp's Explode() dispatches -- see that file for
// the server-side DispatchEffect("NapalmBurst", data) call.
//========================================================================
void FF_FX_NapalmBurst( Vector &origin )
{
	float radius = 180.0f;
	CSmartPtr<CNapalmEmitter> pEmitter = CNapalmEmitter::Create("NapalmBurst");
	if(pEmitter == NULL)
		return;
	pEmitter->SetSortOrigin(origin);

	pEmitter->SetGravity( Vector(0,0,1), nap_burst_gravity.GetFloat() );

	NapalmParticle *pParticle = NULL;
	QAngle angle;
	Vector forward, right, up, velocity;

	//psuedo random burst pattern
	for(float r=radius, offset=0; r>0; r -= 45, offset++)
	{
		int iAngleSeed = RandomInt(0,360);
		for(int iAngle = iAngleSeed; iAngle < (iAngleSeed + 360); iAngle += 60)
		{
			pParticle = pEmitter->AddNapalmParticle(origin);
			if(pParticle)
			{
				angle.x = RandomFloat(45,67.5);
				angle.y = (offset*30) + iAngle;
				angle.z = 0;
				AngleVectors(angle, &forward, &right, &up);

				velocity = forward * (nap_burst_vel.GetFloat() * ((r) / radius));
				velocity.z = RandomFloat(100.0f,nap_burst_vel.GetFloat()/nap_burst_vel_z_divisor.GetFloat());
				pParticle->m_vVelocity = velocity;
				if(random->RandomInt(0,1))
					pParticle->m_bReverseSize = true;
				else
					pParticle->m_bReverseSize = false;
			}
		}
	}
}

void NapalmBurstCallback(const CEffectData &data)
{
	Vector origin = data.m_vOrigin;
	FF_FX_NapalmBurst(origin);
}

DECLARE_CLIENT_EFFECT( "NapalmBurst", NapalmBurstCallback )

//========================================================================
// NapalmletFlameCallback
// -----------------------
// Purpose: dispatched once per napalmlet gib at spawn (ff_grenade_napalmlet.cpp,
// GAME_DLL side) so its fire visually stays on the gib as it tumbles, instead
// of the burst embers' independent ballistic paths. Looks up the specific
// entity via data.entindex() -- works without napalmlet needing any custom
// client-side class, since every networked entity (even with just the
// generic engine-provided client proxy) is reachable this way.
//========================================================================
void NapalmletFlameCallback(const CEffectData &data)
{
	C_BaseEntity *pEntity = ClientEntityList().GetEnt( data.entindex() );
	if ( !pEntity )
		return;

	CSmartPtr<CNapalmEmitter> pEmitter = CNapalmEmitter::Create("NapalmletFlame");
	if ( pEmitter == NULL )
		return;

	pEmitter->SetSortOrigin( pEntity->GetAbsOrigin() );
	pEmitter->StartAttachedFire( pEntity );
}

DECLARE_CLIENT_EFFECT( "NapalmletFlame", NapalmletFlameCallback )
