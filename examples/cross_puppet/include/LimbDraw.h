#ifndef PUPPET_LIMBDRAW_H
#define PUPPET_LIMBDRAW_H

#include "Puppet.h"
#include <ultra64.h>

extern int32_t LimbDrawOpa_Override(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Puppet* thisx);
extern void LimbDrawOpa_Post(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dList, Vec3s* rot, Puppet* thisx);

#endif

