#ifndef __PUPPET_COLLIDER_H__
#define __PUPPET_COLLIDER_H__

// copy of Link's default ColliderCylinderInit
const ColliderCylinderInit colliderInit = {
    {   // ColiderInit base
        COLTYPE_HIT7,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {   // ColliderInfoInit info
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 }, // ColliderTouch toucher
        { 0xFFCFFFFF, 0x00, 0x00 }, // ColliderBumpInit bumper
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    }, // Cylinder16 dim
    { 12, 60, 0, { 0, 0, 0 } },
};

/*
uint32_t unkchart[] =
    {
        0x0100000F, 0x001E1E00};

uint8_t damagechart[] =
    {
        0x10, 0xF2, 0x11, 0xF2, 0x11, 0xF2, 0xE2, 0x01,
        0x11, 0xE2, 0xE4, 0xF2, 0xD2, 0xF4, 0xF2, 0xF2,
        0xFF, 0x60, 0x60, 0x60, 0x00, 0x00, 0xE3, 0xE4,
        0xE5, 0xE5, 0xE5, 0xE6, 0xFA, 0x00, 0xE6, 0x00};
        actor->colChkInfo.damageTable->table[index] // index is 0 to 20

        z_actor_damage_table_init(AADDR(&en->actor, 0x98), &damagechart, &unkchart); // damage chart
*/

#endif /* __PUPPET_COLLIDER_H__ */