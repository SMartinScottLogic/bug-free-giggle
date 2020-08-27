#ifndef _D2TYPES_H
#define _D2TYPES_H


#define DLLIMPORT __declspec( dllimport )
#define DLLEXPORT __declspec(dllexport)

#ifdef _MSC_VER
	#define FASTCALL __fastcall
#else
	#define FASTCALL _msfastcall
#endif

#define STDCALL __stdcall

#define FUNC(retType,call,name,par,addr) \
typedef retType (call *T##name)par;      \
static T##name name = (T##name)addr; 

#define D2DATA DLLIMPORT
// #define D2API DLLIMPORT STDCALL
// #define D2CALL DLLIMPORT FASTCALL

#define D2API_(T) DLLIMPORT T STDCALL
#define D2CALL_(T) DLLIMPORT T FASTCALL



#ifdef D2MOD_EXPORTS
#define D2MOD_API DLLEXPORT STDCALL
#define D2MODDATA DLLEXPORT
#else
#define D2MOD_API DLLIMPORT STDCALL
#define D2MODDATA DLLIMPORT
#endif


#define NAKED void __declspec( naked )


// Include global stucture definitions here
#include <d2constants.hpp>
#include <d2struct.hpp>

#endif
