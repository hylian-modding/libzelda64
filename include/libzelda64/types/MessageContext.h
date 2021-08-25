#ifndef MESSAGECONTEXT_TYPE_H
#define MESSAGECONTEXT_TYPE_H

#include "DmaRequest.h"
#include "Font.h"
#include "View.h"
#include <inttypes.h>
#include <PR/os.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct MessageContext {
    /* 0x0000 */ View view;
    /* 0x0128 */ Font font;
    /* 0xE2B0 */ void* textboxSegment; // "fukidashiSegment"
    /* 0xE2B4 */ void* textureSegment;
    /* 0xE2B8 */ struct OcarinaMessageInfo* ocarinaMessageInfo;
    /* 0xE2BC */ DmaRequest dma;
    /* 0xE2DC */ OSMesgQueue mq;
    /* 0xE2F4 */ OSMesg m;
    /* 0xE2F8 */ uint16_t messageNum;
    /* 0xE2FA */ uint16_t messageSelectionNum;
    /* 0xE2FC */ uint8_t messageDisplayType;
    /* 0xE2FE */ uint8_t messageDisplayBalloonType;
    /* 0xE2FF */ uint8_t messageDisplayPositionType;
    /* 0xE300 */ uint8_t* messageData;
    /* 0xE304 */ uint8_t messageMode;
    union {
        /* 0xE306 */ uint16_t messageBufferJ[100];
        /* 0xE306 */ uint8_t messageBufferE[200];
    };
    /* 0xE3CE */ uint16_t readIndex;
    /* 0xE3D0 */ uint16_t loadIndex;
    /* 0xE3D2 */ uint16_t loadEndIndex;
    /* 0xE3D4 */ uint16_t readEndIndex;
    /* 0xE3D6 */ uint16_t mashTimer;
    /* 0xE3D8 */ int16_t messagePosX;
    /* 0xE3DA */ int16_t messagePosY;
    /* 0xE3DC */ int16_t messageR;
    /* 0xE3DE */ int16_t messageG;
    /* 0xE3E0 */ int16_t messageB;
    /* 0xE3E2 */ int16_t messageA;
    /* 0xE3E4 */ uint8_t messageSelectionMode;
    /* 0xE3E5 */ uint8_t messageSelectionIndex;
    /* 0xE3E6 */ uint8_t itemDisplayFlag;
    /* 0xE3E7 */ int8_t windowCounter;
    /* 0xE3E8 */ uint16_t messageSpeed;
    /* 0xE3EA */ uint16_t messageSpeedInitial; // ?
    /* 0xE3EC */ uint16_t ocarinaSong;
    /* 0xE3EE */ uint16_t ocarinaMode;
    /* 0xE3F0 */ uint16_t ocarinaSongAuto;
    /* 0xE3F2 */ uint16_t ocarinaSongCheck;
    /* 0xE3F4 */ uint16_t sunSong;
    /* 0xE3F6 */ uint16_t messageBoxNum;
    /* 0xE3F8 */ uint8_t messageBoxPrimary;
    /* 0xE3F9 */ uint8_t messageBoxShadow;
    /* 0xE3FA */ uint8_t messageBoxShift;
    /* 0xE3FB */ uint8_t messageBoxAnim;
    /* 0xE3FC */ int16_t messageBoxType;
    /* 0xE3FE */ int16_t messageBoxR;
    /* 0xE400 */ int16_t messageBoxG;
    /* 0xE402 */ int16_t messageBoxB;
    /* 0xE404 */ int16_t messageBoxA;
    /* 0xE406 */ int16_t messageBoxAlpha;
    /* 0xE408 */ struct Actor* talkActor;
    /* 0xE40C */ int16_t warpChoice; // I don't understand why there are two choice variables
    /* 0xE40E */ int16_t sunSongChoice;
    /* 0xE410 */ uint8_t frameCfg;
    /* 0xE411 */ uint8_t _pad[7];
} MessageContext; /* sizeof = 0xE418 */

#else /* GAME_VERSION_1_0 */
#warning "MessageContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00000 */ View view;
    /* 0x00168 */ Font font;
    /* 0x11EF4 */ char unk_11EF4[0x10];
    /* 0x11F04 */ uint16_t unk11F04;
    /* 0x11F06 */ uint8_t pad11F06[0x4];
    /* 0x11F0A */ uint8_t unk11F0A;
    /* 0x11F0B */ uint8_t pad11F0B[0x5];
    /* 0x11F10 */ int32_t unk11F10;
    /* 0x11F14 */ uint8_t pad11F14[0xE];
    /* 0x11F22 */ uint8_t unk11F22;
    /* 0x11F23 */ uint8_t pad11F23[0xFD];
    /* 0x12020 */ uint8_t unk12020;
    /* 0x12021 */ uint8_t choiceIndex;
    /* 0x12022 */ uint8_t unk12022;
    /* 0x12023 */ int8_t unk12023;
    /* 0x12024 */ uint8_t unk12024[0x6];
    /* 0x1202A */ uint16_t unk1202A;
    /* 0x1202C */ uint8_t pad1202C[0x2];
    /* 0x1202E */ uint16_t unk1202E;
    /* 0x12030 */ uint8_t pad12030[0x14];
    /* 0x12044 */ int16_t unk12044;
    /* 0x12046 */ uint8_t pad12046[0x24];
    /* 0x1206A */ int16_t unk1206A;
    /* 0x1206C */ int32_t unk1206C;
    /* 0x12070 */ uint8_t pad12070[0x8];
    /* 0x12078 */ int32_t bankRupeesSelected;
    /* 0x1207C */ int32_t bankRupees;
    /* 0x12080 */ uint8_t pad12080[0x31];
    /* 0x120B1 */ uint8_t unk120B1;
    /* 0x120B2 */ uint8_t pad120B2[0x22];
    /* 0x120D4 */ uint16_t unk120D4;
    /* 0x120D6 */ uint16_t unk120D6;
    /* 0x120D8 */ uint8_t pad120D8[0x8];
} MessageContext; /* sizeof = 0x120E0 */
#endif                /* GAME_MM */

#endif
