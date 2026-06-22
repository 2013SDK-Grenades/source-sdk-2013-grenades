#ifndef PF_CVARS_H
#define PF_CVARS_H

// PF2C port: trimmed to grenade-relevant ConVars only.
#ifdef CLIENT_DLL
extern ConVar pf_projectilelight;
#else
extern ConVar pf_grenadepack_respawn_time;
extern ConVar pf_grenades_infinite;
extern ConVar pf_concuss_effect_disable;
#endif
extern ConVar pf_grenades;
extern ConVar pf_grenade_holstering;
#endif
