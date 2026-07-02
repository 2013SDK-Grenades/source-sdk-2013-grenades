// FF Grenade Port: ported from ff-src/mp/src/game/client/ff/fx/ff_fx_conc_emitter.cpp
// Changes from FF original:
//   - Removed CConcEmitter / refraction particle system (depends on FF-specific materials
//     and a 'sprites/concrefract' VMT not present in TF2). The flat beam-ring effect
//     (cl_conc_refract 0 path) is the default and works without FF materials.
//   - Removed C_ConcEffect clientside entity (depends on 'models/grenades/conc/conceffect.mdl'
//     oriented towards the player using FF-specific camera logic).
//   - g_iConcRingTexture is defined in ff_grenade_concussion.cpp (shared) and precached there.
//   - WaterExplosionEffect() removed (FF custom; TF2 uses a different underwater effect).
//   - DECLARE_CLIENT_EFFECT registers both FF_ConcussionEffect and FF_ConcussionEffectHandheld.

#include "cbase.h"
#include "clienteffectprecachesystem.h"
#include "c_te_effect_dispatch.h"
#include "beam_flags.h"

// Defined and precached in ff_grenade_concussion.cpp
extern int g_iConcRingTexture;

// ConVars ported from FF (tunable in console)
static ConVar ffdev_conc_effect_framerate( "ffdev_conc_effect_framerate", "1", FCVAR_CHEAT );
static ConVar ffdev_conc_effect_width(     "ffdev_conc_effect_width",     "50", FCVAR_CHEAT );
static ConVar ffdev_conc_effect_width2(    "ffdev_conc_effect_width2",    "0",  FCVAR_CHEAT );
static ConVar ffdev_conc_effect_width3(    "ffdev_conc_effect_width3",    "10", FCVAR_CHEAT );
static ConVar ffdev_conc_effect_spread(    "ffdev_conc_effect_spread",    "0",  FCVAR_CHEAT );
static ConVar ffdev_conc_effect_amplitude( "ffdev_conc_effect_amplitude", "0",  FCVAR_CHEAT );
static ConVar ffdev_conc_effect_lifetime(  "ffdev_conc_effect_lifetime",  ".3", FCVAR_CHEAT );
static ConVar ffdev_conc_effect_r(         "ffdev_conc_effect_r",         "255",FCVAR_CHEAT );
static ConVar ffdev_conc_effect_g(         "ffdev_conc_effect_g",         "255",FCVAR_CHEAT );
static ConVar ffdev_conc_effect_b(         "ffdev_conc_effect_b",         "225",FCVAR_CHEAT );
static ConVar ffdev_conc_effect_a(         "ffdev_conc_effect_a",         "178",FCVAR_CHEAT );
static ConVar ffdev_conc_effect_radius(    "ffdev_conc_effect_radius",    "600",FCVAR_CHEAT );
static ConVar ffdev_conc_effect_radius2(   "ffdev_conc_effect_radius2",   "520",FCVAR_CHEAT );

#define CONC_FRAMERATE		ffdev_conc_effect_framerate.GetFloat()
#define CONC_WIDTH			ffdev_conc_effect_width.GetFloat()
#define CONC_WIDTH2			ffdev_conc_effect_width2.GetFloat()
#define CONC_WIDTH3			ffdev_conc_effect_width3.GetFloat()
#define CONC_SPREAD			ffdev_conc_effect_spread.GetFloat()
#define CONC_AMPLITUDE		ffdev_conc_effect_amplitude.GetFloat()
#define CONC_LIFETIME		ffdev_conc_effect_lifetime.GetFloat()
#define CONC_R				ffdev_conc_effect_r.GetFloat()
#define CONC_G				ffdev_conc_effect_g.GetFloat()
#define CONC_B				ffdev_conc_effect_b.GetFloat()
#define CONC_A				ffdev_conc_effect_a.GetFloat()
#define CONC_RADIUS			ffdev_conc_effect_radius.GetFloat()
#define CONC_RADIUS2		ffdev_conc_effect_radius2.GetFloat()

//-----------------------------------------------------------------------------
// Helper: emit the three concussion beam rings at a given origin.
//-----------------------------------------------------------------------------
static void EmitConcRings( const Vector &origin )
{
	CBroadcastRecipientFilter filter;

	te->BeamRingPoint( filter, 0, origin,
		1.0f, CONC_RADIUS, g_iConcRingTexture, 0, 0,
		CONC_FRAMERATE, CONC_LIFETIME, CONC_WIDTH, CONC_SPREAD,
		CONC_AMPLITUDE, CONC_R, CONC_G, CONC_B, CONC_A, 0,
		FBEAM_FADEOUT | FBEAM_SINENOISE );

	te->BeamRingPoint( filter, 0, origin + Vector( 0, 0, 32 ),
		1.0f, CONC_RADIUS2, g_iConcRingTexture, 0, 0,
		CONC_FRAMERATE, CONC_LIFETIME, CONC_WIDTH2, CONC_SPREAD,
		CONC_AMPLITUDE, CONC_R, CONC_G, CONC_B, CONC_A, 0,
		FBEAM_FADEOUT | FBEAM_SINENOISE );

	te->BeamRingPoint( filter, 0, origin + Vector( 0, 0, -32 ),
		1.0f, CONC_RADIUS2, g_iConcRingTexture, 0, 0,
		CONC_FRAMERATE, CONC_LIFETIME, CONC_WIDTH2, CONC_SPREAD,
		CONC_AMPLITUDE, CONC_R, CONC_G, CONC_B, CONC_A, 0,
		FBEAM_FADEOUT | FBEAM_SINENOISE );

	// Outer bounding ring
	te->BeamRingPoint( filter, 0, origin,
		CONC_RADIUS - 1.0f, CONC_RADIUS, g_iConcRingTexture, 0, 0,
		CONC_FRAMERATE, CONC_LIFETIME, CONC_WIDTH3, CONC_SPREAD,
		CONC_AMPLITUDE, CONC_R, CONC_G, CONC_B, CONC_A, 0,
		FBEAM_FADEOUT | FBEAM_SINENOISE );

	te->GaussExplosion( filter, 0, origin, Vector( 0, 0, 1 ), 1 );
}

//-----------------------------------------------------------------------------
// FF_ConcussionEffect — thrown conc
//-----------------------------------------------------------------------------
void FF_FX_ConcussionEffect_Callback( const CEffectData &data )
{
	EmitConcRings( data.m_vOrigin );
}

//-----------------------------------------------------------------------------
// FF_ConcussionEffectHandheld — handheld/primed conc that detonates on the player
//-----------------------------------------------------------------------------
void FF_FX_ConcussionEffectHandheld_Callback( const CEffectData &data )
{
	EmitConcRings( data.m_vOrigin );
}

DECLARE_CLIENT_EFFECT( "FF_ConcussionEffect",         FF_FX_ConcussionEffect_Callback );
DECLARE_CLIENT_EFFECT( "FF_ConcussionEffectHandheld", FF_FX_ConcussionEffectHandheld_Callback );
