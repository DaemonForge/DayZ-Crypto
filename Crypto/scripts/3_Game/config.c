class CryptoConfig extends Managed {
	
	
	
	
	
	
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