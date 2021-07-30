#ifndef INVENTORY_TYPE_H
#define INVENTORY_TYPE_H

#include <inttypes.h>

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

#endif

