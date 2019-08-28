/*
 * 
 * Author:   denkar
 * Created:  28.08.19 15:04
 */

#pragma once

#include <time.h>
#include <stdint.h>

typedef enum time_device_e {
    TIME_REALTIME          ,
    TIME_MONOTONIC         ,
    TIME_BOOTTIME          ,
    TIME_REALTIME_COARSE   ,
    TIME_MONOTONIC_COARSE  ,
    TIME_PROCESS_CPUTIME_ID,
    TIME_THREAD_CPUTIME_ID
    /*TIME_MONOTONIC_ACTIVE*/
} time_device_t;

extern time_t timenow(time_device_t dev);

extern void timestrf(char *dest, time_t src, char *fmt);
