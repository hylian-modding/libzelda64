#ifndef MESSAGECONTEXT_TYPE_H
#define MESSAGECONTEXT_TYPE_H

#include "View.h"
#include "Font.h"
#include "DmaRequest.h"
#include <libultra/PR/os.h>
#include <inttypes.h>

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

#endif

