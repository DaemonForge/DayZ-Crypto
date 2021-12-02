modded class MissionGameplay 
{
	override void OnMissionStart(){
		super.OnMissionStart();
		GetRPCManager().AddRPC( "Crypto", "RPCCryptoConfig", this, SingeplayerExecutionType.Both );
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RequestCryptoConfig, Math.RandomInt(300,500));
		Print(UUtil.GetUTCUnixInt());
	}
	
	void RequestCryptoConfig(){
		Print("[Crypto][Client] Requesting Config From Server");
		GetRPCManager().SendRPC("Crypto", "RPCCryptoConfig", new Param1< CryptoConfig >( NULL ), true, NULL);
	}
	
	void RPCCryptoConfig( CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target ) {
		Param1< CryptoConfig > data;
		if ( !ctx.Read( data ) ) return;
		Print("[Crypto][Client] Received Config From Server");
		CryptoConfig.m_Config = data.param1;
		CryptoConfig.m_Config.LoadCurrencys();
	}
	
}