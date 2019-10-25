dkl-time v0.1.5.4
============================
DKL time - library for working with time

# Features

* Get time (milliseconds) now with multi devices
* Convert time to string by format (strftime)
* Convert time with format passed time

# Api

## Functions

### dtmdev_ms
```C
dtmms_t dtmdev_ms(dtmdev_t dev)
```
### dtmconv
```C
dtmfmt_item_t *dtmconv(char *dest, dtmms_t *src_ms, dtmfmt_t fmt)
```
### dtmfmt_item
```C
dtmfmt_item_t *dtmfmt_item(dtmms_t time, dtmfmt_t fmt)
```
### dtmconv_group
```C
char *dtmconv_group(char *dest, dtmms_t src_ms, dtmfmt_t fmt, uint8_t groups, _Bool is_empty)
```
### dtmstrf
```C
void dtmstrf(char *dest, dtmms_t src, char *fmt)
```
### dtmstr
```C
dtmstr(char *dest, time_t sec)
```
### dtmstr_ms
```C
int dtmstr_ms(char *dest, dtmms_t ms)
```

# Info

* Language code: C
* Author: DenKar
* License: GPL-2.0

# Examples results

![Result](/screenshots/now.png)

time passed
```
# 1567074891137 ms
# 49 year 8 month 1 week 5 day 10 hour 34 min 51 sec 137 ms
# 3 day
# 34 min 51 sec 137 ms
```
