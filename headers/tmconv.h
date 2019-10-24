/*
 * tmconv.h
 *
 * tmconv
 * ==========
 *
 * Author   :  
 * Created  :  Thu Oct 24 08:56:34 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#pragma once

#include "dtmms_t.h"
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
} dtmfmt_t;

typedef struct tm_fmt_item_s {
    uint8_t id;
    char    name[5];
    dtmms_t    val;
} dtmfmt_item_t;

extern dtmfmt_item_t *dtmconv(char *dest, dtmms_t *src_ms, dtmfmt_t fmt);

extern dtmfmt_item_t *tmfmt_item(dtmms_t time, dtmfmt_t fmt);

extern char *dtmconv_group(char *dest, dtmms_t src_ms, dtmfmt_t fmt, uint8_t groups,
                       _Bool is_empty);
