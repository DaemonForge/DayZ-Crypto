modded class PlayerBase extends ManBase
{
    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
	    {
	        DayzPlayerItemBehaviorCfg     toolsOneHanded = new DayzPlayerItemBehaviorCfg;
	        toolsOneHanded.SetToolsOneHanded();
			GetDayZPlayerType().AddItemInHandsProfileIK("Cryptocurrency_base", "dz/anims/workspaces/player/player_main/props/player_main_1h_keys.asi", toolsOneHanded,	"dz/anims/anm/player/ik/gear/handcuff_keys.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Cryptocurrency_Sack_base", "dz/anims/workspaces/player/player_main/props/player_main_1h_fruit.asi", toolsOneHanded,	"dz/anims/anm/player/ik/gear/apple.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Cryptocurrency_Bag", "dz/anims/workspaces/player/player_main/props/player_main_1h_torch.asi", toolsOneHanded,        "dz/anims/anm/player/ik/gear/GasLight.anm");
	    }
        super.Init();
    }
	
	void SetActions(out TInputActionMap InputActionMap) {
		
		super.SetActions(InputActionMap);
		AddAction(ActionCryptoOpenOnAny, InputActionMap);
		
	}
}