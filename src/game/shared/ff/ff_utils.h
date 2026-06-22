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

#endif // FF_UTILS_H
