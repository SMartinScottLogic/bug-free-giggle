// MercMod.cpp : Sample mod dll for use with D2Mod.dll mod system
// Author: SVR 2004
//
//=======================================================================

#include <d2mod.h>		// main include for all import definitions/library functions
#include <stdio.h>		// for sscanf
#include "MercMod.h"	// add you header here


//=======================================================================
// mod data - put needed global data here
#define MAXMERCS 4
#define MAXTYPES 10
#define SHIELDTYPE 2
#define WEAPONTYPE 0x2D

struct MERC {
	int mClass;
	BOOL bShield;
	int iCnt;
	int iTypes[MAXTYPES];
};

int numMercs;

MERC merc[MAXMERCS];

//========================================================================
// mod functions - put functions to call from edits here


BOOL FASTCALL CheckMercItem(int mClass,LPVOID ptItem)
{
	// add checks for allowed weapons here

	for(int i=0;i<numMercs;i++)
	{
		if(mClass == merc[i].mClass)
		{
			if(CheckItemType(ptItem,SHIELDTYPE))
				if(!merc[i].bShield)
					return FALSE;
			for(int j=0;j<merc[i].iCnt;j++)
			{
				if(merc[i].iTypes[j])
					if(CheckItemType(ptItem,merc[i].iTypes[j]))
						return TRUE;
			}
			break;
		}

	}
	if(!CheckItemType(ptItem,WEAPONTYPE))
		return TRUE;

	return FALSE;
}

BOOL STDCALL ClientCheck(LPVOID ptItem,LPBYTE pUnit)
{
	if(!pUnit)
		pUnit=(LPBYTE)-1;
	else
		pUnit=*(LPBYTE *)(pUnit+0xC);

	return CheckMercItem(GetMercClass(pUnit),ptItem);

}
BOOL STDCALL GameCheck(LPVOID ptItem,int *pt)
{
	return CheckMercItem(*(pt+1),ptItem);
}

//--------------------------------------------------


static DWORD pickLoc=0;

NAKED GrabPickLocation()
{
	__asm {
		mov eax,[esp+0x18]
		movzx eax,[eax+1]
		mov pickLoc,eax
		ret
	}
}

DWORD STDCALL StoreMercItem(LPVOID ptMerc,LPVOID *ptItem,LPVOID *removeItem,DWORD *storeLoc)
{
	*storeLoc=pickLoc;

	DWORD equip1=0,equip2=0;

	GetEquipLocations(ptItem,&equip1,&equip2);

	LPVOID p1=GetEquipedItem(ptMerc,equip1);
	LPVOID p2=GetEquipedItem(ptMerc,equip2);

	if(pickLoc==equip2) {
		LPVOID tmp=p1;
		p1=p2;
		p2=tmp;
	}

	if(is2Handed(ptItem)) {
		if(p1&&p2)
			return 0;
		if(!p1) {
			p1=p2;
			p2=0;
		}
	}

	if(!p1 && p2)
		if(is2Handed(p2))
			p1=p2;

	*removeItem=p1;
	return 1;
}


//========================================================================
// code edits - add code edits here
// {dwOffset, dwValue, bRelative }


DECLARE_COMMON_MODS(0)
// D2Common edits here

END_MODS

DECLARE_CLIENT_MODS(3)
// D2Client edits here
	{0x04D4DF,0xE8539055,FT_NON},
	{0x04D4E3,(DWORD)ClientCheck,FT_REL},
	{0x04E6BF,0x61B1D38B,FT_NON}, // stuff equip location
END_MODS

DECLARE_GAME_MODS(12)
// D2Game edits here
	{0x058BB7,0xE8569057,FT_NON},
	{0x058BBB,(DWORD)GameCheck,FT_REL},

// Store Item code patch

	{0x058960,0xe8,FT_NON},
	{0x058961,(DWORD)GrabPickLocation,FT_REL},
	{0x058965,0x90909090,FT_NON},
	{0x058969,0x18244489,FT_NON},

	{0x058D7F,0xE8555251,FT_NON},
	{0x058D83,(DWORD)StoreMercItem,FT_REL},
	{0x058D87,0xDB74C085,FT_NON},
	{0x058D8B,0x10246C8B,FT_NON},
	{0x058D8F,0x1424748B,FT_NON},
	{0x058D93,0x8B9042EB,FT_NON},

END_MODS

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

//========================================================
// dll init functions - setup your mod here


// exported Init function called when loading by D2Mod.dll

MERCMOD_API LPMODDATA STDCALL Init(LPSTR IniName)
{
	// Initialize any memory/resources here
	// using the ini file name passed 
	int i;
	char buff[256];
	char s[30];

	numMercs=MAXMERCS;

	memset(merc,0,sizeof(merc));
	for(i=0;i<numMercs;i++)
	{
		wsprintf(s,"merc%d",i+1);
		GetPrivateProfileString( "mercmod",s,"NONE",buff,256,IniName);
		if(lstrcmpi(buff,"NONE")==0)
		{
			numMercs=i;
			break;
		}
		char *p;

		if((p=strtok(buff,","))!=NULL)
			sscanf(buff,"%d",&merc[i].mClass);
		if((p=strtok(NULL,","))!=NULL)
			sscanf(buff,"%d",&merc[i].bShield);

		int n=0;
		while((p=strtok(NULL,","))!=NULL) {
			sscanf(p,"%d",&merc[i].iTypes[n++]);
			if(n>=MAXTYPES)
				break;
		}
		merc[i].iCnt=n;
	}
	return &ModData;
}

// exported Release function called by when unloading
MERCMOD_API BOOL STDCALL Release()
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

