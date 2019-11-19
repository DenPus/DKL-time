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

static uint8_t dtm_devices[8] = {
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

time_t dtm_secdev(dtmdev_t src) {
    int             err;
    struct timespec spec;

    err = clock_gettime(dtm_devices[src], &spec);

    time_t dst = (time_t) spec.tv_sec;

    return dst;
}

dtmms_t dtm_msdev(dtmdev_t src) {
    struct timespec spec;

    clock_gettime(dtm_devices[src], &spec);

    // Convert nanoseconds to milliseconds
    float ms = (float) (spec.tv_nsec / 1.0e6);

    dtmms_t dst = (dtmms_t) spec.tv_sec;
    dst *= 1000;
    dst += (uint16_t) ms;

    return dst;
}
