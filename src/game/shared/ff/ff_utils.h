//=============================================================================//
//
// Purpose: FF_UTILS - minimal subset
//
// FF Grenade Port: this is NOT the original ff_utils.h. The real FF file is ~1,870
// lines (.h+.cpp combined) and pulls in ff_player.h/ff_gamerules.h/ff_team.h/Lua
// (ff_scriptman.h) -- exactly the subsystems this project has deliberately avoided
// porting throughout. A project-wide search confirmed our ported grenade/projectile
// files actually use exactly 4 symbols from it: FF_DECALTRACE_TRACE_DIST (a constant),
// FF_DecalTrace(), FF_TraceHitWorld(), and FF_IsAirshot(). All 4 are reproduced here
// verbatim from the real FF source, with FF_IsAirshot() retargeted from CFFPlayer to
// CTFPlayer (the same ToFFPlayer -> ToTFPlayer swap applied everywhere else), since
// CFFPlayer isn't being ported either. Nothing else from the original file is here --
// if a future grenade file needs something else from it, that symbol should be added
// the same way these were: verified against the real FF source, not guessed.
//
//=============================================================================//
#ifndef FF_UTILS_H
#define FF_UTILS_H
#ifdef _WIN32
#pragma once
#endif

#define FF_DECALTRACE_TRACE_DIST	48.0f

void FF_DecalTrace( CBaseEntity *pEntity, float flRadius, const char *pszDecalName );
bool FF_TraceHitWorld( trace_t *pTrace );
bool FF_IsAirshot( CBaseEntity *pEntity, float flThresholdMultiplier = 1.0f );

// FF Grenade Port: added 2026-07-14. TF2's own CTFGameRules::RadiusDamage() has a
// structurally different falloff (RemapValClamped from full damage down to
// damage*(damage/radius) -- never reaches 0 inside the radius) than FF's
// CFFGameRules::RadiusDamage() (linear: damage - distance*0.5, hard zero cutoff),
// and TF2 only grants its own self-damage reduction to 4 hardcoded native weapon
// IDs that don't include our grenades. Together that produced verified-correct
// FF damage/radius numbers still feeling wildly excessive in actual play. This is
// a faithful port of FF's real formula for OUR grenades specifically -- it does NOT
// touch CTFGameRules::RadiusDamage(), so every other explosive in the mod (rockets,
// stickies) is unaffected.
//
// Ported verbatim: the core falloff formula, the hard <=0 cutoff, the 2/3 self-
// damage multiplier (CFFGameRules::GetAdjustedDamage), the FL_GRENADE trace filter
// (stops grenades blocking each other's LOS to a target).
//
// Deliberately NOT ported (flagged, not silently dropped):
//  - FF's player-hitbox distance-adjustment hack (the dH/dV block in the real
//    RadiusDamage, guarded by USE_HITBOX_HACK). That math is tuned to FF's own
//    player hull dimensions; applying it verbatim to TF2's different hulls could
//    introduce new inaccuracy rather than fix one. Flag if you want this revisited.
//  - The buildable-under-construction skip -- FF's own source comments call this
//    out as checking the inflictor instead of the victim ("Bug? - AfterShock").
//    Reproducing a bug FF's own devs flagged as questionable isn't "doing it right".
//  - The backpack-explosion special case -- FF backpacks aren't ported.
//  - The Engineer-takes-half-damage-from-own-building clause in GetAdjustedDamage --
//    only triggers when the inflictor is a buildable, which is never true for a
//    thrown hand grenade (inflictor is always the grenade itself), so it's dead
//    code for every one of our 11 grenade types.
//  - FF's blood-decal/TraceBleed visuals -- TF2 has its own hit-feedback pipeline
//    that already fires through TakeDamage(); this doesn't need a manual HL2-style
//    blood-decal pass on top of it.
void FF_RadiusDamage( const CTakeDamageInfo &info, const Vector &vecSrcIn, float flRadius, int iClassIgnore, CBaseEntity *pEntityIgnore );

#endif // FF_UTILS_H
