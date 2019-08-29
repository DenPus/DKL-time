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
    char conv_str[40];

    time = timenow(TM_DEV_REALTIME);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 8, 0);
    printf("TM_DEV_REALTIME %lu - %s - %s\n", time, conv_str, time_str);

    time = timenow(TM_DEV_MONOTONIC);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 0, 1);
    printf("TM_DEV_MONOTONIC %lu - %s - %s\n", time, conv_str, time_str);

    time = timenow(TM_DEV_BOOTTIME);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 0, 0);
    printf("TM_DEV_BOOTTIME %lu - %s - %s\n", time, conv_str, time_str);

    time = timenow(TM_DEV_REALTIME_COARSE);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 0, 0);
    printf("TM_DEV_REALTIME_COARSE %lu - %s - %s\n", time, conv_str, time_str);

    time = timenow(TM_DEV_MONOTONIC_COARSE);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 0, 0);
    printf("TM_DEV_MONOTONIC_COARSE %lu - %s - %s\n", time, conv_str, time_str);

    time = timenow(TM_DEV_PROCESS_CPUTIME_ID);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 0, 0);
    printf("TM_DEV_PROCESS_CPUTIME_ID %lu - %s - %s\n", time, conv_str, time_str);

    time = timenow(TM_DEV_THREAD_CPUTIME_ID);
    timestrf(time_str, time, NULL);
    tm_convert_group(conv_str, time, 0, 0, 0);
    printf("TM_DEV_THREAD_CPUTIME_ID %lu - %s - %s\n", time, conv_str, time_str);

    return 0;
}
