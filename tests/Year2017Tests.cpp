#include "catch_amalgamated.hpp"
#include "Year2017.hpp"

TEST_CASE("Year 2017") {
    SECTION("Day 1") {
        SECTION("Part 1") {
            Year2017 y;
            auto test = std::bind(&Year2017::Day1Part1, &y, std::placeholders::_1);
            CHECK(test("1122") == 3);
            CHECK(test("1111") == 4);
            CHECK(test("1234") == 0);
            CHECK(test("91212129") == 9);
        }

        SECTION("Part 2") {
            Year2017 y;
            auto test = std::bind(&Year2017::Day1Part2, &y, std::placeholders::_1);
            CHECK(test("1212") == 6);
            CHECK(test("1221") == 0);
            CHECK(test("123425") == 4);
            CHECK(test("123123") == 12);
            CHECK(test("12131415") == 4);
        }
    }
}

/*
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
*/
