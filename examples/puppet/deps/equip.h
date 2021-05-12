#ifndef __PUPPET_EQUIP_H__
#define __PUPPET_EQUIP_H__

#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/types/Player.h>
#define F3DEX_GBI_2 1
#define _LANGUAGE_C 1
#include <libultra/PR/gbi.h>

#include "equip/gear.h"
#include "equip/bottle.h"
#include "equip/masks.h"
#include "equip/deku_stick.h"
#include "equip/boomerang.h"
#include "equip/fishing_pole.h"
#include "equip/hammer.h"

#define ITEM_OCARINA_FAIRY 0x07
#define ITEM_OCARINA_OF_TIME 0x08

// Left-Handed Weapons
#define ACTION_IS_DEKU_STICK (((this)->puppet).action.Params[0] == PLAYER_AP_STICK)
#define ACTION_IS_BOOMERANG (((this)->puppet).action.Params[0] == PLAYER_AP_BOOMERANG)
#define ACTION_IS_FISHING_POLE (((this)->puppet).action.Params[0] == PLAYER_AP_FISHING_POLE)
#define ACTION_IS_MEGATON_HAMMER (((this)->puppet).action.Params[0] == PLAYER_AP_HAMMER)
#define ACTION_IS_WEAPON ((((this)->puppet).action.Params[0] >= PLAYER_AP_FISHING_POLE && ((this)->puppet).action.Params[0] <= PLAYER_AP_LONGSHOT) || ((this)->puppet).action.Params[0] <= PLAYER_AP_BOOMERANG)
#define ACTION_IS_OCARINA (((((this)->puppet).action.Params[1] == PLAYER_AP_OCARINA_FAIRY) || (((this)->puppet).action.Params[1] == PLAYER_AP_OCARINA_TIME)) || ((((this)->puppet).action.Params[0] == PLAYER_AP_OCARINA_FAIRY) || (((this)->puppet).action.Params[0] == PLAYER_AP_OCARINA_TIME)))

// Right-Handed Items
#define ACTION_IS_BOW (                                              \
    ((this)->puppet).action.Params[1] == PLAYER_AP_BOW               \   
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_FIRE       \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_ICE        \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_LIGHT      \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_0C         \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_0D         \
    || ((this)->puppet).action.Params[1] == PLAYER_AP_BOW_0E         \
)                                                                    
#define ACTION_IS_SLINGSHOT (((this)->puppet).action.Params[1] == PLAYER_AP_SLINGSHOT)
#define ACTION_IS_HOOKSHOT (((this)->puppet).action.Params[1] == PLAYER_AP_HOOKSHOT)
#define ACTION_IS_LONGSHOT (((this)->puppet).action.Params[1] == PLAYER_AP_LONGSHOT)


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

#define RESET_ENV_TO_TUNIC(GFX) gDPSetEnvColor((GFX)->p++, ((this)->puppet).colorTunic.r, ((this)->puppet).colorTunic.g, ((this)->puppet).colorTunic.b, ((this)->puppet).colorTunic.a);

#endif /* __PUPPET_EQUIP_H__ */