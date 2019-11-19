/*
 * dtm_strsec.h
 *
 * dtm_strsec
 * ==========
 * Get string default format from seconds
 *
 * Author   :  
 * Created  :  Thu Oct 24 11:27:53 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#pragma once

#include "dtmms_t.h"
#include <time.h>

extern int dtm_strsec(char *dst, time_t src);

#define dtm_strms(dst, src) dtm_strsec(dst, src / 1000)
