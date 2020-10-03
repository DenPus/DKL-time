/*
 * dtm_obj.h
 *
 * dtm_obj()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 12:30:13 2020)
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#pragma once

#include "dtmms_t.h"

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
