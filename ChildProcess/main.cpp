#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>

#include "InputParser.h"
#include "Logger.h"

using namespace logger;

Logger* gl_logger;

static int term_cnt = 0;

void signalHandler(int sigNum) {
  delete gl_logger;
  
  exit(sigNum);
}

int main(int argc, char *argv[]) {

  std::signal(SIGTERM, signalHandler);

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
