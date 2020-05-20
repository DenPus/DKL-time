/*
 * dtm_obj_t.h
 *
 * dtm_obj_t
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 12:30:13 2020)
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#pragma once

typedef struct {
    char   sec;
    char   min;
    char   hour;
    char   mday;
    char   month;
    short  year;
    char   wday;
    char   yday;
} dtm_obj_t;
