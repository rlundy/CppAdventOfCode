#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
