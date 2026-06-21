//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Nail Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_NAIL_H
#define TF_WEAPON_GRENADE_NAIL_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeNail C_TFGrenadeNail
#endif

//=============================================================================
//
// TF Nail Grenade
//
class CTFGrenadeNail : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeNail, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();
//	DECLARE_ACTTABLE();

	CTFGrenadeNail() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_NAIL; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeNail ("ff_grenade_nail") instead of the native TF2 projectile +
	// physics-motion-controller pair this file used to define below (now removed --
	// unused dead code, replaced by FF's real, already-ported implementation, which
	// spawns its own CFFProjectileNail entities for the actual nails).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

public:

	CTFGrenadeNail( const CTFGrenadeNail & ) {}
};

#endif // TF_WEAPON_GRENADE_NAIL_H
