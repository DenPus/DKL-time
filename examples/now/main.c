/*
 * 
 * Author:   denkar
 * Created:  28.08.19 16:03
 */

#include <dkl-time.h>
#include <stdio.h>

int main(void) {
    time_t time;

    time = timenow(TIME_REALTIME);
    printf("TIME_REALTIME %lu\n", time);

    time = timenow(TIME_MONOTONIC);
    printf("TIME_MONOTONIC %lu\n", time);

    time = timenow(TIME_BOOTTIME);
    printf("TIME_BOOTTIME %lu\n", time);

    time = timenow(TIME_REALTIME_COARSE);
    printf("TIME_REALTIME_COARSE %lu\n", time);

    time = timenow(TIME_MONOTONIC_COARSE);
    printf("TIME_MONOTONIC_COARSE %lu\n", time);

    time = timenow(TIME_PROCESS_CPUTIME_ID);
    printf("TIME_PROCESS_CPUTIME_ID %lu\n", time);

    time = timenow(TIME_THREAD_CPUTIME_ID);
    printf("TIME_THREAD_CPUTIME_ID %lu\n", time);

    return 0;
}
