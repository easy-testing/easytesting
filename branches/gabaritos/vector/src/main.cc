// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre vetores dinâmicos.
//
// Questão 1.
// Implemente o TAD vector<Type> em vector.h utilizando.
//
// Questão 2.
// Implemente uma função "void FiltraPositivos(vector& v)" que recebe um vetor
// dinâmico v como parâmetro e remove de v todos os números que não são
// positivos.

#include <iostream>
#include "vector/src/vector.h"

using namespace std;

int main() {
  vector v(10);
  for (int i = 0; i < v.size(); i++) {
    v[i] = i;
  }
  for (int i = 0; i < v.size(); i++) {
    cout << i << " = " << v[i] << endl;
  }
}
