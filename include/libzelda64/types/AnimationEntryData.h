#ifndef ANIMATIONENTRYDATA_TYPE_H
#define ANIMATIONENTRYDATA_TYPE_H

#include "DmaRequest.h"
#include <inttypes.h>
#include <PR/os.h>

typedef struct AnimEntryLoadFrame {
    /* 0x00 */ DmaRequest req;
    /* 0x20 */ OSMesgQueue msgQueue;
    /* 0x38 */ OSMesg msg;
} AnimEntryLoadFrame; /* sizeof = 0x3C */

typedef struct AnimEntryCopyAll {
    /* 0x00 */ uint8_t queueFlag;
    /* 0x01 */ uint8_t vecCount;
    /* 0x04 */ struct Vec3s* dst;
    /* 0x08 */ struct Vec3s* src;
} AnimEntryCopyAll; /* sizeof = 0x0C */

typedef struct AnimEntryInterp {
    /* 0x00 */ uint8_t queueFlag;
    /* 0x01 */ uint8_t vecCount;
    /* 0x04 */ struct Vec3s* base;
    /* 0x08 */ struct Vec3s* mod;
    /* 0x0C */ float weight;
} AnimEntryInterp; /* sizeof = 0x10 */

typedef struct AnimEntryCopyTrue {
    /* 0x00 */ uint8_t queueFlag;
    /* 0x01 */ uint8_t vecCount;
    /* 0x04 */ struct Vec3s* dst;
    /* 0x08 */ struct Vec3s* src;
    /* 0x0C */ uint8_t* copyFlag;
} AnimEntryCopyTrue; /* sizeof = 0x10 */

typedef struct AnimEntryCopyFalse {
    /* 0x00 */ uint8_t queueFlag;
    /* 0x01 */ uint8_t vecCount;
    /* 0x04 */ struct Vec3s* dst;
    /* 0x08 */ struct Vec3s* src;
    /* 0x0C */ uint8_t* copyFlag;
} AnimEntryCopyFalse; /* sizeof = 0x10 */

typedef struct AnimEntryMoveActor {
    /* 0x00 */ struct Actor* actor;
    /* 0x04 */ struct SkelAnime* skelAnime;
    /* 0x08 */ float unk_08;
} AnimEntryMoveActor; /* sizeof = 0x0C */

typedef union AnimationEntryData {
    /* 0x00 */ AnimEntryLoadFrame load;
    /* 0x00 */ AnimEntryCopyAll copy;
    /* 0x00 */ AnimEntryInterp interp;
    /* 0x00 */ AnimEntryCopyTrue copy1;
    /* 0x00 */ AnimEntryCopyFalse copy0;
    /* 0x00 */ AnimEntryMoveActor move;
} AnimationEntryData; /* sizeof = 0x3C */


#endif
