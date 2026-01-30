#include <stdio.h>
#include "fft_types.h"

void fft64(cq15_t *x);
void ifft64(cq15_t *x);

int main(void)
{
    cq15_t x[64] = {0};
    x[1].re = 32767;

    fft64(x);
    ifft64(x);

    printf("Recovered real[1] = %d\n", x[1].re);
    return 0;
}
