
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MERCMOD_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MERCMOD_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef MERCMOD_EXPORTS
#define MERCMOD_API extern "C" __declspec(dllexport)
#else
#define MERCMOD_API extern "C" __declspec(dllimport)
#endif


