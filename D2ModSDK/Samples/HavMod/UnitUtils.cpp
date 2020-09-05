#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include "HavMod.h"	// add you header here

void logUnit(LPUNIT unit) {
	D2LogMsg("nUnitType: %d", unit->nUnitType);			//+00 Unit Type
	D2LogMsg("nUnitId: %d", unit->nUnitId);				//+04 Unit ID
    D2LogMsg("unknown: %x", unit->unknown_1);			//+08 ptGame + 1C
    D2LogMsg("nUnitUnid: %d", unit->nUnitUnid);			//+0C Unique ID
	D2LogMsg("nAnimMode: %d", unit->nAnimMode);			//+10 Current animation mode
	if(unit->nUnitType == UNIT_ITEM) {
		D2LogMsg("  pItemData->unknown_1: %x", unit->pItemData->unknown_1);
	}
/*
    union
    {
		PlayerData*     pPlayerData;
		MonsterData*    pMonsterData;
		ObjectData*     pObjectData;
		ItemData*       pItemData;
	};				                //+14 ptUnitData

    DWORD		nAct;		        //+18 Act
	DWORD		ptAct;				//+1C ptAct
	DWORD		LoSeed;				//+20
	DWORD		HiSeed;				//+24
	DWORD		StartLoSeed;		//+28
	Path*		hPath;				//+2C
	DWORD		unknown_7;			//+30
	DWORD		unknown_8;			//+34
	Path*		ptPos;				//+38 ptPos
	DWORD		unknown_10;			//+3C
	DWORD		unknown_11;			//+40
	DWORD		unknown_12;			//+44
	DWORD		unknown_13;			//+48
	DWORD		unknown_14;			//+4C
	DWORD		nAnimData;			//+50 AnimData.D2 record address for current mode
	DWORD		unknown_16;			//+54
	DWORD		unknown_17;			//+58
	StatsList*	ptStatsList;		//+5C ptStatsList
	Inventory*	ptInventory;		//+60 ptInventory
    DWORD		unknown_19;			//+64
	DWORD		unknown_20;			//+68
	DWORD		unknown_21;			//+6C
	DWORD		unknown_22;			//+70
	DWORD		unknown_23;			//+74 0 at start
	DWORD		unknown_24;			//+78
	DWORD		unknown_25;			//+7C
	D2Game*		ptGame;				//+80 ptGame
	DWORD		unknown_26;			//+84
	DWORD		unknown_27;			//+88
	DWORD		unknown_28;			//+8C
	DWORD		unknown_29;			//+90
	DWORD		unknown_30;			//+94
	DWORD		unknown_31;			//+98
	DWORD		unknown_32;			//+9C
	DWORD		unknown_33;			//+A0
	DWORD		unknown_34;			//+A4
	D2Info*		ptInfo;				//+A8 ptInfo
	DWORD		unknown_35;			//+AC
	DWORD		unknown_36;			//+B0
	DWORD		unknown_37;			//+B4
	DWORD		nDropItemCode;		//+B8
	DWORD		unknown_39;			//+BC
	DWORD		unknown_40;			//+C0
	DWORD		nFlags;				//+C4 Flags
	DWORD		nLODFlag;			//+C8 LODFlag
	DWORD		unknown_41;			//+CC
	DWORD		nClientNum;			//+D0 Client# (0B at start)
	DWORD		unknownD4[11];		//+D4 - FC unknown pad to next Unit

};
*/
}