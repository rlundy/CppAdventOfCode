#include <string>
#include <vector>
#include <iostream>

#pragma once

std::string getPuzzleInput(const int year, const int day);

std::string readFileContents(const std::string &filePath);

std::vector<std::string> split(const std::string& original, const std::string& delimiter);

bool contains(const std::string& text, const std::string& textToFind);

std::vector<int> inputToVector(const std::string& input);

std::vector<int> textToInt(const std::vector<std::string> input);

int sum(const std::vector<int> numbers);

int maxInt(const std::vector<int> numbers);

template<typename T>
void showResult(int year, int day, int part, T result) {
    auto puzzleInput { getPuzzleInput(year, day) };
    std::cout
        << "Year " << year
        << " day " << day
        << " part " << part << ": "
        << result << std::endl;
}
