#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include "HavMod.h"	// add you header here

FUNC(DWORD, __fastcall, D2GetStringFromID, (DWORD) ,(DWORD)&D2Lang_10004);
FUNC(DWORD, PASCAL, D2GetStringFromKey, (LPCSTR) ,(DWORD)&D2Lang_10003);
FUNC(LPUNIT, __fastcall, D2GameFindUnit, (LPGAME, DWORD, DWORD), (DWORD)(D2GameBase+0x8BB00));
FUNC(DWORD, FASTCALL, CheckforOwnedItemfromptItem, (LPUNIT,LPUNIT,DWORD), (DWORD)(D2GameBase+0x0203A0));
FUNC(DWORD, FASTCALL, CheckforOwnedItemfromItemCode, (LPGAME,LPUNIT,DWORD), (DWORD)(D2GameBase+0x020410));

LPSTR GetMonsterName(LPUNIT ptMonster) {
	if(ptMonster == NULL || ptMonster->nUnitType != UNIT_MONSTER) {
		return "An Evil Force";
	}
	BYTE *monstats = *(BYTE**)&ptMonster->pMonsterData->unknown[0];
	DWORD s = D2GetStringFromID(*(WORD *)&monstats[6]);

	char buf[1024];
	wcstombs(buf, (const wchar_t *)s, sizeof(buf));
	return buf;
}

LPSTR PASCAL getUnitName(LPUNIT ptUnit) {
	switch(ptUnit->nUnitType) {
	case UNIT_PLAYER:
		return D2GetPlayerInfo(ptUnit)->CharName;
	case UNIT_MONSTER:
		return GetMonsterName(ptUnit);
	case UNIT_OBJECT:
	case UNIT_MISSILE:
	case UNIT_ITEM:
	case UNIT_ROOMTILE:
	default:
		return "";
	}
}

bool isPlayer(LPGAME ptGame, LPUNIT ptUnit) {
	if(ptGame == NULL) {
		return false;
	}
	
	for(int i=0; i<0x80; i++) {
		LPUNIT ptPlayer = *(LPUNIT*)(((DWORD)ptGame) + ((DWORD *)(D2GameBase + 0xF9344))[0] + 4*i);
		
		while(ptPlayer!=NULL) {
			if(ptPlayer == ptUnit) {
				return true;
			}
			ptPlayer = (LPUNIT)(ptPlayer->unknownD4[4]);
		}
	}
	return false;
}

VOID __fastcall Inscribe(DWORD ecx, DWORD edx, LPUNIT item, PropLookup *propLookup,DWORD p7,DWORD p6,DWORD p5,DWORD p4,DWORD p3,DWORD p2,DWORD p1)
{
	// TODO: Future work - better soln would be for ptPlayer to be passed to method - significant rewriting required
	// BEGIN UGLY Hackery
	LPUNIT maybePtPlayer;
	__asm {
		MOV EAX, [ESP+0xC4];
		MOV maybePtPlayer, EAX;
	}
	// END UGLY Hackery
	D2LogMsg(" ecx: %x", ecx);
	D2LogMsg(" edx: %x", edx);
	D2LogMsg(" item: \"%p\"", item);
	logUnit(item);
	D2LogMsg(" p1: %x",p1);
	D2LogMsg(" p2: %x",p2);
	D2LogMsg(" p3: %x",p3);
	D2LogMsg(" p4: %x",p4);
	D2LogMsg(" p5: %x",p5);
	D2LogMsg(" p6: %x",p6);
	D2LogMsg(" p7: %x",p7);
	D2LogMsg(" propLookup: [prop: %x, param: %x, min: %x, max: %x]", propLookup->prop, propLookup->param, propLookup->min, propLookup->max);
	D2LogMsg(" maybePtPlayer: %x", maybePtPlayer);

	LPSTR name;
	if(isPlayer(item->ptGame, maybePtPlayer)) {
		name = D2GetPlayerInfo(maybePtPlayer)->CharName;
	} else {
		name = "HAVVORIC"; // When called without deduceable ptPlayer, use this recognisable placeholder.
	}
	D2SetItemFlag(item, 0x1000000, 1);
	D2InscribeItem(item, name);
}
/*Inscribe plugin for SVR's D2Mod System.
This is based on the code developed by SVR, and described in http://phrozenkeep.it-point.com/forum/viewtopic.php?t=20376.

  Then, add a property to properties.txt ...
  
	code = inscribe
	*done = 1
	func1 = 25
	*eol = 0 
	
	  Now, you have access to a new property 'inscribe'. For instance, a cube recipe can have a 
	  
		mod1 = inscribe 
		mod1 chance = 100
(param, min and max are currently unused).*/
