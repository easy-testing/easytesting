// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

#include <iostream>
#include <string>

using namespace std;

// Imprime os elementos da lista entre chaves.
void Print(list<int>& l) {
  cout << "{ ";
  for (Node<int>* i = l.begin(); i != l.end() ; i = i->next) {
    cout << i->key << " ";
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
