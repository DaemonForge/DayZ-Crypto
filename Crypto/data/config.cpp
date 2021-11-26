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
//---Cryptocurrency
	class Cryptocurrency_base: Inventory_Base
	{
		scope=0;
		displayName="Cryptocurrency";
		descriptionShort="Bitcoin, first released as open-source software in 2009, is the first decentralized cryptocurrency. Since the release of bitcoin, many other cryptocurrencies have been created.";
		model="Crypto\data\Cryptocurrency\Cryptocurrency.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={1,1};
		rotationFlags=16;
		weight=50;
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
			"Crypto\data\Metal Bar\data\Cryptocurrency_gold_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_bitcoin_ruined.rvmat"
							}
						}
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
	class Cryptocurrency_bitcoin: Cryptocurrency_base
	{
		scope=2;
		displayName="Bitcoin Token";
	};
	class Cryptocurrency_ethereum: Cryptocurrency_base
	{
		scope=2;
		displayName="Ethereum Token";
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
						
						{
							1.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ethereum_ruined.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Cryptocurrency_litecoin: Cryptocurrency_base
	{
		scope=2;
		displayName="Litecoin Token";
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Metal Bar\data\Cryptocurrency_silver_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_litecoin_ruined.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Cryptocurrency_ripple: Cryptocurrency_base
	{
		scope=2;
		displayName="Ripple Token";
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Metal Bar\data\Cryptocurrency_silver_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Cryptocurrency\data\Cryptocurrency_ripple_ruined.rvmat"
							}
						}
					};
				};
			};
		};
	};

//---Processor
	class CPU_base: Inventory_Base
	{
		scope=0;
		displayName="Processor";
		descriptionShort="A central processing unit (CPU), also called a central processor, main processor or just processor, is the electronic circuitry that executes instructions comprising a computer program. The CPU performs basic arithmetic, logic, controlling, and input/output (I/O) operations specified by the instructions in the program. | AMD Ryzen Threadripper (https://skfb.ly/6RYV6) by Costr (Viverna) is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).";
		model="Crypto\data\Processor\Processor.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={1,1};
		rotationFlags=16;
		weight=20;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Processor\data\processor.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Processor\data\Processor_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\Processor\data\processor.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Processor\data\processor.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Processor\data\processor_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Processor\data\processor_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Processor\data\processor_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class CPU: CPU_base
	{
		scope=2;
	};

//---GPU
	class GPU_base: Inventory_Base
	{
		scope=0;
		displayName="Graphics Card";
		descriptionShort="A graphics card (also called a video card, display card, graphics adapter, or display adapter) is an expansion card which generates a feed of output images to a display device (such as a computer monitor).";
		model="Crypto\data\GPU\GPU.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={3,4};
		rotationFlags=1;
		weight=120;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\GPU\data\GPU.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\GPU\data\GPU_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\GPU\data\GPU.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\GPU\data\GPU.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\GPU\data\GPU_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\GPU\data\GPU_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\GPU\data\GPU_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class GPU: GPU_base
	{
		scope=2;
	};

//---SSD
	class SSD_base: Inventory_Base
	{
		scope=0;
		displayName="Solid State Drive";
		descriptionShort="A solid-state drive (SSD) is a solid-state storage device that uses integrated circuit assemblies to store data persistently, typically using flash memory, and functioning as secondary storage in the hierarchy of computer storage. | SSD Solid-State Drive (https://skfb.ly/6GzXQ) by isnainul is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).";
		model="Crypto\data\SSD\SSD.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={3,2};
		rotationFlags=1;
		weight=50;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\SSD\data\ssd.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\SSD\data\SSD_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\SSD\data\SSD.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\SSD\data\SSD.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\SSD\data\SSD_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\SSD\data\SSD_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\SSD\data\SSD_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class SSD: SSD_base
	{
		scope=2;
	};
//---HDD
	class HDD_base: Inventory_Base
	{
		scope=0;
		displayName="Hard Disk Drive";
		descriptionShort="A hard disk drive (HDD), hard disk, hard drive, or fixed disk is an electro-mechanical data storage device that stores and retrieves digital data using magnetic storage and one or more rigid rapidly rotating platters coated with magnetic material.";
		model="Crypto\data\HDD\HDD.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={2,3};
		rotationFlags=16;
		weight=80;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\HDD\data\HDD.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\HDD\data\HDD_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\HDD\data\HDD.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\HDD\data\HDD.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\HDD\data\HDD_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\HDD\data\HDD_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\HDD\data\HDD_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class HDD: HDD_base
	{
		scope=2;
	};
//---Floppy Disk
	class FloppyDisk_base: Inventory_Base
	{
		scope=0;
		displayName="Floppy Disk";
		descriptionShort="A floppy disk or floppy diskette (sometimes casually referred to as a floppy or diskette) is a type of disk storage composed of a thin and flexible disk of a magnetic storage medium in a square or nearly square plastic enclosure lined with a fabric that removes dust particles from the spinning disk. | Floppy disk (https://skfb.ly/DXpD) by drumdorf is licensed under Creative Commons Attribution-ShareAlike (http://creativecommons.org/licenses/by-sa/4.0/).";
		model="Crypto\data\Floppy Disk\FloppyDisk.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={1,1};
		rotationFlags=16;
		weight=20;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Floppy Disk\data\floppydisk.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Floppy Disk\data\FloppyDisk_black_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\Floppy Disk\data\floppydisk.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Floppy Disk\data\floppydisk.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Floppy Disk\data\floppydisk_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Floppy Disk\data\floppydisk_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Floppy Disk\data\floppydisk_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class FloppyDisk_black: FloppyDisk_base
	{
		scope=2;
	};
	class FloppyDisk_white: FloppyDisk_base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Floppy Disk\data\FloppyDisk_white_co.paa"
		};
	};
	class FloppyDisk_red: FloppyDisk_base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Floppy Disk\data\FloppyDisk_red_co.paa"
		};
	};
	class FloppyDisk_blue: FloppyDisk_base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Floppy Disk\data\FloppyDisk_blue_co.paa"
		};
	};
	class FloppyDisk_green: FloppyDisk_base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Floppy Disk\data\FloppyDisk_green_co.paa"
		};
	};
	class FloppyDisk_yellow: FloppyDisk_base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Floppy Disk\data\FloppyDisk_yellow_co.paa"
		};
	};

//---RAM
	class RAM_base: Inventory_Base
	{
		scope=0;
		displayName="RAM";
		descriptionShort="Random-access memory (RAM; /ræm/) is a form of computer memory that can be read and changed in any order, typically used to store working data and machine code. | RAM Crucial DDR4 16GB (https://skfb.ly/6Z9GK) by ISUS is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).";
		model="Crypto\data\RAM\RAM.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={3,2};
		rotationFlags=1;
		weight=20;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\RAM\data\RAM.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\RAM\data\RAM_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\RAM\data\RAM.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\RAM\data\RAM.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\RAM\data\RAM_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\RAM\data\RAM_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\RAM\data\RAM_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class RAM: RAM_base
	{
		scope=2;
	};

//---Keyboard
	class Keyboard_base: Inventory_Base
	{
		scope=0;
		displayName="Keyboard";
		descriptionShort="Modern computer keyboards are designed to send a scancode to the operating system (OS) when a key is pressed or released: this code reports only the key's row and column, not the specific character engraved on that key. The OS converts the scancode into a specific binary character code using a scancode to character conversion table, called the keyboard mapping table. | Keyboard - Classic IBM Design (https://skfb.ly/6SUKz) by Matthew is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).";
		model="Crypto\data\Keyboard\Keyboard.p3d";
		visibilityModifier=0.84999999;
		itemSize[]={5,3};
		rotationFlags=16;
		weight=120;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsMaterials[]=
		{
			"Crypto\data\Keyboard\data\Keyboard.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"Crypto\data\Keyboard\data\Keyboard_co.paa"
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
						
						{
							1.0,
							
							{
								"Crypto\data\Keyboard\data\Keyboard.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"Crypto\data\Keyboard\data\Keyboard.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"Crypto\data\Keyboard\data\Keyboard_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"Crypto\data\Keyboard\data\Keyboard_damaged.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"Crypto\data\Keyboard\data\Keyboard_ruined.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Keyboard: Keyboard_base
	{
		scope=2;
	};
};