//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Normal Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_NORMAL_H
#define TF_WEAPON_GRENADE_NORMAL_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeNormal C_TFGrenadeNormal
#endif

//=============================================================================
//
// TF Normal Grenade
//
class CTFGrenadeNormal : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeNormal, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();
//	DECLARE_ACTTABLE();

	CTFGrenadeNormal() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_NORMAL; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeNormal ("ff_grenade_normal") instead of the native TF2
	// projectile class this file used to define below (now removed -- unused dead code,
	// replaced by FF's real, already-ported implementation).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeNormal( const CTFGrenadeNormal & ) {}
};

#endif // TF_WEAPON_GRENADE_NORMAL_H
