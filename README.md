# clog
a super-simple c logging library

I got tired of littering my C code with printf statements, so I wrote a little library for logging. 

## Compiling

`cc -c -o clog.o clog.c` (or simply use `make`)

## Using

```
/* initialize clog to log to stdout using the default timestamp format */
clog_init(0, CLOG_DEFAULT, 0);

clog_warn("this is a %s message", "warning");
clog_debug("this message won't show if I don't have log level set to at least CLOG_DEBUG");
```

Supports 7 log levels, in order from least to most verbose:

- CLOG_NONE   
- CLOG_FATAL  
- CLOG_ERROR  
- CLOG_WARN   
- CLOG_INFO   
- CLOG_DEBUG  
- CLOG_TRACE  

The default is CLOG_WARN.
