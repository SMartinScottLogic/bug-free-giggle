// BOL.cpp : Books Of Lore mod dll for use with D2Mod.dll mod system
// Author: Myhrginoc
// Converted for D2MOD by SVR 2004
//
//=======================================================================

#include <d2mod.h>	// main include for all import definitions/library functions
#include "BOL.h"	// add you header here


#define MAX_BOOKS 4096
//=======================================================================
// mod data - put needed global data here

char STR1[]="namestr";
char STR2[]="difficulty";
char STR3[]="act";
char STR4[]="area";
char STR5[]="quest";
char STR6[]="class";
char STR7[]="levelmin";
char STR8[]="levelmax";
char STR9[]="town";
char STRA[]="allsame";
char STRB[]="end";
char STRC[]="messages";
char STRD[]="C:\\Myhrginoc\\Diablo II\\D2Extra\\MessageUnit.cpp";
char STRE[]="msg.town && (filter.count > 0)";
char STRF[]="msg.adventure && (filter.count > 0)";
char STRG[]="record overflow - ptMsg[x].data not clearing on player exit";
char STRH[]="current book <= MAX_LORE_BOOKS";
char STRI[]="msg.length < MAX_MSG_LENGTH";
char STRJ[]="Level %d";
char STRK[]="Act %d";


DWORD D2Extra6F80D100;
DWORD D2Extra6F80D104;
DWORD D2Extra6F80D108;
DWORD D2Extra6F80D10C;

char D2Extra6F7E5000[][16]={
"Normal",
"Nightmare",
"Hell"
};


DWORD ClassLink=D2CommonBase+0x0A960C;
DWORD Type16Link=D2CommonBase+0x0094D0;

DWORD ptCharStats=D2CommonBase+0x0AA1CC;
DWORD ptLevel =D2CommonBase+0x0AA260;

DWORD ptUnit=D2ClientBase+0x0011C200;
DWORD ptDiff=D2ClientBase+0x0010795C;
DWORD ptInfo=D2ClientBase+0x000FA948;


DWORD D2Game0051B0=D2GameBase+0x0051B0;
DWORD D2Game066E20=D2GameBase+0x066E20;

DWORD Fog00144B7=0x6FF644B7; // BAD Sloan! should be -> FogBase+0x00144B7;



DWORD D2Lang_10033=(DWORD) Unicode::sprintf ;
DWORD D2Lang_10040=(DWORD) D2LangBase+0x014C0;	//Unicode::strlen ;
DWORD D2Lang_10062=(DWORD) D2LangBase+0x01BD0;	//Unicode::win2Unicode ;


//=======================================================================
// mod functions - put functions to call from edits here
/*
d2extra.dll (v1.10)

6F7AB000: Loads the message filter table.
6F7AB200: Clears the message read table of all registrations for a player when that player leaves the game (from d2game.6FC40375).
6F7AB250: Retrieves the client-side pointer to ptUnit—Player.
6F7AB270: Retrieves the client-side game difficulty.
6F7AB290: Retrieves client-side game info (classic/expansion, ordinary/hardcore, highest quest achieved by player).
6F7AB300: Respond to OperateFn 60 handler (from d2game.6FC78B16).
6F7AB380: Verifies message qualifications against the filter table.
6F7AB500: Display a message!
6F7AB600: Selects a town message from all qualifying messages in the filter table.
6F7AB700: Retrieves existing message, or obtains new adventuring message from all qualifying messages in the filter table.
6F7AB830: Posts a newly read message to the message read table (calls other functions for books already seen).
6F7AB920: Update message read table messages in existing read record for one player.
6F7AB970: Update message read table for AllSame messages in existing read record for affected players.

6F7ABC00: Client-side message display setup with string variable detection (from d2client.6FB6C4BD).
6F7ABD00: Interpreter for string variable ##00: Player Name.
6F7ABD20: Interpreter for string variable ##01: Player Class.
6F7ABD50: Interpreter for string variable ##02: Player Level.
6F7ABDA0: Interpreter for string variable ##03: Game Difficulty.
6F7ABDC0: Interpreter for string variable ##04: Game Act.
6F7ABE10: Interpreter for string variable ##05: Game Area.
6F7ABE50: Interpreter for string variable ##06: Player Title.

6F7AD800: Extension of D2Common.10576 (from d2common.6F6104A3[6FD504A3] - load new tables).
6F7ADA00: Extension of D2Common.10575 (from d2common.6F61079C[6FD5079C] - remove new tables).
6F7ADD00: Copy of v1.09x D2Common.10918 -- RND(X) returns random number between 0 and (X-1).
6F7ADD70: Copy of v1.09x D2Common.10919 -- RND(X1,X2) returns random number between X1 and (X2-1).  If X1=X2, returns same value.
6F7ADE00: Inner function used by x-10918 and x-10919 random functions.
6F7ADF00: Initialize the Relocation Table (called by DLL Entrypoint and D2Game.10009[6FC3B275]).
6F7ADF50: Reference the Relocation Table (verify any address in any DLL, adjust for relocations).
6F7ADFD0: DLL Entrypoint Function (used by Windows Loader only).
================================================================
*/


//Inner function used by x-10918 and x-10919 random functions
NAKED D2Extra_DE00()
{
	__asm {

		MOV EAX,DWORD PTR [ESP+8]
		MOV ECX,DWORD PTR [ESP+0x10]
		OR ECX,EAX
		MOV ECX,DWORD PTR [ESP+0xC]
		JNZ SHORT JMP1	//D2Extra.6F7ADE19
		MOV EAX,DWORD PTR [ESP+4]
		MUL ECX
		RETN 0x10
JMP1:		//6F7ADE19
		PUSH EBX
		MUL ECX
		MOV EBX,EAX
		MOV EAX,DWORD PTR [ESP+8]
		MUL DWORD PTR [ESP+0x14]
		ADD EBX,EAX
		MOV EAX,DWORD PTR [ESP+8]
		MUL ECX
		ADD EDX,EBX
		POP EBX
		RETN 0x10

	}
}


// Copy of v1.09x D2Common.10918

NAKED D2Extra_DD00()
{
	__asm {
		TEST EDX,EDX                                 ;  is upper bound zero?
		JG SHORT JMP1	//D2Extra.6F7ADD07
		XOR EAX,EAX
		RETN
JMP1:		//6F7ADD07
		PUSH EBX
		PUSH ESI
		PUSH EDI
		MOV ESI,ECX
		MOV EDI,EDX
		LEA EBX,DWORD PTR [EDI-1]
		TEST EDI,EBX
		JE SHORT JMP2	//D2Extra.6F7ADD3E
		MOV EAX,DWORD PTR [ESI]
		PUSH 0
		PUSH 0x6AC690C5
		PUSH 0
		PUSH EAX
		CALL D2Extra_DE00
		MOV ECX,DWORD PTR [ESI+4]
		XOR EBX,EBX
		ADD EAX,ECX
		ADC EDX,EBX
		MOV DWORD PTR [ESI],EAX
		MOV DWORD PTR [ESI+4],EDX
		XOR EDX,EDX
		DIV EDI
		MOV EAX,EDX
		POP EDI
		POP ESI
		POP EBX
		RETN
JMP2:		//6F7ADD3E
		MOV EDX,DWORD PTR [ESI]
		PUSH 0
		PUSH 0x6AC690C5
		PUSH 0
		PUSH EDX
		CALL D2Extra_DE00
		MOV ECX,EAX
		MOV EAX,DWORD PTR [ESI+4]
		XOR EDI,EDI
		ADD ECX,EAX
		ADC EDX,EDI
		MOV DWORD PTR [ESI],ECX
		MOV DWORD PTR [ESI+4],EDX
		MOV EAX,EBX
		AND EAX,ECX
		POP EDI
		POP ESI
		POP EBX
		RETN
	}
}

// Copy of v1.09x D2Common.10919 (slightly improved)

NAKED D2Extra_DD70()
{
	__asm {
		MOV EAX,DWORD PTR [ESP+4]                 ;  get upper bound
		CMP EAX,EDX                                  ;  compare to lower bound
		JG SHORT JMP1	//D2Extra.6F7ADD7E
		JNZ SHORT JMP2	//D2Extra.6F7ADD7D
		RETN 4                                       ;  if both bounds are same, return same number
JMP2:
		XCHG EAX,EDX                                 ;  swap bounds if lower greater than upper
JMP1:		//6F7ADD7E
		PUSH EBX
		PUSH EBP
		PUSH ESI
		PUSH EDI
		MOV EBX,EAX
		MOV ESI,ECX
		MOV EDI,EDX
		SUB EBX,EDI
		LEA EBP,DWORD PTR [EBX-1]
		TEST EBX,EBP
		JE SHORT JMP3	//D2Extra.6F7ADDBF
		MOV EAX,DWORD PTR [ESI]
		PUSH 0
		PUSH 0x6AC690C5		// what's this ??
		PUSH 0
		PUSH EAX
		CALL D2Extra_DE00
		MOV ECX,DWORD PTR [ESI+4]
		XOR EBP,EBP
		ADD EAX,ECX
		ADC EDX,EBP
		MOV DWORD PTR [ESI],EAX
		MOV DWORD PTR [ESI+4],EDX
		XOR EDX,EDX
		DIV EBX
		MOV EAX,EDX
		ADD EAX,EDI
		POP EDI
		POP ESI
		POP EBP
		POP EBX
		RETN 4
JMP3:		//6F7ADDBF
		MOV EDX,DWORD PTR [ESI]
		PUSH 0
		PUSH 0x6AC690C5
		PUSH 0
		PUSH EDX
		CALL D2Extra_DE00
		MOV ECX,EAX
		MOV EAX,DWORD PTR [ESI+4]
		XOR EBX,EBX
		ADD ECX,EAX
		MOV EAX,EBP
		MOV DWORD PTR [ESI],ECX
		ADC EDX,EBX
		AND EAX,ECX
		ADD EAX,EDI
		MOV DWORD PTR [ESI+4],EDX
		POP EDI
		POP ESI
		POP EBP
		POP EBX
		RETN 4
	}
}


// D2COMMON BASE = 6FD40000
NAKED D2Extra_B000()
{
	__asm {
		PUSHAD
		PUSHFD
		SUB ESP,0x100
		MOV ESI,ECX
		MOV EBX,4
		MOV EDX,3
		XOR ECX,ECX
		MOV DWORD PTR [ESP+0x8],offset STR1
		MOV DWORD PTR [ESP+0x0C],0x16	// ?? 
		MOV DWORD PTR [ESP+0x10],ECX
		MOV DWORD PTR [ESP+0x14],ECX
		MOV	EAX,DWORD PTR [Type16Link]                                ;  function call for type 16 data
		MOV DWORD PTR [ESP+0x18],EAX
		MOV DWORD PTR [ESP+0x1C],OFFSET STR2
		MOV DWORD PTR [ESP+0x20],EBX		//4
		MOV DWORD PTR [ESP+0x24],ECX
		MOV DWORD PTR [ESP+0x28],2
		MOV DWORD PTR [ESP+0x2C],ECX
		MOV DWORD PTR [ESP+0x30],OFFSET STR3
		MOV DWORD PTR [ESP+0x34],EBX		//4
		MOV DWORD PTR [ESP+0x38],ECX
		MOV DWORD PTR [ESP+0x3C],EDX
		MOV DWORD PTR [ESP+0x40],ECX
		MOV DWORD PTR [ESP+0x44],OFFSET STR4
		MOV DWORD PTR [ESP+0x48],EDX		//3
		MOV DWORD PTR [ESP+0x4C],ECX
		MOV DWORD PTR [ESP+0x50],EBX
		MOV DWORD PTR [ESP+0x54],ECX
		MOV DWORD PTR [ESP+0x58],OFFSET STR5
		MOV DWORD PTR [ESP+0x5C],EBX     //4
		MOV DWORD PTR [ESP+0x60],ECX
		MOV DWORD PTR [ESP+0x64],6
		MOV DWORD PTR [ESP+0x68],ECX
		MOV DWORD PTR [ESP+0x6C],OFFSET STR6
		MOV DWORD PTR [ESP+0x70],0x0D   //13
		MOV DWORD PTR [ESP+0x74],ECX
		MOV DWORD PTR [ESP+0x78],7
		MOV EAX,DWORD PTR [ClassLink]                                 ;  linking address for Class field

		MOV DWORD PTR [ESP+0x7C],EAX
		MOV DWORD PTR [ESP+0x80],OFFSET STR7
		MOV DWORD PTR [ESP+0x84],EDX		//3
		MOV DWORD PTR [ESP+0x88],ECX
		MOV DWORD PTR [ESP+0x8C],8
		MOV DWORD PTR [ESP+0x90],ECX
		MOV DWORD PTR [ESP+0x94],OFFSET STR8
		MOV DWORD PTR [ESP+0x98],EDX		//3
		MOV DWORD PTR [ESP+0x9C],ECX
		MOV DWORD PTR [ESP+0xA0],0x0A
		MOV DWORD PTR [ESP+0xA4],ECX
		MOV DWORD PTR [ESP+0xA8],OFFSET STR9
		MOV DWORD PTR [ESP+0xAC],EBX		//4
		MOV DWORD PTR [ESP+0xB0],ECX
		MOV DWORD PTR [ESP+0xB4],0x0C
		MOV DWORD PTR [ESP+0xB8],ECX
		MOV DWORD PTR [ESP+0xBC],OFFSET STRA
		MOV DWORD PTR [ESP+0xC0],EBX		//4
		MOV DWORD PTR [ESP+0xC4],ECX
		MOV DWORD PTR [ESP+0xC8],0x0D
		MOV DWORD PTR [ESP+0xCC],ECX
		MOV DWORD PTR [ESP+0xD0],OFFSET STRB
		MOV DWORD PTR [ESP+0xD4],ECX		//0
		MOV DWORD PTR [ESP+0xD8],ECX
		MOV DWORD PTR [ESP+0xDC],ECX
		MOV DWORD PTR [ESP+0xE0],ECX

		LEA EAX,DWORD PTR [ESP+0x8]
		PUSH 0x10
		PUSH offset D2Extra6F80D104						; D2Extra.6F80D104
		PUSH EAX
		PUSH offset STRC
		PUSH ESI
		CALL DWORD PTR [D2Common_10578]
		MOV DWORD PTR [D2Extra6F80D100],EAX
		ADD ESP,0x100
		PUSH 0                                      ; enough room for 4096 Books of Lore in a game
		PUSH 0x0CCC									; LINE #
		MOV EBX,0x40000								; size
		MOV EDX,OFFSET STRD							; FILENAME
		MOV ECX,EBX									; MEMSIZE TO ALLOC
		CALL DWORD PTR [Fog_10042]					; // WHERE IS THIS FREED ???
		MOV DWORD PTR [D2Extra6F80D108],EAX
		MOV EDI,EAX
		SHR EBX,2
		MOV ECX,EBX
		XOR EAX,EAX
		REP STOSD
		MOV DWORD PTR [D2Extra6F80D10C],EAX
		POPFD
		POPAD
		RETN
	}
}


NAKED D2Extra_B200()
{
	__asm {
		// FROM D2GAME CODE-EDIT
		MOV DWORD PTR [EDI+EBX*4+10F8h],0
		// ----------------------

		PUSHAD
		PUSHFD
		XOR ECX,ECX
loop1:		//6F7AB204
		MOV ESI,ECX
		SHL ESI,6
		ADD ESI,DWORD PTR [D2Extra6F80D108]             ;  get message read record
		MOV EAX,DWORD PTR [ESI]
		TEST EAX,EAX                                ;  check for valid game area
		JE SHORT jmp1	//D2Extra.6F7AB239                   ;  if 0, record should be empty
		XOR EDX,EDX
loop2:		//6F7AB217
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1
		MOV EAX,DWORD PTR [ESI+EDI+0x10]          ;  get ptUnit of Message Read posting
		CMP EAX,DWORD PTR [ESP+8]               ;  get current ptUnit (player)
		JNZ SHORT jmp2	//D2Extra.6F7AB233
		XOR EAX,EAX
		MOV DWORD PTR [ESI+EDI+0x10],EAX
		MOV WORD PTR [ESI+EDI+0x14],AX
		JMP SHORT jmp1	//D2Extra.6F7AB239
jmp2:
		INC EDX
		CMP EDX,8
		JB SHORT loop2	//D2Extra.6F7AB217
jmp1:
		INC ECX
		CMP ECX,DWORD PTR [D2Extra6F80D10C]             ;  current number of Books read
		JB SHORT loop1	//D2Extra.6F7AB204
		POPFD
		POPAD
		RETN
	}
}

// d2client preferred base = 6faa0000
NAKED D2Extra_B250()
{
	__asm {
		MOV EAX,ptUnit       //6fbbc200                       ;  default storage for ptUnit (player)(client-side)
		MOV EAX,DWORD PTR [EAX]                   ;  get ptUnit (player)(client-side)
		RETN
	}
}

NAKED D2Extra_B270()
{
	__asm {
		MOV EAX,ptDiff		//6FBA795C                                ;  default storage for game difficulty (client-side)
		MOV EAX,DWORD PTR [EAX]                   ;  get game difficulty (client-side)
		AND EAX,0x0FF                                  ;  mask off all but AL
		RETN
	}
}

NAKED D2Extra_B290()
{
	__asm {
		MOV EAX,ptInfo		// 6FB9A948			;  default storage for game info pointer
		MOV EAX,DWORD PTR [EAX]					;  client-side pointer to game info
		MOV EAX,DWORD PTR [EAX+0x1EA]            ;  get game info (classic/exp, soft/hardcore, etc)
		RETN
	}
}

NAKED D2Extra_B380()
{
	__asm {
		PUSH ECX
		PUSH EDX
		MOV EDI,ECX
		SHL EDI,4
		ADD EDI,DWORD PTR [D2Extra6F80D100]
		MOVZX ECX,BYTE PTR [EDI+0xC]                ;  get town message indicator
		CMP ECX,[EBP+8] //ARG.1]                              ;  indicator matches current location?
		JE SHORT JMP1	//D2Extra.6F7AB39E
RET1:		//6F7AB396
		MOV EAX,-1                                   ;  failed filter, exit -1
		POP EDX
		POP ECX
		RETN
JMP1:		//6F7AB39E
		TEST EDX,EDX                                 ;  if adventuring && no new msgs, ignore read status
		JNZ SHORT JMP2	//D2Extra.6F7AB3AA
		MOVZX EAX,BYTE PTR [EDI+0xE]                ;  get message read status
		TEST EAX,EAX
		JNZ SHORT RET1	//D2Extra.6F7AB396
JMP2:		//6F7AB3AA
		MOVZX EAX,BYTE PTR [EDI+2]                ;  get difficulty filter
		TEST EAX,EAX
		JE SHORT JMP3	//D2Extra.6F7AB3C2
		TEST ECX,ECX                                 ;  is town?
		JE SHORT JMP4	//D2Extra.6F7AB3BD
		CMP EAX,[EBP+0x20] //ARG.7]                              ;  what is current difficulty?
		JNZ SHORT RET1	//D2Extra.6F7AB396                   ;  if town, must equal difficulty
		JMP SHORT JMP3	//D2Extra.6F7AB3C2
JMP4:
		CMP EAX,[EBP+0x20] //ARG.7]                              ;  what is current difficulty?
		JB SHORT RET1	//D2Extra.6F7AB396
JMP3:		//6F7AB3C2
		MOVZX EAX,BYTE PTR [EDI+3]                ;  get act filter
		TEST EAX,EAX
		JE SHORT JMP5	//D2Extra.6F7AB3DA
		TEST ECX,ECX
		JE SHORT JMP6	//D2Extra.6F7AB3D5
		CMP EAX,[EBP+0x1C] //ARG.6]                              ;  what is current act?
		JNZ SHORT RET1	//D2Extra.6F7AB396                   ;  if town message, must be equal
		JMP SHORT JMP7	//D2Extra.6F7AB3E7                   ;  we don't care about game area since we know act
JMP6:		//6F7AB3D5
		CMP EAX,[EBP+0x1C] //arg.6]                              ;  what is current act?
		JB SHORT RET1	//D2Extra.6F7AB396                    ;  if adventuring message, must be equal or higher
JMP5:		//6F7AB3DA
		MOVZX EAX,WORD PTR [EDI+4]                ;  get game area filter
		TEST EAX,EAX
		JE SHORT JMP7	//D2Extra.6F7AB3E7
		CMP EAX,[EBP+0x18] //ARG.5]                              ;  what game area are we in now?
		JB SHORT RET1	//D2Extra.6F7AB396
JMP7:		//6F7AB3E7
		MOVZX EAX,BYTE PTR [EDI+7]                ;  get class filter
		CMP AL,0x0FF                                   ;  any class = -1
		JE SHORT JMP8	//D2Extra.6F7AB3F4
		CMP EAX,[EBP+0x14] //ARG.4]
		JNZ SHORT RET1	//D2Extra.6F7AB396
JMP8:
		MOVZX EAX,BYTE PTR [EDI+6]                ;  get quest filter
		TEST EAX,EAX
//LOOP1:		//6F7AB3FA
		JE SHORT JMP9	//D2Extra.6F7AB447
		MOV ECX,[EBP+0x20]//ARG.7]                              ;  get current dificulty
		DEC ECX                                      ;  adjust to standard
		PUSH [EBP+0x28] //ARG.9]                                 ;  ptUnit (player)
		CALL DWORD PTR [D2Common_10424]
		MOV EAX,DWORD PTR [EAX+ECX*4+0x10]          ;  get quest record
		TEST EAX,EAX
		JE SHORT JMP9	//D2Extra.6F7AB447
		MOVZX ECX,BYTE PTR [EDI+6]                ;  quest filter
		PUSH ESI
		PUSH EDI
		MOV ESI,EAX
		MOV EDI,ECX
		PUSH 0x0C                                      ;  quest closed?
		PUSH EDI
		PUSH ESI
		CALL DWORD PTR [D2Common_11107]
		TEST EAX,EAX
		JNZ SHORT JMP10	//D2Extra.6F7AB445                   ;  yes
		PUSH 0                                       ;  quest reward granted?
		PUSH EDI
		PUSH ESI
		CALL DWORD PTR [D2Common_11107]
		TEST EAX,EAX
		JNZ SHORT JMP10	//D2Extra.6F7AB445                   ;  yes
		PUSH 0x0D                                      ;  quest objective achieved?
		PUSH EDI
		PUSH ESI
		CALL DWORD PTR [D2Common_11107]
		TEST EAX,EAX
		JNZ SHORT JMP10	//D2Extra.6F7AB445                   ;  yes
		POP EDI
		POP ESI
		JMP SHORT JMP11	//D2Extra.6F7AB46C                   ;  no
JMP10:		//6F7AB445
		POP EDI
		POP ESI
JMP9:		//6F7AB447
		PUSH 0                                       ;  get character level
		PUSH 0x0C
		PUSH [EBP+0x28] //ARG.9]                                 ;  ptUnit (player)
		CALL DWORD PTR [D2Common_10519]
		MOVZX ECX,WORD PTR [EDI+8]                ;  get minimum level filter
		CMP EAX,ECX
		JB SHORT JMP11	//D2Extra.6F7AB46C
		MOVZX ECX,WORD PTR [EDI+0xA]                ;  get maximum level filter
		TEST ECX,ECX
		JE SHORT JMP12	//D2Extra.6F7AB467                    ;  ignore maximum if 0
		CMP EAX,ECX
		JG SHORT JMP11	//D2Extra.6F7AB46C
JMP12:		//6F7AB467
		MOVZX EAX,WORD PTR [EDI]                  ;  passed all filters!  get message index
		JMP SHORT JMP13	//D2Extra.6F7AB471
JMP11:		//6F7AB46C
		MOV EAX,-1                                   ;  failed filter, exit -1
JMP13:		//6F7AB471
		POP EDX
		POP ECX
		RETN
	}
}
// D2GAME BASE = 6FC30000
NAKED D2Extra_B500()
{ 

	__asm {
		MOV ESI,[EBP+0x40] //ARG.15]
		MOV EAX,DWORD PTR [ESI+4]                 ;  ptUnit (Book of Lore)
		MOV ECX,DWORD PTR [EAX+0x10]                ;  anim mode
		TEST ECX,ECX
		JNZ SHORT JMP1	//D2Extra.6F7AB54A
		PUSH 1
		PUSH EAX
		CALL DWORD PTR [D2Common_10348]
		MOV EAX,DWORD PTR [ESI+0x10]
		PUSH EAX
		CALL DWORD PTR [D2Common_10626]
		MOV ECX,DWORD PTR [ESI]                   ;  ptGame
		MOV EDX,DWORD PTR [EAX+0xDC]                ;  get FrameCnt1 from Objects.bin record
		SHR EDX,8
		ADD EDX,DWORD PTR [ECX+0xA8]                ;  add ptGame +A8
		PUSH 0
		PUSH 0
		PUSH EDX
		PUSH 1
		MOV EDX,DWORD PTR [ESI+4]                 ;  ptUnit (Book of Lore)
		CALL DWORD PTR [D2Game0051B0]	//6FC351B0
JMP1:		//6F7AB54A
		MOV EDX,DWORD PTR [ESI+4]                 ;  ptUnit (Book of Lore)
		MOV ECX,DWORD PTR [ESI+8]                 ;  ptUnit (player)
		PUSH DWORD PTR [ESP+4]                    ;  message index
		CALL DWORD PTR [D2Game066E20]	//6FC96E20                                ;  Entry address
		RETN 4
	}
}

NAKED D2Extra_B600()
{ 
	__asm {
		PUSH EBP
		MOV EBP,ESP
		MOV EAX,DWORD PTR [D2Extra6F80D104]              ;  number of filter records
		MOV ECX,EAX
		SHL EAX,2
		SUB ESP,EAX
		XOR EAX,EAX
		MOV EDI,ESP
		REP STOSD
		XOR EBX,EBX                                  ;  start of retrieve new message logic
LOOP1:		//6F7AB617
		CALL D2Extra_B380
		CMP EAX,-1
		JE SHORT JMP1	//D2Extra.6F7AB625
		MOV DWORD PTR [ESP+EBX*4],EAX
		INC EBX
JMP1:		//6F7AB625
		INC ECX
		CMP ECX,DWORD PTR [D2Extra6F80D104]
		JB SHORT LOOP1	//D2Extra.6F7AB617
		TEST EBX,EBX                                 ;  did we find any good messages?
		JNZ SHORT JMP2	//D2Extra.6F7AB651
		PUSH 0x0AB62E
		PUSH OFFSET STRD //D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH OFFSET STRE	//D2Extra.6F80DE2F                        ;  ASCII "msg.town && (filter.count > 0)"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7] //6F80D090]                 ;  Fog.6FF644B7
JMP2:		//6F7AB651
		CMP EBX,1
		JG SHORT JMP3	//D2Extra.6F7AB65A                    ;  more than one message qualifies
		XOR EAX,EAX
		JMP SHORT JMP4	//D2Extra.6F7AB674                   ;  only one good message
JMP3:		//6F7AB65A
		MOV EDX,EBX
		MOV ECX,[EBP+0x38] //ARG.13]                            ;  ptGame (get seed)
		MOV ECX,DWORD PTR [ECX+0x18]
		LEA ECX,DWORD PTR [ECX+0x48]
		CALL D2Extra_DD00                       ;  get a random message
		MOV EDX,DWORD PTR [D2Extra6F80D104]
		CMP EAX,EDX
		JGE SHORT JMP3 //D2Extra.6F7AB65A
JMP4:		//6F7AB674
		MOV EAX,DWORD PTR [ESP+EAX*4]
		PUSH EAX
		CALL D2Extra_B500                        ;  display it!
		LEAVE
		RETN 4
	}
}

NAKED D2Extra_B920()
{ 
	__asm {
		XOR EDX,EDX
LOOP1:		//6F7AB922
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1
		MOV EAX,DWORD PTR [ESI+EDI+10]           ;  check each player position for an open slot
		TEST EAX,EAX
		JNZ SHORT JMP1	//D2Extra.6F7AB93D
		MOV EAX,[EBP+0x28] //ARG.9]                             ;  found one! get ptUnit (player)
		MOV DWORD PTR [ESI+EDI+10],EAX           ;  add to Message Read record
		MOV WORD PTR [ESI+EDI+14],BX             ;  and post filter record number too
		JMP SHORT JMP2	//D2Extra.6F7AB962
JMP1:		//6F7AB93D
		INC EDX
		CMP EDX,8
		JB SHORT LOOP1	//D2Extra.6F7AB922
		PUSH 0x0AB93E                                  ;  no open slot
		PUSH offset STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRG	//D2Extra.6F80DEAD        ;  ASCII "record overflow - ptMsg[x].data not clearing on player exit"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7]	//6F80D090]                 ;  Fog.6FF644B7
JMP2:		//6F7AB962
		RETN
	}
}

NAKED D2Extra_B970()
{ 
	__asm {
		PUSH ECX
		PUSH EBX
		SUB ESP,0x28
		MOV EDI,ESP
		MOV ECX,0x0A
		XOR EAX,EAX
		REP STOSD
		XOR EDX,EDX
LOOP1:		//6F7AB982
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1
		MOV EAX,DWORD PTR [ESI+EDI+0x10]           ;  get Message Read record slot
		TEST EAX,EAX                                ;  is this slot a space?
		JNZ SHORT JMP1	//D2Extra.6F7AB994
		ADD DWORD PTR [ESP+0x24],1                 ;  yes, increment number of open slots
JMP1:		//6F7AB994
		INC EDX
		CMP EDX,8
		JB SHORT LOOP1	//D2Extra.6F7AB982
		MOV EAX,DWORD PTR [ESP+0x24]
		TEST EAX,EAX
		JNZ SHORT JMP2	//D2Extra.6F7AB9C1
		PUSH 0x0AB99E                                  ;  no open slots
		PUSH offset STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRG	//D2Extra.6F80DEAD        ;  ASCII "record overflow - ptMsg[x].data not clearing on player exit"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7]	//6F80D090]                 ;  Fog.6FF644B7
JMP2:		//6F7AB9C1
LOOP2:
		MOV EBX,0x10F8                                ;  ptClient list offset in ptGame
		ADD EBX,[EBP+0x38] //ARG.13]                            ;  ptGame
		MOV EBX,DWORD PTR [EBX+ECX*4]            ;  check active players in game
		TEST EBX,EBX
		JE SHORT JMP3	//D2Extra.6F7AB9EF                   ;  skip if not active player
		XOR EDX,EDX
LOOP3:		//6F7AB9D2
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1                                  ;  get Message Read record slot
		MOV EAX,DWORD PTR [ESI+EDI+0x10]
		CMP EAX,DWORD PTR [EBX]
		JE SHORT JMP3	//D2Extra.6F7AB9EF
		INC EDX
		CMP EDX,8
		JB SHORT LOOP3	//D2Extra.6F7AB9D2
		MOV EAX,DWORD PTR [EBX]                  ;  this player not posted, hold for slot
		MOV DWORD PTR [ESP+ECX*4],EAX
		ADD DWORD PTR [ESP+0x20],1
JMP3:		//6F7AB9EF
		INC ECX
		CMP ECX,8
		JB SHORT LOOP2	//D2Extra.6F7AB9C1                   ;  number of pending updates
		MOV EAX,DWORD PTR [ESP+0x20]
		CMP EAX,DWORD PTR [ESP+0x24]
		JBE SHORT JMP4	//D2Extra.6F7ABA1E                   ;  not enough open slots
		PUSH 0x0AB9F7
		PUSH offset STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRG	//D2Extra.6F80DEAD        ;  ASCII "record overflow - ptMsg[x].data not clearing on player exit"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7] //6F80D090]                 ;  Fog.6FF644B7
JMP4:		//6F7ABA1E
		XOR ECX,ECX
		MOV DWORD PTR [ESP+0x24],ECX
LOOP4:		//6F7ABA24
		MOV EBX,DWORD PTR [ESP+ECX*4]
		TEST EBX,EBX
		JE SHORT JMP5	//D2Extra.6F7ABA57
		XOR EDX,EDX
LOOP5:		//6F7ABA2D
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1
		MOV EAX,DWORD PTR [ESI+EDI+0x10]
		TEST EAX,EAX
		JNZ SHORT JMP6	//D2Extra.6F7ABA51                 ;  get pending character ptUnit
		MOV EAX,DWORD PTR [ESP+ECX*4]
		MOV DWORD PTR [ESI+EDI+0x10],EAX
		MOV EAX,DWORD PTR [ESP+0x28]
		MOV WORD PTR [ESI+EDI+0x14],AX
		ADD DWORD PTR [ESP+0x24],1
		JMP SHORT JMP5	//D2Extra.6F7ABA57
JMP6:		//6F7ABA51
		INC EDX
		CMP EDX,8
		JB SHORT LOOP5	//D2Extra.6F7ABA2D
JMP5:		//6F7ABA57
		INC ECX
		CMP ECX,8
		JB SHORT LOOP4	//D2Extra.6F7ABA24                   ;  was the message posted at all?
		MOV EAX,DWORD PTR [ESP+0x24]
		TEST EAX,EAX
		JNZ SHORT JMP7	//D2Extra.6F7ABA84                   ;  no posts at all
		PUSH 0x0ABA5F
		PUSH offset STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRG	//D2Extra.6F80DEAD        ;  ASCII "record overflow - ptMsg[x].data not clearing on player exit"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7]	//6F80D090]                 ;  Fog.6FF644B7
JMP7:		//6F7ABA84
		CMP EAX,DWORD PTR [ESP+0x20]
		JGE SHORT JMP8	//D2Extra.6F7ABAA9                   ;  we didn't get everybody registered
		PUSH 0x0ABA82
		PUSH offset STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRG	//D2Extra.6F80DEAD        ;  ASCII "record overflow - ptMsg[x].data not clearing on player exit"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7]	//6F80D090]                 ;  Fog.6FF644B7
JMP8:		//6F7ABAA9
		ADD ESP,0x28
		POP EBX
		POP ECX
		RETN
	}
}


NAKED D2Extra_B830()
{ 
	__asm {
		XOR ECX,ECX
		MOV ESI,DWORD PTR [D2Extra6F80D108]              ;  pointer to Messages Read table
LOOP1:		//6F7AB838
		MOV EAX,DWORD PTR [ESI]                  ;  does the Book have game level in ptMsg?
		TEST EAX,EAX                                ;  if 0, this is an unread Book of Lore
		JNZ SHORT JMP1	//D2Extra.6F7AB895
		MOV EAX,[EBP+0x18] //ARG.5]                             ;  get current game level
		MOV DWORD PTR [ESI],EAX
		MOV EAX,[EBP+0xC] //ARG.2]                             ;  get current PosX
		MOV DWORD PTR [ESI+4],EAX
		MOV EAX,[EBP+0x10] //ARG.3]                             ;  get current PosY
		MOV DWORD PTR [ESI+8],EAX
		ADD DWORD PTR [D2Extra6F80D10C],1               ;  increment number of Books read
		MOV EAX,DWORD PTR [ESP+4]                ;  is this an AllSame message?
		TEST EAX,EAX
		JNZ SHORT JMP2	//D2Extra.6F7AB86A
		MOV EAX,[EBP+0x28] //ARG.9]                             ;  get ptUnit (player)
		MOV DWORD PTR [ESI+0x10],EAX               ;  add to Message Read record for this book
		MOV WORD PTR [ESI+0x14],BX                 ;  and post message index number too
		JMP SHORT JMP3	//D2Extra.6F7AB8DA
JMP2:		//6F7AB86A
		PUSH ECX                                    ;  make this an AllSame record
		MOV ECX,0x10F8                                ;  ptClient list offset in ptGame
		ADD ECX,[EBP+0x38] //ARG.13]                            ;  ptGame
		XOR EDX,EDX                                 ;  for i=1 to 8
LOOP2:		//6F7AB875
		MOV EAX,DWORD PTR [ECX+EDX*4]           ;  get ptClient[i] from ptGame list
		TEST EAX,EAX
		JE SHORT JMP4	//D2Extra.6F7AB88C
		MOV EAX,DWORD PTR [EAX]                 ;  get ptUnit[i] from ptClient[i]
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1
		MOV DWORD PTR [ESI+EDI+0x10],EAX          ;  add to Message Read record for this book
		MOV WORD PTR [ESI+EDI+0x14],BX            ;  and post message index number too
JMP4:		//6F7AB88C
		INC EDX
		CMP EDX,8                                  ;  next i
		JB SHORT LOOP2	//D2Extra.6F7AB875
		POP ECX
		JMP SHORT JMP3	//D2Extra.6F7AB8DA
JMP1:		//6F7AB895
		MOV EAX,DWORD PTR [ESI]                  ;  get record level
		CMP EAX,[EBP+0x18] //ARG.5]                             ;  compare to current level
		JNZ SHORT JMP5	//D2Extra.6F7AB8C2
		MOV EAX,DWORD PTR [ESI+4]                ;  get record PosX
		CMP EAX,[EBP+0xC] //ARG.2]                             ;  compare to current PosX
		JNZ SHORT JMP5	//D2Extra.6F7AB8C2
		MOV EAX,DWORD PTR [ESI+8]                ;  get record PosY
		CMP EAX,[EBP+0x10] //ARG.3]                             ;  compare to current PosY
		JNZ SHORT JMP5	//D2Extra.6F7AB8C2
		MOV EAX,DWORD PTR [ESP+4]                ;  is this an AllSame message?
		TEST EAX,EAX
		JNZ SHORT JMP6	//D2Extra.6F7AB8BB
		CALL D2Extra_B920                       ;  no, add current player to message read
		JMP SHORT JMP3	//D2Extra.6F7AB8DA                  ;  record for this message
JMP6:		//6F7AB8BB
		CALL D2Extra_B970                       ;  yes, add all remaining players to message
		JMP SHORT JMP3	//D2Extra.6F7AB8DA                  ;  read record for this message
JMP5:		//6F7AB8C2
		INC ECX
		CMP ECX,MAX_BOOKS	//0x4096                                ;  maximum number of Books of Lore	*** CHECK FOR BUG 4096 HEX ???
		JGE SHORT JMP7	//D2Extra.6F7AB8DD
		ADD ESI,40
		CMP ECX,DWORD PTR [D2Extra6F80D10C]             ;  checked all the books?
		JBE LOOP1	//D2Extra.6F7AB838
JMP3:		//6F7AB8DA
		RETN 4
JMP7:		//6F7AB8DD
		PUSH 0x0AB8C3
		PUSH offset STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRH	//D2Extra.6F80DE72                        ;  ASCII "current book <= MAX_LORE_BOOKS"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7] //6F80D090]                 ;  Fog.6FF644B7
		RETN                                         ;  dummy retn for Ollydbg analysis
	}
}



NAKED D2Extra_B700()
{ 
	__asm {
		PUSH EBP
		MOV EBP,ESP
		MOV EAX,DWORD PTR [D2Extra6F80D104]              ;  number of filter records
		MOV ECX,EAX
		SHL EAX,2
		SUB ESP,EAX
		XOR EAX,EAX
		MOV EDI,ESP
		REP STOSD
		XOR EBX,EBX
		XOR ECX,ECX
		MOV ESI,DWORD PTR [D2Extra6F80D108]              ;  get pointer to Messages Read table
LOOP1:		//6F7AB71F
		MOV EAX,DWORD PTR [ESI]                  ;  get record pointer
		TEST EAX,EAX                                ;  end of table if ptUnit = 0
		JE SHORT JMP1	//D2Extra.6F7AB74D
		MOV EAX,DWORD PTR [ESI]
		CMP EAX,[EBP+0x18] //ARG.5]                             ;  game area match?
// LOOP2:		//6F7AB72A
		JNZ SHORT JMP2	//D2Extra.6F7AB741
		MOV EAX,DWORD PTR [ESI+4]
		CMP EAX,[EBP+0xC] //ARG.2]                             ;  PosX match?
		JNZ SHORT JMP2	//D2Extra.6F7AB741
		MOV EAX,DWORD PTR [ESI+8]		// POSIBLE TYPO ( WAS ) 
		CMP EAX,[EBP+0x10] //ARG.3]                             ;  PosY match?
		JNZ SHORT JMP2	//D2Extra.6F7AB741
		MOV EBX,ESI                                 ;  match found, use Message Read record pointer
		JMP SHORT JMP3	//D2Extra.6F7AB751
JMP2:		//6F7AB741
		ADD ESI,40
		INC ECX
		CMP ECX,DWORD PTR [D2Extra6F80D10C]
		JB SHORT LOOP1	//D2Extra.6F7AB71F
JMP1:		//6F7AB74D
		TEST EBX,EBX
		JE SHORT JMP4	//D2Extra.6F7AB793
JMP3:		//6F7AB751
		XOR EDX,EDX
LOOP3:		//6F7AB753
		LEA EDI,DWORD PTR [EDX+EDX*2]
		SHL EDI,1
		MOV EAX,DWORD PTR [EBX+EDI+0x10]
		CMP EAX,[EBP+0x28] //ARG.9]                             ;  ptUnit (player)
		JNZ SHORT JMP5	//D2Extra.6F7AB768
		MOVZX ECX,WORD PTR [EBX+EDI+0x14]
		JMP SHORT JMP6	//D2Extra.6F7AB770
JMP5:		//6F7AB768
		INC EDX
		CMP EDX,8
		JB SHORT LOOP3	//D2Extra.6F7AB753
		JMP SHORT JMP7	//D2Extra.6F7AB791
JMP6:		//6F7AB770
		MOV DL,1
		CALL D2Extra_B380                        ;  does player still qualify for message?
		CMP EAX,-1
		JE SHORT JMP8	//D2Extra.6F7AB786
		PUSH EAX
		CALL D2Extra_B500                        ;  yes, display it
		LEAVE
		RETN 4
JMP8:		//6F7AB786
		XOR ECX,ECX                                  ;  no, clear it from the Message Read table
		MOV WORD PTR [EBX+EDI+0x14],CX
		MOV DWORD PTR [EBX+EDI+0x10],ECX
JMP7:		//6F7AB791
		XOR EBX,EBX
JMP4:		//6F7AB793
		XOR EDX,EDX
LOOP4:		//6F7AB795
		XOR ECX,ECX
LOOP5:		//6F7AB797
		CALL D2Extra_B380                      ;  find all the qualifying messages
		CMP EAX,-1
		JE SHORT JMP9	//D2Extra.6F7AB7A5
		MOV DWORD PTR [ESP+EBX*4],ECX
		INC EBX
JMP9:		//6F7AB7A5
		INC ECX
		CMP ECX,DWORD PTR [D2Extra6F80D104]
		JB SHORT LOOP5	//D2Extra.6F7AB797
		TEST EBX,EBX                                ;  did we find any good messages?
		JNZ SHORT JMP10	//D2Extra.6F7AB7D8
		TEST EDX,EDX
		JNZ SHORT JMP11	//D2Extra.6F7AB7B9
		INC EDX                                     ;  this time, try all adventuring message
		JMP SHORT LOOP4	//D2Extra.6F7AB795
JMP11:		//6F7AB7B9
		PUSH 0x0AB7B2
		PUSH OFFSET STRD	//D2Extra.6F80DE00                     ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH OFFSET STRF	//2Extra.6F80DE4E                        ;  ASCII "msg.adventure && (filter.count > 0)"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7] //6F80D090]                 ;  Fog.6FF644B7	// abort
JMP10:		//6F7AB7D8
		CMP EBX,1
		JG SHORT JMP12	//D2Extra.6F7AB7E1
		XOR EAX,EAX
		JMP SHORT JMP13	//D2Extra.6F7AB7FB                   ;  only one good message
JMP12:		//6F7AB7E1
		MOV EDX,EBX
		MOV ECX,[EBP+0x38] //ARG.13]                            ;  ptGame (get seed)
		MOV ECX,DWORD PTR [ECX+0x18]
		LEA ECX,DWORD PTR [ECX+0x48]
		CALL D2Extra_DD00                       ;  get a random message
		MOV EDX,DWORD PTR [D2Extra6F80D104]
		CMP EAX,EDX
		JGE SHORT JMP12	//D2Extra.6F7AB7E1
JMP13:		//6F7AB7FB
		MOV EBX,DWORD PTR [ESP+EAX*4]
		MOV EAX,EBX
		SHL EAX,4
		ADD EAX,DWORD PTR [D2Extra6F80D100]
		MOV BYTE PTR [EAX+0xE],1                    ;  post Message Read to filter record
		MOVZX ECX,WORD PTR [EAX]                  ;  get message index number
		PUSH ECX
		MOVZX EAX,BYTE PTR [EAX+0xD]                ;  get AllSame status from filter record
		PUSH EAX
		CALL D2Extra_B830                        ;  post message to Message Read table
		CALL D2Extra_B500
		LEAVE
		RETN 4
	}
}

NAKED D2Extra_B300()
{
	__asm {
		PUSHAD                                       ;  OperateFn handler for Book of Lore
		PUSHFD
		SUB ESP,0x18
		MOV EDI,ESP
		MOV ECX,6
		XOR EAX,EAX
		REP STOSD
		MOV EBX,DWORD PTR [ESP+ 0x1C]                ;  get ptUnit (player)
		MOV EBP,DWORD PTR [ESP+ 0x2C]                ;  get ptGame
		MOV AL,BYTE PTR [EBP+ 0x6D]
		INC EAX
		MOV DWORD PTR [ESP+ 0x14],EAX
		MOV ESI,DWORD PTR [ESP+ 0x20]                ;  get ptUnit (Book of Lore)
		MOV EAX,DWORD PTR [EBX+ 0x4]                 ;  character class
		MOV DWORD PTR [ESP+ 0x8],EAX
		MOV ECX,DWORD PTR [ESI+ 0x2C]                ;  hPath
		MOV EAX,DWORD PTR [ECX+ 0xC]                 ;  PosX
		MOV DWORD PTR [ESP],EAX
		MOV EAX,DWORD PTR [ECX+ 0x10]                ;  PosY
		MOV DWORD PTR [ESP+ 0x4],EAX
		PUSH EBX
		CALL DWORD PTR [D2Common_10342]
		PUSH EAX
		CALL DWORD PTR [D2Common_10057]
		MOV DWORD PTR [ESP+ 0xC],EAX                 ;  game level
		PUSH EAX
		CALL DWORD PTR [D2Common_10001]
		PUSH EAX                                     ;  act (0-count)
		INC EAX
		MOV DWORD PTR [ESP+ 0x14],EAX                ;  act (1-count) // changed 0x10 to 0x14
		CALL DWORD PTR [D2Common_10085]              ;  get town level for this act
		XOR EDX,EDX
		CMP EAX,DWORD PTR [ESP+ 0xC]                 ;  is current level a town level?
		JNZ SHORT JMP1	//D2Extra.6F7AB36D
		INC EDX
		PUSH EDX
		CALL D2Extra_B600	                        ;  yes, show a town message
		JMP SHORT JMP2	//D2Extra.6F7AB373
JMP1:
		PUSH EDX
		CALL D2Extra_B700                        ;  no, show an adventuring message
JMP2:
		ADD ESP,0x18
		POPFD
		POPAD
		RETN
	}
}


//=========================================================================

//##00: Player Name

NAKED D2Extra_BD00()
{ 
	__asm {
		SUB ESP,0x20                                   ;  ##00: Player Name
		MOV ECX,ESP
		CALL D2Extra_B250                        ;  get client-side ptUnit (player)
		PUSH EAX
		CALL DWORD PTR [D2Common_10424]                  ;  get ptPlayerInfo
		MOV EDX,EAX
		PUSH 0x20
		CALL DWORD PTR [D2Lang_10062]                    ;  D2Lang.Unicode::win2Unicode
		ADD ESP,0x20
		RETN
	}
}

//##01: Player Class

NAKED D2Extra_BD20()
{ 
	__asm {
		CALL D2Extra_B250                        ;  ##01: Player Class
		MOV EAX,DWORD PTR [EAX+4]
		MOV DL,0x0C4                                   ;  Charstats record width
		MUL DL
		MOV EDX,EAX
		MOV EAX,ptCharStats	// 6FDEA1CC                                ;  default location of Charstats base address pointer
		MOV EAX,DWORD PTR [EAX]
		ADD EAX,EDX
		RETN
	}
}

//##02: Player Level

NAKED D2Extra_BD50()
{ 
	__asm {
		PUSH EDI                                     ;  ##02: Player Level
		SUB ESP,0x40
		MOV EDI,ESP
		MOV ECX,0x10
		XOR EAX,EAX
		REP STOSD
		MOV ECX,ESP
		PUSH 0x10
		MOV EDX,offset STRJ	//D2Extra.6F7E26C5                     ;  ASCII "Level %d"
		CALL DWORD PTR [D2Lang_10062]                    ;  D2Lang.Unicode::win2Unicode
		MOV EDI,ESP
		CALL D2Extra_B250                        ;  get client-side ptUnit (player)
		PUSH 0
		PUSH 0x0C
		PUSH EAX
		CALL DWORD PTR [D2Common_10519]                  ;  get character level
		PUSH EAX
		PUSH EDI
		ADD EDI,0x18
		PUSH EDI
		PUSH 20H
		CALL DWORD PTR [D2Lang_10033]                    ;  D2Lang.Unicode::sprintf
		MOV EAX,EDI
		ADD ESP,50H
		POP EDI
		RETN
	}
}

// ##03: Game Difficulty

NAKED D2Extra_BDA0()
{ 
	__asm {
		SUB ESP,20H                                   ;  ##03: Game Difficulty
		MOV ECX,ESP
		CALL D2Extra_B270                        ;  get client-side game difficulty
		SHL EAX,4
		ADD EAX,offset D2Extra6F7E5000                     ;  ASCII "Normal" //WHERE THE HELL IS THIS ???
		MOV EDX,EAX
		PUSH 20h
		CALL DWORD PTR [D2Lang_10062]                    ;  D2Lang.Unicode::win2Unicode
		ADD ESP,20h
		RETN
	}
}

//##04: Game Act
NAKED D2Extra_BDC0()
{ 
	__asm {
		PUSH EDI
		SUB ESP,40h
		MOV EDI,ESP
		MOV ECX,10h
		XOR EAX,EAX
		REP STOSD
		MOV ECX,ESP
		PUSH 10h
		MOV EDX,offset STRK	//D2Extra.6F7E26CE                     ;  ASCII "Act %d"
		CALL DWORD PTR [D2Lang_10062]                    ;  D2Lang.Unicode::win2Unicode
		MOV EDI,ESP
		CALL D2Extra_B250                        ;  get client-side ptUnit (player)
		PUSH EAX
		CALL DWORD PTR [D2Common_10342]                  ;  get hRoom
		PUSH EAX
		CALL DWORD PTR [D2Common_10057]                  ;  get game area
		PUSH EAX
		CALL DWORD PTR [D2Common_10001]                  ;  get act
		INC EAX
		PUSH EAX
		PUSH EDI
		ADD EDI,18H
		PUSH EDI
		PUSH 10H
		CALL DWORD PTR [D2Lang_10033]                    ;  D2Lang.Unicode::sprintf
		MOV EAX,EDI
		ADD ESP,50H
		POP EDI
		RETN
	}
}
//##05: Game Area
NAKED D2Extra_BE10()
{ 
	__asm {
		CALL D2Extra_B250                        ;  ##05: Game Area
		PUSH EAX
		CALL DWORD PTR [D2Common_10342]                  ;  get hRoom
		PUSH EAX
		CALL DWORD PTR [D2Common_10057]                  ;  get game area
		MOV EDX,220h                                  ;  record width in levels.bin
		MUL EDX
		MOV EDX,EAX
		MOV	EAX,ptLevel	//6FDEA260
		MOV EAX,DWORD PTR [EAX]                   ;  pointer to levels.bin
		ADD EAX,EDX
		ADD EAX,16Eh                                  ;  offset to Unicode LevelName field
		RETN
	}
}

//##06: Player Title
NAKED D2Extra_BE50()
{ 
	__asm {
		SUB ESP,20h                                   ;  ##06: Player Title
		CALL D2Extra_B290                        ;  get client-side game info
		MOV ECX,EAX
		MOV EDX,EAX
		SHR ECX,8
		AND ECX,0Fh                                   ;  isolate highest quest achieved
		AND EDX,20h                                   ;  isolate classic/expansion info
		AND EAX,4                                    ;  isolate ordinary/hardcore info
		PUSH EDX
		PUSH EAX
		PUSH ECX
		CALL D2Extra_B250                        ;  get client-side ptUnit (player)
		PUSH DWORD PTR [EAX+4]                    ;  get character class
		CALL DWORD PTR [D2Win_10161]                     ;  get player title
		MOV ECX,ESP
		MOV EDX,EAX
		PUSH 20h
		CALL [D2Lang_10062]                    ;  D2Lang.Unicode::win2Unicode
		ADD ESP,20h
		MOV ECX,DWORD PTR [ESP+8]
		ADD ECX,2                                    ;  eliminate extra space
		MOV DWORD PTR [ESP+8],ECX
		RETN
	}
}  
	
/*	  
Jump table for client-side string variable processing (see line 6F7ABC9D)

6F80DC00 00BD 7A6F 20BD 7A6F 50BD 7A6F A0BD 7A6F ..zo .zoP.zo..zo                     ;  6F7ABD00, 6F7ABD20, 6F7ABD50, 6F7ABDA0
6F80DC10 C0BD 7A6F 10BE 7A6F 0000 0000 0000 0000 ..zo..zo........                     ;  6F7ABDC0, 6F7ABE10
*/		

DWORD D2Extra6F80DC00[]={
	(DWORD)D2Extra_BD00,
	(DWORD)D2Extra_BD20,
	(DWORD)D2Extra_BD50,
	(DWORD)D2Extra_BDA0,
	(DWORD)D2Extra_BDC0,
	(DWORD)D2Extra_BE10,
	(DWORD)D2Extra_BE50
};		  
//String Variable detection and evaluation
DWORD FRET;
static char MsgBuff[0x1000];

NAKED D2Extra_BC00()
{ 
	__asm {
		// ADDED CLIENT CODE-EDIT HERE
		//----------------------------
		POP [FRET]	// HACK: SAVE RETURN TO CORRECT THE STACK
		CALL DWORD PTR [D2Lang_10004]                    ;  get original string
		PUSH EAX

/*
		PUSH 0
		PUSH 0CCDh
		MOV ECX,0C00h
		MOV EDX,offset STRD	//D2Client.6FB8E3E4        ;  ASCII "C:\projects\D2\head\Diablo2\Source\D2Client\UI\text.cpp"
		CALL DWORD PTR [Fog_10042]                       ;  make a place for the adjusted string	// WHERE IS IT FREED ???
		PUSH EAX
*/
		PUSH OFFSET MsgBuff	// STATIC MSG BUFFER FOR REPLACEMENT STRING


		PUSH [FRET]	// RESTORE STACK
		//-----------------------------
		PUSH EBP
		MOV EBP,ESP
		MOV ECX,[EBP+0xC] //ARG.2]                              ;  get pointer to string
		CALL DWORD PTR [D2Lang_10040]                    ;  D2Lang.Unicode::strlen
		CMP EAX,4                                    ;  too short to have a string variable?
		JGE SHORT JMP1	//D2Extra.6F7ABC14
		LEAVE
		RETN 4
JMP1:		//6F7ABC14
		CMP EAX,0x0B00                                 ;  message too long?  be reasonable!
		JLE SHORT JMP2	//D2Extra.6F7ABC3A
		PUSH 0x0ABC14
		PUSH offset STRD	//D2Extra.6F80DE00                        ;  ASCII "C:\Myhrginoc\Diablo II\D2Extra\MessageUnit.cpp"
		PUSH offset STRI	//D2Extra.6F80DE91                        ;  ASCII "msg.length < MAX_MSG_LENGTH"
		CALL DWORD PTR [Fog_10023]
		ADD ESP,0x0C
		PUSH -1
		CALL DWORD PTR [Fog00144B7] //6F80D090]                 ;  Fog.6FF644B7
JMP2:		//6F7ABC3A
		PUSH ESI
		PUSH EDI
		PUSH EBX
		PUSH EDX
		MOV EBX,[EBP+8] //ARG.1]                              ;  get heap pointer
		NOP
		NOP
		NOP
		MOV ESI,[EBP+0xC] //ARG.2]                              ;  get pointer to string
		MOV EDI,EBX
		MOV ECX,0x300
		XOR EAX,EAX
		REP STOSD                                    ;  clean the heap space
		MOV EDI,EBX
LOOP1:		//6F7ABC54
		MOVZX EAX,WORD PTR [ESI]                 ;  get the next character
		TEST EAX,EAX
		JNZ SHORT JMP3	//D2Extra.6F7ABC5D
		JMP SHORT JMP4	//D2Extra.6F7ABCD2
JMP3:		//6F7ABC5D
		CMP EAX,0x23                                  ;  ASCII '#'
		JE SHORT JMP5	//D2Extra.6F7ABC66
LOOP2:		//6F7ABC62
		MOVSW                                       ;  if not '#' in '##xx' then copy it to the adjusted string
		JMP SHORT LOOP1 //D2Extra.6F7ABC54
JMP5:		//6F7ABC66
		MOVZX EAX,WORD PTR [ESI+2]
		CMP EAX,0x23                                  ;  ASCII '#'
		JNZ SHORT LOOP2	//D2Extra.6F7ABC62
		MOVZX EAX,WORD PTR [ESI+4]
		CMP EAX,0x30                                  ;  ASCII '0'
		JB SHORT LOOP2	//D2Extra.6F7ABC62
		CMP EAX,0x39                                  ;  ASCII '9'
		JG SHORT LOOP2	//D2Extra.6F7ABC62
		SUB EAX,0x30                                  ;  convert to number: tens digit
		MOV DL,0x0A
		MUL DL
		MOVZX EDX,WORD PTR [ESI+6]
		CMP EDX,0x30                                  ;  ASCII '0'
		JB SHORT LOOP2	//D2Extra.6F7ABC62
		CMP EDX,0x39
		JG SHORT LOOP2	//D2Extra.6F7ABC62                   ;  ASCII '9'
		SUB EDX,0x30                                  ;  convert to number: ones digit
		ADD EAX,EDX
		ADD ESI,8
		CMP EAX,6		// MAX FUNCTION
		JLE	JMP6
		MOV EAX,0x3F003F                              ;  UNICODE '??'
		MOV ECX,2
		REP STOSD
		JMP SHORT LOOP1	//D2Extra.6F7ABC54

JMP6:		//6F7ABCBC
		MOV EDX,DWORD PTR [EAX*4+D2Extra6F80DC00]       ;  string variable function jump table
		PUSH ESI
		PUSH EDI
		CALL EDX                                    ;  evaluate the string variable
		POP EDI
		MOV ESI,EAX                                 ;  now copy from variable definition
		MOV ECX,EAX
		CALL DWORD PTR [D2Lang_10040]               ;  D2Lang.Unicode::strlen
		MOV ECX,EAX
		REP MOVSW                                   ;  copy the value into the destination string
		POP ESI                                     ;  return to the original string as source
		JMP SHORT LOOP1	//D2Extra.6F7ABC54
JMP4:		//6F7ABCD2
		MOV EAX,EBX                                  ;  return with pointer to adjusted string
		POP EDX
		POP EBX
		POP EDI
		POP ESI
		LEAVE
		RETN 8
	}
}
			
			  
//Extension of d2common.10576!!	( ENTER GAME)

NAKED D2Extra_D800()
{ 
	__asm {
		MOV ECX,ESI
		CALL D2Extra_B000                       ;  Load Messages.bin and Message Read heap
												;  Add here for additional txt files

		POP EDI                                 ;  tail end code from 10576
		POP ESI
		POP EBX
		ADD ESP,0B4h
		RETN 0Ch
	}
}
//Extension of d2common.10575!! (LEAVE GAME)

NAKED D2Extra_DA00()
{ 
	__asm {
		MOV EAX,DWORD PTR [D2Extra6F80D100]              ;  remove Messages.bin image
		PUSH EAX
		CALL DWORD PTR [D2Common_10579]
		//free book records
		PUSH 0                                      ; enough room for 4096 Books of Lore in a game
		PUSH 0x0CCC									; LINE #
		MOV EDX,OFFSET STRD							; FILENAME
		MOV ECX,DWORD PTR [D2Extra6F80D108]              ;  remove Book records
		CALL DWORD PTR [Fog_10043]

			                                         ;  add here for additional txt files
		RETN
	}
}

//=======================================================================
// code edits - add code edits here
// {dwOffset, dwValue, FixupType =FT_NON,FT_REL or FT_FIX}


DECLARE_COMMON_MODS(6)
// D2Common edits here
/*
Changes to D2Common.10575 -- Leave the Game

6F61048E   |.  90                        NOP                                    ;  interleave code to remove a RETN
6F61048F   |.  90                        NOP
6F610490   |.  90                        NOP
6F610491   |.  90                        NOP
6F610492   |.  EB 0A                     JMP SHORT D2Common.6F61049E
6F610494   |>  68 F2080000               PUSH 8F2
6F610499   |.  68 606A696F               PUSH D2Common.6F696A60   ; ASCII "C:\projects\D2\head\Diablo2\Source\D2Common\DATATBLS\DataTbls.cpp"
6F61049E   |>  E8 A93E0700               CALL <JMP.&Fog.#10046>
6F6104A3   |>  FF15 0057696F             CALL DWORD PTR [6F695700]           ;  D2Extra.6F7ADA00  ** NEW LINE **  (fixup)
6F6104A9   \.  C3                        RETN                                   ;  tail end code from 10575
*/
{0x001048E,0x90900EEB,FT_NON},	//PUT JMP FIRST,LEAVE DEAD CODE

{0x00104A3,0x909090E9,FT_NON},
{0x00104A4,(DWORD)D2Extra_DA00,FT_REL},	// JMP DA00 ... RETURN FROM THERE

/*
Changes to D2Common.10576 -- Enter the Game

6F610797   |.  E8 84E80100               CALL D2Common.6F62F020                 ;  last Blizzard call from 10576
6F61079C   |.  FF15 FC56696F             CALL DWORD PTR [6F6956FC]           ;  D2Extra.6F7AD800  ** NEW LINE **  (fixup)

// MOVE TAIL INTO D800  
6F6107A2   |.  5F                        POP EDI                                ;  tail end code from 10576
6F6107A3   |.  5E                        POP ESI
6F6107A4   |.  5B                        POP EBX
6F6107A5   |.  81C4 B4000000             ADD ESP,0B4
6F6107AB   \.  C2 0C00                   RETN 0C
6F6107AE       90                        NOP
6F6107AF       90                        NOP
*/
{0x001079C,0x815B5EE9,FT_NON},
{0x001079D,(DWORD)D2Extra_D800,FT_REL},	// JMP D800 ... RETURN FROM THERE

// unknown byte changed here ?
{0x00A1348,0x30,FT_NON},
END_MODS

DECLARE_CLIENT_MODS(2)
// D2Client edits here
/*
Display strings for NPCs (intro, gossip, quest info)

6FB1CDC5   |.  8BCB                      MOV ECX,EBX                                  ;  index to the display string
6FB1CDC7   |.  894424 18                 MOV DWORD PTR [ESP+18],EAX
6FB1CDCB   |.  E8 D0F60400               CALL D2Client.6FB6C4A0                       ;  <<< new code!! ***
*/
{0x07CDCC,(DWORD)D2Extra_BC00,FT_REL},
/*
Display strings for objects (Book of Lore, Tower Tome, etc)

6FB1D212   |.  8BCE                      MOV ECX,ESI                                  ;  index to the display string
6FB1D214   |.  894424 14                 MOV DWORD PTR [ESP+14],EAX
6FB1D218   |.  E8 83F20400               CALL D2Client.6FB6C4A0                       ;  <<< new code!! ***
*/
{0x07D219,(DWORD)D2Extra_BC00,FT_REL},

// NOTE: MOVED TO BC00 ...
/*
New code to get string, and process string variables

6FB6C4A0   /$  E8 33F9FFFF               CALL <JMP.&D2Lang.#10004>                    ;  get original string
6FB6C4A5   |.  50                        PUSH EAX
6FB6C4A6   |.  6A 00                     PUSH 0
6FB6C4A8   |.  68 CD0C0000               PUSH 0CCD
6FB6C4AD   |.  B9 000C0000               MOV ECX,0C00
6FB6C4B2   |.  BA E4E3B86F               MOV EDX,D2Client.6FB8E3E4        ;  ASCII "C:\projects\D2\head\Diablo2\Source\D2Client\UI\text.cpp"
6FB6C4B7   |.  E8 18E2FFFF               CALL <JMP.&Fog.#10042>                       ;  make a place for the adjusted string
6FB6C4BC   |.  50                        PUSH EAX
6FB6C4BD   |.  FF15 3C38B76F             CALL DWORD PTR [6FB7383C]                 ;  D2Extra.6F7ABC00 -- interpret variables
6FB6C4C3   \.  C3                        RETN

*/

END_MODS

DECLARE_GAME_MODS(5)
// D2Game edits here
/*  NOT NEEDED
Changes to D2Game.10009 (initialize the Relocation Table at start of game)

6FC3B275   />  FF15 0CBCD26F             CALL DWORD PTR [6FD2BC0C]                 ;  D2Extra.6F7ADF00
6FC3B27B   \.  C2 0400                   RETN 4

6FC3B2A0 #>/$  8B4424 04                 MOV EAX,DWORD PTR [ESP+4]
6FC3B2A4   |.  A3 2458D46F               MOV DWORD PTR [6FD45824],EAX
6FC3B2A9   \.^ EB CA                     JMP SHORT D2Game.6FC3B275                    ;  make link to DLL relocation table loader
6FC3B2AB       90                        NOP
*/

/* HMMM, TOO MUCH CODE.
Character exit procedure

6FC40310   /$  53                        PUSH EBX
6FC40311   |.  57                        PUSH EDI
6FC40312   |.  8BF9                      MOV EDI,ECX
6FC40314   |.  85FF                      TEST EDI,EDI                                 ;  valid ptGame?
6FC40316   |.  74 63                     JE SHORT D2Game.6FC4037B                        <<< redirected jump ***
6FC40318   |.  85D2                      TEST EDX,EDX                                 ;  valid ptUnit?
6FC4031A   |.  74 5F                     JE SHORT D2Game.6FC4037B                        <<< redirected jump ***
6FC4031C   |.  8B02                      MOV EAX,DWORD PTR [EDX]                   ;  type 0 ptUnit?
6FC4031E   |.  85C0                      TEST EAX,EAX
6FC40320   |.  74 05                     JE SHORT D2Game.6FC40327
6FC40322   |.  83F8 01                   CMP EAX,1
6FC40325   |.  75 54                     JNZ SHORT D2Game.6FC4037B                       <<< redirected jump ***
6FC40327   |>  8B9A D0000000             MOV EBX,DWORD PTR [EDX+D0]
6FC4032D   |.  83FB 0B                   CMP EBX,0B                                   ;  absolute newbie?
6FC40330   |.  74 49                     JE SHORT D2Game.6FC4037B                        <<< redirected jump ***
6FC40332   |.  8B949F F8100000           MOV EDX,DWORD PTR [EDI+EBX*4+10F8]        ;  ptClient list?
6FC40339   |.  85D2                      TEST EDX,EDX
6FC4033B   |.  74 2F                     JE SHORT D2Game.6FC4036C
6FC4033D   |.  56                        PUSH ESI
6FC4033E   |>  8B02                      /MOV EAX,DWORD PTR [EDX]
6FC40340   |.  8B72 08                   |MOV ESI,DWORD PTR [EDX+8]
6FC40343   |.  85C0                      |TEST EAX,EAX
6FC40345   |.  74 0A                     |JE SHORT D2Game.6FC40351
6FC40347   |.  C780 D0000000 0B000000    |MOV DWORD PTR [EAX+D0],0B
6FC40351   |>  8B4F 1C                   |MOV ECX,DWORD PTR [EDI+1C]
6FC40354   |.  6A 00                     |PUSH 0
6FC40356   |.  68 E8000000               |PUSH 0E8
6FC4035B   |.  68 28DED26F               |PUSH D2Game.6FD2DE28         ;  ASCII "C:\projects\D2\head\Diablo2\Source\D2Game\GAME\Targets.cpp"
6FC40360   |.  E8 83C30D00               |CALL <JMP.&Fog.#10046>
6FC40365   |.  85F6                      |TEST ESI,ESI
6FC40367   |.  8BD6                      |MOV EDX,ESI
6FC40369   |.^ 75 D3                     \JNZ SHORT D2Game.6FC4033E
6FC4036B   |.  5E                        POP ESI                                      ;  ptUnit (exiting character)
6FC4036C   |>  33C0                      XOR EAX,EAX
6FC4036E   |.  89849F F8100000           MOV DWORD PTR [EDI+EBX*4+10F8],EAX        ;  clear ptClient from ptGame
6FC40375   |.  FF15 14BCD26F             CALL DWORD PTR [6FD2BC14]                 ;  D2Extra.6F7AB200
6FC4037B   |>  5F                        POP EDI
6FC4037C   |.  5B                        POP EBX
6FC4037D   \.  C3                        RETN
*/
//6FC4036C     C7849F F8100000 00000000   MOV     DWORD PTR [EDI+EBX*4+10F8],0	// JUST REPLACE WITH CALL


{0x1036C,0xF89F84E8,FT_NON},
{0x1036D,(DWORD)D2Extra_B200,FT_REL},
{0x10371,0x90909090,FT_NON},	// HAVE TO FIX THE LANDING FOR RETURN :(
{0x10375,0x5B5F9090,FT_NON},


/* WHERE IS THIS CALLED FROM ???
Handling OperateFn=60 in Objects.txt (activate a Book of Lore)

6FC78A9D   |.  8A8D B3010000             MOV CL,BYTE PTR [EBP+1B3]
6FC78AA3   |.  8BD1                      MOV EDX,ECX
6FC78AA5   |.  8D4C24 10                 LEA ECX,DWORD PTR [ESP+10]
6FC78AA9   |.  FF1495 78FBD26F           CALL DWORD PTR [EDX*4+6FD2FB78]           ;  OperateFn value in EDX

6FC78B16   /.  FF15 10BCD26F             CALL DWORD PTR [6FD2BC10]                 ;  D2Extra.6F7AB300 (React to touching a Book of Lore)
6FC78B1C   \.  C3                        RETN
*/
{0x0FFC68,(DWORD)D2Extra_B300,FT_NON},	// SET FUNCTION TABLE DIRECTLY

END_MODS

DECLARE_WIN_MODS(0)
// D2Win edits here

END_MODS

DECLARE_GFX_MODS(0)
// D2Gfx edits here

END_MODS

DECLARE_NET_MODS(0)
// D2Net edits here

END_MODS

DECLARE_LANG_MODS(0)
// D2Lang edits here

END_MODS

DECLARE_CMP_MODS(0)
// D2Cmp edits here

END_MODS

DECLARE_LAUNCH_MODS(0)
// D2Launch edits here

END_MODS
// stuct to pass to loader with pointers
DECLARE_DATA(ModData)

//=======================================================================
// dll init functions - setup your mod here


// exported Init function called when loading by D2Mod.dll

MYMOD_API LPMODDATA STDCALL Init(LPSTR IniName)
{
	// Initialize any memory/resources here
	// use the ini file name passed to get settings

	return &ModData;
}

// exported Release function called by when unloading
MYMOD_API BOOL STDCALL Release()
{
	// release any memory/resources here
	return TRUE;
}

//=======================================================================

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	// According to MS: Don't call anything here that
	// may link in another call to LoadLibrary.
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			break;
    }
    return TRUE;
}

