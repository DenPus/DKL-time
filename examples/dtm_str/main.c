/*
 * main.c
 *
 * Example dtm_strsec()
 * =================
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
    int ndst;
    char dst[30];

    ndst = dtm_strsec(dst, 3600);

    printf("%.*s\n", ndst, dst);

    return err;
}
