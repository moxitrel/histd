#ifndef HPPX_LOG_LOG_PRINTF_H_
#define HPPX_LOG_LOG_PRINTF_H_

#include <stdint.h>
#include "source_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t log_level_t;
#define LOG_LEVEL_NONE  ((log_level_t)0x00)
// * fatal
// - crash process
#define LOG_LEVEL_FATAL ((log_level_t)0x10)
#define LOG_LEVEL_ERROR ((log_level_t)0x20)
#define LOG_LEVEL_WARN  ((log_level_t)0x30)
#define LOG_LEVEL_INFO  ((log_level_t)0x40)
#define LOG_LEVEL_DEBUG ((log_level_t)0x50)
// * trace
// - function call chain
// - algorithm steps
#define LOG_LEVEL_TRACE ((log_level_t)0x60)
#define LOG_LEVEL_ALL   ((log_level_t)UINT8_MAX)

typedef struct logger {
  log_level_t level;  // current log level
} logger_t;

// * Example
// [E 2021-9-9 8:12:56.127321908 file_name.c 31 function_name] ...
void logger_printf(logger_t* logger, log_level_t level, source_location_t source_location, const char* format, ...);

void logger_level_set(logger_t* logger, log_level_t level);

extern logger_t g_logger;
#define LOG_FATAL(FMT, ...) logger_printf(&g_logger, LOG_LEVEL_FATAL, SOURCE_LOCATION_CURRENT(), FMT, __VA_ARGS__)
#define LOG_ERROR(FMT, ...) logger_printf(&g_logger, LOG_LEVEL_ERROR, SOURCE_LOCATION_CURRENT(), FMT, __VA_ARGS__)
#define LOG_WARN(FMT, ...)  logger_printf(&g_logger, LOG_LEVEL_WARN, SOURCE_LOCATION_CURRENT(), FMT, __VA_ARGS__)
#define LOG_INFO(FMT, ...)  logger_printf(&g_logger, LOG_LEVEL_INFO, SOURCE_LOCATION_CURRENT(), FMT, __VA_ARGS__)
#define LOG_DEBUG(FMT, ...) logger_printf(&g_logger, LOG_LEVEL_DEBUG, SOURCE_LOCATION_CURRENT(), FMT, __VA_ARGS__)
#define LOG_TRACE(FMT, ...) logger_printf(&g_logger, LOG_LEVEL_TRACE, SOURCE_LOCATION_CURRENT(), FMT, __VA_ARGS__)

#ifdef __cplusplus
}
#endif
#endif  // HPPX_LOG_LOG_PRINTF_H_
