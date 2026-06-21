//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Emp Grenade.
//
//=============================================================================//
#include "cbase.h"
#include "tf_weaponbase.h"
#include "tf_gamerules.h"
#include "npcevent.h"
#include "engine/IEngineSound.h"
#include "tf_weapon_grenade_emp.h"

// Server specific.
#ifdef GAME_DLL
#include "tf_player.h"
#include "items.h"
#include "soundent.h"
#include "KeyValues.h"
// FF Grenade Port: spawns FF's real CFFGrenadeEmp instead of a native TF2 projectile
// (see EmitGrenade() below). particle_parse.h/beam_shared.h removed -- were only used
// by the now-removed native projectile's effects.
#include "ff_grenade_base.h"
#endif

#define GRENADE_EMP_TIMER	3.0f //Seconds
#define	GRENADE_EMP_LEADIN	2.0f 

//=============================================================================
//
// TF Emp Grenade tables.
//

IMPLEMENT_NETWORKCLASS_ALIASED( TFGrenadeEmp, DT_TFGrenadeEmp )

BEGIN_NETWORK_TABLE( CTFGrenadeEmp, DT_TFGrenadeEmp )
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA( CTFGrenadeEmp )
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS( tf_weapon_grenade_emp, CTFGrenadeEmp );
PRECACHE_WEAPON_REGISTER( tf_weapon_grenade_emp );

//=============================================================================
//
// TF Emp Grenade functions.
//

// Server specific.
#ifdef GAME_DLL

BEGIN_DATADESC( CTFGrenadeEmp )
END_DATADESC()

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Purpose: Spawns FF's real CFFGrenadeEmp ("ff_grenade_emp") entity. Same spawn
// pattern as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for
// the detailed rationale.
//-----------------------------------------------------------------------------
CBaseGrenade *CTFGrenadeEmp::EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, 
					        AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags )
{
	CFFGrenadeBase *pGrenade = (CFFGrenadeBase *)CreateEntityByName( "ff_grenade_emp" );
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
