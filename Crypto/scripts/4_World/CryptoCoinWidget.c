class CryptoCoinWidget  extends ScriptedWidgetEventHandler {
	
	protected Widget m_Root;
	
	static string 			m_LayoutPath = "Crypto/gui/layouts/CoinWidget.layout";
	protected autoptr CyptoMarketHandler m_Handler;
	protected ItemPreviewWidget 	m_CoinPreveiw;
	protected TextWidget	m_Price;
	protected TextWidget 	m_Name;
	protected ButtonWidget 	m_Buy;
	protected ButtonWidget 	m_Sell;
	protected string m_MarketSymbol = "";
	protected int m_PileCount = 0;
	protected float m_YSpin = -22;
	protected float m_XSpin = 1;
	
	protected int m_NextBuyTime = 0;

	protected InventoryItem m_PreviewItem;
	
	void CryptoCoinWidget(Widget parent, string coin, CyptoMarketHandler handler){
		m_Root				= Widget.Cast(GetGame().GetWorkspace().CreateWidgets(m_LayoutPath, Widget.Cast(parent), true));
		m_CoinPreveiw 		= ItemPreviewWidget.Cast( m_Root.FindAnyWidget("ItemPreviewWidget") );
		m_Price = TextWidget.Cast(m_Root.FindAnyWidget("Price"));
		m_Name 	= TextWidget.Cast(m_Root.FindAnyWidget("Name"));
		m_Buy	= ButtonWidget.Cast(m_Root.FindAnyWidget("Buy"));
		m_Sell	 = ButtonWidget.Cast(m_Root.FindAnyWidget("Sell"));
		
		Class.CastTo(m_Handler, handler);
		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.UpdatePrice, 1000, true);
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.SpinModel, 45, true);
		UUtil.GetConfigInt(coin,"pileCount", m_PileCount);
		UUtil.GetConfigString(coin,"marketSymbol", m_MarketSymbol);
		SetUpPreview(coin);
		m_Root.SetHandler(this);
	}
	
	void ~CryptoCoinWidget(){
		if (m_PreviewItem){
			GetGame().ObjectDelete(m_PreviewItem);
		}
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.UpdatePrice);
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.SpinModel);
	}
	
	void UpdatePrice(){
		float price = -1;
		if (m_Handler && m_Handler.GetData(m_MarketSymbol, price) && price > 0){
			int CoinPrice = Math.Floor(price * m_PileCount);
			m_Price.SetText("Market Value: $" + MakeNiceString(CoinPrice) + " " + m_Handler.GetCurrency());
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if (player && player.UGetPlayerBalance("Crypto"+m_Handler.GetCurrency()) >=  CoinPrice){
				m_Buy.SetAlpha(0.9);
			} else {
				m_Buy.SetAlpha(0.3);
			}
			if (player && player.UGetItemCount(m_PreviewItem.GetType(), true) >= 1){
				m_Sell.SetAlpha(0.9);
			} else {
				m_Sell.SetAlpha(0.3);
			}
		} else {
			m_Price.SetText("Market Error");
			m_Buy.SetAlpha(0.3);
			m_Sell.SetAlpha(0.3);
		}
		
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{	
		int curTime = GetGame().GetTime();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (w == m_Sell && player && curTime > m_NextBuyTime) {
			if ( player.UGetItemCount(m_PreviewItem.GetType(), true) >= 1){
				m_NextBuyTime = curTime + 1200;
				m_Handler.RequestSellTransaction(m_PreviewItem.GetType(),m_Handler.GetCurrency());
				return true;
			}
			
		}
		if (w == m_Buy && player && curTime > m_NextBuyTime) {
			float price = -1;
			if ( m_Handler.GetData(m_MarketSymbol, price) && price > 0 && player){
				int CoinPrice = Math.Floor(price * m_PileCount);
				int balance = player.UGetPlayerBalance("Crypto"+m_Handler.GetCurrency());
				if ( balance >= CoinPrice){
					m_NextBuyTime = curTime + 1200;
					m_Handler.RequestBuyTransaction(m_PreviewItem.GetType(),m_Handler.GetCurrency());
					return true;
				}
			}
			
		}
		return super.OnClick(w, x, y, button);
	}
	
	void SetUpPreview(string coin){
		if (!m_CoinPreveiw) return;
		
		if (m_PreviewItem){
			GetGame().ObjectDelete(m_PreviewItem);
		}

		m_PreviewItem = InventoryItem.Cast(GetGame().CreateObject(coin,"0 0 0", true, false, true ));
		if (m_PreviewItem){
			m_Name.SetText(m_PreviewItem.GetDisplayName());
			m_CoinPreveiw.SetItem( m_PreviewItem );
			m_CoinPreveiw.SetModelPosition( Vector(0.05,0,0) );
			m_CoinPreveiw.SetModelOrientation( Vector(3,m_YSpin,0) );
			m_CoinPreveiw.SetPos( 0, 0);
			m_CoinPreveiw.SetSize( 1, 1);
			m_CoinPreveiw.SetView( 0 );
		}
	}
	
	void SpinModel(){
		m_YSpin = m_YSpin - 0.6;
		if (m_YSpin < -180){
			m_YSpin =  180;
		}
		if (m_CoinPreveiw && m_PreviewItem){
			m_CoinPreveiw.SetModelOrientation( Vector(3,m_YSpin,0) );
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
}