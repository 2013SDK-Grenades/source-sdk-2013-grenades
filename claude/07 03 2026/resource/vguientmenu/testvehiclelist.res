"resource/vguientmenu/testvehiclelist.res"
{
	"VGUI_EntMenu"
	{
		"ControlName"		"CVGUI_EntMenu"
		"fieldName"			"VGUI_EntMenu"
		
		// Relative to resource/
		//"CustomScheme"		"ClientScheme_dark"
		
		// 0 square corners
		// 1 Transparent fade from top left
		// 2 default rounded corners
		// 3 Transparent fade from right
		"PaintBackgroundType" "2"
		
		"wide"				"390"
		"tall"				"350"
		"fgcolor"			"255 255 255"
		"bgcolor"			"64 64 64"
		"Moveable"			"0"
		"Resizeable"		"0"
		"autoResize"		"0"
		"pinCorner"			"0"
		"visible"			"1"
		"enabled"			"1"
	}
	
	"InfoText"
	{
		"ControlName"	"CExLabel"
		"fieldName"		"InfoText"
		"xpos"			"140"
		"ypos"			"5"
		"wide"			"240"
		"tall"			"30"
		"font"			"HudFontBiggerBold"
		"labelText"		"Select something to spawn"
	}
	
	"ListOfPanels"
	{
		"ControlName"		"PanelListPanel"
		"fieldName"			"ListOfPanels"
		"xpos"				"15"
		"ypos"				"30"
		"wide"				"370"
		"tall"				"280"
		"autoResize"		"0"
		"pinCorner"			"0"
		"visible"			"1"
		"enabled"			"1"
		"tabPosition"		"0"
		"bgcolor_override"	"100 100 100 50"
		"font"				"HudFontSmall"
		
		// These are mostly auto detected for types
		"Rows"
		{
			// Fires OnCase01 when clicked, futher items continue up to 16 max
			"Forklift" "models/vehicles/cstrike_forklift.mdl;No Weapon"
			"Jeep" "Tau Cannon;models/buggy.mdl"
			"Jeep" "models/buggy.mdl;No Weapon"
			// Images are relative to materials/vgui/
			"Img"	"hud/vote_yes.vmt;TF Something"
			"Remove"	"Remove Vehicles"
			"Text"	"JustText"
		}
	}
	
	// Sets what all the active rows look like
	"RowPanelActive"
	{
		"ControlName"		"VguiEntMenuRowPanel"
		"fieldName"			"RowPanelActive"
		"visible"			"0"
		"labelColor"		"255 255 255 255"
		"fgcolor_override"	"255 255 255 255"
		"bgcolor_override"	"80 80 80 255"
	}
	
	// Sets what unavailable panels look like,
	// panels are made unavailable by inputs to vgui_menu_entity eg: SetPanelUnavailable 1
	"RowPanelUnavailable"
	{
		"ControlName"		"VguiEntMenuRowPanel"
		"fieldName"			"RowPanelUnavailable"
		"visible"			"0"
		"labelText"			"(Unavailable)"
		"labelColor"		"255 255 255 128"
		"fgcolor_override"	"255 255 255 128"
		"bgcolor_override"	"0 0 0 128"
	}
	
	// Sets what unavailable panels look like,
	// panels are made unavailable by inputs to vgui_menu_entity eg: SetPanelLocked 1
	"RowPanelLocked"
	{
		"ControlName"		"VguiEntMenuRowPanel"
		"fieldName"			"RowPanelLocked"
		"visible"			"0"
		"labelText"			"(Locked)"
		"labelColor"		"255 100 100 255"
		"fgcolor_override"	"255 100 100 255"
		"bgcolor_override"	"80 80 80 255"
	}
}
