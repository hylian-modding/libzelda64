#ifndef __PUPPET_EQUIP_HAMMER_H__
#define __PUPPET_EQUIP_HAMMER_H__

#include <libzelda64.h>

void draw_hammer(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

        gSPMatrix(polyOpa->p++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        gSPDisplayList(polyOpa->p++, baseToPointer(this, PROXY_LINK_DL_HAMMER));
    }
    Matrix_Pop();
}

#endif /* __PUPPET_EQUIP_HAMMER_H__ */