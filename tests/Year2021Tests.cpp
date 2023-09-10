#include "catch_amalgamated.hpp"
#include "Year2021.hpp"

TEST_CASE("Year 2021 Day 1 Part 1") {
    Year2021 y;
    auto test { std::bind(&Year2021::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("199\n200\n208\n210\n200\n207\n240\n269\n260\n263") == 7);
}

TEST_CASE("Year 2021 Day 1 Part 2") {
    Year2021 y;
    auto test { std::bind(&Year2021::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("199\n200\n208\n210\n200\n207\n240\n269\n260\n263") == 5);
}
