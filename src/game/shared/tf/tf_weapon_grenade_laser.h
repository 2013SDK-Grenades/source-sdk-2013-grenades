//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Laser Grenade.
//
// FF Grenade Port: new file -- FF's laser grenade has no stock TF2 equivalent. Modeled
// directly on the established pattern from tf_weapon_grenade_concussion.h.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_LASER_H
#define TF_WEAPON_GRENADE_LASER_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeLaser C_TFGrenadeLaser
#endif

//=============================================================================
//
// TF Laser Grenade
//
class CTFGrenadeLaser : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeLaser, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFGrenadeLaser() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_LASER; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// Spawns FF's real CFFGrenadeLaser ("ff_grenade_laser") entity. Same spawn pattern
	// as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for the
	// detailed rationale.
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeLaser( const CTFGrenadeLaser & ) {}
};

#endif // TF_WEAPON_GRENADE_LASER_H
