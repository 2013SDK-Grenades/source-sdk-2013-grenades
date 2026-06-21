//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Concussion Grenade.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_CONCUSSION_H
#define TF_WEAPON_GRENADE_CONCUSSION_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeConcussion C_TFGrenadeConcussion
#endif

//=============================================================================
//
// TF Concussion Grenade
//
class CTFGrenadeConcussion : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeConcussion, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFGrenadeConcussion() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_CONCUSSION; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// FF Grenade Port: return type CBaseGrenade* (was CTFWeaponBaseGrenadeProj*) -- see the
	// note on the base class declaration in tf_weaponbase_grenade.h. Spawns FF's real
	// CFFGrenadeConcussion ("ff_grenade_concussion") instead of the stock projectile class
	// this file used to define below (now removed -- it was dead code: this dormant system's
	// CTFGrenadeConcussionProjectile::Explode() called pTestPlayer->m_Shared.Concussion(),
	// a function that's declared nowhere in stock SDK 2013, so it could never have compiled
	// as shipped here).
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeConcussion( const CTFGrenadeConcussion & ) {}
};

#endif // TF_WEAPON_GRENADE_CONCUSSION_H
