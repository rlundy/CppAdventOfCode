#include "Parser.hpp"

Parser::Parser(const std::string& str) : iss(str) {}

Parser& Parser::operator>>(const char& ch) {
  iss.ignore(std::numeric_limits<std::streamsize>::max(), ch);
  return *this;
}

Parser::operator bool() const {
  return static_cast<bool>(iss);
}
