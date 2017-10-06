#include <stdlib.h> // rand, RAND_MAX
#include <stdio.h>  // printf
#include <time.h>   // time

#define DIAMETER (RADIUS * 2)
#define RADIUS 1

#define NPOINTS 1000000

int main() {
  int circle_count = 0;
  srand(time(NULL));
# pragma omp for nowait
  for (int i = 0; i < NPOINTS; ++i)
  {
    // generate a point inside the square
    double x = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS,
           y = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS;

    if ((x * x) + (y * y) <= (RADIUS * RADIUS))
    {
#     pragma omp atomic
      ++circle_count;
    }
  }

  printf("Pi: %f\n", 4 * ((double)circle_count / (double)NPOINTS));
}

