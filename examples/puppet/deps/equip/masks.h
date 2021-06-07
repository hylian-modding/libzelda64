#ifndef __PUPPET_EQUIP_MASK_H__
#define __PUPPET_EQUIP_MASK_H__

#include <libzelda64/lib/types/GlobalContext.h>
#include "../lut_offsets.h"
#include "../../puppet.h"

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

const uint32_t mask_dlists[8] = {
    CHILD_LINK_LUT_DL_MASK_KEATON,
    CHILD_LINK_LUT_DL_MASK_SKULL,
    CHILD_LINK_LUT_DL_MASK_SPOOKY,
    CHILD_LINK_LUT_DL_MASK_BUNNY,
    CHILD_LINK_LUT_DL_MASK_GORON,
    CHILD_LINK_LUT_DL_MASK_ZORA,
    CHILD_LINK_LUT_DL_MASK_GERUDO,
    CHILD_LINK_LUT_DL_MASK_TRUTH
};

void BunnyHood_Mtx_Setup(En_Puppet* this, GlobalContext* globalCtx) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    Mtx *ear_mtx = ((Mtx*)baseToPointer(this, PROXY_LINK_MTX_BUNNY1));    // Allocate 0x80 bytes of free space.
    Vec3s *r = &(this->puppet).bunnyHoodRot;
    Vec3s ear;
    gSPSegment(polyOpa->p++, 0x0B, ear_mtx);

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

#endif /* __PUPPET_EQUIP_MASK_H__ */