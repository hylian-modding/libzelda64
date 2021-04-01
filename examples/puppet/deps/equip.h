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

#define ACTION_MASTER_SWORD PLAYER_AP_SWORD_MASTER
#define ACTION_KOKIRI_SWORD PLAYER_AP_SWORD_KOKIRI
#define ACTION_BIGGORON_SWORD PLAYER_AP_SWORD_BGS
#define ACTION_DEKU_STICK PLAYER_AP_STICK
#define ACTION_HAMMER_TIME PLAYER_AP_HAMMER

#define ACTION_BOTTLE(action)(action >= PLAYER_AP_BOTTLE && action <= PLAYER_AP_BOTTLE_FAIRY)

#endif /* __PUPPET_EQUIP_H__ */

// static void draw_bottle(z64_global_t* gl, entity_t* en, int32_t id)
// {
//   z64_disp_buf_t* xlu = &ZQDL(gl, poly_xlu);
//   /* Bottle + Contents */


//   /* Set Environment Color */
//   gDPSetEnvColor(
//    xlu->p++
//   , bottle_colors[id].r
//   , bottle_colors[id].g
//   , bottle_colors[id].b
//   , 255
//   );
//   if (zh_link_is_adult())
//     z_cheap_proc_draw_xlu(gl, OOT_ZZ_PUPPET_DLIST(OOT_ADULT_BOTTLE));
//   else
//     z_cheap_proc_draw_xlu(gl, OOT_ZZ_PUPPET_DLIST(OOT_CHILD_BOTTLE));
//   /* Restore Environment Color */
//   gDPSetEnvColor(
//    xlu->p++
//   , en->puppetData.tunicColor.r
//   , en->puppetData.tunicColor.g
//   , en->puppetData.tunicColor.b
//   , en->puppetData.tunicColor.a
//   );
// }

//fuck
Color_RGB8 bottle_colors[] = {
    {
        0xFF,
        0xFF,
        0xFF
    },
    /* Empty Bottle */ {
        0x50,
        0x50,
        0xFF
    } /* Fish */ ,
    {
        0xFF,
        0x64,
        0xFF
    } /* Blue Fire */ ,
    {
        0x00,
        0x00,
        0xFF
    } /* Bugs */ ,
    {
        0xFF,
        0x00,
        0xFF
    } /* Poe */ ,
    {
        0xFF,
        0x00,
        0xFF
    } /* Big Poe */ ,
    {
        0xC8,
        0xC8,
        0x64
    } /* Ruto's Letter */ ,
    {
        0xFF,
        0x00,
        0x00
    } /* Red Potion */ ,
    {
        0x00,
        0x00,
        0xFF
    } /* Blue Potion */ ,
    {
        0x00,
        0xFF,
        0x00
    } /* Green Potion */ ,
    {
        0xFF,
        0xFF,
        0xFF
    } /* Milk (Full) */ ,
    {
        0xFF,
        0xFF,
        0xFF
    } /* Milk (Half) */ ,
    {
        0x50,
        0x50,
        0xFF
    } /* Fairy */
};

#define RESOLVE_BOTTLE_COLOR(action)(bottle_colors[action - 30])