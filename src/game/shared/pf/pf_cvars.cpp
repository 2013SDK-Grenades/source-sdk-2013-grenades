// PF2C port: trimmed to grenade-relevant ConVars only.
#include "cbase.h"
#include "pf_cvars.h"

#ifdef CLIENT_DLL
ConVar pf_projectilelight( "pf_projectilelight", "0", FCVAR_ARCHIVE, "Enable dynamic lights for grenades and rockets" );
#else
ConVar pf_grenadepack_respawn_time( "pf_grenadepack_respawn_time", "20", FCVAR_NOTIFY, "Respawn time for grenade packs." );
ConVar pf_grenades_infinite( "pf_grenades_infinite", "0", FCVAR_NOTIFY, "Player can throw an unlimited amount of grenades" );
ConVar pf_concuss_effect_disable( "pf_concuss_effect_disable", "0", FCVAR_NOTIFY | FCVAR_SERVER_CAN_EXECUTE, "Disables the camera shake from concussion grenade" );
#endif
ConVar pf_grenades( "pf_grenades", "1", FCVAR_NOTIFY | FCVAR_REPLICATED, "Toggle the grenades in-game" );
ConVar pf_grenade_holstering( "pf_grenade_holstering", "1", FCVAR_NOTIFY | FCVAR_REPLICATED );
