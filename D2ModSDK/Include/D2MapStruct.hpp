/*=================================================================*/
/** @file D2MapStruct.h
 *  @brief Diablo II Map Structures definitions.
 *
 *  (c) January 2002 - Joel Falcou for The Phrozen Keep.
 */
/*=================================================================*/

#ifndef __D2MAPSTRUCT_H__INCLUDED__
#define __D2MAPSTRUCT_H__INCLUDED__

/*=================================================================*/
/*   Automap Cell Structure.                                       */
/*=================================================================*/

struct AutomapCell 
{                                   //Offset from Code
	DWORD           fSaved;         //+00
	WORD            nCellNo;        //+04
	WORD            xPixel;         //+06
	WORD            yPixel;         //+08
	WORD            unknown1;       //Unknown Data at +0C
	AutomapCell*    pLess;          //+0c
	AutomapCell*    pMore;          //+10
};

/*=================================================================*/
/*   Automap Layer Structure.                                       */
/*=================================================================*/

struct AutomapLayer 
{                                   //Offset from Code
	DWORD           unknown1[2];    //Unknown data at +00
	AutomapCell*    pFloors;        //+08
	AutomapCell*    pWalls;         //+0c
	AutomapCell*    pObjects;       //+10
	AutomapCell*    pExtras;        //+14
};
 
#endif
