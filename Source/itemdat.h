/**
 * @file itemdat.h
 *
 * Interface of all item data.
 */
#ifndef __ITEMDAT_H__
#define __ITEMDAT_H__

DEVILUTION_BEGIN_NAMESPACE

#ifdef __cplusplus
extern "C" {
#endif

typedef enum item_drop_rate {
	IDROP_NEVER,
	IDROP_REGULAR,
	IDROP_DOUBLE,
} item_drop_rate;

typedef enum item_class {
	ICLASS_NONE,
	ICLASS_WEAPON,
	ICLASS_ARMOR,
	ICLASS_MISC,
	ICLASS_GOLD,
	ICLASS_QUEST,
} item_class;

typedef enum item_equip_type {
	ILOC_NONE,
	ILOC_ONEHAND,
	ILOC_TWOHAND,
	ILOC_ARMOR,
	ILOC_HELM,
	ILOC_RING,
	ILOC_AMULET,
	ILOC_UNEQUIPABLE,
	ILOC_BELT,
	ILOC_INVALID = -1,
} item_equip_type;

/// Item graphic IDs; frame_num-11 of objcurs.cel.
typedef enum item_cursor_graphic {
	// clang-format off
	ICURS_POTION_OF_FULL_MANA         = 0,
	ICURS_SCROLL_OF                   = 1,
	ICURS_GOLD_SMALL                  = 4,
	ICURS_GOLD_MEDIUM                 = 5,
	ICURS_GOLD_LARGE                  = 6,
	ICURS_RING_OF_TRUTH               = 10,
	ICURS_RING                        = 12,
	ICURS_SPECTRAL_ELIXIR             = 15,
	ICURS_GOLDEN_ELIXIR               = 17,
	ICURS_EMPYREAN_BAND               = 18,
	ICURS_EAR_SORCEROR                = 19,
	ICURS_EAR_WARRIOR                 = 20,
	ICURS_EAR_ROGUE                   = 21,
	ICURS_BLOOD_STONE                 = 25,
	ICURS_OIL                         = 30,
	ICURS_ELIXIR_OF_VITALITY          = 31,
	ICURS_POTION_OF_HEALING           = 32,
	ICURS_POTION_OF_FULL_REJUVENATION = 33,
	ICURS_ELIXIR_OF_MAGIC             = 34,
	ICURS_POTION_OF_FULL_HEALING      = 35,
	ICURS_ELIXIR_OF_DEXTERITY         = 36,
	ICURS_POTION_OF_REJUVENATION      = 37,
	ICURS_ELIXIR_OF_STRENGTH          = 38,
	ICURS_POTION_OF_MANA              = 39,
	ICURS_BRAIN                       = 40,
	ICURS_OPTIC_AMULET                = 44,
	ICURS_AMULET                      = 45,
	ICURS_DAGGER                      = 51,
	ICURS_BLADE                       = 56,
	ICURS_BASTARD_SWORD               = 57,
	ICURS_MACE                        = 59,
	ICURS_LONG_SWORD                  = 60,
	ICURS_BROAD_SWORD                 = 61,
	ICURS_FALCHION                    = 62,
	ICURS_MORNING_STAR                = 63,
	ICURS_SHORT_SWORD                 = 64,
	ICURS_CLAYMORE                    = 65,
	ICURS_CLUB                        = 66,
	ICURS_SABRE                       = 67,
	ICURS_SPIKED_CLUB                 = 70,
	ICURS_SCIMITAR                    = 72,
	ICURS_FULL_HELM                   = 75,
	ICURS_MAGIC_ROCK                  = 76,
	ICURS_THE_UNDEAD_CROWN            = 78,
	ICURS_HELM                        = 82,
	ICURS_BUCKLER                     = 83,
	ICURS_VIEL_OF_STEEL               = 85,
	ICURS_BOOK_GREY                   = 86,
	ICURS_BOOK_RED                    = 87,
	ICURS_BOOK_BLUE                   = 88,
	ICURS_BLACK_MUSHROOM              = 89,
	ICURS_SKULL_CAP                   = 90,
	ICURS_CAP                         = 91,
	ICURS_HARLEQUIN_CREST             = 93,
	ICURS_CROWN                       = 95,
	ICURS_MAP_OF_THE_STARS            = 96,
	ICURS_FUNGAL_TOME                 = 97,
	ICURS_GREAT_HELM                  = 98,
	ICURS_BATTLE_AXE                  = 101,
	ICURS_HUNTERS_BOW                 = 102,
	ICURS_FIELD_PLATE                 = 103,
	ICURS_SMALL_SHIELD                = 105,
	ICURS_CLEAVER                     = 106,
	ICURS_STUDDED_LEATHER_ARMOR       = 107,
	ICURS_SHORT_STAFF                 = 109,
	ICURS_TWO_HANDED_SWORD            = 110,
	ICURS_CHAIN_MAIL                  = 111,
	ICURS_SMALL_AXE                   = 112,
	ICURS_KITE_SHIELD                 = 113,
	ICURS_SCALE_MAIL                  = 114,
	ICURS_SHORT_BOW                   = 118,
	ICURS_LONG_WAR_BOW                = 119,
	ICURS_WAR_HAMMER                  = 121,
	ICURS_MAUL                        = 122,
	ICURS_LONG_STAFF                  = 123,
	ICURS_WAR_STAFF                   = 124,
	ICURS_TAVERN_SIGN                 = 126,
	ICURS_HARD_LEATHER_ARMOR          = 127,
	ICURS_RAGS                        = 128,
	ICURS_QUILTED_ARMOR               = 129,
	ICURS_FLAIL                       = 131,
	ICURS_TOWER_SHIELD                = 132,
	ICURS_COMPOSITE_BOW               = 133,
	ICURS_GREAT_SWORD                 = 134,
	ICURS_LEATHER_ARMOR               = 135,
	ICURS_SPLINT_MAIL                 = 136,
	ICURS_ROBE                        = 137,
	ICURS_ANVIL_OF_FURY               = 140,
	ICURS_BROAD_AXE                   = 141,
	ICURS_LARGE_AXE                   = 142,
	ICURS_GREAT_AXE                   = 143,
	ICURS_AXE                         = 144,
	ICURS_LARGE_SHIELD                = 147,
	ICURS_GOTHIC_SHIELD               = 148,
	ICURS_CLOAK                       = 149,
	ICURS_CAPE                        = 150,
	ICURS_FULL_PLATE_MAIL             = 151,
	ICURS_GOTHIC_PLATE                = 152,
	ICURS_BREAST_PLATE                = 153,
	ICURS_RING_MAIL                   = 154,
	ICURS_STAFF_OF_LAZARUS            = 155,
	ICURS_ARKAINES_VALOR              = 157,
	ICURS_SHORT_WAR_BOW               = 165,
	ICURS_COMPOSITE_STAFF             = 166,
	ICURS_SHORT_BATTLE_BOW            = 167,
	ICURS_GOLD                        = 168,
	ICURS_AURIC_AMULET                = 180,
	ICURS_RUNE_BOMB                   = 187,
	ICURS_THEODORE                    = 188,
	ICURS_TORN_NOTE_1                 = 189,
	ICURS_TORN_NOTE_2                 = 190,
	ICURS_TORN_NOTE_3                 = 191,
	ICURS_RECONSTRUCTED_NOTE          = 192,
	ICURS_RUNE_OF_FIRE                = 193,
	ICURS_GREATER_RUNE_OF_FIRE        = 194,
	ICURS_RUNE_OF_LIGHTNING           = 195,
	ICURS_GREATER_RUNE_OF_LIGHTNING   = 196,
	ICURS_RUNE_OF_STONE               = 197,
	ICURS_GREY_SUIT                   = 198,
	ICURS_BROWN_SUIT                  = 199,
	ICURS_BOVINE                      = 226,
	// clang-format on
} item_cursor_graphic;

typedef enum item_type {
	ITYPE_MISC,
	ITYPE_SWORD,
	ITYPE_AXE,
	ITYPE_BOW,
	ITYPE_MACE,
	ITYPE_SHIELD,
	ITYPE_LARMOR,
	ITYPE_HELM,
	ITYPE_MARMOR,
	ITYPE_HARMOR,
	ITYPE_STAFF,
	ITYPE_GOLD,
	ITYPE_RING,
	ITYPE_AMULET,
	ITYPE_FOOD, /* used in demo */
	ITYPE_NONE = -1,
} item_type;

typedef enum unique_base_item {
	UITYPE_NONE,
	UITYPE_SHORTBOW,
	UITYPE_LONGBOW,
	UITYPE_HUNTBOW,
	UITYPE_COMPBOW,
	UITYPE_WARBOW,
	UITYPE_BATTLEBOW,
	UITYPE_DAGGER,
	UITYPE_FALCHION,
	UITYPE_CLAYMORE,
	UITYPE_BROADSWR,
	UITYPE_SABRE,
	UITYPE_SCIMITAR,
	UITYPE_LONGSWR,
	UITYPE_BASTARDSWR,
	UITYPE_TWOHANDSWR,
	UITYPE_GREATSWR,
	UITYPE_CLEAVER,
	UITYPE_LARGEAXE,
	UITYPE_BROADAXE,
	UITYPE_SMALLAXE,
	UITYPE_BATTLEAXE,
	UITYPE_GREATAXE,
	UITYPE_MACE,
	UITYPE_MORNSTAR,
	UITYPE_SPIKCLUB,
	UITYPE_MAUL,
	UITYPE_WARHAMMER,
	UITYPE_FLAIL,
	UITYPE_LONGSTAFF,
	UITYPE_SHORTSTAFF,
	UITYPE_COMPSTAFF,
	UITYPE_QUARSTAFF,
	UITYPE_WARSTAFF,
	UITYPE_SKULLCAP,
	UITYPE_HELM,
	UITYPE_GREATHELM,
	UITYPE_CROWN,
	UITYPE_38,
	UITYPE_RAGS,
	UITYPE_STUDARMOR,
	UITYPE_CLOAK,
	UITYPE_ROBE,
	UITYPE_CHAINMAIL,
	UITYPE_LEATHARMOR,
	UITYPE_BREASTPLATE,
	UITYPE_CAPE,
	UITYPE_PLATEMAIL,
	UITYPE_FULLPLATE,
	UITYPE_BUCKLER,
	UITYPE_SMALLSHIELD,
	UITYPE_LARGESHIELD,
	UITYPE_KITESHIELD,
	UITYPE_GOTHSHIELD,
	UITYPE_RING,
	UITYPE_55,
	UITYPE_AMULET,
	UITYPE_SKCROWN,
	UITYPE_INFRARING,
	UITYPE_OPTAMULET,
	UITYPE_TRING,
	UITYPE_HARCREST,
	UITYPE_MAPOFDOOM,
	UITYPE_ELIXIR,
	UITYPE_ARMOFVAL,
	UITYPE_STEELVEIL,
	UITYPE_GRISWOLD,
	UITYPE_LGTFORGE,
	UITYPE_LAZSTAFF,
	UITYPE_BOVINE,
	UITYPE_INVALID = -1,
} unique_base_item;

typedef enum item_special_effect {
	// clang-format off
	ISPL_NONE           = 0x00000000,
	ISPL_INFRAVISION    = 0x00000001,
	ISPL_RNDSTEALLIFE   = 0x00000002,
	ISPL_RNDARROWVEL    = 0x00000004,
	ISPL_FIRE_ARROWS    = 0x00000008,
	ISPL_FIREDAM        = 0x00000010,
	ISPL_LIGHTDAM       = 0x00000020,
	ISPL_DRAINLIFE      = 0x00000040,
	ISPL_UNKNOWN_1      = 0x00000080,
	ISPL_NOHEALPLR      = 0x00000100,
	ISPL_MULT_ARROWS    = 0x00000200,
	ISPL_UNKNOWN_3      = 0x00000400,
	ISPL_KNOCKBACK      = 0x00000800,
	ISPL_NOHEALMON      = 0x00001000,
	ISPL_STEALMANA_3    = 0x00002000,
	ISPL_STEALMANA_5    = 0x00004000,
	ISPL_STEALLIFE_3    = 0x00008000,
	ISPL_STEALLIFE_5    = 0x00010000,
	ISPL_QUICKATTACK    = 0x00020000,
	ISPL_FASTATTACK     = 0x00040000,
	ISPL_FASTERATTACK   = 0x00080000,
	ISPL_FASTESTATTACK  = 0x00100000,
	ISPL_FASTRECOVER    = 0x00200000,
	ISPL_FASTERRECOVER  = 0x00400000,
	ISPL_FASTESTRECOVER = 0x00800000,
	ISPL_FASTBLOCK      = 0x01000000,
	ISPL_LIGHT_ARROWS   = 0x02000000,
	ISPL_THORNS         = 0x04000000,
	ISPL_NOMANA         = 0x08000000,
	ISPL_ABSHALFTRAP    = 0x10000000,
	ISPL_UNKNOWN_4      = 0x20000000,
	ISPL_3XDAMVDEM      = 0x40000000,
	ISPL_ALLRESZERO     = 0x80000000,
	// clang-format on
} item_special_effect;

typedef enum item_misc_id {
	IMISC_NONE,
	IMISC_USEFIRST,
	IMISC_FULLHEAL,
	IMISC_HEAL,
	IMISC_OLDHEAL,
	IMISC_DEADHEAL,
	IMISC_MANA,
	IMISC_FULLMANA,
	IMISC_POTEXP,  /* add experience */
	IMISC_POTFORG, /* remove experience */
	IMISC_ELIXSTR,
	IMISC_ELIXMAG,
	IMISC_ELIXDEX,
	IMISC_ELIXVIT,
	IMISC_ELIXWEAK, /* double check with alpha */
	IMISC_ELIXDIS,
	IMISC_ELIXCLUM,
	IMISC_ELIXSICK,
	IMISC_REJUV,
	IMISC_FULLREJUV,
	IMISC_USELAST,
	IMISC_SCROLL,
	IMISC_SCROLLT,
	IMISC_STAFF,
	IMISC_BOOK,
	IMISC_RING,
	IMISC_AMULET,
	IMISC_UNIQUE,
	IMISC_FOOD, /* from demo/PSX */
	IMISC_OILFIRST,
	IMISC_OILOF, /* oils are beta or hellfire only */
	IMISC_OILACC,
	IMISC_OILMAST,
	IMISC_OILSHARP,
	IMISC_OILDEATH,
	IMISC_OILSKILL,
	IMISC_OILBSMTH,
	IMISC_OILFORT,
	IMISC_OILPERM,
	IMISC_OILHARD,
	IMISC_OILIMP,
	IMISC_OILLAST,
	IMISC_MAPOFDOOM,
	IMISC_EAR,
	IMISC_SPECELIX,
	IMISC_0x2D, // Unknown
	IMISC_RUNEFIRST,
	IMISC_RUNEF,
	IMISC_RUNEL,
	IMISC_GR_RUNEL,
	IMISC_GR_RUNEF,
	IMISC_RUNES,
	IMISC_RUNELAST,
	IMISC_AURIC,
	IMISC_NOTE,
	IMISC_INVALID = -1,
} item_misc_id;

typedef struct ItemDataStruct {
	enum item_drop_rate iRnd;
	enum item_class iClass;
	enum item_equip_type iLoc;
	enum item_cursor_graphic iCurs;
	enum item_type itype;
	enum unique_base_item iItemId;
	const char *iName;
	const char *iSName;
	Sint8 iMinMLvl;
	Sint32 iDurability;
	Sint32 iMinDam;
	Sint32 iMaxDam;
	Sint32 iMinAC;
	Sint32 iMaxAC;
	Sint8 iMinStr;
	Sint8 iMinMag;
	Sint8 iMinDex;
	Sint32 iFlags; // item_special_effect as bit flags
	enum item_misc_id iMiscId;
	enum spell_id iSpell;
	BOOL iUsable;
	Sint32 iValue;
	Sint32 iMaxValue;
} ItemDataStruct;

typedef enum item_effect_type {
	IPL_TOHIT,
	IPL_TOHIT_CURSE,
	IPL_DAMP,
	IPL_DAMP_CURSE,
	IPL_TOHIT_DAMP,
	IPL_TOHIT_DAMP_CURSE,
	IPL_ACP,
	IPL_ACP_CURSE,
	IPL_FIRERES,
	IPL_LIGHTRES,
	IPL_MAGICRES,
	IPL_ALLRES,
	IPL_SPLCOST, /* only used in beta */
	IPL_SPLDUR,  /* only used in beta */
	IPL_SPLLVLADD,
	IPL_CHARGES,
	IPL_FIREDAM,
	IPL_LIGHTDAM,
	IPL_0x12, // Unknown
	IPL_STR,
	IPL_STR_CURSE,
	IPL_MAG,
	IPL_MAG_CURSE,
	IPL_DEX,
	IPL_DEX_CURSE,
	IPL_VIT,
	IPL_VIT_CURSE,
	IPL_ATTRIBS,
	IPL_ATTRIBS_CURSE,
	IPL_GETHIT_CURSE,
	IPL_GETHIT,
	IPL_LIFE,
	IPL_LIFE_CURSE,
	IPL_MANA,
	IPL_MANA_CURSE,
	IPL_DUR,
	IPL_DUR_CURSE,
	IPL_INDESTRUCTIBLE,
	IPL_LIGHT,
	IPL_LIGHT_CURSE,
	IPL_0x28,        // Unknown
	IPL_MULT_ARROWS, /* only used in hellfire */
	IPL_FIRE_ARROWS,
	IPL_LIGHT_ARROWS,
	IPL_INVCURS,
	IPL_THORNS,
	IPL_NOMANA,
	IPL_NOHEALPLR,
	IPL_0x30,     // Unknown
	IPL_0x31,     // Unknown
	IPL_FIREBALL, /* only used in hellfire */
	IPL_0x33,     // Unknown
	IPL_ABSHALFTRAP,
	IPL_KNOCKBACK,
	IPL_NOHEALMON,
	IPL_STEALMANA,
	IPL_STEALLIFE,
	IPL_TARGAC,
	IPL_FASTATTACK,
	IPL_FASTRECOVER,
	IPL_FASTBLOCK,
	IPL_DAMMOD,
	IPL_RNDARROWVEL,
	IPL_SETDAM,
	IPL_SETDUR,
	IPL_NOMINSTR,
	IPL_SPELL,
	IPL_FASTSWING,
	IPL_ONEHAND,
	IPL_3XDAMVDEM,
	IPL_ALLRESZERO,
	IPL_0x47, // Unknown
	IPL_DRAINLIFE,
	IPL_RNDSTEALLIFE,
	IPL_INFRAVISION,
	IPL_SETAC,
	IPL_ADDACLIFE,
	IPL_ADDMANAAC,
	IPL_FIRERESCLVL,
	IPL_AC_CURSE,
	IPL_FIRERES_CURSE,
	IPL_LIGHTRES_CURSE,
	IPL_MAGICRES_CURSE,
	IPL_ALLRES_CURSE,
	IPL_DEVASTATION,
	IPL_DECAY,
	IPL_PERIL,
	IPL_JESTERS,
	IPL_CRYSTALLINE,
	IPL_DOPPELGANGER,
	IPL_ACDEMON,
	IPL_ACUNDEAD,
	IPL_MANATOLIFE,
	IPL_LIFETOMANA,
	IPL_INVALID = -1,
} item_effect_type;

typedef enum goodorevil {
	GOE_ANY,
	GOE_EVIL,
	GOE_GOOD,
} goodorevil;

typedef enum affix_item_type {
	// clang-format off
	PLT_MISC  = 0x000001,
	PLT_BOW   = 0x000010,
	PLT_STAFF = 0x000100,
	PLT_WEAP  = 0x001000,
	PLT_SHLD  = 0x010000,
	PLT_ARMO  = 0x100000,
	// clang-format on
} affix_item_type;

typedef struct PLStruct {
	const char *PLName;
	enum item_effect_type PLPower;
	Sint32 PLParam1;
	Sint32 PLParam2;
	Sint8 PLMinLvl;
	Sint32 PLIType; // affix_item_type as bit flags
	enum goodorevil PLGOE;
	bool PLDouble;
	bool PLOk;
	Sint32 PLMinVal;
	Sint32 PLMaxVal;
	Sint32 PLMultVal;
} PLStruct;

typedef struct UItemStruct {
	const char *UIName;
	enum unique_base_item UIItemId;
	Sint8 UIMinLvl;
	Sint8 UINumPL;
	Sint32 UIValue;
	enum item_effect_type UIPower1;
	Sint32 UIParam1;
	Sint32 UIParam2;
	enum item_effect_type UIPower2;
	Sint32 UIParam3;
	Sint32 UIParam4;
	enum item_effect_type UIPower3;
	Sint32 UIParam5;
	Sint32 UIParam6;
	enum item_effect_type UIPower4;
	Sint32 UIParam7;
	Sint32 UIParam8;
	enum item_effect_type UIPower5;
	Sint32 UIParam9;
	Sint32 UIParam10;
	enum item_effect_type UIPower6;
	Sint32 UIParam11;
	Sint32 UIParam12;
} UItemStruct;

extern ItemDataStruct AllItemsList[];
extern const PLStruct PL_Prefix[];
extern const PLStruct PL_Suffix[];
extern const UItemStruct UniqueItemList[];

#ifdef __cplusplus
}
#endif

DEVILUTION_END_NAMESPACE

#endif /* __ITEMDAT_H__ */
