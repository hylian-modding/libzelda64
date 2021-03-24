#ifndef ACTORLISTENTRY_TYPE_H
#define ACTORLISTENTRY_TYPE_H

#include <inttypes.h>

typedef enum {
    ACTORLIST_CATEGORY_SWITCH,
    ACTORLIST_CATEGORY_BG,
    ACTORLIST_CATEGORY_PLAYER,
    ACTORLIST_CATEGORY_EXPLOSIVE,
    ACTORLIST_CATEGORY_NPC,
    ACTORLIST_CATEGORY_ENEMY,
    ACTORLIST_CATEGORY_PROP,
    ACTORLIST_CATEGORY_ITEM,
    ACTORLIST_CATEGORY_MISC,
    ACTORLIST_CATEGORY_BOSS,
    ACTORLIST_CATEGORY_DOOR,
    ACTORLIST_CATEGORY_CHEST,
    ACTORLIST_CATEGORY_COUNT
} ACTORLIST_CATEGORY;

typedef struct ActorListEntry {
    /* 0x00 */ int32_t length;
    /* 0x04 */ struct Actor* head;
} ActorListEntry; /* 0x08 */

/* Special Actor Flags */
#define ACTORFLAG_NOP                 (0)                             /* No operations. */
#define ACTORFLAG_CAN_TARGET          (1)                             /* Can be Z-Targeted. */
#define ACTORFLAG_TARGET              ACTORFLAG_CAN_TARGET            /* Can be Z-Targeted; Target is enabled. */
#define ACTORFLAG_FIGHT               ((1 << 2) | ACTORFLAG_TARGET)   /* Target is enabled, plays danger music if using ACTORCAT_ENEMY. */
#define ACTORFLAG_TALK                ((1 << 3) | ACTORFLAG_TARGET)   /* Target is enabled, enable speak command. */
#define ACTORFLAG_ALWAYS_UPDATE       (1 << 4)                        /* Update function always runs, even if the camera isn't focusing on the actor. */
#define ACTORFLAG_ALWAYS_DRAW         (1 << 5)                        /* Draw function always runs, even if the camera isn't focusing on the actor. */
#define ACTORFLAG_NO_CULL_FLAG        (1 << 6)                        /* Outside of culling range. */
#define ACTORFLAG_INVISIBLE           (1 << 7)                        /* Is invisible. */
#define ACTORFLAG_TALKING_NOW         (1 << 8)                        /* Currently speaking. */
#define ACTORFLAG_CAN_HOOKSHOT_GRAB   (1 << 9)                        /* Can be grappled with the hookshot, if collider is set properly. */
#define ACTORFLAG_CAN_HOOKSHOT        (1 << 10)                       /* Can be hookshot to, if collider is set properly. */
#define ACTORFLAG_ZOMBI               (1 << 11)                       /* */
#define ACTORFLAG_NO_QUAKE            (1 << 12)                       /* Not affected by the screen shaking. (i.e. Megaton Hammer Earthquake) */
#define ACTORFLAG_CARRIED_HOOKSHOT    (1 << 13)                       /* Is currently being pulled by the hookshot. */
#define ACTORFLAG_ARROW_CARRY         (1 << 14)                       /* */
#define ACTORFLAG_ARROW_CARRY_NOW     (1 << 15)                       /* */
#define ACTORFLAG_FORCE_TALK          (1 << 16)                       /* Force an unavoidable conversation. */
#define ACTORFLAG_CARRY_ANGLE_SET     (1 << 17)                       /* */
#define ACTORFLAG_ELF_MAIL            ((1 << 18) | ACTORFLAG_TARGET)  /* */
#define ACTORFLAG_SFX_PLAYER          (1 << 19)                       /* Set sound effect type. (Player) */
#define ACTORFLAG_SFX_SYSTEM          (1 << 20)                       /* Set sound effect type. (System) */
#define ACTORFLAG_SFX_FIXED           (1 << 21)                       /* Set sound effect type. (Fixed) */
#define ACTORFLAG_MAP_LIGHT_MODE      (1 << 22)                       /* Terrain Type Lighting Flag */
#define ACTORFLAG_THROW_ONLY          (1 << 23)                       /* When picked up, you can only throw--not drop. */
#define ACTORFLAG_BODY_HIT            (1 << 24)                       /* */
#define ACTORFLAG_OKARINA_NO_STOP     (1 << 25)                       /* */
#define ACTORFLAG_CAN_PRESS_SWITCH    (1 << 26)                       /* Can activate floor switches. */
#define ACTORFLAG_NO_TARGET_LOCK      (1 << 27)                       /* */
#define ACTORFLAG_SFX_TIMER           (1 << 28)                       /* Set sound effect type. (Timer) */

#endif

