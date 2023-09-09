#include <string>
#include <vector>

#pragma once

std::string getPuzzleInput(const int year, const int day);

std::string readFileContents(const std::string &filePath);

std::vector<std::string> split(const std::string& original, const std::string& delimiter);

bool contains(const std::string& text, const std::string& textToFind);
