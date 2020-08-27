/*=================================================================*/
/** @file D2Struct.hpp
 *  @brief Diablo II structures definitions.
 *
 *  (c) January 2002 - Joel Falcou for The Phrozen Keep.
 */
/*=================================================================*/

#ifndef __D2STRUCT_HPP__INCLUDED__
#define __D2STRUCT_HPP__INCLUDED__

/*=================================================================*/
/*    Common Structure.                                            */ 
/*=================================================================*/

struct D2Seed 
{
	DWORD lowSeed;
    DWORD highSeed;
};

struct FogBitMasks
{
	DWORD	Mask[32];
};

/*=================================================================*/
/*   Forward Declarations.                                         */
/*=================================================================*/

// Unit related
struct Unit;

struct PlayerData;
struct MonsterData;
struct ObjectData;
struct ItemData ;

struct Quest;
struct Waypoint;
struct LocInfo;
struct Node;
struct Inventory;
struct Skills;
struct D2Info;
struct StatsList;
struct Stats ;
struct Combat;
struct D2Game;
struct Room;
struct Client;

// Map & dungeons related.
struct DrlgRoom2;
struct DrlgLevel;
struct DrlgMisc;
struct DrlgAct;
struct Path;

// Automap related.
struct AutomapCell;
struct AutomapLayer;

// String Table realted
struct TblHeader;
struct TblNode;

// Shrines effect
struct StateEffect;

// Menus
struct Menu;
struct NpcMenuData;

// TXT tables
struct D2SkillsTXT;
struct D2SkillDescTXT;
struct D2BooksTXT;
struct D2ItemsTXT;
struct D2RunesTXT;
struct D2RuneStruct;

// Cube Related
struct CubeInput;
struct CubeOutput;

// Object Related
struct Operate;

// Vendors
struct VendorLst;
struct VItems;


/*=================================================================*/
/*    Specific Structure.                                          */ 
/*=================================================================*/

#include "D2TxtStruct.h"
#include "D2UnitStruct.hpp"
//#include "D2DRLGStruct.hpp"
#include "D2MapStruct.hpp"
//#include "d2customtxt.hpp"
#include "D2StringTblStruct.hpp"
/*=================================================================*/
/*    Pointer Defintions                                           */
/*=================================================================*/

#define LPGAME      D2Game* 
#define LPUNIT      Unit*	    
#define LPPLAYER    Unit*	    
#define LPSKILL     D2SkillsTXT*

#endif
