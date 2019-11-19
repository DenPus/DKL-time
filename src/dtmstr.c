/*
 * dtm_strsec.c
 *
 * dtm_strsec()
 * =========
 * Get string default format from seconds
 *
 * Author   :  
 * Created  :  Thu Oct 24 11:27:53 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include "dtmstr.h"
#include <time.h>
#include <string.h>

int dtm_strsec(char *dst, time_t src) {
    int    len  = -1;
    char   *_dst;

#if _WIN64
    /*errno_t e = */ctime_s(dst, 100, &_src);
#else
    _dst = ctime_r(&src, dst);
#endif

    if (!_dst) {
        return len;
    }

    len = (int) strlen(dst) - 1;

    return len;
}
