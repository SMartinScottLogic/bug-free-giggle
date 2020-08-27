/*=================================================================*\
 *  @file StrTable.cpp
 *  @brief Code snippet about new string tables.
 *
 *  (c) June 2003 - Allan Jensen
 *   Modified Apr 2004 - SVR
\*=================================================================*/

#include <d2mod.h>
#include <stdio.h>
#include "StrTable.hpp"
// #include <math.h>


/*
struct TBLRREC {
	TblHeader *ptTblFile;
	DWORD *ptTblMemLoc;
	DWORD *ptTblMemLoc2;
};
TBLREC Table[MAX_TABLES];
*/

#define NUM_NDX 10000
#define START_NDX 30000

// **** Global Vars
static BYTE gTablesLoaded = 0;
static TblHeader* ptTblFile[MAX_TABLES] = {NULL, NULL, NULL};
static DWORD* ptTblMemLoc[MAX_TABLES] = {NULL, NULL, NULL};
static DWORD* ptTblMemLoc2[MAX_TABLES] = {NULL, NULL, NULL};


extern int gNumTables;
extern LPSTR ptFiles[];


DWORD* STDCALL LoadCustomTbl()
{
	// **** default return value
	DWORD* retval = NULL;
	DWORD TblSize;
	WORD NumElements;
	DWORD ptTblFile_adr;
	DWORD StringStart;
	DWORD i;
	DWORD* temp_memloc;
	DWORD StringWidth;
	char buffer[255];
	char lng[6];
	char path[] = "data\\local\\lng\\%s\\%s";

	D2GetLang(lng, 0);

	gTablesLoaded=0;

	log_message("Loading tables ...");
	for(int TblCount=0;TblCount<gNumTables;TblCount++)
	{
		// **** Load our own tbl file. Change it if needed
		sprintf(buffer, path, lng, ptFiles[TblCount]);

		if((ptTblFile[gTablesLoaded] = D2LoadTblFile(buffer))!=0)
		{

			// **** Get the HashTableSize of out tbl file
			TblSize = ptTblFile[gTablesLoaded]->HashTableSizeOffset;

			// **** Allocate some memory, test if it is rally allocated and fill it with zeros
			ptTblMemLoc[gTablesLoaded] = (DWORD*)FogMemAlloc((TblSize*4), __FILE__, __LINE__, NULL);
			if(!ptTblMemLoc[gTablesLoaded])
				return retval;
			ZeroMemory(ptTblMemLoc[gTablesLoaded], (TblSize*4));

			// **** Find the first Node in the tbl file
			NumElements = ptTblFile[gTablesLoaded]->NumElementsOffset;
			ptTblFile_adr = (DWORD)ptTblFile[gTablesLoaded];
			TblNode* ptTblNode = (TblNode*)(ptTblFile_adr + (2 * NumElements + 0x15) );
	
			StringStart = 0;
	
			// **** find the added Unicode length of the strings in the tbl
			if(TblSize > 0)
			{
				TblNode* temp_node = ptTblNode;
				i = 0;
				while(i < TblSize)
				{
					StringStart += D2UnicodeWidth((temp_node->NameStringOffset + ptTblFile_adr), temp_node->NameLenOffset) + 0x02;
					temp_node = (TblNode*)&temp_node->NextTblNode;
					i++;
				}
			}

			// **** Allocate memory based on Unicode length of strings, and test if it is allocated
			ptTblMemLoc2[gTablesLoaded] = (DWORD*)FogMemAlloc((StringStart*2), __FILE__, __LINE__, NULL);
			if(!ptTblMemLoc2[gTablesLoaded])
				return retval;

			if(TblSize > 0)
			{
				TblNode* temp_node = ptTblNode;
				temp_memloc = ptTblMemLoc2[gTablesLoaded];
				i = 0;
				StringWidth = 0;
				while(i < TblSize)
				{
					// **** put the address of temp_memloc into allocated memory
					*(ptTblMemLoc[gTablesLoaded] + i) = (DWORD)temp_memloc;

					// **** Get the Unicode length of the string we need to copy to our memory
					StringWidth = D2UnicodeWidth((temp_node->NameStringOffset + ptTblFile_adr), temp_node->NameLenOffset) + 0x02;

					// **** Converte it to Unicode
					D2ToUnicode(temp_memloc, (ptTblFile_adr + temp_node->NameStringOffset), StringWidth);

					i++;

					// **** Find the next string
					temp_node = (TblNode*)&temp_node->NextTblNode;

					// **** Move our mempointer
					temp_memloc += (StringWidth/2);
				}
			}
			retval = (DWORD*)temp_memloc;
			log_message("%s loaded", buffer);
			gTablesLoaded++;
		}
	}
	return retval;
}

// **** These functions should be easy to understand
LPWSTR FASTCALL GetStringByIndex(WORD dwIndexNum)
{
	if(dwIndexNum < START_NDX) return (LPWSTR)-1;

	int n=(dwIndexNum-START_NDX)/NUM_NDX;
	int ndx=dwIndexNum%NUM_NDX;

	if(n<gTablesLoaded)
		if(ptTblFile[n])
			return D2GetStrFromIndex(ptTblFile[n], ptTblMemLoc[n], ndx);

	return (LPWSTR)-1;
}

DWORD STDCALL GetStringByRef(LPSTR String, LPWSTR RetString)
{
	DWORD retval;
	for(int i=0;i<gTablesLoaded;i++)
	{
		if(ptTblFile[i])
		{
			retval= D2GetString(ptTblFile[i], ptTblMemLoc[i], String, RetString)&0xFFFF;
			if(retval != 0xFFFF)
				return (retval + START_NDX + i * NUM_NDX);
		}
	}
	return NULL;
}

void STDCALL UnLoadCustomTbl()
{
	log_message("Unloading tables ...");

	for(int i=0;i<gTablesLoaded;i++)
	{
		if(ptTblFile[i] != NULL)
		{
			ptTblFile[i] = NULL;
			FogMemDeAlloc(ptTblMemLoc[i], __FILE__, __LINE__, NULL);
			ptTblMemLoc[i] = NULL;

			FogMemDeAlloc(ptTblMemLoc2[i], __FILE__, __LINE__, NULL);
			ptTblMemLoc2[i] = NULL;
			log_message("%s unloaded", ptFiles[i]);
		}
	}
	gTablesLoaded=0;
}
