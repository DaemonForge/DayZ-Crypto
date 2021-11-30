modded class MissionGameplay 
{
	override void OnMissionStart(){
		super.OnMissionStart();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RequestCryptoConfig, Math.RandomInt(300,500));
	}
	
	void RequestCryptoConfig(){
		GetRPCManager().AddRPC( "Crypto", "RPCCryptoConfig", this, SingeplayerExecutionType.Both );
		Print("[Crypto][Client] Requesting Config From Server");
		GetRPCManager().SendRPC("Crypto", "RPCCryptoConfig", new Param1< CryptoConfig >( NULL ), true, NULL);
	}
	
	void RPCCryptoConfig( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		Param1< CryptoConfig > data;
		if ( !ctx.Read( data ) ) return;
		Print("[Crypto][Client] Received Config From Server");
		CryptoConfig.m_Config = data.param1;
		CryptoConfig.m_Config.LoadCurrencys();
	}
	
}