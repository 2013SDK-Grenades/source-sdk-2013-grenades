//Script written by Lazyneer

hasRecievedCash <- {}
deathStreak <- {}
for(local i = 1; i <= Constants.Server.MAX_PLAYERS; i++)
{
    hasRecievedCash[i] <- false
    deathStreak[i] <- 0
}

function OnGameEvent_teamplay_round_start(params)
{
    ForceEnableUpgrades(2)
    ResetCanteens()
}

function OnGameEvent_teamplay_round_win(params)
{
    ResetPlayers()
}

function OnGameEvent_teamplay_restart_round(params)
{
    ResetPlayers()
}

function OnGameEvent_player_spawn(params)
{
    local client = GetPlayerFromUserID(params.userid)
    if(!hasRecievedCash[client.entindex()])
    {
        local playerClass = client.GetPlayerClass()
        local health = client.GetMaxHealth()
        for(local i = 1; i <= 9; i++)
        {
            client.SetPlayerClass(i)
            client.Regenerate(true)
            client.GrantOrRemoveAllUpgrades(true, false)
        }

        client.SetPlayerClass(playerClass)
        client.Regenerate(true)
        client.SetHealth(health)
        client.SetCurrency(500)
        hasRecievedCash[client.entindex()] = true
    }

    if(deathStreak[client.entindex()] >= 3)
    {
        AddCurrency(client, 100)
        deathStreak[client.entindex()] = 0
    }
}

function OnGameEvent_player_disconnect(params)
{
    local client = GetPlayerFromUserID(params.userid)
    if(client.IsValid())
    {
        hasRecievedCash[client.entindex()] = false
        deathStreak[client.entindex()] = 0
    }
}

function ResetPlayers()
{
    for(local i = 1; i <= Constants.Server.MAX_PLAYERS; i++)
    {
        hasRecievedCash[i] = false
        deathStreak[i] = 0
    }
}

function ResetCanteens()
{
    local ent = null
    while(ent = Entities.FindByClassname(ent, "tf_powerup_bottle"))
    {
        NetProps.SetPropInt(ent, "m_usNumCharges", 0)
        NetProps.SetPropBool(ent, "m_bActive", false)
        ent.RemoveAttribute("critboost")
        ent.RemoveAttribute("ubercharge")
        ent.RemoveAttribute("building instant upgrade")
        ent.RemoveAttribute("refill_ammo")
        ent.RemoveAttribute("recall")
    }
}

function AddCurrency(client, cash)
{
    client.SetCurrency(client.GetCurrency() + cash)
}

function OnGameEvent_player_death(params)
{
    //Dead Ringer
    if(params.death_flags & 32)
        return

    local attacker = GetPlayerFromUserID(params.attacker)
    local assister = GetPlayerFromUserID(params.assister)
    local victim = GetPlayerFromUserID(params.userid)
    
    if(attacker != null)
    {
        if(attacker != victim && attacker.GetTeam() != victim.GetTeam())
        {
            AddCurrency(attacker, 100)
            deathStreak[attacker.entindex()] = 0
            deathStreak[victim.entindex()] += 1
        }
    }

    if(assister != null)
    {
        if(assister != victim && assister.GetTeam() != victim.GetTeam())
        {
            if(assister.GetPlayerClass() == Constants.ETFClass.TF_CLASS_MEDIC)
            {
                AddCurrency(assister, 100)
                deathStreak[assister.entindex()] = 0
            }
            else
                AddCurrency(assister, 50)
        }
    }
}

__CollectGameEventCallbacks(this)