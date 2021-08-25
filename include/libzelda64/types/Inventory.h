#ifndef INVENTORY_TYPE_H
#define INVENTORY_TYPE_H

#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct {
    /* 0x00 */ uint8_t items[24];
    /* 0x18 */ int8_t ammo[16];
    /* 0x28 */ uint16_t equipment;
    /* 0x2C */ uint32_t upgrades;
    /* 0x30 */ uint32_t questItems;
    /* 0x34 */ uint8_t dungeonItems[20];
    /* 0x48 */ int8_t dungeonKeys[19];
    /* 0x5B */ int8_t defenseHearts;
    /* 0x5C */ int16_t gsTokens;
} Inventory; /* sizeof = 0x5E */

#else /* GAME_VERSION_1_0 */
#warning "Inventory is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ uint8_t items[24];
    /* 0x18 */ uint8_t masks[24];
    /* 0x30 */ int8_t ammo[24];
    /* 0x48 */ uint32_t upgrades; // some bits are wallet upgrades
    /* 0x4C */ uint32_t questItems;
    /* 0x50 */ uint8_t dungeonItems[10];
    /* 0x5A */ int8_t dungeonKeys[10];
    /* 0x64 */ int8_t strayFairies[10]; // "orange_fairy"
    /* 0x6E */ uint8_t unk_6E[8][3];    // "degnuts_memory_name"
} Inventory;                            /* sizeof = 0x88 */
#endif                /* GAME_MM */

#endif
