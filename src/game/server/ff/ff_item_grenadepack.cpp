//========= FF Grenade Port ===============================================//
//
// Purpose: item_grenadepack -- see header for full background. This is a
// from-scratch native port of FF's Lua-configured "genericbackpack"
// mechanic, not a translation of existing C++ (none exists -- FF's own
// C++ backpack class, ff_item_backpack.cpp, is for the DROPPED-on-death
// case, a different entity with a different lifecycle; it doesn't
// respawn, this does). Used ff_item_backpack.cpp's touch/collision/
// ammo-granting pattern as a structural reference, and ff-game's
// ff_dustbowl.lua (dbgrenadepackone/dbgrenadepacktwo) as the source for
// every grant value below -- both are real FF data, not guesses.
//
// Grant values and their sourcing, so this is auditable later:
//   Grenades: gren1 += 2, gren2 += 2
//     -- directly from ff_dustbowl.lua's gren1/gren2 fields. This is the
//        one Dan specifically asked for; no ambiguity here.
//   Health: += 100
//     -- ff_dustbowl.lua has TWO grenadepack instances, one with
//        health=300, one with health=100. Picked the smaller, more
//        conservative value as a single default since this entity
//        doesn't yet support per-map-entity configuration (see below).
//   Primary/Secondary ammo: += 50 each
//     -- NOT a direct FF value. FF's real data is per-weapon-type
//        (nails=50, shells=50, rockets=20, mancannons=1), which doesn't
//        map onto TF2's abstracted primary/secondary ammo pools 1:1.
//        50/50 is a judgment call capturing "meaningful resupply, not a
//        full refill" rather than a faithful translation of those exact
//        numbers. Flag if this should be tuned.
//   Armor: NOT implemented.
//     -- TF2 (and this port) has no armor stat anywhere. Real FF value
//        was armor=100. Adding a new player stat system as a side effect
//        of this entity is out of scope; flagging rather than skipping
//        silently.
//
// Also not implemented: per-map-entity configuration of these values
// (real FF gets this from Lua per map/per pack instance -- e.g. the two
// dustbowl packs differ only in health). Every item_grenadepack placed by
// any map currently grants the same fixed amounts. Revisit with
// KeyValues/DATADESC input fields if per-instance tuning turns out to
// matter.
//
//===========================================================================//

#include "cbase.h"
#include "ff_item_grenadepack.h"
#include "tf_player.h"
#include "tf_shareddefs.h"

#include "tier0/memdbgon.h"

#define GRENADEPACK_MODEL			"models/items/backpack/backpack.mdl"
#define GRENADEPACK_TOUCH_SOUND		"Backpack.touch"
#define GRENADEPACK_MATERIALIZE_SOUND	"Item.Materialize"
#define GRENADEPACK_RESPAWN_TIME	15.0f		// ff_dustbowl.lua: respawntime = 15
#define GRENADEPACK_PICKUP_BOX_BLOAT	24			// matches ff_item_backpack.cpp
#define GRENADEPACK_SPIN_CONTEXT	"GrenadepackSpinThink"
#define GRENADEPACK_SPIN_INTERVAL	0.05f		// 20 updates/sec, smooth without being wasteful
#define GRENADEPACK_SPIN_DEGREES	3.0f		// degrees of yaw per update -> full turn in 5s

#define GRENADEPACK_GREN1			2			// ff_dustbowl.lua: gren1 = 2
#define GRENADEPACK_GREN2			2			// ff_dustbowl.lua: gren2 = 2
#define GRENADEPACK_HEALTH			100			// ff_dustbowl.lua health value (conservative pick, see header)
#define GRENADEPACK_PRIMARY_AMMO	50			// judgment call, see header
#define GRENADEPACK_SECONDARY_AMMO	50			// judgment call, see header

BEGIN_DATADESC( CFFItemGrenadepack )
	DEFINE_ENTITYFUNC( RestockTouch ),
	DEFINE_THINKFUNC( MaterializeThink ),
	DEFINE_THINKFUNC( SpinThink ),
END_DATADESC();

LINK_ENTITY_TO_CLASS( item_grenadepack, CFFItemGrenadepack );
PRECACHE_REGISTER( item_grenadepack );

CFFItemGrenadepack::CFFItemGrenadepack()
{
	m_bRespawning = false;
	m_flNextRespawnTime = 0.0f;
}

void CFFItemGrenadepack::Precache( void )
{
	PrecacheModel( GRENADEPACK_MODEL );
	PrecacheScriptSound( GRENADEPACK_TOUCH_SOUND );
	PrecacheScriptSound( GRENADEPACK_MATERIALIZE_SOUND );
}

void CFFItemGrenadepack::Spawn( void )
{
	Precache();

	// FF Grenade Port: matches ff_item_backpack.cpp's collision setup exactly --
	// see "Bug #0000131" comment there re: not fully solid so it doesn't stop
	// rockets, but still traceable (sniper dot, etc.) via the trigger bounds.
	// COLLISION_GROUP_NONE here, not FF's COLLISION_GROUP_TRIGGERONLY -- that's
	// an FF-specific addition to Collision_Group_t that doesn't exist in stock
	// SDK2013's enum (public/const.h). SOLID_NONE + FSOLID_TRIGGER already give
	// "no physical collision, still trigger-touchable"; NONE is the safe,
	// always-valid default for the group itself.
	SetSolid( SOLID_NONE );
	AddSolidFlags( FSOLID_NOT_STANDABLE | FSOLID_TRIGGER );
	SetCollisionGroup( COLLISION_GROUP_NONE );

	SetMoveType( MOVETYPE_NONE );

	SetModel( GRENADEPACK_MODEL );

	CollisionProp()->UseTriggerBounds( true, GRENADEPACK_PICKUP_BOX_BLOAT );

	SetTouch( &CFFItemGrenadepack::RestockTouch );

	// FF Grenade Port: spin added per Dan's request, not something confirmed from
	// FF's real data -- the Lua source has no rotation/spin field at all, so this
	// is a deliberate FC-specific visual choice (matching TF2's own ammo/health
	// pickups), not a restoration of FF behavior. Named context so it runs
	// independently of MaterializeThink()'s respawn-timer think below -- default
	// SetThink()/SetNextThink() only support one active think at a time; this
	// needs two running simultaneously.
	SetContextThink( &CFFItemGrenadepack::SpinThink, gpGlobals->curtime, GRENADEPACK_SPIN_CONTEXT );

	m_bRespawning = false;
}

void CFFItemGrenadepack::RestockTouch( CBaseEntity *pOther )
{
	if ( m_bRespawning )
		return;

	if ( !pOther->IsPlayer() )
		return;

	CTFPlayer *pTFPlayer = ToTFPlayer( pOther );
	if ( !pTFPlayer || !pTFPlayer->IsAlive() )
		return;

	pTFPlayer->GiveAmmo( GRENADEPACK_GREN1, TF_AMMO_GRENADES1 );
	pTFPlayer->GiveAmmo( GRENADEPACK_GREN2, TF_AMMO_GRENADES2 );
	pTFPlayer->GiveAmmo( GRENADEPACK_PRIMARY_AMMO, TF_AMMO_PRIMARY );
	pTFPlayer->GiveAmmo( GRENADEPACK_SECONDARY_AMMO, TF_AMMO_SECONDARY );
	pTFPlayer->TakeHealth( GRENADEPACK_HEALTH, DMG_GENERIC );

	EmitSound( GRENADEPACK_TOUCH_SOUND );

	// FF Grenade Port: hide + go non-solid + wait, rather than UTIL_Remove like
	// the drop-pack does -- this one respawns, it doesn't get consumed forever.
	AddEffects( EF_NODRAW );
	SetSolid( SOLID_NONE );
	RemoveSolidFlags( FSOLID_TRIGGER );
	SetTouch( NULL );

	m_bRespawning = true;
	m_flNextRespawnTime = gpGlobals->curtime + GRENADEPACK_RESPAWN_TIME;

	SetThink( &CFFItemGrenadepack::MaterializeThink );
	SetNextThink( m_flNextRespawnTime );
}

void CFFItemGrenadepack::SpinThink( void )
{
	QAngle angles = GetLocalAngles();
	angles.y += GRENADEPACK_SPIN_DEGREES;
	SetLocalAngles( angles );

	SetContextThink( &CFFItemGrenadepack::SpinThink, gpGlobals->curtime + GRENADEPACK_SPIN_INTERVAL, GRENADEPACK_SPIN_CONTEXT );
}

void CFFItemGrenadepack::MaterializeThink( void )
{
	RemoveEffects( EF_NODRAW );
	SetSolid( SOLID_NONE );
	AddSolidFlags( FSOLID_NOT_STANDABLE | FSOLID_TRIGGER );
	SetCollisionGroup( COLLISION_GROUP_NONE );	// see Spawn() for why NONE, not FF's TRIGGERONLY

	SetTouch( &CFFItemGrenadepack::RestockTouch );
	SetThink( NULL );

	m_bRespawning = false;

	EmitSound( GRENADEPACK_MATERIALIZE_SOUND );
}
