#include <map>
#include "catch_amalgamated.hpp"
#include "Year2015.hpp"

TEST_CASE("Year 2015 Day 1 Part 1") {
    Year2015 y;
    auto test { std::bind(&Year2015::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("(())") == 0);
    CHECK(test("()()") == 0);
    CHECK(test("(((") == 3);
    CHECK(test("(()(()(") == 3);
    CHECK(test("))(((((") == 3);
    CHECK(test("())") == -1);
    CHECK(test("))(") == -1);
    CHECK(test(")))") == -3);
    CHECK(test(")())())") == -3);
}

TEST_CASE("Year 2015 Day 1 Part 2") {
    Year2015 y;
    auto test { std::bind(&Year2015::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test(")") == 1);
    CHECK(test("()())") == 5);
}
