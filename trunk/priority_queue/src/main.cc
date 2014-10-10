// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Filas de Prioridade.
//
// Questão 1.
// Implemente em priority_queue.h e priority_queue.cc o TAD priority_queue,
// utilizando árvores binárias de busca.
//
// Questão 2.
// Implemente uma função "void PriorityQueueSort(int n, float v[])" que ordena
// os elementos de um vetor utilizando uma priority_queue.
//
// Questão 3.
// Escreva um programa para testar a função da questão anterior.

#include <fstream>
#include <iostream>

#include "src/priority_queue.h"

using std::cout;

void Print(int n, float v[]) {
  cout << "{";
  for (int i = 0 ; i < n; i++) {
    cout << v[i];
    if (i < n - 1) {
      cout << ", ";
    }
  }
  cout << "}\n";
}

void PriorityQueueSort(int n, float v[]) {
  priority_queue q;
  for (int i = 0; i < n; i++) {
    q.push(v[i]);
  }
  priority_queue qq;
  qq = q;
  for (int i = 0; i < n; i++) {
    v[i] = qq.top();
    qq.pop();
  }
}

int main() {
  float v[] = {5, 6, 4, 7, 3, 8, 2, 9, 1, 0};
  Print(10, v);
  PriorityQueueSort(10, v);
  Print(10, v);
  return 0;
}
