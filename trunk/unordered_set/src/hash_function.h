// Copyright 2011 Thiago Noronha
#ifndef UNORDERED_SET_SRC_HASH_FUNCTION_H_
#define UNORDERED_SET_SRC_HASH_FUNCTION_H_

#include <stdlib.h>
#include <math.h>

int hash(int x, int max_size) {
  return abs(x) % max_size;
}

int hash(float x, int max_size) {
  return (int) fabs(x * 1000) % max_size;
}

#endif  // UNORDERED_SET_SRC_HASH_FUNCTION_H_
