#include "Timer.h"

namespace timer {

  void Timer::setTimer(std::function<void(void)> func, int delay) {
    std::thread log([func, delay]()
		    {
		      while(true) {
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			func();
		      }
		    });
    log.detach();
  }

  std::string Timer::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
  }
  
}
