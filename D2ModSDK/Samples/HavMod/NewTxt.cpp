#include <AggressiveOptimize.h>
#include <d2mod.h>	// main include for all import definitions/library functions
#include "HavMod.h"	// add you header here

BOOL NewTXT_bound = FALSE;

typedef struct tagF {
	TableLoadFunc load;
	TableUnloadFunc unload;
	char *name;
	struct tagF *next;
}Func;
typedef Func * LPFUNC;
LPFUNC TFuncs = NULL;

typedef VOID (__fastcall *TableAddFunc)(LPSTR,TableLoadFunc,TableUnloadFunc);
HAVMOD_API AddTable(LPSTR name, TableLoadFunc in, TableUnloadFunc out)
{
	DWORD mem = *(DWORD *)(D2CommonBase+0x10798);
	DWORD mem2= *(DWORD *)(D2CommonBase+0x107a8);
	D2LogMsg("Bound(B): %s", NewTXT_bound ? "TRUE\0" : "FALSE\0");
	D2LogMsg("Mem address: %08x",mem);
	D2LogMsg("NewTxt Load address: %08x",mem2);
	D2LogMsg("Patched: %s",(mem==0x0001e884)?"FALSE":"TRUE");
	D2LogMsg("New txt:%s, added",name);
	
	LPFUNC temp = new Func;
	temp->name=new char[lstrlen(name)+1];
	lstrcpy(temp->name,name);
	temp->next = TFuncs;
	temp->load = in;
	temp->unload=out;
	TFuncs = temp;
	
	if(NewTXT_bound==FALSE && mem!=0x0001e884 && mem2!=0x90909090)
	{
		LPFUNC ctemp = TFuncs;
		while(ctemp)
		{
			D2LogMsg("Transfering new Txt: %s\n",ctemp->name);
			TableAddFunc tableAddFunc=(TableAddFunc)mem2;
			tableAddFunc(ctemp->name,ctemp->load,ctemp->unload);
			TFuncs = ctemp->next;
			delete ctemp;
			ctemp = TFuncs;
		}
	}
}

HAVMOD_API NewTables(DWORD unk)
{
	LPFUNC temp = TFuncs;
	while(temp!=NULL)
	{
		D2LogMsg("New txt:%s, loaded (%08x: %d)\n",temp->name,temp->load,IsBadCodePtr((FARPROC)temp->load));
		temp->load(unk);
		temp = temp->next;
	}
}

HAVMOD_API RemoveTables()
{
	LPFUNC temp = TFuncs;
	while(temp!=NULL)
	{
		temp->unload();
		temp = temp->next;
	}
}

HAVMOD_API FreeNewTXT() {
	LPFUNC temp = TFuncs;
	while(TFuncs!=NULL)
	{
		temp = TFuncs->next;
		delete TFuncs;
		TFuncs = temp;
	}
}