/*=================================================================*/
/** @file D2StringTblStruct.hpp
 *  @brief Diablo II Tbl Structures definitions.
 *
 *  (c) June 2003 - Allan Jensen
 */
/*=================================================================*/

#pragma pack(1)

struct TblHeader
{
	WORD		CRCOffset;				// +00
	WORD		NumElementsOffset;		// +02
	DWORD		HashTableSizeOffset;	// +04
	BYTE		VersionOffset;			// +08
	DWORD		StringStartOffset;		// +09
	DWORD		NumLoopsOffset;			// +0D
	DWORD		FileSizeOffset;			// +11
};

struct TblNode
{
	BYTE		ActiveOffset;			// +00
	WORD		IdxNbrOffset;			// +01
	DWORD		HashValueOffset;		// +03
	DWORD		IdxStringOffset;		// +07
	DWORD		NameStringOffset;		// +0B
	WORD		NameLenOffset;			// +0F
	TblNode*	NextTblNode;			// +11
};
#pragma pack()

#define TBLHEADERSIZE	0x15
#define TBLNODESIZE		0x11