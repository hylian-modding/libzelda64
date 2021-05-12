#ifndef __PUPPET_EQUIP_BOTTLE_H__
#define __PUPPET_EQUIP_BOTTLE_H__

#define ACTION_IS_BOTTLE (((this)->puppet).action.Params[1] >= PLAYER_AP_BOTTLE && ((this)->puppet).action.Params[1] <= PLAYER_AP_BOTTLE_FAIRY)

#define BOTTLE_INDEX (((this)->puppet).action.Params[1] - 30)

const Color_RGB8 contents[13] = {
    { 0xFF, 0xFF, 0xFF },   /* Empty Bottle */
    { 0x50, 0x50, 0xFF },   /* Fish */
    { 0xFF, 0x64, 0xFF },   /* Blue Fire */
    { 0x00, 0x00, 0xFF },   /* Bugs */
    { 0xFF, 0x00, 0xFF },   /* Poe */
    { 0xFF, 0x00, 0xFF },   /* Big Poe */
    { 0xC8, 0xC8, 0x64 },   /* Ruto's Letter */
    { 0xFF, 0x00, 0x00 },   /* Red Potion */
    { 0x00, 0x00, 0xFF },   /* Blue Potion */
    { 0x00, 0xFF, 0x00 },   /* Green Potion */
    { 0xFF, 0xFF, 0xFF },   /* Milk (Full) */
    { 0xFF, 0xFF, 0xFF },   /* Milk (Half) */
    { 0x50, 0x50, 0xFF },   /* Fairy */
};

#define RESOLVE_BOTTLE_COLOR(action)(bottle_colors[action - 30])

#endif /* __PUPPET_EQUIP_BOTTLE_H__ */