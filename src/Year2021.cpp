#include "Year2021.hpp"

#include "Util.hpp"

int Year2021::Day1Part1(const std::string& input) {
    auto depths { inputToVector(input) };
    auto increases { 0 };
    for (auto i { 0 }; i < depths.size() - 1; i++) {
        auto from { depths[i] };
        auto to { depths[i + 1] };
        if (to > from) {
            increases++;
        }
    }
    return increases;
}

int Year2021::Day1Part2(const std::string& input) {
    auto depths { inputToVector(input) };
    auto increases { 0 };
    for (auto i { 0 }; i < depths.size() - 3; i++) {
        auto a1 { depths[i] };
        auto a2 { depths[i + 1] };
        auto a3 { depths[i + 2] };
        auto a4 { depths[i + 3] };
        auto first { a1 + a2 + a3 };
        auto second { a2 + a3 + a4 };
        if (second > first) {
            increases++;
        }
    }
    return increases;
}
