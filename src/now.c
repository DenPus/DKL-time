/*
 * 
 * Author:   denkar
 * Created:  28.08.19 15:14
 *
 * Get current time from devices
 */

#include "main.h"

/* static */

static uint8_t time_devices[7] = {
        CLOCK_REALTIME,
        CLOCK_MONOTONIC,
        CLOCK_BOOTTIME,
        CLOCK_REALTIME_COARSE,
        CLOCK_MONOTONIC_COARSE,
        CLOCK_PROCESS_CPUTIME_ID,
        CLOCK_THREAD_CPUTIME_ID
        /*CLOCK_MONOTONIC_ACTIVE*/
};

/* public */

time_t timenow(time_device_t dev) {
    struct timespec spec;

    if (dev > 6) {
        dev = 0;
    }

    clock_gettime(time_devices[dev], &spec);

    // Convert nanoseconds to milliseconds
    float ms = (float) (spec.tv_nsec / 1.0e6);

    time_t dest = (uint32_t) spec.tv_sec;
    dest *= 1000;
    dest += (uint16_t) ms;

    return dest;
}
