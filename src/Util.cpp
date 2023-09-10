#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <algorithm>

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

std::vector<int> textToInt(std::vector<std::string> freqText) {
    std::vector<int> frequencies;
    std::transform(
        freqText.cbegin(),
        freqText.cend(),
        std::back_inserter(frequencies),
        [](const std::string& s) { return std::stoi(s); }
    );
    return frequencies;
}
