#include "catch_amalgamated.hpp"
#include "Year2016.hpp"

TEST_CASE("Year 2016") {
    SECTION("Day 1") {
        SECTION("Part 1") {
            Year2016 y;
            auto test = std::bind(&Year2016::Day1Part1, &y, std::placeholders::_1);
            CHECK(test("R2, L3") == 5);
            CHECK(test("R2, R2, R2") == 2);
            CHECK(test("R5, L5, R5, R3") == 12);
        }

        SECTION("Part 2") {
            Year2016 y;
            auto test = std::bind(&Year2016::Day1Part2, &y, std::placeholders::_1);
            CHECK(test("R8, R4, R4, R8") == 4);
        }
    }
}
