#ifndef MACROS_H
#define MACROS_H

#include <inttypes.h>

#define AVAL(base, type, offset) (*(type *)((uint8_t*)(base) + (offset)))
#define AADDR(a, o) ((void *)((uint8_t*)(a) + (o)))

#endif