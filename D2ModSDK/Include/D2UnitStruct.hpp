/*=================================================================*/
/** @file D2UnitStruct.h
 *  @brief Diablo II Unit Structures definitions.
 *
 *  (c) January 2002 - Joel Falcou for The Phrozen Keep.
 */
/*=================================================================*/

#ifndef __D2UNITSTRUCT_H__INCLUDED__
#define __D2UNITSTRUCT_H__INCLUDED__
#pragma pack(1)

/*=================================================================*/
/*    Preset Unit Structures (used by DrlgRoom2).                  */
/*=================================================================*/

struct PresetUnit
{                                   //Offset from Code
};


/*=================================================================*/
/*   Unit Data Structure.                                          */
/*=================================================================*/

struct Unit
{									//Offset from Code.
	DWORD		nUnitType;			//+00 Unit Type
	DWORD		nUnitId;			//+04 Unit ID
    DWORD*		unknown_1;			//+08 ptGame + 1C
    DWORD		nUnitUnid;			//+0C Unique ID
	DWORD		nAnimMode;			//+10 Current animation mode

    union
    {
		PlayerData*     pPlayerData;
		MonsterData*    pMonsterData;
		ObjectData*     pObjectData;
		ItemData*       pItemData;
	};				                //+14 ptUnitData

    DWORD		nAct;		        //+18 Act
	DWORD		ptAct;				//+1C ptAct
	DWORD		LoSeed;				//+20
	DWORD		HiSeed;				//+24
	DWORD		StartLoSeed;		//+28
	Path*		hPath;				//+2C
	DWORD		unknown_7;			//+30
	DWORD		unknown_8;			//+34
	Path*		ptPos;				//+38 ptPos
	DWORD		unknown_10;			//+3C
	DWORD		unknown_11;			//+40
	DWORD		unknown_12;			//+44
	DWORD		unknown_13;			//+48
	DWORD		unknown_14;			//+4C
	DWORD		nAnimData;			//+50 AnimData.D2 record address for current mode
	DWORD		unknown_16;			//+54
	DWORD		unknown_17;			//+58
	StatsList*	ptStatsList;		//+5C ptStatsList
	Inventory*	ptInventory;		//+60 ptInventory
    DWORD		unknown_19;			//+64
	DWORD		unknown_20;			//+68
	DWORD		unknown_21;			//+6C
	DWORD		unknown_22;			//+70
	DWORD		unknown_23;			//+74 0 at start
	DWORD		unknown_24;			//+78
	DWORD		unknown_25;			//+7C
	D2Game*		ptGame;				//+80 ptGame
	DWORD		unknown_26;			//+84
	DWORD		unknown_27;			//+88
	DWORD		unknown_28;			//+8C
	DWORD		unknown_29;			//+90
	DWORD		unknown_30;			//+94
	DWORD		unknown_31;			//+98
	DWORD		unknown_32;			//+9C
	DWORD		unknown_33;			//+A0
	DWORD		unknown_34;			//+A4
	D2Info*		ptInfo;				//+A8 ptInfo
	DWORD		unknown_35;			//+AC
	DWORD		unknown_36;			//+B0
	DWORD		unknown_37;			//+B4
	DWORD		nDropItemCode;		//+B8
	DWORD		unknown_39;			//+BC
	DWORD		unknown_40;			//+C0
	DWORD		nFlags;				//+C4 Flags
	DWORD		nLODFlag;			//+C8 LODFlag
	DWORD		unknown_41;			//+CC
	DWORD		nClientNum;			//+D0 Client# (0B at start)
	DWORD		unknownD4[11];		//+D4 - FC unknown pad to next Unit

};

struct AIStruct
{
/*+00 = 0 on spawn, gæti breyst seinna
+04 = pfnFunction, ptr, see ai table.txt at +08 (if 0 and +00 = 0, then 6FCD3AD0, then 6FCCA0D0)
+0c = -1 on spawn
+10 = 1 on spawn
+14 = 0 on spawn
+18 = 0 on spawn
+1c = 0 on spawn
+28 = if minion, then ptGame
+2c = if minion, then owner id
+30 = if minion, then owner type */
};

/*struct D2ItemsTXT
{
   char   FlippyFile[0x20];      //+00
   char   InvFile[0x20];         //+20
   char   UniqueInvFile[0x20];   //+40
   char   SetInvFile[0x20];      //+60
   DWORD   ItemCode;            //+80
   DWORD   NormCode;            //+84
   DWORD   UberCode;            //+88
   DWORD   HellCode;            //+8C
   DWORD   AlternateGfx;         //+90
   DWORD   pSpell;               //+94
   WORD   State;               //+98
   WORD   cState1;            //+9A
   WORD   cState2;            //+9C
   WORD   Stat1;               //+9E
   WORD   Stat2;               //+A0
   WORD   Stat3;               //+A2
   int      Calc1;               //+A4
   int      Calc2;               //+A8
   int      Calc3;               //+AC
   DWORD   Len;               //+B0
   WORD   SpellDesc;            //+B4
   WORD   SpellDescStr;         //+B6
   DWORD   SpellDescCalc;         //+B8
   DWORD   BetterGem;            //+BC
   DWORD   WClass;               //+C0
   DWORD   TwoHandedWClass;      //+C4
   DWORD   TMogType;            //+C8
   DWORD   MinAC;               //+CC
   DWORD   MaxAC;               //+D0
   DWORD   GambleCost;            //+D4
   DWORD   Speed;               //+D8
   DWORD   BitField;            //+DC
   DWORD   Cost;               //+E0
   DWORD   MinStack;            //+E4
   DWORD   MaxStack;            //+E8
   DWORD   SpawnStack;            //+EC
   DWORD   GemOffset;            //+F0
   WORD   NameStr;            //+F4
   WORD   Version;            //+F6
   WORD   AutoPrefix;            //+F8
   WORD   MissileType;         //+FA
   BYTE   Rarity;               //+FC
   BYTE   Level;               //+FD
   BYTE   MinDam;               //+FE
   BYTE   MaxDam;               //+FF
   BYTE   MinMisDam;            //+100
   BYTE   MaxMisDam;            //+101
   BYTE   TwoHandMinDam;         //+102
   BYTE   TwoHandMaxDam;         //+103
   BYTE   RangeAdder;            //+104
   BYTE   NotUsed1;            //+105
   WORD   StrBonus;            //+106
   WORD   DexBonus;            //+108
   WORD   RegStr;               //+10A
   WORD   RegDex;               //+10C
   BYTE   Absorbs;            //+10E
   BYTE   InvWidth;            //+10F
   BYTE   InvHeight;            //+110
   BYTE   Block;               //+111
   BYTE   Durability;            //+112
   BYTE   NoDurability;         //+113
   BYTE   Missile;            //+114
   BYTE   Component;            //+115
   BYTE   RArm;               //+116
   BYTE   LArm;               //+117
   BYTE   Torso;               //+118
   BYTE   Legs;               //+119
   BYTE   RSpad;               //+11A
   BYTE   LSpad;               //+11B
   BYTE   TwoHanded;            //+11C
   BYTE   Usable;               //+11D
   WORD   Type;               //+11E
   WORD   Type2;               //+120
   BYTE   SubType;            //+122
   BYTE   NotUsed2;            //+123
   WORD   DropSound;            //+124
   WORD   UseSound;            //+126
   BYTE   DropSfxFrame;         //+128
   BYTE   Unique;               //+129
   BYTE   Quest;               //+12A
   BYTE   QuestDiffCheck;         //+12B
   BYTE   Transparent;         //+12C
   BYTE   TransTbl;            //+12D
   BYTE   NotUsed3;            //+12E
   BYTE   LightRadius;         //+12F
   BYTE   Belt;               //+130
   BYTE   AutoBelt;            //+131
   BYTE   Stackable;            //+132
   BYTE   Spawnable;            //+133
   BYTE   SpellIcon;            //+134
   BYTE   DurWarning;            //+135
   BYTE   QntWaning;            //+136
   BYTE   HasInv;               //+137
   BYTE   GemSockets;            //+138
   BYTE   TransmoGrify;         //+139
   BYTE   TMogMin;            //+13A
   BYTE   TMogMax;            //+13B
   BYTE   HitClass;            //+13C
   BYTE   OneOrTwoHanded;         //+13D
   BYTE   GemApplyType;         //+13E
   BYTE   LevelReq;            //+13F
   BYTE   MagicLvl;            //+140
   BYTE   Transform;            //+141
   BYTE   InvTrans;            //+142
   BYTE   CompactSave;         //+143
   BYTE   SkipName;            //+144
   BYTE   NotUsed4;            //+145
   BYTE   VendorMin[17];         //+146
   BYTE   VendorMax[17];         //+157
   BYTE   VendorMagicMin[17];      //+168
   BYTE   VendorMagicMax[17];      //+179
   BYTE   VendorMagicLvl[17];      //+18A
   BYTE   NotUsed5;            //+19B
   DWORD   NightmareUpgrade;      //+19C
   DWORD   HellUpgrade;         //+1A0
   BYTE   PermStoreItem;         //+1A4
   BYTE   Multibuy;            //+1A5
};
*/
struct PlayerData
{
	char	CharName[0x10];	//+00	Player Name
	LPVOID	ptQuest[3];		//+10	Quest Pointers for each difficulty
	BYTE	unknown[0x80];
	void*	ptClient;		//+9C	ptClient
};

struct MonsterData
{
	BYTE	unknown[0x26];		// +00
	WORD	SuperUniqueID;		// +26 Superunique ID of monster
/*
    AIStruct*     AIPtr;
    void*         unkonwPtr1;
    void*         uniqueInfo;
    void*         spawnInfo;
    void*         unknownPtr2;
    DWORD         unkown[8];
    void*         lvlPtr;
    MonStatTxt*   monstatPtr;
*/
};

struct ObjectData
{                       // Offset from Code
};

struct ItemData
{							// Offset from Code

	DWORD quality;			// +00.
	DWORD lowSeed;			// +04.
	DWORD highSeed;			// +08.
	DWORD unknown_1;		// +0c.
	DWORD startLowSeed;		// +10.
	DWORD cmdFlags;			// +14.
	DWORD flags;			// +18.
	DWORD unknown_2[3];		// +1C -> 27
	DWORD PlayerClass;		// +28
	DWORD unknown2C;		// +2C
	DWORD unknown30[5];		// +30 -> 43
	// SVR - as seen by D2Game Item pspell function
	BYTE Location;			// +44			equipped location (0 = grid)
	BYTE StorePage;			// +45
	WORD unk46;				// +46 47
	WORD unk48;				// +48 49
	BYTE IName[18];			// +4A -> 5B	inscribed/ear name
	Inventory*	ptInventory; //+5C			ptInventory
	Unit *prev;				// +60			prev item unit
	Unit *next;				// +64			next item unit
	DWORD unk68;			// +68
	Unit *unk6C;			// +6C			same as prev ?
	DWORD *unk70[4];		// +70
	DWORD ptdata[18];		// +80 -> C7	area pointed to by ptStatslist ?
	Stats *ptStats;			// +C8			pointer to stat array
	WORD nStats;			// +CC
	WORD unkCE;				// +CE
	DWORD unkD0;			// +D0
	DWORD unkD4;			// +D4
	DWORD *ptUnkD8;			// +D8
	DWORD unkDC[9];			// +DC -> FF
/*
    DWORD originID;			// +24.
    DWORD iLvl;				// +28.
    WORD  version;			// +2C.
    WORD  prefix;			// +2E.
    WORD  suffix;			// +30.
    WORD  autoPrefix;		// +32.
    WORD  prefix1;			// +34.
    WORD  prefix2;			// +36.
    WORD  prefix3;			// +38.
    WORD  suffix1;			// +3A.
    WORD  suffix2;			// +3C.
    WORD  suffix3;			// +3E.
    BYTE  bodyLoc;			// +40.
    BYTE  inPage;			// +41.
    BYTE  unknown3[3];		// +42
    BYTE  picture[8];		// +45
    DWORD ilvl;				// +4C
*/
};


struct MissilesData
{
/*
+04 flags
+08 0 on start
+0c -1 on start
+20 nDirection
+28 range?
+2c range?
+30 level
+34 number of pierces (byte)
+35 (byte)
+36 (byte)
+37 (byte)
+38 range-activate */
};

struct D2Game
{
	BYTE	unknown_0[0x18];
	DWORD	_ptLock	;			// +18 Unknown
	DWORD	MemoryPool;			// +1C Memory Pool (??)
	BYTE	unknown_1[0x4A];	// +20 
	BYTE	GameType;			// +6A
	WORD	unknown_1b;			// +6B
	BYTE	Difficulty;			// +6D Difficulty 0,1,2
	WORD	unknown_2;			// +6E Cube puts 4 here
	DWORD	LODFlage;			// +70 0 = Normal, 1 = LOD
//	Unit*	ptCubeUnit;			// +74 Cube puts the ptUnit of itself here
	DWORD	unknown_3;			// +74 0 at start
	DWORD	unknown_4;			// +78
	DWORD	unknown_5;			// +7C
	DWORD	unknown_6;			// +80
	DWORD	unknown_7;			// +84
	void*	ptClient;			// +88 ptClient
};

struct Client
{
	DWORD	ClientNbr;			// +000 Client #
	DWORD	ConnectionState;	// +004 Connection State (4 = connected)
	DWORD	unknown_1;			// +008
	BYTE	unknown_2;			// +00C
	char	CharName[0x10];		// +00D PlayerName
	BYTE	unknown_3[0x157];	// +01D
	Unit*	ptPlayer;			// +174 ptPlayer this Client Belongs To
};

/*=================================================================*/
/*   Item Location Structure.                                     */
/*=================================================================*/

struct LocInfo
{                       //Offset from Code
/*
    DWORD noneLoc;      //+00
    DWORD headLoc;      //+04
    DWORD neckLoc;      //+08
    DWORD torsoLoc;     //+0c
    DWORD rightArmLoc;  //+10
    DWORD leftArmLoc;   //+14
    DWORD rightRingLoc; //+18
    DWORD leftRingLoc;  //+1c
    DWORD beltLoc;      //+20
    DWORD feetLoc;      //+24
    DWORD glovesLoc;    //+28
*/
};

/*=================================================================*/
/*   Inventory Node Structure.                                     */
/*=================================================================*/

struct Node
{                   //Offset from Code.
/*
    DWORD null;     //+00
    ItemData* pItem;    //+04
    DWORD unID;     //+08
    DWORD page;     //+0c
    Node* nextNode; //+10
*/
};

/*=================================================================*/
/*   Inventory Structure.                                          */
/*=================================================================*/

struct Inventory
{                               //Offset from Code.
    DWORD		nIdentifier;	//+00 1020304
    DWORD		unknown_1;		//+04 ptGame + 1C
	Unit*		ptUnit;			//+08 ptUnit
	DWORD		unknown_2;		//+0C
	DWORD		unknown_3;		//+10
	DWORD		unknown_4;		//+14
	DWORD		unknown_5;		//+18
	DWORD		unknown_6;		//+1C
	DWORD		unknown_7;		//+20
	DWORD		nUnitUnid;		//+24 Unit unid
};

/*=================================================================*/
/*  Skill Structure.                                               */
/*=================================================================*/

struct Skills
{
							//Offset from Code.
    D2SkillsTXT*  skillTxt;	//+00
    Skills* pNextSkill;     //+04
    DWORD   mode;           //+08
    DWORD   unknown1[3];    //+0C
    DWORD   targetInfo;     //+18
    DWORD   targetType;     //+1c
    DWORD   targetUNID;     //+20
    DWORD   unknown2;       //+24
    DWORD   slvl;           //+28
    DWORD   slvlBonus;      //+2c
    DWORD   unknown3;       //+30
    DWORD   state;          //+34
};

/*=================================================================*/
/*  Skills Info Structure.                                         */
/*=================================================================*/

struct D2Info
{								//Offset from Code.
	DWORD		unknown_1;		// +00 ptGame + 1C
/*
    DWORD   gameRelated;    //+00
    Skills* ptSkill;        //+04
    Skills* ptLeftSkill;    //+08
    Skills* ptRightSkill;   //+0c
    Skills* ptCurrentSkill; //+10
*/
};

struct StatsList
{
	DWORD		unknow_1;		//+00
	DWORD		unknow_2;		//+04
	DWORD		unknow_3;		//+08
	DWORD		unknow_4;		//+0C
	DWORD		Charges;		//+10
	DWORD		unknow_6;		//+14
	DWORD		unknow_7;		//+18
	DWORD		unknow_8;		//+20
	Stats*		ptStats[80];	//+24 ptStats
	DWORD		nStatCount;		//+28 nStatCount
	DWORD		nStatCount1;	//+2A Unknown
};

struct Stats
{
	WORD		nStatParam; //Index;		//+00	// SVR
	WORD		nStatID;		//+02
	WORD		nStatValue;		//+04
};

struct Combat
{
/*
	DWORD mHeader;		// +00 : Always 0x32
	DWORD mDisplayFlag;	// +04 : Affect critical hit etc ...
	DWORD mPhysicalDmg; // +08 : Values are << 8
	DWORD mUnknown1;    // +0C
	DWORD mFireDmg;		// +10 : Values are << 8
	DWORD mUnknown2;    // +14


18h - Burning length, puts some fire overlay on enemies
1Ch - Lightning damage, shifted left 8 bits
20h - Magic damage, shifted left 8 bits
24h - Cold damage, shifted left 8 bits
28h - Poison damage, wierd as hell, not sure of the calculation
2Ch - Poison length, in frames maybe??
30h - Cold duration, in frames maybe??
34h - Freeze duration, in frames maybe??
38h - Life stolen, not sure if absolute or a percent
3Ch - Mana stolen, not sure if absolute or a percent
40h - Unknown
44h - Stun duration, in frames maybe??
48h - Unknown
4Ch - Total damage (physical + all elemental), doesn't seem to do anything
50h - Unknown
54h - Unknown
58h - Unknown
5Ch - Unknown
60h - Unknown
64h - Unknown
68h - Overlay
6Ch - Unknown, always 7h??
*/

};

/*=================================================================*/
/*   Data Structure to Update Client                               */
/*=================================================================*/
struct DataPacket
{
	BYTE mType;			// +00 Packet Type
	BYTE mFunc;			// +02 Function to Call
	BYTE mSize;			// +04 Size of the Packet
	DWORD mReserved;	// +06 Used with items
	BYTE mUnitType;		// +0A Always '0'
	DWORD mPlayerID;	// +0C The Player ID (ptUnit + 08h)
	DWORD mItemID;		// +10 The Item ID
	DWORD mMod1_ID;		// +14 The Stat/Mod ID
	DWORD mParam1;		// +18 3 Paramters
	DWORD mParam2;		// +1C
	DWORD mParam3;		// +20
};

/*=================================================================*/
/*   Data Structure to Add Mods to Items                           */
/*=================================================================*/
struct ItemMod
{
	DWORD mID;			// +00 Mod ID, get it from properties.txt
	DWORD mParam;		// +04 First Property
	DWORD mMinimum;		// +08 Second Property, Min Value
	DWORD mMaximum;		// +0C Third Property, Max Value
};

/*=================================================================*/
/*   Data Structure for shrines			                           */
/*=================================================================*/
struct StateEffect
{
	Unit* ptSource;		// +00
	Unit* ptTarget;		// +04
	DWORD skillID;		// +08
	DWORD skillSLVL;	// +0C
	DWORD duration;		// +10
	DWORD StatID;		// +14
	DWORD StatValue;	// +18
	DWORD StateID;		// +1C
	DWORD EndOffset;	// +20
};

/*=================================================================*/
/*   Data Structure for menus			                           */
/*=================================================================*/
struct Menu
{
};

/*=================================================================*/
/*   Data Structure for Cube Input and Output                      */
/*=================================================================*/

struct CubeInput
{
	BYTE	Flag1;			// +00	Flags
	BYTE	Flag2;			// +01	Flags
	WORD	ID;				// +02	ItemNbr, ItemType
	WORD	unknown;		// +04
	BYTE	Quality;		// +06	Item Quality
	BYTE	Quantity;		// +07	Quantity
};

struct CubeOutput
{
	BYTE	Flag1;			// +00 Flags
	BYTE	Flag2;			// +01 Flags
	WORD	ID;				// +02 ItemNbr
	WORD	unknown1;		// +04
	BYTE	Quality;		// +06 Item Quality
	BYTE	Quantity;		// +07 Quantity
	BYTE	OutputItem;		// +08 Flag to show what to Output
	BYTE	unused[3];		// +09 Overwritten in cube
	WORD	Prefix;			// +0C Prefix to Add to item
	DWORD	unknown2;		// +0E
	WORD	Suffix;			// +12 Suffix to Add to item
	DWORD	unknown3;		// +14
};

/*=================================================================*/
/*   Data Structure for objects			                           */
/*=================================================================*/

struct Operate
{
	D2Game*		ptGame;		//+00
	Unit*		ptObject;	//+04
	Unit*		ptPlayer;	//+08
	void*		ptUnknown;	//+0C	ptGame + 0x10F0
	DWORD		nObjectID;	//+10
};

/*=================================================================*/
/*   Data Structure for NPC menus		                           */
/*=================================================================*/
struct NpcMenuData
{
	DWORD		NpcID;				//+00
	DWORD		NbrMenuItems;		//+04
	WORD		MenuItemTxt[5];		//+08
	DWORD		MenuItemFunc[5];	//+12
	BYTE		Unknown;			//+26
};

/*=================================================================*/
/*   Data Structure for Vendor screens							   */
/*=================================================================*/
struct VLItems
{
	BYTE		VendorMin;			//+00
	BYTE		VendorMax;			//+01
	BYTE		VendorMagicMin;		//+02
	BYTE		VendorMagicMax;		//+03
	DWORD		ItemCode;			//+04
	DWORD		VendorMagicLvl;		//+08
};

struct VendorLst
{
	VLItems*	LimitItems;			//+00
	DWORD		LimitCount;			//+04
	DWORD*		PermItems;			//+08
	DWORD		PermCount;			//+0C
};
#pragma pack()

#endif
