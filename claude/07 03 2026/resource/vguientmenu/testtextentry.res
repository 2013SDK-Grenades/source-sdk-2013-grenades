"Resource/ui/testtextentry.res"
{
	"VGUI_EntMenu"
	{
		"ControlName"		"CVGUI_EntMenu"
		"fieldName"			"VGUI_EntMenu"
		"Moveable"			"0"
		"Resizeable"		"0"
		"autoResize"		"0"
		"pinCorner"			"0"
		"visible"			"1"
		"enabled"			"1"
	}
	
	"InfoText"
	{
		"ControlName"	"Label"
		"fieldName"		"InfoText"
		"xpos"			"15"
		"ypos"			"10"
		"wide"			"240"
		"tall"			"30"
		"labelText"		"What could this password be?"
	}
	
	"TextBox"
	{
		"ControlName"	"TextEntry"
		"fieldName"		"TextBox"
		"xpos"			"15"
		"ypos"			"50"
		"wide"			"240"
		"tall"			"30"
		"autoResize"	"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"	"0"
		"textHidden"	"0"
		"editable"		"1"
		"maxchars"		"-1"
		"NumericInputOnly"		"0"
	}
	
	"KeyOk"
	{
		"ControlName"	"Button"
		"fieldName"		"KeyOk"
		"xpos"			"185"
		"ypos"			"100"
		"wide"			"80"
		"tall"			"30"
		"visible"		"1"
		"enabled"		"1"
		"command"		"FireEntry TextBox"

		"labelText" 		"#MessageBox_OK"
		"textAlignment"		"center"
		"font"				"HudFontSmallBold"
		"border_default"	"128 128 128 128"
		"border_armed"		"32 32 32 32"
		"defaultFgColor_override"	"255 255 255 255"
		"defaultBgColor_override"	"64 64 64 64"
		"armedFgColor_override"		"255 255 255 255"
		"armedBgColor_override"		"200 200 200 128"
		"selectedBgColor_override"	"32 32 32 32"
		"selectedFgColor_override"	"255 255 255 255"
		"sound_depressed"	"ui/buttonclick.wav"
		"sound_released"	"ui/buttonclickrelease.wav"
	}
}
