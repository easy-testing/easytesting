// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_WITH_LINKED_LIST_SRC_STACK_H_
#define TRUNK_STACK_WITH_LINKED_LIST_SRC_STACK_H_

#include <string>

// Define como os elementos da pilha serão organizados na memória.
// É declarado aqui, mas só é implementado em stack.cpp para não violar o
// encapsulamento.
struct Node;

// Implementa uma pilha de elementos utilizando Listas Encadeadas.
// O tipo dos elementos contidos na pilha é definido por SType.
// O valor de SType deve ser definido em tempo de compilação.
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack();

  // Testa se a pilha está vazia em O(1).
  bool empty() const;

  // Retorna o número de elementos na pilha em O(1).
  int size() const;

  Node* begin() const;

  Node* end() const;

  // Retorna o elemento que está no topo da pilha em O(1).
  // Precondição: a pilha não pode estar vazia.
  SType top() const;

  // Insere k no topo da pilha em O(1).
  void push(SType k);

  // Remove o elemento que está no topo da pilha em O(1).
  // Precondição: a pilha não pode estar vazia.
  void pop();

  // Faz a pilha corrente ficar igual a p em O(n + m),
  // onde m = p.size() e n = size_.
  void operator=(const stack& p);

  // Libera a memória alocada para a pilha em O(n), onde n = size_.
  ~stack();

 private:
  // Número de elementos na pilha.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend Node* beginTest(const stack& p);

  friend Node* endTest(const stack& p);

  friend int sizeTest(const stack& p);
};

#endif  // TRUNK_STACK_WITH_LINKED_LIST_SRC_STACK_H_
