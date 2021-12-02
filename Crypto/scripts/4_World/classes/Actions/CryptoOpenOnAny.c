class ActionCryptoOpenOnAny: ActionInteractBase
{
	void ActionCryptoOpenOnAny()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	
	
	override string GetText()
	{
		return "Trade";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target || !player) 
			return false;
		
		EntityAI theTarget;
		
		CryptoTrader trader;
		if ( Class.CastTo(theTarget, target.GetObject()) && GetCryptoConfig().TraderAtPos(theTarget.GetPosition(), theTarget.GetType(), trader) ) {
			return true;
		}
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data ){
		super.OnExecuteServer( action_data );
		
	}
	
	override void OnExecuteClient( ActionData action_data ){
		super.OnExecuteClient( action_data );

		if ( !action_data )
			return;
		
		EntityAI theTarget;
		PlayerBase thePlayer;
		if (Class.CastTo(theTarget, action_data.m_Target.GetObject()) && Class.CastTo(thePlayer, action_data.m_Player)){
			CryptoTrader trader;
			if (GetCryptoConfig().TraderAtPos(theTarget.GetPosition(), theTarget.GetType(), trader)){
				if (!m_CryptoTraderMenu){
					m_CryptoTraderMenu = CryptoTraderMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(CRYPTO_MENU, NULL));
				}
				m_CryptoTraderMenu.SetTrader(trader);
			}
		}
	}
	
}