/*
 * 
 * Author:   denkar
 * Created:  28.08.19 16:03
 */

#include <dkl-time.h>
#include <stdio.h>

int main(void) {
    tm_t time;
    char time_str[40];
    char conv_str[50];

    time = dtmdev_ms(DTMDEV_PROCESS_CPUTIME_ID);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 0, 0);
    printf("-- DTMDEV__PROCESS_CPUTIME_ID -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    time = dtmdev_ms(DTMDEV_REALTIME);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 8, 0);
    printf("-- DTMDEV__REALTIME -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    time = dtmdev_ms(DTMDEV_MONOTONIC);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 0, 1);
    printf("-- DTMDEV__MONOTONIC -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    time = dtmdev_ms(DTMDEV_BOOTTIME);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 0, 0);
    printf("-- DTMDEV__BOOTTIME -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    time = dtmdev_ms(DTMDEV_REALTIME_COARSE);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 0, 0);
    printf("-- DTMDEV__REALTIME_COARSE -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    time = dtmdev_ms(DTMDEV_MONOTONIC_COARSE);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 0, 0);
    printf("-- DTMDEV__MONOTONIC_COARSE -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    time = dtmdev_ms(DTMDEV_THREAD_CPUTIME_ID);
    timestrf(time_str, time, NULL);
    dtmconv_group(conv_str, time, 0, 0, 0);
    printf("-- DTMDEV__THREAD_CPUTIME_ID -> %lu\n   %s -> %s\n", time, time_str, conv_str);

    return 0;
}
