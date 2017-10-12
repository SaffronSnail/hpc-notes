#include "parallel.h"
#include "serial.h"
#include "timer.h"

#include <iostream>

int main(void) {
  Timer serial_timer;
  auto pi = serial::pi();
  auto time = serial_timer.check();
  std::cout << "SERIAL: ";
  std::cout << "Calculated pi to be " << pi << " in " << time.count()
            << " milliseconds!" << std::endl;

  Timer parallel_timer;
  pi = parallel::pi();
  time = parallel_timer.check();
  std::cout << "PARALLEL: ";
  std::cout << "Calculated pi to be " << pi << " in " << time.count()
            << " milliseconds!" << std::endl;
}

