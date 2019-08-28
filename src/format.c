/*
 *
 * Author:   denkar
 * Created:  28.08.19 14:30
 *
 * Get current time from devices
 */

#include <main.h>

void timestrf(char *dest, time_t src, char *fmt) {
/*    if (fmt) {
        char      strTime[200];
        struct tm *u;

        u = localtime(&timer);
        
        strftime(strTime, 200, fmt->val, u);

        fmtStr = strTime;
    } else {*/

    if (fmt) {
        strftime(dest, 100, fmt, gmtime(&src));
    } else {
        dest = ctime_r(&src, dest);

        size_t len = strlen(dest);

        if (len) {
            dest[len - 1] = '\0';
        }
    }
}
