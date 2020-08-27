/*==============================================*/
/** @file d2functions.hpp 
    @brief Exported Diablo II DLL functions.

    This file implements some common and useful
    function related to some Diablo II mechanisms.

 */ 
/*==============================================*/

#ifndef __D2FUNCTIONS_HPP__INCLUDED__
#define __D2FUNCTIONS_HPP__INCLUDED__

//#include "common.hpp"
#include "d2struct.hpp"
//#include "d2wrapper.hpp"

/*==============================================*/
/** 
 *  @brief stdcall function pointer declaration.
 *
 *  Declares the type for a STDCALL function pointer
 *  called N with arguments list A adn returning R.
 *
 */
/*==============================================*/

#define STDCALL_FUNCTION( R, N, A )  typedef R (_stdcall *N) A

/*==============================================*/
/**
 *  @brief fastcall function pointer declaration.
 *
 *  Declares the type for a FASTCALL function pointer
 *  called N with arguments list A adn returning R.
 *
 */
/*==============================================*/

#define FASTCALL_FUNCTION( R, N, A ) typedef R (_fastcall *N) A

/*==============================================*/
/**
 *  @brief cdecl function pointer declaration.
 *
 *  Declares the type for a CDECL function pointer
 *  called N with arguments list A adn returning R.
 *
 */
/*==============================================*/

#define CDECL_FUNCTION( R, N, A ) typedef R (_cdecl *N) A

/*=================================================================*/
/* D2 Functions prototypes CDECL                                   */
/*=================================================================*/

CDECL_FUNCTION(void,			D2Fog2727,			(const char* ptMessage, const char* ptLocation, DWORD line));

CDECL_FUNCTION(void,			D2L_SPrintF,		(DWORD wChar_Size, LPWSTR ptTo, LPCWSTR ptFrom, ...));

/*=================================================================*/
/* D2 Functions prototypes STDCALL                                 */
/*=================================================================*/

//D2Common
STDCALL_FUNCTION(DWORD,			D2Common2762,		(Room* ptRoom));
STDCALL_FUNCTION(Unit*,			D2Common2811,		(Inventory* ptInventory, DWORD BodyLoc));
STDCALL_FUNCTION(Unit*,			D2Common2825,		(Inventory* ptInventory));
STDCALL_FUNCTION(Unit*,			D2Common2840,		(Unit* ptItem));
STDCALL_FUNCTION(Unit*,			D2Common2841,		(Unit* ptItem));
STDCALL_FUNCTION(int,			D2Common2843,		(Unit* ptItem));
STDCALL_FUNCTION(Skills*,		D2Common2851,		(Unit* ptPlayer));
STDCALL_FUNCTION(Skills*,		D2Common2853,		(Unit* ptPlayer));
STDCALL_FUNCTION(void,			D2Common285C,		(Unit* ptUnit, void* ptOffsetStruct));
STDCALL_FUNCTION(Room*,			D2Common2866,		(Unit* ptUnit));
STDCALL_FUNCTION(void,			D2Common286C,		(Unit* ptItem, DWORD Mode));
STDCALL_FUNCTION(void,			D2Common2915,		(Unit* ptUnit, DWORD StatID, int Value, void* TableIndex));
STDCALL_FUNCTION(void,			D2Common2916,		(Unit* ptUnit, DWORD StatID, int Value, void* TableIndex));
STDCALL_FUNCTION(int,			D2Common2917,		(Unit* ptUnit, DWORD StatID, void* TableIndex));
STDCALL_FUNCTION(int,			D2Common2919,		(Unit* ptUnit, DWORD StatID, void* TableIndex));
STDCALL_FUNCTION(void,			D2Common294F,		());
STDCALL_FUNCTION(void*,			D2Common2952,		(WORD unused, const char* ptFilename, BINField* ptFields, DWORD* ptRecordCount, WORD recordLength));
STDCALL_FUNCTION(void,			D2Common2953,		(void* ptBinFile));
STDCALL_FUNCTION(D2ItemsTXT*,	D2Common2968,		(DWORD ItemNbr));
STDCALL_FUNCTION(D2ItemsTXT*,	D2Common2969,		(DWORD ItemCode, int* ptRetNum));
STDCALL_FUNCTION(D2BooksTXT*,	D2Common297A,		(DWORD BookNbr));
STDCALL_FUNCTION(D2RuneStruct*,	D2Common297B,		());
STDCALL_FUNCTION(LPVOID,		D2Common29A3,		(DWORD TCIndex, DWORD clvl));
STDCALL_FUNCTION(DWORD,			D2Common29C7,		(Unit* ptItem));
STDCALL_FUNCTION(WORD,			D2Common29CD,		(Unit* ptItem, DWORD SuffixNbr));
STDCALL_FUNCTION(DWORD,			D2Common29D3,		(Unit* ptItem, DWORD dwFlag, LPCSTR file, DWORD line));
STDCALL_FUNCTION(void,			D2Common29D4,		(Unit* ptItem, DWORD dwFlag, DWORD dwAction));
STDCALL_FUNCTION(DWORD,			D2Common29D5,		(Unit* ptItem));
STDCALL_FUNCTION(BYTE,			D2Common29DF,		(Unit* ptItem));
STDCALL_FUNCTION(void,			D2Common29E0,		(Unit* ptItem, DWORD dwPage));
STDCALL_FUNCTION(BOOL,			D2Common29EB,		(Unit* ptItem, DWORD dwTypeID));
STDCALL_FUNCTION(DWORD,			D2Common29FA,		(Unit* ptItem));
STDCALL_FUNCTION(DWORD,			D2Common29FF,		(Unit* ptItem));
STDCALL_FUNCTION(BOOL,			D2Common2A0D,		(Unit* ptItem));
STDCALL_FUNCTION(int,			D2Common2A18,		(Unit* ptPlayer));
STDCALL_FUNCTION(int,			D2Common2A34,		(Unit* ptItem));
STDCALL_FUNCTION(DWORD,			D2Common2A40,		(Unit* ptItem));
STDCALL_FUNCTION(DWORD,			D2Common2A45,		(Unit* ptItem));
STDCALL_FUNCTION(void,			D2Common2A66,		(Unit* ptItem, DWORD dwPage));
STDCALL_FUNCTION(void,			D2Common2A71,		(Unit* ptItem));
STDCALL_FUNCTION(DWORD,			D2Common2A74,		(Unit* ptItem, ItemMod* ptProperty, int one));
STDCALL_FUNCTION(DWORD,			D2Common2A80,		(Unit* ptItem));
STDCALL_FUNCTION(int,			D2Common2AEA,		(DWORD SkillID));
STDCALL_FUNCTION(int,			D2Common2AEB,		(Unit* ptUnit, DWORD SkillID));
STDCALL_FUNCTION(int,			D2Common2AEC,		(Unit* ptUnit, DWORD SkillID));
STDCALL_FUNCTION(int,			D2Common2AED,		(Unit* ptUnit, DWORD SkillID));
STDCALL_FUNCTION(void,			D2Common2AC8,		(Unit* ptPlayer, DWORD SkillID));
STDCALL_FUNCTION(DWORD,			D2Common2AD8,		(Unit* ptPlayer, Skills* ptSkill, DWORD mode));
STDCALL_FUNCTION(BOOL,			D2Common2B63,		(void* ptQuest, DWORD QuestID, DWORD QuestState));

//D2Client
STDCALL_FUNCTION(void,			D2Client6FAABF30,	());
STDCALL_FUNCTION(void,			D2Client6FAF65C0,	());
STDCALL_FUNCTION(Unit*,			D2Client6FB283D0,	());

//Fog
STDCALL_FUNCTION(void,			D2Fog272D,			(LPCSTR ptszMsg, ...));
STDCALL_FUNCTION(void*,			D2Fog27E3,			(LPCSTR ptszFile, DWORD dwLine));
STDCALL_FUNCTION(DWORD,			D2Fog27E9,			(void* ptBin, LPCSTR ptText, DWORD column));

//D2Lang
STDCALL_FUNCTION(WORD,			D2Lang10013,		(LPSTR ptStringRef, LPWSTR* ptReturnStr));
STDCALL_FUNCTION(void,			D2Lang10006,		(LPSTR ptLang, DWORD Zero));

//D2Gfx
STDCALL_FUNCTION(HWND,			D2Gfx10027,			());
STDCALL_FUNCTION(void,          D2Gfx10072,         (void* ImageStructure, DWORD Xpos, DWORD Ypos, DWORD unknown, DWORD DrawWindowType, DWORD unknown2)); 

//D2Net
STDCALL_FUNCTION(DWORD,			D2Net2715,			(DWORD IndexNbr, void* ptData, DWORD dwSize));


/*=================================================================*/
/* D2 Functions prototypes FASTCALL                                */
/*=================================================================*/

//D2Common
FASTCALL_FUNCTION(Skills*,		D2Common2AC5,		(Unit* ptPlayer, DWORD SkillID, DWORD un1_n1));
FASTCALL_FUNCTION(Skills*,		D2Common2AC6,		(Unit* ptPlayer, DWORD SkillID));
FASTCALL_FUNCTION(DWORD,		D2Common6FD52410,	(BYTE* ptBinLine, LPCSTR ptLine, DWORD Offset, DWORD unknown));
FASTCALL_FUNCTION(DWORD,		D2Common6FD52910,	(BYTE* ptBinLine, LPCSTR ptLine, DWORD Offset, DWORD unknown));

//D2Game
FASTCALL_FUNCTION(DWORD,		D2Game6FC3C710,		(Client* ptClient, void* pData, DWORD size));
FASTCALL_FUNCTION(void,			D2Game6FC3E9D0,		(Client* ptClient, Unit* ptPlayer, Unit* ptItem, DWORD dwCmd));
FASTCALL_FUNCTION(void,			D2Game6FC3EC20,		(Client* ptClient, Unit* ptItem, DWORD unknown1_1, DWORD StatID, DWORD Value, DWORD unknown2_0));
FASTCALL_FUNCTION(void,			D2Game6FC3EDC0,		(Client* ptClient, Unit* ptItem, DWORD dwSpellIcon, DWORD unknown1_0, DWORD unknown2_1, DWORD dwSkillId));
FASTCALL_FUNCTION(DWORD,		D2Game6FC44410,		(char* lpszErrFile, DWORD ErrLine, D2Game* ptGame, Unit* ptPlayer, DWORD ItemUniqueID, DWORD XOffset, DWORD YOffset, DWORD Unknown1_1, DWORD Unknown2_1, DWORD Unknown3_0));
FASTCALL_FUNCTION(void,			D2Game6FC471F0,		(D2Game* ptGame, Unit* ptPlayer, Unit* ptItem, DWORD zero));
FASTCALL_FUNCTION(void,			D2Game6FC47C90,		(Unit* ptPlayer, DWORD SkillID));
FASTCALL_FUNCTION(void,			D2Game6FC49670,		(D2Game* ptGame, Unit* ptPlayer, Unit* ptItem));
FASTCALL_FUNCTION(void,			D2Game6FC4BD50,		(D2Game* ptGame, Unit* ptPlayer, Unit* ptItem));
FASTCALL_FUNCTION(void,			D2Game6FC4FEC0,		(D2Game* ptGame, Unit* ptUnit, DWORD dwQuality, void* ptOffsets, DWORD un1_0, DWORD un2_neg, DWORD un3_0));
FASTCALL_FUNCTION(Unit*,		D2Game6FC51070,		(D2Game* ptGame, Unit* ptItem, DWORD unknown1_0, DWORD unknown2_1));
FASTCALL_FUNCTION(void,			D2Game6FC51360,		(D2Game* ptGame, Unit* ptChar, Unit* ptNPC, void* ptTC, DWORD z5, DWORD ilvl, DWORD z1, DWORD z2, DWORD z3, DWORD z4));
FASTCALL_FUNCTION(DWORD,		D2Game6FC6AD10,		(D2Game* ptGame, Unit* ptMonster));
FASTCALL_FUNCTION(WORD,			D2Game6FC8FE40,		(D2Game* ptGame, DWORD Lvl, WORD ItemType));
FASTCALL_FUNCTION(BOOL,			D2Game6FC937A0,		(D2Game* ptGame, Unit* ptPlayer));
FASTCALL_FUNCTION(void,			D2Game6FC95DF0,		(void* ptGame, Unit* ptChar, DWORD itemCode, DWORD ilvl, DWORD quality, DWORD one));
FASTCALL_FUNCTION(void,			D2Game6FCBAEE0,		(D2Game* ptGame, Unit* ptItem));
FASTCALL_FUNCTION(Unit*,		D2Game6FCBBB00,		(D2Game* ptGame, DWORD UnitType, DWORD UniqueID));
FASTCALL_FUNCTION(Client*,		D2Game6FCBC2E0,		(Unit* ptPlayer, char* lpszErrFile, DWORD ErrLine));
FASTCALL_FUNCTION(void,			D2Game6FCBC480,		(Unit* ptPlayer_1, DWORD SoundNbr, Unit* ptPlayer_2));
FASTCALL_FUNCTION(BOOL,			D2Game6FD03E40,		(D2Game* ptGame, Unit* ptPlayer, Unit* ptItem, Unit* ptTargetItem, DWORD X_Offset, DWORD Y_Offset));
FASTCALL_FUNCTION(DWORD,		D2Game6FD12950,		(D2Game* ptGame, Unit* ptPlayer, DWORD dwSkillID, DWORD dwSkillLvl, DWORD Unknown1_1));
FASTCALL_FUNCTION(DWORD,		D2Game6FD12BA0,		(D2Game* ptGame, Unit* ptPlayer, DWORD dwSkillID, DWORD dwSkillLvl, DWORD Unknown1_1, DWORD ClassSkill, DWORD Unknown3_0));
FASTCALL_FUNCTION(void,			D2Game6FD13260,		(D2Game* ptGame, Unit* ptPlayer, DWORD dwSkillID, DWORD dwSkillLvl, DWORD Unknown1_0));

//D2Client
FASTCALL_FUNCTION(void,			D2Client6FAAD990,	(BYTE MsgNum, WORD Msg));
FASTCALL_FUNCTION(void,			D2Client6FAADA20,	(BYTE MsgNum, DWORD Msg));
FASTCALL_FUNCTION(void*,		D2Client6FABC6B0,	(Unit* ptCltPlayer, DWORD SkillID, DWORD SkillLvl, DWORD unknown2_0));
FASTCALL_FUNCTION(Menu*,		D2Client6FAD6BE0,	(DWORD X, DWORD Y, DWORD func1, DWORD func2, DWORD un1_0, DWORD un2_0, DWORD AutoSize, DWORD Width, DWORD Heigth, DWORD un6_0, DWORD un7_1));
FASTCALL_FUNCTION(void,			D2Client6FAD6EB0,	(Menu* hMenu));
FASTCALL_FUNCTION(void,			D2Client6FAD6DC0,	());
FASTCALL_FUNCTION(void,			D2Client6FAD7150,	(Menu* hMenu, DWORD un1_1));
FASTCALL_FUNCTION(void*,		D2Client6FAD7180,	(Menu* hMenu, LPCWSTR ptMenuString, DWORD dwPixel, DWORD dwUnknown, DWORD dwColor, DWORD dwFontType, DWORD dwFunc, DWORD dwSelectable));
FASTCALL_FUNCTION(void,			D2Client6FB1CBD0,	(DWORD func1, DWORD func2));
FASTCALL_FUNCTION(void,			D2Client6FB1CC20,	(Unit* ptUnit, DWORD ptText, int zero));
FASTCALL_FUNCTION(DWORD,		D2Client6FB23260,	(DWORD UImsg, DWORD un1_0, DWORD un2_0));
FASTCALL_FUNCTION(Unit*,		D2Client6FB269F0,	(DWORD UnitID, DWORD nUnitType));
FASTCALL_FUNCTION(Unit*,		D2Client6FB26A60,	(DWORD UnitID, DWORD nUnitType));
FASTCALL_FUNCTION(LPWSTR,		D2Client6FB297F0,	(Unit* ptNpc));
FASTCALL_FUNCTION(void,			D2Client6FB55820,	(DWORD un1_1, DWORD un2_0, DWORD un3_0, DWORD un4_0, DWORD un5_0));

//Fog
FASTCALL_FUNCTION(void*,		D2Fog273A,			(DWORD dwMemSize, LPCSTR lpszErrFile, DWORD ErrLine, DWORD null));
FASTCALL_FUNCTION(void,			D2Fog273B,			(void* ptMemLoc, LPCSTR lpszErrFile, DWORD ErrLine, DWORD null));
FASTCALL_FUNCTION(void*,		D2Fog273C,			(DWORD MemPool, DWORD MemSize, LPCSTR lpszErrFile, DWORD ErrLine, DWORD null));
FASTCALL_FUNCTION(void,			D2Fog273D,			(DWORD MemPool, void* ptMemLoc, LPCSTR lpszErrFile, DWORD ErrLine, DWORD null));
FASTCALL_FUNCTION(void,			D2Fog2783,			(LPSTR ptPath, DWORD dwFlag));

//D2Lang
FASTCALL_FUNCTION(LPWSTR,		D2Lang10003,		(LPCSTR ptString));
FASTCALL_FUNCTION(LPWSTR,		D2Lang10004,		(WORD dwIndexNum));
FASTCALL_FUNCTION(DWORD,		D2L_UnicodeWidth,	(DWORD MemLoc, WORD Size));
FASTCALL_FUNCTION(DWORD,		D2L_ToUnicode,		(void* ptToLoc, DWORD ptFromLoc, DWORD Size));
FASTCALL_FUNCTION(LPWSTR,		D2L_StrCat,			(LPWSTR ptToString, LPCWSTR ptFromString));
FASTCALL_FUNCTION(void,			D2L_StrCpy,			(LPWSTR ptTo, LPCWSTR ptFrom));
FASTCALL_FUNCTION(void,			D2L_Win2Unicode,	(LPWSTR ptTo, LPCSTR ptFrom, DWORD wCharSize));
FASTCALL_FUNCTION(LPWSTR,		D2Lang6FC12E60,		(void* ptFile, void* ptMemLoc, DWORD dwIndexNum ));
FASTCALL_FUNCTION(TblHeader*,	D2Lang6FC13640,		(LPCSTR lpszFileName));
FASTCALL_FUNCTION(WORD,			D2Lang6FC13A90,		(void* ptFile, void* ptMemLoc, LPSTR String, LPWSTR RetString));

/*=================================================================*/
/* D2 Functions pointers		                                   */
/*=================================================================*/
/*
//D2Common
static D2Common2762		D2CheckIfTown			= (D2Common2762)		(0x4D0E0 + CommonOffset);	// 1.10
static D2Common2811		D2GetItemInBodyLoc		= (D2Common2811)		(0x4FAE0 + CommonOffset);	// 1.10
static D2Common2825		D2GetInventoryItem		= (D2Common2825)		(0x4E7A0 + CommonOffset);	// 1.10
static D2Common2840		D2GetNextInventoryItem	= (D2Common2840)		(0x52080 + CommonOffset);	// 1.10
static D2Common2841		D2CheckInventoryItem	= (D2Common2841)		(0x520C0 + CommonOffset);	// 1.10
static D2Common2843		D2GetNodePage			= (D2Common2843)		(0x52100 + CommonOffset);	// 1.10
static D2Common2851		D2GetLeftSkill			= (D2Common2851)		(0x7D5B0 + CommonOffset);	// 1.10
static D2Common2853		D2GetCurrentSkill		= (D2Common2853)		(0x7D670 + CommonOffset);	// 1.10
static D2Common285C		D2GetMapOffsetsFromUnit	= (D2Common285C)		(0x7DD10 + CommonOffset);	// 1.10
static D2Common2866		D2GetRoomFromUnit		= (D2Common2866)		(0x7E270 + CommonOffset);	// 1.10
static D2Common286C		D2SetUnitMode			= (D2Common286C)		(0x7EA60 + CommonOffset);	// 1.10
static D2Common2915		D2SetUnitStat			= (D2Common2915)		(0x77AB0 + CommonOffset);	// 1.10
static D2Common2916		D2AddUnitStat			= (D2Common2916)		(0x77B00 + CommonOffset);	// 1.10
static D2Common2917		D2GetUnitStat			= (D2Common2917)		(0x77C30 + CommonOffset);	// 1.10
static D2Common2919		D2GetUnitBaseStat		= (D2Common2919)		(0x77B30 + CommonOffset);	// 1.10
static D2Common294F		D2UnloadAllBinImages	= (D2Common294F)		(0x10150 + CommonOffset);	// 1.10
static D2Common2952		D2CompileText			= (D2Common2952)		(0x0FD70 + CommonOffset);	// 1.10
static D2Common2953		D2UnloadBinImage		= (D2Common2953)		(0x10110 + CommonOffset);	// 1.10
static D2Common2968		D2GetItemTXTFromNbr		= (D2Common2968)		(0x17680 + CommonOffset);	// 1.10
static D2Common2969		D2GetItemTXTFromCode	= (D2Common2969)		(0x176D0 + CommonOffset);	// 1.10
static D2Common297A		D2GetBookPt				= (D2Common297A)		(0x1BD30 + CommonOffset);	// 1.10
static D2Common297B		D2GetRuneStruct			= (D2Common297B)		(0x1E9E0 + CommonOffset);	// 1.10
static D2Common29A3		D2GetTCFromID			= (D2Common29A3)		(0x28DF0 + CommonOffset);	// 1.10
static D2Common29C7		D2GetQuality			= (D2Common29C7)		(0x58550 + CommonOffset);	// 1.10
static D2Common29CD		D2GetSuffix				= (D2Common29CD)		(0x58650 + CommonOffset);	// 1.10
static D2Common29D3		D2TestFlags				= (D2Common29D3)		(0x58750 + CommonOffset);	// 1.10
static D2Common29D4		D2SetFlags				= (D2Common29D4)		(0x58780 + CommonOffset);	// 1.10
static D2Common29D5		D2GetFlags				= (D2Common29D5)		(0x587C0 + CommonOffset);	// 1.10
static D2Common29DF		D2GetPage				= (D2Common29DF)		(0x588E0 + CommonOffset);	// 1.10
static D2Common29E0		D2SetPage				= (D2Common29E0)		(0x58900 + CommonOffset);	// 1.10
static D2Common29EB		D2CheckItemType			= (D2Common29EB)		(0x5DCE0 + CommonOffset);	// 1.10
static D2Common29FA		D2GetItemCode			= (D2Common29FA)		(0x59370 + CommonOffset);	// 1.10
static D2Common29FF		D2GetItemType			= (D2Common29FF)		(0x595D0 + CommonOffset);	// 1.10
static D2Common2A0D		D2CheckIfTwoHanded		= (D2Common2A0D)		(0x5A700 + CommonOffset);	// 1.10
static D2Common2A18		D2GetNbrOfUdfItems		= (D2Common2A18)		(0x5FF00 + CommonOffset);	// 1.10
static D2Common2A34		D2GetSpellIcon			= (D2Common2A34)		(0x5D0F0 + CommonOffset);	// 1.10
static D2Common2A40		D2GetSockets			= (D2Common2A40)		(0x5D580 + CommonOffset);	// 1.10
static D2Common2A45		D2IsSocketFiller		= (D2Common2A45)		(0x5D9D0 + CommonOffset);	// 1.10
static D2Common2A66		D2SetOrgPage			= (D2Common2A66)		(0x58980 + CommonOffset);	// 1.10
static D2Common2A71		D2SetEtheral			= (D2Common2A71)		(0x558D0 + CommonOffset);	// 1.10
static D2Common2A74		D2SetItemMod			= (D2Common2A74)		(0x55F90 + CommonOffset);	// 1.10
static D2Common2A80		D2IsEtheral				= (D2Common2A80)		(0x60340 + CommonOffset);	// 1.10
static D2Common2AEA		D2GetSkillReq			= (D2Common2AEA)		(0x71BC0 + CommonOffset);	// 1.10
static D2Common2AEB		D2GetCurrentSkillReq	= (D2Common2AEB)		(0x71C00 + CommonOffset);	// 1.10
static D2Common2AEB		D2CheckPrevSkillEnabled	= (D2Common2AEC)		(0x71C80 + CommonOffset);	// 1.10
static D2Common2AEB		D2CheckSkillStatReq		= (D2Common2AED)		(0x71FC0 + CommonOffset);	// 1.10
static D2Common2AC5		D2GetSkill				= (D2Common2AC5)		(0x6FF40 + CommonOffset);	// 1.10
static D2Common2AC6		D2GetPtSkill			= (D2Common2AC6)		(0x6FF80 + CommonOffset);	// 1.10
static D2Common2AC8		D2AddSkill				= (D2Common2AC8)		(0x70320 + CommonOffset);	// 1.10
static D2Common2AD8		D2GetCurrentSkillLvl	= (D2Common2AD8)		(0x71700 + CommonOffset);	// 1.10
static D2Common2B63		D2GetQuestState			= (D2Common2B63)		(0x6E800 + CommonOffset);	// 1.10
static D2Common6FD52410	D2ParseCubeInput		= (D2Common6FD52410)	(0x12410 + CommonOffset);	// 1.10
static D2Common6FD52910	D2ParseCubeOutput		= (D2Common6FD52910)	(0x12910 + CommonOffset);	// 1.10

//D2Game
static D2Game6FC3C710	D2SendPacket			= (D2Game6FC3C710)		0x6FC3C710;	// 1.10
static D2Game6FC3E9D0	D2UpdateClientItem		= (D2Game6FC3E9D0)		0x6FC3E9D0; // 1.10
static D2Game6FC3EC20	D2SetClientUnitStat		= (D2Game6FC3EC20)		0x6FC3EC20; // 1.10
static D2Game6FC3EDC0	D2ChangeItemMode		= (D2Game6FC3EDC0)		0x6FC3EDC0; // 1.10
static D2Game6FC44410	D2PlaceItem				= (D2Game6FC44410)		0x6FC44410; // 1.10
static D2Game6FC471F0	D2RemoveItem			= (D2Game6FC471F0)		0x6FC471F0; // 1.10
static D2Game6FC47C90	D2UpdateSkillIcon		= (D2Game6FC47C90)		0x6FC47C90; // 1.10
static D2Game6FC49670	D2IdentifyItem			= (D2Game6FC49670)		0x6FC49670;	// 1.10
static D2Game6FC4BD50	D2ResetCharges			= (D2Game6FC4BD50)		0x6FC4BD50; // 1.10
static D2Game6FC4FEC0	D2DropAtUnit			= (D2Game6FC4FEC0)		0x6FC4FEC0;	// 1.10
static D2Game6FC51070	D2ItemDuplicate			= (D2Game6FC51070)		0x6FC51070; // 1.10
static D2Game6FC51360	D2DropTC				= (D2Game6FC51360)		0x6FC51360; // 1.10
static D2Game6FC6AD10	D2GetUniqueNbr			= (D2Game6FC6AD10)		0x6FC6AD10;	// 1.10
static D2Game6FC8FE40	D2GetRndItemFromType	= (D2Game6FC8FE40)		0x6FC8FE40; // 1.10
static D2Game6FC937A0	D2_UnknownCheck			= (D2Game6FC937A0)		0x6FC937A0;	// 1.10
static D2Game6FC95DF0	D2SpawnItem				= (D2Game6FC95DF0)		0x6FC95DF0; // 1.10
static D2Game6FCBAEE0	D2ForceSpawn			= (D2Game6FCBAEE0)		0x6FCBAEE0;	// 1.10
static D2Game6FCBBB00	D2GetServerUnit			= (D2Game6FCBBB00)		0x6FCBBB00;	// 1.10
static D2Game6FCBC2E0	D2GetClient				= (D2Game6FCBC2E0)		0x6FCBC2E0;	// 1.10
static D2Game6FCBC480	D2FireSound				= (D2Game6FCBC480)		0x6FCBC480; // 1.10
static D2Game6FD03E40	D2UseItemFunc			= (D2Game6FD03E40)		0x6FD03E40; // 1.10
static D2Game6FD12950	D2SkillFunc_1			= (D2Game6FD12950)		0x6FD12950; // 1.10
static D2Game6FD12BA0	D2SrvSkill				= (D2Game6FD12BA0)		0x6FD12BA0; // 1.10
static D2Game6FD13260	D2SkillFunc_2			= (D2Game6FD13260)		0x6FD13260; // 1.10

//D2Client
static D2Client6FAAD990 D2SendSrvMsg_3			= (D2Client6FAAD990)	0x6FAAd990;	// 1.10
static D2Client6FAADA20 D2SendSrvMsg_5			= (D2Client6FAADA20)	0x6FAADA20;	// 1.10
static D2Client6FAABF30 D2MenuInit				= (D2Client6FAABF30)	0x6FAABF30; // 1.10
static D2Client6FABC6B0 D2CltSkill				= (D2Client6FABC6B0)	0x6FABC6B0; // 1.10
static D2Client6FAD6BE0	D2CreateMenu			= (D2Client6FAD6BE0)	0x6FAD6BE0; // 1.10
static D2Client6FAD6EB0 D2Menu					= (D2Client6FAD6EB0)	0x6FAD6EB0; // 1.10
static D2Client6FAD7150 D2ShowMenu				= (D2Client6FAD7150)	0x6FAD7150; // 1.10
static D2Client6FAD7180 D2AddNpcMenuItem		= (D2Client6FAD7180)	0x6FAD7180; // 1.10
static D2Client6FAF65C0 D2MainNPCMenu			= (D2Client6FAF65C0)	0x6FAF65C0; // 1.10
static D2Client6FAD6DC0 D2RemoveMenu			= (D2Client6FAD6DC0)	0x6FAD6DC0; // 1.10
static D2Client6FB1CBD0 D2SetScrollEndFunc		= (D2Client6FB1CBD0)	0x6FB1CBD0;	// 1.10
static D2Client6FB1CC20	D2ScrollText			= (D2Client6FB1CC20)	0x6FB1CC20;	// 1.10
static D2Client6FB23260 D2SendUImsg				= (D2Client6FB23260)	0x6FB23260; // 1.10
static D2Client6FB269F0	D2GetClientUnit_1		= (D2Client6FB269F0)	0x6FB269F0;	// 1.10
static D2Client6FB26A60	D2GetClientUnit_2		= (D2Client6FB26A60)	0x6FB26A60;	// 1.10
static D2Client6FB283D0	D2GetClientPlayer		= (D2Client6FB283D0)	0x6FB283D0; // 1.10
static D2Client6FB297F0	D2GetNpcName			= (D2Client6FB297F0)	0x6FB297F0;	// 1.10
static D2Client6FB55820 D2CloseMenu				= (D2Client6FB55820)	0x6FB55820; // 1.10

//Fog
static D2Fog2727		FogAssert				= (D2Fog2727)			(FogOffset + 0x0ED30);	// 1.10
static D2Fog272D		FogLogMsg				= (D2Fog272D)			(FogOffset + 0x120A0);	// 1.10
static D2Fog273A		FogMemAlloc				= (D2Fog273A)			(FogOffset + 0x08F50);	// 1.10
static D2Fog273B		FogMemDeAlloc			= (D2Fog273B)			(FogOffset + 0x08F90);	// 1.10
static D2Fog273C		FogMemPoolAlloc			= (D2Fog273C)			(FogOffset + 0x08FF0);	// 1.10
static D2Fog273D		FogMemPoolDeAlloc		= (D2Fog273D)			(FogOffset + 0x09030);	// 1.10
static D2Fog2783		FogGetPath				= (D2Fog2783)			(FogOffset + 0x11900);	// 1.10
static D2Fog27E3		FogUnknown				= (D2Fog27E3)			(FogOffset + 0x0B720);	// 1.10
static D2Fog27E9		FogGetRowFromText		= (D2Fog27E9)			(FogOffset + 0x0BC20);	// 1.10

//D2Lang
static D2Lang10003		D2GetStringFromCode		= (D2Lang10003)			(LangOffset + 0x3BC0);	// 1.10
static D2Lang10004		D2GetStringFromIndex	= (D2Lang10004)			(LangOffset + 0x3740);	// 1.10
static D2Lang10006		D2GetLang				= (D2Lang10006)			(LangOffset + 0x3FB0);	// 1.10
static D2Lang10013		D2GetStringAndNum		= (D2Lang10013)			(LangOffset + 0x3960);	// 1.10
static D2L_UnicodeWidth	D2UnicodeWidth			= (D2L_UnicodeWidth)	(LangOffset + 0x29B0);	// 1.10
static D2L_ToUnicode	D2ToUnicode				= (D2L_ToUnicode)		(LangOffset + 0x2A40);	// 1.10
static D2L_StrCat		D2StrCat				= (D2L_StrCat)			(LangOffset + 0x13F0);	// 1.10
static D2L_StrCpy		D2StrCpy				= (D2L_StrCpy)			(LangOffset + 0x14A0);	// 1.10
static D2L_SPrintF		D2SPrintF				= (D2L_SPrintF)			(LangOffset + 0x1670);	// 1.10
static D2L_Win2Unicode	D2Win2Unicode			= (D2L_Win2Unicode)		(LangOffset + 0x1BD0);	// 1.10
static D2Lang6FC12E60	D2GetStrFromIndex		= (D2Lang6FC12E60)		(LangOffset + 0x2E60);	// 1.10
static D2Lang6FC13640	D2LoadTblFile			= (D2Lang6FC13640)		(LangOffset + 0x3640);	// 1.10
static D2Lang6FC13A90	D2GetString				= (D2Lang6FC13A90)		(LangOffset + 0x3A90);	// 1.10

//D2Gfx
static D2Gfx10027		D2GetWindowHandle		= (D2Gfx10027)			(GfxOffset + 0x49C0);	// 1.10
static D2Gfx10072       D2DrawImageToWindow     = (D2Gfx10072)          (GfxOffset + 0x42A0);	// 1.10 // Added by Kingpin 16/3

//D2Net
static D2Net2715		D2SendNetMessage		= (D2Net2715)			0x6FC01760;	// 1.10
*/
/*=================================================================*/
/* D2 Variable prototypes		                                   */
/*=================================================================*/

#define VARIABLE(R, N) typedef R *N

// D2Game
VARIABLE(DWORD*,		Cltn);

// D2Client
VARIABLE(DWORD,			ScrH);
VARIABLE(DWORD,			ScrW);
VARIABLE(DWORD,			BoxX);
VARIABLE(DWORD,			BoxY);
VARIABLE(DWORD,			MsgMenu);
VARIABLE(char,			CharName);
VARIABLE(DWORD,			Uk1);
VARIABLE(DWORD,			Uk2);
VARIABLE(DWORD,			NpcU);
VARIABLE(DWORD,			NpcT);
VARIABLE(DWORD,			NpcI);
VARIABLE(Menu*,			NpcM);
VARIABLE(NpcMenuData,	NpcS1);
VARIABLE(DWORD,			NpcS2);
VARIABLE(DWORD,			HireN);
VARIABLE(DWORD,			HireR);
VARIABLE(void*,			QuestP);
VARIABLE(DWORD,			SellB);
VARIABLE(DWORD,			ObjUID);

// D2Common
VARIABLE(D2SkillsTXT*,		SkillPt);
VARIABLE(DWORD,				SkillNum);
VARIABLE(DWORD,				MonS);
VARIABLE(DWORD,				SupU);
VARIABLE(D2SkillDescTXT*,	SkillDescPt);

// Fog
VARIABLE(DWORD,			Fog2813);

/*=================================================================*/
/* D2 Variable pointers			                                   */
/*=================================================================*/
/*
// D2Game
static Cltn			Clients				= (Cltn)		0x6FD43FB8;				//1.10

// D2Client
static ScrH			ScreenHeight		= (ScrH)		0x6FB740F0;					//1.10
static ScrW			ScreenWidth			= (ScrW)		0x6FB740EC;					//1.10
static NpcS1		NpcMenuStruct		= (NpcS1)		0x6FB7BD70;					//1.10
static NpcS2		NpcDataNbr			= (NpcS2)		0x6FB7C4C0;					//1.10
static BoxX			TextBoxX			= (BoxX)		0x6FBB9F54;					//1.10
static BoxY			TextBoxY			= (BoxY)		0x6FB8D220;					//1.10
static MsgMenu		MessageMenu			= (MsgMenu)		0x6FBBA6C8;					//1.10
static CharName		CharacterName		= (CharName)	0x6FBA7810;					//1.10
static Uk1			Unknown1			= (Uk1)			0x6FBC1AF4;					//1.10
static Uk1			Unknown2			= (Uk2)			0x6FBC1AFC;					//1.10
static NpcU			ActiveNpcUniqueID	= (NpcU)		0x6FBB5CF5;					//1.10
static NpcT			ActiveNpcType		= (NpcT)		0x6FBB5CF9;					//1.10
static NpcI			ActiveNpcID			= (NpcI)		0x6FBB5CFD;					//1.10
static NpcM			ActiveNpcMenu		= (NpcM)		0x6FBB5D3B;					//1.10
static HireN		HirelingName		= (HireN)		0x6FB7A5BC;					//1.10
static HireR		HireResurrectCost	= (HireR)		0x6FBB5D9C;					//1.10
static QuestP		QuestData			= (QuestP)		0x6FBB5D13;					//1.10
static SellB		VendorButtons		= (SellB)		0x6FB795B0;					//1.10
static ObjUID		ActiveContainerUID	= (ObjUID)		0x6FBBA984;					//1.10

// D2Common
static SkillPt		SkillPointer		= (SkillPt)		(0xAA1A0 + CommonOffset);	//1.10
static SkillNum		NumberOfSkills		= (SkillNum)	(0xAA1A8 + CommonOffset);	//1.10
static MonS			MonStats			= (MonS)		(0xAA084 + CommonOffset);	//1.10
static SupU			SuperUniques		= (SupU)		(0xAA0E0 + CommonOffset);	//1.10
static SkillDescPt	SkillDescPointer	= (SkillDescPt)	(0xAA194 + CommonOffset);	//1.10

static Fog2813		gdwBitMasks			= (Fog2813)		0x6FF71308;					//1.10
*/
#endif