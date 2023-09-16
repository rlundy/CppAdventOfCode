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

TEST_CASE("IntCode computer") {
    SECTION("Test 1") {
        IntCode ic { "1,9,10,3,2,3,11,0,99,30,40,50" };
        ic.process();
        CHECK(ic.getState() == "3500,9,10,70,2,3,11,0,99,30,40,50");
    }
    SECTION("Test 2") {
        IntCode ic { "1,0,0,0,99" };
        ic.process();
        CHECK(ic.getState() == "2,0,0,0,99");
    }
    SECTION("Test 2") {
        IntCode ic { "2,3,0,3,99" };
        ic.process();
        CHECK(ic.getState() == "2,3,0,6,99");
    }
    SECTION("Test 2") {
        IntCode ic { "2,4,4,5,99,0" };
        ic.process();
        CHECK(ic.getState() == "2,4,4,5,99,9801");
    }
    SECTION("Test 2") {
        IntCode ic { "1,1,1,4,99,5,6,0,99" };
        ic.process();
        CHECK(ic.getState() == "30,1,1,4,2,5,6,0,99");
    }
}
