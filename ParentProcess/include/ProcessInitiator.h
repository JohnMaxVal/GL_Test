#ifndef PROCESS_INITIATOR_H_
#define PROCESS_INITIATOR_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <chrono>
#include <thread>

namespace process_initiator {

  class ProcessInitiator
  {
  public:
    static void run(char* command);
  };
  
}

#endif
