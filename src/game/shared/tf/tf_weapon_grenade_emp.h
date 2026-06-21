//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Emp Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_EMP_H
#define TF_WEAPON_GRENADE_EMP_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeEmp C_TFGrenadeEmp
#endif

//=============================================================================
//
// TF Emp Grenade
//
class CTFGrenadeEmp : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeEmp, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();
//	DECLARE_ACTTABLE();

	CTFGrenadeEmp() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_EMP; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeEmp ("ff_grenade_emp") instead of the native TF2 projectile
	// class this file used to define below (now removed -- unused dead code, replaced by
	// FF's real, already-ported and rewritten implementation -- see ff_grenade_emp.cpp,
	// patched in an earlier batch to detonate TF2's real stickybombs).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeEmp( const CTFGrenadeEmp & ) {}
};

#endif // TF_WEAPON_GRENADE_EMP_H
