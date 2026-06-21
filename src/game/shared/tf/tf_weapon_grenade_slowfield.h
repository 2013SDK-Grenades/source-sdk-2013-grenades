//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: TF Slowfield Grenade.
//
// FF Grenade Port: new file -- FF's slowfield grenade has no stock TF2 equivalent.
// Modeled directly on the established pattern from tf_weapon_grenade_concussion.h.
//
//=============================================================================//
#ifndef TF_WEAPON_GRENADE_SLOWFIELD_H
#define TF_WEAPON_GRENADE_SLOWFIELD_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_grenade.h"

// Client specific.
#ifdef CLIENT_DLL
#define CTFGrenadeSlowfield C_TFGrenadeSlowfield
#endif

//=============================================================================
//
// TF Slowfield Grenade
//
class CTFGrenadeSlowfield : public CTFWeaponBaseGrenade
{
public:

	DECLARE_CLASS( CTFGrenadeSlowfield, CTFWeaponBaseGrenade );
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFGrenadeSlowfield() {}

	// Unique identifier.
	virtual int			GetWeaponID( void ) const			{ return TF_WEAPON_GRENADE_SLOWFIELD; }

// Server specific.
#ifdef GAME_DLL

	DECLARE_DATADESC();

	// Spawns FF's real CFFGrenadeSlowfield ("ff_grenade_slowfield") entity. Same spawn
	// pattern as the other ported grenades -- see tf_weapon_grenade_concussion.cpp for
	// the detailed rationale.
	virtual CBaseGrenade *EmitGrenade( Vector vecSrc, QAngle vecAngles, Vector vecVel, AngularImpulse angImpulse, CBasePlayer *pPlayer, float flTime, int iflags = 0 );

#endif

	CTFGrenadeSlowfield( const CTFGrenadeSlowfield & ) {}
};

#endif // TF_WEAPON_GRENADE_SLOWFIELD_H
