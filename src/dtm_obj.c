/*
 * dtm_obj.c
 *
 * dtm_obj()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 12:30:13 2020
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#include "dtm_obj.h"
#include <time.h>

int dtm_obj(long time, dtm_obj_t *obj) {
    int    err;
    struct tm *utm;

    utm = localtime(&time);

    if (utm) {
        obj->sec   = (char) utm->tm_sec;
        obj->min   = (char) utm->tm_min;
        obj->hour  = (char) utm->tm_hour;
        obj->mday  = (char) utm->tm_mday;
        obj->month = (char) utm->tm_mon;
        obj->year  = (short) (utm->tm_year + 1900);

        err = 0;
    } else {
        err = 1;
    }

    return err;
}
