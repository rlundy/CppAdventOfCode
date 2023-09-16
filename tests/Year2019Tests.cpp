#include "catch_amalgamated.hpp"
#include "Year2019.hpp"
#include "IntCode.hpp"

TEST_CASE("Year 2019 Day 1 Part 1") {
    Year2019 y;
    auto test { std::bind(&Year2019::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("12") == 2);
    CHECK(test("14") == 2);
    CHECK(test("1969") == 654);
    CHECK(test("100756") == 33583);
}

TEST_CASE("Year 2019 Day 1 Part 2") {
    Year2019 y;
    auto test { std::bind(&Year2019::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("14") == 2);
    CHECK(test("1969") == 966);
    CHECK(test("100756") == 50346);
}
