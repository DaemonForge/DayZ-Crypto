class CfgPatches
{
	class Crypto
	{
		units[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"UniversalApi"
		};
	};
};

class CfgMods
{
	class Crypto
	{
		dir = "Crypto";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Crypto";
		credits = "";
		author = "DaemonForge,tteett";
		authorID = "0"; 
		version = "1.0.0"; 
		extra = 0;
		type = "mod";
		dependencies[] = { "Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = 
				{
					"Crypto/scripts/3_Game"
				};
			};
			
			class worldScriptModule
			{
				value = "";
				files[] = 
				{
					"Crypto/scripts/4_World"
				};
			};

			class missionScriptModule
			{
				value = "";
				files[] = 
				{
					"Crypto/scripts/5_Mission"
				};
			};
		};
	};
};

class cfgVehicles
{
	class Inventory_Base;
	
};