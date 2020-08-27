// ExtLvl.cpp : mod dll for use with D2Mod.dll mod system
//		Allows up to 1024 levels
// Author: afj666
// Converted to D2MOD by SVR
//=======================================================================

#include <d2mod.h>	// main include for all import definitions/library functions
#include "extlvl.h"	// add you header here


//=======================================================================
// mod data - put needed global data here

static DWORD ECXSave;
//=======================================================================
// mod functions - put functions to call from edits here

/*
0008D546   890D A771B96F    MOV DWORD PTR DS:[6FB971A7],ECX
0008D54C   8B5424 10        MOV EDX,DWORD PTR SS:[ESP+10]
0008D550   33C0             XOR EAX,EAX
0008D552  ^E9 862DF9FF      JMP 000202DD
*/

NAKED Func8D546()
{
	__asm {
		MOV ECXSave,ECX
		MOV EDX,DWORD PTR SS:[ESP+0x14]	// add 4 for return
		XOR EAX,EAX
		RET		// 0008D552  ^E9 862DF9FF      JMP 000202DD
	}
}
/*
0008D559   A1 A771B96F      MOV EAX,DWORD PTR DS:[6FB971A7]
0008D55E   8B4C24 04        MOV ECX,DWORD PTR SS:[ESP+4]
0008D562   85C9             TEST ECX,ECX
0008D564   74 08            JE SHORT 0008D56E
0008D566   05 20020000      ADD EAX,220
0008D56B   49               DEC ECX
0008D56C  ^EB F4            JMP SHORT 0008D562
0008D56E   8B40 03          MOV EAX,DWORD PTR DS:[EAX+3]
0008D571   25 FF000000      AND EAX,0FF
0008D576   C2 0400          RETN 4
*/

NAKED Func8D559()
{
	__asm {
		MOV EAX,ECXSave
		MOV ECX,DWORD PTR SS:[ESP+4]	// jmp'd here no stack adjust
loop1:
		TEST ECX,ECX
		JE SHORT jmp1	// 0008D56E
		ADD EAX,0x220
		DEC ECX
		JMP SHORT loop1	//0008D562
jmp1:
		MOV EAX,DWORD PTR DS:[EAX+3]
		AND EAX,0xFF
		RETN 4
	}
}

//=======================================================================
// code edits - add code edits here
// {dwOffset, dwValue, FixupType =FT_NON,FT_REL or FT_FIX}


DECLARE_COMMON_MODS(6)
// D2Common edits here
/*
***********************************************************
D2Common.dll
***********************************************************
000202D7   E8 6AD20600      CALL 0008D546
000202DC   90               NOP
*/

{0x00202D7,0xE8,FT_NON},
{0x00202D8,(DWORD)Func8D546,FT_REL},
{0x00202DC,0x8D286A90,FT_NON},			// clean for return

/*
***********************************************************
00035300   E9 54820500      JMP 0008D559
00035305   90               NOP
00035306   90               NOP
00035307   90               NOP
00035308   90               NOP
*/

{0x0035300,0xE9,FT_NON},
{0x0035301,(DWORD)Func8D559,FT_REL},	// no need to clean, no return here


{0x008E5C4,0x85,FT_NON},
//	8E5C5:	04	00

END_MODS

DECLARE_CLIENT_MODS(19)
// D2Client edits here

/*
***********************************************************
D2Client.dll
***********************************************************
*/


//0002C080   81EC 0C100000    SUB ESP,100C
{0x2C082,0x0000100C,FT_NON},

//0002C09E   B9 99030000      MOV ECX,399
{0x2C09F,0x00000399,FT_NON},

//0002C0B9   68 00100000      PUSH 1000
{0x2C0BA,0x00001000,FT_NON},

//0002C0C9   817C24 10 001000>CMP DWORD PTR SS:[ESP+10],1000
{0x2C0CD,0x00001000,FT_NON},

//0002C0D3   B9 00040000      MOV ECX,400
{0x2C0D4,0x00000400,FT_NON},

//0002C0F5   68 00100000      PUSH 1000
{0x2C0F6,0x00001000,FT_NON},

//0002C180   68 00100000      PUSH 1000
{0x2C181,0x00001000,FT_NON},

//0002C2A4   81C4 0C100000    ADD ESP,100C
{0x2C2A6,0x0000100C,FT_NON},


//************************************************************

//0002C615   81EC 4C100000    SUB ESP,104C
{0x2C617,0x0000104c,FT_NON},

// 0002C639   B9 99030000      MOV ECX,399
{0x2C63A,0x00000399,FT_NON},

// 0002C650   68 00100000      PUSH 1000
{0x2C651,0x00001000,FT_NON},

//0002C664   817C24 14 001000>CMP DWORD PTR SS:[ESP+14],1000
{0x2C668,0x00001000,FT_NON},

//0002C86C   68 00100000      PUSH 1000
{0x2C86D,0x00001000,FT_NON},

//0002C99F   68 00100000      PUSH 1000
{0x2C9A0,0x00001000,FT_NON},

//0002CAE4   68 00100000      PUSH 1000
{0x2CAE5,0x00001000,FT_NON},

//0002CC2B   68 00100000      PUSH 1000
{0x2CC2C,0x00001000,FT_NON},

//0002CC67   81C4 4C100000    ADD ESP,104C
{0x2CC69,0x0000104C,FT_NON},

//0002CCA7   81C4 4C100000    ADD ESP,104C
{0x2CCA9,0x0000104C,FT_NON},

//0002CCC5   68 00100000      PUSH 1000
{0x2CCC6,0x00001000,FT_NON},


  
//************************************************************


END_MODS


DECLARE_GAME_MODS(0)
// D2Game edits here
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

//=======================================================================
// dll init functions - setup your mod here


// exported Init function called when loading by D2Mod.dll

MYMOD_API LPMODDATA STDCALL Init(LPSTR IniName)
{
	// Initialize any memory/resources here
	// use the ini file name passed to get settings

	return &ModData;
}

// exported Release function called by when unloading
MYMOD_API BOOL STDCALL Release()
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

