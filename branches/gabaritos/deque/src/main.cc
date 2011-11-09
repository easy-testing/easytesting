// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Pilhas.
//
// Questão 1.
// Implemente em deque.h e deque.cc o TAD deque, utilizando listas ligadas.
//
// Questão 2.
// Escreva uma função "void ImprimeDeque(deque* d)" que recebe como parâmetro um
// deque e imprime os elementos do deque na tela do computador.
//
// Questão 3.
// Implemente uma função "bool PertenceDeque(deque& d, type x)" que recebe um
// deque d e um elemento x e retorna verdadeiro se x é um dos elementos do
// deque e false caso contrário.
//
// Questão 4.
// Escreva uma função "void MergeSort(deque& q)" que ordena os elementos de um
// deque em O(n*log n), onde n = q.size().
//
// Questão 5.
// TODO(tfn): escrever enunciado. Eventos de alta prioridade LIFO. Enventos de
// baixa prioridade FIFO.

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "deque/src/deque.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Questão 2.
////////////////////////////////////////////////////////////////////////////////

void ImprimeDeque(deque& d) {
  cout << "[ ";
  for (int i = 0; i < d.size(); i++) {
    cout << d.front() << " ";
    d.push_back(d.front());
    d.pop_front();
  }
  cout << "]" << endl;
}

// Questão 3.
////////////////////////////////////////////////////////////////////////////////

bool PertenceDeque(deque& d, type x) {
  bool pertence = false;
  for (int i = 0; i < d.size(); i++) {
    if (d.front() == x) {
       pertence = true;
    }
    d.push_back(d.front());
    d.pop_front();
  }
  return pertence;
}

// Questão 4.
////////////////////////////////////////////////////////////////////////////////

// Recebe dois deques ordenados q1 e q2 e retorna um deque ordenado com todos os
// elementos de q1 e q2.
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

// Questão 5.
////////////////////////////////////////////////////////////////////////////////

int main() {
  // Lê uma expressão em notação pré-fixada de um arquivo.
  ifstream fin("input.txt");
  deque event_queue;
  string op;
  while (fin >> op) {
    if (op == "out") {
    cout << event_queue.front() << endl;
    event_queue.pop_front();
    } else {  // op == "in"
      string priority, name;
      fin >> priority >> name;
      if (priority == "high") {
        event_queue.push_front(name);
      } else {  // priority == "low"
        event_queue.push_back(name);
      }
    }
  }
  return 0;
}
