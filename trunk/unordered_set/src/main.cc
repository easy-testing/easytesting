// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
#include <math.h>
#include <iostream>
#include "easytesting/unordered_set/src/unordered_set.h"

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(unordered_set<float>& set) {
  list<float> l;
  set.ToList(&l);
  cout << "{ ";
  for (list<float>::iterator i = l.begin(); i != l.end() ; ++i) {
    cout << *i << " ";
  }
  cout << "} = " << l.size() << endl;
}

int main() {
  unordered_set<float> s;
  for (int i = 0; i < 5; ++i) {
    s.insert(i);
    s.insert(-i);
  }

  for (int i = -4; i <= 4; ++i) {
    if (i % 2 == 1 || -i % 2 == 1) {
      s.erase(i);
    }
  }

  list<float> l;
  s.ToList(&l);
  for (list<float>::iterator i = l.begin(); i != l.end() ; ++i) {
    if (*i == 0) {
      s.erase(*i);
      break;
    }
  }

  s.insert(3.14);

  Print(s);
  return 0;
}
