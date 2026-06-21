//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Napalm Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_napalm.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeNapalm instead of a native TF2 projectile
// (see EmitGrenade() below).
#include "ff_grenade_base.h"
#endif

//=============================================================================
//
// TF Napalm Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeNapalm, DT_TFGrenadeNapalm )

BEGIN_NETWORK_TABLE( CTFGrenadeNapalm, DT_TFGrenadeNapalm )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeNapalm )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_napalm, CTFGrenadeNapalm );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_napalm );

//=============================================================================
//
// TF Napalm Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeNapalm )
END_DATADESC()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeNapalm ("ff_grenade_napalm") entity. Same spawn
// pattern as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for
// the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeNapalm::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
					        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_napalm" );
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
