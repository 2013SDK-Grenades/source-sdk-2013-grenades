//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Flare Grenade.
//
// FF Grenade Port: new file -- FF's flare grenade has no stock TF2 equivalent (unlike
// the other grenade types, where an existing dormant tf_weapon_grenade_*.cpp/h pair was
// adapted instead). Modeled directly on the established pattern from
// tf_weapon_grenade_concussion.h, the cleanest of the adapted files.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_FLARE_H
#define TF_WEAPON_GRENADE_FLARE_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeFlare C_TFGrenadeFlare
#endif

//=============================================================================
//
// TF Flare Grenade
//
class CTFGrenadeFlare : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeFlare, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFGrenadeFlare() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_FLARE; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// Spawns FF's real CFFGrenadeFlare ("ff_grenade_flare") entity. Same spawn pattern
	// as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for the
	// detailed rationale.
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeFlare( const CTFGrenadeFlare & ) {}
};

#endif // TF_WEAPON_GRENADE_FLARE_H
