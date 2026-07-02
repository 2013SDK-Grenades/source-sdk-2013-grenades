// PF2C grenade port — HudLayout.res override.
// The engine merges this with TF2's base HudLayout.res from the VPK,
// so we only need to list the elements we are adding.
"Resource/UI/HudLayout.res"
{
	HudGrenadeAmmo
	{
		"fieldName"		"HudGrenadeAmmo"
		"visible"		"1"
		"enabled"		"1"
		"xpos"			"r99"	[$WIN32]
		"ypos"			"r73"	[$WIN32]
		"xpos"			"r131"	[$X360]
		"ypos"			"r77"	[$X360]
		"wide"			"90"
		"tall"			"65"
	}

	HudSmokeBomb
	{
		"fieldName"		"HudSmokeBomb"
		"visible"		"1"
		"enabled"		"1"
		"xpos"			"r99"
		"ypos"			"r90"
		"wide"			"90"
		"tall"			"20"
	}

	HudPlayerConditions
	{
		"fieldName"		"HudPlayerConditions"
		"visible"		"1"
		"enabled"		"1"
		"xpos"			"10"
		"ypos"			"180"
		"wide"			"40"
		"tall"			"200"
		"bgcolor_override"	"255 0 0 0"
	}
}
