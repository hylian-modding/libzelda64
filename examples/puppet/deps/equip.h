#ifndef __PUPPET_EQUIP_H__
#define __PUPPET_EQUIP_H__

#include <libzelda64/lib/types/Player.h>

#define SWORD0 0x3B
#define SWORD1 0x3C
#define SWORD2 0x3D

#define SHIELD0 0x01
#define SHIELD1 0x02
#define SHIELD2 0x03

#define KOKIRI_SWORD SWORD0
#define MASTER_SWORD SWORD1
#define BIGGORON_SWORD SWORD2

#define DEKU_SHIELD SHIELD0
#define HYLIAN_SHIELD SHIELD1
#define MIRROR_SHIELD SHIELD2

// Left-Handed Weapons
#define ACTION_IS_SWORD (((this)->puppet).action.Params[0] >= PLAYER_AP_SWORD_MASTER && ((this)->puppet).action.Params[0] <= PLAYER_AP_SWORD_BGS)
#define ACTION_IS_KOKIRI_SWORD (((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_KOKIRI)
#define ACTION_IS_MASTER_SWORD (((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_MASTER)
#define ACTION_IS_BIGGORON_SWORD (((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_BGS)
#define ACTION_IS_DEKU_STICK (((this)->puppet).action.Params[0] == PLAYER_AP_STICK)
#define ACTION_IS_BOOMERANG (((this)->puppet).action.Params[0] == PLAYER_AP_BOOMERANG)
#define ACTION_IS_FISHING_POLE (((this)->puppet).action.Params[0] == PLAYER_AP_FISHING_POLE)
#define ACTION_IS_MEGATON_HAMMER (((this)->puppet).action.Params[0] == PLAYER_AP_HAMMER)
#define ACTION_IS_WEAPON ((((this)->puppet).action.Params[0] >= PLAYER_AP_FISHING_POLE && ((this)->puppet).action.Params[0] <= PLAYER_AP_LONGSHOT) || ((this)->puppet).action.Params[0] <= PLAYER_AP_BOOMERANG)

// Right-Handed Items
#define ACTION_IS_BOW (                                              \
    ((this)->puppet).action.Params[1] == PLAYER_AP_BOW               \   
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_FIRE       \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_ICE        \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_LIGHT      \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_0C         \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_0D         \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_0E         \
)                                                                    \
#define ACTION_IS_SLINGSHOT (((this)->puppet).action.Params[1] == PLAYER_AP_SLINGSHOT)
#define ACTION_IS_HOOKSHOT (((this)->puppet).action.Params[1] == PLAYER_AP_HOOKSHOT)
#define ACTION_IS_LONGSHOT (((this)->puppet).action.Params[1] == PLAYER_AP_LONGSHOT)
#define ACTION_IS_SHIELD (((this)->puppet).action.Params[1] == 0xFF)
#define SHIELD_IS_DEKU (((this)->puppet).currentShield == SHIELD0)
#define SHIELD_IS_HYLIAN (((this)->puppet).currentShield == SHIELD1)
#define SHIELD_IS_MIRROR (((this)->puppet).currentShield == SHIELD2)

#define DEKU_STICK_IS_BROKEN (((this)->puppet).deku_stick.length < 1.0f)
//#define KNIFE_IS_BROKEN
#define SLASH_INDEX(ACTION) {                   \
    uint8_t out = 0;                            \
    switch((ACTION))                            \
    {                                           \
        case ACTION_IS_KOKIRI_SWORD:            \
            out = 2;                            \
            break;                              \
        case ACTION_IS_MASTER_SWORD:            \
            out = 1;                            \
            break;                              \
        case ACTION_IS_BIGGORON_SWORD:          \
            out = 3;                            \
            break;                              \
        case ACTION_IS_MEGATON_HAMMER:          \
            out = 5;                            \
            break;                              \
        case ACTION_IS_DEKU_STICK:              \
            out = DEKU_STICK_IS_BROKEN ? 5 : 3; \
            break;                              \
    }                                           \
    return out;                                 \
}                                               \

// Slash Lengths
float slash_length_table[6] = {
    0.0f,
    4000.0f,
    3000.0f,
    5500.0f,
    0.0f,
    2500.0f
};

// Bottles
//#define ACTION_BOTTLE(action)(action >= PLAYER_AP_BOTTLE && action <= PLAYER_AP_BOTTLE_FAIRY)
#define ACTION_IS_BOTTLE (((this)->puppet).action.Params[1] >= PLAYER_AP_BOTTLE && ((this)->puppet).action.Params[1] <= PLAYER_AP_BOTTLE_FAIRY)
#define BOTTLE_INDEX (((this)->puppet).action.Params[1] - 30)

Color_RGB8 contents[13] = {
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

#define RESET_ENV_TO_TUNIC(GFX) gDPSetEnvColor((GFX)->p++, ((this)->puppet).colorTunic.r, ((this)->puppet).colorTunic.g, ((this)->puppet).colorTunic.b, ((this)->puppet).colorTunic.a);

#endif /* __PUPPET_EQUIP_H__ */