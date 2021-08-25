#ifndef DAMAGETABLE_TYPE_H
#define DAMAGETABLE_TYPE_H

#include <inttypes.h>

typedef struct DamageTable {
    /* 0x00 */ uint8_t table[32];
} DamageTable; /* sizeof = 0x20 */

#define DMG_ENTRY(damage, effect) ((damage) | ((effect) << 4))

#ifdef GAME_OOT
// These flags are not to be used in code until we figure out how we want to format them. They are only here for reference
#define DMG_DEKU_NUT     (1 << 0x00)
#define DMG_DEKU_STICK   (1 << 0x01)
#define DMG_SLINGSHOT    (1 << 0x02)
#define DMG_EXPLOSIVE    (1 << 0x03)
#define DMG_BOOMERANG    (1 << 0x04)
#define DMG_ARROW_NORMAL (1 << 0x05)
#define DMG_HAMMER_SWING (1 << 0x06)
#define DMG_HOOKSHOT     (1 << 0x07)
#define DMG_SLASH_KOKIRI (1 << 0x08)
#define DMG_SLASH_MASTER (1 << 0x09)
#define DMG_SLASH_GIANT  (1 << 0x0A)
#define DMG_ARROW_FIRE   (1 << 0x0B)
#define DMG_ARROW_ICE    (1 << 0x0C)
#define DMG_ARROW_LIGHT  (1 << 0x0D)
#define DMG_ARROW_UNK1   (1 << 0x0E)
#define DMG_ARROW_UNK2   (1 << 0x0F)
#define DMG_ARROW_UNK3   (1 << 0x10)
#define DMG_MAGIC_FIRE   (1 << 0x11)
#define DMG_MAGIC_ICE    (1 << 0x12)
#define DMG_MAGIC_LIGHT  (1 << 0x13)
#define DMG_SHIELD       (1 << 0x14)
#define DMG_MIR_RAY      (1 << 0x15)
#define DMG_SPIN_KOKIRI  (1 << 0x16)
#define DMG_SPIN_GIANT   (1 << 0x17)
#define DMG_SPIN_MASTER  (1 << 0x18)
#define DMG_JUMP_KOKIRI  (1 << 0x19)
#define DMG_JUMP_GIANT   (1 << 0x1A)
#define DMG_JUMP_MASTER  (1 << 0x1B)
#define DMG_UNKNOWN_1    (1 << 0x1C)
#define DMG_UNBLOCKABLE  (1 << 0x1D)
#define DMG_HAMMER_JUMP  (1 << 0x1E)
#define DMG_UNKNOWN_2    (1 << 0x1F)

#define DMG_SLASH       (DMG_SLASH_KOKIRI | DMG_SLASH_MASTER | DMG_SLASH_GIANT)
#define DMG_SPIN_ATTACK (DMG_SPIN_KOKIRI | DMG_SPIN_MASTER | DMG_SPIN_GIANT)
#define DMG_JUMP_SLASH  (DMG_JUMP_KOKIRI | DMG_JUMP_MASTER | DMG_JUMP_GIANT)
#define DMG_SWORD       (DMG_SLASH | DMG_SPIN_ATTACK | DMG_JUMP_SLASH)
#define DMG_HAMMER      (DMG_HAMMER_SWING | DMG_HAMMER_JUMP)
#define DMG_FIRE        (DMG_ARROW_FIRE | DMG_MAGIC_FIRE)
#define DMG_ARROW       (DMG_ARROW_NORMAL | DMG_ARROW_FIRE | DMG_ARROW_ICE | DMG_ARROW_LIGHT | DMG_UNK_ARROW_1 | DMG_UNK_ARROW_2 | DMG_UNK_ARROW_3)
#define DMG_RANGED      (DMG_ARROW | DMG_HOOKSHOT | DMG_SLINGSHOT)
#define DMG_DEFAULT     ~(DMG_SHIELD | DMG_MIR_RAY)
#endif

#endif
