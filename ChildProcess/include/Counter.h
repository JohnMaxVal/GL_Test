#ifndef COUNTER_H_
#define COUNTER_H_

#include <cstdint>

namespace counter {

  class Counter
  {
  public:
    Counter() = default;
    Counter(uint32_t cnt);

    uint32_t incrementCounter();
    
  private:
    uint32_t m_cnt;
  };
  
}

#endif
