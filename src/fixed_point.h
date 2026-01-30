#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

typedef int16_t q15_t;
typedef int32_t q31_t;

static inline q15_t sat_q15(q31_t x)
{
    if (x > 32767)  return 32767;
    if (x < -32768) return -32768;
    return (q15_t)x;
}

/* Q15 multiplication with rounding */
static inline q15_t q15_mul(q15_t a, q15_t b)
{
    return sat_q15((q31_t)a * b >> 15);
}

#endif
