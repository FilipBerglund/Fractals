#ifndef TIMERH
#define TIMERH

#include "timer.h"

void Timer::reset() {
  m_beg = Clock::now();
}

#endif
