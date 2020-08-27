#ifndef _PE_H
#define _PE_H

#pragma warning( disable : 4200 )  // Disable warning for zero-size struct

#pragma pack( push, enter_include1 )	// save pack settings
#pragma pack(1)

struct PE_HEADER {
	DWORD	PE_signature;	//= (PE)
	WORD	Machine;	// = IMAGE_FILE_MACHINE_I386
	WORD	NumberOfSections;	// = 4
	DWORD	TimeDateStamp;	// = 3F7CB7A2
	DWORD	PointerToSymbolTable;	// = 0
	DWORD	NumberOfSymbols;	// = 0
	WORD	SizeOfOptionalHeader;	// = E0 (224.)
	WORD	Characteristics;	// = DLL|EXECUTABLE_IMAGE|32BIT_MACHINE|LINE_NUMS_STRIPPED|LOCAL_SYMS_STRIPPED
	WORD	MagicNumber;	// = PE32
	BYTE	MajorLinkerVersion;	// = 6
	BYTE	MinorLinkerVersion;	// = 0
	DWORD  SizeOfCode;	// = B000 (45056.)
	DWORD  SizeOfInitializedData;	// = 15000 (86016.)
	DWORD  SizeOfUninitializedData;	// = 0
	DWORD  AddressOfEntryPoint;	// = 54A5
	DWORD  BaseOfCode;	// = 1000
	DWORD  BaseOfData;	// = C000
	DWORD ImageBase;	// = 6FA70000
	DWORD  SectionAlignment;	// = 1000
	DWORD  FileAlignment;	// = 1000
	WORD  MajorOSVersion;	// = 4
	WORD  MinorOSVersion;	// = 0
	WORD  MajorImageVersion;	// = 0
	WORD  MinorImageVersion;	// = 0
	WORD  MajorSubsystemVersion;	// = 4
	WORD  MinorSubsystemVersion;	// = 0
	DWORD  Reserved;
	DWORD  SizeOfImage;	// = 21000 (135168.)
	DWORD  SizeOfHeaders;	// = 1000 (4096.)
	DWORD  CheckSum;	// = 0
	WORD  Subsystem;	// = IMAGE_SUBSYSTEM_WINDOWS_GUI
	WORD  DLLCharacteristics;	// = 0
	DWORD  SizeOfStackReserve;	// = 100000 (1048576.)
	DWORD  SizeOfStackCommit;	// = 1000 (4096.)
	DWORD  SizeOfHeapReserve;	// = 100000 (1048576.)
	DWORD  SizeOfHeapCommit;	// = 1000 (4096.)
	DWORD  LoaderFlags;	// = 0
	DWORD  NumberOfRvaAndSizes;	// = 10 (16.)
	DWORD Export_Table_address;		// = D070
	DWORD Export_Table_size;		// = 17E (382.)
	DWORD Import_Table_address;		// = C834
	DWORD Import_Table_size;		// = 8C (140.)

};

struct EXPORTS {
	DWORD unk[3];
	DWORD dllName;
	DWORD startOrd;
	DWORD ordCnt;
	DWORD strCnt;
	DWORD ordStart;
	DWORD strStart;
	DWORD strOrds;
	DWORD exports[];
};

struct STR_EXP {
	DWORD strStart;
	WORD ord[];
};

struct D2DLL {
	LPSTR pName;
	DWORD dwBase,dwDelta;
	EXPORTS *pExports;
	DWORD *dwOffsets;
};

#pragma pack( pop, enter_include1 )	// restore pack settings

static DWORD ExAdd,ExEnd,prot,dwDelta;
#endif
