#ifndef PAUSECONTEXT_TYPE_H
#define PAUSECONTEXT_TYPE_H

#include "View.h"
#include "OcarinaMessageInfo.h"
#include "DmaRequest.h"
#include "SkelAnime.h"
#include <libultra/PR/os.h>
#include <inttypes.h>

typedef struct PauseContext {
    /* 0x000 */ View view;
    /* 0x128 */ char* iconItemSegment;
    /* 0x12C */ char* iconItem24Segment;
    /* 0x130 */ char* iconItemMapSegment;
    /* 0x134 */ char* iconItemJpnSegment;
    /* 0x138 */ char* itemNameSegment;
    /* 0x13C */ char* mapNameSegment;
    /* 0x140 */ struct Vtx_t* itemFrameVtx;
    /* 0x144 */ struct Vtx_t* equipmentFrameVtx;
    /* 0x148 */ struct Vtx_t* mapFrameVtx;
    /* 0x14C */ struct Vtx_t* collectFrameVtx;
    /* 0x150 */ struct Vtx_t* menuVtx;
    /* 0x154 */ struct Vtx_t* itemVtx;
    /* 0x158 */ struct Vtx_t* equipVtx;
    /* 0x15C */ struct Vtx_t* mapVtx;
    /* 0x160 */ struct Vtx_t* collectVtx;
    /* 0x164 */ struct Vtx_t* cursorVtx;
    /* 0x168 */ struct Vtx_t* saveVtx;
    /* 0x16C */ int8_t mapPalette[32];
    /* 0x18C */ char* cvg;
    /* 0x190 */ struct OcarinaMessageInfo* ocarinaInfo;
    /* 0x194 */ DmaRequest kaleidoscopeDma;
    /* 0x1B4 */ OSMesgQueue kaleidoQueue;
    /* 0x1CC */ OSMesg kaleidoMessage;
    /* 0x1D0 */ uint16_t status;
    /* 0x1D2 */ uint16_t mode;
    /* 0x1D4 */ uint16_t pos;
    /* 0x1D6 */ uint16_t scroll;
    /* 0x1D8 */ uint16_t saveStatus;
    /* 0x1DA */ uint16_t _pad0;
    /* 0x1DC */ float translate;
    /* 0x1E0 */ float angleItem;
    /* 0x1E4 */ float angleEquipment;
    /* 0x1E8 */ float angleMap;
    /* 0x1EC */ float angleCollect;
    /* 0x1F0 */ float angleSave;
    /* 0x1F4 */ uint16_t alpha;
    /* 0x1F6 */ int16_t yPos;
    /* 0x1F8 */ int32_t inputX;
    /* 0x1FC */ int32_t inputY;
    /* 0x200 */ int16_t inputXW;
    /* 0x202 */ int16_t inputYW;
    /* 0x204 */ int16_t cursorPoint[5];
    /* 0x20E */ int16_t cursorPointX[5];
    /* 0x218 */ int16_t cursorPointY[5];
    /* 0x222 */ int16_t dungeonMapPoint;
    /* 0x224 */ int16_t inputAngle;
    /* 0x226 */ int16_t inputWait;
    /* 0x228 */ uint16_t itemName;
    /* 0x22A */ uint16_t selectName[4];
    /* 0x232 */ uint16_t selectPoint[4];
    /* 0x23A */ uint16_t selectItemNum0;
    /* 0x23C */ uint16_t selectItemNum1;
    /* 0x23E */ uint16_t selectCButton;
    /* 0x240 */ int16_t selectPosX;
    /* 0x242 */ int16_t selectPosY;
    /* 0x244 */ int16_t selectAlpha;
    /* 0x246 */ int16_t moveY;
    /* 0x248 */ uint16_t flashCounter;
    /* 0x24A */ uint16_t holdFlag;
    /* 0x24C */ int16_t cursorColorIdx;
    /* 0x24E */ int16_t saveCursor;
    /* 0x250 */ int16_t ocarinaNum; // song num?
    /* 0x252 */ uint8_t mapEvent[20];
    /* 0x266 */ uint8_t  warashibeFlag; // what does this mean?
    /* 0x267 */ uint8_t _pad1;
    /* 0x268 */ SkelAnime skeleton;
    /* 0x2B0 */ uint8_t _pad2[0x10]; // What???????????? TODO: Check if this is valid?
} PauseContext, KaleidoscopeContext; /* sizeof = 0x2C0 */


#endif

