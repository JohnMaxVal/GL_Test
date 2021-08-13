#include "ProcessInitiator.h"

namespace process_initiator {

  void ProcessInitiator::run(char* command) {
      while(true) {
	pid_t pid = fork();

	if(pid == 0) {
	    execl("../ChildProcess/logger",
		  "../ChildProcess/logger",
		  command,
		  (char*)NULL);

	    exit(1);
	}
	wait(NULL);
	std::this_thread::sleep_for(std::chrono::seconds(1));
      }
  }
}
