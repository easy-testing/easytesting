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
// Implemente uma função "bool PertenceDeque(deque& d, Typex)" que recebe um
// deque d e um elemento x e retorna verdadeiro se x é um dos elementos do
// deque e false caso contrário.
//
// Questão 4.
// Escreva uma função "void MergeSort(deque& q)" que ordena os elementos de um
// deque em O(n*log n), onde n = q.size().
//
// Questão 5.
// Escreva um programa que gerencia uma fila de eventos com duas prioridades.
// Eventos de alta prioridade (high) tem precedência sobre eventos de
// baixa prioridade (low), ou seja, um evento de baixa prioridade só é atendido
// se não existir nenhum evendo de alta prioridade na fila. Eventos de alta
// prioridade são atendidos de acordo com um protocolo LIFO (Last In
// First Out), ou seja, o último evento de alta prioridade que foi inserido na
// fila é o próximo a ser atendido. Já os eventos de baixa prioridade são
// atendidos de acordo com um protocolo FIFO (First In First Out), ou seja,
// os eventos de baixa prioridade são atendidos na ordem em que entraram na
// fila. O seu programa deve ler de um arquivo (ou do teclado) operações do tipo
// "in" e "out". No caso de um operação do tipo "in" seu programa deve solicitar
// o nome e a prioridade do evento e inserir o nome do evento na fila
// de eventos. No caso de operações "out", o seu programa deve retirar o nome
// no próximo evento que será atendido e imprimi-lo na tela.
// Tome o arquivo "input.txt" como exemplo. A saída do seu programa para este
// arquivo deveria ser "e2 e5 e1 e3 e4 e6 e7".
// DICA: Use apenas um único deque com o nome dos eventos para gerenciar a fila
// de eventos.

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

bool PertenceDeque(deque& d, Type x) {
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
