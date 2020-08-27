#include <string>
#include <sstream>
#include <iomanip>

#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include "HavMod.h"	// add you header here

typedef DWORD (__fastcall *DispatchFunc)(LPGAME,LPPLAYER,char *,DWORD);
typedef struct {
	DispatchFunc func;
	DWORD unk;
}DFTable;

std::string make_hex_string(char *data, DWORD len, bool use_uppercase = true, bool insert_spaces = false)
{
    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    if (use_uppercase)
        ss << std::uppercase;
	for(DWORD i=0; i<len; i++) {
		if (insert_spaces && i > 0) {
			ss << " ";
		}
		ss << std::setw(2) << static_cast<unsigned int>(data[i]);
	}
    return ss.str();
}

DFTable *DispatchFuncTable=(DFTable *)(D2GameBase + 0xf8fa0);
DWORD __fastcall OverrideDispatcher(LPGAME ptGame, LPPLAYER ptPlayer, DWORD method, char *msg, DWORD len)
{
	D2LogMsg("%s {method: %02lx, len: %02lx, msg: \"%s\"}", "OverrideDispatcher", method, len, make_hex_string(msg, len, true, true).c_str());
	DispatchFunc dispatch=DispatchFuncTable[method].func;
	DWORD r = dispatch(ptGame, ptPlayer, msg, len);
	updateWeight(ptPlayer);
	return r;
}

