/*
 * 
 * Author:   denkar
 * Created:  28.08.19 15:04
 */

#pragma once

#include <stdint.h>

typedef uint64_t tm_t;

typedef enum tm_device_e {
    TM_REALTIME          ,
    TM_MONOTONIC         ,
    TM_BOOTTIME          ,
    TM_REALTIME_COARSE   ,
    TM_MONOTONIC_COARSE  ,
    TM_PROCESS_CPUTIME_ID,
    TM_THREAD_CPUTIME_ID
    /*TIME_MONOTONIC_ACTIVE*/
} tm_device_t;

extern tm_t timenow(tm_device_t dev);

extern void timestrf(char *dest, tm_t src, char *fmt);
