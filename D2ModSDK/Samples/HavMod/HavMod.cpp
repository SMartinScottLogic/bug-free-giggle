// MyMod.cpp : Sample mod dll for use with D2Mod.dll mod system
// Author: SVR 2004
//
//=======================================================================
#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include "HavMod.h"	// add you header here

//=======================================================================
// mod data - put needed global data here
#define VERSION "13 v0.01"

extern BOOL NewTXT_bound;

BYTE nImbue=6;
DWORD NewTXT_ReplacedCall = D2CommonBase+0x2f020;
DWORD NewTXT_fret;

//=======================================================================
// mod functions - put functions to call from edits here
DWORD __fastcall OverrideDispatcher(LPGAME ptGame, LPPLAYER ptPlayer, DWORD method, char *msg, DWORD len);

VOID PASCAL LoadWeight(DWORD unk);
VOID PASCAL UnloadWeight();
DWORD PASCAL getSpeedPostWeight(LPUNIT ptUnit, DWORD stat, DWORD zero);

HAVMOD_API NewTables(DWORD unk);
HAVMOD_API RemoveTables();
HAVMOD_API FreeNewTXT();

NAKED LoadNewTables()
{
        DWORD unk;
        __asm {
                PUSHAD;
                PUSHFD;
                MOV unk,ECX;
        }
        NewTables(unk);
        __asm {
                POPFD;
                POPAD;
                RETN;
        }
}

NAKED UnloadNewTables()
{
        RemoveTables();
        __asm {
                RETN;
        }
}

NAKED MakeSpaceLoading()
{
        __asm
        {
                CALL NewTXT_ReplacedCall;
        }
        LoadNewTables();
        __asm
        {
                RETN;
        }
}

NAKED MakeSpaceUnloading()
{
        __asm
        {
                pop NewTXT_fret;        // restore stack
                CALL DWORD PTR [Fog_10046];
        }
        UnloadNewTables();
        __asm
        {
                push NewTXT_fret;
                RETN;
        }
}

DWORD __cdecl CustomLabel(char * s, size_t n, const char * format, ... ) {
	unsigned int len = min(n, 1+strlen(VERSION));
	memcpy(s, VERSION, len);
	s[len]='\0';
	return len;
}

//=======================================================================
// code edits - add code edits here
// {dwOffset, dwValue, FixupType =FT_NON,FT_REL or FT_FIX}


DECLARE_COMMON_MODS(6)
// D2Common edits here
{0xA3984,(DWORD)Inscribe,FT_NON},
//NewTXT
{0x1048E,0x90900EEB,FT_NON},
{0x1049F,(DWORD)MakeSpaceUnloading,FT_REL},
{0x10798,(DWORD)MakeSpaceLoading,FT_REL},
{0x107a8,(DWORD)AddTable,FT_NON},
//Weight
{0x7F4C6,(DWORD)getSpeedPostWeight,FT_REL},
END_MODS

DECLARE_CLIENT_MODS(0)
// D2Client edits here

END_MODS

DECLARE_GAME_MODS(5)
// D2Game edits here
// Imbue
{0x09A296, nImbue, FT_NON},
// Inscribe
{0x1f1c5, (DWORD)getUnitName, FT_REL},
// Weight
{0x593e3,0x9090e853,FT_NON},
{0x593e6,0x90909090,FT_NON},
{0x593e5,(DWORD)OverrideDispatcher,FT_REL},
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

DECLARE_LAUNCH_MODS(2)
// D2Launch edits here
{0x96f7, (DWORD)CustomLabel, FT_REL},
{0x971a, (DWORD)CustomLabel, FT_REL},
END_MODS
// stuct to pass to loader with pointers
DECLARE_DATA(ModData)

//=======================================================================
// dll init functions - setup your mod here


// exported Init function called when loading by D2Mod.dll

HAVMOD_API LPMODDATA STDCALL Init(LPSTR IniName)
{
	// Initialize any memory/resources here
	// use the ini file name passed to get settings
	nImbue = GetPrivateProfileInt("HavMod","Imbue",6,IniName);
//	srand( (unsigned)time( NULL ) );
	switch(nImbue)
	{
		case 0:
		case 1:
		case 4:
		case 5:
		case 6:
		case 7:
			break;
/*		case 124:
			{
				int t = (rand()/(RAND_MAX/6));
				nImbue = t;
				if(t>1) nImbue += 2;
				if(nImbue > 7)
					nImbue = 7;
			}
			break;
*/		default:nImbue=6;
	}
	AddTable("Weight", LoadWeight, UnloadWeight);
	D2ModsGAME[0].newValue=nImbue;

	NewTXT_bound = TRUE;
	return &ModData;
}

// exported Release function called by when unloading
HAVMOD_API BOOL STDCALL Release()
{
	// release any memory/resources here
	FreeNewTXT();
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

