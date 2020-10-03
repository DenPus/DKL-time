/*
 * dkl-time.h
 *
 * Headers dkl-time
 * ================
 * DKL time - library for working with time
 *
 * Author   :   denkar
 * Created  :   24.10.19 09:39 (base 28.08.19 15:04)
 * Homepage :   https://github.com/Denpus/DKL-time#README.md
 * License  :   GPL-2.0
 * Version  :   0.9.9
 *
 * Copyright (C) Denis Karabadjak <denkar>
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

#include <time.h>

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
} dtmdev_t;

extern time_t dtm_secdev(dtmdev_t src);

extern dtmms_t dtm_msdev(dtmdev_t src);

#define dtm_strdev(dst, dev) dtm_strsec(dst, dtm_secdev(dev))

#define dtm_strfdev(dst, dev, nfmt, fmt) dtm_strfsec(dst, dtm_secdev(dev), nfmt, fmt)

#include <stdint.h>

typedef enum dtmfmt_e {
    DTM_FMT_MILLISECOND,
    DTM_FMT_SECOND,
    DTM_FMT_MINUTE,
    DTM_FMT_HOUR,
    DTM_FMT_DAY,
    DTM_FMT_WEEK,
    DTM_FMT_MONTH,
    DTM_FMT_YEAR
} dtmfmt_t;

typedef struct tm_fmt_item_s {
    uint8_t id;
    char    name[5];
    dtmms_t val;
} dtmfmt_item_t;

extern dtmfmt_item_t *dtmconv(char *dst, dtmms_t *src_ms, dtmfmt_t fmt);

extern dtmfmt_item_t *dtmfmt_item(dtmms_t time, dtmfmt_t fmt);

extern char *
dtmconv_group(char *dst, dtmms_t src_ms, dtmfmt_t fmt, uint8_t groups,
              _Bool is_empty);

#include <time.h>

extern int dtm_strfsec(char *dst, time_t src, int nfmt, char *fmt);

#define dtm_strfms(dst, src, nfmt, fmt) dtm_strfsec(dst, src / 1000, nfmt, fmt)

#include <time.h>

extern int dtm_strsec(char *dst, time_t src);

#define dtm_strms(dst, src) dtm_strsec(dst, src / 1000)

/* */

extern int dtm_obj(long time, dtmo_t *obj);

/* object convert to int */

extern dtm_t dtmo_tos(dtmo_t *src);

#define dtmo_toms(src)                                                         \
    ((dtmms_t )(dtmo_tos(src) * 1000ul) + (src)->msec)

#define dtmo_tous(src)                                                         \
    ((dtmms_t )(dtmo_tos(src) * 1000ul) + (src)->usec)

#define dtmo_tons(src)                                                         \
    ((dtmms_t )(dtmo_tos(src) * 1000ul) + (src)->nsec)

/* init struct */

#define dtmo(_yday, _nonth, _mday, _wday, _hour, _min, _s, _ms, _us, _ns)      \
    ((dtmo_t ){                                                                \
        .yday  = _yday,                                                        \
        .mday  = _mday,                                                        \
        .month = _nonth,                                                       \
        .wday  = _wday,                                                        \
        .hour  = _hour,                                                        \
        .min   = _min,                                                         \
        .sec   = _s,                                                           \
        .msec  = _ms,                                                          \
        .usec  = _us,                                                          \
        .nsec  = _ns,                                                          \
    })

#define dtmo_year(yday, month, mday, wday, hour, min, sec, ms, us, ns)         \
    dtmo(yday, month, mday, wday, hour, min, sec, ms, us, ns)

#define dtmo_month(mday, wday, hour, min, sec, ms, us, ns)                     \
    dtmo(0, 0, mday, wday, hour, min, sec, ms, us, ns)

#define dtmo_week(wday, hour, min, sec, ms, us, ns)                            \
    dtmo_month(0, wday, hour, min, sec, ms, us, ns)

#define dtmo_day(hour, min, sec, ms, us, ns)                                   \
    dtmo_week(0, hour, min, sec, ms, us, ns)

#define dtmo_hour(min, sec, ms, us, ns)                                        \
    dtmo_day(0, min, sec, ms, us, ns)

#define dtmo_min(sec, ms, us, ns)                                              \
    dtmo_hour(0, sec, ms, us, ns)

#define dtmo_sec(ms, us, ns)                                                   \
    dtmo_min(0, ms, us, ns)

/* */

typedef struct {
    short id;
    char  wday, _wday;
    _Bool lear:1;
} dtm_year_t;

extern int dtm_year(dtm_year_t *year);

typedef struct {
    char id, len, wday;
} dtm_moth_t;

extern int dtm_month(dtm_year_t *year, dtm_moth_t *month);

// @deprecated

typedef dtmms_t tm_t;
#define tm_fmt_item_t dtmfmt_item_t
#define tm_convert dtmconv
#define tm_convert_group dtmconv_group
#define tm_get_fmt_item dtmfmt_item
#define timenow dtm_msdev
#define timestrf dtm_strfsec

#define TM_DEV_REALTIME             DTMDEV_REALTIME
#define TM_DEV_MONOTONIC            DTMDEV_MONOTONIC
#define TM_DEV_PROCESS_CPUTIME_ID  DTMDEV_PROCESS_CPUTIME_ID
#define TM_DEV_THREAD_CPUTIME_ID   DTMDEV_THREAD_CPUTIME_ID
#define TM_DEV_MONOTONIC_RAW       DTMDEV_MONOTONIC_RAW
#define TM_DEV_REALTIME_COARSE     DTMDEV_REALTIME_COARSE
#define TM_DEV_MONOTONIC_COARSE    DTMDEV_MONOTONIC_COARSE
#define TM_DEV_BOOTTIME            DTMDEV_BOOTTIME

#define TM_FMT_MILLISECOND          DTM_FMT_MILLISECOND
#define TM_FMT_SECOND               DTM_FMT_SECOND
#define TM_FMT_MINUTE               DTM_FMT_MINUTE
#define TM_FMT_HOUR                 DTM_FMT_HOUR
#define TM_FMT_DAY                  DTM_FMT_DAY
#define TM_FMT_WEEK                 DTM_FMT_WEEK
#define TM_FMT_MONTH                DTM_FMT_MONTH
#define TM_FMT_YEA                  DTM_FMT_YEA
