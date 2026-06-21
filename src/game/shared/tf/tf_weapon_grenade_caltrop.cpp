//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Caltrop Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_caltrop.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeCaltrop instead of a native TF2 projectile
// (see EmitGrenade() below).
#include "ff_grenade_base.h"
#endif

#define GRENADE_CALTROP_TIMER			3.0f //Seconds
#define GRENADE_CALTROP_RELEASE_COUNT	6
#define GRENADE_CALTROP_DAMAGE			10

//=============================================================================
//
// TF Caltrop Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeCaltrop, DT_TFGrenadeCaltrop )

BEGIN_NETWORK_TABLE( CTFGrenadeCaltrop, DT_TFGrenadeCaltrop )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeCaltrop )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_caltrop, CTFGrenadeCaltrop );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_caltrop );

//=============================================================================
//
// TF Caltrop Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeCaltrop )
END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeCaltrop ("ff_grenade_caltrop") thrown canister.
// FF's own CFFGrenadeCaltrop::Explode() already scatters the individual caltrop pickups
// itself (confirmed by reading it), so unlike this dormant TF2 version (which released
// several native projectiles directly from here), only the single canister needs
// spawning. Same spawn pattern as the other ported grenades -- see
// tf_weapon_grenade_concussion.cpp for the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeCaltrop::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
							        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_caltrop" );
	if ( !pGrenade )
		return NULL;

	UTIL_SetOrigin( pGrenade, vecSrc );
	pGrenade->Spawn();
	pGrenade->SetAbsVelocity( vecVel );
	pGrenade->SetThrower( pPlayer );
	pGrenade->SetOwnerEntity( pPlayer );
	pGrenade->ChangeTeam( pPlayer->GetTeamNumber() );
	pGrenade->SetDetonateTimerLength( flTime );
	pGrenade->SetupInitialTransmittedVelocity( vecVel );

	return pGrenade;
}

#endif

