/*
 * tmdev_ms.h
 *
 * tmdev_ms()
 * ==========
 * Get milliseconds from device
 *
 * Author   :  
 * Created  :  Thu Oct 24 08:56:34 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#pragma once

#include "dtmms_t.h"
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
