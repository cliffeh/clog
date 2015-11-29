#include "clog.h"

int main(int argc, char *argv[])
{
  int level = CLOG_DEFAULT;
  const char *lname = "DEFAULT";

  clog_init(stdout, level, CLOG_DEFAULT_TS_FMT);

  if(argc == 2) {
    if(!strcmp("FATAL", argv[1])) { clog_set_level(level = CLOG_FATAL); lname = "FATAL"; }
    if(!strcmp("ERROR", argv[1])) { clog_set_level(level = CLOG_ERROR); lname = "ERROR"; }
    if(!strcmp("WARN", argv[1]))  { clog_set_level(level = CLOG_WARN);  lname = "WARN";  }
    if(!strcmp("INFO", argv[1]))  { clog_set_level(level = CLOG_INFO);  lname = "INFO";  }
    if(!strcmp("DEBUG", argv[1])) { clog_set_level(level = CLOG_DEBUG); lname = "DEBUG"; }
    if(!strcmp("TRACE", argv[1])) { clog_set_level(level = CLOG_TRACE); lname = "TRACE"; }
  }

  fprintf(stdout, "--- %s ---\n", lname);
  clog_fatal("this is %s log",  "fatal");
  clog_error("this is %s log",  "error");
  clog_warn("this is %s log",    "warn");
  clog_info("this is %s log",    "info");
  clog_debug("this is %s log",  "debug");
  clog_trace("this is %s log",  "trace");

  return 0;
}
