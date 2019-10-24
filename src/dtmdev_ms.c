/*
 * tmdev_ms.c
 *
 * tmdev_ms()
 * ==========
 * Get milliseconds from device
 *
 * Author   :
 * Created  :  28.08.19 15:14
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include "dtmdev_ms.h"
#include <time.h>
#include <stdint.h>

/* private */

static uint8_t tmdev_ls[8] = {
        CLOCK_REALTIME,
        CLOCK_MONOTONIC,
        CLOCK_PROCESS_CPUTIME_ID,
        CLOCK_THREAD_CPUTIME_ID,
        CLOCK_MONOTONIC_RAW,
        CLOCK_REALTIME_COARSE,
        CLOCK_MONOTONIC_COARSE,
        CLOCK_BOOTTIME,
        /*CLOCK_MONOTONIC_ACTIVE*/
};

/* public */

dtmms_t dtmdev_ms(dtmdev_t dev) {
    struct timespec spec;

    if (dev > 6) {
        dev = 0;
    }

    clock_gettime(tmdev_ls[dev], &spec);

    // Convert nanoseconds to milliseconds
    float ms = (float) (spec.tv_nsec / 1.0e6);

    dtmms_t dest = (dtmms_t) spec.tv_sec;
    dest *= 1000;
    dest += (uint16_t) ms;

    return dest;
}
