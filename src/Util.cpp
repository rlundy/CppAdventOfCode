#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <algorithm>
#include <numeric>
#include <cctype>

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

std::vector<int> readInts(const std::string& original) {
    std::istringstream originalStream { original };
    std::istream_iterator<int> start { originalStream };
    std::istream_iterator<int> end;
    std::vector<int> ints { start, end };
    return ints;
}

std::vector<std::string> split(const std::string& original, const std::string& delimiter, const bool keepEmptyParts) {
    std::vector<std::string> parts;
    if (original.empty()) {
        return parts;
    }
    size_t start { 0 }, end { 0 };
    auto delimiterLength { delimiter.length() };

    auto add {
        [&](const std::string& part) {
            if (keepEmptyParts || !part.empty()) {
                parts.push_back(part);
            }
        }
    };

    while ((end = original.find(delimiter, start)) != std::string::npos) {
        add(original.substr(start, end - start));
        start = end + delimiterLength;
    }
    add(original.substr(start));
    return parts;
}

bool contains(const std::string &text, const std::string &textToFind)
{
    return text.find(textToFind) != std::string::npos;
}

std::vector<int> inputToVector(const std::string& input) {
    return textToInt(split(input, "\n"));
}

std::vector<int> textToInt(std::vector<std::string> texts) {
    std::vector<int> numbers;
    if (texts.empty()) {
        return numbers;
    }
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

std::string trim(const std::string& text)
{
    if (text.empty()) {
        return text;
    }
    auto startAt { 0 };
    auto endAt { text.size() - 1 };
    while (std::isspace(text[startAt])) {
        ++startAt;
    }
    while (std::isspace(text[endAt])) {
        --endAt;
    }
    return text.substr(startAt, endAt - startAt + 1);
}

std::string toKey(int x, int y) {
    return std::format("{},{}", x, y);
}

int toInt(std::string binaryRepresentation)
{
    int result { 0 };
    for (auto i { 0 }; i < binaryRepresentation.length(); ++i) {
        if (i > 0) {
            result <<= 1;
        }
        result |= binaryRepresentation[i] - '0';
    }
    return result;
}
