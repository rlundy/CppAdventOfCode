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

TEST_CASE("Year 2021 Day 2 Part 1") {
    Year2021 y;
    auto test { std::bind(&Year2021::Day2Part1, &y, std::placeholders::_1) };
    CHECK(test("forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2") == 150);
}

TEST_CASE("Year 2021 Day 2 Part 2") {
    Year2021 y;
    auto test { std::bind(&Year2021::Day2Part2, &y, std::placeholders::_1) };
    CHECK(test("forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2") == 900);
}

TEST_CASE("Year 2021 Day 3 Part 1") {
    Year2021 y;
    auto test { std::bind(&Year2021::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test("00100\n11110\n10110\n10111\n10101\n01111\n00111\n11100\n10000\n11001\n00010\n01010") == 198);
}

TEST_CASE("Year 2021 Day 3 Part 2") {
    Year2021 y;
    auto test { std::bind(&Year2021::Day3Part2, &y, std::placeholders::_1) };
    CHECK(test("00100\n11110\n10110\n10111\n10101\n01111\n00111\n11100\n10000\n11001\n00010\n01010") == 230);
}
