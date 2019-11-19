/*
 * tmconv.h
 *
 * tmconv()
 * ========
 * Convert time to string with format passed time
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
