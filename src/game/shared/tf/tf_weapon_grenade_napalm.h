//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Napalm Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_NAPALM_H
#define TF_WEAPON_GRENADE_NAPALM_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeNapalm C_TFGrenadeNapalm
#endif

//=============================================================================
//
// TF Napalm Grenade
//
class CTFGrenadeNapalm : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeNapalm, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFGrenadeNapalm() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_NAPALM; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeNapalm ("ff_grenade_napalm") instead of the native TF2
	// projectile class this file used to define below (now removed -- unused dead code,
	// replaced by FF's real, already-ported implementation, which spawns its own
	// CFFGrenadeNapalmlet sub-entities on detonation).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeNapalm( const CTFGrenadeNapalm & ) {}
};

#endif // TF_WEAPON_GRENADE_NAPALM_H
