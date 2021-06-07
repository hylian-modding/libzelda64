#ifndef INTERFACE_FUNC_H
#define INTERFACE_FUNC_H

#include <inttypes.h>
#include "types/InterfaceContext.h"

extern void Interface_LoadItemIcon1(struct GlobalContext* globalCtx, uint16_t button);
asm("Interface_LoadItemIcon1 = 0x8006FB50");

extern void Interface_LoadItemIcon2(struct GlobalContext* globalCtx, uint16_t button);
asm("Interface_LoadItemIcon2 = 0x8006FC00");

#endif