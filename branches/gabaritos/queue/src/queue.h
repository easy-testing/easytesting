// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "queue/src/node.h"

// Implementa uma fila de elementos utilizando Listas Ligadas.
// O tipo dos elementos � definido por 'type'.
class queue {
 public:
  // Cria uma fila vazia em O(1).
  queue();

  // Libera a mem�ria alocada para todos os elementos da fila em O(n),
  // onde n � o n�mero de elementos na fila.
  ~queue();

  // Testa se a fila est� vazia em O(1).
  bool empty();

  // Retorna o n�mero de elementos na fila em O(1).
  int size();

  // Retorna o elemento que est� no in�cio da fila em O(1).
  // PRECONDI��O: a fila n�o pode estar vazia.
  type front();

  // Retorna o elemento que est� no final da fila em O(1).
  // PRECONDI��O: a fila n�o pode estar vazia.
  type back();

  // Insere x no final da fila em O(1).
  void push(type x);

  // Remove o elemento que est� no in�cio da fila em O(1).
  // PRECONDI��O: a fila n�o pode estar vazia.
  void pop();

 private:
  // N�mero de elementos na fila.
  int size_;

  // Ponteiro para o n� sentinela da fila.
  node* end_;

  friend class Teste;
};

#endif  // SET_SRC_SET_H_
