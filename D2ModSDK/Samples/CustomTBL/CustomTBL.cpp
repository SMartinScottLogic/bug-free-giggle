// CustomTBL.cpp : Sample mod dll for use with D2Mod.dll mod system
// Converted to d2mod.dll by SVR 2004
// Author: Allen Jensen
//=======================================================================

#include <d2mod.h>	// main include for all import definitions/library functions
#include "CustomTBL.h"	// add you header here
#include "StrTable.hpp"

//=======================================================================
// mod data - put needed global data here


int gNumTables=MAX_TABLES;
LPSTR ptFiles[MAX_TABLES];

LPSTR pLogfilePath="CustomTbl.log";

//=======================================================================
// mod functions - put functions to call from edits here

/*
*****************************************
		Custom ASM
*****************************************
*/

NAKED func1()
{
	__asm {

		CALL LoadCustomTbl
		TEST EAX,EAX
		JE SHORT JMP1
		MOV [ESP+0x14],EAX	// add 4 to local for call ret address !
JMP1:
		MOV ECX,0x14D0
		RET
	}
}

static DWORD fRet;
NAKED func3()
{
	__asm {
		pop [fRet]			// pop return address
		PUSH ESI
		MOV ESI,ECX			// no need to save ecx
		XOR EDX,EDX
		CALL GetStringByIndex
		CMP EAX,-1
		JNZ SHORT JMP1		// 0000A7DC

		push [fRet]			// push return address
		CMP SI,0x4E20
		RET					// return to hooked function
JMP1: 
		POP ESI
		RET					// return all the way back to original caller
	}
}

NAKED func2()				// hook 03A27
{
	__asm {
		pop [fRet]			// pop return address
		PUSH EDX			// save edx,ecx
		PUSH ECX
		PUSH EDI			// re-push for call
		PUSH ESI
		CALL GetStringByRef
		POP ECX
		pop EDX
		TEST EAX,EAX
		JNZ SHORT JMP1		// 0000A803

//		PUSH EDI	//already on the stack ?
//		PUSH ESI
		CALL DWORD PTR [D2Lang_10067]

		push [fRet]			// push return address
		RET					// for local return

JMP1:
		POP EDI				// ? how many pops ???
		POP ESI
		POP EDI				// double ! should nop the original pushes *
		POP ESI
		RETN 8				// return to original caller
	}
}


NAKED func4()				// hook 3C09
{
	__asm {
		push edx			// save regs
		push ecx
		CALL UnLoadCustomTbl
		pop ecx				// restore regs
		pop edx
		pop [fRet]			// pop return
		push 325			// push from hook to fix stack
		push [fRet]			// push return back
		ret					//JMP 0x0003C0F	//ret1
	}
}

NAKED func5()				// hook not active in AFJ's code ???
{
	__asm {
		TEST EAX,EAX		
		JE SHORT JMP1		//0000A837
		MOV EDI,[EAX+0x11]
		MOV ESI,[EAX+9]
		ret					//JMP 0x0003662		// ret2
JMP1:
		pop eax				// pop return address
		XOR EAX,EAX
		POP EDI
		POP ESI
		POP EBX
		RETN				// return to original caller
	}
}

//=======================================================================
// code edits - add code edits here
// {dwOffset, dwValue, FixupType =FT_NON,FT_REL or FT_FIX}


DECLARE_COMMON_MODS(0)
// D2Common edits here

END_MODS

DECLARE_CLIENT_MODS(0)
// D2Client edits here

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

DECLARE_LANG_MODS(11)
// D2Lang edits here
// ASM changes for D2Lang.dll 1.10

//*****************************************
//		For D2Lang.#10000
//*****************************************
	{0x3512 ,0x000000E8		,FT_NON},
	{0x3513 ,(DWORD)func1	,FT_REL},			// E9 7D720000      CALL 0000A794 (func1)

//*****************************************
//		For D2Lang.#10004
//*****************************************
	{0x3740 ,0x000000E8		,FT_NON},
	{0x3741 ,(DWORD)func3	,FT_REL},			// E9 273700000     CALL 0000A7B8
	{0x3745 ,0x72909090		,FT_NON},			// 90               NOP ...

//*****************************************
//		For D2Lang.#10003
//*****************************************
	{0x3A27 ,(DWORD)func2	,FT_REL},			// E8 func2      Call 0000A7EA

//*****************************************
//		For D2Lang.#10001
//*****************************************
	{0x3C10 ,0x000000E8		,FT_NON},
	{0x3C11 ,(DWORD)func4	,FT_REL},			// E8 ...      CALL 0000A814 (func2)


//*****************************************
//		Fix table not exists crash
//*****************************************
	{0x365C ,0x000000E8		,FT_NON},
	{0x365D ,(DWORD)func5	,FT_REL},			// E8 ...      CALL func5 
	{0x3661 ,0x72F73B90		,FT_NON},			// 90			NOP ...

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

CUSTOMTBL_API LPMODDATA STDCALL Init(LPCSTR IniName)
{
	// Initialize any memory/resources here
	// use the ini file name passed to get settings

	char lLogFile[1024] = "";
    DWORD dw = 0;
	lstrcpy(lLogFile,IniName);
	char *p=strrchr(lLogFile,'\\');

	lstrcpy(p+1,pLogfilePath);


    set_logfile( lLogFile );
    log_info("*-------------------------------------------------------------*");
    log_info("|                                                             |");
    log_info("|    Custom Tbl Loader for 1.10 (NOT beta)                    |");
	log_info("|    by Allan JENSEN.                                         |");
    log_info("|                                                             |");
    log_info("|                                                             |");
	log_info("|    Modified for D2Mod.dll system by SVR                     |");
    log_info("|                                                             |");
    log_info("|                                                             |");
    log_info("*-------------------------------------------------------------*");
    log_info("");
	log_info( "Starting Diablo II.\n\n");


	log_info("\n\n");

	

	int i;
	char buff[256];
	char s[30];

	gNumTables=MAX_TABLES;

	memset(ptFiles,0,sizeof(ptFiles));
	for(i=0;i<gNumTables;i++)
	{
		wsprintf(s,"Table%d",i+1);
		GetPrivateProfileString( "CustomTbl",s,"NONE",buff,256,IniName);
		if(lstrcmpi(buff,"NONE")==0)
		{
			gNumTables=i;
			break;
		}
		ptFiles[i]=new char[lstrlen(buff)+1];
		lstrcpy(ptFiles[i],buff);
	}

	return &ModData;
}

// exported Release function called by when unloading
CUSTOMTBL_API BOOL STDCALL Release()
{

	// release any memory/resources here
	for(int i=0;i<gNumTables;i++)
	{
		if(ptFiles[i]) {
			delete ptFiles[i];
			ptFiles[i]=0;
		}
	}

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

