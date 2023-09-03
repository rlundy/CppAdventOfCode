#include <string>
#include <vector>

#pragma once

std::string readFileContents(const std::string& filePath);
std::vector<std::string> split(const std::string& original, const std::string& delimiter);
