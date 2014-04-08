// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_WITH_ARRAY_SRC_STACK_H_
#define TRUNK_STACK_WITH_ARRAY_SRC_STACK_H_

#include <string>

// Implementa uma pilha de elementos utilizando arrays.
// O tipo dos elementos contidos na pilha é definido por SType.
// O valor de SType deve ser definido em tempo de compilação.
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack();

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
  // onde m = p.size() e n = size().
  void operator=(stack& p);

// Libera a memória alocada para a pilha em O(1).
  ~stack();

 private:
  // Função que altera o número máximo de elementos na pilha
  // para pelo menos 'm' em O(m).
  void reserve(int m);

  // Número de elementos na pilha.
  int size_;

  // Número de elementos no vetor array_.
  int capacity_;

  // Vetor com os elementos da pilha.
  SType* array_;

  friend class Teste;
};

#endif  // TRUNK_STACK_WITH_ARRAY_SRC_STACK_H_
