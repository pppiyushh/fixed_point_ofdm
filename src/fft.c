#include "fft_types.h"
#include "fixed_point.h"
#include "twiddle.h"

static void butterfly(cq15_t *a, cq15_t *b, cq15_t w)
{
    q15_t tr = q15_mul(b->re, w.re) - q15_mul(b->im, w.im);
    q15_t ti = q15_mul(b->re, w.im) + q15_mul(b->im, w.re);

    b->re = sat_q15(a->re - tr);
    b->im = sat_q15(a->im - ti);

    a->re = sat_q15(a->re + tr);
    a->im = sat_q15(a->im + ti);
}

void fft64(cq15_t *x)
{
    int step = 1;

    for (int stage = 0; stage < 6; stage++) {
        int jump = step << 1;
        for (int group = 0; group < step; group++) {
            cq15_t w = twiddle_64[group * (32 / step)];
            for (int pair = group; pair < 64; pair += jump) {
                butterfly(&x[pair], &x[pair + step], w);
            }
        }
        step = jump;
    }
}
