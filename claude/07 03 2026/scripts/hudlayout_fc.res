#base "../scripts/hudlayout.res"

"Resource/HudLayout_fc.res"
{
	HudBombIcon
	{
		"fieldName" "HudBombIcon"
		"visible" "1"
		"enabled" "1"
		"wide"	"f0"
		"tall"	"480"
		"xpos"	"c-70"
		"ypos"	"c185"
	}
	HUDQuickInfo
	{
		"fieldName" "HUDQuickInfo"
		"visible" "1"
		"enabled" "1"
		"wide"	 "640"
		"tall"	 "480"
	}
	HudPosture
	{
		"fieldName" 		"HudPosture"
		"visible" 		"1"
		"PaintBackgroundType"	"2"
		"xpos"	"16"
		"ypos"	"316"
		"tall"  "36"
		"wide"	"36"
		"font"	"WeaponIconsSmall"
		"icon_xpos"	"10"
		"icon_ypos" 	"0"
	}
	HudProgressBar
	{
		"fieldName" "HudProgressBar"
		"xpos"	"c-150"
		"ypos"	"300"
		"wide"	"300"
		"tall"  "15"
		"visible" "1"
		"enabled" "1"

		"BorderThickness" "1"

		"PaintBackgroundType"	"2"
	}
	
	HudRadar
	{
		"fieldName" "HudRadar"
		"visible"	"1"
		"enabled"	"1"
		"xpos"		"16"
		"ypos"		"16"
		"wide"		"96"
		"tall"		"96"
	}

	HudLocation
	{
		"fieldName" "HudLocation"
		"visible"	"1"
		"enabled"	"1"
		"xpos"		"16"
		"ypos"		"112"
		"wide"		"96"
		"tall"		"16"
		"textAlignment"	"north"
	}
	overview
	{
		"fieldname"				"overview"
		"visible"				"1"
		"enabled"				"1"
		"xpos"					"0"
		"ypos"					"480"
		"wide"					"0"
		"tall"					"0"
	}
	
	HudHintDisplay
	{
		"fieldName"	"HudHintDisplay"
		"visible"	"0"
		"enabled" "1"
		"xpos"		"c-240"
		"ypos"		"c60"
		"wide"		"480"
		"tall"		"100"
		"text_xpos"	"8"
		"text_ypos"	"8"
		"center_x"	"0"	// center text horizontally
		"center_y"	"-1"	// align text on the bottom
		"HintSize"	"1"
	}

	HudHintKeyDisplay
	{
		"fieldName"	"HudHintKeyDisplay"
		"visible"	"0"
		"enabled" 	"1"
		"xpos"		"r120"
		"ypos"		"r340"
		"wide"		"100"
		"tall"		"200"
		"text_xpos"	"8"
		"text_ypos"	"8"
		"text_xgap"	"8"
		"text_ygap"	"8"
		"TextColor"	"255 170 0 220"

		"PaintBackgroundType"	"2"
	}
	
	RadialMenu
	{
		"fieldName" "RadialMenu"
		"visible" "1"
		"enabled" "1"
		"wide"	 "2450"
		"tall"	 "480"		
	}
	
	HudWeaponSecondaryAmmo
	{
		"fieldName"				"HudWeaponSecondaryAmmo"
		"xpos"					"r162"	[$WIN32]
		"ypos"					"r152"	[$WIN32]
		"ypos_minmode"			"r134"	[$WIN32]
		"xpos"					"r194"	[$X360]
		"ypos"					"r174"	[$X360]
		"wide"					"116"
		"tall"  				"180"
		"visible" 				"1"
		"enabled" 				"1"
		"PaintBackgroundType"	"2"
	}

	HudSuitPower
	{
		"fieldName" "HudSuitPower"
		"visible" "1"
		"enabled" "1"
		"xpos"	"-32"	[$WIN32]
		"ypos"	"r170"	[$WIN32]
		"wide"	"200"
		"tall"	"100"
	}
	
	HudTeleportMeter
	{
		"fieldName"		"HudTeleportMeter"
		"visible"		"1"
		"enabled"		"1"
		"xpos"			"r190"	
		"ypos"			"r69"
		"wide"			"116"
		"tall"  		"180"
		"visible"		"1"
		"enabled"		"1"
		"MeterFG"		"White"
		"MeterBG"		"Gray"
	}
	
	HudFlashlight
	{
		"fieldName" "HudFlashlight"
		"visible" "1"
		"enabled" "1"
		"xpos"	"16"
		"ypos"	"370"
		"wide"	"102"
		"tall"	"20"
		
		"text_xpos" "8"
		"text_ypos" "6"
		"TextColor"	"255 170 0 220"

		"PaintBackgroundType"	"2"
	}

	
	HudLocator
	{
		"fieldName" "HudLocator"
		"visible" "1"
		"PaintBackgroundType"	"2"
		"xpos"	"c8"	[$WIN32]
		"ypos"	"r36"	[$WIN32]
		"xpos"	"c-32"	[$X360]
		"ypos_hidef"	"r52"	[$X360]
		"ypos_lodef"	"r95"	[$X360]		// 52 is aligned to bottom of HudSuit
		"wide"	"64"
		"tall"  "24"
	}

	HudSquadStatus
	{
		"fieldName"	"HudSquadStatus"
		"visible"	"1"
		"enabled" "1"
		"xpos"	"r118"
		"ypos"	"375"
		"wide"	"120"
		"tall"	"46"
		"text_xpos"	"8"
		"text_ypos"	"34"
		"SquadIconColor"	"255 220 0 160"
		"IconInsetX"	"8"
		"IconInsetY"	"0"
		"IconGap"		"24"

		"PaintBackgroundType"	"0"
	}

	CoOpWinPanel
	{
		"fieldName"				"CoOpWinPanel"
		"visible"				"1"
		"enabled"				"1"
		"xpos"					"c-150"
		"ypos"					"255"
		"wide"					"300"
		"tall"					"215"
	}
	
	HudCredits
	{
		"fieldName"	"HudCredits"
		"TextFont"	"Default"
		"visible"	"1"
		"xpos"	"0"
		"ypos"	"0"
		"wide"	"640"
		"tall"	"480"
		"TextColor"	"255 255 255 192"

	}
	
	HudGrenadeAmmo
	{
		"fieldName" "HudGrenadeAmmo"
		"visible" "1"
		"enabled" "1"
		"xpos"	"r95"
		"xpos_minmode"	"r85"
		"ypos"	"r105"
		"ypos_minmode"	"r86"
		"wide"	"94"
		"tall"	"70"
	}
	
	HudDeathNotice
	{
		"fieldName" "HudDeathNotice"
		"visible" "1"
		"enabled" "1"
		"xpos"	 "r640"	[$WIN32]
		"ypos"	 "18"	[$WIN32]
		"xpos"	 "r672"	[$X360]
		"ypos"	 "35"	[$X360]
		"wide"	 "628"
		"tall"	 "468"

		"MaxDeathNotices" "4"
		"IconScale"	  "0.35"
		"LineHeight"	  "16"
		"LineSpacing"	  "4"
		"CornerRadius"	  "3"
		"RightJustify"	  "1"	// If 1, draw notices from the right
		
		"TextFont"		"Default"
		
		"TeamBlue"		"HUDBlueTeamSolid"
		"TeamRed"		"HUDRedTeamSolid"
		"IconColor"		"HudWhite"
		"LocalPlayerColor"	"HUDBlack"

		"BaseBackgroundColor"	"46 43 42 220"		[$WIN32]
		"LocalBackgroundColor"	"245 229 196 200"	[$WIN32]
		"BaseBackgroundColor"	"32 32 32 255"		[$X360]
		"LocalBackgroundColor"	"0 0 0 255"		[$X360]
	}
	
	HudCrosshair
	{
		"fieldName" "HudCrosshair"
		"visible" "1"
		"enabled" "1"
		"wide"	 "640"
		"tall"	 "480"
	}
	
	HudTFCrosshair
	{
		"fieldName" "HudTFCrosshair"
		"visible" "1"
		"enabled" "1"
		"wide"	 "640"
		"tall"	 "480"
	}
}
