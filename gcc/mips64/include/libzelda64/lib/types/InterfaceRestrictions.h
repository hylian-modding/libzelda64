#ifndef INTERFACERESTRICTIONS_TYPE_H
#define INTERFACERESTRICTIONS_TYPE_H

#include <inttypes.h>

typedef struct InterfaceRestrictions {
    /* 0x00 */ uint8_t h_gage;     /* Heart, magic gauge, rupee, key */
    /* 0x01 */ uint8_t b_button;   /* B button */
    /* 0x02 */ uint8_t a_button;   /* A button */
    /* 0x03 */ uint8_t c_bottle;   /* Bottle */
    /* 0x04 */ uint8_t c_warasibe; /* Straw */
    /* 0x05 */ uint8_t c_hook;     /* Hook shot */
    /* 0x06 */ uint8_t c_ocarina;  /* Ocarina */
    /* 0x07 */ uint8_t c_warp;     /* Ocarina（warp）*/
    /* 0x08 */ uint8_t c_sunmoon;  /* Ocarina（Song of the sun）*/
    /* 0x09 */ uint8_t m_wind;     /* Magic (wind) */
    /* 0x0A */ uint8_t m_magic;    /* Magic (flame / love) */
    /* 0x0B */ uint8_t another;    /* Other C button */
} InterfaceRestrictions; /* sizeof = 0x0C */


#endif

