// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em multiset.h e multiset.cc o TAD multiset, utilizando árvores
// binárias de busca.
//
// Questão 2.
// Escreva uma função "void Print(multiset& s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.

#include <fstream>
#include <iostream>
#include <string>

#include "ordered_multiset/src/set.h"

using std::cout;
using std::endl;
using std::ifstream;

void Print(multiset& c) {
  cout << "{ ";
  for (Node* i = c.begin(); i != c.end(); i = c.next(i)) {
    cout << c.value(i) << " ";
  }
  cout << "} = " << c.size() << endl;
}

int main() {
  ifstream fin("input.txt");
  Type k;
  multiset s;
  while(fin >> k) {
    s.insert(k);
  }
  Type max;
  int max_count;
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    if (s.count(s.value(i)) > max_count) {
      max = s.value(i);
      max_count = s.count(s.value(i));
    }
  }
  Print(s);
  cout << "O elemento mais frequente eh: '" << max
      << "' com '" << max_count << "' ocorrencias." << endl;
  return 0;
}
