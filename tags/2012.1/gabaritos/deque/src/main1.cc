// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre listas encadeadas - deque.
//
// Questão 1.
// Implemente em deque.h e deque.cc o TAD deque, utilizando listas ligadas.
//
// Questão 2.
// Escreva uma função "void Imprimir(deque& d)" que recebe como parâmetro um
// deque e imprime os elementos do deque na tela do computador.
//
// Questão 3.
// Escreva uma função "void MergeSort(deque& q)" que ordena os elementos de um
// deque em O(n*log n), onde n = q.size().
//
// Questão 4.
// Escreva um programa que lê um conjunto de números reais de um arquivo,
// Armazena-os em um deque e imprime os números ordenados na tela.

#include <fstream>
#include <iostream>

#include "deque/src/deque.h"

using namespace std;

// Questão 2.
void Imprimir(deque& d) {
  cout << "[ ";
  for (int i = 0; i < d.size(); i++) {
    cout << d.front() << " ";
    d.push_back(d.front());
    d.pop_front();
  }
  cout << "]" << endl;
}

// Concatena dois deques ordenados q1 e q2 em um único deque ordenado r.
void Merge(deque& q1, deque& q2, deque* r) {
  int n = q1.size() + q2.size();
  for (int i = 0; i < n; i++) {
    if (q1.empty()) {
      r->push_back(q2.front());
      q2.pop_front();
    } else if (q2.empty()) {
      r->push_back(q1.front());
      q1.pop_front();
    } else if (q2.front() < q1.front()) {
      r->push_back(q2.front());
      q2.pop_front();
    } else {  // q2.front() >= q1.front()
      r->push_back(q1.front());
      q1.pop_front();
    }
  }
}

// Questão 3.
void MergeSort(deque& q) {
  if (q.size() > 1) {
    deque v[2];
    for (int i = 0; !q.empty(); i++) {
      v[i % 2].push_back(q.front());
      q.pop_front();
    }
    MergeSort(v[0]);
    MergeSort(v[1]);
    Merge(v[0], v[1], &q);
  }
}

// Questão 4.
int main() {
  ifstream fin("input1.txt");
  deque d;
  float x;
  while (fin >> x) {
    d.push_back(x);
  }
  MergeSort(d);
  Imprimir(d);
  return 0;
}
