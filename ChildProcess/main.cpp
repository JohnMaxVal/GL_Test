#include <iostream>
#include <csignal>

#include "InputParser.h"
#include "Logger.h"

using namespace logger;

Logger* gl_logger;

void signalHandler(int sigNum) {
  std::cout << "Terminating the program" << std::endl;

  gl_logger->~Logger();

  exit(sigNum);
}

int main(int argc, char *argv[]) {

  signal(SIGINT, signalHandler);

  std::cout << "Hello from logger" << std::endl;
  
  InputParser parser(argc, argv);
  if(!parser.isValidInput) {
    std::cout << parser.getErrorMessage() << std::endl;
    return -1;
  }

  gl_logger = new Logger(parser.getTokenValue());

  gl_logger->consoleLogging();
  
  while(true) ;
  
  return 0;
}
