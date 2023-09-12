#include "catch_amalgamated.hpp"
#include "Year2017.hpp"

TEST_CASE("Year 2017 Day 1 Part 1") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("1122") == 3);
    CHECK(test("1111") == 4);
    CHECK(test("1234") == 0);
    CHECK(test("91212129") == 9);
}

TEST_CASE("Year 2017 Day 1 Part 2") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("1212") == 6);
    CHECK(test("1221") == 0);
    CHECK(test("123425") == 4);
    CHECK(test("123123") == 12);
    CHECK(test("12131415") == 4);
}

TEST_CASE("Year 2017 Day 2 Part 1") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day2Part1, &y, std::placeholders::_1) };
    CHECK(test("5\t1\t9\t5\n7\t5\t3\n2\t4\t6\t8") == 18);
}

TEST_CASE("Year 2017 Day 2 Part 2") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day2Part2, &y, std::placeholders::_1) };
    CHECK(test("5\t9\t2\t8\n9\t4\t7\t3\n3\t8\t6\t5") == 9);
}
