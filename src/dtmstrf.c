/*
 * tmfmt.c
 *
 * tmfmt
 * ==========
 * Time to string by format
 *
 * Author   :
 * Created  :  28.08.19 14:30
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include "dtmstrf.h"
#include <time.h>
#include <string.h>

void dtmstrf(char *dst, dtmms_t src, char *fmt) {
    time_t _src = src / 1000;
/*    if (fmt) {
        char      strTime[200];
        struct tm *u;

        u = localtime(&timer);
        
        strftime(strTime, 200, fmt->val, u);

        fmtStr = strTime;
    } else {*/

    if (fmt) {
        strftime(dst, 100, fmt, gmtime(&_src));
    } else {
#if _WIN64
        /*errno_t e = */ctime_s(dst, 100, &_src);
#else
        /*dst = */ctime_r(&_src, dst);
#endif
        size_t len = strlen(dst);

        if (len) {
            dst[len - 1] = '\0';
        }
    }
}
