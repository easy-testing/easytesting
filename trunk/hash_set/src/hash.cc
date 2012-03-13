// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "hash_set/src/hash.h"

#include <cmath>
#include <cstdlib>
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
