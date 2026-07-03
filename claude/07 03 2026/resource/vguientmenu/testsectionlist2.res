"Resource/ui/main_menu/AchievementsDialog.res"
{
	"Run"
	{
		"ControlName"	"Button"
		"fieldName"		"Run"
		"xpos"			"15"
		"ypos"			"240"
		"zpos"			"2"
		"wide"			"124"
		"tall"			"25"
		"visible"		"1"
		"enabled"		"1"
		"command"		"select_section 0"

		"labelText" 		"Back"
		"textAlignment"		"center"
		"font"				"HudFontSmallBold"
		"border_default"	"AdvSquareButtonDefault"
		"border_armed"		"AdvSquareButtonArmed"
		"border_depressed"	"AdvSquareButtonDepressed"
		"paintbackground"   "0"
		"xshift" 			"0"
		"yshift"			"-2"
	}

	"SectionListPanel"
	{
		"ControlName"		"SectionedListPanel"
		"fieldName"		"SectionListPanel"
		"xpos"		"15"
		"ypos"		"25"
		"wide"		"300"
		"tall"		"200"
		"autoResize"		"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"tabPosition"		"1"
		"NumColumns"	"3"
		"ColumnName0"	"This title"
		"ColumnWidth0"	"100"
		"ColumnName1"	"SomeInfo"
		"ColumnWidth1"	"80"
		"ColumnName2"	"Sub info"
		"ColumnWidth2"	"50"
		"ColumnFlags2"	"2"
		"Rows"
		{
			"Page2 Row 1" "Proven to be;maps/menu_thumb_am2"
			"Page2 Row 2" "not so good;resource/mic_meter_dead;showpage testres"
		}
	}
	
}
