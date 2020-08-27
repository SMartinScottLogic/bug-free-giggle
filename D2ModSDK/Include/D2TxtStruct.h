/*=================================================================*/
/** @file D2SkillsTxt .h
 *  @brief Diablo II Constants.
 *
 *  (c) January 2002 - Joel Falcou for The Phrozen Keep.
 */
/*=================================================================*/

#ifndef __D2TXTSTRUCT_H__INCLUDED__
#define __D2TXTSTRUCT_H__INCLUDED__


struct D2DataTables
{
	BYTE	unknown1[0x0C0C];
	DWORD*	D2Sets;				// +0C0C Sets.txt
	DWORD	D2SetsCount;		// +0C10
	DWORD	unknown2;			// +0C14
	DWORD*	D2SetItems;			// +0C18 SetItems.txt
	DWORD	D2SetItemsCOunt;	// +0C1C
};

struct D2SkillsTXT
{
	WORD	SkillID;			//+00
	BYTE	Mask1;				//+02
	BYTE	Mask2;				//+03
	BYTE	Unknown[8];			//+04
	BYTE	CharClass;			//+0C
	BYTE	unknown_1[0x187];	//+0D
	WORD	SkillDesc;			//+194
	BYTE	unknown_2[0xA6];	//+196
};

struct D2SkillDescTXT
{
	BYTE	unknown_1[0x08];	//+00
	WORD	SkillName;			//+08
	BYTE	unknown[0x116];		//+00
};

struct D2BooksTXT
{
	WORD	Name_Unused;		//+00
	WORD	SkillIcon;			//+02
	DWORD	pSpell;				//+04
	DWORD	ScrollSkill;		//+08
	DWORD	BookSkill;			//+0C
	DWORD	BaseCost;			//+10
	DWORD	CostPerCharge;		//+14
	DWORD	ScrollSpellCode;	//+18
	DWORD	BookSpellCode;		//+1C
};

struct D2ItemsTXT
{
	char	FlippyFile[0x20];		//+00
	char	InvFile[0x20];			//+20
	char	UniqueInvFile[0x20];	//+40
	char	SetInvFile[0x20];		//+60
	DWORD	ItemCode;				//+80
	DWORD	NormCode;				//+84
	DWORD	UberCode;				//+88
	DWORD	HellCode;				//+8C
	DWORD	AlternateGfx;			//+90
	DWORD	pSpell;					//+94
	WORD	State;					//+98
	WORD	cState1;				//+9A
	WORD	cState2;				//+9C
	WORD	Stat1;					//+9E
	WORD	Stat2;					//+A0
	WORD	Stat3;					//+A2
	DWORD	Calc1;					//+A4
	DWORD	Calc2;					//+A8
	DWORD	Calc3;					//+AC
	DWORD	Len;					//+B0
	WORD	SpellDesc;				//+B4
	WORD	SpellDescStr;			//+B6
	DWORD	SpellDescCalc;			//+B8
	DWORD	BetterGem;				//+BC
	DWORD	WClass;					//+C0
	DWORD	TwoHandedWClass;		//+C4
	DWORD	TMogType;				//+C8
	DWORD	MinAC;					//+CC
	DWORD	MaxAC;					//+D0
	DWORD	GambleCost;				//+D4
	DWORD	Speed;					//+D8
	DWORD	BitField;				//+DC
	DWORD	Cost;					//+E0
	DWORD	MinStack;				//+E4
	DWORD	MaxStack;				//+E8
	DWORD	SpawnStack;				//+EC
	DWORD	GemOffset;				//+F0
	WORD	NameStr;				//+F4
	WORD	Version;				//+F6
	WORD	AutoPrefix;				//+F8
	WORD	MissileType;			//+FA
	BYTE	Rarity;					//+FC
	BYTE	Level;					//+FD
	BYTE	MinDam;					//+FE
	BYTE	MaxDam;					//+FF
	BYTE	MinMisDam;				//+100
	BYTE	MaxMisDam;				//+101
	BYTE	TwoHandMinDam;			//+102
	BYTE	TwoHandMaxDam;			//+103
	BYTE	RangeAdder;				//+104
	BYTE	NotUsed1;				//+105
	WORD	StrBonus;				//+106
	WORD	DexBonus;				//+108
	WORD	RegStr;					//+10A
	WORD	RegDex;					//+10C
	BYTE	Absorbs;				//+10E
	BYTE	InvWidth;				//+10F
	BYTE	InvHeight;				//+110
	BYTE	Block;					//+111
	BYTE	Durability;				//+112
	BYTE	NoDurability;			//+113
	BYTE	Missile;				//+114
	BYTE	Component;				//+115
	BYTE	RArm;					//+116
	BYTE	LArm;					//+117
	BYTE	Torso;					//+118
	BYTE	Legs;					//+119
	BYTE	RSpad;					//+11A
	BYTE	LSpad;					//+11B
	BYTE	TwoHanded;				//+11C
	BYTE	Usable;					//+11D
	WORD	Type;					//+11E
	WORD	Type2;					//+120
	BYTE	SubType;				//+122
	BYTE	NotUsed2;				//+123
	WORD	DropSound;				//+124
	WORD	UseSound;				//+126
	BYTE	DropSfxFrame;			//+128
	BYTE	Unique;					//+129
	BYTE	Quest;					//+12A
	BYTE	QuestDiffCheck;			//+12B
	BYTE	Transparent;			//+12C
	BYTE	TransTbl;				//+12D
	BYTE	NotUsed3;				//+12E
	BYTE	LightRadius;			//+12F
	BYTE	Belt;					//+130
	BYTE	AutoBelt;				//+131
	BYTE	Stackable;				//+132
	BYTE	Spawnable;				//+133
	BYTE	SpellIcon;				//+134
	BYTE	DurWarning;				//+135
	BYTE	QntWaning;				//+136
	BYTE	HasInv;					//+137
	BYTE	GemSockets;				//+138
	BYTE	TransmoGrify;			//+139
	BYTE	TMogMin;				//+13A
	BYTE	TMogMax;				//+13B
	BYTE	HitClass;				//+13C
	BYTE	OneOrTwoHanded;			//+13D
	BYTE	GemApplyType;			//+13E
	BYTE	LevelReq;				//+13F
	BYTE	MagicLvl;				//+140
	BYTE	Transform;				//+141
	BYTE	InvTrans;				//+142
	BYTE	CompactSave;			//+143
	BYTE	SkipName;				//+144
	BYTE	NotUsed4;				//+145
	BYTE	VendorMin[17];			//+146
	BYTE	VendorMax[17];			//+157
	BYTE	VendorMagicMin[17];		//+168
	BYTE	VendorMagicMax[17];		//+179
	BYTE	VendorMagicLvl[17];		//+18A
	BYTE	NotUsed5;				//+19B
	DWORD	NightmareUpgrade;		//+19C
	DWORD	HellUpgrade;			//+1A0
	BYTE	PermStoreItem;			//+1A4
	BYTE	Multibuy;				//+1A5
};

#pragma pack(1)
struct D2RunesTXT
{
	char	Name[0x40];				//+00
	char	RuneName[0x40];			//+40
	BYTE	Complete;				//+80
	BYTE	Server;					//+81
	BYTE	Unknown[4];				//+82
	WORD	Itypes[6];				//+86
	WORD	Etypes[3];				//+92
	int		Runes[6];				//+98
	DWORD	t1code1;				//+B0
	DWORD	t1param1;				//+B4
	DWORD	t1min1;					//+B8
	DWORD	t1max1;					//+BC
	DWORD	t1code2;				//+C0
	DWORD	t1param2;				//+C4
	DWORD	t1min2;					//+C8
	DWORD	t1max2;					//+CC
	DWORD	t1code3;				//+D0
	DWORD	t1param3;				//+D4
	DWORD	t1min3;					//+D8
	DWORD	t1max3;					//+DC
	DWORD	t1code4;				//+E0
	DWORD	t1param4;				//+E4
	DWORD	t1min4;					//+E8
	DWORD	t1max4;					//+EC
	DWORD	t1code5;				//+F0
	DWORD	t1param5;				//+F4
	DWORD	t1min5;					//+F8
	DWORD	t1max5;					//+FC
	DWORD	t1code6;				//+100
	DWORD	t1param6;				//+104
	DWORD	t1min6;					//+108
	DWORD	t1max6;					//+10C
	DWORD	t1code7;				//+110
	DWORD	t1param7;				//+114
	DWORD	t1min7;					//+118
	DWORD	t1max7;					//+11C
	// Custom Added
	BYTE	quality;				//+120
};
#pragma pack()

struct D2RuneStruct
{
	int			nNbrOfRuneWords;
	D2RunesTXT*	ptRunes;
};

#endif
