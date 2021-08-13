#include "ProcessInitiator.h"

using namespace process_initiator;

int main(int argc, char *argv[]) {
  std::cout << "Hello from parent process" << std::endl;

  if(argc >= 2)
    ProcessInitiator::run(argv[1]);
  else
    std::cout << "Input parameters must be specified" << std::endl;

  return 0;
}
