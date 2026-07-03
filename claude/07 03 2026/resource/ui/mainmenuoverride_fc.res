"Resource/UI/MainMenuOverride.res"
{
	MainMenuOverride
	{
		"fieldName"		"MainMenuOverride"
		"visible"		"1"
		"enabled"		"1"
		"xpos"			"0"
		"ypos"			"0"
		"zpos"			"0"
		"wide"			"f0"
		"tall"			"480"
		
//		"bgcolor_override"	"0 0 0 240"
		
		"update_url"	"https://store.steampowered.com/news/?filter=updates&appids=3561600"
		"blog_url"		"https://www.teamfortress.com/"
		
		"button_x_offset"	"-285"
		"button_y"			"120"
		"button_y_delta"	"5"
		"button_kv"
		{
			"xpos"			"0"
			"ypos"			"150"
			"wide"			"250"
			"tall"			"26"
			"visible"		"1"

			"SubButton"
			{
				"ControlName"	"CExImageButton"
				"fieldName"		"SubButton"
				"xpos"			"0"
				"ypos"			"0"
				"wide"			"250"
				"tall"			"26"
				"autoResize"	"0"
				"pinCorner"		"3"
				"visible"		"1"
				"enabled"		"1"
				"tabPosition"	"0"
				"textinsetx"	"25"
				"use_proportional_insets" "1"
				"font"			"HudFontSmallBold"
				"textAlignment"	"west"
				"dulltext"		"0"
				"brighttext"	"0"
				"default"		"1"
				"sound_depressed"	"UI/buttonclick.wav"
				"sound_released"	"UI/buttonclickrelease.wav"
				
				"border_default"	"MainMenuButtonDefault"
				"border_armed"		"MainMenuButtonArmed"
				"paintbackground"	"0"
				
				"defaultFgColor_override" "46 43 42 255"
				"armedFgColor_override" "235 226 202 255"
				"depressedFgColor_override" "46 43 42 255"
				
				"image_drawcolor"	"117 107 94 255"
				"image_armedcolor"	"235 226 202 255"
				"SubImage"
				{
					"ControlName"	"ImagePanel"
					"fieldName"		"SubImage"
					"xpos"			"6"
					"ypos"			"6"
					"zpos"			"1"
					"wide"			"14"
					"tall"			"14"
					"visible"		"1"
					"enabled"		"1"
					"scaleImage"	"1"
				}				
			}		
		}
		"VersionLabelVerText"
		{
				"ControlName"		"CExLabel"
				"fieldName"			"VersionLabelVerText"
				"xpos"				"r540"
				"ypos"				"425"
				"zpos"				"0"
				"wide"				"520"
				"tall"				"40"
				"autoResize"		"0"
				"pinCorner"			"0"
				"visible"			"1"
				"enabled"			"1"
				"labelText"			""
				"textAlignment"		"east"
				"fgcolor"			"HudOffWhite"
				"font"				"TF2MenuTitleSmall"
		}
		
		"ControllerText"
		{
				"ControlName"		"CExLabel"
				"fieldName"			"ControllerText"
				"xpos"				"62"
				"ypos"				"425"
				"zpos"				"0"
				"wide"				"520"
				"tall"				"40"
				"autoResize"		"0"
				"pinCorner"			"0"
				"visible"			"1"
				"enabled"			"1"
				"labelText"			""
				"textAlignment"		"west"
				"fgcolor"			"HudOffWhite"
				"font"				"TF2MenuTitleSmall"
		}
		
		"SaxxySettings"
		{
			"xpos"			"0"
			"ypos"			"0"
			"zpos"			"-101"		
			"wide"			"f0"
			"tall"			"480"
			
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			
			"flashbounds_x"	"50"
			"flashbounds_y"	"65"
			"flashbounds_w"	"250"
			"flashbounds_h"	"120"
			
			"flashstartsize_min"	"8"
			"flashstartsize_max"	"12"
			
			"flash_maxscale"		"4"
			
			"flash_lifelength_min"	".1"
			"flash_lifelength_max"	".2"
			
			"curtain_anim_duration"		"4.0"
			"curtain_open_time"		"2.8"
			"flash_start_time"		"4.0"
			
			"initial_freakout_duration"		"15.0"
			"clap_sound_duration"	"10.0"
			
			"CameraFlashSettings"
			{
				"visible"		"1"
				"enabled"		"1"
				"tileImage"		"0"
				"scaleImage"	"1"
				"zpos"			"9"
			}
		}
	}
	
	"mouseoveritempanel"
	{
		"ControlName"	"CItemModelPanel"
		"fieldName"		"mouseoveritempanel"
		"xpos"			"c-70"
		"ypos"			"270"
		"zpos"			"100"
		"wide"			"300"
		"tall"			"300"
		"visible"		"0"
		"bgcolor_override"		"0 0 0 0"
		"noitem_textcolor"		"117 107 94 255"
		"PaintBackgroundType"	"2"
		"paintborder"	"1"
		"border"		"MainMenuBGBorder"
		
		"text_ypos"			"20"
		"text_center"		"1"
		"model_hide"		"1"
		"resize_to_text"	"1"
		"padding_height"	"15"
		
		"attriblabel"
		{
			"font"			"ItemFontAttribLarge"
			"xpos"			"0"
			"ypos"			"30"
			"zpos"			"2"
			"wide"			"140"
			"tall"			"60"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"labelText"		"%attriblist%"
			"textAlignment"	"center"
			"fgcolor"		"117 107 94 255"
			"centerwrap"	"1"
		}
	}
	
	"Background"
	{
		"ControlName"	"ScalableImagePanel"
		"fieldName"		"Background"
		"xpos"			"cs-0.5"
		"ypos"			"0"
		"zpos"			"-200"
		"wide"			"o1.6"
		"tall"			"f0"
		"visible"		"0"
		"enabled"		"1"
		"image"			""
		"scaleImage"	"1"
		"proportionaltoparent"	"1"

		if_wider
		{
			"wide"			"f0"
			"tall"			"o0.628"
		}

		if_taller
		{
			"wide"			"o1.6"
			"tall"			"f0"
		}
		
		if_halloween_0
		{
			"image"		"../console/title_team_halloween2011_widescreen"
		}
		if_halloween_1
		{
			"image"		"../console/title_team_halloween2012_widescreen"
		}
		if_halloween_2
		{
			"image"		"../console/title_team_halloween2013_widescreen"
		}
		if_halloween_3
		{
			"image"		"../console/title_team_halloween2014_widescreen"
		}
		if_halloween_4
		{	
			"image"		"../console/title_team_halloween2015_widescreen"
		}
		if_halloween_5
		{	
			"image"		"../console/title_scream_fortress_2017_widescreen"
		}
		if_fullmoon
		{
			"image"		"../console/title_fullmoon_widescreen"
		}
		if_christmas_0
		{
			"image"		"../console/background_xmas2020_widescreen"
		}
		if_christmas_1
		{
			"image"		"../console/background_xmas2023_widescreen"
		}
	}
	"TFLogoImage"
	{
		"ControlName"	"ImagePanel"
		"fieldName"		"TFLogoImage"
		"xpos"			"60"
		"ypos"			"30"
		"zpos"			"1"
		"wide"			"275"
		"tall"			"80"
		"visible"		"1"
		"enabled"		"1"
		"image"			"../logo/new_tf2_logo"
		"scaleImage"	"1"
		"mouseinputenabled"	"0"
	}	
	
	"TFCharacterImage"
	{
		// "ControlName"	"ImagePanel"
		"fieldName"		"TFCharacterImage"
		"xpos"			"c-250"
		"ypos"			"-80"
		"zpos"			"-99"
		"wide"			"600"
		"tall"			"600"
		"visible"		"1"
		"enabled"		"1"
		"scaleImage"	"1"
	}

	"RankModelPanel"
	{
		"ControlName"	"CPvPRankPanel"
		"fieldName"		"RankModelPanel"
		"xpos"			"cs-0.5-256"
		"ypos"			"cs-0.5-120"

		"zpos"			"-51"
		"wide"			"1000"
		"tall"			"1000"
		"visible"		"0"
		"proportionaltoparent"	"1"
		"mouseinputenabled"	"1"

		"matchgroup"	"MatchGroup_Casual_12v12"

		"show_progress"	"0"
	}

	"CycleRankTypeButton"
	{
	
	}

	"RankTooltipPanel"
	{

	}
	
	"RankPanel"
	{

	}

	"NoGCMessage"
	{

	}

	"NoGCImage"
	{

	}	

	"RankBorder"
	{
		"ControlName"	"EditablePanel"
		"fieldName"		"RankBorder"
		"xpos"			"c-290"
		"ypos"			"94"
		"zpos"			"-100"
		"wide"			"260"
		"tall"			"60"
		"visible"		"0"
		"PaintBackgroundType"	"2"
		"border"		"MainMenuBGBorder"
		"proportionaltoparent"	"1"
	}
	
	"TooltipPanel"
	{
		"ControlName"	"EditablePanel"
		"fieldName"		"TooltipPanel"
		"xpos"			"0"
		"ypos"			"0"
		"zpos"			"10000"
		"wide"			"150"
		"tall"			"50"
		"visible"		"0"
		"PaintBackgroundType"	"2"
		"border"		"MainMenuBGBorder"
		
		"TipSubLabel"
		{
			"ControlName"	"CExLabel"
			"fieldName"		"TipSubLabel"
			"font"			"HudFontSmall"
			"labelText"		"%tipsubtext%"
			"textAlignment"	"center"
			"xpos"			"20"
			"ypos"			"30"
			"zpos"			"2"
			"wide"			"250"
			"tall"			"50"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"fgcolor_override"	"117 107 94 255"
			"wrap"			"1"
		}
		
		"TipLabel"
		{
			"ControlName"	"CExLabel"
			"fieldName"		"TipLabel"
			"font"			"HudFontSmallBold"
			"labelText"		"%tiptext%"
			"textAlignment"	"center"
			"xpos"			"20"
			"ypos"			"5"
			"zpos"			"2"
			"wide"			"140"
			"tall"			"30"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"fgcolor_override"	"235 226 202 255"
			"auto_wide_tocontents" "1"
		}
	}	

	"Notifications_ShowButtonPanel"
	{
	
	}

	"Notifications_Panel"
	{
		
	}
	
	"VRBGPanel"
	{
		"ControlName"	"EditablePanel"
		"fieldName"		"VRBGPanel"
		"xpos"			"c-290"
		"ypos"			"373"
		"zpos"			"-61"
		"wide"			"260"
		"tall"			"38"
		"visible"		"1"
		"PaintBackgroundType"	"2"
		"border"		"MainMenuBGBorder"
	}

	"VRModeButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"VRModeButton"
		"xpos"			"c-285"
		"ypos"			"379"
		"zpos"			"-60"
		"wide"			"270"
		"tall"			"36"
		"visible"		"1"
		"PaintBackgroundType"	"2"

		"navUp"			"ReplayBrowserButton"
		"navDown"		"QuitButton"
		"navRight"		"Notifications_ShowButtonPanel"
		"navToRelay"	"SubButton"

		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"xpos"			"0"
			"ypos"			"0"
			"wide"			"250"
			"tall"			"26"
			"autoResize"	"0"
			"pinCorner"		"3"
			"visible"		"1"
			"enabled"		"1"
			"tabPosition"	"0"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"textAlignment"	"west"
			"dulltext"		"0"
			"brighttext"	"0"
			"default"		"1"
			"sound_depressed"	"UI/buttonclick.wav"
			"sound_released"	"UI/buttonclickrelease.wav"
			
			"border_default"	"MainMenuButtonDefault"
			"border_armed"		"MainMenuButtonArmed"
			"paintbackground"	"0"
			
			"defaultFgColor_override" "46 43 42 255"
			"armedFgColor_override" "235 226 202 255"
			"depressedFgColor_override" "46 43 42 255"
			
			"image_drawcolor"	"117 107 94 255"
			"image_armedcolor"	"235 226 202 255"
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"zpos"			"1"
				"wide"			"14"
				"tall"			"14"
				"visible"		"1"
				"enabled"		"1"
				"scaleImage"	"1"
			}		
		}
	}

	"CompetitiveAccessInfoPanel"
	{
	}

	"FriendsContainer"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"FriendsContainer"
		"xpos"			"r135"
		"ypos"			"140"
		"zpos"			"5"
		"wide"			"130"
		"tall"			"210"
		"visible"		"1"

		"paintbackgroundtype" "2"
		"bgcolor_override"		"OurpleBG"
		
		//"border"		"MainMenuBGBorder"

		"TitleLabel"
		{
			"ControlName"	"CExLabel"
			"fieldName"		"TitleLabel"
			"font"			"HudFontSmallBold"
			"labelText"		"#TF_Competitive_Friends"
			"textAlignment"	"west"
			"xpos"			"7"
			"ypos"			"2"
			"wide"			"f0"
			"tall"			"30"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"0"
			"fgcolor_override"	"255 255 255 255"
		}

		"InnerShadow"
		{
			"ControlName"	"EditablePanel"
			"fieldname"		"InnerShadow"
			"xpos"			"cs-0.5"
			"ypos"			"rs1-10"
			"zpos"			"501"
			"wide"			"f10"
			"tall"			"175"
			"visible"		"0"	
			"PaintBackgroundType"	"0"
			"proportionaltoparent"	"1"
			"mouseinputenabled"	"0"

			"paintborder"	"1"
			"border"		"InnerShadowBorder"
		}

		"SteamFriendsList"
		{
			"ControlName"	"CSteamFriendsListPanel"
			"fieldname"		"SteamFriendsList"
			"xpos"			"cs-0.5"
			"ypos"			"30"
			"zpos"			"500"
			"wide"			"f10"
			"tall"			"175"
			"visible"		"1"
			"proportionaltoparent"	"1"

			"columns_count"	"2"
			"inset_x"		"10"
			"inset_y"		"5"
			"row_gap"		"5"
			"column_gap"	"10"
			"restrict_width"	"0"

			"friendpanel_kv"
			{
				"wide"		"110"
				"tall"		"20"
			}

			"ScrollBar"
			{
				"ControlName"	"ScrollBar"
				"FieldName"		"ScrollBar"
				"xpos"			"rs1-1"
				"ypos"			"0"
				"tall"			"f0"
				"wide"			"7"
				"zpos"			"1000"
				"nobuttons"		"1"
				"proportionaltoparent"	"1"

				"Slider"
				{
					"fgcolor_override"	"TanLight"
				}
		
				"UpButton"
				{
					"ControlName"	"Button"
					"FieldName"		"UpButton"
					"visible"		"0"
				}
		
				"DownButton"
				{
					"ControlName"	"Button"
					"FieldName"		"DownButton"
					"visible"		"0"
				}
			}
		}

		"BelowDarken"
		{
			"ControlName"	"EditablePanel"
			"fieldname"		"BelowDarken"
			"xpos"			"cs-0.5"
			"ypos"			"30"
			"zpos"			"499"
			"wide"			"f10"
			"tall"			"175"
			"visible"		"1"	
			"PaintBackgroundType"	"0"
			"proportionaltoparent"	"1"
			"mouseinputenabled"	"0"

			"bgcolor_override"	"OurpleBG"
		}
	}

	"icon_generator"
	{
		"ControlName"		"CEmbeddedItemModelPanel"
		"fieldName"		"icon_generator"

		"xpos"			"0"
		"ypos"			"0"
		"zpos"			"1"		
		"wide"			"300"
		"tall"			"300"
		"autoResize"		"0"
		"pinCorner"		"0"
		"visible"		"1"
		"enabled"		"1"
		"useparentbg"		"1"
	
		"inset_eq_x"	"2"
		"inset_eq_y"	"2"

		"fov"			"54"
		"start_framed"		"1"

		"disable_manipulation"	"1"

		"model"
		{
			"angles_x"		"10"
			"angles_y"		"130"
			"angles_z"		"0"
		}
	}

	// some new fc shit

	"MainMenuBG"
	{
		"ControlName"		"EditablePanel"
		"fieldName"			"MainMenuBG"
		"xpos"				"64"
		"ypos"				"125"
		"zpos"				"3"
		"wide"				"260"
		"tall"				"203"
		"visible"			"1"
		"enabled"			"1"
		"bgcolor_override"	"OurpleBG"
		"PaintBackgroundType"	"2"
		"font"				"MenuMainTitle"
	}

	"CreditsButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"CreditsButton"
		"xpos"			"216"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"engine open_contribs"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_love"
			}
		}
	}
	// ---------- Footer Content ----------
	
	"FooterBackground"
	{
		"ControlName"		"ImagePanel"
		"fieldName"			"FooterBackground"
		"xpos"				"0"
		"ypos"				"420"
		"zpos"				"-98"
		"wide"				"f0"
		"tall"				"62"
		"visible"			"1"
		"enabled"			"1"
		"image"				"loadout_bottom_gradient"
		"scaleImage"		"0"
		"tileImage"			"1"
	}				
	"FooterLine"
	{
		"ControlName"		"ImagePanel"
		"fieldName"			"FooterLine"
		"xpos"				"0"
		"ypos"				"420"
		"zpos"				"-50"
		"wide"				"f0"
		"tall"				"10"
		"visible"			"1"
		"enabled"			"1"
		"image"				"loadout_solid_line"
		"scaleImage"		"1"
	}
	
	"FakeBGImage"
	{
		"ControlName"		"ImagePanel"
		"fieldName"			"FakeBGImage"
		"xpos"				"0"
		"ypos"				"0"
		"zpos"				"200"
		"wide"				"f0"
		"tall"				"f0"
		"visible"			"0"
		"enabled"			"1"
		"image"				"../console/background03_widescreen"
		"alpha"				"255"
		"scaleImage"		"1"
	}
	
	// ---------- Header Content ----------
	
	"HeaderBackground"
	{
		"ControlName"		"ImagePanel"
		"fieldName"			"HeaderBackground"
		"xpos"				"0"
		"ypos"				"0"
		"zpos"				"-100"
		"wide"				"f0"
		"tall"				"90"
		"visible"			"0"
		"enabled"			"1"
		"image"				"loadout_bottom_gradient"
		"scaleImage"		"0"
		"tileImage"			"1"
	}				
	"HeaderLine"
	{
		"ControlName"		"ImagePanel"
		"fieldName"			"HeaderLine"
		"xpos"				"0"
		"ypos"				"90"
		"zpos"				"70"
		"wide"				"f0"
		"tall"				"10"
		"visible"			"0"
		"enabled"			"1"
		"image"				"loadout_solid_line"
		"scaleImage"		"1"
	}	
	
	"WelcomeLabel"
	{
		"ControlName"		"CExLabel"
		"fieldName"			"WelcomeLabel"
		"xpos"				"71"
		"ypos"				"127"
		"zpos"				"6"
		"wide"				"223"
		"tall"				"30"
		"autoResize"		"0"
		"pinCorner"			"0"
		"visible"			"1"
		"enabled"			"1"
		"alpha"				"255"
		"labelText"			"#TF_Welcome"
		"textAlignment"		"west"
		//"font"				"HudFontMediumSmall"
		"font"				"TF2MenuTitleMedium"
		"fgcolor"			"TanLight"
		//"bgcolor_override"	"255 0 0 128"
		
		"if_inlevel"
		{
			"visible"		"0"
		}
	}
	
	"AvatarBG"
	{
		"ControlName"		"EditablePanel"
		"fieldName"			"AvatarBG"
		"xpos"				"294"
		"ypos"				"129"
		"zpos"				"5"
		"wide"				"24"
		"tall"				"24"
		"visible"			"1"
		"enabled"			"1"
		"border"			"MainMenuAdvBGBorderAlpha"
		"font"				"MenuMainTitle"
		"bgcolor_override"	"229 207 231 255"
		
		"if_inlevel"
		{
			"visible"		"0"
		}
	}
	
	"AvatarImage"
	{
		"ControlName"		"CAvatarImagePanel"
		"fieldName"			"AvatarImage"
		"xpos"				"296"
		"ypos"				"131"
		"zpos"				"6"
		"wide"				"20"
		"tall"				"20"
		"visible"			"1"
		"enabled"			"1"
		"image"				""
		"scaleImage"		"1"
		"color_outline"		"FCLighterGrey"
		
		"if_inlevel"
		{
			"visible" "0"
		}
	}

	"FindServerButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"FindServerButton"
		"xpos"					"70"
		"ypos"					"155"
		"zpos"					"5"
		"wide"					"248"
		"tall"					"28"
		"visible"				"1"
		"enabled"				"1"
		"bordervisible"			"1"
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"command"       "engine gamemenucommand openserverbrowser"
			"wide"			"248"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"				"HudFontSmallBold"
			"labeltext"			"#GameUI_GameMenu_FindServers"
			"actionsignallevel" "2"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"

			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_multiplayer"
			}
		}
	}
	
	"CreateServerButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"CreateServerButton"
		"xpos"				"70"
		"ypos"				"183"
		"zpos"					"5"
		"wide"					"248"
		"tall"					"28"
		"visible"		"1"
		"enabled"		"1"
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"command"			"engine gameui_fccreateserver"
			"wide"			"248"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		"#GameUI_GameMenu_CreateServer"
			"actionsignallevel" "2"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_create"
			}
		}
	}
	
	"MutePlayersButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"MutePlayersButton"
		"xpos"			"263"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"find_game"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_muted"
			}
		}
	}
	
	"CustomizeButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"CustomizeButton"
		"xpos"					"70"
		"ypos"					"211"
		"zpos"					"5"
		"wide"					"248"
		"tall"					"28"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"248"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		"#MMenu_CharacterSetup"
			"actionsignallevel" "2"
			"command"		"engine open_charinfo"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_items"
			}
		}		
	}
	
	"OptionsButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"OptionsButton"
		"xpos"					"70"
		"ypos"					"239"
		"zpos"					"5"
		"wide"					"220"
		"tall"					"28"
		"visible"		"1"
		"enabled"		"1"
	
		"SubButton"
		{
			"ControlName"			"CExImageButton"
			"fieldName"				"SubButton"
			"wide"					"220"
			"tall"					"26"
			"visible"				"1"
			"enabled"				"1"
			"textinsetx"			"25"
			"use_proportional_insets" "1"
			"font"					"HudFontSmallBold" 
			"labeltext"				"#MMenu_Tooltip_Options"
			"actionsignallevel"		"2"
			"command"				"OpenOptionsDialog"
			"sound_armed"			"ui/buttonrollover.wav"
			"sound_depressed"		"ui/buttonclick.wav"
			"sound_released"		"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_options"
			}
		}	
	}
	
	"AdvOptionsButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"AdvOptionsButton"
		"xpos"					"292"
		"ypos"					"239"
		"zpos"					"6"
		"wide"					"32"
		"tall"					"32"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"opentf2options"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_options"
			}
		}
		
		"PlusLabel"
		{
			"ControlName"	"Label"
			"fieldname"		"PlusLabel"
			"zpos"			"99"
			"visible"		"1"
			"enabled"		"0"
			"labelText"		"+"
			"textAlignment"	"north-west"
			"textinsetx"	"39"
			"mouseinputenabled"	"0"
			
			"disabledfgcolor2_override"	"33 33 33 255"
		}
	}
	
	"AchievementsButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"AchievementsButton"
		"xpos"			"187"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"OpenAchievementsDialog"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_achievements"
			}
		}	
	}
	
	"WorkshopButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"WorkshopButton"
		"xpos"			"158"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"			"engine OpenSteamWorkshopDialog"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_steamworkshop"
			}
		}
	}
	
	"ReplaysButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"ReplaysButton"
		"xpos"			"128"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"engine replay_reloadbrowser"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_tv"
			}
		}
	}

	"QuitButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"QuitButton"
		"xpos"					"70"
		"ypos"					"267"
		"zpos"					"5"
		"wide"					"248"
		"tall"					"28"
		"visible"		"0"
		"enabled"		"0"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"248"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		"#TF_Quit_Title"
			"actionsignallevel" "2"
			"command"		"quit"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_quit"
			}
		}	
	}
	
	"DisconnectButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"DisconnectButton"
		"xpos"					"70"
		"ypos"					"267"
		"zpos"					"5"
		"wide"					"248"
		"tall"					"28"
		"visible"				"1"
		"enabled"				"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"248"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		"DISCONNECT"
			"actionsignallevel" "2"
			"command"			"disconnect"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_quit"
			}
		}	
	}

	"RandomMusicButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"RandomMusicButton"
		"xpos"			"99"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"engine randommusic"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_random"
			}
		}
	}

	"ToggleMusicButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"ToggleMusicButton"
		"xpos"			"70"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"engine toggle mainmenu_music"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_speaker"
			}
		}
	}

	"BlogButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"BlogButton"
		"xpos"			"245"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		"url https://fortressconnected.com"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_forums"
			}
		}
	}
	
	"ToggleAnimatedBGButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"ToggleAnimatedBGButton"
		"xpos"			"275"
		"ypos"			"298"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"		""
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_forums"
			}
		}
	}

	/// IN GAME BUTTONS

	"InGameButtonBG"
	{
		"ControlName"		"EditablePanel"
		"fieldName"			"InGameButtonBG"
		"xpos"				"64"
		"ypos"				"330"
		"zpos"				"3"
		"wide"				"96"
		"tall"				"35"
		"visible"			"1"
		"enabled"			"1"
		"bgcolor_override"	"OurpleBG"
		"PaintBackgroundType"	"2"
		"font"				"MenuMainTitle"
	}
	"CallVoteButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"CallVoteButton"
		"xpos"			"70"
		"ypos"			"335"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"			"find_game"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"icon_checkbox"
			}
		}
	}
	"MutePlayersButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"MutePlayersButton"
		"xpos"			"99"
		"ypos"			"335"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"			"find_game"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_create"
				"scaleImage"	"1"
				"proportionaltoparent"	"1"
			}				
		}
	}
	"ReportPlayerButton"
	{
		"ControlName"	"EditablePanel"
		"fieldname"		"ReportPlayerButton"
		"xpos"			"128"
		"ypos"			"335"
		"zpos"			"100"
		"wide"			"26"
		"tall"			"26"
		"visible"		"1"
		"enabled"		"1"
		
		"SubButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"SubButton"
			"wide"			"26"
			"tall"			"26"
			"visible"		"1"
			"enabled"		"1"
			"textinsetx"	"25"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallBold"
			"labeltext"		""
			"actionsignallevel" "2"
			"command"			"find_game"
			"sound_armed"		"ui/buttonrollover.wav"
			"sound_depressed"	"ui/buttonclick.wav"
			"sound_released"	"ui/buttonclickrelease.wav"

			"border_default"		"AdvRoundedButtonDefault"
			"border_armed"			"AdvRoundedButtonArmed"
			"border_depressed"		"AdvRoundedButtonDepressed"
			"paintbackground"       "0"
			
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"6"
				"ypos"			"6"
				"wide"			"14"
				"tall"			"14"
				"scaleImage"	"1"
				"visible"		"1"
				"enabled"		"0"
				"image"			"glyph_create"
				"scaleImage"	"1"
				"proportionaltoparent"	"1"
			}				
		}
	}
	"RequestCoachButton"
	{
		"visible"	"0"
		"enabled"	"0"
	}
	
	"MOTD_Panel"
	{
		"ControlName"	"EditablePanel"
		"fieldName"		"MOTD_Panel"
		"xpos"			"c5"
		"ypos"			"65"
		"zpos"			"1"
		"wide"			"300"
		"tall"			"350"
		"visible"		"0"
		"PaintBackgroundType"	"2"
		"paintbackground"	"0"
		"border"		"MainMenuHighlightBorder"

		"navDown"		"SettingsButton"		// when a sub element can't nav down it will pass through this
		"navLeft"		"MOTD_ShowButtonPanel"	// when a sub element can't nav left it will pass through this
		"navToRelay"	"MOTD_URLButton"		// when naving to this it auto navs to this child instead
		
		"MOTD_HeaderContainer"
		{
			"ControlName"	"EditablePanel"
			"fieldName"		"MOTD_HeaderContainer"
			"xpos"			"0"
			"ypos"			"0"
			"wide"			"300"
			"tall"			"22"
			"visible"		"1"
			
			"MOTD_HeaderLabel"
			{
				"ControlName"	"CExLabel"
				"fieldName"		"MOTD_HeaderLabel"
				"font"			"HudFontSmallBold"
				"textAlignment"	"center"
				"labelText"		"%motdheader%"
				"xpos"			"0"
				"ypos"			"0"
				"wide"			"300"
				"tall"			"24"
				"autoResize"	"0"
				"pinCorner"		"0"
				"visible"		"1"
				"enabled"		"1"
				"PaintBackgroundType" "2"
				"fgcolor_override"	"235 226 202 255"
				"bgcolor_override"	"141 178 61 255"
			}
		}
		
		"MOTD_CloseButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"MOTD_CloseButton"
			"xpos"			"282"
			"ypos"			"4"
			"zpos"			"10"
			"wide"			"14"
			"tall"			"14"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"tabPosition"	"0"
			"labeltext"		""
			"font"			"HudFontSmallBold"
			"textAlignment"	"center"
			"dulltext"		"0"
			"brighttext"	"0"
			"default"		"0"
			"actionsignallevel"	"2"

			"navDown"			"MOTD_URLButton"
			"navActivate"		"<QuickplayButton"

			"sound_depressed"	"UI/buttonclick.wav"
			"sound_released"	"UI/buttonclickrelease.wav"
			"Command"		"motd_hide"
			
			"paintbackground"	"0"
			
			//"defaultFgColor_override" "235 226 202 255"
			//"armedFgColor_override" "46 43 42 255"
			"defaultFgColor_override" "46 43 42 255"
			"armedFgColor_override" "235 226 202 255"
			"depressedFgColor_override" "46 43 42 255"
			
			"image_drawcolor"	"235 226 202 255"
			"image_armedcolor"	"200 80 60 255"
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"0"
				"ypos"			"0"
				"zpos"			"1"
				"wide"			"14"
				"tall"			"14"
				"visible"		"1"
				"enabled"		"1"
				"image"			"close_button"
				"scaleImage"	"1"
			}				
		}	

		"MOTD_HeaderIcon"
		{
			"ControlName"	"ImagePanel"
			"fieldName"		"MOTD_HeaderIcon"
			"xpos"			"265"
			"ypos"			"25"
			"zpos"			"100"
			"wide"			"25"
			"tall"			"25"
			"visible"		"0"
			"enabled"		"1"
			"image"			"class_icons/filter_all_motd"
			"scaleImage"	"1"
		}
			
		"MOTD_TitleLabel"
		{
			"ControlName"	"CExLabel"
			"fieldName"		"MOTD_TitleLabel"
			"font"			"HudFontSmallBold"
			"labelText"		"%motdtitle%"
			"textAlignment"	"west"
			"xpos"			"10"
			"ypos"			"25"
			"wide"			"250"
			"tall"			"15"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"fgcolor"		"LabelDark"
			"wrap"			"1"
		}
		
		"MOTD_Label"
		{
			"ControlName"	"CExLabel"
			"fieldName"		"MOTD_Label"
			"font"			"HudFontSmall"
			"labelText"		"%motddate%"
			"textAlignment"	"north-west"
			"xpos"			"10"
			"ypos"			"40"
			"wide"			"300"
			"tall"			"15"
			"autoResize"	"0"
			"pinCorner"		"0"
			"visible"		"1"
			"enabled"		"1"
			"fgcolor"		"LabelDark"
		}
		
		"MOTD_TitleImageBg"
		{
			"ControlName"	"ImagePanel"
			"fieldName"		"MOTD_TitleImageBg"
			"xpos"			"cs-0.5"
			"ypos"			"55"
			"zpos"			"99"
			"wide"			"250"
			"tall"			"150"
			"visible"		"1"
			"enabled"		"1"
			"image"			"item_bg"
			"scaleImage"	"1"
			"proportionaltoparent" "1"
		}
		
		"MOTD_TitleImageContainer"
		{
			"ControlName"	"EditablePanel"
			"fieldName"		"MOTD_TitleImageContainer"
			"xpos"			"cs-0.5"
			"ypos"			"55"
			"zpos"			"100"
			"wide"			"250"
			"tall"			"150"
			"visible"		"1"
			"proportionaltoparent" "1"
			
			"MOTD_TitleImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"MOTD_TitleImage"
				"xpos"			"0"
				"ypos"			"0"
				"zpos"			"100"
				"wide"			"250"
				"tall"			"250"
				"visible"		"1"
				"enabled"		"1"
				"image"			"class_icons/filter_all"
				"scaleImage"	"0"
			}
		}
			
		"MOTD_TextScroller"
		{
			"ControlName"	"ScrollableEditablePanel"
			"fieldName"		"MOTD_TextScroller"
			"xpos"			"20"
			"ypos"			"215"
			"wide"			"280"
			"tall"			"115"
			"PaintBackgroundType"	"2"
			"fgcolor"		"LabelDark"
			
			"MOTD_TextPanel"
			{
				"ControlName"	"EditablePanel"
				"fieldName"		"MOTD_TextPanel"
				"xpos"			"0"
				"ypos"			"0"
				"wide"			"250"
				"tall"			"300"
				"visible"		"1"
				"PaintBackgroundType"	"2"
			
				"MOTD_TextLabel"
				{
					"ControlName"	"CExLabel"
					"fieldName"		"MOTD_TextLabel"
					"font"			"HudFontSmall"
					"labelText"		"%motdtext%"
					"textAlignment"	"north-west"
					"xpos"			"0"
					"ypos"			"0"
					"wide"			"250"
					"tall"			"300"
					"autoResize"	"0"
					"pinCorner"		"0"
					"visible"		"1"
					"enabled"		"1"
					"fgcolor"		"LabelDark"
					"wrap"			"1"
				}
			}
		}
		
		"MOTD_URLButton"
		{
			"ControlName"	"CExButton"
			"fieldName"		"MOTD_URLButton"
			"xpos"			"75"
			"ypos"			"rs1.2"
			"wide"			"150"
			"tall"			"15"
			"autoResize"	"0"
			"pinCorner"		"3"
			"visible"		"1"
			"enabled"		"1"
			"tabPosition"	"0"
			"labelText"		"#MMenu_MOTD_URL"
			"textinsetx"	"20"
			"use_proportional_insets" "1"
			"font"			"HudFontSmallestBold"
			"textAlignment"	"center"
			"dulltext"		"0"
			"brighttext"	"0"
			"default"		"1"
			"command"		"motd_viewurl"
			"proportionaltoparent" "1"
			"actionsignallevel"	"2"


			"navUp"			"MOTD_CloseButton"
			"navLeft"		"MOTD_PrevButton"
			"navRight"		"MOTD_NextButton"

			"sound_depressed"	"UI/buttonclick.wav"
			"sound_released"	"UI/buttonclickrelease.wav"
			
			"defaultFgColor_override" "235 226 202 255"
			"defaultBgColor_override" "46 43 42 255"
			"armedFgColor_override" "235 226 202 255"
			"depressedFgColor_override" "235 226 202 255"
		}	
		
		"MOTD_PrevButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"MOTD_PrevButton"
			"xpos"			"12"
			"ypos"			"336"
			"zpos"			"1"
			"wide"			"20"
			"tall"			"20"
			"autoResize"	"0"
			"pinCorner"		"3"
			"visible"		"0"
			"enabled"		"1"
			"tabPosition"	"0"
			"labelText"		""
			"font"			"HudFontSmallBold"
			"textAlignment"	"center"
			"dulltext"		"0"
			"brighttext"	"0"
			"default"		"1"
			"Command"		"motd_prev"
			"actionsignallevel"	"2"

			"navUp"			"MOTD_CloseButton"
			"navRight"		"MOTD_URLButton"

			"sound_depressed"	"UI/buttonclick.wav"
			"sound_released"	"UI/buttonclickrelease.wav"
			"paintbackground" "0"
			
			"image_drawcolor"	"235 226 202 255"
			"image_armedcolor"	"255 255 255 255"
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"0"
				"ypos"			"0"
				"zpos"			"1"
				"wide"			"20"
				"tall"			"20"
				"visible"		"1"
				"enabled"		"1"
				"image"			"blog_back"
				"scaleImage"	"1"
			}
		}		
		
		"MOTD_NextButton"
		{
			"ControlName"	"CExImageButton"
			"fieldName"		"MOTD_NextButton"
			"xpos"			"267"
			"ypos"			"336"
			"zpos"			"1"
			"wide"			"20"
			"tall"			"20"
			"autoResize"	"0"
			"pinCorner"		"3"
			"visible"		"0"
			"enabled"		"1"
			"tabPosition"	"0"
			"labelText"		""
			"font"			"HudFontSmallBold"
			"textAlignment"	"center"
			"dulltext"		"0"
			"brighttext"	"0"
			"default"		"1"
			"Command"		"motd_next"
			"actionsignallevel"	"2"

			"navUp"			"MOTD_CloseButton"
			"navLeft"		"MOTD_URLButton"

			"sound_depressed"	"UI/buttonclick.wav"
			"sound_released"	"UI/buttonclickrelease.wav"
			"paintbackground" "0"
			
			"image_drawcolor"	"235 226 202 255"
			"image_armedcolor"	"255 255 255 255"
			"SubImage"
			{
				"ControlName"	"ImagePanel"
				"fieldName"		"SubImage"
				"xpos"			"0"
				"ypos"			"0"
				"zpos"			"1"
				"wide"			"20"
				"tall"			"20"
				"visible"		"1"
				"enabled"		"1"
				"image"			"blog_forward"
				"scaleImage"	"1"
			}
		}
	}
}
