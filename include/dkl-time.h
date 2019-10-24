/*
 * dkl-time.h
 *
 * Headers dkl-time
 * =============
 * DKL time - library for working with time
 *
 * Author   :   denkar
 * Created  :   24.10.19 09:39 (base 28.08.19 15:04)
 * Homepage :   https://github.com/Denpus/DKL-time#README.md
 * License  :   GPL-2.0
 * Version  :   0.1.5.0
 *
 * Copyright (C) Denis Karabadjak <denkar>
 */

#pragma once

#include <stdint.h>

typedef uint64_t dtmms_t;

typedef enum tmdev_e {
    DTMDEV_REALTIME,
    DTMDEV_MONOTONIC,
    DTMDEV_PROCESS_CPUTIME_ID,
    DTMDEV_THREAD_CPUTIME_ID,
    DTMDEV_MONOTONIC_RAW,
    DTMDEV_REALTIME_COARSE,
    DTMDEV_MONOTONIC_COARSE,
    DTMDEV_BOOTTIME,
    DTMDEV_MONOTONIC_ACTIVE,
}                dtmdev_t;

extern dtmms_t dtmdev_ms(dtmdev_t dev);

#include <stdint.h>

typedef enum dtmfmt_e {
    TM_FMT_MILLISECOND,
    TM_FMT_SECOND,
    TM_FMT_MINUTE,
    TM_FMT_HOUR,
    TM_FMT_DAY,
    TM_FMT_WEEK,
    TM_FMT_MONTH,
    TM_FMT_YEAR
}                dtmfmt_t;

typedef struct tm_fmt_item_s {
    uint8_t id;
    char    name[5];
    dtmms_t val;
}                dtmfmt_item_t;

extern dtmfmt_item_t *dtmconv(char *dest, dtmms_t *src_ms, dtmfmt_t fmt);

extern dtmfmt_item_t *tmfmt_item(dtmms_t time, dtmfmt_t fmt);

extern char *
dtmconv_group(char *dest, dtmms_t src_ms, dtmfmt_t fmt, uint8_t groups,
              _Bool is_empty);

extern void timestrf(char *dest, dtmms_t src, char *fmt);

#include <time.h>

extern int dtmstr(char *dest, time_t sec);

extern int dtmstr_ms(char *dest, dtmms_t ms);

// @deprecated

typedef dtmms_t tm_t;
#define tm_fmt_item_t dtmfmt_item_t
#define tm_convert dtmconv
#define tm_convert_group dtmconv_group
#define tm_get_fmt_item tmfmt_item
#define timenow dtmdev_ms

#define TM_DEV_REALTIME            DTMDEV_REALTIME
#define TM_DEV_MONOTONIC           DTMDEV_MONOTONIC
#define TM_DEV_PROCESS_CPUTIME_ID  DTMDEV_PROCESS_CPUTIME_ID
#define TM_DEV_THREAD_CPUTIME_ID   DTMDEV_THREAD_CPUTIME_ID
#define TM_DEV_MONOTONIC_RAW      DTMDEV_MONOTONIC_RAW
#define TM_DEV_REALTIME_COARSE    DTMDEV_REALTIME_COARSE
#define TM_DEV_MONOTONIC_COARSE   DTMDEV_MONOTONIC_COARSE
#define TM_DEV_BOOTTIME           DTMDEV_BOOTTIME

