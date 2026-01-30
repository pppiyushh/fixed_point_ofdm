#include "fft_types.h"
#include "fixed_point.h"

void ifft64(cq15_t *x)
{
    /* Conjugate */
    for (int i = 0; i < 64; i++)
        x[i].im = -x[i].im;

    fft64(x);

    /* Conjugate + scale */
    for (int i = 0; i < 64; i++) {
        x[i].re >>= 6;
        x[i].im = -(x[i].im >> 6);
    }
}
