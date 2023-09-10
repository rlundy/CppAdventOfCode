#include "catch_amalgamated.hpp"
#include "Year2020.hpp"

TEST_CASE("Year 2020 Day 1 Part 1") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("1721\n979\n366\n299\n675\n1456") == 514579);
}

TEST_CASE("Year 2020 Day 1 Part 2") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("1721\n979\n366\n299\n675\n1456") == 241861950);
}
