// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_
#define TRUNK_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_

#include <string>

// Define como os elementos da fila de prioridades serão organizados na memória.
// É declarado aqui, mas só é implementado em priority_queue.cc para não violar
// o encapsulamento.
struct Node;

// Implementa uma fila de prioridades utilizando árvores binárias de busca.
// Podem haver elementos repetitos.
// NOTA: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do conjunto. Entretanto, isto não é garantido nesta
// implentação. Para simplificar as funções de complexidade,
// denota-se n = size_.
class priority_queue {
 public:
  // Cria uma fila de prioridades vazia em O(1).
  priority_queue();

  // Testa se a fila está vazia em O(1).
  bool empty();

  // Retorna o número de elementos na fila em O(1).
  int size();

  // Retorna o menor elemento da fila em O(log n).
  // Precondição: a fila não está vazia.
  SType top();

  // Insere k na fila de prioridades em O(log n).
  void push(SType k);

  // Remove o menor elemento da fila em O(log n).
  // Precondição: a fila não está vazia.
  void pop();

  // Libera a memória alocada para todos os elementos da fila.
  ~priority_queue();

 private:
  // Número de elementos na fila.
  int size_;

  // Ponteiro para a raiz da árvore.
  // "root_ == NULL" se o conjunto é vazio.
  Node* root_;

  friend class Teste;
};

#endif  // TRUNK_PRIORITY_QUEUE_SRC_PRIORITY_QUEUE_H_
