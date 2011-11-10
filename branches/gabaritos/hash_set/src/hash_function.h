// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_HASH_SET_SRC_HASH_FUNCTION_H_
#define BRANCHES_GABARITOS_HASH_SET_SRC_HASH_FUNCTION_H_

#include <math.h>
#include <stdlib.h>

#include <string>

int hash(int x, int max_size) {
  return abs(x) % max_size;
}

int hash(float x, int max_size) {
  return (int) fabs(x * 1000000) % max_size;
}

int hash(std::string& x, int max_size) {
  int h = 0;
  for (int i = 0; i < x.size(); i++) {
    h += (int) x[i];
  }
  return h % max_size;
}

#endif  // BRANCHES_GABARITOS_HASH_SET_SRC_HASH_FUNCTION_H_
