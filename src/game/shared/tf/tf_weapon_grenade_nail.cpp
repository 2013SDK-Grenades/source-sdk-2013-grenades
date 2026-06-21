//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Nail Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_nail.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeNail instead of a native TF2 projectile
// (see EmitGrenade() below). tf_projectile_nail.h/physics_saverestore.h/phys_controller.h
// removed -- were only used by the now-removed native projectile and its physics motion
// controller.
#include "ff_grenade_base.h"
#endif

#define GRENADE_NAIL_TIMER	3.0f //Seconds

//=============================================================================
//
// TF Nail Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeNail, DT_TFGrenadeNail )

BEGIN_NETWORK_TABLE( CTFGrenadeNail, DT_TFGrenadeNail )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeNail )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_nail, CTFGrenadeNail );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_nail );

//=============================================================================
//
// TF Nail Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeNail )
END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeNail ("ff_grenade_nail") entity. Same spawn
// pattern as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for
// the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeNail::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
					        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_nail" );
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
