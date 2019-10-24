/*
 * main.c
 *
 * Example dtmstr()
 * ===============
 *
 * Author   :  
 * Created  :  Thu Oct 24 11:27:53 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include <dkl-time.h>
#include <stdio.h>

int main(void) {
    int err = 0;
    int len;
    char dst[30];

    len = dtmstr(dst, 3600);

    printf("%.*s", len, dst);

    return err;
}
