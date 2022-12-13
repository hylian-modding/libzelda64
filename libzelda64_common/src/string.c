#include "string.h"

s32 memcmp(const u8* lhs, const u8* rhs, SIZE_TYPE length) {
    register u8* lh = lhs;
    register u8* rh = rhs;
    register u8 lv;
    register u8 rv;

    while (length-- > 0) {
        lv = *lh++;
        rv = *rh++;

        if (lv != rv) {
            if (lv < rv) {
                return -1;
            }
            else {
                return 1;
            }
        }
    }

    return 0;
}

s32 strncmp(const u8* lhs, const u8* rhs, SIZE_TYPE length) {
    register u8* lh = lhs;
    register u8* rh = rhs;
    register u8 lv;
    register u8 rv;

    while (length-- > 0) {
        lv = *lh++;
        rv = *rh++;

        if (lv != rv) {
            return lv - rv;
        }
        
        if (lv == '\0') {
            return 0;
        }
    }

    return 0;
}


s32 atoi(const char* str) {
    register char* s = str;
    register char v;
    s16 sign;
    s16 num;
    s32 sum;

    while(*s == ' ') {
        s++;
    }

    switch (*s) {
        case ('-'): {
            sign = 1;
            break;
        }
        case ('+'): {
            sign = 0;
            break;
        }
    }

    while(v = *s++) {
        num = v - '0';
        if (num > 9 || num < 0) {
            break;
        }

        sum = num + (10 * sum);
    }

    if (sign) {
        return -sum;
    }
    else {
        return sum;
    }
}

s64 atol(const char* str) {
    register char* s = str;
    register char v;
    s16 sign;
    s16 num;
    s64 sum;

    while(*s == ' ') {
        s++;
    }

    switch (*s) {
        case ('-'): {
            sign = 1;
            break;
        }
        case ('+'): {
            sign = 0;
            break;
        }
    }

    while(v = *s++) {
        num = v - '0';
        if (num > 9 || num < 0) {
            break;
        }

        sum = num + (10 * sum);
    }

    if (sign) {
        return -sum;
    }
    else {
        return sum;
    }
}
