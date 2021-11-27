modded class PlayerBase extends ManBase
{
    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
    {
        DayzPlayerItemBehaviorCfg     toolsOneHanded = new DayzPlayerItemBehaviorCfg;
        toolsOneHanded.SetToolsOneHanded();
		GetDayZPlayerType().AddItemInHandsProfileIK("Cryptocurrency_base", "dz/anims/workspaces/player/player_main/props/player_main_1h_keys.asi", toolsOneHanded,	"dz/anims/anm/player/ik/gear/handcuff_keys.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("Cryptocurrency_base", "dz/anims/workspaces/player/player_main/props/player_main_1h_fruit.asi", toolsOneHanded,	"dz/anims/anm/player/ik/gear/apple.anm");
    }
        super.Init();
    }
}