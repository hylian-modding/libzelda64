#ifndef ACTORCONTEXT_TYPE_H
#define ACTORCONTEXT_TYPE_H

#include "ActorListEntry.h"
#include "TargetContext.h"
#include "ActorEnvironment.h"
#include "TitleCardContext.h"
#include <inttypes.h>

typedef enum {
    /* 0x00 */ ACTORCAT_SWITCH,
    /* 0x01 */ ACTORCAT_BG,
    /* 0x02 */ ACTORCAT_PLAYER,
    /* 0x03 */ ACTORCAT_EXPLOSIVE,
    /* 0x04 */ ACTORCAT_NPC,
    /* 0x05 */ ACTORCAT_ENEMY,
    /* 0x06 */ ACTORCAT_PROP,
    /* 0x07 */ ACTORCAT_ITEMACTION,
    /* 0x08 */ ACTORCAT_MISC,
    /* 0x09 */ ACTORCAT_BOSS,
    /* 0x0A */ ACTORCAT_DOOR,
    /* 0x0B */ ACTORCAT_CHEST
} ActorCategory;

typedef struct ActorContext {
    /* 0x000 */ uint8_t damageFlashTimer; // Screen flashes white when this reaches 0
    /* 0x001 */ uint8_t flashType; // Type of flash for the flash timer
    /* 0x002 */ uint8_t hammerQuake; // Window of opportunity (in frames) to flip (or apply quake effect) enemies where applicable
    /* 0x003 */ uint8_t lensEnabled;
    /* 0x004 */ uint8_t _pad0;
    /* 0x005 */ int16_t shieldMagicTimer;
    /* 0x007 */ uint8_t total; // total number of actors loaded;
    /* 0x008 */ uint8_t _pad1[3];
    /* 0x00C */ ActorListEntry actorLists[ACTORLIST_CATEGORY_COUNT];
    /* 0x06C */ TargetContext targetCtx;
    /* 0x104 */ ActorEnvironment flags;
    /* 0x128 */ TitleCardContext titleCtx;
    /* 0x138 */ void* naviMessage;
    /* 0x13C */ void* absoluteSpace; // Space used to allocate actor overlays of alloc type 1
} ActorContext; /* sizeof = 0x140 */

#endif

