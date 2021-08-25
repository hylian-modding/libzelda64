#ifndef SAVECONTEXT_TYPE_H
#define SAVECONTEXT_TYPE_H

#include "../zelda64_version.h"
#include "FaroresWindData.h"
#include "HorseData.h"
#include "Inventory.h"
#include "ItemEquips.h"
#include "RespawnData.h"
#include "SavedSceneFlags.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct SaveContext {
    /* 0x0000 */ int32_t entranceIndex; // start of `save` substruct, originally called "memory"
    /* 0x0004 */ int32_t linkAge;       // 0: Adult; 1: Child
    /* 0x0008 */ int32_t cutsceneIndex;
    /* 0x000C */ uint16_t dayTime; // "zelda_time"
    /* 0x0010 */ int32_t nightFlag;
    /* 0x0014 */ int32_t numDays;
    /* 0x0018 */ int32_t unk_18; // increments with numDays, gets reset by goron for bgs and one other use
    /* 0x001C */ char newf[6];   // string "ZELDAZ". start of `info` substruct, originally called "information"
    /* 0x0022 */ uint16_t deaths;
    /* 0x0024 */ char playerName[8];
    /* 0x002C */ int16_t n64ddFlag;
    /* 0x002E */ int16_t healthCapacity; // "max_life"
    /* 0x0030 */ int16_t health;         // "now_life"
    /* 0x0032 */ int8_t magicLevel;
    /* 0x0033 */ int8_t magic;
    /* 0x0034 */ int16_t rupees;
    /* 0x0036 */ uint16_t swordHealth;
    /* 0x0038 */ uint16_t naviTimer;
    /* 0x003A */ uint8_t magicAcquired;
    /* 0x003B */ char unk_3B[0x01];
    /* 0x003C */ uint8_t doubleMagic;
    /* 0x003D */ uint8_t doubleDefense;
    /* 0x003E */ uint8_t bgsFlag;
    /* 0x003F */ uint8_t ocarinaGameReward;
    /* 0x0040 */ ItemEquips childEquips;
    /* 0x004A */ ItemEquips adultEquips;
    /* 0x0054 */ uint32_t unk_54; // this may be incorrect, currently used for alignement
    /* 0x0058 */ char unk_58[0x0E];
    /* 0x0066 */ int16_t savedSceneNum;
    /* 0x0068 */ ItemEquips equips;
    /* 0x0074 */ Inventory inventory;
    /* 0x00D4 */ SavedSceneFlags sceneFlags[124];
    /* 0x0E64 */ FaroresWindData fw;
    /* 0x0E8C */ char unk_E8C[0x10];
    /* 0x0E9C */ int32_t gsFlags[6];
    /* 0x0EB4 */ char unk_EB4[0x4];
    /* 0x0EB8 */ int32_t highScores[7];
    /* 0x0ED4 */ uint16_t eventChkInf[14]; // "event_chk_inf"
    /* 0x0EF0 */ uint16_t itemGetInf[4];   // "item_get_inf"
    /* 0x0EF8 */ uint16_t infTable[30];    // "inf_table"
    /* 0x0F34 */ char unk_F34[0x04];
    /* 0x0F38 */ uint32_t worldMapAreaData; // "area_arrival"
    /* 0x0F3C */ char unk_F3C[0x4];
    /* 0x0F40 */ uint8_t scarecrowCustomSongSet;
    /* 0x0F41 */ uint8_t scarecrowCustomSong[0x360];
    /* 0x12A1 */ char unk_12A1[0x24];
    /* 0x12C5 */ uint8_t scarecrowSpawnSongSet;
    /* 0x12C6 */ uint8_t scarecrowSpawnSong[0x80];
    /* 0x1346 */ char unk_1346[0x02];
    /* 0x1348 */ HorseData horseData;
    /* 0x1352 */ uint16_t checksum; // "check_sum"
    /* 0x1354 */ int32_t fileNum;   // "file_no"
    /* 0x1358 */ char unk_1358[0x0004];
    /* 0x135C */ int32_t gameMode;
    /* 0x1360 */ int32_t sceneSetupIndex;
    /* 0x1364 */ int32_t respawnFlag;    // "restart_flag"
    /* 0x1368 */ RespawnData respawn[3]; // "restart_data"
    /* 0x13BC */ float entranceSpeed;
    /* 0x13C0 */ uint16_t entranceSound;
    /* 0x13C2 */ char unk_13C2[0x0001];
    /* 0x13C3 */ uint8_t unk_13C3;
    /* 0x13C4 */ int16_t dogParams;
    /* 0x13C6 */ uint8_t textTriggerFlags;
    /* 0x13C7 */ uint8_t showTitleCard;
    /* 0x13C8 */ int16_t nayrusLoveTimer;
    /* 0x13CA */ char unk_13CA[0x0002];
    /* 0x13CC */ int16_t rupeeAccumulator;
    /* 0x13CE */ int16_t timer1State;
    /* 0x13D0 */ int16_t timer1Value;
    /* 0x13D2 */ int16_t timer2State;
    /* 0x13D4 */ int16_t timer2Value;
    /* 0x13D6 */ int16_t timerX[2];
    /* 0x13DA */ int16_t timerY[2];
    /* 0x13DE */ char unk_13DE[0x0002];
    /* 0x13E0 */ uint8_t seqIndex;
    /* 0x13E1 */ uint8_t nightSeqIndex;
    /* 0x13E2 */ uint8_t buttonStatus[5];
    /* 0x13E7 */ uint8_t unk_13E7;     // alpha related
    /* 0x13E8 */ uint16_t unk_13E8;    // alpha type?
    /* 0x13EA */ uint16_t unk_13EA;    // also alpha type?
    /* 0x13EC */ uint16_t unk_13EC;    // alpha type counter?
    /* 0x13EE */ uint16_t unk_13EE;    // previous alpha type?
    /* 0x13F0 */ int16_t unk_13F0;     // magic related
    /* 0x13F2 */ int16_t unk_13F2;     // magic related
    /* 0x13F4 */ int16_t unk_13F4;     // magic related
    /* 0x13F6 */ int16_t unk_13F6;     // magic related
    /* 0x13F8 */ int16_t unk_13F8;     // magic related
    /* 0x13FA */ uint16_t eventInf[4]; // "event_inf"
    /* 0x1402 */ uint16_t mapIndex;    // intended for maps/minimaps but commonly used as the dungeon index
    /* 0x1404 */ uint16_t minigameState;
    /* 0x1406 */ uint16_t minigameScore; // "yabusame_total"
    /* 0x1408 */ char unk_1408[0x0001];
    /* 0x1409 */ uint8_t language;
    /* 0x140A */ uint8_t audioSetting;
    /* 0x140B */ char unk_140B[0x0001];
    /* 0x140C */ uint8_t zTargetSetting; // 0: Switch; 1: Hold
    /* 0x140E */ uint16_t unk_140E;      // bgm related
    /* 0x1410 */ uint8_t unk_1410;       // transition related
    /* 0x1411 */ char unk_1411[0x0001];
    /* 0x1412 */ uint16_t nextCutsceneIndex;
    /* 0x1414 */ uint8_t cutsceneTrigger;
    /* 0x1415 */ uint8_t chamberCutsceneNum;
    /* 0x1416 */ uint16_t nextDayTime; // "next_zelda_time"
    /* 0x1418 */ uint8_t fadeDuration;
    /* 0x1419 */ uint8_t unk_1419; // transition related
    /* 0x141A */ uint16_t environmentTime;
    /* 0x141C */ uint8_t dogIsLost;
    /* 0x141D */ uint8_t nextTransition;
    /* 0x141E */ char unk_141E[0x0002];
    /* 0x1420 */ int16_t worldMapArea;
    /* 0x1422 */ int16_t unk_1422; // day time related
    /* 0x1424 */ int16_t healthAccumulator;
} SaveContext; /* sizeof = 0x1428 */

#else /* GAME_VERSION_1_0 */
#warning "SaveContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct SaveContext {
    /* 0x0000 */ uint32_t entranceIndex; // "scene_no"
    /* 0x0004 */ uint8_t equippedMask;   // "player_mask"
    /* 0x0005 */ uint8_t unk_05;         // "opening_flag"
    /* 0x0006 */ uint8_t unk_06;
    /* 0x0007 */ uint8_t linkAge;  // "link_age"
    /* 0x0008 */ int32_t cutscene; // "day_time"
    /* 0x000C */ uint16_t time;    // "zelda_time"
    /* 0x000E */ uint16_t owlSaveLocation;
    /* 0x0010 */ int32_t isNight;         // "asahiru_fg"
    /* 0x0014 */ uint32_t unk_14;         // "change_zelda_time"
    /* 0x0018 */ int32_t day;             // "totalday"
    /* 0x001C */ uint32_t daysElapsed;    // "eventday"
    /* 0x0020 */ uint8_t playerForm;      // "player_character"
    /* 0x0021 */ uint8_t snowheadCleared; // "spring_flag"
    /* 0x0022 */ uint8_t hasTatl;         // "bell_flag"
    /* 0x0023 */ uint8_t isOwlSave;
    /* 0x0024 */ char newf[6];                // Will always be "ZELDA3" for a valid save
    /* 0x002B */ uint16_t deaths;             // "savect"
    /* 0x002C */ char playerName[8];          // "player_name"
    /* 0x0034 */ int16_t healthCapacity;      // "max_life"
    /* 0x0036 */ int16_t health;              // "now_life"
    /* 0x0038 */ int8_t magicLevel;           // "magic_max"
    /* 0x0039 */ int8_t magic;                // "magic_now"
    /* 0x003A */ int16_t rupees;              // "lupy_count"
    /* 0x003C */ uint16_t swordHealth;        // "long_sword_hp"
    /* 0x003E */ uint16_t naviTimer;          // "navi_timer"
    /* 0x0040 */ uint8_t magicAcquired;       // "magic_mode"
    /* 0x0041 */ uint8_t doubleMagic;         // "magic_ability"
    /* 0x0042 */ uint8_t doubleDefense;       // "life_ability"
    /* 0x0043 */ uint8_t unk_43;              // "ocarina_round"
    /* 0x0044 */ uint8_t unk_44;              // "first_memory"
    /* 0x0046 */ uint16_t owlActivationFlags; // "memory_warp_point"
    /* 0x0048 */ uint8_t unk_48;              // "last_warp_pt"
    /* 0x004A */ int16_t savedSceneNum;       // "scene_data_ID"
    /* 0x004C */ ItemEquips equips;
    /* 0x0070 */ Inventory inventory;
    /* 0x00F8 */ uint32_t roomInf[128][7];
    /* 0x0EF8 */ uint8_t weekEventReg[100];      // "week_event_reg"
    /* 0x0F5C */ uint32_t mapsVisited;           // "area_arrival"
    /* 0x0F60 */ uint32_t unk_F60;               // "cloud_clear"
    /* 0x0F64 */ uint8_t unk_F64;                // "oca_rec_flag"
    /* 0x0F65 */ uint8_t unk_F65;                // "oca_rec_flag8"
    /* 0x0F66 */ uint8_t unk_F66[128];           // "oca_rec_buff8"
    /* 0x0FE6 */ int8_t unk_FE6;                 // "aikotoba_index"
    /* 0x0FE7 */ int8_t unk_FE7[5];              // "aikotoba_table"
    /* 0x0FEC */ int8_t lotteryCodes[3][3];      // "numbers_table"
    /* 0x0FF5 */ int8_t spiderHouseMaskOrder[6]; // "kinsta_color_table"
    /* 0x0FFB */ int8_t bomberCode[5];           // "bombers_aikotoba_table"
    /* 0x1000 */ HorseData horseData;
    /* 0x100A */ uint16_t checksum; // "check_sum"
    /* 0x100C */ uint8_t eventInf[8];
    /* 0x1014 */ uint8_t unk_1014; // "stone_set_flag"
    /* 0x1015 */ uint8_t unk_1015;
    /* 0x1016 */ uint16_t unk_1016;
    /* 0x1018 */ int16_t rupeeAccumulator;  // "lupy_udct"
    /* 0x101A */ uint8_t unk_101A[6];       // "bottle_status", one entry for each bottle
    /* 0x1020 */ OSTime unk_1020[6];        // "bottle_ostime", one entry for each bottle
    /* 0x1050 */ OSTime unk_1050[6];        // "bottle_sub", one entry for each bottle
    /* 0x1080 */ OSTime unk_1080[6];        // "bottle_time", one entry for each bottle
    /* 0x10B0 */ OSTime unk_10B0[6];        // "bottle_stop_time", one entry for each bottle
    /* 0x10E0 */ uint64_t pictoPhoto[1400]; // buffer containing the pictograph photo
    /* 0x3CA0 */ int32_t fileNum;           // "file_no"
    /* 0x3CA4 */ int16_t powderKegTimer;    // "big_bom_timer"
    /* 0x3CA6 */ uint8_t unk_3CA6;
    /* 0x3CA7 */ uint8_t unk_3CA7;          // "day_night_flag"
    /* 0x3CA8 */ int32_t gameMode;          // "mode"
    /* 0x3CAC */ int32_t sceneSetupIndex;   // "counter"
    /* 0x3CB0 */ int32_t respawnFlag;       // "restart_flag"
    /* 0x3CB4 */ RespawnData respawn[8];    // "restart_data"
    /* 0x3DB4 */ float entranceSpeed;       // "player_wipe_speedF"
    /* 0x3DB8 */ uint16_t entranceSound;    // "player_wipe_door_SE"
    /* 0x3DBA */ uint8_t unk_3DBA;          // "player_wipe_item"
    /* 0x3DBB */ uint8_t unk_3DBB;          // "next_walk"
    /* 0x3DBC */ uint16_t dogParams;        // "dog_flag"
    /* 0x3DBE */ uint8_t textTriggerFlags;  // "guide_status"
    /* 0x3DBF */ uint8_t showTitleCard;     // "name_display"
    /* 0x3DC0 */ int16_t unk_3DC0;          // "shield_magic_timer"
    /* 0x3DC2 */ uint8_t unk_3DC2;          // "pad1"
    /* 0x3DC8 */ OSTime unk_3DC8;           // "get_time"
    /* 0x3DD0 */ uint8_t unk_3DD0[7];       // "event_fg"
    /* 0x3DD7 */ uint8_t unk_3DD7[7];       // "calc_flag"
    /* 0x3DE0 */ OSTime unk_3DE0[7];        // "event_ostime"
    /* 0x3E18 */ OSTime unk_3E18[7];        // "event_sub"
    /* 0x3E50 */ OSTime unk_3E50[7];        // "func_time"
    /* 0x3E88 */ OSTime unk_3E88[7];        // "func_end_time"
    /* 0x3EC0 */ OSTime unk_3EC0[7];        // "func_stop_time"
    /* 0x3EF8 */ int16_t timerX[7];         // "event_xp"
    /* 0x3F06 */ int16_t timerY[7];         // "event_yp"
    /* 0x3F14 */ int16_t unk_3F14;          // "character_change"
    /* 0x3F16 */ uint8_t seqIndex;          // "old_bgm"
    /* 0x3F17 */ uint8_t nightSeqIndex;     // "old_env"
    /* 0x3F18 */ uint8_t buttonStatus[6];   // "button_item"
    /* 0x3F1E */ uint8_t unk_3F1E;          // "ck_fg"
    /* 0x3F20 */ uint16_t unk_3F20;         // "alpha_type"
    /* 0x3F22 */ uint16_t unk_3F22;         // "prev_alpha_type"
    /* 0x3F24 */ uint16_t unk_3F24;         // "alpha_count"
    /* 0x3F26 */ uint16_t unk_3F26;         // "last_time_type"
    /* 0x3F28 */ int16_t unk_3F28;          // "magic_flag"
    /* 0x3F2A */ int16_t unk_3F2A;          // "recovery_magic_flag"
    /* 0x3F2C */ int16_t unk_3F2C;          // "keep_magic_flag"
    /* 0x3F2E */ int16_t unk_3F2E;          // "magic_now_max"
    /* 0x3F30 */ int16_t unk_3F30;          // "magic_now_now"
    /* 0x3float */ int16_t unk_3float;      // "magic_used"
    /* 0x3F34 */ int16_t unk_3F34;          // "magic_recovery"
    /* 0x3F36 */ uint16_t mapIndex;         // "scene_ID"
    /* 0x3F38 */ uint16_t minigameState;    // "yabusame_mode"
    /* 0x3F3A */ uint16_t minigameScore;    // "yabusame_total"
    /* 0x3F3C */ uint16_t unk_3F3C;         // "yabusame_out_ct"
    /* 0x3F3E */ uint8_t unk_3F3E;          // "no_save"
    /* 0x3F3F */ uint8_t unk_3F3F;          // "flash_flag"
    /* 0x3F40 */ uint16_t option_id;        // "option_id"
    /* 0x3F42 */ uint8_t language;          // "j_n"
    /* 0x3F43 */ uint8_t audioSetting;      // "s_sound"
    /* 0x3F44 */ uint8_t unk_3F44;          // "language"
    /* 0x3F45 */ uint8_t zTargetSetting;    // 0: Switch; 1: Hold
    /* 0x3F46 */ uint16_t unk_3F46;         // "NottoriBgm"
    /* 0x3F48 */ uint8_t unk_3F48;          // "fade_go"
    /* 0x3F4A */ uint16_t unk_3F4A;         // "next_daytime"
    /* 0x3F4C */ uint8_t cutsceneTrigger;   // "doukidemo"
    /* 0x3F4D */ uint8_t unk_3F4D;          // "Kenjya_no"
    /* 0x3F4E */ uint16_t nextDayTime;      // "next_zelda_time"
    /* 0x3F50 */ uint8_t fadeDuration;      // "fade_speed"
    /* 0x3F51 */ uint8_t unk_3F51;          // "wipe_speed"
    /* 0x3F52 */ uint16_t environmentTime;  // "kankyo_time"
    /* 0x3F54 */ uint8_t dogIsLost;         // "dog_event_flag"
    /* 0x3F55 */ uint8_t nextTransition;    // "next_wipe"
    /* 0x3F56 */ int16_t worldMapArea;      // "area_type"
    /* 0x3F58 */ int16_t unk_3F58;          // "sunmoon_flag"
    /* 0x3F5A */ int16_t healthAccumulator; // "life_mode"
    /* 0x3F5C */ int32_t unk_3F5C;          // "bet_rupees"
    /* 0x3F60 */ uint8_t unk_3F60;          // "framescale_flag"
    /* 0x3F64 */ float unk_3F64;            // "framescale_scale"
    /* 0x3F68 */ uint32_t unk_3F68[5][120];
    /* 0x48C8 */ uint16_t unk_48C8; // "scene_id_mix"
    /* 0x48CA */ uint8_t unk_48CA[27];
} SaveContext; /* sizeof = 0x48C8 */
#endif

extern SaveContext gSaveContext;
SYMBOL_VERSION_CONFIG(gSaveContext, 0x8011A5D0, 0x801EF670);

#endif
