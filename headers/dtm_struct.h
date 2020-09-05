/*
 * dtm_struct.h
 *
 * dtm_struct()
 * ==========
 *
 * Author   :  denkar
 * Created  :  05.09.20 10:22
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#pragma once

#include "dtmdev_ms.h"
#include <time.h>

extern time_t dtm_struct(struct tm* src);
