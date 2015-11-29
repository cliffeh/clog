#ifndef CLOG_H
#define CLOG_H 1

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define CLOG_LEVEL_SILENT 0
#define CLOG_LEVEL_FATAL  (1<<1)
#define CLOG_LEVEL_ERROR  (1<<2)
#define CLOG_LEVEL_WARN   (1<<3)
#define CLOG_LEVEL_INFO   (1<<4)
#define CLOG_LEVEL_DEBUG  (1<<5)
#define CLOG_LEVEL_TRACE  (1<<6)

#define CLOG_NONE    CLOG_LEVEL_SILENT
#define CLOG_SILENT  CLOG_LEVEL_SILENT
#define CLOG_FATAL   CLOG_LEVEL_FATAL
#define CLOG_ERROR   (CLOG_LEVEL_ERROR|CLOG_FATAL)
#define CLOG_WARN    (CLOG_LEVEL_WARN|CLOG_ERROR)
#define CLOG_INFO    (CLOG_LEVEL_INFO|CLOG_WARN)
#define CLOG_DEFAULT CLOG_INFO
#define CLOG_DEBUG   (CLOG_LEVEL_DEBUG|CLOG_INFO)
#define CLOG_TRACE   (CLOG_LEVEL_TRACE|CLOG_DEBUG)
#define CLOG_ALL     CLOG_TRACE

#define CLOG_DEFAULT_TS_FMT "%FT%T%z"

int (*clog_fatal) (const char *fmt, ...);
int (*clog_error) (const char *fmt, ...);
int (*clog_warn)  (const char *fmt, ...);
int (*clog_info)  (const char *fmt, ...);
int (*clog_debug) (const char *fmt, ...);
int (*clog_trace) (const char *fmt, ...);

void clog_init(FILE *fp, int level, const char *ts_fmt);
int clog_get_level();
int clog_set_level(int level);

#endif
