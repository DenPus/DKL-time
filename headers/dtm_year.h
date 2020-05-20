/*
 * dtm_year.h
 *
 * dtm_year()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 13:49:58 2020)
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#pragma once

typedef struct {
    short id;
    char  wday, _wday;
    _Bool lear:1;
} dtm_year_t;

extern int dtm_year(dtm_year_t *year);
