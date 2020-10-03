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

int dtm_obj(long time, dtmo_t *obj) {
    int    err;
    struct tm *utm;

    utm = localtime(&time);

    if (utm) {
        obj->sec   = (uint8_t) utm->tm_sec;
        obj->min   = (uint8_t) utm->tm_min;
        obj->hour  = (uint8_t) utm->tm_hour;
        obj->mday  = (uint8_t) utm->tm_mday;
        obj->month = (uint8_t) utm->tm_mon;
        obj->year  = (uint16_t) (utm->tm_year + 1900);

        err = 0;
    } else {
        err = 1;
    }

    return err;
}

dtm_t dtmo_tos(dtmo_t *src) {
    dtm_t ms = 0;

    ms += src->mday * 86400;
    ms += src->hour * 3600;
    ms += src->min * 60;
    ms += src->sec;
    return ms;
}
