// FF Grenade Port: ported from ff-src/mp/src/game/client/ff/fx/ff_fx_slowfield.cpp
// Changes from FF original:
//   - C_FFPlayer::GetLocalFFPlayerOrObserverTarget() -> C_BasePlayer::GetLocalPlayer()
//   - FindOverrideMaterial() -> SetMaterial() on C_BaseAnimating (TF2 SDK equivalent)
//   - TEAM_BLUE/RED/YELLOW/GREEN -> TF_TEAM_BLUE/TF_TEAM_RED; yellow/green unsupported in TF2
//   - 'effects/slowfield*' materials may not exist; effect falls back gracefully if missing
//   - DECLARE_CLIENT_EFFECT name is "FF_SlowFieldEffect" (capital F in Field, matches the
//     SLOWFIELD_EFFECT define in ff_grenade_slowfield.cpp which uses "FF_SlowFieldEffect")

#include "cbase.h"
#include "clienteffectprecachesystem.h"
#include "c_te_effect_dispatch.h"
#include "c_baseanimating.h"
#include "tf_shareddefs.h"

#define FF_SLOWFIELD_MATERIAL        "effects/slowfield"
#define FF_SLOWFIELD_MATERIAL_BLUE   "effects/slowfield_blue"
#define FF_SLOWFIELD_MATERIAL_RED    "effects/slowfield_red"
#define FF_SLOWFIELD_TEXTURE_GROUP   TEXTURE_GROUP_CLIENT_EFFECTS

#define SLOWFIELD_DURATION 10.0f

CLIENTEFFECT_REGISTER_BEGIN( PrecacheSlowfieldEmitter )
	CLIENTEFFECT_MATERIAL( FF_SLOWFIELD_MATERIAL )
	CLIENTEFFECT_MATERIAL( FF_SLOWFIELD_MATERIAL_BLUE )
	CLIENTEFFECT_MATERIAL( FF_SLOWFIELD_MATERIAL_RED )
CLIENTEFFECT_REGISTER_END()

class C_SlowfieldEffect : public C_BaseAnimating
{
	DECLARE_CLASS( C_SlowfieldEffect, C_BaseAnimating );
public:
	static C_SlowfieldEffect *CreateClientsideEffect( const char *pszModelName, const Vector &vecOrigin, int iTeam );
	bool InitializeEffect( const char *pszModelName, const Vector &vecOrigin );
	void ClientThink( void );

protected:
	IMaterial *m_pMaterial;
	float      m_flStart;
	int        m_iTeam;
};

C_SlowfieldEffect *C_SlowfieldEffect::CreateClientsideEffect( const char *pszModelName, const Vector &vecOrigin, int iTeam )
{
	C_SlowfieldEffect *pEffect = new C_SlowfieldEffect;
	if ( !pEffect )
		return NULL;

	if ( !pEffect->InitializeEffect( pszModelName, vecOrigin ) )
		return NULL;

	// Choose material by team
	const char *pszMat = FF_SLOWFIELD_MATERIAL;
	if ( iTeam == TF_TEAM_BLUE )
		pszMat = FF_SLOWFIELD_MATERIAL_BLUE;
	else if ( iTeam == TF_TEAM_RED )
		pszMat = FF_SLOWFIELD_MATERIAL_RED;

	pEffect->m_pMaterial = materials->FindMaterial( pszMat, FF_SLOWFIELD_TEXTURE_GROUP );
	pEffect->m_flStart   = gpGlobals->curtime;
	pEffect->m_iTeam     = iTeam;
	return pEffect;
}

bool C_SlowfieldEffect::InitializeEffect( const char *pszModelName, const Vector &vecOrigin )
{
	if ( !InitializeAsClientEntity( pszModelName, RENDER_GROUP_OPAQUE_ENTITY ) )
	{
		Release();
		return false;
	}
	SetAbsOrigin( vecOrigin );
	SetNextClientThink( CLIENT_THINK_ALWAYS );
	return true;
}

void C_SlowfieldEffect::ClientThink( void )
{
	if ( gpGlobals->curtime - m_flStart >= SLOWFIELD_DURATION )
	{
		Release();
		return;
	}

	// Orient the disc to face the local player
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	if ( !pPlayer )
		return;

	Vector vecDir = GetAbsOrigin() - pPlayer->EyePosition();
	QAngle angFace;
	VectorAngles( vecDir, angFace );
	angFace.x += 90;
	SetAbsAngles( angFace );

	BaseClass::ClientThink();
}

//-----------------------------------------------------------------------------
// Callback — registered as "FF_SlowFieldEffect" (capital F, matching the define)
//-----------------------------------------------------------------------------
void FF_FX_SlowfieldEffect_Callback( const CEffectData &data )
{
	C_SlowfieldEffect::CreateClientsideEffect(
		"models/grenades/conc/conceffect.mdl",
		data.m_vOrigin,
		(int)data.m_nColor );
}

DECLARE_CLIENT_EFFECT( "FF_SlowFieldEffect", FF_FX_SlowfieldEffect_Callback );
