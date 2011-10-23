// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <math.h>
#include <iostream>
#include "array_set/src/array_set.h"

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(array_set<float>& set) {
  array_set<float>& aux = set;
  cout << "{ ";
  while (!aux.empty()) {
    cout << aux.min() << " ";
    aux.erase(aux.min());
  }
  cout << "}";
}

int main() {
  array_set<float> s;
  for (int i = 0; i < 5; ++i) {
    s.insert(i);
    s.insert(-i);
  }

  for (int i = -4; i <= 4; ++i) {
    if (i % 2 == 1 || -i % 2 == 1) {
      s.erase(i);
    }
  }

  s.erase(0.0);
  s.insert(3.14);

  Print(s);
  return 0;
}
