#include "parallel.h"

#include <stdlib.h> // rand, RAND_MAX
#include <stdio.h>    // printf
#include <time.h>   // time

#include "omp.h"

#include "config.h"

namespace parallel {
double pi() {
  int circle_count = 0;
  srand(time(NULL));
# pragma omp for nowait num_threads(16)
  for (int j = 1; j < NPOINTS; j++) {
#   pragma omp critical
    printf("Hello from thread %d\n", omp_get_thread_num());
    // generate a point inside the square
    double x = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS,
           y = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS;

    if ((x * x) + (y * y) <= (RADIUS * RADIUS))
#     pragma omp atomic
      ++circle_count;
  }

  return 4 * (double)circle_count / (double)NPOINTS;
}
}

