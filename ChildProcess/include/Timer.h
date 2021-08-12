#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <thread>
#include <functional>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <string>

namespace timer {

  class Timer
  {
  public:
    Timer() = delete;
    
    static void setTimer(std::function<void(void)> func, int delay);
    static std::string getCurrentDateTime();
  };
  
}

#endif
