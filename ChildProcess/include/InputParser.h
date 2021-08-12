#ifndef INPUT_PARSER_H_
#define INPUT_PARSER_H_

#include <string>
#include <iostream>

class InputParser
{
 public:
  InputParser(int argc, char *argv[]);
  
  double getTokenValue() const;
  std::string getErrorMessage();
  
  bool isValidInput;

 private:
  bool checkValidPeriodicity() const;
  
  double m_periodicity;
  std::string m_errMsg;
};

#endif
