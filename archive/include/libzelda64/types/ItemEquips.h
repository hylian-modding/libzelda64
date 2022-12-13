#ifndef ITEMEQUIPS_TYPE_H
#define ITEMEQUIPS_TYPE_H

#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct {
    /* 0x00 */ uint8_t buttonItems[4];
    /* 0x04 */ uint8_t cButtonSlots[3];
    /* 0x08 */ uint16_t equipment;
} ItemEquips; /* sizeof = 0x0A */

#else /* GAME_VERSION_1_0 */
#warning "ItemEquips is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ uint8_t buttonItems[4][4];
    /* 0x04 */ uint8_t cButtonSlots[4][4];
    /* 0x20 */ uint16_t equipment;
} ItemEquips; /* sizeof = 0x22 */
#endif                /* GAME_MM */

#endif
