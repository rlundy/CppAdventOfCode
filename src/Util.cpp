#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <algorithm>
#include <numeric>

#include "Util.hpp"

std::string getPuzzleInput(const int year, const int day) {
    auto path { std::format("puzzleInput/Year{}Day{}.txt", year, day) };
    return readFileContents(path);
}

std::string readFileContents(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

std::vector<std::string> split(const std::string& original, const std::string& delimiter) {
    std::vector<std::string> parts;
    size_t start { 0 }, end { 0 };

    while ((end = original.find(delimiter, start)) != std::string::npos) {
        parts.push_back(original.substr(start, end - start));
        start = end + delimiter.length();
    }
    parts.push_back(original.substr(start));
    return parts;
}

bool contains(const std::string &text, const std::string &textToFind)
{
    return text.find(textToFind) != std::string::npos;
}

std::vector<int> inputToVector(const std::string& input) {
    auto parts { split(input, "\n") };
    std::vector<int> numbers;
    std::transform(
        parts.cbegin(),
        parts.cend(),
        std::back_inserter(numbers),
        [](const std::string& s) { return std::stoi(s); }
    );
    return numbers;
}

std::vector<int> textToInt(std::vector<std::string> texts) {
    std::vector<int> numbers;
    std::transform(
        texts.cbegin(),
        texts.cend(),
        std::back_inserter(numbers),
        [](const std::string& s) { return std::stoi(s); }
    );
    return numbers;
}

int sum(const std::vector<int> numbers)
{
    return std::accumulate(numbers.cbegin(), numbers.cend(), 0);
}

int maxInt(const std::vector<int> numbers)
{
    return *std::max_element(numbers.cbegin(), numbers.cend());
}
