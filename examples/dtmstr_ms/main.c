/*
 * main.c
 *
 * Example dtmstr_ms()
 * ===============
 *
 * Author   :  
 * Created  :  Thu Oct 24 11:49:16 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include <dkl-time.h>
#include <stdio.h>

int main(void) {
    int err = 0;
    int len;
    char dst[30];

    len = dtmstr_ms(dst, 3600000);

    printf("%.*s", len, dst);

    return err;
}

