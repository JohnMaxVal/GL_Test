#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

#include "Counter.h"
#include "Timer.h"

using namespace counter;
using namespace timer;

namespace logger {

  class Logger {
  public:
    Logger(double ms);
    ~Logger();
    void consoleLogging();

  private:
    std::ofstream m_file;
    std::ofstream m_configFile;
    Counter m_counter{1};
    double m_ms;

    void writeConfigFile();
    void actualizeCounter();
  };
  
}

#endif
