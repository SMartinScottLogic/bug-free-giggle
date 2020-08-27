/*=================================================================*/
/*  @file StrTable.hpp
 *
 *
 *  (c) June 2003 - Allan Jensen.
 */
/*=================================================================*/

#ifndef __STRTABLE_H__INCLUDED
#define __STRTABLE_H__INCLUDED

#define MAX_TABLES 3

DWORD* STDCALL LoadCustomTbl();
LPWSTR FASTCALL GetStringByIndex(WORD dwIndexNum);
DWORD STDCALL GetStringByRef(LPSTR String, LPWSTR RetString);
void STDCALL UnLoadCustomTbl();

#endif
