#include <map>
#include "catch_amalgamated.hpp"
#include "Year2015.hpp"

TEST_CASE("Year 2015") {
    SECTION("Day 1") {
        SECTION("Part 1") {
            std::map<std::string, int> inputsResults;
            inputsResults["(())"] = 0;
            inputsResults["()()"] = 0;
            inputsResults["((("] = 3;
            inputsResults["(()(()("] = 3;
            inputsResults["))((((("] = 3;
            inputsResults["())"] = -1;
            inputsResults["))("] = -1;
            inputsResults[")))"] = -3;
            inputsResults[")())())"] = -3;

            std::for_each(inputsResults.begin(), inputsResults.end(), [](const auto& pair) {
                Year2015 y;
                CAPTURE("Steps: " + pair.first);
                CHECK(y.Day1Part1(pair.first) == pair.second);
            });
        }

        SECTION("Part 2") {
            std::map<std::string, int> inputsResults;
            inputsResults[")"] = 1;
            inputsResults["()())"] = 5;

            std::for_each(inputsResults.begin(), inputsResults.end(), [](const auto& pair) {
                Year2015 y;
                CAPTURE("Steps: " + pair.first);
                CHECK(y.Day1Part1(pair.first) == pair.second);
            });
        }
    }
}
