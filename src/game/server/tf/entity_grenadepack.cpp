//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: CTF GrenadePack.
//
//=============================================================================//
#include "cbase.h"
#include "items.h"
#include "tf_gamerules.h"
#include "tf_shareddefs.h"
#include "tf_player.h"
#include "tf_team.h"
#include "engine/IEngineSound.h"
#include "entity_grenadepack.h"
#include "pf/pf_cvars.h"		// PF2C port — pf_grenadepack_respawn_time

//=============================================================================
//
// CTF GrenadePack defines.
//

#define TF_GRENADEPACK_MODEL			"models/items/item_grenadepack.mdl"
#define TF_GRENADEPACK_PICKUP_SOUND		"GrenadePack.Touch"
#define TF_GRENADEPACK_GRENADES1		4
#define TF_GRENADEPACK_GRENADES2		4

LINK_ENTITY_TO_CLASS( item_grenadepack, CGrenadePack );

//=============================================================================
//
// CTF GrenadePack functions.
//

//-----------------------------------------------------------------------------
// Purpose: Spawn function for the grenadepack
//-----------------------------------------------------------------------------
void CGrenadePack::Spawn( void )
{
	Precache();
	SetModel( TF_GRENADEPACK_MODEL );

	BaseClass::Spawn();

	// PF2C port: grenade packs are now functional. Original stub called UTIL_Remove(this) here.
}

//-----------------------------------------------------------------------------
// Purpose: Precache function for the grenadepack
//-----------------------------------------------------------------------------
void CGrenadePack::Precache( void )
{
	PrecacheModel( TF_GRENADEPACK_MODEL );
	PrecacheScriptSound( TF_GRENADEPACK_PICKUP_SOUND );
}

//-----------------------------------------------------------------------------
// Purpose: Return the default model path for this powerup.
//-----------------------------------------------------------------------------
const char *CGrenadePack::GetDefaultPowerupModel( void )
{
	return TF_GRENADEPACK_MODEL;
}

//-----------------------------------------------------------------------------
// Purpose: Respawn delay driven by pf_grenadepack_respawn_time ConVar.
//          CTFPowerup::Respawn() handles the full respawn cycle automatically
//          once we override this.  PF2C port.
//-----------------------------------------------------------------------------
float CGrenadePack::GetRespawnDelay( void )
{
	return pf_grenadepack_respawn_time.GetFloat();
}

//-----------------------------------------------------------------------------
// Purpose: MyTouch function for the grenadepack
//-----------------------------------------------------------------------------
bool CGrenadePack::MyTouch( CBasePlayer *pPlayer )
{
	bool bSuccess = false;

	if ( ValidTouch( pPlayer ) )
	{
		// try to give primary grenades
		if ( pPlayer->GiveAmmo( TF_GRENADEPACK_GRENADES1, TF_AMMO_GRENADES1, true ) )
		{
			bSuccess = true;
		}

		// try to give secondary grenades
		if ( pPlayer->GiveAmmo( TF_GRENADEPACK_GRENADES2, TF_AMMO_GRENADES2, true ) )
		{
			bSuccess = true;
		}

		// did we give them anything?
		if ( bSuccess )
		{
			CSingleUserRecipientFilter filter( pPlayer );
			EmitSound( filter, entindex(), TF_GRENADEPACK_PICKUP_SOUND );
		}
	}

	return bSuccess;
}
