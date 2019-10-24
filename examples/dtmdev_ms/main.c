/*
 * 
 * Author:   denkar
 * Created:  28.08.19 16:03
 */

#include <dkl-time.h>
#include <stdio.h>

int main(void) {
    dtmms_t dtmms;
    char time_str[40];
    char conv_str[50];

    dtmms = dtmdev_ms(DTMDEV_PROCESS_CPUTIME_ID);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__PROCESS_CPUTIME_ID -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtmdev_ms(DTMDEV_REALTIME);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 8, 0);
    printf("-- DTMDEV__REALTIME -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtmdev_ms(DTMDEV_MONOTONIC);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 0, 1);
    printf("-- DTMDEV__MONOTONIC -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtmdev_ms(DTMDEV_BOOTTIME);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__BOOTTIME -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtmdev_ms(DTMDEV_REALTIME_COARSE);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__REALTIME_COARSE -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtmdev_ms(DTMDEV_MONOTONIC_COARSE);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__MONOTONIC_COARSE -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtmdev_ms(DTMDEV_THREAD_CPUTIME_ID);
    dtmstrf(time_str, dtmms, NULL);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__THREAD_CPUTIME_ID -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    return 0;
}
