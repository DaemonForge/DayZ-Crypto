class CfgPatches
{
	class Cryptocurrency_Items
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class cfgvehicles
{
	class Inventory_Base;
	class Container_Base;
//---Cryptocurrency
class Cryptocurrency_base: Inventory_Base
	{
		scope=0;
		displayName="Cryptocurrency";
		descriptionShort="Bitcoin, first released as open-source software in 2009, is the first decentralized cryptocurrency. Since the release of bitcoin, many other cryptocurrencies have been created.";
		marketSymbol="";
		pileCount=1;
		
	};
	class Cryptocurrency_Coin_base: Cryptocurrency_base
	{
		scope=0;
		model="Crypto\data\Cryptocurrency\Cryptocurrency.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={1,1};
		rotationFlags=16;
		weight=50;
		marketSymbol="";
		pileCount=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_gold_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{1.0, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin.rvmat" }},
						{0.69999999, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin.rvmat" }},
						{0.5,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin_damaged.rvmat"}},
						{0.30000001,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin_damaged.rvmat"}},
						{0.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin_ruined.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpShovel_Light
				{
					soundSet="pickUpShovelLight_SoundSet";
					id=796;
				};
				class pickUpShovel
				{
					soundSet="pickUpShovel_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="shovel_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Cryptocurrency_bitcoin: Cryptocurrency_Coin_base
	{
		scope=2;
		displayName="Bitcoin";
		marketSymbol="BTC";
		pileCount=1;
	};
	class Cryptocurrency_Pile_bitcoin: Cryptocurrency_bitcoin
	{
		scope=2;
		displayName="20 Bitcoin Tokens";
		model="Crypto\data\Cryptocurrency\CryptocurrencyPile.p3d";
		pileCount=20;
		weight=1000;
	};
	class Cryptocurrency_ethereum: Cryptocurrency_Coin_base
	{
		scope=2;
		displayName="Ethereum Token";
		marketSymbol="ETH";
		pileCount=1;
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{ 1.0, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum.rvmat" } },
						{ 0.69999999, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum.rvmat" } },
						{ 0.5, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum_damaged.rvmat" } },
						{ 0.30000001, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum_damaged.rvmat" } },
						{ 0.0, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum_ruined.rvmat" } }
					};
				};
			};
		};
	};
	class Cryptocurrency_Pile_ethereum: Cryptocurrency_ethereum
	{
		scope=2;
		displayName="50 Ethereum";
		model="Crypto\data\Cryptocurrency\CryptocurrencyPile.p3d";
		pileCount=20;
	};
	class Cryptocurrency_litecoin: Cryptocurrency_Coin_base
	{
		scope=2;
		displayName="Litecoin";
		marketSymbol="LTC";
		pileCount=1;
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_gold_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{1.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin.rvmat"}},
						{0.69999999,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin.rvmat"}},
						{0.5,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin_damaged.rvmat"}},
						{0.30000001,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin_damaged.rvmat"}},
						{0.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin_ruined.rvmat"}}
					};
				};
			};
		};
	};
	class Cryptocurrency_doge: Cryptocurrency_Coin_base
	{
		scope=2;
		displayName="DOGECOIN";
		marketSymbol="DOGE";
		pileCount=1;
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_doge.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_gold_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{1.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_doge.rvmat"}},
						{0.69999999,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_doge.rvmat"}},
						{0.5,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_doge_damaged.rvmat"}},
						{0.30000001,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_doge_damaged.rvmat"}},
						{0.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_doge_ruined.rvmat"}}
					};
				};
			};
		};
	};
	class Cryptocurrency_Pile_litecoin: Cryptocurrency_litecoin
	{
		scope=2;
		displayName="20 Litecoin";
		model="Crypto\data\Cryptocurrency\CryptocurrencyPile.p3d";
		pileCount=20;
		weight=1000;
	};
	class Cryptocurrency_ripple: Cryptocurrency_Coin_base
	{
		scope=2;
		displayName="Ripple";
		marketSymbol="XRP";
		pileCount=1;
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_gold_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{1.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple.rvmat"}},
						{0.69999999,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple.rvmat"}},
						{0.5,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple_damaged.rvmat"}},
						{0.30000001,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple_damaged.rvmat"}},
						{0.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple_ruined.rvmat"}}
					};
				};
			};
		};
	};
	class Cryptocurrency_Pile_ripple: Cryptocurrency_ripple
	{
		scope=2;
		displayName="Pile Of 50 Ripple Tokens";
		model="Crypto\data\Cryptocurrency\CryptocurrencyPile.p3d";
		pileCount=50;
		weight=1000;
	};

//---Crypocurrency Sack
	class Cryptocurrency_Sack_base: Cryptocurrency_base
	{
		scope=0;
		displayName="Sack Of Cryptocurrency";
		model="Crypto\data\Cryptocurrency\CryptoSack.p3d";
		itemSize[]={2,2};
		weight=1000;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{1.0, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack.rvmat" }},
						{0.69999999, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack.rvmat" }},
						{0.5,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_damaged.rvmat"}},
						{0.30000001,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_damaged.rvmat"}},
						{0.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_ruined.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
	class Cryptocurrency_Sack_bitcoin: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="5 Bitcoins";
		marketSymbol="BTC";
		pileCount=5;
		weight=300;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_bitcoin_co.paa"
		};
	};
	class Cryptocurrency_Sack_ethereum: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="5 Ethereum Tokens";
		marketSymbol="ETH";
		pileCount=5;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_ethereum_co.paa"
		};
	};
	class Cryptocurrency_Sack_litecoin: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="20 Litecoin Tokens";
		marketSymbol="LTC";
		pileCount=20;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_litecoin_co.paa"
		};
	};
	class Cryptocurrency_Sack_ripple: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="10,000 Ripple Tokens";
		marketSymbol="XRP";
		pileCount=10000;
		weight=3000;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_ripple_co.paa"
		};
	};
	class Cryptocurrency_Sack_cardano: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="10,000 Cardano Tokens";
		marketSymbol="ADA";
		pileCount=10000;
		weight=5000;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_cardano_co.paa"
		};
	};
	class Cryptocurrency_Sack_dogecoin: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="100,000 Dogecoins";
		marketSymbol="DOGE";
		pileCount=100000;
		weight=5000;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_dogecoin_co.paa"
		};
	};
	class Cryptocurrency_Sack_shiba: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="100,000,000 Shiba Inu Coins";
		marketSymbol="SHIB";
		pileCount=100000000;
		weight=10000;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_shiba_co.paa"
		};
	};
	class Cryptocurrency_Sack_binance: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="10 Binance Tokens";
		marketSymbol="BNB";
		pileCount=10;
		weight=300;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_binance_co.paa"
		};
	};
	class Cryptocurrency_Sack_solana: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="10 Solana Tokens";
		marketSymbol="SOL";
		pileCount=10;
		weight=300;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_solana_co.paa"
		};
	};
	class Cryptocurrency_Sack_stellar: Cryptocurrency_Sack_base
	{
		scope=2;
		displayName="10,000 Stellar Lumens";
		marketSymbol="XLM";
		pileCount=10000;
		weight=3000;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_stellar_co.paa"
		};
	};

//---Crypocurrency Bag
	class Cryptocurrency_Bag: Container_Base
	{
		scope=2;
		displayName="Cryptocurrency Wumbo Bag";
		descriptionShort="Cryptocurrency wumbo bag for holding all your precious investments in one central location";
		model="Crypto\data\Cryptocurrency\CryptoBag.p3d";
		itemSize[]={5,8};
		itemsCargoSize[]={8,10};
		weight=5000;
		rotationFlags=2;
		canBeDigged=1;
		allowOwnedCargoManipulation=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						{1.0, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack.rvmat" }},
						{0.69999999, { "Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack.rvmat" }},
						{0.5,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_damaged.rvmat"}},
						{0.30000001,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_damaged.rvmat"}},
						{0.0,{"Crypto\data\Cryptocurrency\data\Cryptocurrency_Sack_ruined.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
};