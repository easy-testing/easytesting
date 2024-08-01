// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre alocacão dinâmica - vetores dinâmicos.
//
// Questão 1.
// Implemente em vector.h e vector.cpp o TAD vector.
//
// Questão 2.
// Implemente uma função "void FiltraPositivos(vector* v)" que recebe um
// vetor dinâmico 'v' e remove de v todos os números que não são positivos.
//
// Questão 3.
// Implemente uma função "void MergeSort(vector& v)" que ordena um vector v
// em O(n.log n).
//
// Questão 4.
// Escreva um programa que (i) lê de um arquivo um conjunto de números reais,
// (ii) armazena-os em um vector, (iii) Remover os números
// não positivos de 'v' e (iv) imprime na tela apenas os números
// positivos que estavam no arquivo ordenados do menor para o maior.

#include <iostream>
#include <fstream>

#include "src/vector.h"

using std::cout;
using std::endl;
using std::ifstream;

// Questão 2.
void FiltraPositivos(vector& v) {  // NOLINT
  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= 0.0) {
      v.erase(i);
      i--;
    }
  }
}

// Questão 3a.
// Mescla dois vetores ordenados v1 e v2 em um único vetor ordenado v.
// Precondição: v->size() == v1.size() + v2.size().
void Merge(vector& v1, vector& v2, vector& v) {  // NOLINT
  int j1 = 0;  // Contador de v1.
  int j2 = 0;  // Contador de v2.
  for (int i = 0; i < v.size(); i++) {
    if (j1 == v1.size()) {
      v[i] = v2[j2++];
    } else if (j2 == v2.size()) {
      v[i] = v1[j1++];
    } else if (v2[j2] < v1[j1]) {
      v[i] = v2[j2++];
    } else {  // v2[j2] < q1[j1]
      v[i] = v1[j1++];
    }
  }
}

// Questão 3b.
void MergeSort(vector& v) {  // NOLINT
  if (v.size() > 1) {
    vector v1(v.size() / 2);
    vector v2(v.size() / 2 + v.size() % 2);
    for (int i = 0; i < v1.size(); i++) v1[i] = v[i];
    for (int i = 0; i < v2.size(); i++) v2[i] = v[i + v.size() / 2 ];
    MergeSort(v1);
    MergeSort(v2);
    Merge(v1, v2, v);
  }
}

int main() {
  ifstream fin("input.txt");
  int n;
  fin >> n;
  vector v(n);
  for (int i = 0; i < n; i++) {
    fin >> v[i];
  }
  FiltraPositivos(v);
  MergeSort(v);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
