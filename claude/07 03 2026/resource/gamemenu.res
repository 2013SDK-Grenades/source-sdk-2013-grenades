"GameMenu" [$WIN32]
{
	"VRModeButton"
	{
		"label" "#MMenu_VRMode_Activate"
		"command" "engine vr_toggle"
		"subimage" "glyph_vr"
		"OnlyWhenVREnabled" "1"
	}

	// These buttons are only shown while in-game
	// and also are positioned by the .res file

	"CallVoteButton"
	{
		"label"			""
		"command"		"callvote"
		"OnlyInGame"	"1"
		"tooltip" 		"#MMenu_CallVote"
	}
	"MutePlayersButton"
	{
		"label"			""
		"command"		"OpenMutePlayerDialog"
		"OnlyInGame"	"1"
		"tooltip" 		"#MMenu_MutePlayers"
	}
	
	"FindServerButton"
	{
		"label"			"#GameUI_GameMenu_FindServers"
		"command"		"openserverbrowser"
	}

	"CreateServerButton"
	{
		"label"			"#GameUI_GameMenu_CreateServer"
		"command"		"engine gameui_fccreateserver"
	}
	
	"QuitButton"
	{
		"label"			"#TF_Quit_Title"
		"command"		"quit"
		"OnlyAtMenu"	"1"
	}

	"DisconnectButton"
	{
		"label"			"#TF_Disconnect"
		"command"		"disconnect"
		"OnlyInGame"	"1"
	}

	"RandomMusicButton"
	{
		"label"			""
		"command"		"engine randommusic"
		"tooltip" 		"Random Music"
	}

	"ToggleMusicButton"
	{
		"label"			""
		"command"		"engine toggle mainmenu_music"
		"tooltip" 		"Toggle Music"
	}

	"AchievementsButton"
	{
		"label"			""
		"command"		"OpenAchievementsDialog"
		"tooltip" 		"#Achievements"
	}

	"WorkshopButton"
	{
		"label"			""
		"command"		"engine OpenSteamWorkshopDialog"
		"tooltip" 		"#MMenu_SteamWorkshop"
	}

	"ReplaysButton"
	{
		"label"			""
		"command"		"engine replay_reloadbrowser"
		"tooltip" 		"#MMenu_Tooltip_Replay"
	}

	"CreditsButton"
	{
		"label"			""
		"command"		"engine open_contribs"
		"tooltip" 		"Credits" 
	}

	"BlogButton"
	{
		"label"			""
		"command"		"url https://fortressconnected.com"
		"tooltip" 		"FC WebSite"
	}
	
	"ToggleAnimatedBGButton"
	{
		"label"			""
		"command"		"engine toggle fc_animated_menu_background;map_background balls" // bit of a funny workaround but this makes the video instantly play when toggling. 
		"tooltip" 		"Toggle Animated menu background"
		"OnlyAtMenu"	"1"
	}
}
