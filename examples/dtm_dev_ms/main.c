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
    int nstr;

    dtmms = dtm_msdev(DTMDEV_PROCESS_CPUTIME_ID);
    nstr = dtm_strsec(time_str, dtmms);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__PROCESS_CPUTIME_ID -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtm_msdev(DTMDEV_REALTIME);
    dtm_strms(time_str, dtmms);
    dtmconv_group(conv_str, dtmms, 0, 8, 0);
    printf("-- DTMDEV__REALTIME -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtm_msdev(DTMDEV_MONOTONIC);
    dtm_strms(time_str, dtmms);
    dtmconv_group(conv_str, dtmms, 0, 0, 1);
    printf("-- DTMDEV__MONOTONIC -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtm_msdev(DTMDEV_BOOTTIME);
    dtm_strms(time_str, dtmms);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__BOOTTIME -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtm_msdev(DTMDEV_REALTIME_COARSE);
    nstr = dtm_strfms(time_str, dtmms, 24, "Format: %Y-%m-%d %I:%M%p");
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__REALTIME_COARSE -> %lu\n   %.*s -> %s\n", dtmms, nstr, time_str, conv_str);

    dtmms = dtm_msdev(DTMDEV_MONOTONIC_COARSE);
    nstr = dtm_strms(time_str, dtmms);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__MONOTONIC_COARSE -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    dtmms = dtm_msdev(DTMDEV_THREAD_CPUTIME_ID);
    dtm_strms(time_str, dtmms);
    dtmconv_group(conv_str, dtmms, 0, 0, 0);
    printf("-- DTMDEV__THREAD_CPUTIME_ID -> %lu\n   %s -> %s\n", dtmms, time_str, conv_str);

    return 0;
}
