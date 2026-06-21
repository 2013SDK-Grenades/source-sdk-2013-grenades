//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Slowfield Grenade.
//
// FF Grenade Port: new file -- see tf_weapon_grenade_slowfield.h for context.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_slowfield.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
#include "ff_grenade_base.h"
#endif

//=============================================================================
//
// TF Slowfield Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeSlowfield, DT_TFGrenadeSlowfield )

BEGIN_NETWORK_TABLE( CTFGrenadeSlowfield, DT_TFGrenadeSlowfield )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeSlowfield )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_slowfield, CTFGrenadeSlowfield );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_slowfield );

//=============================================================================
//
// TF Slowfield Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeSlowfield )
END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeSlowfield ("ff_grenade_slowfield") entity. Same
// spawn pattern as the other ported grenades -- see tf_weapon_grenade_concussion.cpp
// for the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeSlowfield::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
					        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_slowfield" );
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
