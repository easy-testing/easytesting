// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Filas de Prioridade.
//
// Questão 1.
// Implemente em priority_queue.h e priority_queue.cc o TAD queue,
// utilizando árvores binárias de busca.

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>

#include "type/type.h"
#include "priority_queue/src/priority_queue.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
  for (int i = 0; i < n; i++) {
    v[i] = q.top();
    q.pop();
  }
}

int main() {
  float v[] = {5, 6, 4, 7, 3, 8, 2, 9, 1, 0};
  Print(10, v);
  PriorityQueueSort(10, v);
  Print(10, v);
  return 0;
}
