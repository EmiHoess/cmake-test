#include <catch2/catch_test_macros.hpp>

int add(int,int);

TEST_CASE("Basic addition") {
    REQUIRE(add(2, 3) == 5);
}
