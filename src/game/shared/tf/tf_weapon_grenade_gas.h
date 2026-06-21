//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Gas Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_GAS_H
#define TF_WEAPON_GRENADE_GAS_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeGas C_TFGrenadeGas
#endif

//=============================================================================
//
// TF Gas Grenade
//
class CTFGrenadeGas : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeGas, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();
//	DECLARE_ACTTABLE();

	CTFGrenadeGas() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_GAS; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeGas ("ff_grenade_gas") instead of the native TF2 projectile +
	// particle-effect-entity pair this file used to define below (now removed -- unused
	// dead code, replaced by FF's real, already-ported implementation, which handles its
	// own gas-cloud effect internally).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeGas( const CTFGrenadeGas & ) {}
};

#endif // TF_WEAPON_GRENADE_GAS_H
