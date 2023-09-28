#pragma once

#include <sstream>
#include <string>
#include <limits>

class Parser {
public:
  Parser(const std::string& str);
  
  template <typename T>
  Parser& operator>>(T& value) {
    iss >> value;
    return *this;
  }

  Parser& operator>>(const char& ch);
  
  operator bool() const;

private:
  std::istringstream iss;
};
