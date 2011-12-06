// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_
#define BRANCHES_GABARITOS_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_

#include "type/type.h"

// Defite como os elementos da fila de prioridades serão organizados na memória.
// É declarado aqui, mas só é implementado em priority_queue.cc para não violar
// o encapsulamento
struct Node;

// Implementa uma fila de prioridades utilizando árvores binárias de busca.
// Podem haver elementos repetitos.
// NOTA: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do conjunto. Entretanto, isto não é garantido nesta
// implentação.
class priority_queue {
 public:
  // Cria uma fila de prioridades vazia em O(1).
  priority_queue();

  // Libera a memória alocada para todos os elementos da fila em O(n*log n),
  // onde n é o número de elementos na fila.
  ~priority_queue();

  // Testa se a fila está vazia em O(1).
  bool empty();

  // Retorna o número de elementos na fila em O(1).
  int size();

  // Retorna o MENOR elemento da fila em O(log n).
  // PRECONDIÇÃO: a fila não pode estar vazia.
  Type top();

  // Insere k na fila de prioridades em O(log n).
  void push(Type k);

  // Remove o MENOR elemento da fila em O(log n).
  // PRECONDIÇÃO: a fila não pode estar vazia.
  void pop();

 private:
  // Número de elementos na fila.
  int size_;

  // Nó sentinela da árvore binária de busca que representa a fila de
  // prioridades.
  Node* end_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_
