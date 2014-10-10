// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_QUEUE_WITH_LINKED_LIST_SRC_QUEUE_H_
#define TRUNK_QUEUE_WITH_LINKED_LIST_SRC_QUEUE_H_

#include <string>

// Define como os elementos da fila serão organizados na memória.
// É declarado aqui, mas só é implementado em queue.cc para não violar o
// encapsulamento.
struct Node;

// Implementa uma fila de elementos utilizando listas encadeadas.
// O tipo dos elementos contidos na fila é definido por QType.
// O valor de QType deve ser definido em tempo de compilação.
class queue {
 public:
  // Cria uma fila vazia em O(1).
  queue();

  // Libera a memória alocada para todos os elementos da fila em O(n),
  // onde n é o número de elementos na fila.
  ~queue();

  // Testa se a fila está vazia em O(1).
  bool empty() const;

  // Retorna o número de elementos na fila em O(1).
  int size() const;

  // Retorna o elemento que está no início da fila em O(1).
  // Precondição: a fila não pode estar vazia.
  QType front() const;

  // Retorna o elemento que está no final da fila em O(1).
  // Precondição: a fila não pode estar vazia.
  QType back() const;

  // Insere k no final da fila em O(1).
  void push(QType k);

  // Remove o elemento que está no início da fila em O(1).
  // Precondição: a fila não pode estar vazia.
  void pop();

  // Faz a fila corrente ficar igual a q em O(n + m),
  // onde m = q.size() e n é o número de elementos na fila corrente.
  void operator=(const queue& q);

 private:
  // Número de elementos na fila.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend class Teste;
};

#endif  // TRUNK_QUEUE_WITH_LINKED_LIST_SRC_QUEUE_H_
