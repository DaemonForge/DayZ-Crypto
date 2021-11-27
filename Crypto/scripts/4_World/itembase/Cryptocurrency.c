class Cryptocurrency_bitcoin extends Cryptocurrency_base {};
class Cryptocurrency_ethereum extends Cryptocurrency_base {};
class Cryptocurrency_litecoin extends Cryptocurrency_base {};
class Cryptocurrency_ripple extends Cryptocurrency_base {};


class Cryptocurrency_base extends ItemBase {
	
	protected int m_CryptoPileCount = 0;
	protected string m_CryptoMarketSymbol = 0;
	
	void Cryptocurrency_base(){
		
		if ( ConfigIsExisting("pileCount") ) {
			m_CryptoPileCount = ConfigGetInt("pileCount");
		} else {
			m_CryptoPileCount = 1;
		}
		if ( ConfigIsExisting("marketSymbol") ) {
			m_CryptoMarketSymbol = ConfigGetString("marketSymbol");
		} else {
			m_CryptoMarketSymbol = "";
		}
	}
	
	string GetCryptoMarketSymbol(){
		return m_CryptoMarketSymbol;
	}

	string GetCryptoPileCount(){
		return m_CryptoMarketSymbol;
	}

};
