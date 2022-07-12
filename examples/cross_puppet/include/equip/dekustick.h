#ifndef __PUPPET_EQUIP_STICK_H__
#define __PUPPET_EQUIP_STICK_H__

#include <libzelda64.h>
#include "../Puppet.h"
#include "../LUTOffsets.h"
#include "../Macros.h"

#define DEKU_STICK_IS_BROKEN ((((this)->puppet).deku_stick).length < 1.0f)

void DrawDekuStick(GlobalContext* globalCtx, Puppet* thisx) {
    
    Matrix_Push();
    {
        Matrix_Translate(-428.26f, 267.20f, -33.82f, 1);
        Matrix_RotateRPY(0x8000, 0, 0x4000, 1);
        Matrix_Scale(1.0f, ((thisx)->syncInfo).dekuStickLength, 1.0f, 1);
        Gfx_DrawDListOpa(globalCtx, obtainAlias(DL_DEKU_STICK));
    }
    Matrix_Pop();
}

#endif /* __PUPPET_EQUIP_STICK_H__ */