#ifndef ACTOROVERLAY_TYPE_H
#define ACTOROVERLAY_TYPE_H

#include "../zelda64_version.h"
#include <inttypes.h>

typedef struct ActorOverlay {
    /* 0x00 */ uint32_t vromStart;
    /* 0x04 */ uint32_t vromEnd;
    /* 0x08 */ void* vramStart;
    /* 0x0C */ void* vramEnd;
    /* 0x10 */ void* loadedRamAddr; // original name: "allocp"
    /* 0x14 */ struct ActorInit* initInfo;
    /* 0x18 */ char* name;
    /* 0x1C */ uint16_t allocType;
    /* 0x1E */ int8_t nbLoaded; // original name: "clients"
} ActorOverlay;                 /* sizeof = 0x20 */

extern ActorOverlay gActorOverlayTable[];
SYMBOL_VERSION_CONFIG(gActorOverlayTable, 0x800E8530, 0x801AEFD0);

#endif
