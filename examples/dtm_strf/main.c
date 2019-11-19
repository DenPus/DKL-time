/*
 * main.c
 *
 * Example dtm_strms()
 * ====================
 *
 * Author   :  
 * Created  :  Thu Oct 24 11:49:16 2019
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include <dkl-time.h>
#include <stdio.h>

int main(void) {
    int  err   = 0;
    int  ndst;
    char dst[30];
    char fmt[] = "%Y-%m-%d -- %I:%M %p";
    int  nfmt  = sizeof(fmt) - 1;

    ndst = dtm_strfsec(dst, 3600, nfmt, fmt);

    printf(
            "String from datetime by format: '%.*s'\n"
            "result '%.*s'\n",
            nfmt, fmt,
            ndst, dst
    );

    return err;
}

