// StatFix.cpp : Sample mod dll for use with D2Mod.dll mod system
// Author: SVR 2004
//
//=======================================================================

#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include <stdio.h>
#include "StatFix.h"	// add you header here


//=======================================================================
// mod data - put needed global data here

#define BAR_WIDTH 102
#define MAX_STATS 4

struct STATS {
	int stat,max_stat;
	int color1,color2,color3;
	int nIndex;
	int nScale;
};

STATS stats[MAX_STATS];

static int numStats=0;

//========================================================================
// mod functions - put functions to call from edits here


int GetStat(int stat)
{
	return D2CommonGetStat(D2ClientGetClient(),stat);
}

BOOL CheckState(int state)
{
	return D2CommonCheckState((DWORD)D2ClientGetClient(),state);
}

BOOL CheckPlayerState(int state)
{
	return D2CommonCheckPlayerState((DWORD)D2ClientGetClient(),state);
}

void FASTCALL DoStatBar() //int x,int y,int w,int h,BYTE color,BYTE trans)
{
	int x,y,w,h;
	WCHAR buff[100];
	int textColor=0;	// 0 - 16 text color
	int color=stats[0].color2;

	__int64 stat=GetStat(stats[0].stat);
	__int64 max_stat=GetStat(stats[0].max_stat);

	if(stats[0].color1==0)
	{
		stats[0].color1=D2WinGetPaletteIndex(0xFF,0,0);
		stats[0].color2=D2WinGetPaletteIndex(0xF4,0xC0,0x4C);
		stats[0].color3=D2WinGetPaletteIndex(0,0,0xFF);
	}

	x=((gScreenX>>1)-0x7f);
	y=(gScreenY-27);

	h=0x12/(numStats);

	if(stat>=(max_stat+5) || CheckPlayerState(0x18))	//stamina shrine active ?
		color=stats[0].color3;

	if(CheckState(0x88))	//stamina shrine active ?
		textColor=3;

	for(int i=0;i<numStats;i++)
	{
		int nIndex=stats[i].nIndex;
		int Scale=stats[i].nScale;
		
		stat=GetStat(stats[i].stat);
		max_stat=GetStat(stats[i].max_stat);

		if(max_stat==0) {
			y+=h;
			continue;
		}

		if(i)
			color=stats[i].color2;


		w=(int)(stat*BAR_WIDTH/max_stat);

		if(w<=0) {
			y+=h;
			continue;
		}

		if(w>BAR_WIDTH)
			w=BAR_WIDTH;
		else if(w<(BAR_WIDTH>>2))
			color=stats[i].color1;

		RECT rc={x,y,x+w,y+h};

		D2ClientFillRect(x,y,w,h,color,2);

		if(PtInRect(&rc,ptMouse)) {
			if(i)
				textColor=i;	// 0 - 16 text color

			memset(buff,0,sizeof(buff));

			DWORD tmp1=(DWORD)(stat/Scale);
			DWORD tmp2=(DWORD)(max_stat/Scale);
			Unicode :: sprintf(100,(Unicode *)buff,uStrFromIndex(nIndex),tmp1,tmp2);
			D2WinAddDisplayString(buff,x+33,y-27,textColor,1);
		}
		y+=h;
	}
}

NAKED FASTCALL SendStats2()
{
	__asm {
		SUB     ESP,0x30
		LEA     EAX,[ESP]
		PUSH    ESI
		PUSH    EDI
		PUSH    ECX
		MOV     BYTE PTR [EAX],0x95
		LEA     EDI,[EAX+0x5]
		MOV     ECX,0x6
		LEA     ESI,[EAX+0x34]
		MOV     [EAX+0x1],EDX
		REP     MOVSD
		POP     ECX
		MOV     EDX,EAX
		PUSH    0x20

		call	dword ptr [D2Game00C710]

		POP     EDI
		POP     ESI
		ADD     ESP,0x30
		RETN    0x18
	}
}

//========================================================================
// code edits - add code edits here
// {dwOffset, dwValue, FixupType =FT_NON,FT_REL or FT_FIX}

DECLARE_COMMON_MODS(0)
// D2Common edits here

END_MODS

DECLARE_CLIENT_MODS(57)
// D2Client edits here
//===========================
// ReceiveStat2
	{0x013320,0x5730EC83,FT_NON},
	{0x013324,0x04247c8d,FT_NON},
	{0x013328,0x01718d56,FT_NON},
	{0x01332C,0x000007b9,FT_NON},
	{0x013330,0x5EA5F300,FT_NON},
	{0x013334,0x90907CEB,FT_NON},

	{0x0133C3,0x0C24748B,FT_NON},
	{0x0133C7,0x9090006A,FT_NON},
	{0x0133CB,0x90909090,FT_NON},

	{0x0133DB,0x1024448B,FT_NON},
	{0x0133DF,0x9090006A,FT_NON},
	{0x0133E3,0xC1909090,FT_NON},


	{0x0133F2,0x14244C8B,FT_NON},
	{0x0133F6,0x9090006A,FT_NON},
	{0x0133FA,0x90909090,FT_NON},

	{0x01340A,0x2024448B,FT_NON},
	{0x01340E,0x24244C8B,FT_NON},

	{0x013437,0x1C245C8B,FT_NON},
	{0x01343B,0x1824548B,FT_NON},

	{0x01347A,0xC330C483,FT_NON},

//============================
//copy stats from recv buf
	{0x015298,0x4C8D206A,FT_NON},
	{0x0152B5,0xE850206A,FT_NON},

	{0x0152C1,0xE851206A,FT_NON},
	{0x0152CD,0xE852206A,FT_NON},
	{0x0152D9,0xE850206A,FT_NON},
	{0x0152E5,0xE851206A,FT_NON},
	{0x0152F1,0xE852206A,FT_NON},
	{0x0152FD,0xE850206A,FT_NON},

//===========================
// Health globe

	{0x05F9DA,0xB030E850,FT_NON},
	{0x05F9DE,0xC0850006,FT_NON},
	{0x05F9E2,0x016A840F,FT_NON},
	{0x05F9E6,0xF08B0000,FT_NON},
	{0x05F9EA,0x000006B9,FT_NON},
	{0x05F9EE,0xF8DCE800,FT_NON},
	{0x05F9F2,0x9090FFFF,FT_NON},
	{0x05F9F6,0xBB539090,FT_NON},
	{0x05F9FA,0x00000050,FT_NON},
	{0x05F9FE,0xFEF7EBF7,FT_NON},

	{0x05FAE2,0x19E83F7E,FT_NON}, // fix blizzard bug -hp crash ! 

	
//===========================
// Mana globe
	{0x05FB6A,0xB65CE850,FT_NON},
	{0x05FB6E,0xC0850006,FT_NON},
	{0x05FB72,0x011D840F,FT_NON},
	{0x05FB76,0xF08B0000,FT_NON},
	{0x05FB7A,0x000008B9,FT_NON},
	{0x05FB7E,0xF74CE800,FT_NON},
	{0x05FB82,0xF03BFFFF,FT_NON},
	{0x05FB86,0xC68B027D,FT_NON},
	{0x05FB8A,0x0050BB53,FT_NON},
	{0x05FB8E,0xEBF70000,FT_NON},

	{0x05FB92,0x9090FEF7,FT_NON},
	{0x05FB96,0x12B99090,FT_NON},

//===========================	
//stamina bar

	{0x06006A,0x000066B8,FT_NON},
	{0x06006E,0x90EFF700,FT_NON},
	{0x060072,0x90909090,FT_NON},
	{0x060076,0x83FDF790,FT_NON},

//============================
// multi-bar
	{0x05F999,(DWORD)DoStatBar,FT_REL},
	
//============================
// packet-size
	{0x0D6970,0x20,FT_NON},
END_MODS

DECLARE_GAME_MODS(2)
// D2Game edits here
	{0x0D9A0,0xE9,FT_NON},
	{0x0D9A1,(DWORD)SendStats2,FT_REL},
END_MODS

DECLARE_WIN_MODS(0)
// D2Win edits here

END_MODS

DECLARE_GFX_MODS(0)
// D2Gfx edits here

END_MODS

DECLARE_NET_MODS(1)
// D2Net edits here
	{0x0839c,0x20,FT_NON},
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

//========================================================
// dll init functions - setup your mod here


// exported Init function called by loader (D2Mod.dll)

STATFIX_API LPMODDATA STDCALL Init(LPSTR IniName)
{
	// Initialize any memory/resources here

	int i;
	char buff[256];
	char s[30];

	stats[0].stat=0xA;
	stats[0].max_stat=0xB;
	stats[0].color1=D2WinGetPaletteIndex(0xFF,0,0);
	stats[0].color2=D2WinGetPaletteIndex(0xF4,0xC0,0x4C);
	stats[0].color3=D2WinGetPaletteIndex(0,0,0xFF);
	stats[0].nIndex=0x1044;
	stats[0].nScale=256;

	numStats=MAX_STATS;

	for(i=1;i<numStats;i++)
	{
		wsprintf(s,"stat%d",i);
		GetPrivateProfileString( "statbar",s,"NONE",buff,256,IniName);
		if(lstrcmpi(buff,"NONE")==0)
		{
			numStats=i;
			break;
		}
		sscanf(buff,"%d,%d,%d,%d,%d,%d,%d",&stats[i].stat,&stats[i].max_stat,
			&stats[i].color1,&stats[i].color2,&stats[i].color3,&stats[i].nIndex,&stats[i].nScale);
		if(stats[i].nScale==0)
			stats[i].nScale=1;
	}
	// always return the DECLARE_DATA name
	return &ModData;
}

// exported Release function called by loader (D2Mod.dll)
STATFIX_API BOOL STDCALL Release()
{
	// release any memory/resources here
	return TRUE;
}


//======================================================

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	// According to MS: Don't call anything here that
	//  may link in another call to LoadLibrary.
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

