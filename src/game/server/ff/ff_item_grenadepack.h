//========= FF Grenade Port ===============================================//
//
// Purpose: Static, map-placed, respawning resupply pack. Grants grenade
// ammo (and a few other resources) to any player who touches it, then
// hides and reappears after a timer -- the "buckets" that let you
// replenish grenades away from a resupply locker.
//
// This entity classname (item_grenadepack) is expected directly by
// existing maps (ad_dustbowl spawns several, confirmed via
// "Attempted to create unknown entity type item_grenadepack!" before this
// was added) -- it doesn't exist as a native C++ class anywhere in FF's
// real source. Classic FF implements this entirely through its Lua
// map-scripting system (a "genericbackpack" Lua prototype, configured
// per-map -- see ff-game/maps/ff_dustbowl.lua for the exact values this
// is based on: dbgrenadepackone/dbgrenadepacktwo). Since this project
// strips Lua scripting throughout, this is a from-scratch native C++
// port of that mechanic, not a straight translation of existing code --
// see the .cpp for exactly which values are real FF data vs. judgment
// calls made translating FF's ammo model onto TF2's.
//
//===========================================================================//

#ifndef FF_ITEM_GRENADEPACK_H
#define FF_ITEM_GRENADEPACK_H
#ifdef _WIN32
#pragma once
#endif

#include "cbase.h"

class CFFItemGrenadepack : public CBaseAnimating
{
public:
	DECLARE_CLASS( CFFItemGrenadepack, CBaseAnimating );
	DECLARE_DATADESC();

	CFFItemGrenadepack();

	virtual void Spawn( void );
	virtual void Precache( void );

	void RestockTouch( CBaseEntity *pOther );
	void MaterializeThink( void );

private:
	bool	m_bRespawning;		// true while hidden, waiting for the respawn timer
	float	m_flNextRespawnTime;
};

#endif // FF_ITEM_GRENADEPACK_H
