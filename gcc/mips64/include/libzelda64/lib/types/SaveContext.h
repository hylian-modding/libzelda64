#ifndef SAVECONTEXT_TYPE_H
#define SAVECONTEXT_TYPE_H

#include <inttypes.h>
#include "ItemEquips.h"
#include "Inventory.h"
#include "SavedSceneFlags.h"
#include "FaroresWindData.h"
#include "HorseData.h"
#include "RespawnData.h"

typedef struct {
    /* 0x0000 */ int32_t entranceIndex; // start of `save` substruct, originally called "memory"
    /* 0x0004 */ int32_t linkAge; // 0: Adult; 1: Child
    /* 0x0008 */ int32_t cutsceneIndex;
    /* 0x000C */ uint16_t dayTime; // "zelda_time"
    /* 0x0010 */ int32_t nightFlag;
    /* 0x0014 */ int32_t numDays;
    /* 0x0018 */ int32_t unk_18; // increments with numDays, gets reset by goron for bgs and one other use
    /* 0x001C */ char newf[6]; // string "ZELDAZ". start of `info` substruct, originally called "information"
    /* 0x0022 */ uint16_t deaths;
    /* 0x0024 */ char playerName[8];
    /* 0x002C */ int16_t n64ddFlag;
    /* 0x002E */ int16_t healthCapacity; // "max_life"
    /* 0x0030 */ int16_t health; // "now_life"
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
    /* 0x0EF0 */ uint16_t itemGetInf[4]; // "item_get_inf"
    /* 0x0EF8 */ uint16_t infTable[30]; // "inf_table"
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
    /* 0x1354 */ int32_t fileNum; // "file_no"
    /* 0x1358 */ char unk_1358[0x0004];
    /* 0x135C */ int32_t gameMode;
    /* 0x1360 */ int32_t sceneSetupIndex;
    /* 0x1364 */ int32_t respawnFlag; // "restart_flag"
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
    /* 0x13E7 */ uint8_t unk_13E7; // alpha related
    /* 0x13E8 */ uint16_t unk_13E8; // alpha type?
    /* 0x13EA */ uint16_t unk_13EA; // also alpha type?
    /* 0x13EC */ uint16_t unk_13EC; // alpha type counter?
    /* 0x13EE */ uint16_t unk_13EE; // previous alpha type?
    /* 0x13F0 */ int16_t unk_13F0; // magic related
    /* 0x13F2 */ int16_t unk_13F2; // magic related
    /* 0x13F4 */ int16_t unk_13F4; // magic related
    /* 0x13F6 */ int16_t unk_13F6; // magic related
    /* 0x13F8 */ int16_t unk_13F8; // magic related
    /* 0x13FA */ uint16_t eventInf[4]; // "event_inf"
    /* 0x1402 */ uint16_t mapIndex; // intended for maps/minimaps but commonly used as the dungeon index
    /* 0x1404 */ uint16_t minigameState;
    /* 0x1406 */ uint16_t minigameScore; // "yabusame_total"
    /* 0x1408 */ char unk_1408[0x0001];
    /* 0x1409 */ uint8_t language;
    /* 0x140A */ uint8_t audioSetting;
    /* 0x140B */ char unk_140B[0x0001];
    /* 0x140C */ uint8_t zTargetSetting; // 0: Switch; 1: Hold
    /* 0x140E */ uint16_t unk_140E; // bgm related
    /* 0x1410 */ uint8_t unk_1410; // transition related
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
} SaveContext; /* size = 0x1428 */

#endif

