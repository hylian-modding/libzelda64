#ifndef ROOMCONTEXT_TYPE_H
#define ROOMCONTEXT_TYPE_H

#include "Room.h"
#include "DmaRequest.h"
#include <libultra/PR/os.h>
#include <inttypes.h>

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


#endif

