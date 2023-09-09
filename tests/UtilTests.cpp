#include <string>

#include "catch_amalgamated.hpp"
#include "Util.hpp"

TEST_CASE("Split") {
    std::string original = "abcxdefxghi";
    auto parts = split(original, "x");
    CHECK(parts.at(0) == "abc");
    CHECK(parts.at(1) == "def");
    CHECK(parts.at(2) == "ghi");
}

TEST_CASE("Contains") {
    CHECK(contains("ABCdefGHI", "def"));
    CHECK_FALSE(contains("ABCdefGHI", "DEF"));
}
