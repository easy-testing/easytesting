// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef STACK_SRC_STACK_H_
#define STACK_SRC_STACK_H_

#include "stack/src/node.h"

// Implementa uma pilha de elementos utilizando Listas Ligadas.
// O tipo dos elementos � definido por 'type'.
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack();

  // Libera a mem�ria alocada para todos os elementos da pilha em O(n),
  // onde n � o n�mero de elementos na pilha.
  ~stack();

  // Testa se a pilha est� vazia em O(1).
  bool empty();

  // Retorna o n�mero de elementos na pilha em O(1).
  int size();

  // Retorna o elemento que est� no topo da pilha em O(1).
  // PRECONDI��O: a pilha n�o pode estar vazia.
  type top();

  // Insere x no topo da pilha em O(1).
  void push(type x);

  // Remove o elemento que est� no topo da pilha em O(1).
  // PRECONDI��O: a pilha n�o pode estar vazia.
  void pop();

 private:
  // N�mero de elementos na pilha.
  int size_;

  // Ponteiro para o n� sentinela da pilha.
  node* end_;

  friend class Teste;
};

#endif  // STACK_SRC_STACK_H_
