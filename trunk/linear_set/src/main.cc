// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <math.h>
#include <iostream>
#include "linear_set/src/linear_set.h"

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(linear_set<float>& set) {
  list<float> l;
  set.ToList(&l);
  cout << "{ ";
  for (Node<float>* i = l.begin(); i != l.end() ; i = i->next) {
    cout << i->key << " ";
  }
  cout << "} = " << l.size() << endl;
}

int main() {
  linear_set<float> s;
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
