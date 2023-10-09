#pragma once

#include <string>
#include <vector>
#include <iostream>

std::string getPuzzleInput(const int year, const int day);

std::string readFileContents(const std::string &filePath);

std::vector<std::string> split(const std::string& original, const std::string& delimiter, const bool keepEmptyParts = false);

std::string join(std::vector<std::string> strings, std::string joinText);

std::vector<int> readInts(const std::string& original);

bool contains(const std::string& text, const std::string& textToFind);

std::vector<int> inputToVector(const std::string& input);

std::vector<int> textToInt(const std::vector<std::string> input);

int sum(const std::vector<int> numbers);

int maxInt(const std::vector<int> numbers);

std::string trim(const std::string& text);

std::string toKey(int x, int y);

int toInt(std::string binaryRepresentation);

template<typename T>
void showResult(int year, int day, int part, T result) {
    auto puzzleInput { getPuzzleInput(year, day) };
    std::cout
        << "Year " << year
        << " day " << day
        << " part " << part << ": "
        << result << std::endl;
}
