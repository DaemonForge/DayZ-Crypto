static ref CryptoTraderMenu m_CryptoTraderMenu;
class CryptoTraderMenu extends UIScriptedMenu {
	
	protected autoptr CryptoTrader 	m_Trader;
	
	static string 			m_LayoutPath = "Crypto/gui/layouts/CryptoTraderMenu.layout";
	
	protected Widget m_StoreGrid;
	
	protected TextWidget m_PlayerBalance;
	
	protected autoptr array<autoptr CryptoCoinWidget> m_CoinWidgets;
	protected autoptr CyptoMarketHandler m_Handler;
	
	override Widget Init()
	{
		layoutRoot 				= Widget.Cast(GetGame().GetWorkspace().CreateWidgets(m_LayoutPath));
		m_PlayerBalance 		= TextWidget.Cast( layoutRoot.FindAnyWidget("PlayerBalance") );
		m_StoreGrid 			= Widget.Cast( layoutRoot.FindAnyWidget("StoreGrid") );
		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.UpdateBalance, 1000, true);
		
		return layoutRoot;
	}
	
	void ~CryptoTraderMenu(){
		CUnLockControls();
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.UpdateBalance);
		if (m_Handler){
			delete m_Handler;
		}
	}
	
	void UpdateBalance(){
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player){
			int balance =  player.UGetPlayerBalance("Crypto"+m_Handler.GetCurrency());
			m_PlayerBalance.SetText("Your Balance: $" + MakeNiceString(balance) + " " + m_Handler.GetCurrency());
		}
	}
	
	override void Update( float timeslice ) {
		super.Update( timeslice );
		if ( GetGame().GetInput().LocalPress( "UAUIBack", false ) ) {
			CloseSelf();
		}		
	}
	
	string MakeNiceString(int DollarAmount){
		string NiceString = "";
		string OrginalString = DollarAmount.ToString();
		if (OrginalString.Length() <= 3){
			return OrginalString;
		} 
		int StrLen = OrginalString.Length() - 3;
		string StrSelection = OrginalString.Substring(StrLen,3);
		NiceString = StrSelection;
		while (StrLen > 3){
			StrLen = StrLen - 3;
			StrSelection = OrginalString.Substring(StrLen,3);
			NiceString = StrSelection + "," + NiceString;
		}
		StrSelection = OrginalString.Substring(0,StrLen);
		NiceString = StrSelection + "," + NiceString;
		return NiceString;
	}
	
	void SetTrader(CryptoTrader trader){
		Class.CastTo(m_Trader, trader);
		CLockControls();
		
		TStringArray MarketSymbols = new TStringArray;
		int i = 0;
		for (i = 0; i < m_Trader.Cryptos.Count(); i++){
			string marketSymbol = "";
			UUtil.GetConfigString(m_Trader.Cryptos.Get(i),"marketSymbol", marketSymbol);
			if (marketSymbol != "" && MarketSymbols.Find(marketSymbol) == -1){
				MarketSymbols.Insert(marketSymbol);
			}
		}
		m_Handler = new CyptoMarketHandler(m_Trader.AcceptedCurrency,MarketSymbols);
		m_CoinWidgets = new array<autoptr CryptoCoinWidget>;
		for (i = 0; i < m_Trader.Cryptos.Count(); i++){
			m_CoinWidgets.Insert(new CryptoCoinWidget(m_StoreGrid,m_Trader.Cryptos.Get(i),m_Handler));
		}
	}
	
	void CloseSelf(){
		GetGame().GetUIManager().CloseMenu(CRYPTO_MENU);
	}
	protected void CLockControls() {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowUICursor(true);
    }

    protected void CUnLockControls() {
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor(false);
    }
}