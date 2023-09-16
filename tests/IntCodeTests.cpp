#include "catch_amalgamated.hpp"
#include "IntCode.hpp"

TEST_CASE("IntCode computer") {
    SECTION("Basic tests") {
        IntCode ic { "" };
        ic.process();
        CHECK(ic.getState() == "");
    }
    SECTION("Advent of code tests") {
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
        SECTION("Test 3") {
            IntCode ic { "2,3,0,3,99" };
            ic.process();
            CHECK(ic.getState() == "2,3,0,6,99");
        }
        SECTION("Test 4") {
            IntCode ic { "2,4,4,5,99,0" };
            ic.process();
            CHECK(ic.getState() == "2,4,4,5,99,9801");
        }
        SECTION("Test 5") {
            IntCode ic { "1,1,1,4,99,5,6,0,99" };
            ic.process();
            CHECK(ic.getState() == "30,1,1,4,2,5,6,0,99");
        }
    }
}
