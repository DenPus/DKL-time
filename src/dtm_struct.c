/*
 * dtm_struct.c
 *
 * dtm_struct()
 * ==========
 *
 * Author   :  denkar
 * Created  :  05.09.20 10:22
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include "dtm_struct.h"

time_t dtm_struct(struct tm* src) {
    time_t tim_ms = 0;

    tim_ms += src->tm_mday * 86400;
    tim_ms += src->tm_hour * 3600;
    tim_ms += src->tm_min * 60;
    tim_ms += src->tm_sec;
    tim_ms *= 1000;

    return tim_ms;
}
