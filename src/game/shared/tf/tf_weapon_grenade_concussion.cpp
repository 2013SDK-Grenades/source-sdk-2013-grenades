//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Concussion Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_concussion.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeConcussion instead of a native TF2
// projectile (see EmitGrenade() below).
#include "ff_grenade_base.h"

#endif

#define GRENADE_CONCUSSION_TIMER	3.0f			// seconds

//=============================================================================
//
// TF Concussion Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeConcussion, DT_TFGrenadeConcussion )

BEGIN_NETWORK_TABLE( CTFGrenadeConcussion, DT_TFGrenadeConcussion )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeConcussion )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_concussion, CTFGrenadeConcussion );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_concussion );

//=============================================================================
//
// TF Concussion Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeConcussion )
END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeConcussion ("ff_grenade_concussion") entity.
// Follows the same spawn pattern FF's own CFFPlayer::ThrowGrenade() used
// (CreateEntityByName + manual Spawn()/SetAbsVelocity()/SetThrower()/etc) rather than
// TF2's InitGrenade() helper -- FF's grenade classes don't derive from
// CTFWeaponBaseGrenadeProj, so that helper isn't available to them, and they have their
// own initialization conventions (own gravity/friction/elasticity set in their own
// Spawn(), own damage/radius from their own ConVars).
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeConcussion::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
							        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_concussion" );
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
