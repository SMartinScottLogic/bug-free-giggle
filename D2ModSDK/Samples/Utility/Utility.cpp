// Utility.cpp : Sample mod dll for use with D2Mod.dll mod system
// Author: SVR 2004
//
//=======================================================================

#include <d2mod.h>	// main include for all import definitions/library functions
#include <stdio.h>
#include "Utility.h"	// add you header here


//=======================================================================
// mod data - put needed global data here


DWORD D2GameSetStat=D2GameBase+0xEB8BA;
int SkillPoints;
DWORD PlayersXmin=1;
BYTE PlayersXmax=8;
BYTE MaxGambleItems=0x0E;
BOOL bMagicTabs=0;
DWORD InvMult,StashMult;
BYTE MonDiff=25;
BYTE Skills1=1,Skills2=1,Skills3=2;
BOOL rune[10]={1,1,1,0,0,0,0,0,0,0};

// DWORD ptAct[5];

DWORD D2Common_0077C30=D2CommonBase+0x077C30;
//=======================================================================
// mod functions - put functions to call from edits here
static DWORD fret;
NAKED DoSkillPoints()
{
	__asm {
		pop fret	// restore stack
		mov edx,[esp+8]
		imul edx,SkillPoints
		mov [esp+8],edx
		call DWORD PTR [D2GameSetStat]
		push fret
		ret
	}
}
NAKED DoRuneword()
{
	__asm {
		dec eax
		mov eax,[rune+eax*4]
		test eax,eax
		ret
	}
}

NAKED MultGoldInv()
{
	__asm {
		pop fret
		call DWORD PTR [D2Common_0077C30]
		mul [InvMult]
		jno jmp1
		mov eax,0x7FFFFFFF
jmp1:
		retn 4
	}
}
NAKED MultGoldStash()
{
	__asm {
		pop fret
		call DWORD PTR [D2Common_0077C30]
		mul [StashMult]
		jno jmp1
		mov eax,0x7FFFFFFF
jmp1:
		retn 4
	}
}

//=======================================================================
// code edits - add code edits here
// {dwOffset, dwValue, FixupType =FT_NON,FT_REL or FT_FIX}


DECLARE_COMMON_MODS(6)
// D2Common edits here
// enable runewords
{0x05DA03,0xE8909090,FT_NON},
{0x05DA07,(DWORD)DoRuneword,FT_REL},

// UseGambleCost
{0x05B384,0x018E840F,FT_NON},
{0x05B385,0x00018E84,FT_NON},

// gold mult
{0x81D9A,(WORD)MultGoldInv,FT_REL},
{0x8263A,(WORD)MultGoldStash,FT_REL},

END_MODS

//---------------------------------------
DECLARE_CLIENT_MODS(5)
// D2Client edits here

//playersXmax
{0x32B78,0x7CF08B00+PlayersXmax,FT_NON},
{0x32B7E,PlayersXmax,FT_NON},

// Enable Magic Tabs
{0x0D958C,0x00000FC5+bMagicTabs,FT_NON},


{0x0032B73,0x83517E00+PlayersXmin,FT_NON},
{0x0032BC8,PlayersXmin,FT_NON},



END_MODS

//----------------------------------------
DECLARE_GAME_MODS(18)
// D2Game edits here

// skill points
{0x04ED60,(DWORD)DoSkillPoints,FT_REL}, //0

// PlayersXmin
{0x04C4A1,0x002444BA,FT_NON},	//1	
{0x04C4A2,PlayersXmin,FT_NON},	//2
{0x04C4A6,0x909024EB,FT_NON},	//3

//playersXmax
{0x04C496,0x89067F00+PlayersXmax,FT_NON},	//4

// Max items in gamble screen
{0x09ADF3,0xE58C0F00+MaxGambleItems,FT_NON},	//5

// Ancients Level cap
{0x086CAC,0xDD8B027E,FT_NON},	//6

// MonsterDiff
{0x092FC2,0x85097c00+MonDiff,FT_NON},	//7

// quest skill rewards
{0x01824B,0x56056A00+Skills1,FT_NON},	//8
{0x067CF6,0x51056A00+Skills2,FT_NON},	//9
{0x07DBE1,0x51056A00+Skills3,FT_NON},	//10

// tk takes all
{0x0E6889,0xE853166A,FT_NON},		//11
{0x0E688D,0x0000503B,FT_NON},		//12

// actX levels
{0x0F8E88,1,FT_NON},	//13
{0x0F8E8C,15,FT_NON},	//14
{0x0F8E90,20,FT_NON},	//15
{0x0F8E94,26,FT_NON},	//16
{0x0F8E98,32,FT_NON},	//17
END_MODS

//----------------------------------------
DECLARE_WIN_MODS(0)
// D2Win edits here

END_MODS

DECLARE_GFX_MODS(0)
// D2Gfx edits here

END_MODS

DECLARE_NET_MODS(0)
// D2Net edits here

END_MODS

DECLARE_LANG_MODS(0)
// D2Lang edits here

END_MODS

DECLARE_CMP_MODS(0)
// D2Cmp edits here

END_MODS

DECLARE_LAUNCH_MODS(0)
// D2Launch edits here

END_MODS
// stuct to pass to loader with pointers
DECLARE_DATA(ModData)

//=======================================================================
// dll init functions - setup your mod here


// exported Init function called when loading by D2Mod.dll

UTILITY_API LPMODDATA STDCALL Init(LPSTR IniName)
{
	// Initialize any memory/resources here
	// use the ini file name passed to get settings

	char buff[200];
	SkillPoints=GetPrivateProfileInt( "Utility","SkillPoints",1,IniName);

	GetPrivateProfileString( "Utility","EnableRunewords","1,1,1,0,0,0,0,0,0",buff,200,IniName);
	sscanf(buff,"%d,%d,%d,%d,%d,%d,%d,%d,%d",
		&rune[0],
		&rune[1],
		&rune[2],
		&rune[3],
		&rune[4],
		&rune[5],
		&rune[6],
		&rune[7],
		&rune[8]
	);

	PlayersXmin=GetPrivateProfileInt( "Utility","PlayersXmin",1,IniName);
	D2ModsCLIENT[3].newValue=(0x83517E00+PlayersXmin);
	D2ModsCLIENT[4].newValue=(PlayersXmin);
	D2ModsGAME[2].newValue=(PlayersXmin);

	
	PlayersXmax=GetPrivateProfileInt( "Utility","PlayersXmax",8,IniName);
	D2ModsCLIENT[0].newValue=(0x7CF08B00+PlayersXmax);
	D2ModsCLIENT[1].newValue=(PlayersXmax);
	D2ModsGAME[4].newValue=(0x89067F00+PlayersXmax);


	GetPrivateProfileString( "Utility","ActX","1,15,20,26,32",buff,200,IniName);
	sscanf(buff,"%d,%d,%d,%d,%d",
		&D2ModsGAME[13].newValue,
		&D2ModsGAME[14].newValue,
		&D2ModsGAME[15].newValue,
		&D2ModsGAME[16].newValue,
		&D2ModsGAME[17].newValue
	);

	if(GetPrivateProfileInt( "Utility","UseGambleCost",0,IniName)) {
		D2ModsCOMMON[2].newValue=0x018E84E9;
		D2ModsCOMMON[3].newValue=0x0000018F;
	}

	MaxGambleItems=GetPrivateProfileInt( "Utility","MaxGambleItems",0x0E,IniName);
	D2ModsGAME[5].newValue=(0xE58C0F00+MaxGambleItems);

	bMagicTabs=GetPrivateProfileInt( "Utility","UseMagicTabs",0,IniName);
	D2ModsCLIENT[2].newValue=(0x00000FC5+bMagicTabs);

	StashMult=GetPrivateProfileInt( "Utility","StashGold",10000,IniName);
	InvMult=GetPrivateProfileInt( "Utility","InvGold",10000,IniName);
	
	if(!GetPrivateProfileInt( "Utility","AncientsCap",1,IniName))
		D2ModsGAME[6].newValue=0xDD8B02EB;

	MonDiff=GetPrivateProfileInt( "Utility","MonsterDiff",25,IniName);
	D2ModsGAME[7].newValue=(0x85097c00+MonDiff);

	GetPrivateProfileString( "Utility","QuestSkills","1,1,2",buff,200,IniName);
	sscanf(buff,"%d,%d,%d",&Skills1,&Skills2,&Skills3);
	D2ModsGAME[8].newValue=(0x56056A00+Skills1);
	D2ModsGAME[9].newValue=(0x51056A00+Skills2);
	D2ModsGAME[10].newValue=(0x51056A00+Skills3);


	if(GetPrivateProfileInt( "Utility","tkTakeAll",0,IniName)) {
		D2ModsGAME[11].newValue=(0x0000A2E9);
		D2ModsGAME[12].newValue=(0x90909000);
	}	
	return &ModData;
}

// exported Release function called by when unloading
UTILITY_API BOOL STDCALL Release()
{
	// release any memory/resources here
	return TRUE;
}

//=======================================================================

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	// According to MS: Don't call anything here that
	// may link in another call to LoadLibrary.
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			break;
    }
    return TRUE;
}

