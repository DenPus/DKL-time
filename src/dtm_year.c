/*
 * dtm_year.c
 *
 * dtm_year()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Wed May 20 13:49:58 2020
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#include "dtm_year.h"

int dtm_year_wday(int year) {
    int wday, d1, d2, d3;

    d1 = (int) ((year - 1.)/ 4.0);
    d2 = (int) ((year - 1.)/ 100.);
    d3 = (int) ((year - 1.)/ 400.);

    wday = (year + d1 - d2 + d3) % 7;
    wday--;

    return wday;
}

_Bool dtm_year_leap(int year) {
    _Bool is;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        is = 1;
    } else {
        is = 0;
    }

    return is;
}

int dtm_year(dtm_year_t *year) {
    int err;

    year->wday = (char) dtm_year_wday(year->id);
    year->lear = dtm_year_leap(year->id);

    err = 0;

    return err;
}
