#include "clog.h"

#define __CLOG_LOG(FN_NAME, LEVEL) static int FN_NAME(const char *fmt, ...)\
  {\
  va_list args;\
  time_t t = time(0);\
  char buf[64];\
  strftime(buf, 64, __clog_ts_fmt, localtime(&t));\
  int r = fprintf(__clog_fp, "%s", buf);\
  r += fprintf(__clog_fp, " " LEVEL  " ");\
  va_start(args, fmt);\
  r += vfprintf(__clog_fp, fmt, args) + fprintf(__clog_fp, "\n");\
  va_end(args);\
  return r;\
  }

static FILE *__clog_fp;
static int __clog_level;
static const char *__clog_ts_fmt;

__CLOG_LOG(__clog_fatal, "FATAL")
__CLOG_LOG(__clog_error, "ERROR")
__CLOG_LOG(__clog_warn, "WARN")
__CLOG_LOG(__clog_info, "INFO")
__CLOG_LOG(__clog_debug, "DEBUG")
__CLOG_LOG(__clog_trace, "TRACE")
static int __clog_noop(const char *fmt, ...) { return 0; }

void clog_init(FILE *logger, int level, const char *ts_fmt)
{
  __clog_fp = logger ? logger : stdout;
  __clog_ts_fmt = ts_fmt ? ts_fmt : CLOG_DEFAULT_TS_FMT;
  clog_set_level(level);
}

int clog_get_level()
{
  return __clog_level;
}

int clog_set_level(int level)
{
  __clog_level = level;
  clog_fatal = (level & CLOG_LEVEL_FATAL) ? __clog_fatal : __clog_noop;
  clog_error = (level & CLOG_LEVEL_ERROR) ? __clog_error : __clog_noop;
  clog_warn =  (level & CLOG_LEVEL_WARN)  ? __clog_warn  : __clog_noop;
  clog_info =  (level & CLOG_LEVEL_INFO)  ? __clog_info  : __clog_noop;
  clog_debug = (level & CLOG_LEVEL_DEBUG) ? __clog_debug : __clog_noop;
  clog_trace = (level & CLOG_LEVEL_TRACE) ? __clog_trace : __clog_noop;
  return __clog_level;
}
