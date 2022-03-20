#include <cstddef>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <histd/histd.hpp>
#include <limits>

TEST_CASE("std20", "<utility>") {
  SECTION("cmp") {
    unsigned maxU = -1u;

    // -1 != max
    REQUIRE((-1 == maxU && std::cmp_not_equal(-1, maxU)));
    // -1 < 1
    REQUIRE((-1 > 1u && std::cmp_less(-1, 1u)));
    // 1 == 1
    REQUIRE((1 == 1u && std::cmp_equal(1, 1u)));

    REQUIRE(std::in_range<std::ptrdiff_t>(std::numeric_limits<std::uint16_t>::max()));
  }
}
