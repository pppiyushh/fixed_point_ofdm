#ifndef OFDM_CP_H
#define OFDM_CP_H

#include <stddef.h>
#include "fft_types.h"

/*
 * Adds cyclic prefix to a single OFDM symbol.
 * time_in  : FFT_LEN samples (time domain)
 * time_out : CP_LEN + FFT_LEN samples
 */
void ofdm_add_cp(
    const cq15_t *time_in,
    cq15_t *time_out,
    size_t fft_len,
    size_t cp_len
);

/*
 * Removes cyclic prefix from a single OFDM symbol.
 */
void ofdm_remove_cp(
    const cq15_t *time_in,
    cq15_t *time_out,
    size_t fft_len,
    size_t cp_len
);

#endif /* OFDM_CP_H */
