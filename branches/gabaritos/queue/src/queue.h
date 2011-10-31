// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "queue/src/node.h"

// Implementa uma fila de elementos utilizando Listas Ligadas.
// O tipo dos elementos é definido por 'type'.
class queue {
 public:
  // Cria uma fila vazia em O(1).
  queue();

  // Libera a memória alocada para todos os elementos da fila em O(n),
  // onde n é o número de elementos na fila.
  ~queue();

  // Testa se a fila está vazia em O(1).
  bool empty();

  // Retorna o número de elementos na fila em O(1).
  int size();

  // Retorna o elemento que está no início da fila em O(1).
  // PRECONDIÇÃO: a fila não pode estar vazia.
  type front();

  // Retorna o elemento que está no final da fila em O(1).
  // PRECONDIÇÃO: a fila não pode estar vazia.
  type back();

  // Insere x no final da fila em O(1).
  void push(type x);

  // Remove o elemento que está no início da fila em O(1).
  // PRECONDIÇÃO: a fila não pode estar vazia.
  void pop();

 private:
  // Número de elementos na fila.
  int size_;

  // Ponteiro para o nó sentinela da fila.
  node* end_;

  friend class Teste;
};

#endif  // SET_SRC_SET_H_
