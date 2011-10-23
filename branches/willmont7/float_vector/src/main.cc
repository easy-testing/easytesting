// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre vetores dinâmicos.
//
// Questão 1.
// Implemente em float_FloatVector.h e float_FloatVector.cc o TAD FloatVector.
//
// Questão 2.
// Implemente uma função "void FiltraPositivos(FloatVector& v)" que recebe um
// vetor dinâmico 'v' e remove de v todos os números que não são positivos.
//
// Questão 3.
// Escreva um programa que (i) lê de um arquivo um conjunto de números reais,
// (ii) armazena-os em um FloatVector, (iii) Chama a função
// "void FiltraPositivos(FloatVector& v)" (Questão 2) para remover os números
// não positivos de 'v' e (iv) imprime na tela apenas os números
// positivos que estavam no arquivo.


#include <iostream>
#include <fstream>
#include "float_vector/src/float_vector.h"

using namespace std;

void FiltraPositivos(FloatVector& v) {
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) <= 0) {
      v.erase(i);
      i--;
    }
  }
}

int main() {
  ifstream fin("input.txt");
  int n;
  fin >> n;
  FloatVector v(n);
  for (int i = 0; i < n; i++) {
    fin >> v.at(i);
  }
  FiltraPositivos(v);
  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << endl;
  }

  return 0;
}