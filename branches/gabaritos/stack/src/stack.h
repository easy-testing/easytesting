// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef STACK_SRC_STACK_H_
#define STACK_SRC_STACK_H_

#include "stack/src/node.h"

// Implementa uma pilha de elementos utilizando Listas Ligadas.
// O tipo dos elementos é definido por 'type'.
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack();

  // Libera a memória alocada para todos os elementos da pilha em O(n),
  // onde n é o número de elementos na pilha.
  ~stack();

  // Testa se a pilha está vazia em O(1).
  bool empty();

  // Retorna o número de elementos na pilha em O(1).
  int size();

  // Retorna o elemento que está no topo da pilha em O(1).
  // PRECONDIÇÃO: a pilha não pode estar vazia.
  type top();

  // Insere x no topo da pilha em O(1).
  void push(type x);

  // Remove o elemento que está no topo da pilha em O(1).
  // PRECONDIÇÃO: a pilha não pode estar vazia.
  void pop();

 private:
  // Número de elementos na pilha.
  int size_;

  // Ponteiro para o nó sentinela da pilha.
  node* end_;

  friend class Teste;
};

#endif  // STACK_SRC_STACK_H_
