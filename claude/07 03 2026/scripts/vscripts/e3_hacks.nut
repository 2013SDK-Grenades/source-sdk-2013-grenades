// Synergy: Open all areaportals and window areaportals. Taken From Lambda Fortress 
local portal = null;
while ( portal = Entities.FindByClassname( portal, "func_areaportal" ) )
{
	printl( "AREA PORTAL: " + portal );

	portal.KeyValueFromString( "targetname", "disabled_portal" );
	portal.KeyValueFromInt( "StartOpen", 1 );
	//portal.AcceptInput( "Open", "1", null, null );
}

local wportal = null;
while ( wportal = Entities.FindByClassname( wportal, "func_areaportalwindow" ) )
{
	printl( "AREA WINDOW PORTAL: " + wportal );

	wportal.KeyValueFromString( "targetname", "disabled_portal_window" );
	wportal.KeyValueFromInt( "FadeStartDist", 1000 );
	wportal.KeyValueFromInt( "FadeDist", 1500 );
}

local map = GetMapName()

// Synergy: Change the jeep classname on ep2 maps
if ( startswith( map, "ep2_" ) )
{
	printl( "RUNNING ON A EP2 MAP!" );

	if ( map == "ep2_outland_07" )
	{
		SpawnEntityFromTable( "filter_activator_name", { origin = Vector( -10088, -10305, 165 ), targetname = "alyx_filter", Negated = 0, filtername = "alyx" } )
	}

	function update_jeep_filter()
	{
		local filter = null;
		while ( filter = Entities.FindByClassname( filter, "filter_activator_class" ) )
		{
			printl( "Found filter: " + filter );

			printl( "PREVIOUS FILTER: " + NetProps.GetPropString( filter, "m_iFilterClass" ) );

			if ( NetProps.GetPropString( filter, "m_iFilterClass" ) == "prop_vehicle_jeep" )
			{
				NetProps.SetPropString( filter, "m_iFilterClass", "prop_vehicle_jeep_episodic" );
			}

			printl( "NEW FILTER: " + NetProps.GetPropString( filter, "m_iFilterClass" ) );
		}
	}

	update_jeep_filter();
}

// Change some npcs models
if ( startswith( map, "ep2_" ) )
{
	// change barney model
	PrecacheModel( "models/barney_ep2.mdl" );
	local barney = null;
	while ( barney = Entities.FindByClassname( barney, "npc_barney" ) )
	{
		barney.SetModel( "models/barney_ep2.mdl" );
	}

	// change combine soldier model
	PrecacheModel( "models/combine_soldier_ep2.mdl" );
	PrecacheModel( "models/combine_super_soldier_ep2.mdl" );
	local cmb = null;
	while ( cmb = Entities.FindByClassname( cmb, "npc_combine_s" ) )
	{
		if ( cmb.GetModelName() == "models/combine_soldier.mdl" )
		{
			cmb.SetModel( "models/combine_soldier_ep2.mdl" );
		}
		if ( cmb.GetModelName() == "models/combine_super_soldier.mdl" )
		{
			cmb.SetModel( "models/combine_super_soldier_ep2.mdl" );
		}
	}

	// change mossman model
	PrecacheModel( "models/mossman_ep2.mdl" );
	local moss = null;
	while ( moss = Entities.FindByClassname( moss, "npc_mossman" ) )
	{
		moss.SetModel( "models/mossman_ep2.mdl" );
	}
}
