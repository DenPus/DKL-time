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

    time = timenow(TM_REALTIME);
    timestrf(time_str, time, NULL);
    printf("TM_REALTIME %lu - %s\n", time, time_str);

    time = timenow(TM_MONOTONIC);
    timestrf(time_str, time, NULL);
    printf("TM_MONOTONIC %lu - %s\n", time, time_str);

    time = timenow(TM_BOOTTIME);
    timestrf(time_str, time, NULL);
    printf("TM_BOOTTIME %lu - %s\n", time, time_str);

    time = timenow(TM_REALTIME_COARSE);
    timestrf(time_str, time, NULL);
    printf("TM_REALTIME_COARSE %lu - %s\n", time, time_str);

    time = timenow(TM_MONOTONIC_COARSE);
    timestrf(time_str, time, NULL);
    printf("TM_MONOTONIC_COARSE %lu - %s\n", time, time_str);

    time = timenow(TM_PROCESS_CPUTIME_ID);
    timestrf(time_str, time, NULL);
    printf("TM_PROCESS_CPUTIME_ID %lu - %s\n", time, time_str);

    time = timenow(TM_THREAD_CPUTIME_ID);
    timestrf(time_str, time, NULL);
    printf("TM_THREAD_CPUTIME_ID %lu - %s\n", time, time_str);

    return 0;
}
