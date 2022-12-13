#ifndef __PUPPET_EQUIP_H__
#define __PUPPET_EQUIP_H__

#include <libzelda64.h>
#include <ultra64.h>
#include <PR/gbi.h>

#include "equip/gear.h"
#include "equip/bottle.h"
#include "equip/masks.h"
#include "equip/dekustick.h"
#include "equip/boomerang.h"
#include "equip/fishingpole.h"
#include "equip/hammer.h"

#define ITEM_OCARINA_FAIRY 0x07
#define ITEM_OCARINA_OF_TIME 0x08

// Left-Handed Weapons
#define ACTION_OOT_IS_DEKU_STICK (((thisx)->syncInfo).actionParams[0] == PLAYER_AP_STICK)
#define ACTION_OOT_IS_BOOMERANG (((thisx)->syncInfo).actionParams[0] == PLAYER_AP_BOOMERANG)
#define ACTION_OOT_IS_FISHING_POLE (((thisx)->syncInfo).actionParams[0] == PLAYER_AP_FISHING_POLE)
#define ACTION_OOT_IS_MEGATON_HAMMER (((thisx)->syncInfo).actionParams[0] == PLAYER_AP_HAMMER)
#define ACTION_OOT_IS_WEAPON ((((thisx)->syncInfo).actionParams[0] >= PLAYER_AP_FISHING_POLE && ((thisx)->syncInfo).actionParams[0] <= PLAYER_AP_LONGSHOT) || ((thisx)->syncInfo).actionParams[0] <= PLAYER_AP_BOOMERANG)
#define ACTION_OOT_IS_OCARINA (((((thisx)->syncInfo).actionParams[1] == PLAYER_AP_OCARINA_FAIRY) || (((thisx)->syncInfo).actionParams[1] == PLAYER_AP_OCARINA_TIME)) || ((((thisx)->syncInfo).actionParams[0] == PLAYER_AP_OCARINA_FAIRY) || (((thisx)->syncInfo).actionParams[0] == PLAYER_AP_OCARINA_TIME)))

// Right-Handed Items
#define ACTION_OOT_IS_BOW (                                              \
    ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW               \
    || ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW_FIRE       \
    || ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW_ICE        \
    || ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW_LIGHT      \
    || ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW_0C         \
    || ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW_0D         \
    || ((thisx)->syncInfo).actionParams[1] == PLAYER_AP_BOW_0E         \
)
#define ACTION_OOT_IS_SLINGSHOT (((thisx)->syncInfo).actionParams[1] == PLAYER_AP_SLINGSHOT)
#define ACTION_OOT_IS_HOOKSHOT (((thisx)->syncInfo).actionParams[1] == PLAYER_AP_HOOKSHOT)
#define ACTION_OOT_IS_LONGSHOT (((thisx)->syncInfo).actionParams[1] == PLAYER_AP_LONGSHOT)

#define SLASH_INDEX(ACTION) {                   \
    uint8_t out = 0;                            \
    switch((ACTION))                            \
    {                                           \
        case ACTION_OOT_IS_KOKIRI_SWORD:            \
            out = 2;                            \
            break;                              \
        case ACTION_OOT_IS_MASTER_SWORD:            \
            out = 1;                            \
            break;                              \
        case ACTION_OOT_IS_BIGGORON_SWORD:          \
            out = 3;                            \
            break;                              \
        case ACTION_OOT_IS_MEGATON_HAMMER:          \
            out = 5;                            \
            break;                              \
        case ACTION_OOT_IS_DEKU_STICK:              \
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
//#define ACTION_OOT_BOTTLE(action)(action >= PLAYER_AP_BOTTLE && action <= PLAYER_AP_BOTTLE_FAIRY)

#endif /* __PUPPET_EQUIP_H__ */