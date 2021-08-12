#include "Counter.h"

namespace counter {

  Counter::Counter(uint32_t cnt): m_cnt{cnt} {}
  
  uint32_t Counter::incrementCounter() {
    return m_cnt++;
  }
  
}
