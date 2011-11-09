// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_STACK_SRC_STACK_H_
#define BRANCHES_GABARITOS_STACK_SRC_STACK_H_

#include <string>

// Tipo dos elementos contidos na lista.
typedef std::string  type;

// Defite como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento
struct node;

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
  // PRECONDIÇÃO: a pilha não pode estar vazia.
  type top();

  // Insere k no topo da pilha em O(1).
  void push(type k);

  // Remove o elemento que está no topo da pilha em O(1).
  // PRECONDIÇÃO: a pilha não pode estar vazia.
  void pop();

 private:
  // Número de elementos na pilha.
  int size_;

  // Ponteiro para o nó sentinela da lista ligada.
  node* end_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_STACK_SRC_STACK_H_
