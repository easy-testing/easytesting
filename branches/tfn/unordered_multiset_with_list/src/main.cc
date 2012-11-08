// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em set.h e set.cc o TAD set, utilizando árvores binárias de busca.
//
// Questão 2.
// Escreva uma função "void Imprimir(multiset& s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.
//
// Questão 3.
// Implemente uma função "void ImprimirOcorrencias(multiset& s)" que
// imprime na tela o elemento e o número de ocorrências de cada elemento no
// conjunto. Cada elemento do conjunto só deve ser impresso uma única vez.
//
// Questão 4.
// Escreva um programa que lê um conjunto com repetições de um arquivo e
// imprime na tela o elemento e o número de ocorrências de cada elemento no
// conjunto. Cada elemento do conjunto só deve ser impresso uma única vez.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "unordered_multiset_with_list/src/multiset.h"

using namespace std;

// Questão 2.
void ImprimirOcorrencias(set& s) {
  set impressos;
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    if (!impressos.find(s[i])) {
      int d = s.count(s[i]);
      cout << s[i] << ": " << d << endl;
      impressos.insert(s[i]);
    }
  }
}

// Questão 3.
int main() {
  set s;
  ifstream fin("dados.txt");
  int n;
  fin >> n;
  for (int i = 0; i < n; i++) {
    string k;
    fin >> k;
    s.insert(k);
  }
  ImprimirOcorrencias(s);
  return 0;
}
