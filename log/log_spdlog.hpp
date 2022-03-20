#ifndef HPPX_LOG_LOG_SPDLOG_HPP_
#define HPPX_LOG_LOG_SPDLOG_HPP_
#include <spdlog/spdlog.h>

#define LOG_FATAL(...) SPDLOG_CRITICAL(__VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define LOG_WARN(...)  SPDLOG_WARN(__VA_ARGS__)
#define LOG_INFO(...)  SPDLOG_INFO(__VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define LOG_TRACE(...) SPDLOG_TRACE(__VA_ARGS__)

#endif
