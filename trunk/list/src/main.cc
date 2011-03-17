// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
// TODO(thiago): Escrever enunciado desta lista.

#include "easytesting/list/src/list.h"
//#include <list>

#include <iostream>

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(list<int>& l) {
  cout << "{ ";
  for (list<int>::iterator i = l.begin(); i != l.end() ; ++i) {
    cout << *i << " ";
  }
  cout << "}" << endl;
}

int main() {
  list<int> l;
  for (int i = 0; i < 3; ++i) {
    l.push_back(i);
    l.push_back(-i);
    l.pop_back();
    l.push_front(i);
    l.push_front(-i);
    l.pop_front();
  }
  l.front() = -8;
  Print(l);
  return 0;
}
