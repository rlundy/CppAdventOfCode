#pragma once

#include <string>

#include "RPS.hpp"
#include "RpsResult.hpp"

class Year2022 {
    private:
        RpsResult getScore(RPS hisPlay, RPS myPlay);
        RPS getPlay(RPS hisPlay, RpsResult expectedResult);
        RPS asPlay(char letter);
        RpsResult asExpectedResult(char letter);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int Day2Part1(const std::string &input);
        int Day2Part2(const std::string& input);
};
