/*
 * 
 * Author:   denkar
 * Created:  28.08.19 14:57
 */

#pragma once

#include <stdint.h>

typedef uint32_t dtm_t;     /* seconds */
typedef uint64_t dtmms_t;   /* milliseconds */
typedef uint64_t dtm_us_t;  /* microseconds */
typedef uint64_t dtm_ns_t;  /* nanoseconds */

typedef struct dtmo_s {
    uint8_t  month,
             mday,
             wday,
             hour,
             min,
             sec;
    uint16_t year,
             yday,
             msec,
             usec,
             nsec;
} dtmo_t;
