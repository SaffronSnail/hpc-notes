#include "timer.h"

Timer::Timer() {
  start = clock::now();
  stopped = false;
}

void Timer::stop() {
end = clock::now();
  stopped = true;
}

std::chrono::milliseconds Timer::check() {
  if (stopped)
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  else // if (!stopped)
    return std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - start);
}

