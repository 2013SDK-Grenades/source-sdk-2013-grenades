// FF Grenade Port: ported from ff-src/mp/src/game/client/ff/fx/ff_fx_empzap.cpp
// Changes: minimal — g_iEmpRingTexture defined/precached in ff_grenade_emp.cpp (shared).

#include "cbase.h"
#include "c_te_effect_dispatch.h"
#include "beam_flags.h"

// Defined and precached in ff_grenade_emp.cpp
extern int g_iEmpRingTexture;

void FF_FX_EmpZap_Callback( const CEffectData &data )
{
	CBroadcastRecipientFilter filter;

	te->BeamRingPoint( filter, 0, data.m_vOrigin,
		1.0f, 200.0f, g_iEmpRingTexture, 0, 0,
		1, 0.2f, 32, 2550, 255,
		128, 255, 255, 196, 0,
		FBEAM_FADEOUT | FBEAM_SINENOISE );

	te->BeamRingPoint( filter, 0, data.m_vOrigin,
		1.0f, 150.0f, g_iEmpRingTexture, 0, 0,
		1, 0.2f, 32, 2550, 255,
		128, 128, 255, 196, 0,
		FBEAM_FADEOUT | FBEAM_SINENOISE );
}

DECLARE_CLIENT_EFFECT( "FF_EmpZap", FF_FX_EmpZap_Callback );
