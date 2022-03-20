#include "log_printf.h"
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

logger_t g_logger = {
    .level = LOG_LEVEL_DEBUG,
};

void logger_level_set(logger_t* logger, log_level_t level) {
  assert(logger != NULL);
  logger->level = level;
  logger_printf(logger, LOG_LEVEL_DEBUG, SOURCE_LOCATION_CURRENT(), "(logger_t %p).level = %#x", logger, (unsigned)level);
}

void logger_printf(logger_t* logger, log_level_t level, source_location_t location, const char* format, ...) {
  if (logger == NULL) {
    return;
  }
  if (format == NULL) {
    return;
  }
  if (level <= LOG_LEVEL_NONE || logger->level < level) {
    return;
  }

  const char* level_name;
  switch (level) {
  case LOG_LEVEL_FATAL:
    level_name = "F";
    break;
  case LOG_LEVEL_ERROR:
    level_name = "E";
    break;
  case LOG_LEVEL_WARN:
    level_name = "W";
    break;
  case LOG_LEVEL_INFO:
    level_name = "I";
    break;
  case LOG_LEVEL_DEBUG:
    level_name = "D";
    break;
  case LOG_LEVEL_TRACE:
    level_name = "T";
    break;
  default:
    level_name = "?";  // unknown level
    break;
  }

  struct timespec now;
  (void)timespec_get(&now, TIME_UTC);
  struct tm now_datetime;
  (void)gmtime_r(&now.tv_sec, &now_datetime);

  FILE* out = (level <= LOG_LEVEL_WARN)
                  ? stderr
                  : stdout;
  fprintf(out,
          "[%s %d-%d-%d %d:%d:%d.%ld %s %lu %s] ",
          level_name,
          1900 + now_datetime.tm_year,
          1 + now_datetime.tm_mon,
          now_datetime.tm_mday,
          now_datetime.tm_hour,
          now_datetime.tm_min,
          now_datetime.tm_sec,
          now.tv_nsec,
          location.file_name,
          (unsigned long)location.line,
          location.function_name);

  va_list format_args;
  va_start(format_args, format);
  vfprintf(out, format, format_args);
  va_end(format_args);

  fputc('\n', out);
}
