#ifndef LOG_SOURCE_LOCATION_H_
#define LOG_SOURCE_LOCATION_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct source_location {
  uint_least32_t line;

  // -fmacro-prefix-map=<old>=<new> : modify __FILE__
  //  /path/to/src=prefix : /path/to/src/log/source_location.h -> prefix/log/source_location.h
  const char* file_name;

  const char* function_name;
} source_location_t;

#define SOURCE_LOCATION_CURRENT() \
  ((source_location_t){           \
      .line          = __LINE__,  \
      .file_name     = __FILE__,  \
      .function_name = __func__,  \
  })

#ifdef __cplusplus
}
#endif
#endif  // LOG_SOURCE_LOCATION_H_
