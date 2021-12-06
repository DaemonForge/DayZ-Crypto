class CryptoConfig extends Managed {
	
	protected static string ConfigDIR = "$profile:Crypto";
	protected static string ConfigPATH = ConfigDIR + "\\Crypto.json";
	static ref CryptoConfig m_Config;
	string ConfigVersion = "1";
	
	ref array<ref CryptoCurrencyMap> Currencies = new array<autoptr CryptoCurrencyMap>;
	ref array<ref CryptoTrader> CryptoTraders = new array<autoptr CryptoTrader>;
	
	bool ManagedTypesFile = true;
	
	
	void Load(){
		if (GetGame().IsServer()){
			if (FileExist(ConfigPATH)){ // If config exist load File
			    UApiJSONHandler<CryptoConfig>.FromFile(ConfigPATH, this);
				LoadCurrencys();
				
			} else { // File does not exist create file	
				MakeDirectory(ConfigDIR);
				Currencies.Insert(new CryptoCurrencyMap);
				CryptoTraders.Insert(new CryptoTrader);
				Save();
			}
		}
	}
	
	void Save(){
		UApiJSONHandler<CryptoConfig>.ToFile(ConfigPATH, this);
	}
	
	void LoadCurrencys(){
		for (int i = 0; i < Currencies.Count(); i++){
			UCurrency.InsertNew("Crypto" + Currencies.Get(i).CurrencyCode, Currencies.Get(i).Values);
		}
	}
	
	
	bool TraderAtPos(vector pos, string type, out CryptoTrader trader){
		for (int i = 0; i < CryptoTraders.Count(); i++) {
			if ( CryptoTraders.Get(i).ObjectType == type && vector.Distance(CryptoTraders.Get(i).Pos, pos) < 2 ){
				trader = CryptoTrader.Cast(CryptoTraders.Get(i));
				return true;
			}
		}
		return false;
	}
	
}

class CryptoCurrencyMap extends Managed {
	
	string CurrencyCode = "USD";
	autoptr array<autoptr UCurrencyValue> Values = new array<autoptr UCurrencyValue>;
	
	void CryptoCurrencyMap(){
		Values = new UCurrency;
		Values.Insert(new UCurrencyValue("MoneyRuble100", 100));
		Values.Insert(new UCurrencyValue("MoneyRuble50", 50));
		Values.Insert(new UCurrencyValue("MoneyRuble25", 25));
		Values.Insert(new UCurrencyValue("MoneyRuble10", 10));
		Values.Insert(new UCurrencyValue("MoneyRuble5", 5));
		Values.Insert(new UCurrencyValue("MoneyRuble1", 1));
	}
	
}

class CryptoTrader extends Managed {
	string ObjectType = "SurvivorM_Boris";
	autoptr TStringArray Attachemts = {"BomberJacket_Black", "CargoPants_Blue", "DressShoes_Black"};
	vector Pos = Vector(3715.95,402.56,5984.85);
	vector Ori = Vector(-55,0,0);
	string AcceptedCurrency = "USD";
	autoptr TStringArray Cryptos = {"Cryptocurrency_bitcoin", "Cryptocurrency_ethereum", "Cryptocurrency_litecoin", "Cryptocurrency_Sack_ripple", "Cryptocurrency_Sack_cardano", "Cryptocurrency_Sack_dogecoin", "Cryptocurrency_Sack_shiba", "Cryptocurrency_Sack_binance", "Cryptocurrency_Sack_solana","Cryptocurrency_Sack_stellar"};
}

//Helper function to return Config
static CryptoConfig GetCryptoConfig()
{
	if ( GetGame().IsServer()){
		if (!CryptoConfig.m_Config)
		{
			CryptoConfig.m_Config = new CryptoConfig;
			CryptoConfig.m_Config.Load();
		}
	}
	return CryptoConfig.m_Config;
};