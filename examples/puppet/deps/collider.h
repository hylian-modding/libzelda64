#ifndef __PUPPET_COLLIDER_H__
#define __PUPPET_COLLIDER_H__

// copy of Link's default ColliderCylinderInit
const ColliderCylinderInit colliderInit = {
    {   // ColiderInit base
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {   // ColliderInfoInit info
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 }, // ColliderTouch toucher
        { 0xFFCFFFFF, 0x00, 0x00 }, // ColliderBumpInit bumper
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    }, // Cylinder16 dim
    { 12, 60, 0, { 0, 0, 0 } },
};

// 1 damage unit = 1 / 16 heart when passed through Health_ChangeBy
// however, the damage nibble is 0-F, so we need to use effects to apply damage correctly
// in this case, we will store damage as 1 unit =  (1 / 16) / 4
const DamageTable damageTable = {
                        // first entry is amount of damage, second is effect index (0-15) which is entirely arbitrary (we have to impl)
    /* Deku nut      */ DMG_ENTRY(0x01, 0),
    /* Deku stick    */ DMG_ENTRY(0x08, 0),
    /* Slingshot     */ DMG_ENTRY(0x02, 0),
    /* Explosive     */ DMG_ENTRY(0x0A, 1),
    /* Boomerang     */ DMG_ENTRY(0x04, 0),
    /* Normal arrow  */ DMG_ENTRY(0x08, 2),
    /* Hammer swing  */ DMG_ENTRY(0x08, 0),
    /* Hookshot      */ DMG_ENTRY(0x01, 0),
    /* Kokiri sword  */ DMG_ENTRY(0x04, 0),
    /* Master sword  */ DMG_ENTRY(0x06, 0),
    /* Giant's Knife */ DMG_ENTRY(0x07, 0),
    /* Fire arrow    */ DMG_ENTRY(0x0A, 3),
    /* Ice arrow     */ DMG_ENTRY(0x0A, 4),
    /* Light arrow   */ DMG_ENTRY(0x0A, 5),
    /* Unk arrow 1   */ DMG_ENTRY(0x08, 2),
    /* Unk arrow 2   */ DMG_ENTRY(0x08, 2),
    /* Unk arrow 3   */ DMG_ENTRY(0x08, 2),
    /* Fire magic    */ DMG_ENTRY(0x04, 3),
    /* Ice magic     */ DMG_ENTRY(0x04, 4),
    /* Light magic   */ DMG_ENTRY(0x04, 5),
    /* Shield        */ DMG_ENTRY(0x00, 0), // ??
    /* Mirror Ray    */ DMG_ENTRY(0x00, 0), // ??
    /* Kokiri spin   */ DMG_ENTRY(0x06, 0),
    /* Giant spin    */ DMG_ENTRY(0x0F, 0),
    /* Master spin   */ DMG_ENTRY(0x0F, 0),
    /* Kokiri jump   */ DMG_ENTRY(0x08, 0),
    /* Giant jump    */ DMG_ENTRY(0x0E, 0),
    /* Master jump   */ DMG_ENTRY(0x06, 0),
    /* Unknown 1     */ DMG_ENTRY(0x00, 0),
    /* Unblockable   */ DMG_ENTRY(0x00, 0),
    /* Hammer jump   */ DMG_ENTRY(0x0C, 0),
    /* Unknown 2     */ DMG_ENTRY(0x00, 0)
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