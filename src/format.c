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

#include "tmfmt.h"
#include <time.h>
#include <string.h>

void timestrf(char *dest, dtmms_t src, char *fmt) {
    time_t _src = src / 1000;
/*    if (fmt) {
        char      strTime[200];
        struct tm *u;

        u = localtime(&timer);
        
        strftime(strTime, 200, fmt->val, u);

        fmtStr = strTime;
    } else {*/

    if (fmt) {
        strftime(dest, 100, fmt, gmtime(&_src));
    } else {
#if _WIN64
        /*errno_t e = */ctime_s(dest, 100, &_src);
#else
        /*dest = */ctime_r(&_src, dest);
#endif
        size_t len = strlen(dest);

        if (len) {
            dest[len - 1] = '\0';
        }
    }
}
