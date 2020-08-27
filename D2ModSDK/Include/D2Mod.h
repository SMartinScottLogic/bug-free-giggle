#ifndef _D2MOD_H
#define _D2MOD_H

#include <d2dlls.h>
#pragma comment( lib, "d2dlls" )

#ifndef D2MOD_EXPORTS
#pragma comment( lib, "d2mod" )
#endif



#define DECLARE_MODS(A,x) \
const D2MODS##A=x; \
SAVEFIX D2Save##A[x+1]; \
FIXUP D2Mods##A[x+1]={


#define END_MODS {0,0,FT_NON} \
};


#define DECLARE_COMMON_MODS(x) DECLARE_MODS(COMMON,x)

#define DECLARE_CLIENT_MODS(x) DECLARE_MODS(CLIENT,x)

#define DECLARE_GAME_MODS(x) DECLARE_MODS(GAME,x) 

#define DECLARE_WIN_MODS(x) DECLARE_MODS(WIN,x)

#define DECLARE_GFX_MODS(x) DECLARE_MODS(GFX,x)

#define DECLARE_NET_MODS(x) DECLARE_MODS(NET,x)

#define DECLARE_LANG_MODS(x) DECLARE_MODS(LANG,x)

#define DECLARE_CMP_MODS(x) DECLARE_MODS(CMP,x)

#define DECLARE_LAUNCH_MODS(x) DECLARE_MODS(LAUNCH,x)


/*
struct MODDATA {
	FIXUP *D2Mods;
	SAVEFIX *D2Save;
	DWORD D2MODSCNT;
};
*/

struct MODDATA {

	FIXUP *D2CommonMods;
	SAVEFIX *D2CommonSave;
	DWORD D2COMMONMODS;

	FIXUP *D2ClientMods;
	SAVEFIX *D2ClientSave;
	DWORD D2CLIENTMODS;

	FIXUP *D2GameMods;
	SAVEFIX *D2GameSave;
	DWORD D2GAMEMODS;

	FIXUP *D2WinMods;
	SAVEFIX *D2WinSave;
	DWORD D2WINMODS;

	FIXUP *D2GfxMods;
	SAVEFIX *D2GfxSave;
	DWORD D2GFXMODS;

	FIXUP *D2NetMods;
	SAVEFIX *D2NetSave;
	DWORD D2NETMODS;

	FIXUP *D2LangMods;
	SAVEFIX *D2LangSave;
	DWORD D2LANGMODS;

	FIXUP *D2CmpMods;
	SAVEFIX *D2CmpSave;
	DWORD D2CMPMODS;

	FIXUP *D2LaunchMods;
	SAVEFIX *D2LaunchSave;
	DWORD D2LAUNCHMODS;
};

typedef MODDATA* LPMODDATA;


#define DECLARE_DATA(x) \
MODDATA x = { \
	D2ModsCOMMON,D2SaveCOMMON,D2MODSCOMMON, \
	D2ModsCLIENT,D2SaveCLIENT,D2MODSCLIENT, \
	D2ModsGAME,  D2SaveGAME,D2MODSGAME, \
	D2ModsWIN,D2SaveWIN,D2MODSWIN, \
	D2ModsGFX,D2SaveGFX,D2MODSGFX, \
	D2ModsNET,D2SaveNET,D2MODSNET, \
	D2ModsLANG,D2SaveLANG,D2MODSLANG, \
	D2ModsCMP,D2SaveCMP,D2MODSCMP, \
	D2ModsLAUNCH,D2SaveLAUNCH,D2MODSLAUNCH, \
};


#endif
