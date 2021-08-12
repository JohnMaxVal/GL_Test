#include "InputParser.h"

InputParser::InputParser(int argc, char *argv[]) {
  if(argc >= 2) {
    this->isValidInput = true;
    std::string token = std::string(argv[1]);
    this->m_periodicity = std::stod(token);
    if(!this->checkValidPeriodicity()) {
      this->isValidInput = false;
      this->m_errMsg = std::string("Invalid period");
    }
  }
  else {
    this->m_errMsg = std::string("Input parameter isn't specified");
  }
}

double InputParser::getTokenValue() const {
  return m_periodicity;
}

std::string InputParser::getErrorMessage() {
  return m_errMsg;
}

// private methods
bool InputParser::checkValidPeriodicity() const { // [1-1000]
  return (m_periodicity >= 0 && m_periodicity <= 1000);
}

