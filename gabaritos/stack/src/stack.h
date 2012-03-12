// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_SRC_STACK_H_
#define TRUNK_STACK_SRC_STACK_H_

#include <string>

// Define como os elementos da pilha serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento.
struct Node;

// Implementa uma pilha de elementos utilizando Listas Encadeadas.
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack();

  // Libera a memória alocada para a pilha em O(n),
  // onde n é o número de elementos na pilha.
  ~stack();

  // Testa se a pilha está vazia em O(1).
  bool empty();

  // Retorna o número de elementos na pilha em O(1).
  int size();

  // Retorna o elemento que está no topo da pilha em O(1).
  // Precondição: a pilha não pode estar vazia.
  SType top();

  // Insere k no topo da pilha em O(1).
  void push(SType k);

  // Remove o elemento que está no topo da pilha em O(1).
  // Precondição: a pilha não pode estar vazia.
  void pop();

  // Faz a pilha corrente ficar igual a p em O(n + m),
  // onde m = p.size() e n é o número de elementos na pilha corrente.
  void operator=(stack& p);

 private:
  // Número de elementos na pilha.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend class Teste;
};

#endif  // TRUNK_STACK_SRC_STACK_H_
