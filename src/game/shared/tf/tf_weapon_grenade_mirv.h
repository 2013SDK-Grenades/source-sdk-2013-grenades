//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Mirv Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_MIRV_H
#define TF_WEAPON_GRENADE_MIRV_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeMirv C_TFGrenadeMirv
#define CTFGrenadeMirv_Demoman C_TFGrenadeMirv_Demoman
#endif

//=============================================================================
//
// TF Mirv Grenade
//
class CTFGrenadeMirv : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeMirv, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFGrenadeMirv() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_MIRV; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeMirv ("ff_grenade_mirv") instead of the native TF2 projectile +
	// "bomb" submunition pair this file used to define below (now removed -- unused dead
	// code, replaced by FF's real, already-ported implementation, which spawns its own
	// CFFGrenadeMirvlet sub-entities on detonation -- confirmed by reading
	// ff_grenade_mirv.cpp directly, same two-stage pattern as napalm/napalmlet).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeMirv( const CTFGrenadeMirv & ) {}
};

// Demoman version calls different models. FF Grenade Port: kept as-is -- trivial,
// harmless, inherits EmitGrenade() from CTFGrenadeMirv unchanged. FF doesn't have a
// class-specific mirv variant, but this costs nothing to keep around for whenever
// per-class loadout/cosmetic assignment is set up later (deferred along with other
// assets/scripts work).
class CTFGrenadeMirv_Demoman : public CTFGrenadeMirv
{
public:
	DECLARE_CLASS( CTFGrenadeMirv_Demoman, CTFGrenadeMirv );
	DECLARE_NETWORKCLASS(); 
	DECLARE_PREDICTABLE();

	virtual int		GetWeaponID( void ) const		{ return TF_WEAPON_GRENADE_MIRV_DEMOMAN; }
};

#endif // TF_WEAPON_GRENADE_MIRV_H
