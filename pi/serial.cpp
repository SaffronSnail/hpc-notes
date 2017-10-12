#include "serial.h"

#include <stdlib.h> // rand, RAND_MAX
#include <time.h>   // time

#include "config.h"

namespace serial {
double pi() {
  int circle_count = 0;
  srand(time(NULL));
  for (int j = 1; j < NPOINTS; j++) {
    // generate a point inside the square
    double x = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS,
           y = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS;

    if ((x * x) + (y * y) <= (RADIUS * RADIUS))
      ++circle_count;
  }

  return 4 * (double)circle_count / (double)NPOINTS;
}
}

