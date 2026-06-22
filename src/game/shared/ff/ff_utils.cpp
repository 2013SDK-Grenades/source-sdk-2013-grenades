//=============================================================================//
//
// Purpose: FF_UTILS - minimal subset
//
// FF Grenade Port: see ff_utils.h for why this isn't the full original file.
//
//=============================================================================//
#include "cbase.h"
#include "ff_utils.h"

#ifdef GAME_DLL
	#include "tf_player.h"
#endif

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// Purpose: Verbatim from FF's ff_utils.cpp. Used by the EMP/EmpProjectile-style
// explode-and-scorch-the-ground logic shared across several ported grenades
// (originally CFFProjectileNail and other CFFProjectileBase-derived classes).
//-----------------------------------------------------------------------------
void FF_DecalTrace( CBaseEntity *pEntity, float flRadius, const char *pszDecalName )
{
#ifdef CLIENT_DLL 
#else
	// If we've gotten here then the normal trace_t passed
	// to the explode function did not find ground below the
	// object. But, that doesn't mean we aren't near something
	// we should draw scorch marks on. So, check above and then
	// around the object for stuff to draw the scorch mark on.

	AssertMsg( pEntity, "FF_DecalTrace - Entity was NULL" );

	Vector vecOrigin = pEntity->GetAbsOrigin();

	trace_t trUp;
	UTIL_TraceLine( vecOrigin, vecOrigin + Vector( 0, 0, flRadius ), MASK_SHOT_HULL, pEntity, COLLISION_GROUP_NONE, &trUp );

	// If the trace never finished (we hit something)
	if( trUp.fraction != 1.0f )
	{
		UTIL_DecalTrace( &trUp, pszDecalName );
		return;
	}

	// Well, didn't hit anything below us (if we did we wouldn't
	// have been in this function in the first place) and we didn't
	// hit anything above us so now "reach out" and try to find
	// something nearby to do scorch marks on for:
	// Bug #0000211: Grens and pipe not drawing explosion soot decal on walls.

	Vector vecEndPos[ 8 ], vecForward, vecRight, vecUp;

	AngleVectors( pEntity->GetAbsAngles(), &vecForward, &vecRight, &vecUp );	

	VectorNormalize( vecForward );
	VectorNormalize( vecRight );
	VectorNormalize( vecUp );

	// Make some points around the object where "O" is the object:
	// . . .
	// . O .
	// . . .

	vecEndPos[ 0 ] = vecOrigin + ( vecForward * flRadius ) - ( vecRight * flRadius );
	vecEndPos[ 1 ] = vecOrigin + ( vecForward * flRadius );
	vecEndPos[ 2 ] = vecOrigin + ( vecForward * flRadius ) + ( vecRight * flRadius );
	vecEndPos[ 3 ] = vecOrigin - ( vecRight * flRadius );
	vecEndPos[ 4 ] = vecOrigin + ( vecRight * flRadius );
	vecEndPos[ 5 ] = vecOrigin - ( vecForward * flRadius ) - ( vecRight * flRadius );
	vecEndPos[ 6 ] = vecOrigin - ( vecForward * flRadius );
	vecEndPos[ 7 ] = vecOrigin - ( vecForward * flRadius ) + ( vecRight * flRadius );

	// Go ahead and compute this now to use later
	vecUp *= flRadius;

	// For the traces
	trace_t tr[ 24 ];
	// Which trace we're on
	int iTraceCount = 0;
	// Index to use for the shortest trace
	int iIndex = -1;
	// To keep track of shortest distance
	float flDist = flRadius * flRadius;
	
	// Do 24 traces - EEK
	for( int j = -1; j <= 1; j++ )
	{
		for( int i = 0; i < 8; i++ )
		{
			// Want to make sure we're only tracing out flRadius units
			// so get a direction vector facing the outward point(s)
			Vector vecDir = ( vecEndPos[ i ] + ( j * vecUp ) ) - vecOrigin;
			VectorNormalize( vecDir );

			UTIL_TraceLine( vecOrigin, vecOrigin + ( vecDir * flRadius ), MASK_SHOT_HULL, pEntity, COLLISION_GROUP_NONE, &tr[ iTraceCount++ ] );

			// [Trace didn't finish so] we hit something
			if( tr[ iTraceCount - 1 ].fraction != 1.0f )
			{
				// Is this distance closer?
				if( vecOrigin.DistTo( tr[ iTraceCount - 1 ].endpos ) < flDist )
				{
					// Store off this trace index since it's the closet so far
					iIndex = iTraceCount - 1;
				}
			}
		}
	}

	if( iIndex != -1 )
	{
		UTIL_DecalTrace( &tr[ iIndex ], pszDecalName );
	}
#endif
}

//-----------------------------------------------------------------------------
// Purpose: Verbatim from FF's ff_utils.cpp -- See if a trace hit the world
//-----------------------------------------------------------------------------
bool FF_TraceHitWorld( trace_t *pTrace )
{
	if( !pTrace )
		return false;

	if( pTrace->DidHitWorld() )
		return true;

	if( pTrace->m_pEnt == NULL )
		return false;

	if( pTrace->m_pEnt->GetMoveType() == MOVETYPE_PUSH )
	{
		// All doors are push, but not all things that push are doors. This 
		// narrows the search before we start to do classname compares.
		if( FClassnameIs( pTrace->m_pEnt, "prop_door_rotating" ) ||
			FClassnameIs( pTrace->m_pEnt, "func_door" ) ||
			FClassnameIs( pTrace->m_pEnt, "func_door_rotating" ) ||
			FClassnameIs( pTrace->m_pEnt, "func_breakable" ) )
			return true;
	}

	return false;
}

#ifdef GAME_DLL
// FF Grenade Port: was FCVAR_FF_FFDEV_REPLICATED, an FF-specific macro defined in FF's
// own modified public/tier1/iconvar.h (== FCVAR_CHEAT|FCVAR_NOTIFY|FCVAR_REPLICATED).
// We're using stock SDK 2013's unmodified iconvar.h, so spelled out directly here
// instead of touching a stock public header for one macro.
ConVar ffdev_airshot_height_threshold( "ffdev_airshot_height_threshold", "72", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_REPLICATED, "Minimum height a player has to be off the ground for a direct hit to count as an airshot" );
#define FFDEV_AIRSHOT_HEIGHT_THRESHOLD ffdev_airshot_height_threshold.GetFloat()

//-----------------------------------------------------------------------------
// Purpose: Adapted from FF's ff_utils.cpp -- CFFPlayer -> CTFPlayer, ToFFPlayer ->
// ToTFPlayer (ff_player.cpp isn't being ported; see ff_utils.h). Everything else
// (the actual airshot detection logic) is unchanged.
//-----------------------------------------------------------------------------
bool FF_IsAirshot( CBaseEntity *pEntity, float flThresholdMultiplier/*=1.0f*/ )
{
	if (!pEntity || !pEntity->IsPlayer())
		return false;

	CTFPlayer *pPlayer = ToTFPlayer( pEntity );

	// if on the ground, in water, or on a ladder: no airshot
	if (!pPlayer || pPlayer->GetFlags() & FL_ONGROUND || pPlayer->GetWaterLevel() != WL_NotInWater || pPlayer->IsOnLadder())
		return false;

	trace_t tr;
	Vector vecStartPos = pPlayer->GetAbsOrigin();
	vecStartPos.z += pPlayer->GetPlayerMins()[ 2 ];
	Vector vecEndPos = vecStartPos - Vector(0,0,FFDEV_AIRSHOT_HEIGHT_THRESHOLD*flThresholdMultiplier);
	UTIL_TraceLine( vecStartPos, vecEndPos, MASK_PLAYERSOLID_BRUSHONLY, pPlayer, COLLISION_GROUP_PLAYER_MOVEMENT, &tr );

	if (!tr.DidHit())
		return true;
	else
		return false;
}
#endif
