#include "stdlib.h"
#include "math.h"

int hash(int x, int max_size) {
  return abs(x) % max_size;
}

int hash(float x, int max_size) {
  return (int) fabs(x * 1000) % max_size;
}
