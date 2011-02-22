// Copyright 2011 Thiago Noronha
#include <math.h>
#include <iostream>
#include "easytesting/set/src/set.h"

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(set<float>& set) {
  list<float> l;
  set.ToList(&l);
  cout << "{ ";
  for (list<float>::iterator i = l.begin(); i != l.end() ; ++i) {
    cout << *i << " ";
  }
  cout << "} = " << l.size() << endl;
}

int main() {
  set<float> s;
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
