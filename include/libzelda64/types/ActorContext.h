#ifndef ACTORCONTEXT_TYPE_H
#define ACTORCONTEXT_TYPE_H

#include "ActorEnvironment.h"
#include "ActorListEntry.h"
#include "TargetContext.h"
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

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct ActorContext {
    /* 0x000 */ uint8_t damageFlashTimer; // Screen flashes white when this reaches 0
    /* 0x001 */ uint8_t flashType;        // Type of flash for the flash timer
    /* 0x002 */ uint8_t hammerQuake;      // Window of opportunity (in frames) to flip (or apply quake effect) enemies where applicable
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
} ActorContext;                      /* sizeof = 0x140 */

#else /* GAME_VERSION_1_0 */
#warning "ActorContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct ActorContext {
    /* 0x000 */ char pad0[0x2];
    /* 0x002 */ uint8_t unk2;
    /* 0x003 */ uint8_t unk3;
    /* 0x004 */ int8_t unk4;
    /* 0x005 */ uint8_t unk5;
    /* 0x006 */ char pad6[0x5];
    /* 0x00B */ int8_t unkB;
    /* 0x00C */ int16_t unkC;
    /* 0x00E */ uint8_t total;
    /* 0x00F */ uint8_t undrawnActorCount;
    /* 0x010 */ ActorListEntry actorLists[ACTORLIST_CATEGORY_COUNT];
    /* 0x0A0 */ uint16_t* undrawnActors[32]; // Records the first 32 actors drawn each frame
    /* 0x120 */ TargetContext targetCtx;
    /* 0x1B8 */ uint32_t switchFlags[4]; // First 0x40 are permanent, second 0x40 are temporary
    /* 0x1C8 */ uint32_t chestFlags;
    /* 0x1CC */ uint32_t clearedRooms;
    /* 0x1D0 */ uint32_t clearedRoomsTemp;
    /* 0x1D4 */ uint32_t collectibleFlags[4]; // bitfield of 128 bits
    /* 0x1E4 */ TitleCardContext titleCtx;
    /* 0x1F4 */ uint8_t unk1F4;
    /* 0x1F5 */ uint8_t unk1F5;
    /* 0x1F6 */ char pad1F6[0x2];
    /* 0x1F8 */ float unk1F8;
    /* 0x1FC */ Vec3f unk1FC;
    /* 0x208 */ char pad208[0x48];
    /* 0x250 */ void* unk250; // allocation of 0x20f0 bytes?
    /* 0x254 */ uint32_t unk254[5];
    /* 0x268 */ uint8_t unk268;
    /* 0x269 */ char pad269[0x3];
    /* 0x26C */ char pad26C[0xC];
    /* 0x278 */ uint16_t unk278;
    /* 0x27A */ char pad27A[0x2];
    /* 0x27C */ char pad27C[0x8];
} ActorContext; /* sizeof = 0x284 */
#endif                /* GAME_MM */

#endif
