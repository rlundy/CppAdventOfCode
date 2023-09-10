#include "catch_amalgamated.hpp"
#include "Year2018.hpp"

TEST_CASE("Year 2018 Day 1 Part 1") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("+1\n-2\n+3\n+1") == 3);
    CHECK(test("+1\n+1\n+1") == 3);
    CHECK(test("+1\n+1\n-2") == 0);
    CHECK(test("-1\n-2\n-3") == -6);
}

TEST_CASE("Year 2018 Day 1 Part 2") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("+1\n-2\n+3\n+1") == 2);
    CHECK(test("+1\n-1") == 0);
    CHECK(test("+3\n+3\n+4\n-2\n-4") == 10);
    CHECK(test("-6\n+3\n+8\n+5\n-6") == 5);
    CHECK(test("+7\n+7\n-2\n-7\n-4") == 14);
}
