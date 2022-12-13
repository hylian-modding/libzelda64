#ifndef __PUPPET_EQUIP_MASK_H__
#define __PUPPET_EQUIP_MASK_H__

#include <libzelda64.h>
#include "../Puppet.h"
#include "../LUTOffsets.h"
#include "../Macros.h"

enum {
    MASK_INDEX_NONE,
    MASK_INDEX_KEATON,
    MASK_INDEX_SKULL,
    MASK_INDEX_SPOOKY,
    MASK_INDEX_BUNNY_HOOD,
    MASK_INDEX_GORON,
    MASK_INDEX_ZORA,
    MASK_INDEX_GERUDO,
    MASK_INDEX_TRUTH,
    MASK_INDEX_COUNT
} Oot_Mask;

const uint32_t mask_dlists_oot[9] = {
    DL_DF,
    DL_MASK_KEATON,
    DL_MASK_SKULL,
    DL_MASK_SPOOKY,
    DL_MASK_BUNNY,
    DL_MASK_GORON,
    DL_MASK_ZORA,
    DL_MASK_GERUDO,
    DL_MASK_TRUTH
};

#ifdef GAME_OOT
void BunnyHood_Mtx_Setup(Puppet* thisx, GlobalContext* globalCtx) {
    
    Mtx *ear_mtx = obtainAlias(MATRIX_BUNNYHOOD0);    // Allocate 0x80 bytes of free space.
    Vec3s *r = &(thisx->syncInfo).bunnyHoodRot;
    Vec3s ear;
    gSPSegment(POLY_OPA_DISP++, 0x0B, ear_mtx);

    // Right Ear
    ear.x = r->y + 0x03E2;
    ear.y = r->z + 0x0D8E;
    ear.z = r->x + 0xCB76;
    Matrix_SoftCv3_Load(97.0f, -1203.0f, -240.0f, &ear);
    Matrix_ToMtx(ear_mtx, 0, 0);

    // Left Ear
    ear.x = r->y + 0xFC1E;
    ear.y = 0xF242 - r->z;
    ear.z = r->x + 0xCB76;
    Matrix_SoftCv3_Load(97.0f, -1203.0f, 240.0f, &ear);
    Matrix_ToMtx(ear_mtx + 1, 0, 0);
}
#elif defined GAME_MM
void BunnyHood_Mtx_Setup(Puppet* thisx, GlobalContext* globalCtx) {}
#endif

#endif /* __PUPPET_EQUIP_MASK_H__ */