#ifndef __PUPPET_EQUIP_STICK_H__
#define __PUPPET_EQUIP_STICK_H__

#include <libzelda64/types/GlobalContext.h>

#define DEKU_STICK_IS_BROKEN ((((this)->puppet).deku_stick).length < 1.0f)

void DrawDekuStick(GlobalContext* globalCtx, En_Puppet* this) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    Matrix_Push();
    {
        Matrix_Translate(-428.26f, 267.20f, -33.82f, 1);
        Matrix_RotateRPY(0x8000, 0, 0x4000, 1);
        Matrix_Scale(1.0f, ((this)->puppet).dekuStickLength, 1.0f, 1);
        Gfx_DrawDListOpa(globalCtx, PROXY_LINK_DL_STICK);
    }
    Matrix_Pop();
}

#endif /* __PUPPET_EQUIP_STICK_H__ */