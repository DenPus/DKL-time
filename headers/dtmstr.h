/*
 * dtmstr.h
 *
 * dtmstr
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

extern int dtmstr(char *dest, time_t sec);
