#ifndef OBJECTSTATUS_TYPE_H
#define OBJECTSTATUS_TYPE_H

#include "DmaRequest.h"
#include <inttypes.h>
#include <PR/os.h>

typedef struct ObjectStatus {
    /* 0x00 */ int16_t id;
    /* 0x04 */ void* segment;
    /* 0x08 */ DmaRequest dmaRequest;
    /* 0x28 */ OSMesgQueue loadQueue;
    /* 0x40 */ OSMesg loadMsg;
} ObjectStatus; /* sizeof = 0x44 */

#endif
