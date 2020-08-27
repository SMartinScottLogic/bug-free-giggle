#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include "HavMod.h"	// add you header here

typedef struct {
	char *name;
	DWORD type;
	DWORD len;
	DWORD offset;
	DWORD lookup;
}TableEntry;
#define LPTABLE TableEntry *

enum EntryType {Null=0,String=1,Dword,Word,SByte,UByte=6,Code=9,LCode1=10,LCode2=11,LCode3=13,LongCode=16,LCode4=17};

typedef struct tagD2TXTLinkNodeStrc {
	char szName[20];
	DWORD nNode;
	struct tagD2TXTLinkNodeStrc* left;
	struct tagD2TXTLinkNodeStrc* right;
}D2TXTLinkNodeStrc;

typedef struct {
	DWORD numEntries;
	DWORD unk1;
	DWORD unk2;
	D2TXTLinkNodeStrc* pLinkNodes;
}D2TXTLinkageStrc;

D2TXTLinkageStrc** itemStatLinkage = (D2TXTLinkageStrc**)(D2CommonBase + 0xAA1D8);
D2TXTLinkageStrc** itemTypeLinkage = (D2TXTLinkageStrc**)(D2CommonBase + 0xAA1FC);

#pragma pack(1)
typedef struct
{
	WORD type;
	DWORD weight;
}WeightTXT;

FUNC(LPUNIT,PASCAL, D2GetFirstInventoryItem, (Inventory*), (DWORD)(&D2Common_10277));
FUNC(LPUNIT,PASCAL, D2GetNextItem, (LPUNIT), (DWORD)(&D2Common_10304));
FUNC(BYTE, STDCALL, D2GetItemPage, (LPUNIT),(DWORD)&D2Common_10719);
FUNC(DWORD, PASCAL, DATATABLES_GetLinkIndex, (D2TXTLinkageStrc *, LPSTR, BOOL), (DWORD)&Fog_10217);

DWORD numWeights=0;
WeightTXT *Weights = NULL;

VOID PASCAL LoadWeight(DWORD unk)
{
	TableEntry table[3];
	int n=0;
	table[n].name="type";
	table[n].type=0x0f;
	table[n].len=0;
	table[n].offset=0;
	table[n++].lookup=(DWORD)itemTypeLinkage;
	table[n].name="weight";
	table[n].type=Dword;
	table[n].len=0;
	table[n].offset=2;
	table[n++].lookup=0;
	table[n].name="eol";
	table[n].type=Null;
	table[n].len=0;
	table[n].offset=0;
	table[n++].lookup=0;
	Weights=(WeightTXT *)D2GetBinImage(unk,"weights",table,&numWeights, sizeof(WeightTXT));
	D2LogMsg("sizeof(WeightTXT) = %d", sizeof(WeightTXT));
}

VOID PASCAL UnloadWeight()
{
	D2UnloadBin((char *)Weights);
}

DWORD getWeight(LPUNIT ptUnit)
{
	DWORD w = 0;
	
	for(DWORD i=0;i<numWeights;i++)
	{
		if(CheckItemType(ptUnit,Weights[i].type)!=0)
		{
			DWORD tw = Weights[i].weight;
			if(tw > w) 
				w = tw;
		}
	}
	
	return w;
}

VOID updateWeight(LPPLAYER ptPlayer) {
	DWORD weight_stat = DATATABLES_GetLinkIndex(*itemStatLinkage, "weight", TRUE);
	if(weight_stat!=-1) {
		D2LogMsg("weight_stat = %ld, recalculating", weight_stat);
        // Iterate over all items, adding their weight to weight stat
        LPUNIT ptUnit=D2GetFirstInventoryItem(ptPlayer->ptInventory);
        DWORD weight = 0;
		
        while(ptUnit!=NULL)
        {
			if(ptUnit->nUnitType==4)
			{
			/*
			00:   Inventory
			03:   Cube
			04:   Stash
			FF:   BodyLoc
				*/
				char page = D2GetItemPage(ptUnit);
				char pagename[20];
				DWORD iWeight = getWeight(ptUnit);
				switch(page)
				{
				case 0:lstrcpy(pagename,"Inventory");
					weight += iWeight;
					break;
				case 3:lstrcpy(pagename,"Cube");
					break;
				case 4:lstrcpy(pagename,"Stash");
					break;
				case -1:lstrcpy(pagename,"Body");
					weight += iWeight;
					break;
				default:wsprintf(pagename,"Unknown page: %02x",page);
					break;
				}
				//D2LogMsg("Item %08x (weight = %d), in page %s",ptUnit,iWeight,pagename);
			}
			ptUnit=D2GetNextItem(ptUnit);
		}
		D2LogMsg("Total weight: %d", weight);
        D2CommonSetStat(ptPlayer, weight_stat, weight,0);
	}
}

FUNC(DWORD, PASCAL, D2Common10520, (LPUNIT, DWORD, DWORD), (DWORD)(&D2Common_10520));
#define WEIGHT_SHIFT 5
#define MAX_ENC 100
DWORD PASCAL getSpeedPostWeight(LPUNIT ptUnit, DWORD stat, DWORD zero)
{
	DWORD r = D2Common10520(ptUnit, stat, zero);		
	if(ptUnit->nUnitType==UNIT_PLAYER)
	{
		DWORD weight_stat = DATATABLES_GetLinkIndex(*itemStatLinkage, "weight", TRUE);
		if(weight_stat!=-1) {
			updateWeight(ptUnit);
			DWORD weight = D2CommonGetStat(ptUnit,weight_stat,0);
			DWORD strength = D2CommonGetStat(ptUnit,STATS_STRENGTH,0);
			DWORD diff = ((weight>>WEIGHT_SHIFT)<strength)?0:((weight>>WEIGHT_SHIFT)-strength);
			if(diff>MAX_ENC) diff = MAX_ENC;
			r-=diff;
			D2LogMsg("%s weight = %d, strength = %d, diff = %d, r = %d",ptUnit->pPlayerData,weight,strength,diff,r);
		}
	}
	
	return r;
}
