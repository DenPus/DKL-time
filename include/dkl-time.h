/*
 * 
 * Author:   denkar
 * Created:  28.08.19 15:04
 */

#pragma once

#include <stdint.h>

typedef uint64_t tm_t;

typedef enum tm_device_e {
    TM_DEV_REALTIME,
    TM_DEV_MONOTONIC,
    TM_DEV_PROCESS_CPUTIME_ID,
    TM_DEV_THREAD_CPUTIME_ID,
    TM_DEV_MONOTONIC_RAW,
    TM_DEV_REALTIME_COARSE,
    TM_DEV_MONOTONIC_COARSE,
    TM_DEV_BOOTTIME,
    /*TIME_MONOTONIC_ACTIVE*/
}                tm_device_t;

typedef enum tm_fmt_e {
    TM_FMT_MILLISECOND,
    TM_FMT_SECOND,
    TM_FMT_MINUTE,
    TM_FMT_HOUR,
    TM_FMT_DAY,
    TM_FMT_WEEK,
    TM_FMT_MONTH,
    TM_FMT_YEAR
} tm_fmt_t;

typedef struct tm_fmt_item_s {
    uint8_t id;
    char name[5];
    tm_t val;
} tm_fmt_item_t;

extern tm_t timenow(tm_device_t dev);

tm_fmt_item_t *tm_get_fmt_item(tm_t time, tm_fmt_t fmt);

char *tm_convert_group(char *dest, tm_t src_ms, tm_fmt_t fmt, uint8_t groups,
                       _Bool is_empty);

extern void timestrf(char *dest, tm_t src, char *fmt);
