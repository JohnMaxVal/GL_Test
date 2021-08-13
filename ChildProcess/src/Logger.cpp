#include <iostream>

#include "Logger.h"

namespace logger {

  Logger::Logger(double ms):
    m_ms{ms}
  {
    actualizeCounter();

    try {
      m_file.open(getLogFilePath(), std::ios::out);
    }
    catch(...) {
      if(m_file.is_open())
	m_file.close();
      if(m_configFile.is_open())
	m_configFile.close();
    }
  }

  Logger::~Logger() {
    writeConfigFile();
    m_configFile.close();
  }

  void Logger::consoleLogging() {
    auto log = [&]()
	       {
		 uint32_t counter = m_counter.incrementCounter();
		 std::cout << "Counter: " << counter << std::endl;
		 m_file << "Counter: " << counter << std::endl;
	       };
    Timer::setTimer(log, static_cast<int>(m_ms));
  }

  void Logger::writeConfigFile() {
    m_configFile.open(getConfigFilePath());
    if(m_configFile.is_open()) {
      m_configFile << m_counter.incrementCounter() - 1;
      m_configFile.close();
    }
  }

  void Logger::actualizeCounter() {
    std::ifstream file(getConfigFilePath(), std::ios::in);
    if(file.is_open()) {
      std::string line;
      std::getline(file, line);
      this->m_counter = std::stoi(line);
    }
    file.close();
  }

  std::string Logger::getLogFilePath() const {
    return "../logs/log_" + Timer::getCurrentDateTime() + ".txt";
  }

  std::string Logger::getConfigFilePath() const {
    return "../logs/.counter";
  }
}
