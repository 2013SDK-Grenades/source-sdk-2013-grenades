#include "cbase.h"
#include "ff_grenade_base.h"

#include "ff_grenade_napalmlet.h"
#include "ff_utils.h"

// FF Grenade Port: CFFPlayer -> CTFPlayer. We're not porting ff_player.cpp, so this
// pulls in TF2's own player class instead. baseobject_shared.h replaces FF's buildable
// headers for the sentry/dispenser damage case below, same TF2-native pattern used in
// the earlier ff_grenade_laser.cpp/ff_grenade_nail.cpp buildables rewrite.
#include "tf_player.h"
#include "baseobject_shared.h"
#include "te_effect_dispatch.h"

//ConVar ffdev_nap_bonusdamage_burn1("ffdev_nap_bonusdamage_burn1", "0", FCVAR_REPLICATED | FCVAR_CHEAT);
#define NAP_BONUSDAMAGE_BURN1 0 //ffdev_nap_bonusdamage_burn1.GetInt()
//ConVar ffdev_nap_bonusdamage_burn2("ffdev_nap_bonusdamage_burn2", "1", FCVAR_REPLICATED | FCVAR_CHEAT);
#define NAP_BONUSDAMAGE_BURN2 1 //ffdev_nap_bonusdamage_burn2.GetInt()
//ConVar ffdev_nap_bonusdamage_burn3("ffdev_nap_bonusdamage_burn3", "2", FCVAR_REPLICATED | FCVAR_CHEAT);
#define NAP_BONUSDAMAGE_BURN3 2 //ffdev_nap_bonusdamage_burn3.GetInt()

//ConVar burn_standon_ng("ffdev_burn_standon_ng", "7.0", 0, "Damage you take when standing on a burning napalmlet");
//ConVar ffdev_nap_flamesize("ffdev_nap_flamesize", "30.0", 0, "Napalmlet flame size");
#define FFDEV_NAP_FLAMESIZE 30.0f //ffdev_nap_flamesize.GetFloat() // 50.0f
//ConVar nap_burn_radius("ffdev_nap_burn_radius","70.0",FCVAR_FF_FFDEV,"Burn radius of a napalmlet.");
#define NAP_BURN_RADIUS 70.0f //nap_burn_radius.GetFloat() //98.0f

//ConVar ffdev_nap_burnamount("ffdev_nap_burnamount", "10.0", 0, "Napalmlet burn increase per tick, 100 is a full burn level");
#define FFDEV_NAPALM_BURNAMOUNT 10.0f //ffdev_nap_burnamount.GetFloat() // 50.0f
//ConVar ffdev_nap_height("ffdev_nap_height", "70.0", 0, "Napalmlet maximum burn height above the ground");
#define FFDEV_NAP_HEIGHT 70.0f //ffdev_nap_height.GetFloat() // 50.0f

#define BURN_STANDON_NG 2

BEGIN_DATADESC( CFFGrenadeNapalmlet )
	DEFINE_THINKFUNC( FlameThink ),
END_DATADESC()


LINK_ENTITY_TO_CLASS( ff_grenade_napalmlet, CFFGrenadeNapalmlet );
PRECACHE_WEAPON_REGISTER( ff_grenade_napalmlet );


void CFFGrenadeNapalmlet::UpdateOnRemove( void )
{
	StopSound( "General.BurningFlesh" );
	StopSound( "General.BurningObject" );

	BaseClass::UpdateOnRemove();
}

//-----------------------------------------------------------------------------
// Purpose: Precache assets
//-----------------------------------------------------------------------------
void CFFGrenadeNapalmlet::Precache ( void )
{
	PrecacheModel( NAPALMLET_MODEL );
	BaseClass::Precache();
}

//-----------------------------------------------------------------------------
// Purpose: Spawn
//-----------------------------------------------------------------------------
void CFFGrenadeNapalmlet::Spawn( void )
{
	BaseClass::Spawn();

	SetModel ( NAPALMLET_MODEL );
	SetAbsAngles( QAngle( 0, 0, 0 ) );
	SetSolidFlags( FSOLID_TRIGGER | FSOLID_NOT_STANDABLE );
	SetMoveType( MOVETYPE_FLYGRAVITY, MOVECOLLIDE_FLY_CUSTOM );
	SetSolid( SOLID_BBOX );
	SetCollisionGroup( COLLISION_GROUP_DEBRIS );
	SetSize( Vector ( -5, -5, -5 ), Vector ( 5, 5, 5 ) );
	SetThink( &CFFGrenadeNapalmlet::FlameThink );
	SetNextThink( gpGlobals->curtime );
	SetEffects(EF_NOSHADOW);

	m_pFlame = CEntityFlame::Create( this, false );
	if (m_pFlame)
	{
		m_pFlame->SetLifetime( m_flBurnTime );
		AddFlag( FL_ONFIRE );
		SetEffectEntity( m_pFlame );
		m_pFlame->SetSize( FFDEV_NAP_FLAMESIZE );
	}
}


//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CFFGrenadeNapalmlet::ResolveFlyCollisionCustom( trace_t &trace, Vector &vecVelocity )
{
	//Assume all surfaces have the same elasticity
	float flSurfaceElasticity = 1.0;

	//Don't bounce off of players with perfect elasticity
	if( trace.m_pEnt && trace.m_pEnt->IsPlayer() )
	{
		flSurfaceElasticity = 0.3;
	}

	// if its breakable glass and we kill it, don't bounce.
	// give some damage to the glass, and if it breaks, pass 
	// through it.
	bool breakthrough = false;

	if (trace.m_pEnt && ( FClassnameIs(trace.m_pEnt, "func_breakable") || FClassnameIs(trace.m_pEnt, "func_breakable_surf") ) )
	{
		breakthrough = true;
	}

	if (breakthrough)
	{
		CTakeDamageInfo info( this, GetOwnerEntity(), 10, DMG_CLUB );
		trace.m_pEnt->DispatchTraceAttack( info, GetAbsVelocity(), &trace );

		ApplyMultiDamage();

		if( trace.m_pEnt->m_iHealth <= 0 )
		{
			// slow our flight a little bit
			Vector vel = GetAbsVelocity();

			vel *= 0.4;

			SetAbsVelocity( vel );
			return;
		}
	}

	float flTotalElasticity = GetElasticity() * flSurfaceElasticity;
	flTotalElasticity = clamp( flTotalElasticity, 0.0f, 0.9f );

	// NOTE: A backoff of 2.0f is a reflection
	Vector vecAbsVelocity;
	PhysicsClipVelocity( GetAbsVelocity(), trace.plane.normal, vecAbsVelocity, 2.0f );
	vecAbsVelocity *= flTotalElasticity;

	// Get the total velocity (player + conveyors, etc.)
	VectorAdd( vecAbsVelocity, GetBaseVelocity(), vecVelocity );
	float flSpeedSqr = DotProduct( vecVelocity, vecVelocity );

	// Stop if on ground.
	if ( trace.plane.normal.z > 0.7f )			// Floor
	{
		// Verify that we have an entity.
		CBaseEntity *pEntity = trace.m_pEnt;
		Assert( pEntity );

		SetAbsVelocity( vecAbsVelocity );

		if ( flSpeedSqr < ( 30 * 30 ) )
		{
			if ( pEntity->IsStandable() )
			{
				SetGroundEntity( pEntity );
			}

			// Reset velocities.
			SetAbsVelocity( vec3_origin );
			SetLocalAngularVelocity( vec3_angle );	
		}
		else
		{
			Vector vecDelta = GetBaseVelocity() - vecAbsVelocity;	
			Vector vecBaseDir = GetBaseVelocity();
			VectorNormalize( vecBaseDir );
			float flScale = vecDelta.Dot( vecBaseDir );

			VectorScale( vecAbsVelocity, ( 1.0f - trace.fraction ) * gpGlobals->frametime, vecVelocity ); 
			VectorMA( vecVelocity, ( 1.0f - trace.fraction ) * gpGlobals->frametime, GetBaseVelocity() * flScale, vecVelocity );
			PhysicsPushEntity( vecVelocity, &trace );
		}
	}
	else
	{
		// If we get *too* slow, we'll stick without ever coming to rest because
		// we'll get pushed down by gravity faster than we can escape from the wall.
		if ( flSpeedSqr < ( 30 * 30 ) )
		{
			// Reset velocities.
			SetAbsVelocity( vec3_origin );
			SetLocalAngularVelocity( vec3_angle );
		}
		else
		{
			SetAbsVelocity( vecAbsVelocity );
		}
	}
}

//-----------------------------------------------------------------------------
// Purpose: Burninate the players
//-----------------------------------------------------------------------------
void CFFGrenadeNapalmlet::FlameThink()
{
	// FF Grenade Port: dispatched here instead of Spawn(). Spawn() runs at the
	// exact instant the entity is created server-side -- dispatching the
	// attached-flame effect that same instant risked it reaching clients
	// before their own copy of this entity existed yet (NapalmletFlameCallback
	// looks the entity up by entindex via ClientEntityList().GetEnt(), which
	// silently returns NULL/no-ops if that entity isn't there yet -- no error,
	// just nothing happens, which is exactly what "fire never appears" looks
	// like). FlameThink() firing means at least one full server tick has
	// already passed, giving the network far more room for the entity to have
	// actually arrived first.
	if ( !m_bDispatchedFlameEffect )
	{
		m_bDispatchedFlameEffect = true;

		CEffectData data;
		data.m_nEntIndex = entindex();
		DispatchEffect( "NapalmletFlame", data );

		// FF Grenade Port: diagnostic only, remove once confirmed working.
		Msg( "[FF Grenade Port] napalmlet entindex %d dispatched NapalmletFlame\n", entindex() );
	}

	// Remove if we've reached the end of our fuse
	if( gpGlobals->curtime > m_flBurnTime )
	{
		UTIL_Remove(this);
		return;
	}

	// Bug #0001664: Pyro napalm flames in water shouldnt exist
	if( GetWaterLevel() != 0  )
	{
		UTIL_Remove(this);
		return;
	}

	Vector	vecSrc = GetAbsOrigin();
	vecSrc.z += 1;

	CBaseEntity *pEntity = NULL;

	for( CEntitySphereQuery sphere( vecSrc, NAP_BURN_RADIUS ); ( pEntity = sphere.GetCurrentEntity() ) != NULL; sphere.NextEntity() )
	{
		if( !pEntity )
			continue;

		// Bug #0000269: Napalm through walls.
		// Mulch: if we hit water w/ the trace, abort too!
		trace_t tr;
		UTIL_TraceLine(GetAbsOrigin(), pEntity->GetAbsOrigin(), MASK_SOLID_BRUSHONLY | CONTENTS_WATER, this, COLLISION_GROUP_DEBRIS, &tr);

		if (tr.fraction < 1.0f)
			continue;

		// Bug #0000270: Napalm grenade burn radius reaches unrealisticly high.
		float height = tr.startpos.z - tr.endpos.z;
		if (height < -FFDEV_NAP_HEIGHT || height > FFDEV_NAP_HEIGHT)
			continue;

		// Don't damage if entity is more than feet deep in water
		if( pEntity->GetWaterLevel() >= 2 )
			continue;

		// FF Grenade Port: was switch( pEntity->Classify() ) with cases CLASS_PLAYER and
		// CLASS_SENTRYGUN/CLASS_MANCANNON/CLASS_DISPENSER (FF's own class-ID enum, which never
		// matches TF2's real entities). Rewritten as if/else-if: the player case still uses
		// Classify()==CLASS_PLAYER (a stock engine value, unmodified, confirmed real), and the
		// buildable case now uses TF2's actual ObjectType()/CBaseObject system -- same pattern
		// as the earlier laser/nail buildables rewrite. Mancannon dropped (no TF2 equivalent
		// exists, same decision made for ff_grenade_laser.cpp).
		if ( pEntity->Classify() == CLASS_PLAYER )
		{
			// FF Grenade Port: CFFPlayer -> CTFPlayer, ToFFPlayer -> ToTFPlayer.
			CTFPlayer *pPlayer = ToTFPlayer( pEntity );
			if( !pPlayer )
				continue;

			if (!pPlayer->InSameTeam(GetOwnerEntity()))  // FF Grenade Port: FCanTakeDamage->InSameTeam
			{
				// FF Grenade Port: FF's leveled burn system (GetBurnLevel()/IncreaseBurnLevel(),
				// 0-300 across 3 tiers) doesn't exist in TF2 and isn't being ported -- TF2 has
				// no leveled-burn concept. CalculateBonusBurnDamage() is left in place below
				// (unused for now) since it's self-contained FF logic with no further
				// dependencies; only the base BURN_STANDON_NG damage is applied here.
				int damage = BURN_STANDON_NG;
				pPlayer->TakeDamage( CTakeDamageInfo( this, GetOwnerEntity(), damage, DMG_BURN ) );

				// Ignite using TF2's own native afterburn system (CTFPlayerShared::Burn(),
				// the same call stock TF2's CTFPlayer::IgnitePlayer() uses) instead of porting
				// FF's burn-level tracking.
				CTFPlayer *pTFAttacker = ToTFPlayer( GetOwnerEntity() );
				pPlayer->m_Shared.Burn( pTFAttacker, NULL );
			}
		}
		else if ( pEntity->IsBaseObject() )
		{
			CBaseObject *pObject = dynamic_cast<CBaseObject*>( pEntity );
			if ( pObject && ( pObject->ObjectType() == OBJ_SENTRYGUN || pObject->ObjectType() == OBJ_DISPENSER )
				 && !pObject->IsBuilding() && !pObject->IsPlacing() )
			{
				if (!pEntity->InSameTeam( GetOwnerEntity()))  // FF Grenade Port: FCanTakeDamage->InSameTeam
					pEntity->TakeDamage( CTakeDamageInfo( this, GetOwnerEntity(), BURN_STANDON_NG, DMG_BURN ) );
			}
		}
	}

	SetNextThink( gpGlobals->curtime + 0.25f );
}

//----------------------------------------------------------------------------
// Purpose: Calculate the bonus damage for the napalmlet based on the players current burn level
//----------------------------------------------------------------------------
int CFFGrenadeNapalmlet::CalculateBonusBurnDamage(int burnLevel)
{
	if (burnLevel <100)
	{
		return NAP_BONUSDAMAGE_BURN1;
	}
	if (burnLevel <200)
	{
		return NAP_BONUSDAMAGE_BURN2;
	}

	return NAP_BONUSDAMAGE_BURN3;
}
