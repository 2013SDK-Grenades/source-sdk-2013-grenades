local map = GetMapName()

// Synergy: Change the jeep classname on ep2 maps. Taken From Lambda Fortress 
if ( startswith( map, "ep2_" ) )
{
	printl( "RUNNING ON A EP2 MAP!" );

	function update_jeep()
	{
		// Re-spawn the vehicle at the same pos but with new classname
		local playerjeep = Entities.FindByName( null, "jeep" );
		if ( playerjeep == null )
			return;

		local jeeporigin = playerjeep.GetLocalOrigin();
		local jeepangles = playerjeep.GetLocalAngles();
		local hadradar   = false; //playerjeep.GetBodygroup( 1 ) == 1; //NetProps.GetPropBool( playerjeep, "m_bRadarEnabled" );
		local hadhopper  = playerjeep.GetBodygroup( 2 ) == 1;

		playerjeep.Destroy();

		printl( "PREVIOUS JEEP ORIGIN: " + jeeporigin );
		printl( "PREVIOUS JEEP ANGLES: " + jeepangles );
		printl( "HAD RADAR: " + hadradar );
		printl( "HAD HOPPER: " + hadhopper );

		local vehicle_data =
		{
				origin = jeeporigin + Vector( 0, 0, 16 ),
				angles = jeepangles,
				targetname = "jeep",
				model = "models/vehicle.mdl",
				solid = 6,
				vehiclescript = "scripts/vehicles/jalopy.txt"
		}

		local tbl = {}
		if ( map == "ep2_outland_06" )
		{
			tbl =
			{
				"PlayerOn" : "alyxSetDamageFilteralyx_invuln_filter0-1",
				"PlayerOff" : "alyxSetDamageFilter0-1",
				"OnCompanionEnteredVehicle" : "vort_charge_relayTrigger11",
				"PlayerOn" : "alyxEnterVehiclejeep0-1",
				"PlayerOff" : "alyxExitVehicle0-1",
				"OnCompanionEnteredVehicle" : "alyx_incar_timerEnable11",
				"PlayerOn" : "player_incar_branchSetValue00-1",
				"PlayerOff" : "player_incar_branchSetValue10-1",
				"PlayerOff" : "player_off_relayTrigger0-1",
				"PlayerOn" : "redteleport1TeleportPlayers01"
			}
		}

		if ( map == "ep2_outland_06a" || map == "ep2_outland_08" )
		{
			tbl =
			{
				"PlayerOn#1" : "alyxEnterVehiclejeep0-1",
				"PlayerOff#1" : "alyxExitVehicle0-1",
				"PlayerOn#2" : "alyxSetDamageFilteralyx_invuln_filter0-1",
				"PlayerOff#2" : "alyxSetDamageFilter0-1"
			}
		}

		if ( map == "ep2_outland_07" )
		{
			tbl =
			{
				"PlayerOn#1" : "alyxEnterVehiclejeep0-1",
				"PlayerOff#1" : "alyxExitVehicle0-1",
				"PlayerOn#2" : "alyxSetDamageFilteralyx_invuln_filter0-1",
				"PlayerOff#2" : "alyxSetDamageFilter0-1",

				"PlayerOn" : "spawner1RemoveVehicles01",
				"PlayerOn" : "spawner1Disable0.01-1"
			}
		}

		if ( map == "ep2_outland_09" )
		{
			tbl =
			{
				"PlayerOn#1" : "relay_jeep_PlayerOnTrigger0-1",
				"PlayerOff#1" : "relay_jeep_PlayerOffTrigger0-1",
				"OnCompanionEnteredVehicle#1" : "relay_jeep_CompanionOnTrigger0-1",
				"OnCompanionExitedVehicle#1" : "relay_jeep_CompanionOffTrigger0-1",
				"OnHostileEnteredVehicle#1" : "relay_jeep_HostileOnTrigger0-1",
				"OnHostileExitedVehicle#1" : "relay_jeep_HostileOffTrigger0-1",

				"PlayerOn" : "spawner1Enable01"
			}

			hadradar = true;
		}

		if ( map == "ep2_outland_10" || map == "ep2_outland_10a" )
		{
			tbl =
			{
				"PlayerOn#1" : "relay_jeep_PlayerOnTrigger0-1",
				"PlayerOff#1" : "relay_jeep_PlayerOffTrigger0-1",
				"OnCompanionEnteredVehicle#1" : "relay_jeep_CompanionOnTrigger0-1",
				"OnCompanionExitedVehicle#1" : "relay_jeep_CompanionOffTrigger0-1",
				"OnHostileEnteredVehicle#1" : "relay_jeep_HostileOnTrigger0-1",
				"OnHostileExitedVehicle#1" : "relay_jeep_HostileOffTrigger0-1"
			}

			hadradar = true;
		}

		if ( map == "ep2_outland_11b" || map == "ep2_outland_12" )
		{
			tbl =
			{
				"PlayerOn" : "player_sprinthint_in_car_relayTrigger0-1",
				"PlayerOff" : "player_sprinthint_out_car_relayTrigger0-1",
				"PlayerOff" : "player_carhint_out_car_relayTrigger0-1",
				"PlayerOn" : "player_carhint_in_car_relayTrigger0-1"
			}

			hadradar = true;
		}

		foreach ( key, value in tbl )
		{
			vehicle_data[key] <- value;
		}

		SpawnEntityFromTable( "prop_vehicle_jeep_episodic", vehicle_data );
		if ( hadradar || hadhopper )
		{
			local curjeep = Entities.FindByName( null, "jeep" );
			if( curjeep == null )
			{
				printl( "Missing jeep!" );
				return;
			}

			if( hadradar )
			{
				curjeep.AcceptInput( "EnableRadar", "", null, null );

				local mark_alyx_radar = Entities.FindByName( null, "mark_alyx_radar" );
				if ( mark_alyx_radar == null )
					mark_alyx_radar = SpawnEntityFromTable( "info_target", { targetname = "mark_alyx_radar" } );

				if ( mark_alyx_radar )
				{
					mark_alyx_radar.AcceptInput( "SetParent", "jeep", null, null );
					mark_alyx_radar.AcceptInput( "SetParentAttachment", "controlpanel0_ur", null, null );
				}
			}
			if( hadhopper )
				curjeep.AcceptInput( "SetCargoHopperVisibility", "1", null, null );

			curjeep.SetBodygroup( 3, 1 );
		}
	}

	update_jeep();
}