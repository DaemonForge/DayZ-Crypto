static ref CryptoTraderMenu m_CryptoTraderMenu;
class CryptoTraderMenu extends UIScriptedMenu {
	
	
	static string 			m_LayoutPath = "Crypto/gui/layouts/CryptoTraderMenu.layout";
	
	override Widget Init()
	{
		layoutRoot 				= Widget.Cast(GetGame().GetWorkspace().CreateWidgets(m_LayoutPath));
		return layoutRoot;
	}
	
	void SetTrader(CryptoTrader trader){
		
	}
}