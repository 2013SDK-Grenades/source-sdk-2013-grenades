//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Mirv Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_mirv.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeMirv instead of a native TF2 projectile
// (see EmitGrenade() below).
#include "ff_grenade_base.h"
#endif

#define GRENADE_MIRV_TIMER	3.0f // seconds
#define	GRENADE_MIRV_LEADIN	2.0f 

//=============================================================================
//
// TF Demoman Mirv Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeMirv_Demoman, DT_TFGrenadeMirv_Demoman )

BEGIN_NETWORK_TABLE( CTFGrenadeMirv_Demoman, DT_TFGrenadeMirv_Demoman )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeMirv_Demoman )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_mirv_demoman, CTFGrenadeMirv_Demoman );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_mirv_demoman );

//=============================================================================
//
// TF Mirv Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeMirv, DT_TFGrenadeMirv )

BEGIN_NETWORK_TABLE( CTFGrenadeMirv, DT_TFGrenadeMirv )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeMirv )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_mirv, CTFGrenadeMirv );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_mirv );

//=============================================================================
//
// TF Mirv Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeMirv )
END_DATADESC()

//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeMirv ("ff_grenade_mirv") canister. FF's own
// CFFGrenadeMirv::Explode() already scatters the individual CFFGrenadeMirvlet
// sub-munitions itself (confirmed by reading ff_grenade_mirv.cpp), so unlike this
// dormant TF2 version (which used a separate "bomb" projectile class spawned from
// here), only the single canister needs spawning. Same spawn pattern as the other
// ported grenades -- see tf_weapon_grenade_concussion.cpp for the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeMirv::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
					      AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_mirv" );
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
