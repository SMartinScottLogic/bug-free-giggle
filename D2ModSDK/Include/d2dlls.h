#ifndef _D2DLLS_H
#define _D2DLLS_H
#include <windows.h>

#include <D2Types.h>
#include <d2error.h>
#include "d2client.h"
#include "d2cmp.h"
#include "d2common.h"
#include "d2game.h"
#include "d2gfx.h"
#include "d2lang.h"
#include "d2launch.h"
#include "d2net.h"
#include "d2Win.h"
#include "fog.h"
#include "storm.h"

#include "LibUtil.h"


enum FIXTYPE {FT_NON,FT_REL,FT_FIX};

//===============================
struct FIXUP {
	DWORD offset;
	DWORD newValue;
	FIXTYPE fixType;
};
struct SAVEFIX {
	DWORD value;
	DWORD protect;
};


extern D2MODDATA DWORD D2ClientBase,D2ClientDelta;
extern D2MODDATA DWORD D2CommonBase,D2CommonDelta;
extern D2MODDATA DWORD D2GfxBase,D2GfxDelta;
extern D2MODDATA DWORD D2GameBase,D2GameDelta;
extern D2MODDATA DWORD D2WinBase,D2WinDelta;
extern D2MODDATA DWORD D2NetBase,D2NetDelta;
extern D2MODDATA DWORD D2LangBase,D2LangDelta;
extern D2MODDATA DWORD D2CmpBase,D2CmpDelta;
extern D2MODDATA DWORD D2LaunchBase,D2LaunchDelta;

BOOL STDCALL D2DllInit();
void STDCALL D2DllFree();
void FASTCALL D2ClientHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2ClientUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2CommonHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2CommonUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2GameHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2GameUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2GfxHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2GfxUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2WinHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2WinUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2NetHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2NetUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2LangHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2LangUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2CmpHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2CmpUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2LaunchHook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);
void FASTCALL D2LaunchUnhook(FIXUP *Ticks,SAVEFIX *OldTicks,int cnt);


#endif
