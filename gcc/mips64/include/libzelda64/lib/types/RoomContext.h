#ifndef ROOMCONTEXT_TYPE_H
#define ROOMCONTEXT_TYPE_H

#include "../zelda64_version.h"
#include "DmaRequest.h"
#include "Room.h"
#include <inttypes.h>
#include <libultra/PR/os.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct RoomContext {
    /* 0x00 */ Room curRoom;
    /* 0x14 */ Room prevRoom;
    /* 0x28 */ void* bufPtrs[2];
    /* 0x30 */ uint8_t buffer_count;
    /* 0x31 */ int8_t status;
    /* 0x32 */ int8_t readData;
    /* 0x33 */ int8_t _pad;
    /* 0x34 */ void* readBufferAddress;
    /* 0x38 */ DmaRequest dmaRequest;
    /* 0x58 */ OSMesgQueue loadQueue;
    /* 0x70 */ OSMesg loadMsg;
} RoomContext; /* sizeof = 0x74 */

#else /* GAME_VERSION_1_0 */
#warning "Actor is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct RoomContext {
    /* 0x00 */ Room curRoom;
    /* 0x14 */ Room prevRoom;
    /* 0x28 */ void* bufPtrs[2];
    /* 0x30 */ uint8_t buffer_count;
    /* 0x31 */ int8_t status;
    /* 0x32 */ int8_t readData;
    /* 0x33 */ int8_t _pad;
    /* 0x34 */ void* readBufferAddress;
    /* 0x38 */ DmaRequest dmaRequest;
    /* 0x58 */ OSMesgQueue loadQueue;
    /* 0x70 */ OSMesg loadMsg;
    /* 0x74 */ void* unk74;
    /* 0x78 */ int8_t unk78;
    /* 0x79 */ int8_t unk79;
    /* 0x7A */ uint16_t unk7A[3];
} RoomContext; /* sizeof = 0x80 */
#endif                /* GAME_MM */

#endif
