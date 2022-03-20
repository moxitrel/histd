#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <gsl/span>
#include <gsl/util>
#include <iterator>
#include <limits>
#include <type_traits>

namespace hppx {
using span        = ::gsl::span;
using format_to_n = ::fmt::format_to_n;

char* AsciiOf(const void* data, std::size_t dataSize, void* buffer, std::size_t bufferSize) {
  static const auto& kFmtChar = fmt::runtime("{}");
  static const auto& kFmtHex  = fmt::runtime("\\x{:02x}");

  if (buffer == nullptr || bufferSize == 0) {
    return nullptr;
  }

  auto        bi = static_cast<char*>(buffer);
  const auto& be = bi + bufferSize;
  for (const auto& c : span{static_cast<const char*>(data), dataSize}) {
    const auto& fmt = std::isprint(c) ? kFmtChar : kFmtHex;
    bi              = format_to_n(bi, be - bi, fmt, c).out;
    if (bi >= be) {
      bi = be - 1;  // store '\0'
      SPDLOG_WARN("buffer isn't large enough");
      break;
    }
  }
  *bi = '\0';

  return static_cast<char*>(buffer);
}

}  // namespace hppx
