#ifndef BETTERMATH_H
#define BETTERMATH_H

#include <libzelda64/lib/Math.h>

#define abs(value) value < 0 ? -(value) : (value)
float Math_PowF(float a, float b) {
    if (b == 1.0f) return a;
    if (b == 2.0f) return a * a;
    if (b == -1.0f) return 1.0f / a;
    if (b == 0.0f) return 1.0f;

    float low, high, sqr, acc, mid;

    if(b >= 1) {
        sqr = Math_PowF(a, b / 2);
        return sqr * sqr;
    }
    else {
        low = 0.0f;
        high = 1.0f;
        sqr = sqrtf(a);
        acc = sqr;
        mid = high / 2;

        while(abs(mid - b) > 0.000001f) {
            sqr = sqrtf(sqr);

            if (mid <= b) {
                low = mid;
                acc *= sqr;
            }
            else {
                high = mid;
                acc *= (1 / sqr);
            }
            mid = (low + high) / 2;
        }

        return acc;
    }
}

#undef abs

#endif

