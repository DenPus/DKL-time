/*
 * dtmstr_ms.c
 *
 * dtmstr_ms()
 * ===========
 * Get string default format from milliseconds
 *
 * Author   :  
 * Created  :  Thu Oct 24 11:49:16 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include "dtmms_t.h"
#include "dtmstr_ms.h"
#include "dtmstr.h"

int dtmstr_ms(char *dst, dtmms_t ms) {
    time_t sec = ms / 1000;

    return dtmstr(dst, sec);
}
