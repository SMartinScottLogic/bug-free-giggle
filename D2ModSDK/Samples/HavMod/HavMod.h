
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MYMOD_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MYMOD_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef HAVMOD_EXPORTS
#define HAVMOD_API extern "C" __declspec(dllexport)
#else
#define HAVMOD_API extern "C" __declspec(dllimport)
#endif

// =========== START: D2 Functions ===========
// D2Common
FUNC(LPSTR, PASCAL, D2GetBinImage, (DWORD,LPSTR,LPVOID,LPDWORD,DWORD),(DWORD)&D2Common_10578);
FUNC(DWORD,PASCAL,D2UnloadBin,(LPSTR),(DWORD)&D2Common_10579);
// Fog
FUNC(VOID, __cdecl, D2LogMsg, (LPSTR, ...),(DWORD)&Fog_10029);
// ===========  END : D2 Functions ===========

VOID updateWeight(LPPLAYER ptPlayer);

typedef VOID (PASCAL *TableLoadFunc)(DWORD);
typedef VOID (PASCAL *TableUnloadFunc)();
HAVMOD_API AddTable(LPSTR name,TableLoadFunc in, TableUnloadFunc out);
