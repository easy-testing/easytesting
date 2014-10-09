// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef SRC_PRIORITY_QUEUE_H_
#define SRC_PRIORITY_QUEUE_H_

#include <string>

// Define como os elementos da fila de prioridades serão organizados na memória.
// É declarado aqui, mas só é implementado em priority_queue.cc para não violar
// o encapsulamento.
struct Node;

// Implementa uma fila de prioridades utilizando árvores binárias de busca.
// NOTA1: Podem haver elementos repetitos.
// NOTA2: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade da fila (i.e. n = size_). Entretanto, isto não é garantido
// nesta implentação.
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

  // Libera a memória alocada para todos os elementos da fila em O(n.log n).
  ~priority_queue();

 private:
  // Número de elementos na fila.
  int size_;

  // Ponteiro para a raiz da árvore.
  // "root_ == NULL" se o conjunto é vazio.
  Node* root_;

  friend class Teste;
};

#endif  // SRC_PRIORITY_QUEUE_H_
