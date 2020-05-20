/*
 * dtm_month.h
 *
 * dtm_month()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 13:18:48 2020)
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#pragma once

#include "dtm_year.h"

typedef struct {
    char id, len, wday;
} dtm_moth_t;

extern int dtm_month(dtm_year_t *year, dtm_moth_t *month);
