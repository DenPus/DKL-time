/*
 * tmstrf.h
 *
 * tmstrf()
 * ========
 * Time to string by format
 *
 * Author   :  
 * Created  :  Thu Oct 24 08:56:34 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#pragma once

#include "dtmms_t.h"
#include <time.h>

extern int dtm_strfsec(char *dst, time_t src, int nfmt, char *fmt);

#define dtm_strfms(dst, src, nfmt, fmt) dtm_strfsec(dst, src / 1000, nfmt, fmt)
