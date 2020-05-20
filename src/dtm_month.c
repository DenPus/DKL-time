/*
 * dtm_month.c
 *
 * dtm_month()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 13:18:48 2020
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#include "dtm_month.h"
#include "dtm_year.h"

char dtm_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dtm_month(dtm_year_t *year, dtm_moth_t *month) {
    int err;

    err = dtm_year(year);

    if (!month->id) {
        month->wday = year->wday;
    } else {
        month->wday = year->_wday;
    }

    month->len = dtm_days_in_month[month->id];

    if (month->id == 1 && year->lear) {
        month->len++;
    }

    year->_wday = month->wday + month->len;
    year->_wday %= 7;

    err = 0;

    return err;
}
