//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Caltrop Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_CALTROP_H
#define TF_WEAPON_GRENADE_CALTROP_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeCaltrop C_TFGrenadeCaltrop
#endif

//=============================================================================
//
// TF Caltrop Grenade
//
class CTFGrenadeCaltrop : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeCaltrop, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();
//	DECLARE_ACTTABLE();

	CTFGrenadeCaltrop() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_CALTROP; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*). Spawns
	// FF's real CFFGrenadeCaltrop ("ff_grenade_caltrop") instead of the native TF2
	// projectile class this file used to define below (now removed -- unused dead code,
	// replaced by FF's real, already-ported implementation).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeCaltrop( const CTFGrenadeCaltrop & ) {}
};

#endif // TF_WEAPON_GRENADE_CALTROP_H
