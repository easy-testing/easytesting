// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef HASH_SET_SRC_HASH_FUNCTION_H_
#define HASH_SET_SRC_HASH_FUNCTION_H_

#include <string>
#include <math.h>
#include <stdlib.h>

using std::string;

int hash(int x, int max_size) {
  return abs(x) % max_size;
}

int hash(float x, int max_size) {
  return (int) fabs(x * 1000000) % max_size;
}

int hash(string x, int max_size) {
  int h = 0;
  for (int i = 0; i < x.size(); i++) {
    h += (int) x[i];
  }
  return h % max_size;
}

#endif  // HASH_SET_SRC_HASH_FUNCTION_H_
