//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef TF_HUD_AMMOSTATUS_H
#define TF_HUD_AMMOSTATUS_H
#ifdef _WIN32
#pragma once
#endif

#define TF_MAX_GRENADES			4
#define TF_MAX_FILENAME_LENGTH	128

//-----------------------------------------------------------------------------
// Purpose:  Displays weapon ammo data
//-----------------------------------------------------------------------------
class CTFHudWeaponAmmo : public CHudElement, public vgui::EditablePanel
{
	DECLARE_CLASS_SIMPLE( CTFHudWeaponAmmo, vgui::EditablePanel );

public:

	CTFHudWeaponAmmo( const char *pElementName );

	virtual void ApplySchemeSettings( vgui::IScheme *pScheme );
	virtual void Reset();

	virtual bool ShouldDraw( void );

protected:

	virtual void OnThink();

private:
	
	void UpdateAmmoLabels( bool bPrimary, bool bReserve, bool bNoClip );
	void ShowLowAmmoIndicator( void );
	void SizeLowAmmoIndicator( float flCurrentAmount, float flMaxAmount );
	void HideLowAmmoIndicator( void );

private:

	float							m_flNextThink;

	CHandle<C_BaseCombatWeapon>		m_hCurrentActiveWeapon;
	int								m_nAmmo;
	int								m_nAmmo2;

	int								m_nLowAmmoImageOrigX;
	int								m_nLowAmmoImageOrigY;
	int								m_nLowAmmoImageOrigW;
	int								m_nLowAmmoImageOrigH;

	CExLabel						*m_pInClip;
	CExLabel						*m_pInClipShadow;
	CExLabel						*m_pInReserve;
	CExLabel						*m_pInReserveShadow;
	CExLabel						*m_pNoClip;
	CExLabel						*m_pNoClipShadow;
	vgui::ImagePanel				*m_pLowAmmoImage;
};

//-----------------------------------------------------------------------------
// Purpose:  Displays grenade ammo counts (grenade1 and grenade2 slots).
//           PF2C port — stripped CTFInventory dependency, uses GetAmmoCount directly.
//-----------------------------------------------------------------------------
class CTFHudGrenadeAmmo : public CHudElement, public vgui::EditablePanel
{
	DECLARE_CLASS_SIMPLE( CTFHudGrenadeAmmo, vgui::EditablePanel );

public:

	CTFHudGrenadeAmmo( const char *pElementName );

	virtual void ApplySchemeSettings( vgui::IScheme *pScheme );
	virtual void Reset();

	virtual bool ShouldDraw( void );

protected:

	virtual void OnThink();

private:
	void UpdateGrenadesLabels( bool bGrenades1, bool bGrenades2 );

private:

	float						m_flNextThink;

	int							m_nGrenades1;
	int							m_nGrenades2;

	CExLabel					*m_pGrenades1;
	CExLabel					*m_pGrenades1Shadow;
	CExLabel					*m_pGrenades2;
	CExLabel					*m_pGrenades2Shadow;
};

#endif	// TF_HUD_AMMOSTATUS_H
