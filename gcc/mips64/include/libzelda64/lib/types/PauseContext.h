#ifndef PAUSECONTEXT_TYPE_H
#define PAUSECONTEXT_TYPE_H

#include "../zelda64_version.h"
#include "DmaRequest.h"
#include "OcarinaMessageInfo.h"
#include "SkelAnime.h"
#include "View.h"
#include <inttypes.h>
#include <libultra/PR/os.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

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
    /* 0x266 */ uint8_t warashibeFlag; // what does this mean?
    /* 0x267 */ uint8_t _pad1;
    /* 0x268 */ SkelAnime skeleton;
    /* 0x2B0 */ uint8_t _pad2[0x10]; // What???????????? TODO: Check if this is valid?
} PauseContext, KaleidoscopeContext; /* sizeof = 0x2C0 */

#else /* GAME_VERSION_1_0 */
#warning "STRUCT is not defined for this game version!"

#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x000 */ View view;
    /* 0x168 */ char* iconItemSegment;
    /* 0x16C */ char* iconItem24Segment;
    /* 0x170 */ char* iconItemMapSegment;
    /* 0x174 */ char* iconItemJpnSegment;
    /* 0x178 */ char* itemNameSegment;
    /* 0x17C */ char* mapNameSegment;
    /* 0x180 */ struct Vtx_t* itemFrameVtx;
    /* 0x184 */ struct Vtx_t* mapFrameVtx;
    /* 0x188 */ struct Vtx_t* collectFrameVtx;
    /* 0x18C */ struct Vtx_t* maskPageVtx;
    /* 0x190 */ struct Vtx_t* itemVtx;
    /* 0x194 */ struct Vtx_t* mapVtx;
    /* 0x198 */ struct Vtx_t* questVtx;
    /* 0x19C */ struct Vtx_t* maskVtx;
    /* 0x1A0 */ struct Vtx_t* unk_1A0;
    /* 0x1A4 */ struct Vtx_t* unk_1A4;
    /* 0x1A8 */ struct Vtx_t* cursorVtx;
    /* 0x1AC */ struct OcarinaMessageInfo* ocarinaInfo;
    /* 0x1B0 */ DmaRequest kaleidoscopeDma;
    /* 0x1D0 */ OSMesgQueue kaleidoQueue;
    /* 0x1E8 */ OSMesg kaleidoMessage;
    /* 0x1EC */ uint16_t status;
    /* 0x1EE */ uint16_t debugState;
    /* 0x1F0 */ uint8_t unk_1F0;
    /* 0x1F4 */ Vec3f eye;
    /* 0x200 */ uint16_t unk_200;
    /* 0x202 */ uint16_t mode;
    /* 0x204 */ uint16_t pageIndex;
    /* 0x206 */ uint16_t unk_206;
    /* 0x208 */ uint16_t unk_208;
    /* 0x20C */ float translate;
    /* 0x210 */ float angleItem;
    /* 0x214 */ float angleEquipment;
    /* 0x218 */ float angleMap;
    /* 0x21C */ float angleCollect;
    /* 0x220 */ float angleSave;
    /* 0x224 */ uint16_t alpha;
    /* 0x226 */ int16_t yPos;
    /* 0x228 */ int32_t unk_228;
    /* 0x22C */ int32_t unk_22C;
    /* 0x230 */ int32_t unk_230;
    /* 0x234 */ int32_t unk_234;
    /* 0x238 */ int16_t cursorPoint[5];
    /* 0x242 */ int16_t cursorPointX[5];
    /* 0x24C */ int16_t cursorPointY[5];
    /* 0x256 */ int16_t dungeonMapPoint;
    /* 0x258 */ int16_t inputAngle;
    /* 0x25A */ int16_t inputWait;
    /* 0x25C */ uint16_t itemName;
    /* 0x25E */ uint16_t selectName[5];
    /* 0x268 */ uint16_t selectPoint[5];
    /* 0x272 */ uint16_t selectItemNum0;
    /* 0x274 */ uint16_t selectItemNum1;
    /* 0x276 */ uint16_t selectCButton;
    /* 0x278 */ int16_t selectPosX;
    /* 0x27A */ int16_t selectPosY;
    /* 0x27C */ int16_t selectAlpha;
    /* 0x27E */ int16_t moveY;
    /* 0x280 */ uint16_t flashCounter;
    /* 0x282 */ uint16_t holdFlag;
    /* 0x284 */ int16_t cursorColorIdx;
    /* 0x286 */ int16_t saveCursor;
    /* 0x288 */ float unk_288;
    /* 0x28C */ float unk_28C;
    /* 0x290 */ float unk_290;
    /* 0x294 */ float unk_294;
    /* 0x298 */ float unk_298;
    /* 0x29C */ int16_t unk_29C;
    /* 0x29E */ int16_t unk_29E;
    /* 0x2A0 */ int16_t unk_2A0;
    /* 0x2A2 */ uint8_t mapEvent[20];
    /* 0x2B6 */ uint8_t unk_2B6;
    /* 0x2B7 */ uint8_t unk_2B7;
    /* 0x2B8 */ uint8_t unk_2B8;
    /* 0x2B9 */ uint8_t unk_2B9;
    /* 0x2BA */ int16_t unk_2BA;
    /* 0x2BC */ int16_t unk_2BC;
    /* 0x2BE */ int16_t unk_2BE[5];
    /* 0x2C8 */ uint16_t unk_2C8;
    /* 0x2CA */ int16_t unk_2CA;
} PauseContext; /* size = 0x2D0 */

#endif /* GAME_MM */

#endif
