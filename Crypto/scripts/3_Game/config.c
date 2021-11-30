class CryptoConfig extends Managed {
	
	protected static string ConfigDIR = "$profile:Crypto";
	protected static string ConfigPATH = ConfigDIR + "\\UniversalApi.json";
	static ref CryptoConfig m_Config;
	string ConfigVersion = "1";
	
	autoptr array<autoptr CryptoCurrencyMap> Currencies = new array<autoptr CryptoCurrencyMap>;
	autoptr array<autoptr CryptoTrader> Traders = new array<autoptr CryptoTrader>;
	
	bool ManagedTypesFile = true;
	
	
	void Load(){
		if (GetGame().IsServer()){
			if (FileExist(ConfigPATH)){ // If config exist load File
			    JsonFileLoader<CryptoConfig>.JsonLoadFile(ConfigPATH, this);
				LoadCurrencys();
				
			} else { // File does not exist create file	
				MakeDirectory(ConfigDIR);
				Currencies.Insert(new CryptoCurrencyMap);
				Traders.Insert(new CryptoTrader);
				Save();
			}
		}
	}
	
	void Save(){
		JsonFileLoader<CryptoConfig>.JsonSaveFile(ConfigPATH, this);
	}
	
	void LoadCurrencys(){
		for (int i = 0; i < Currencies.Count(); i++){
			UCurrency.Register("Crypto" + Currencies.Get(i).CurrencyCode, Currencies.Get(i).CurrencyValues);
		}
	}
	
	
	bool TraderAtPos(vector pos, string type, out CryptoTrader trader){
		for (int i = 0; i < Traders.Count(); i++) {
			if ( Traders.Get(i).ObjectType == type && vector.Distance(Traders.Get(i).Pos, pos) < 2 ){
				trader = CryptoTrader.Cast(Traders.Get(i));
				return true;
			}
		}
		return false;
	}
	
}

class CryptoCurrencyMap extends Managed {
	
	string CurrencyCode = "RUB";
	float Modifier = 1.0;
	autoptr TStringIntMap CurrencyValues = new TStringIntMap;
	
	void CryptoCurrencyMap(){
		CurrencyValues.Insert("MoneyRuble100", 100);
		CurrencyValues.Insert("MoneyRuble50", 50);
		CurrencyValues.Insert("MoneyRuble25", 25);
		CurrencyValues.Insert("MoneyRuble10", 10);
		CurrencyValues.Insert("MoneyRuble5", 5);
		CurrencyValues.Insert("MoneyRuble1", 1);
	}
	
}

class CryptoTrader extends Managed {
	string ObjectType = "SurvivorM_Boris";
	autoptr TStringArray Attachemts = {"BomberJacket_Black", "CargoPants_Blue", "DressShoes_Black"};
	vector Pos = Vector(3715.95,402.56,5984.85);
	vector Ori = Vector(-55,0,0);
	autoptr TStringArray AcceptedCurrencies = {"RUB"};
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