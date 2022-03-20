// Remove SPDLOG_* at compile time.
// Use spdlog::set_level(spdlog::level::trace) to change log level
// SPDLOG_LEVEL_TRACE,
// SPDLOG_LEVEL_DEBUG,
// SPDLOG_LEVEL_INFO,
// SPDLOG_LEVEL_WARN,
// SPDLOG_LEVEL_ERROR,
// SPDLOG_LEVEL_CRITICAL,
// SPDLOG_LEVEL_OFF
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

static void spdlog_example()
{
  // change log level to TRACE
  spdlog::set_level(spdlog::level::trace);

  SPDLOG_TRACE();
  SPDLOG_DEBUG();
  SPDLOG_INFO();
  SPDLOG_WARN();
  SPDLOG_ERROR();
  SPDLOG_CRITICAL();

  SPDLOG_LOGGER_TRACE(spdlog::default_logger_raw());
  SPDLOG_LOGGER_DEBUG(spdlog::default_logger_raw());
  SPDLOG_LOGGER_INFO(spdlog::default_logger_raw());
  SPDLOG_LOGGER_WARN(spdlog::default_logger_raw());
  SPDLOG_LOGGER_ERROR(spdlog::default_logger_raw());
  SPDLOG_LOGGER_CRITICAL(spdlog::default_logger_raw());

  // pointer
  //  fmt::ptr() -> const void*
  int x;
  SPDLOG_ERROR("{}", fmt::ptr(&x));
}
