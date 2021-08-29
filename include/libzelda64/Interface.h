#ifndef INTERFACE_FUNC_H
#define INTERFACE_FUNC_H

#include "types/InterfaceContext.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void Interface_LoadItemIcon1(struct GlobalContext* globalCtx, uint16_t button);
SYMBOL_VERSION_CONFIG(Interface_LoadItemIcon1, 0x8006FB50, 0x80112B40);

extern void Interface_LoadItemIcon2(struct GlobalContext* globalCtx, uint16_t button);
SYMBOL_VERSION_CONFIG(Interface_LoadItemIcon2, 0x8006FC00, 0x80112BE4);

#endif