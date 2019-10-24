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

#include "tm_t.h"

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

extern dtmms_t dtmdev_ms(dtmdev_t dev);
