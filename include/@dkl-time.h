/*
 * @name\.h
 *
 * Headers @name
 * ================
 * @description
 *
 * Author   :   denkar
 * Created  :   24.10.19 09:39 (base 28.08.19 15:04)
 * Homepage :   @homepage
 * License  :   @license
 * Version  :   @version
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#pragma once

@include("../headers/dtmms_t.h" "#include <")
@include("../headers/dtmdev_ms.h" "typedef enum")
@include("../headers/dtmconv.h" "#include <")
@include("../headers/dtmstrf.h" "extern ")
@include("../headers/dtmstr.h" "#include <")
@include("../headers/dtmstr_ms.h" "extern ")

// \@deprecated

typedef dtmms_t tm_t;
#define tm_fmt_item_t dtmfmt_item_t
#define tm_convert dtmconv
#define tm_convert_group dtmconv_group
#define tm_get_fmt_item dtmfmt_item
#define timenow dtmdev_ms
#define timestrf dtmstrf

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
