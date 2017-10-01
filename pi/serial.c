#include <stdlib.h> // rand, RAND_MAX
#include <stdio.h>  // printf
#include <time.h>   // time

#define DIAMETER (RADIUS * 2)
#define RADIUS 1

int main() {
  int npoints = 1000000, circle_count = 0;
  srand(time(NULL));
  for (int j = 1; j < npoints; j++) {
    // generate a point inside the square
    double x = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS,
           y = ((rand() / (double)RAND_MAX) * DIAMETER) - RADIUS;

    if ((x * x) + (y * y) <= (RADIUS * RADIUS))
      ++circle_count;

  }
  printf("Pi: %f\n", 4 * ((double)circle_count / (double)npoints));
}

