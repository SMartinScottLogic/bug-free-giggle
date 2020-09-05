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

const char *getPacketName(DWORD method) {
	switch(method) {
	case 0x03: return "PACKET_PLAYERMOVE(0x03)";
	case 0x0d: return "UNIT_DEATH(0x0d)";
	default: return NULL;
	}
}

BOOL havePacketName(DWORD method) {
	switch(method) {
	case 0x03: return TRUE;
	case 0x0d: return TRUE;
	default: return FALSE;
	}
}

FUNC(LPUNIT, __fastcall, D2GameFindUnit, (LPGAME, DWORD, DWORD), (DWORD)(D2GameBase+0x8BB00));
FUNC(LPVOID, PASCAL, D2CommonGetItemData, (DWORD), (DWORD)&D2Common_10600);
DFTable *DispatchFuncTable=(DFTable *)(D2GameBase + 0xf8fa0);
DWORD __fastcall OverrideDispatcher(LPGAME ptGame, LPPLAYER ptPlayer, DWORD method, char *msg, DWORD len)
{
	if(havePacketName(method)) {
		D2LogMsg("%s {method: %s, len: %02lx, msg: \"%s\"}", "OverrideDispatcher", getPacketName(method), len, make_hex_string(msg, len, true, true).c_str());
	} else {
		D2LogMsg("%s {method: %02lx, len: %02lx, msg: \"%s\"}", "OverrideDispatcher", method, len, make_hex_string(msg, len, true, true).c_str());
	}
	switch(method) {
	case 0x02:
	case 0x04:
	case 0x06:
	case 0x16:
	case 0x0d:
	case 0x13:
	case 0x2f:
	case 0x28:
	case 0x30:
		DWORD unitType = *(DWORD *)&msg[1];
		DWORD unitUniqId = *(DWORD *)&msg[5];
		LPUNIT ptUnit = D2GameFindUnit(ptGame, unitType, unitUniqId);
		if(ptUnit != NULL) {
			logUnit(ptUnit);
			D2LogMsg("  unit [type %x, uniqId %x] (%p)", unitType, unitUniqId, ptUnit);
		}
		else {
			D2LogMsg("  NO unit [type %x, uniqId %x]", unitType, unitUniqId);
		}
		break;
	}
	
	if(method==0x19) {
		LPUNIT ptItem = D2GameFindUnit(ptGame, UNIT_ITEM, *(DWORD *)&msg[1]);
		logUnit(ptItem);
		char *bindata = (char *)D2CommonGetItemData(ptItem->nUnitId);
		D2LogMsg("%d -> %s", ptItem->nUnitId, &bindata[32]);
		D2LogMsg("%d -> %s", ptItem->nUnitId, make_hex_string(&bindata[128], 4, true).c_str());
		D2LogMsg("%d -> %d", ptItem->nUnitId, D2GetItemPage(ptItem));
		if(D2GetItemPage(ptItem)==0) {
			return 0;
		}
	}
	DispatchFunc dispatch=DispatchFuncTable[method].func;
	DWORD r = dispatch(ptGame, ptPlayer, msg, len);
	updateWeight(ptPlayer);
	return r;
}

