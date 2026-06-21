//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Gas Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_gas.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeGas instead of a native TF2 projectile
// (see EmitGrenade() below).
#include "ff_grenade_base.h"
#endif

#define GRENADE_GAS_TIMER	3.0f //Seconds

//=============================================================================
//
// TF Gas Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeGas, DT_TFGrenadeGas )

BEGIN_NETWORK_TABLE( CTFGrenadeGas, DT_TFGrenadeGas )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeGas )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_gas, CTFGrenadeGas );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_gas );

//=============================================================================
//
// TF Gas Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeGas )
END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeGas ("ff_grenade_gas") entity. Same spawn
// pattern as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for
// the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeGas::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
					        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_gas" );
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
