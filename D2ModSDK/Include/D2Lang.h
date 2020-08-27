#ifndef _D2LANG_H
#define _D2LANG_H

#define D2LANG_API_(T) D2API_(T)
#define D2LANGCALL_(T) D2CALL_(T)
#define D2LANGDATA D2DATA




struct Unicode  {
	Unicode(WORD cnt); // @10014
	
	static void __cdecl sprintf(int,Unicode* p,const Unicode *p1,... );	// @10033 
};

// ?sprintf@Unicode@@SAXHPAU1@PBU1@ZZ

/*
??0Unicode@@QAE@G@Z										@10014	NONAME
??4Unicode@@QAEAAU0@ABU0@@Z								@10015	NONAME
??BUnicode@@QBEGXZ										@10016	NONAME
??_FUnicode@@QAEXXZ										@10017	NONAME
?Personalize@Unicode@@SIXPAU1@PBU1@1HW4ELANGUAGE@@@Z	@10018	NONAME
?_toLowerTable@Unicode@@0PAGA							@10019	NONAME
?_toUpperTable@Unicode@@0PAGA							@10020	NONAME
?compare@Unicode@@QBEHU1@@Z								@10021	NONAME
?compare@Unicode@@SIHU1@0@Z								@10022	NONAME
?directionality@Unicode@@QAE?AW4Direction@1@XZ			@10023	NONAME
?isASCII@Unicode@@QBEHXZ								@10024	NONAME
?isAlpha@Unicode@@QBEHXZ								@10025	NONAME
?isLeftToRight@Unicode@@QBEHXZ							@10026	NONAME
?isLineBreak@Unicode@@SIHPBU1@I@Z						@10027	NONAME
?isNewline@Unicode@@QBEHXZ								@10028	NONAME
?isPipe@Unicode@@QBEHXZ									@10029	NONAME
?isWhitespace@Unicode@@QBEHXZ							@10030	NONAME
?isWordEnd@Unicode@@SIHPBU1@I@Z							@10031	NONAME
?loadSysMap@Unicode@@SIHPAUHD2ARCHIVE__@@PBD@Z			@10032	NONAME
?sprintf@Unicode@@SAXHPAU1@PBU1@ZZ						@10033	NONAME
?strcat@Unicode@@SIPAU1@PAU1@PBU1@@Z					@10034	NONAME
?strchr@Unicode@@SIPAU1@PBU1@U1@@Z						@10035	NONAME
?strcmp@Unicode@@SIHPBU1@0@Z							@10036	NONAME
?strcoll@Unicode@@SIHPBU1@0@Z							@10037	NONAME
?strcpy@Unicode@@SIPAU1@PAU1@PBU1@@Z					@10038	NONAME
?stricmp@Unicode@@SIHPBU1@0@Z							@10039	NONAME
?strlen@Unicode@@SIHPBU1@@Z								@10040	NONAME
?strncat@Unicode@@SIPAU1@PAU1@PBU1@H@Z					@10041	NONAME
?strncmp@Unicode@@SIHPBU1@0I@Z							@10042	NONAME
?strncoll@Unicode@@SIHPBU1@0H@Z							@10043	NONAME
?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z					@10044	NONAME
?strnicmp@Unicode@@SIHPBU1@0I@Z							@10045	NONAME
?strstr@Unicode@@SIPAU1@PBU1@0@Z						@10046	NONAME
?strstri@Unicode@@SIPAU1@PBU1@0@Z						@10047	NONAME
?sys2Unicode@Unicode@@SIPAU1@PAU1@PBDH@Z				@10048	NONAME
?sysWidth@Unicode@@SIKPBU1@H@Z							@10049	NONAME
?toLower@Unicode@@QBE?AU1@XZ							@10050	NONAME
?toUnicode@Unicode@@SIPAU1@PAU1@PBDH@Z					@10051	NONAME
?toUpper@Unicode@@QBE?AU1@XZ							@10052	NONAME
?toUtf@Unicode@@SIPADPADPBU1@H@Z						@10053	NONAME
?unicode2Sys@Unicode@@SIPADPADPBU1@H@Z					@10054	NONAME
?unicode2Win@Unicode@@SIPADPADPBU1@H@Z					@10055	NONAME
?unicodeWidth@Unicode@@SIKPBDH@Z						@10056	NONAME
?unicodenwidth@Unicode@@SIIPBDH@Z						@10057	NONAME
?unloadSysMap@Unicode@@SIXXZ							@10058	NONAME
?utf8ToUnicode@Unicode@@SIPAU1@PAU1@PBDH@Z				@10059	NONAME
?utfnwidth@Unicode@@SIIPBU1@H@Z							@10060	NONAME
?utfwidth@Unicode@@QBEHXZ								@10061	NONAME
?win2Unicode@Unicode@@SIPAU1@PAU1@PBDH@Z				@10062	NONAME
*/


#ifdef __cplusplus
extern "C" {
#endif


// Existing exports
//D2LANG_API_(DWORD) D2Lang_10000();
D2LANGDATA DWORD D2Lang_10000;
D2LANG_API_(DWORD) D2Lang_10001();
D2LANG_API_(DWORD) D2Lang_10002();

D2LANGDATA DWORD D2Lang_10003;
//D2LANGCALL_(Unicode *) D2Lang_10003(LPCSTR ptString);			// uStrFromKey
D2LANGCALL_(Unicode *)
 D2Lang_10004(DWORD index);				// uStrFromIndex

D2LANG_API_(DWORD) D2Lang_10005();
D2LANG_API_(void ) D2Lang_10006( LPSTR ptLang, DWORD Zero);	//D2GetLang
D2LANG_API_(DWORD) D2Lang_10007();
D2LANG_API_(DWORD) D2Lang_10008();
D2LANG_API_(DWORD) D2Lang_10009();
D2LANG_API_(DWORD) D2Lang_10010();
D2LANG_API_(DWORD) D2Lang_10011();
D2LANG_API_(DWORD) D2Lang_10012();
D2LANGDATA DWORD D2Lang_10013;
//D2LANG_API_(DWORD) D2Lang_10013();
/*
DWORD D2LANGDATA D2Lang_10033;//(LPWSTR);	// DUMMY
DWORD D2LANGDATA D2Lang_10040;//(LPWSTR);
DWORD D2LANGDATA D2Lang_10062;//(LPWSTR);
*/
//;----------------------------------
// Added exports
D2LANGCALL_(DWORD)
	D2Lang_10063(DWORD,DWORD);					// D2UnicodeWidth
D2LANGCALL_(DWORD)
	D2Lang_10064(LPVOID,DWORD,DWORD);			// D2ToUnicode
D2LANGCALL_(LPWSTR)
	D2Lang_10065(LPVOID ptFile,LPVOID,DWORD);	// D2GetStrFromIndex 
D2LANGCALL_(TblHeader*)
	D2Lang_10066(LPCSTR);						// D2LoadTblFile
D2LANGCALL_(DWORD)
	D2Lang_10067(LPVOID,LPVOID,LPSTR,LPWSTR);	// D2GetString (from key)


D2LANGDATA DWORD D2Lang_10713;
 
//;----------------------------------

#define uStrFromKey		D2Lang_10003
#define uStrFromIndex	D2Lang_10004
#define D2GetLang		D2Lang_10006

#define uStrLen			D2Lang_10040

#define D2UnicodeWidth	D2Lang_10063
#define D2ToUnicode		D2Lang_10064
#define D2GetStrFromIndex D2Lang_10065
#define D2LoadTblFile	D2Lang_10066
#define D2GetString		D2Lang_10067		//3a90


#define D2LANG_LASTORD D2Lang_10713;
#define D2LANG_BASE D2Lang_10713;



#ifdef __cplusplus
}
#endif

#endif