typedef Param3<string, string, string> CryptoPurchaseDetails;
class CyptoMarketHandler extends Managed {
	
	protected static int FAILED = -1;
	protected static int WAITINGFORFIRST = 0;
	protected static int PENDING = 1;
	protected static int UPDATED = 2;
	
	protected autoptr  map<string,float> m_Cache = new map<string,float>;
	protected int m_LastCacheStatus = WAITINGFORFIRST;
	protected int m_LastCacheId = -1;
	protected int m_LastCacheTime = 0;
	protected autoptr TStringArray m_WatchedCurrencies = new TStringArray;
	protected string m_Currency = "RUB";
	
	string GetCurrency(){
		return m_Currency;
	}
	
	void CyptoMarketHandler(string fiatCur, TStringArray cryptoCur){
		if (!GetGame().IsDedicatedServer()){
			m_Currency = fiatCur;
			m_WatchedCurrencies.Copy(cryptoCur);
			m_LastCacheId = UApi().api().Crypto(m_WatchedCurrencies,m_Currency,this,"CBUpdateCache");
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.CheckAndRefreshCache, 100);
		} else {
			GetRPCManager().AddRPC( "Crypto", "RPCRequestTransaction", this, SingeplayerExecutionType.Both );
		}
	}
	
	void ~CyptoMarketHandler(){
		UApi().RequestCallCancel(m_LastCacheId);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.CheckAndRefreshCache);
	}
	
	void CheckAndRefreshCache(){
		m_LastCacheStatus = PENDING;
		m_LastCacheId = UApi().api().Crypto(m_WatchedCurrencies,m_Currency,this,"CBUpdateCache");
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.CheckAndRefreshCache, 7000);
	}
	
	bool GetData(string currencyCode, out float value){
		int CurTime = GetGame().GetTime();
		if ((m_LastCacheStatus == UPDATED || m_LastCacheStatus == PENDING) && m_LastCacheTime > (CurTime - 10000) && m_Cache){
			bool rValue = m_Cache.Find(currencyCode, value);
			return rValue;
		} else {
			value = -1;
			return false;
		}
	}
	
	void RequestBuyTransaction(string ItemClass, string Currency){
		 GetRPCManager().SendRPC("Crypto","RPCRequestTransaction",new CryptoPurchaseDetails(ItemClass,Currency,"buy"),true);
	}
	
	void RequestSellTransaction(string ItemClass, string Currency){
		 GetRPCManager().SendRPC("Crypto","RPCRequestTransaction",new CryptoPurchaseDetails(ItemClass,Currency,"sell"),true);
		 
	}
	
	void RPCRequestTransaction(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target ) {
		if (!GetGame().IsServer() || !sender) return;
		CryptoPurchaseDetails data;
		if ( !ctx.Read( data ) ) return;
		string id = sender.GetId() + "|" + data.param1 + "|" + data.param2;
		string marketSymbol;
		int pileCount = 0;
		if (data.param3 == "buy" && GetCryptoData(data.param1,marketSymbol,pileCount)){
			UApi().api().CryptoConvert(marketSymbol,data.param2,pileCount,this,"CBHandleTransactionBuy",id);
			return;
		}
		if (data.param3 == "sell" && GetCryptoData(data.param1,marketSymbol,pileCount)){
			UApi().api().CryptoConvert(marketSymbol,data.param2,pileCount,this,"CBHandleTransactionSell",id);
			return;
		}
		SendNotification(sender,"Error with transaction");
	}
	
	void CBUpdateCache(int cid, int status, string id, UApiCryptoResults data){
		if (status == UAPI_SUCCESS){
			m_Cache.Copy(data.Get());
			m_LastCacheStatus = UPDATED;
			m_LastCacheTime = GetGame().GetTime();
		} else {
			m_LastCacheStatus = FAILED;
		}
	}
	
	void CBHandleTransactionBuy(int cid, int status, string id, UApiCryptoConvertResult data){
		TStringArray transctionData = new TStringArray;
		id.Split("|",transctionData);
		transctionData.Debug();
		if (transctionData.Count() == 3){
			string guid = transctionData.Get(0);
			string item = transctionData.Get(1);
			string currency = transctionData.Get(2);
			PlayerBase player = PlayerBase.Cast(UUtil.FindPlayer(guid));
			if (player && status == UAPI_SUCCESS){
				float cost = data.Get();
				string ckey = "Crypto" + currency;
				int balance = player.UGetPlayerBalance(ckey);
				if (balance >= Math.Floor(cost)){
					player.URemoveMoney(ckey, Math.Floor(cost));
					
					string dispayname;
					int AmountLeft = player.UCreateItemInInventory(item);
					if (AmountLeft > 0){
						player.UCreateItemGround(item);
						if (UUtil.GetConfigString(item, "displayName", dispayname)){
							SendNotification(player.GetIdentity(),"You bought " + dispayname + " and it was spawned on the ground");
						}
						
						return;
					}
					if (UUtil.GetConfigString(item, "displayName", dispayname)){
						SendNotification(player.GetIdentity(), "You bought " + dispayname);
					}
					return;
				}
				SendNotification(player.GetIdentity(),"Insufficient Balance");
				return;
			}
			SendNotification(player.GetIdentity(),"Error with transaction");
		}
	}
	
	void CBHandleTransactionSell(int cid, int status, string id, UApiCryptoConvertResult data){
		TStringArray transctionData = new TStringArray;
		id.Split("|",transctionData);
		if (transctionData.Count() == 3){
			string guid = transctionData.Get(0);
			string item = transctionData.Get(1);
			string currency = transctionData.Get(2);
			PlayerBase player = PlayerBase.Cast(UUtil.FindPlayer(guid));
			if (status == UAPI_SUCCESS && player){
				float cost = data.Get();
				string ckey = "Crypto" + currency;
				string dispayname;
				if (player.UGetItemCount(item,true) > 0){
					player.URemoveItemFromInventory(item,1);
					int error = player.UAddMoney(ckey, Math.Floor(cost));
					if (UUtil.GetConfigString(item, "displayName", dispayname) && error == 1){
						SendNotification(player.GetIdentity(),"You sold " + dispayname + " and some money was spawned on the ground");
					} else if (UUtil.GetConfigString(item, "displayName", dispayname)){
						SendNotification(player.GetIdentity(),"You sold " + dispayname);
					}
					return;
				}
			}
			SendNotification(player.GetIdentity(),"Error with transaction");
		}
	}
	
	static bool GetCryptoData(string itemClass, out string marketSymbol, out int pileCount ){
		return (UUtil.GetConfigInt(itemClass,"pileCount",pileCount) && UUtil.GetConfigString(itemClass,"marketSymbol",marketSymbol));
	}
	
	void SendNotification(PlayerIdentity player, string message){
		if (!player) return;
		
		NotificationSystem.CreateNotification(new StringLocaliser("Crypto Trader"), new StringLocaliser(message),"Crypto\\gui\\images\\crypto.edds", ARGB(255,245, 230, 171),10,player);
	}
}