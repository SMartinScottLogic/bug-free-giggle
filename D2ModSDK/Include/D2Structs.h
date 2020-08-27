#ifndef D2STRUCT_H
#define D2STRUCT_h

// ----------------------------------------------------------------------------
//  Include global stucture definitions here


/*==============================*/
/*    Structure Definitions     */
/*==============================*/

// Special thanks to Joel Falcou and Allan Jensen


enum D2DifficultyMode
{
	D2DM_NORMAL = 0,
	D2DM_NIGHTMARE,
	D2DM_HELL
};

enum D2PlayerClass
{
	D2PC_AMAZON = 0,
	D2PC_SORCERESS,
	D2PC_NECROMANCER,
	D2PC_PALADIN,
	D2PC_BARBARIAN,
	D2PC_DRUID,
	D2PC_ASSASSIN
};

enum D2ItemFlags
{
    ITEMFLAG_NEWITEM			= 0x00000001,
	ITEMFLAG_TAGETING			= 0x00000004,
    ITEMFLAG_UNIDENTIFIED		= 0x00000010,
    ITEMFLAG_SOCKETED			= 0x00000800,
    ITEMFLAG_EAR				= 0x00001000,
    ITEMFLAG_NEWITEM2			= 0x00002000,
    ITEMFLAG_CHECKSECPRICE		= 0x00010000,
    ITEMFLAG_CHECKGAMBLEPRICE	= 0x00020000,
    ITEMFLAG_ETHERAL			= 0x00400000,
    ITEMFLAG_FROMPLAYER			= 0x01000000,
	ITEMFLAG_RUNEWORD			= 0x04000000
};

enum D2ItemQuality
{
	ITEMQUALITY_CRACKED = 1,
	ITEMQUALITY_NORMAL,
	ITEMQUALITY_SUPERIOR,
	ITEMQUALITY_MAGIC,
	ITEMQUALITY_SET,
	ITEMQUALITY_RARE,
	ITEMQUALITY_UNIQUE,
	ITEMQUALITY_CRAFTED,
	ITEMQUALITY_TEMPERED
};

enum D2UnitType
{
	UNIT_PLAYER = 0,
	UNIT_MONSTER,
	UNIT_OBJECT,
	UNIT_MISSILE,
	UNIT_ITEM,
	UNIT_ROOMTILE
};

enum D2Page
{
	PAGE_INVENTORY = 0,
	PAGE_CORPSE,		// Currently not known
	PAGE_MERC,			// Currently not known
	PAGE_CUBE,
	PAGE_STASH,
	PAGE_BODY = 0xFF
};

enum D2NodePage
{
	NODEPAGE_GROUND = 0,
	NODEPAGE_INVENTORY,
	NODEPAGE_BELT,
	NODEPAGE_BODYLOC,
	NODEPAGE_UNKNOWN
};

enum D2BodyLoc
{
	BODYLOC_NONE = 0,
	BODYLOC_HEAD,
	BODYLOC_NECK,
	BODYLOC_TORSO,
	BODYLOC_RIGHT_ARM,
	BODYLOC_LEFT_ARM,
	BODYLOC_RIGHT_RING,
	BODYLOC_LEFT_RING,
	BODYLOC_BELT,
	BODYLOC_FEET,
	BODYLOC_GLOVES
};

enum D2CubeFlagInput1
{
	CUBE_INPUT1_ITEM_ANY	= 0x01,		// also used to specify an item
	CUBE_INPUT1_TYPE		= 0x02,
	CUBE_INPUT1_NOS			= 0x04,
	CUBE_INPUT1_SOCK		= 0x08,
	CUBE_INPUT1_ETH			= 0x10,
	CUBE_INPUT1_NOE			= 0x20,
	CUBE_INPUT1_UPG			= 0x80
};

enum D2CubeFlagInput2
{
	CUBE_INPUT2_BAS			= 0x01,
	CUBE_INPUT2_EXC			= 0x02,
	CUBE_INPUT2_ELI			= 0x04,
	CUBE_INPUT2_NRU			= 0x08
};

enum D2CubeFlagOutput1
{
	CUBE_OUTPUT1_MOD		= 0x01,
	CUBE_OUTPUT1_SOCK		= 0x02,
	CUBE_OUTPUT1_ETH		= 0x04,
	CUBE_OUTPUT1_UNS		= 0x10,
	CUBE_OUTPUT1_REM		= 0x20,
	CUBE_OUTPUT1_REG		= 0x40,
	CUBE_OUTPUT1_EXC		= 0x80
};

enum D2CubeFlagOutput2
{
	CUBE_OUTPUT2_ELI		= 0x01,
	CUBE_OUTPUT2_REP		= 0x02,
	CUBE_OUTPUT2_RCH		= 0x04
};

enum D2CubeItemFlag
{
	CUBE_USEITEM			= 0xFF,
	CUBE_USETYPE			= 0xFE,
	CUBE_TYPE				= 0xFD,
	CUBE_ITEM				= 0xFC
};

enum D2ItemTypes
{
	ITEMTYPE_NONE_1 = 0,
	ITEMTYPE_NONE_2,
	ITEMTYPE_SHIELD,
	ITEMTYPE_ARMOR,
	ITEMTYPE_GOLD,
	ITEMTYPE_BOW_QUIVER,
	ITEMTYPE_CROSSBOW_QUIVER,
	ITEMTYPE_PLAYER_BODY_PART,
	ITEMTYPE_HERB,
	ITEMTYPE_POTION,
	ITEMTYPE_RING,
	ITEMTYPE_ELIXIR,
	ITEMTYPE_AMULET,
	ITEMTYPE_CHARM,
	ITEMTYPE_NONE_3,
	ITEMTYPE_BOOTS,
	ITEMTYPE_GLOVES,
	ITEMTYPE_NONE_4,
	ITEMTYPE_BOOK,
	ITEMTYPE_BELT,
	ITEMTYPE_GEM,
	ITEMTYPE_TORCH,
	ITEMTYPE_SCROLL,
	ITEMTYPE_NONE_5,
	ITEMTYPE_SCEPTER,
	ITEMTYPE_WAND,
	ITEMTYPE_STAFF,
	ITEMTYPE_BOW,
	ITEMTYPE_AXE,
	ITEMTYPE_CLUB,
	ITEMTYPE_SWORD,
	ITEMTYPE_HAMMER,
	ITEMTYPE_KNIFE,
	ITEMTYPE_SPEAR,
	ITEMTYPE_PLOEARM,
	ITEMTYPE_CROSSBOW,
	ITEMTYPE_MACE,
	ITEMTYPE_HELM,
	ITEMTYPE_MISSILE_POTION,
	ITEMTYPE_QUEST,
	ITEMTYPE_BODY_PART,
	ITEMTYPE_KEY,
	ITEMTYPE_THROWING_KNIFE,
	ITEMTYPE_THROWING_AXE,
	ITEMTYPE_JAVELIN,
	ITEMTYPE_WEAPON,
	ITEMTYPE_MELEE_WEAPON,
	ITEMTYPE_MISSILE_WEAPON,
	ITEMTYPE_THROWN_WEAPON,
	ITEMTYPE_COMBO_WEAPON,
	ITEMTYPE_ANY_ARMOR,
	ITEMTYPE_ANY_SHIELD,
	ITEMTYPE_MISCELLANEOUS,
	ITEMTYPE_SOCKET_FILLER,
	ITEMTYPE_SECOND_HAND,
	ITEMTYPE_STAVES_AND_RODS,
	ITEMTYPE_MISSILE,
	ITEMTYPE_BLUNT,
	ITEMTYPE_JEWEL,
	ITEMTYPE_CLASS_SPECIFIC,
	ITEMTYPE_AMAZON_ITEM,
	ITEMTYPE_BARBARIAN_ITEM,
	ITEMTYPE_NECROMANCER_ITEM,
	ITEMTYPE_PALADIN_ITEM,
	ITEMTYPE_SORCERESS_ITEM,
	ITEMTYPE_ASSASSIN_ITEM,
	ITEMTYPE_DRIUD_ITEM,
	ITEMTYPE_HAND_TO_HAND,
	ITEMTYPE_ORB,
	ITEMTYPE_VOODOO_HEADS,
	ITEMTYPE_AURIC_SHIELDS,
	ITEMTYPE_PRIMAL_HELM,
	ITEMTYPE_PELT,
	ITEMTYPE_CLOAK,
	ITEMTYPE_RUNE,
	ITEMTYPE_CIRCLET,
	ITEMTYPE_HEALING_POTION,
	ITEMTYPE_MANA_POTION,
	ITEMTYPE_REJUV_POTION,
	ITEMTYPE_STAMINA_POTION,
	ITEMTYPE_ANTIDOTE_POTION,
	ITEMTYPE_THAWING_POTION,
	ITEMTYPE_SMALL_CHARM,
	ITEMTYPE_MEDIUM_CHARM,
	ITEMTYPE_LARGE_CHARM,
	ITEMTYPE_AMAZON_BOW,
	ITEMTYPE_AMAZON_SPEAR,
	ITEMTYPE_AMAZON_JAVELIN,
	ITEMTYPE_HAND_TO_HAND_2,
	ITEMTYPE_MAGIC_BOW_QUIV,
	ITEMTYPE_CHIPPED_GEM,
	ITEMTYPE_FLAWED_GEM,
	ITEMTYPE_STANDARD_GEM,
	ITEMTYPE_FLAWLESS_GEM,
	ITEMTYPE_PERFECT_GEM,
	ITEMTYPE_AMETHYST,
	ITEMTYPE_DIAMOND,
	ITEMTYPE_EMERALD,
	ITEMTYPE_RUBY,
	ITEMTYPE_SAPPHIRE,
	ITEMTYPE_TOPAZ,
	ITEMTYPE_SKULL,
// Own ItemTypes
};

enum D2States
{
	STATE_NONE = 0,
	STATE_FREEZE,
	STATE_POISON,
	STATE_RESISTFIRE,
	STATE_RESISTCOLD,
	STATE_RESISTLIGHT,
	STATE_RESISTMAGIC,
	STATE_PLAYERBODY,
	STATE_RESISTALL,
	STATE_AMPLIFYDAMAGE,
	STATE_FROZENARMOR,
	STATE_COLD,
	STATE_INFERNO,
	STATE_BLAZE,
	STATE_BONEARMOR,
	STATE_CONCENTRATE,
	STATE_ENCHANT,
	STATE_INNERSIGHT,
	STATE_SKILL_MOVE,
	STATE_WEAKEN,
	STATE_CHILLINGARMOR,
	STATE_STUNNED,
	STATE_SPIDERLAY,
	STATE_DIMVISION,
	STATE_SLOWED,
	STATE_FETISHAURA,
	STATE_SHOUT,
	STATE_TAUNT,
	STATE_CONVICTION,
	STATE_CONVICTED,
	STATE_ENERGYSHIELD,
	STATE_VENOMCLAWS,
	STATE_BATTLEORDERS,
	STATE_MIGHT,
	STATE_PRAYER,
	STATE_HOLYFIRE,
	STATE_THORNS,
	STATE_DEFIANCE,
	STATE_THUNDERSTORM,
	STATE_LIGHTNINGBOLT,
	STATE_BLESSEDAIM,
	STATE_STAMINA,
	STATE_CONCENTRATION,
	STATE_HOLYWIND,
	STATE_HOLYWINDCOLD,
	STATE_CLEANSING,
	STATE_HOLYSHOCK,
	STATE_SANCTUARY,
	STATE_MEDITATION,
	STATE_FANATICISM,
	STATE_REDEMPTION,
	STATE_BATTLECOMMAND,
	STATE_PREVENTHEAL,
	STATE_CONVERSION,
	STATE_UNINTERRUPTABLE,
	STATE_IRONMAIDEN,
	STATE_TERROR,
	STATE_ATTRACT,
	STATE_LIFETAP,
	STATE_CONFUSE,
	STATE_DECREPIFY,
	STATE_LOWERRESIST,
	STATE_OPENWOUNDS,
	STATE_DOPPLEZON,
	STATE_CRITICALSTRIKE,
	STATE_DODGE,
	STATE_AVOID,
	STATE_PENETRATE,
	STATE_EVADE,
	STATE_PIERCE,
	STATE_WARMTH,
	STATE_FIREMASTERY,
	STATE_LIGHTNINGMASTERY,
	STATE_COLDMASTERY,
	STATE_SWORDMASTERY,
	STATE_AXEMASTERY,
	STATE_MACEMASTERY,
	STATE_POLEARMMASTERY,
	STATE_THROWINGMASTERY,
	STATE_SPEARMASTERY,
	STATE_INCREASEDSTAMINA,
	STATE_IRONSKIN,
	STATE_INCREASEDSPEED,
	STATE_NATURALRESISTANCE,
	STATE_FINGERMAGECURSE,
	STATE_NOMANAREGEN,
	STATE_JUSTHIT,
	STATE_SLOWMISSILES,
	STATE_SHIVERARMOR,
	STATE_BATTLECRY,
	STATE_BLUE,
	STATE_RED,
	STATE_DEATH_DELAY,
	STATE_VALKYRIE,
	STATE_FRENZY,
	STATE_BERSERK,
	STATE_REVIVE,
	STATE_ITEMFULLSET,
	STATE_SOURCEUNIT,
	STATE_REDEEMED,
	STATE_HEALTHPOT,
	STATE_HOLYSHIELD,
	STATE_JUST_PORTALED,
	STATE_MONFRENZY,
	STATE_CORPSE_NODRAW,
	STATE_ALIGNMENT,
	STATE_MANAPOT,
	STATE_SHATTER,
	STATE_SYNC_WARPED,
	STATE_CONVERSION_SAVE,
	STATE_PREGNANT,
	STATE_111,
	STATE_RABIES,
	STATE_DEFENSE_CURSE,
	STATE_BLOOD_MANA,
	STATE_BURNING,
	STATE_DRAGONFLIGHT,
	STATE_MAUL,
	STATE_CORPSE_NOSELECT,
	STATE_SHADOWWARRIOR,
	STATE_FERALRAGE,
	STATE_SKILLDELAY,
	STATE_PROGRESSIVE_DAMAGE,
	STATE_PROGRESSIVE_STEAL,
	STATE_PROGRESSIVE_OTHER,
	STATE_PROGRESSIVE_FIRE,
	STATE_PROGRESSIVE_COLD,
	STATE_PROGRESSIVE_LIGHTNING,
	STATE_SHRINE_ARMOR,
	STATE_SHRINE_COMBAT,
	STATE_SHRINE_RESIST_LIGHTNING,
	STATE_SHRINE_RESIST_FIRE,
	STATE_SHRINE_RESIST_COLD,
	STATE_SHRINE_RESIST_POISON,
	STATE_SHRINE_SKILL,
	STATE_SHRINE_MANA_REGEN,
	STATE_SHRINE_STAMINA,
	STATE_SHRINE_EXPERIENCE,
	STATE_FENRIS_RAGE,
	STATE_WOLF,
	STATE_BEAR,
	STATE_BLOODLUST,
	STATE_CHANGECLASS,
	STATE_ATTACHED,
	STATE_HURRICANE,
	STATE_ARMAGEDDON,
	STATE_INVIS,
	STATE_BARBS,
	STATE_WOLVERINE,
	STATE_OAKSAGE,
	STATE_VINE_BEAST,
	STATE_CYCLONEARMOR,
	STATE_CLAWMASTERY,
	STATE_CLOAK_OF_SHADOWS,
	STATE_RECYCLED,
	STATE_WEAPONBLOCK,
	STATE_CLOAKED,
	STATE_QUICKNESS,
	STATE_BLADESHIELD,
	STATE_FADE
};

enum D2Stat
{
    STAT_STRENGTH = 0,					// 000
    STAT_ENERGY,						// 001
    STAT_DEXTERITY,					    // 002
    STAT_VITALITY,						// 003
    STAT_STATPTS,						// 004
    STAT_NEWSKILLS,					    // 005
    STAT_HITPOINTS,					    // 006
    STAT_MAXHP,						    // 007
    STAT_MANA,							// 008
    STAT_MAXMANA,						// 009
    STAT_STAMINA,						// 00A
    STAT_MAXSTAMINA,					// 00B
    STAT_LEVEL,						    // 00C
    STAT_EXPERIENCE,					// 00D
    STAT_GOLD,							// 00E
    STAT_GOLDBANK,						// 00F
    STAT_ITEM_ARMOR_PERCENT,			// 010
    STAT_ITEM_MAXDAMAGE_PERCENT,		// 011
    STAT_ITEM_MINDAMAGE_PERCENT,		// 012
    STAT_TOHIT,
    STAT_TOBLOCK,
    STAT_MINDAMAGE,
    STAT_MAXDAMAGE,
    STAT_SECONDARY_MINDAMAGE,
    STAT_SECONDARY_MAXDAMAGE,
    STAT_DAMAGEPERCENT,
    STAT_MANARECOVERY,
    STAT_MANARECOVERYBONUS,
    STAT_STAMINARECOVERYBONUS,
    STAT_LASTEXP,
    STAT_NEXTEXP,
    STAT_ARMORCLASS,
    STAT_ARMORCLASS_VS_MISSILE,
    STAT_ARMORCLASS_VS_HTH,
    STAT_NORMAL_DAMAGE_REDUCTION,
    STAT_MAGIC_DAMAGE_REDUCTION,
    STAT_DAMAGERESIST,
    STAT_MAGICRESIST,
    STAT_MAXMAGICRESIST,
    STAT_FIRERESIST,
    STAT_MAXFIRERESIST,
    STAT_LIGHTRESIST,
    STAT_MAXLIGHTRESIST,
    STAT_COLDRESIST,
    STAT_MAXCOLDRESIST,
    STAT_POISONRESIST,
    STAT_MAXPOISONRESIST,
    STAT_DAMAGEAURA,
    STAT_FIREMINDAM,
    STAT_FIREMAXDAM,
    STAT_LIGHTMINDAM,
    STAT_LIGHTMAXDAM,
    STAT_MAGICMINDAM,
    STAT_MAGICMAXDAM,
    STAT_COLDMINDAM,
    STAT_COLDMAXDAM,
    STAT_COLDLENGTH,
    STAT_POISONMINDAM,
    STAT_POISONMAXDAM,
    STAT_POISONLENGTH,
    STAT_LIFEDRAINMINDAM,
    STAT_LIFEDRAINMAXDAM,
    STAT_MANADRAINMINDAM,
    STAT_MANADRAINMAXDAM,
    STAT_STAMDRAINMINDAM,
    STAT_STAMDRAINMAXDAM,
    STAT_STUNLENGTH,
    STAT_VELOCITYPERCENT,
    STAT_ATTACKRATE,
    STAT_OTHER_ANIMRATE,
    STAT_QUANTITY,
    STAT_VALUE,
    STAT_DURABILITY,
    STAT_MAXDURABILITY,
    STAT_HPREGEN,
    STAT_ITEM_MAXDURABILITY_PERCENT,
    STAT_ITEM_MAXHP_PERCENT,
    STAT_ITEM_MAXMANA_PERCENT,
    STAT_ITEM_ATTACKERTAKESDAMAGE,
    STAT_ITEM_GOLDBONUS,
    STAT_ITEM_MAGICBONUS,
    STAT_ITEM_KNOCKBACK,
    STAT_ITEM_TIMEDURATION,
    STAT_ITEM_ADDCLASSSKILLS,
    STAT_UNSENTPARAM1,
    STAT_ITEM_ADDEXPERIENCE,
    STAT_ITEM_HEALAFTERKILL,
    STAT_ITEM_REDUCEDPRICES,
    STAT_ITEM_DOUBLEHERBDURATION,
    STAT_ITEM_LIGHTRADIUS,
    STAT_ITEM_LIGHTCOLOR,
    STAT_ITEM_REQ_PERCENT,
    STAT_ITEM_LEVELREQ,
    STAT_ITEM_FASTERATTACKRATE,
    STAT_ITEM_LEVELREQPCT,
    STAT_LASTBLOCKFRAME,
    STAT_ITEM_FASTERMOVEVELOCITY,
    STAT_ITEM_NONCLASSSKILL,
    STAT_STATE,
    STAT_ITEM_FASTERGETHITRATE,
    STAT_MONSTER_PLAYERCOUNT,
    STAT_SKILL_POISON_OVERRIDE_LENGTH,
    STAT_ITEM_FASTERBLOCKRATE,
    STAT_SKILL_BYPASS_UNDEAD,
    STAT_SKILL_BYPASS_DEMONS,
    STAT_ITEM_FASTERCASTRATE,
    STAT_SKILL_BYPASS_BEASTS,
    STAT_ITEM_SINGLESKILL,
    STAT_ITEM_RESTINPEACE,
    STAT_CURSE_RESISTANCE,
    STAT_ITEM_POISONLENGTHRESIST,
    STAT_ITEM_NORMALDAMAGE,
    STAT_ITEM_HOWL,
    STAT_ITEM_STUPIDITY,
    STAT_ITEM_DAMAGETOMANA,
    STAT_ITEM_IGNORETARGETAC,
    STAT_ITEM_FRACTIONALTARGETAC,
    STAT_ITEM_PREVENTHEAL,
    STAT_ITEM_HALFFREEZEDURATION,
    STAT_ITEM_TOHIT_PERCENT,
    STAT_ITEM_DAMAGETARGETAC,
    STAT_ITEM_DEMONDAMAGE_PERCENT,
    STAT_ITEM_UNDEADDAMAGE_PERCENT,
    STAT_ITEM_DEMON_TOHIT,
    STAT_ITEM_UNDEAD_TOHIT,
    STAT_ITEM_THROWABLE,
    STAT_ITEM_ELEMSKILL,
    STAT_ITEM_ALLSKILLS,
    STAT_ITEM_ATTACKERTAKESLIGHTDAMAGE,
    STAT_IRONMAIDEN_LEVEL,
    STAT_LIFETAP_LEVEL,
    STAT_THORNS_PERCENT,
    STAT_BONEARMOR,
    STAT_BONEARMORMAX,
    STAT_ITEM_FREEZE,
    STAT_ITEM_OPENWOUNDS,
    STAT_ITEM_CRUSHINGBLOW,
    STAT_ITEM_KICKDAMAGE,
    STAT_ITEM_MANAAFTERKILL,
    STAT_ITEM_HEALAFTERDEMONKILL,
    STAT_ITEM_EXTRABLOOD,
    STAT_ITEM_DEADLYSTRIKE,
    STAT_ITEM_ABSORBFIRE_PERCENT,
    STAT_ITEM_ABSORBFIRE,
    STAT_ITEM_ABSORBLIGHT_PERCENT,
    STAT_ITEM_ABSORBLIGHT,
    STAT_ITEM_ABSORBMAGIC_PERCENT,
    STAT_ITEM_ABSORBMAGIC,
    STAT_ITEM_ABSORBCOLD_PERCENT,
    STAT_ITEM_ABSORBCOLD,
    STAT_ITEM_SLOW,
    STAT_ITEM_AURA,
    STAT_ITEM_INDESCTRUCTIBLE,
    STAT_ITEM_CANNOTBEFROZEN,
    STAT_ITEM_STAMINADRAINPCT,
    STAT_ITEM_REANIMATE,
    STAT_ITEM_PIERCE,
    STAT_ITEM_MAGICARROW,
    STAT_ITEM_EXPLOSIVEARROW,
    STAT_ITEM_THROW_MINDAMAGE,
    STAT_ITEM_THROW_MAXDAMAGE,
    STAT_SKILL_HANDOFATHENA,
    STAT_SKILL_STAMINAPERCENT,
    STAT_SKILL_PASSIVE_STAMINAPERCENT,
    STAT_SKILL_CONCENTRATION,
    STAT_SKILL_ENCHANT,
    STAT_SKILL_PIERCE,
    STAT_SKILL_CONVICTION,
    STAT_SKILL_CHILLINGARMOR,
    STAT_SKILL_FRENZY,
    STAT_SKILL_DECREPIFY,
    STAT_SKILL_ARMOR_PERCENT,
    STAT_ALIGNMENT,
    STAT_TARGET0,
    STAT_TARGET1,
    STAT_GOLDLOST,
    STAT_CONVERSION_LEVEL,
    STAT_CONVERSION_MAXHP,
    STAT_UNIT_DOOVERLAY,
    STAT_ATTACK_VS_MONTYPE,
    STAT_DAMAGE_VS_MONTYPE,
    STAT_FADE,
    STAT_ARMOR_OVERRIDE_PERCENT,
    STAT_UNUSED183,
    STAT_UNUSED184,
    STAT_UNUSED185,
    STAT_UNUSED186,
    STAT_UNUSED187,
    STAT_ITEM_ADDSKILL_TAB,
    STAT_UNUSED189,
    STAT_UNUSED190,
    STAT_UNUSED191,
    STAT_UNUSED192,
    STAT_UNUSED193,
    STAT_ITEM_NUMSOCKETS,
    STAT_ITEM_SKILLONATTACK,
    STAT_ITEM_SKILLONKILL,
    STAT_ITEM_SKILLONDEATH,
    STAT_ITEM_SKILLONHIT,
    STAT_ITEM_SKILLONLEVELUP,
    STAT_UNUSED200,
    STAT_ITEM_SKILLONGETHIT,
    STAT_UNUSED202,
    STAT_UNUSED203,
    STAT_ITEM_CHARGED_SKILL,
    STAT_UNUSED204,
    STAT_UNUSED205,
    STAT_UNUSED206,
    STAT_UNUSED207,
    STAT_UNUSED208,
    STAT_UNUSED209,
    STAT_UNUSED210,
    STAT_UNUSED211,
    STAT_UNUSED212,
    STAT_ITEM_ARMOR_PERLEVEL,
    STAT_ITEM_ARMORPERCENT_PERLEVEL,
    STAT_ITEM_HP_PERLEVEL,
    STAT_ITEM_MANA_PERLEVEL,
    STAT_ITEM_MAXDAMAGE_PERLEVEL,
    STAT_ITEM_MAXDAMAGE_PERCENT_PERLEVEL,
    STAT_ITEM_STRENGTH_PERLEVEL,
    STAT_ITEM_DEXTERITY_PERLEVEL,
    STAT_ITEM_ENERGY_PERLEVEL,
    STAT_ITEM_VITALITY_PERLEVEL,
    STAT_ITEM_TOHIT_PERLEVEL,
    STAT_ITEM_TOHITPERCENT_PERLEVEL,
    STAT_ITEM_COLD_DAMAGEMAX_PERLEVEL,
    STAT_ITEM_FIRE_DAMAGEMAX_PERLEVEL,
    STAT_ITEM_LTNG_DAMAGEMAX_PERLEVEL,
    STAT_ITEM_POIS_DAMAGEMAX_PERLEVEL,
    STAT_ITEM_RESIST_COLD_PERLEVEL,
    STAT_ITEM_RESIST_FIRE_PERLEVEL,
    STAT_ITEM_RESIST_LTNG_PERLEVEL,
    STAT_ITEM_RESIST_POIS_PERLEVEL,
    STAT_ITEM_ABSORB_COLD_PERLEVEL,
    STAT_ITEM_ABSORB_FIRE_PERLEVEL,
    STAT_ITEM_ABSORB_LTNG_PERLEVEL,
    STAT_ITEM_ABSORB_POIS_PERLEVEL,
    STAT_ITEM_THORNS_PERLEVEL,
    STAT_ITEM_FIND_GOLD_PERLEVEL,
    STAT_ITEM_FIND_MAGIC_PERLEVEL,
    STAT_ITEM_REGENSTAMINA_PERLEVEL,
    STAT_ITEM_STAMINA_PERLEVEL,
    STAT_ITEM_DAMAGE_DEMON_PERLEVEL,
    STAT_ITEM_DAMAGE_UNDEAD_PERLEVEL,
    STAT_ITEM_TOHIT_DEMON_PERLEVEL,
    STAT_ITEM_TOHIT_UNDEAD_PERLEVEL,
    STAT_ITEM_CRUSHINGBLOW_PERLEVEL,
    STAT_ITEM_OPENWOUNDS_PERLEVEL,
    STAT_ITEM_KICK_DAMAGE_PERLEVEL,
    STAT_ITEM_DEADLYSTRIKE_PERLEVEL,
    STAT_ITEM_FIND_GEMS_PERLEVEL,
    STAT_ITEM_REPLENISH_DURABILITY,
    STAT_ITEM_REPLENISH_QUANTITY,
    STAT_ITEM_EXTRA_STACK,
    STAT_ITEM_FIND_ITEM,
    STAT_ITEM_SLASH_DAMAGE,
    STAT_ITEM_SLASH_DAMAGE_PERCENT,
    STAT_ITEM_CRUSH_DAMAGE,
    STAT_ITEM_CRUSH_DAMAGE_PERCENT,
    STAT_ITEM_THRUST_DAMAGE,
    STAT_ITEM_THRUST_DAMAGE_PERCENT,
    STAT_ITEM_ABSORB_SLASH,
    STAT_ITEM_ABSORB_CRUSH,
    STAT_ITEM_ABSORB_THRUST,
    STAT_ITEM_ABSORB_SLASH_PERCENT,
    STAT_ITEM_ABSORB_CRUSH_PERCENT,
    STAT_ITEM_ABSORB_THRUST_PERCENT,
    STAT_ITEM_ARMOR_BYTIME,
    STAT_ITEM_ARMORPERCENT_BYTIME,
    STAT_ITEM_HP_BYTIME,
    STAT_ITEM_MANA_BYTIME,
    STAT_ITEM_MAXDAMAGE_BYTIME,
    STAT_ITEM_MAXDAMAGE_PERCENT_BYTIME,
    STAT_ITEM_STRENGTH_BYTIME,
    STAT_ITEM_DEXTERITY_BYTIME,
    STAT_ITEM_ENERGY_BYTIME,
    STAT_ITEM_VITALITY_BYTIME,
    STAT_ITEM_TOHIT_BYTIME,
    STAT_ITEM_TOHITPERCENT_BYTIME,
    STAT_ITEM_COLD_DAMAGEMAX_BYTIME,
    STAT_ITEM_FIRE_DAMAGEMAX_BYTIME,
    STAT_ITEM_LTNG_DAMAGEMAX_BYTIME,
    STAT_ITEM_POIS_DAMAGEMAX_BYTIME,
    STAT_ITEM_RESIST_COLD_BYTIME,
    STAT_ITEM_RESIST_FIRE_BYTIME,
    STAT_ITEM_RESIST_LTNG_BYTIME,
    STAT_ITEM_RESIST_POIS_BYTIME,
    STAT_ITEM_ABSORB_COLD_BYTIME,
    STAT_ITEM_ABSORB_FIRE_BYTIME,
    STAT_ITEM_ABSORB_LTNG_BYTIME,
    STAT_ITEM_ABSORB_POIS_BYTIME,
    STAT_ITEM_FIND_GOLD_BYTIME,
    STAT_ITEM_FIND_MAGIC_BYTIME,
    STAT_ITEM_REGENSTAMINA_BYTIME,
    STAT_ITEM_STAMINA_BYTIME,
    STAT_ITEM_DAMAGE_DEMON_BYTIME,
    STAT_ITEM_DAMAGE_UNDEAD_BYTIME,
    STAT_ITEM_TOHIT_DEMON_BYTIME,
    STAT_ITEM_TOHIT_UNDEAD_BYTIME,
    STAT_ITEM_CRUSHINGBLOW_BYTIME,
    STAT_ITEM_OPENWOUNDS_BYTIME,
    STAT_ITEM_KICK_DAMAGE_BYTIME,
    STAT_ITEM_DEADLYSTRIKE_BYTIME,
    STAT_ITEM_FIND_GEMS_BYTIME,
    STAT_ITEM_PIERCE_COLD,
    STAT_ITEM_PIERCE_FIRE,
    STAT_ITEM_PIERCE_LTNG,
    STAT_ITEM_PIERCE_POIS,
    STAT_ITEM_DAMAGE_VS_MONSTER,
    STAT_ITEM_DAMAGE_PERCENT_VS_MONSTER,
    STAT_ITEM_TOHIT_VS_MONSTER,
    STAT_ITEM_TOHIT_PERCENT_VS_MONSTER,
    STAT_ITEM_AC_VS_MONSTER,
    STAT_ITEM_AC_PERCENT_VS_MONSTER,
    STAT_FIRELENGTH,
    STAT_BURNINGMIN,
    STAT_BURNINGMAX,
    STAT_PROGRESSIVE_DAMAGE,
    STAT_PROGRESSIVE_STEAL,
    STAT_PROGRESSIVE_OTHER,
    STAT_PROGRESSIVE_FIRE,
    STAT_PROGRESSIVE_COLD,
    STAT_PROGRESSIVE_LIGHTNING,
    STAT_ITEM_EXTRA_CHARGES,
    STAT_PROGRESSIVE_TOHIT,
    STAT_POISON_COUNT,
    STAT_DAMAGE_FRAMERATE,
    STAT_PIERCE_IDX,
    STAT_PASSIVE_FIRE_MASTERY,
    STAT_PASSIVE_LTNG_MASTERY,
    STAT_PASSIVE_COLD_MASTERY,
    STAT_PASSIVE_POIS_MASTERY,
    STAT_PASSIVE_FIRE_PIERCE,
    STAT_PASSIVE_LTNG_PIERCE,
    STAT_PASSIVE_COLD_PIERCE,
    STAT_PASSIVE_POIS_PIERCE,
    STAT_PASSIVE_CRITICAL_STRIKE,
    STAT_PASSIVE_DODGE,
    STAT_PASSIVE_AVOID,
    STAT_PASSIVE_EVADE,
    STAT_PASSIVE_WARMTH,
    STAT_PASSIVE_MASTERY_MELEE_TH,
    STAT_PASSIVE_MASTERY_MELEE_DMG,
    STAT_PASSIVE_MASTERY_MELEE_CRIT,
    STAT_PASSIVE_MASTERY_THROW_TH,
    STAT_PASSIVE_MASTERY_THROW_DMG,
    STAT_PASSIVE_MASTERY_THROW_CRIT,
    STAT_PASSIVE_WEAPONBLOCK,
    STAT_PASSIVE_SUMMON_RESIST,
    STAT_MODIFIERLIST_SKILL,
    STAT_MODIFIERLIST_LEVEL,
    STAT_LAST_SENT_HP_PCT,
    STAT_SOURCE_UNIT_TYPE,
    STAT_SOURCE_UNIT_ID,
    STAT_SHORTPARAM1,
    STAT_QUESTITEMDIFFICULTY,
    STAT_PASSIVE_MAG_MASTERY,
    STAT_PASSIVE_MAG_PIERCE,            // 166
 // Own Stats
};

enum D2Mod
{
	ARMORCLASS = 0,
	ARMORCLASS_VS_MISSILE,
	ARMORCLASS_VS_HTH,
	NORMAL_DAMAGE_REDUCTION,
	NORMAL_DAMAGE_REDUCTION_PCT,
	ARMOR_PERCENT,
	MAGIC_DAMAGE_REDUCTION,
	STRENGTH,
	DEXTERITY,
	VITALITY,
	ENERGY,
	MAXMANA,
	MAXMANA_PERCENT,
	MAXHP,
	MAXHP_PERCENT,
	TOHIT,
	TOBLOCK,
	COLDMINDAM,
	COLDMAXDAM,
	COLDLENGTH,
	FIREMINDAM,
	FIREMAXDAM,
	LIGHTMINDAM,
	LIGHTMAXDAM,
	POISONMINDAM,
	POISONMAXDAM,
	POISONLENGTH,
	MINDAMAGE,
	MAXDAMAGE,
	WEAPONDAMAGE_PERCENT,
	DAMAGETOMANA,
	FIRERESIST,
	MAXFIRERESIST,
	LIGHTRESIST,
	MAXLIGHTRESIST,
	COLDRESIST,
	MAXCOLDRESIST,
	MAGICRESIST,
	MAXMAGICRESIST,
	POISONRESIST,
	MAXPOISONRESIST,
	RESISTALL,
	MAXRESISTALL,
	ASBORBFIRE_PERCENT,
	ASBORBFIRE,
	ASBORBLIGHT_PERCENT,
	ASBORBLIGHT,
	ASBORBMAGIC_PERCENT,
	ASBORBMAGIC,
	ASBORBCOLD_PERCENT,
	ASBORBCOLD,
	MAXDURABILITY,
	MAXDURABILITY_PERCENT,
	HITPOINTS_DELTA,
	ATTACKERTAKES_DAMAGE,
	FASTATTACKRATE,
	FASTERATTACKRATE,
	FASTESTATTACKRATE,
	GOLDBONUS,
	MAGICBONUS,
	KNOCKBACK,
	REGENSTAMINA_PERCENT,
	REGENMANA_PERCENT,
	BASESTAMINA,
	TIMEDURATION,
	MANASTEAL,
	LIFESTEAL,
	ADDAMASKILLPOINTS,
	ADDPALSKILLPOINTS,
	ADDNECSKILLPOINTS,
	ADDSORSKILLPOINTS,
	ADDBARSKILLPOINTS,
	DOUBLEHERBDURATION,
	LIGHTRADIUS,
	LIGHTCOLOR,
	REQ_PERCENT,
	FASTMOVEVELOCITY,
	FASTERMOVEVELOCITY,
	FASTESTMOVEVELOCITY,
	FASTGETHITRATE,
	FASTERGETHITRATE,
	FASTESTGETHITRATE,
	FASTBLOCKRATE,
	FASTERBLOCKRATE,
	FASTESTBLOCKRATE,
	FASTCASTRATE,
	FASTERCASTRATE,
	FASTESTCASTRATE,
	POISONLENGTHRESIST,
	NORMALDAMAGE,
	HOWL,
	STUPIDITY,
	IGNORETARGETAC,
	FRACTIONALTARGETAC,
	PREVENTHEAL,
	HALFFREEZEDURATION,
	TOHIT_PERCENT,
	DAMAGETARGETAC,
	DEMONDAMAGE_PERCENT,
	UNDEADDAMAGE_PERCENT,
	DEMON_TOHIT,
	UNDEAD_TOHIT,
	THROWABLE,
	FIRESKILL,
	ALLSKILLS,
	ATTACKERTAKESLIGHT_DAMAGE,
	FREEZE,
	OPENWOUNDS,
	CRUSHINGBLOW,
	KICKDAMAGE,
	MANAAFTERKILL,
	HEALAFTERDEMONKILL,
	EXTRABLOOD,
	DEADLYSTRIKE,
	SLOW,
	CANNOTBEFROZEN,
	STAMINADRAINPCT,
	REANIMATE,
	PIERCE,
	MAGICARROW,
	EXPLOSIVEARROW,
	ADDDRUSKILLPOINTS,
	ADDASSSKILLPOINTS,
	ADDSKILL,
	ADDTAB,
	ADDSKILL_PASSIVES,
	SKILL_ON_ATTACK,
	SKILL_ON_HIT,
	SKILL_ON_GETHIT,
	GEMBONUS,
	DURABILITY_OVER_TIME,
	FIRE_EFFECTS,
	LIGHTNING_EFFECTS,
	SOCKETS,
	FIRE_DAMAGE_MINMAX,
	LIGHT_DAMAGE_MINMAX,
	MAGIC_DAMAGE_MINMAX,
	COLD_DAMAGE_MINMAXLEN,
	POIS_DAMAGE_MINMAXLEN,
	THROW_DAMAGE_MINMAX,
	DAMAGE_MINMAX,
	STATS_ITEM_ARMOR_PERLEVEL_MOD,
	STATS_ITEM_ARMORPERCENT_PERLEVEL_MOD,
	STATS_ITEM_HP_PERLEVEL_MOD,
	STATS_ITEM_MANA_PERLEVEL_MOD,
	STATS_ITEM_MAXDAMAGE_PERLEVEL_MOD,
	STATS_ITEM_MAXDAMAGE_PERCENT_PERLEVEL_MOD,
	STATS_ITEM_STRENGTH_PERLEVEL_MOD,
	STATS_ITEM_DEXTERITY_PERLEVEL_MOD,
	STATS_ITEM_ENERGY_PERLEVEL_MOD,
	STATS_ITEM_VITALITY_PERLEVEL_MOD,
	STATS_ITEM_TOHIT_PERLEVEL_MOD,
	STATS_ITEM_TOHITPERCENT_PERLEVEL_MOD,
	STATS_ITEM_COLD_DAMAGEMAX_PERLEVEL_MOD,
	STATS_ITEM_FIRE_DAMAGEMAX_PERLEVEL_MOD,
	STATS_ITEM_LTNG_DAMAGEMAX_PERLEVEL_MOD,
	STATS_ITEM_POIS_DAMAGEMAX_PERLEVEL_MOD,
	STATS_ITEM_RESIST_COLD_PERLEVEL_MOD,
	STATS_ITEM_RESIST_FIRE_PERLEVEL_MOD,
	STATS_ITEM_RESIST_LTNG_PERLEVEL_MOD,
	STATS_ITEM_RESIST_POIS_PERLEVEL_MOD,
	STATS_ITEM_ABSORB_COLD_PERLEVEL_MOD,
	STATS_ITEM_ABSORB_FIRE_PERLEVEL_MOD,
	STATS_ITEM_ABSORB_LTNG_PERLEVEL_MOD,
	STATS_ITEM_ABSORB_POIS_PERLEVEL_MOD,
	STATS_ITEM_THORNS_PERLEVEL_MOD,
	STATS_ITEM_FIND_GOLD_PERLEVEL_MOD,
	STATS_ITEM_FIND_MAGIC_PERLEVEL_MOD,
	STATS_ITEM_REGENSTAMINA_PERLEVEL_MOD,
	STATS_ITEM_STAMINA_PERLEVEL_MOD,
	STATS_ITEM_DAMAGE_DEMON_PERLEVEL_MOD,
	STATS_ITEM_DAMAGE_UNDEAD_PERLEVEL_MOD,
	STATS_ITEM_TOHIT_DEMON_PERLEVEL_MOD,
	STATS_ITEM_TOHIT_UNDEAD_PERLEVEL_MOD,
	STATS_ITEM_CRUSHINGBLOW_PERLEVEL_MOD,
	STATS_ITEM_OPENWOUNDS_PERLEVEL_MOD,
	STATS_ITEM_KICK_DAMAGE_PERLEVEL_MOD,
	STATS_ITEM_DEADLYSTRIKE_PERLEVEL_MOD,
	STATS_ITEM_FIND_GEMS_PERLEVEL_MOD,
	STATS_ITEM_REPLENISH_DURABILITY_MOD,
	STATS_ITEM_REPLENISH_QUANTITY_MOD,
	STATS_ITEM_EXTRA_STACK_MOD,
	STATS_ITEM_FIND_ITEM_MOD,
	STATS_ITEM_SLASH_DAMAGE_MOD,
	STATS_ITEM_SLASH_DAMAGE_PERCENT_MOD,
	STATS_ITEM_CRUSH_DAMAGE_MOD,
	STATS_ITEM_CRUSH_DAMAGE_PERCENT_MOD,
	STATS_ITEM_THRUST_DAMAGE_MOD,
	STATS_ITEM_THRUST_DAMAGE_PERCENT_MOD,
	STATS_ITEM_ABSORB_SLASH_MOD,
	STATS_ITEM_ABSORB_CRUSH_MOD,
	STATS_ITEM_ABSORB_THRUST_MOD,
	STATS_ITEM_ABSORB_SLASH_PERCENT_MOD,
	STATS_ITEM_ABSORB_CRUSH_PERCENT_MOD,
	STATS_ITEM_ABSORB_THRUST_PERCENT_MOD,
	STATS_ITEM_ARMOR_BYTIME_MOD,
	STATS_ITEM_ARMORPERCENT_BYTIME_MOD,
	STATS_ITEM_HP_BYTIME_MOD,
	STATS_ITEM_MANA_BYTIME_MOD,
	STATS_ITEM_MAXDAMAGE_BYTIME_MOD,
	STATS_ITEM_MAXDAMAGE_PERCENT_BYTIME_MOD,
	STATS_ITEM_STRENGTH_BYTIME_MOD,
	STATS_ITEM_DEXTERITY_BYTIME_MOD,
	STATS_ITEM_ENERGY_BYTIME_MOD,
	STATS_ITEM_VITALITY_BYTIME_MOD,
	STATS_ITEM_TOHIT_BYTIME_MOD,
	STATS_ITEM_TOHITPERCENT_BYTIME_MOD,
	STATS_ITEM_COLD_DAMAGEMAX_BYTIME_MOD,
	STATS_ITEM_FIRE_DAMAGEMAX_BYTIME_MOD,
	STATS_ITEM_LTNG_DAMAGEMAX_BYTIME_MOD,
	STATS_ITEM_POIS_DAMAGEMAX_BYTIME_MOD,
	STATS_ITEM_RESIST_COLD_BYTIME_MOD,
	STATS_ITEM_RESIST_FIRE_BYTIME_MOD,
	STATS_ITEM_RESIST_LTNG_BYTIME_MOD,
	STATS_ITEM_RESIST_POIS_BYTIME_MOD,
	STATS_ITEM_ABSORB_COLD_BYTIME_MOD,
	STATS_ITEM_ABSORB_FIRE_BYTIME_MOD,
	STATS_ITEM_ABSORB_LTNG_BYTIME_MOD,
	STATS_ITEM_ABSORB_POIS_BYTIME_MOD,
	STATS_ITEM_FIND_GOLD_BYTIME_MOD,
	STATS_ITEM_FIND_MAGIC_BYTIME_MOD,
	STATS_ITEM_REGENSTAMINA_BYTIME_MOD,
	STATS_ITEM_STAMINA_BYTIME_MOD,
	STATS_ITEM_DAMAGE_DEMON_BYTIME_MOD,
	STATS_ITEM_DAMAGE_UNDEAD_BYTIME_MOD,
	STATS_ITEM_TOHIT_DEMON_BYTIME_MOD,
	STATS_ITEM_TOHIT_UNDEAD_BYTIME_MOD,
	STATS_ITEM_CRUSHINGBLOW_BYTIME_MOD,
	STATS_ITEM_OPENWOUNDS_BYTIME_MOD,
	STATS_ITEM_KICK_DAMAGE_BYTIME_MOD,
	STATS_ITEM_DEADLYSTRIKE_BYTIME_MOD,
	STATS_ITEM_FIND_GEMS_BYTIME_MOD,
	STATS_ITEM_PIERCE_COLD_MOD,
	STATS_ITEM_PIERCE_FIRE_MOD,
	STATS_ITEM_PIERCE_LTNG_MOD,
	STATS_ITEM_PIERCE_POIS_MOD,
	STATS_ITEM_DAMAGE_VS_MONSTER_MOD,
	STATS_ITEM_DAMAGE_PERCENT_VS_MONSTER_MOD,
	STATS_ITEM_TOHIT_VS_MONSTER_MOD,
	STATS_ITEM_TOHIT_PERCENT_VS_MONSTER_MOD,
	STATS_ITEM_AC_VS_MONSTER_MOD,
	STATS_ITEM_AC_PERCENT_VS_MONSTER_MOD,
	INDESTRUCTIBLE,
	STATS_ITEM_CHARGED_SKILL_MOD,
};



/*=================================================================*/
/*   Forward Declarations.                                         */
/*=================================================================*/

// Unit related
struct Unit;

struct PlayerData;
struct MonsterData;
struct ObjectData;
struct ItemData;

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

// TXT tables
struct D2SkillsTXT;
struct D2BooksTXT;
struct D2ItemsTXT;
struct D2RunesTXT;
struct D2RuneStruct;

// Cube Related
struct CubeInput;
struct CubeOutput;

// Object Related
struct Operate;





/*=================================================================*/
/*    Preset Unit Structures (used by DrlgRoom2).                  */
/*=================================================================*/

struct PresetUnit
{                                   //Offset from Code
};


/*=================================================================*/
/*   Unit Data Structure.                                          */
/*=================================================================*/

struct Unit
{									//Offset from Code.
	DWORD		nUnitType;			//+00 Unit Type
	DWORD		nUnitId;			//+04 Unit ID
    DWORD*		unknown_1;			//+08 ptGame + 1C
    DWORD		nUnitUnid;			//+0C Unique ID
	DWORD		nAnimMode;			//+10 Current animation mode

    union
    {
		PlayerData*     pPlayerData;
		MonsterData*    pMonsterData;
		ObjectData*     pObjectData;
		ItemData*       pItemData;
	};				                //+14 ptUnitData

    DWORD		nAct;		        //+18 Act
	DWORD		ptAct;				//+1C ptAct
	DWORD		LoSeed;				//+20
	DWORD		HiSeed;				//+24
	DWORD		StartLoSeed;		//+28
	Path*		hPath;				//+2C
	DWORD		unknown_7;			//+30
	DWORD		unknown_8;			//+34
	Path*		ptPos;				//+38 ptPos
	DWORD		unknown_10;			//+3C
	DWORD		unknown_11;			//+40
	DWORD		unknown_12;			//+44
	DWORD		unknown_13;			//+48
	DWORD		unknown_14;			//+4C
	DWORD		nAnimData;			//+50 AnimData.D2 record address for current mode
	DWORD		unknown_16;			//+54
	DWORD		unknown_17;			//+58
	StatsList*	ptStatsList;		//+5C ptStatsList
	Inventory*	ptInventory;		//+60 ptInventory
    DWORD		unknown_19;			//+64
	DWORD		unknown_20;			//+68
	DWORD		unknown_21;			//+6C
	DWORD		unknown_22;			//+70
	DWORD		unknown_23;			//+74 0 at start
	DWORD		unknown_24;			//+78
	DWORD		unknown_25;			//+7C
	D2Game*		ptGame;				//+80 ptGame
	DWORD		unknown_26;			//+84
	DWORD		unknown_27;			//+88
	DWORD		unknown_28;			//+8C
	DWORD		unknown_29;			//+90
	DWORD		unknown_30;			//+94
	DWORD		unknown_31;			//+98
	DWORD		unknown_32;			//+9C
	DWORD		unknown_33;			//+A0
	DWORD		unknown_34;			//+A4
	D2Info*		ptInfo;				//+A8 ptInfo
	DWORD		unknown_35;			//+AC
	DWORD		unknown_36;			//+B0
	DWORD		unknown_37;			//+B4
	DWORD		nDropItemCode;		//+B8
	DWORD		unknown_39;			//+BC
	DWORD		unknown_40;			//+C0
	DWORD		nFlags;				//+C4 Flags
	DWORD		nLODFlag;			//+C8 LODFlag
	DWORD		unknown_41;			//+CC
	DWORD		nClientNum;			//+D0 Client# (0B at start)

};

struct AIStruct
{
/*+00 = 0 on spawn, gæti breyst seinna
+04 = pfnFunction, ptr, see ai table.txt at +08 (if 0 and +00 = 0, then 6FCD3AD0, then 6FCCA0D0)
+0c = -1 on spawn
+10 = 1 on spawn
+14 = 0 on spawn
+18 = 0 on spawn
+1c = 0 on spawn
+28 = if minion, then ptGame
+2c = if minion, then owner id
+30 = if minion, then owner type */
};

struct PlayerData
{
	char	CharName[0x10];	//+00	Player Name
	LPVOID	ptQuest[3];		//+10	Quest Pointers for each difficulty
	BYTE	unknown[0x80];
	void*	ptClient;		//+9C	ptClient
};

struct MonsterData
{
	BYTE	unknown[0x26];		// +00
	WORD	SuperUniqueID;		// +26 Superunique ID of monster
/*
    AIStruct*     AIPtr;
    void*         unkonwPtr1;
    void*         uniqueInfo;
    void*         spawnInfo;
    void*         unknownPtr2;
    DWORD         unkown[8];
    void*         lvlPtr;
    MonStatTxt*   monstatPtr;
*/
};

struct ObjectData
{                       // Offset from Code
};

struct ItemData
{							// Offset from Code

	DWORD quality;			// +00.
	DWORD lowSeed;			// +04.
	DWORD highSeed;			// +08.
	DWORD unknown_1;		// +0c.
	DWORD startLowSeed;		// +10.
	DWORD cmdFlags;			// +14.
	DWORD flags;			// +18.
	DWORD unknown_2[3];		// +1C
	DWORD PlayerClass;		// +28
	BYTE unknown_3[19];		// +2C
	BYTE StorePage;			// +45
/*
    DWORD originID;			// +24.
    DWORD iLvl;				// +28.
    WORD  version;			// +2C.
    WORD  prefix;			// +2E.
    WORD  suffix;			// +30.
    WORD  autoPrefix;		// +32.
    WORD  prefix1;			// +34.
    WORD  prefix2;			// +36.
    WORD  prefix3;			// +38.
    WORD  suffix1;			// +3A.
    WORD  suffix2;			// +3C.
    WORD  suffix3;			// +3E.
    BYTE  bodyLoc;			// +40.
    BYTE  inPage;			// +41.
    BYTE  unknown3[3];		// +42
    BYTE  picture[8];		// +45
    DWORD ilvl;				// +4C
*/
};

struct MissilesData
{
/*
+04 flags
+08 0 on start
+0c -1 on start
+20 nDirection
+28 range?
+2c range?
+30 level
+34 number of pierces (byte)
+35 (byte)
+36 (byte)
+37 (byte)
+38 range-activate */
};

struct D2Game
{
	BYTE	unknown_0[0x18];
	DWORD	_ptLock	;			// +18 Unknown
	DWORD	MemoryPool;			// +1C Memory Pool (??)
	BYTE	unknown_1[0x4D];
	BYTE	Difficulty;			// +6D Difficulty 0,1,2
	WORD	unknown_2;			// +6E Cube puts 4 here
	DWORD	LODFlage;			// +70 0 = Normal, 1 = LOD
//	Unit*	ptCubeUnit;			// +70 Cube puts the ptUnit of itself here
	DWORD	unknown_3;			// +74 0 at start
	DWORD	unknown_4;			// +78
	DWORD	unknown_5;			// +7C
	DWORD	unknown_6;			// +80
	DWORD	unknown_7;			// +84
	void*	ptClient;			// +88 ptClient
};

struct Client
{
	DWORD	ClientNbr;			// +000 Client #
	DWORD	ConnectionState;	// +004 Connection State (4 = connected)
	DWORD	unknown_1;			// +008
	BYTE	unknown_2;			// +00C
	char	CharName[0x10];		// +00D PlayerName
	BYTE	unknown_3[0x157];	// +01D
	Unit*	ptPlayer;			// +174 ptPlayer this Client Belongs To
};

/*=================================================================*/
/*   Item Location Structure.                                     */
/*=================================================================*/

struct LocInfo
{                       //Offset from Code
/*
    DWORD noneLoc;      //+00
    DWORD headLoc;      //+04
    DWORD neckLoc;      //+08
    DWORD torsoLoc;     //+0c
    DWORD rightArmLoc;  //+10
    DWORD leftArmLoc;   //+14
    DWORD rightRingLoc; //+18
    DWORD leftRingLoc;  //+1c
    DWORD beltLoc;      //+20
    DWORD feetLoc;      //+24
    DWORD glovesLoc;    //+28
*/
};

/*=================================================================*/
/*   Inventory Node Structure.                                     */
/*=================================================================*/

struct Node
{                   //Offset from Code.
/*
    DWORD null;     //+00
    ItemData* pItem;    //+04
    DWORD unID;     //+08
    DWORD page;     //+0c
    Node* nextNode; //+10
*/
};

/*=================================================================*/
/*   Inventory Structure.                                          */
/*=================================================================*/

struct Inventory
{                               //Offset from Code.
    DWORD		nIdentifier;	//+00 1020304
    DWORD		unknown_1;		//+04 ptGame + 1C
	Unit*		ptUnit;			//+08 ptUnit
	DWORD		unknown_2;		//+0C
	DWORD		unknown_3;		//+10
	DWORD		unknown_4;		//+14
	DWORD		unknown_5;		//+18
	DWORD		unknown_6;		//+1C
	DWORD		unknown_7;		//+20
	DWORD		nUnitUnid;		//+24 Unit unid
};

/*=================================================================*/
/*  Skill Structure.                                               */
/*=================================================================*/

struct Skills
{
							//Offset from Code.
    D2SkillsTXT*  skillTxt;	//+00
    Skills* pNextSkill;     //+04
    DWORD   mode;           //+08
    DWORD   unknown1[3];    //+0C
    DWORD   targetInfo;     //+18
    DWORD   targetType;     //+1c
    DWORD   targetUNID;     //+20
    DWORD   unknown2;       //+24
    DWORD   slvl;           //+28
    DWORD   slvlBonus;      //+2c
    DWORD   unknown3;       //+30
    DWORD   state;          //+34
};

/*=================================================================*/
/*  Skills Info Structure.                                         */
/*=================================================================*/

struct D2Info
{								//Offset from Code.
	DWORD		unknown_1;		// +00 ptGame + 1C
/*
    DWORD   gameRelated;    //+00
    Skills* ptSkill;        //+04
    Skills* ptLeftSkill;    //+08
    Skills* ptRightSkill;   //+0c
    Skills* ptCurrentSkill; //+10
*/
};

struct StatsList
{
	DWORD		unknow_1;		//+00
	DWORD		unknow_2;		//+04
	DWORD		unknow_3;		//+08
	DWORD		unknow_4;		//+0C
	DWORD		Charges;		//+10
	DWORD		unknow_6;		//+14
	DWORD		unknow_7;		//+18
	DWORD		unknow_8;		//+20
	Stats*		ptStats[80];	//+24 ptStats
	DWORD		nStatCount;		//+28 nStatCount
	DWORD		nStatCount1;	//+2A Unknown
};

struct Stats
{
	WORD		nStatIndex;		//+00
	WORD		nStatID;		//+02
	WORD		nStatValue;		//+04
};

struct Combat
{
/*
	DWORD mHeader;		// +00 : Always 0x32
	DWORD mDisplayFlag;	// +04 : Affect critical hit etc ...
	DWORD mPhysicalDmg; // +08 : Values are << 8
	DWORD mUnknown1;    // +0C
	DWORD mFireDmg;		// +10 : Values are << 8
	DWORD mUnknown2;    // +14


18h - Burning length, puts some fire overlay on enemies
1Ch - Lightning damage, shifted left 8 bits
20h - Magic damage, shifted left 8 bits
24h - Cold damage, shifted left 8 bits
28h - Poison damage, wierd as hell, not sure of the calculation
2Ch - Poison length, in frames maybe??
30h - Cold duration, in frames maybe??
34h - Freeze duration, in frames maybe??
38h - Life stolen, not sure if absolute or a percent
3Ch - Mana stolen, not sure if absolute or a percent
40h - Unknown
44h - Stun duration, in frames maybe??
48h - Unknown
4Ch - Total damage (physical + all elemental), doesn't seem to do anything
50h - Unknown
54h - Unknown
58h - Unknown
5Ch - Unknown
60h - Unknown
64h - Unknown
68h - Overlay
6Ch - Unknown, always 7h??
*/

};

/*=================================================================*/
/*   Data Structure to Update Client                               */
/*=================================================================*/
struct DataPacket
{
	BYTE mType;			// +00 Packet Type
	BYTE mFunc;			// +02 Function to Call
	BYTE mSize;			// +04 Size of the Packet
	DWORD mReserved;	// +06 Used with items
	BYTE mUnitType;		// +0A Always '0'
	DWORD mPlayerID;	// +0C The Player ID (ptUnit + 08h)
	DWORD mItemID;		// +10 The Item ID
	DWORD mMod1_ID;		// +14 The Stat/Mod ID
	DWORD mParam1;		// +18 3 Paramters
	DWORD mParam2;		// +1C
	DWORD mParam3;		// +20
};

/*=================================================================*/
/*   Data Structure to Add Mods to Items                           */
/*=================================================================*/
struct ItemMod
{
	DWORD mID;			// +00 Mod ID, get it from properties.txt
	DWORD mParam;		// +04 First Property
	DWORD mMinimum;		// +08 Second Property, Min Value
	DWORD mMaximum;		// +0C Third Property, Max Value
};

/*=================================================================*/
/*   Data Structure for shrines			                           */
/*=================================================================*/
struct StateEffect
{
	Unit* ptSource;		// +00
	Unit* ptTarget;		// +04
	DWORD skillID;		// +08
	DWORD skillSLVL;	// +0C
	DWORD duration;		// +10
	DWORD StatID;		// +14
	DWORD StatValue;	// +18
	DWORD StateID;		// +1C
	DWORD EndOffset;	// +20
};

/*=================================================================*/
/*   Data Structure for menus			                           */
/*=================================================================*/
struct Menu
{
};

/*=================================================================*/
/*   Data Structure for Cube Input and Output                      */
/*=================================================================*/

struct CubeInput
{
	BYTE	Flag1;			// +00	Flags
	BYTE	Flag2;			// +01	Flags
	WORD	ID;				// +02	ItemNbr, ItemType
	WORD	unknown;		// +04
	BYTE	Quality;		// +06	Item Quality
	BYTE	Quantity;		// +07	Quantity
};

struct CubeOutput
{
	BYTE	Flag1;			// +00 Flags
	BYTE	Flag2;			// +01 Flags
	WORD	ID;				// +02 ItemNbr
	WORD	unknown1;		// +04
	BYTE	Quality;		// +06 Item Quality
	BYTE	Quantity;		// +07 Quantity
	BYTE	OutputItem;		// +08 Flag to show what to Output
	BYTE	unused[3];		// +09 Overwritten in cube
	WORD	Prefix;			// +0C Prefix to Add to item
	DWORD	unknown2;		// +0E
	WORD	Suffix;			// +12 Suffix to Add to item
	DWORD	unknown3;		// +14
};

/*=================================================================*/
/*   Data Structure for objects			                           */
/*=================================================================*/

struct Operate
{
	D2Game*		ptGame;		//+00
	Unit*		ptObject;	//+04
	Unit*		ptPlayer;	//+08
	void*		ptUnknown;	//+0C	ptGame + 0x10F0
	DWORD		nObjectID;	//+10
};

/*=================================================================*/
/*   Data Structure for NPC menus		                           */
/*=================================================================*/
#pragma pack(1)
struct NpcMenuData
{
	DWORD		NpcID;				//+00
	DWORD		NbrMenuItems;		//+04
	WORD		MenuItemTxt[5];		//+08
	DWORD		MenuItemFunc[5];	//+12
	BYTE		Unknown;			//+26
};
#pragma pack()

/*=================================================================*/
/*   Data Structure for Vendor screens							   */
/*=================================================================*/
struct VLItems
{
	BYTE		VendorMin;			//+00
	BYTE		VendorMax;			//+01
	BYTE		VendorMagicMin;		//+02
	BYTE		VendorMagicMax;		//+03
	DWORD		ItemCode;			//+04
	DWORD		VendorMagicLvl;		//+08
};

struct VendorLst
{
	VLItems*	LimitItems;			//+00
	DWORD		LimitCount;			//+04
	DWORD*		PermItems;			//+08
	DWORD		PermCount;			//+0C
};


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
/*    TXT tables.                                                  */
/*=================================================================*/

struct D2DataTables
{
	BYTE	unknown1[0x0C0C];
	DWORD*	D2Sets;				// +0C0C Sets.txt
	DWORD	D2SetsCount;		// +0C10
	DWORD	unknown2;			// +0C14
	DWORD*	D2SetItems;			// +0C18 SetItems.txt
	DWORD	D2SetItemsCOunt;	// +0C1C
};

struct D2SkillsTXT
{
	WORD	SkillID;			//+00
	BYTE	Mask1;				//+02
	BYTE	Mask2;				//+03
	BYTE	Unknown[8];			//+04
	BYTE	CharClass;			//+0C
	BYTE	unknown_1[0x169];	//+0D
	WORD    strReq;             //+176
    WORD    dexReq;             //+178
    WORD    vitReq;             //+17A
	WORD    eneReq;             //+17C
    BYTE	unknown_2[0x16];	//+17E
	WORD	SkillDesc;			//+194
	BYTE	unknown_3[0xA6];	//+196
};

struct D2SkillDescTXT
{
	BYTE	unknown_1[0x08];	//+00
	WORD	SkillName;			//+08
	BYTE	unknown[0x116];		//+00
};

struct D2BooksTXT
{
	WORD	Name_Unused;		//+00
	WORD	SkillIcon;			//+02
	DWORD	pSpell;				//+04
	DWORD	ScrollSkill;		//+08
	DWORD	BookSkill;			//+0C
	DWORD	BaseCost;			//+10
	DWORD	CostPerCharge;		//+14
	DWORD	ScrollSpellCode;	//+18
	DWORD	BookSpellCode;		//+1C
};

struct D2ItemsTXT
{
	char	FlippyFile[0x20];		//+00
	char	InvFile[0x20];			//+20
	char	UniqueInvFile[0x20];	//+40
	char	SetInvFile[0x20];		//+60
	DWORD	ItemCode;				//+80
	DWORD	NormCode;				//+84
	DWORD	UberCode;				//+88
	DWORD	HellCode;				//+8C
	DWORD	AlternateGfx;			//+90
	DWORD	pSpell;					//+94
	WORD	State;					//+98
	WORD	cState1;				//+9A
	WORD	cState2;				//+9C
	WORD	Stat1;					//+9E
	WORD	Stat2;					//+A0
	WORD	Stat3;					//+A2
	DWORD	Calc1;					//+A4
	DWORD	Calc2;					//+A8
	DWORD	Calc3;					//+AC
	DWORD	Len;					//+B0
	WORD	SpellDesc;				//+B4
	WORD	SpellDescStr;			//+B6
	DWORD	SpellDescCalc;			//+B8
	DWORD	BetterGem;				//+BC
	DWORD	WClass;					//+C0
	DWORD	TwoHandedWClass;		//+C4
	DWORD	TMogType;				//+C8
	DWORD	MinAC;					//+CC
	DWORD	MaxAC;					//+D0
	DWORD	GambleCost;				//+D4
	DWORD	Speed;					//+D8
	DWORD	BitField;				//+DC
	DWORD	Cost;					//+E0
	DWORD	MinStack;				//+E4
	DWORD	MaxStack;				//+E8
	DWORD	SpawnStack;				//+EC
	DWORD	GemOffset;				//+F0
	WORD	NameStr;				//+F4
	WORD	Version;				//+F6
	WORD	AutoPrefix;				//+F8
	WORD	MissileType;			//+FA
	BYTE	Rarity;					//+FC
	BYTE	Level;					//+FD
	BYTE	MinDam;					//+FE
	BYTE	MaxDam;					//+FF
	BYTE	MinMisDam;				//+100
	BYTE	MaxMisDam;				//+101
	BYTE	TwoHandMinDam;			//+102
	BYTE	TwoHandMaxDam;			//+103
	BYTE	RangeAdder;				//+104
	BYTE	NotUsed1;				//+105
	WORD	StrBonus;				//+106
	WORD	DexBonus;				//+108
	WORD	RegStr;					//+10A
	WORD	RegDex;					//+10C
	BYTE	Absorbs;				//+10E
	BYTE	InvWidth;				//+10F
	BYTE	InvHeight;				//+110
	BYTE	Block;					//+111
	BYTE	Durability;				//+112
	BYTE	NoDurability;			//+113
	BYTE	Missile;				//+114
	BYTE	Component;				//+115
	BYTE	RArm;					//+116
	BYTE	LArm;					//+117
	BYTE	Torso;					//+118
	BYTE	Legs;					//+119
	BYTE	RSpad;					//+11A
	BYTE	LSpad;					//+11B
	BYTE	TwoHanded;				//+11C
	BYTE	Usable;					//+11D
	WORD	Type;					//+11E
	WORD	Type2;					//+120
	BYTE	SubType;				//+122
	BYTE	NotUsed2;				//+123
	WORD	DropSound;				//+124
	WORD	UseSound;				//+126
	BYTE	DropSfxFrame;			//+128
	BYTE	Unique;					//+129
	BYTE	Quest;					//+12A
	BYTE	QuestDiffCheck;			//+12B
	BYTE	Transparent;			//+12C
	BYTE	TransTbl;				//+12D
	BYTE	NotUsed3;				//+12E
	BYTE	LightRadius;			//+12F
	BYTE	Belt;					//+130
	BYTE	AutoBelt;				//+131
	BYTE	Stackable;				//+132
	BYTE	Spawnable;				//+133
	BYTE	SpellIcon;				//+134
	BYTE	DurWarning;				//+135
	BYTE	QntWaning;				//+136
	BYTE	HasInv;					//+137
	BYTE	GemSockets;				//+138
	BYTE	TransmoGrify;			//+139
	BYTE	TMogMin;				//+13A
	BYTE	TMogMax;				//+13B
	BYTE	HitClass;				//+13C
	BYTE	OneOrTwoHanded;			//+13D
	BYTE	GemApplyType;			//+13E
	BYTE	LevelReq;				//+13F
	BYTE	MagicLvl;				//+140
	BYTE	Transform;				//+141
	BYTE	InvTrans;				//+142
	BYTE	CompactSave;			//+143
	BYTE	SkipName;				//+144
	BYTE	NotUsed4;				//+145
	BYTE	VendorMin[17];			//+146
	BYTE	VendorMax[17];			//+157
	BYTE	VendorMagicMin[17];		//+168
	BYTE	VendorMagicMax[17];		//+179
	BYTE	VendorMagicLvl[17];		//+18A
	BYTE	NotUsed5;				//+19B
	DWORD	NightmareUpgrade;		//+19C
	DWORD	HellUpgrade;			//+1A0
	BYTE	PermStoreItem;			//+1A4
	BYTE	Multibuy;				//+1A5
};

#pragma pack(1)
struct D2RunesTXT
{
	char	Name[0x40];				//+00
	char	RuneName[0x40];			//+40
	BYTE	Complete;				//+80
	BYTE	Server;					//+81
	BYTE	Unknown[4];				//+82
	WORD	Itypes[6];				//+86
	WORD	Etypes[3];				//+92
	int		Runes[6];				//+98
	DWORD	t1code1;				//+B0
	DWORD	t1param1;				//+B4
	DWORD	t1min1;					//+B8
	DWORD	t1max1;					//+BC
	DWORD	t1code2;				//+C0
	DWORD	t1param2;				//+C4
	DWORD	t1min2;					//+C8
	DWORD	t1max2;					//+CC
	DWORD	t1code3;				//+D0
	DWORD	t1param3;				//+D4
	DWORD	t1min3;					//+D8
	DWORD	t1max3;					//+DC
	DWORD	t1code4;				//+E0
	DWORD	t1param4;				//+E4
	DWORD	t1min4;					//+E8
	DWORD	t1max4;					//+EC
	DWORD	t1code5;				//+F0
	DWORD	t1param5;				//+F4
	DWORD	t1min5;					//+F8
	DWORD	t1max5;					//+FC
	DWORD	t1code6;				//+100
	DWORD	t1param6;				//+104
	DWORD	t1min6;					//+108
	DWORD	t1max6;					//+10C
	DWORD	t1code7;				//+110
	DWORD	t1param7;				//+114
	DWORD	t1min7;					//+118
	DWORD	t1max7;					//+11C
	// Custom Added
	BYTE	quality;				//+120
};
#pragma pack()

struct D2RuneStruct
{
	int			nNbrOfRuneWords;
	D2RunesTXT*	ptRunes;
};



/*=================================================================*/
/*    Pointer Defintions                                           */
/*=================================================================*/

#define LPGAME      D2Game* 
#define LPUNIT      Unit*	    
#define LPPLAYER    Unit*	    
#define LPSKILL     D2SkillsTXT*




// ----------------------------------------------------------------------------

#endif