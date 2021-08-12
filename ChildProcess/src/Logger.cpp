#include <iostream>

#include "Logger.h"

namespace logger {

  Logger::Logger(double ms):
    m_ms{ms}
  {
    actualizeCounter();
    
    std::string logFilePath = "./logs/log_" + Timer::getCurrentDateTime() + ".txt";

    try {
      m_file.open(logFilePath, std::ios::out);
    }
    catch(...) {
      m_file.close();
      m_configFile.close();
      throw;
    }
  }

  Logger::~Logger() { // no destuctor call after termination
    writeConfigFile();
    m_configFile.close();
  }

  void Logger::consoleLogging() {
    //Timer::setTimer(printLogMessage, static_cast<int<(m_ms));
    //auto log = [&]() {std::cout << "Counter: " << m_counter.incrementCounter() << std::endl;}; 
    auto log = [&]()
	       {
		 uint32_t counter = m_counter.incrementCounter();
		 std::cout << "Counter: " << counter << std::endl;
		 m_file << "Counter: " << counter << std::endl;
	       };
    Timer::setTimer(log, static_cast<int>(m_ms));
  }

  void Logger::writeConfigFile() {
    std::string configFilePath = "./logs/.lastCntConfig";
    m_configFile.open(configFilePath);
    m_configFile << m_counter.incrementCounter() - 1;
    m_configFile.close();
  }

  void Logger::actualizeCounter() {
    std::string cfgFileName = "./logs/.lastCntConfig";
    struct stat buffer;
    if(stat(cfgFileName.c_str(), &buffer) == 0) {
      std::ifstream file {cfgFileName};
      std::string line;
      if(file.is_open()) {
	getline(file, line);
	this->m_counter = std::stoi(line);
      }

      file.close();
    }
  }
}
