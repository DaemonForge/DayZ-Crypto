class Cryptocurrency_bitcoin extends Cryptocurrency_Coin_base {};
class Cryptocurrency_Pile_bitcoin extends Cryptocurrency_bitcoin {};
class Cryptocurrency_ethereum extends Cryptocurrency_Coin_base {};
class Cryptocurrency_Pile_ethereum extends Cryptocurrency_ethereum {};
class Cryptocurrency_litecoin extends Cryptocurrency_Coin_base {};
class Cryptocurrency_Pile_litecoin extends Cryptocurrency_litecoin {};
class Cryptocurrency_ripple extends Cryptocurrency_Coin_base {};
class Cryptocurrency_Pile_ripple extends Cryptocurrency_ripple {};
class Cryptocurrency_Sack_bitcoin extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_ethereum extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_litecoin extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_ripple extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_cardano extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_dogecoin extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_shiba extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_binance extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_solana extends Cryptocurrency_Sack_base {};
class Cryptocurrency_Sack_stellar extends Cryptocurrency_Sack_base {};


class Cryptocurrency_Coin_base extends Cryptocurrency_base {};
class Cryptocurrency_Sack_base extends Cryptocurrency_base {};


class Cryptocurrency_base extends ItemBase {
	
	protected int m_CryptoPileCount = 0;
	protected string m_CryptoMarketSymbol = "";
	
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

	int GetCryptoPileCount(){
		return m_CryptoPileCount;
	}

};
