#include "catch_amalgamated.hpp"
#include "calculator.hpp"

TEST_CASE("Calculator operations") {
    Calculator calc;

    SECTION("Addition") {
        REQUIRE(calc.add(3, 4) == 7);
    }

    SECTION("Subtraction") {
        REQUIRE(calc.subtract(5, 2) == 3);
    }
}
