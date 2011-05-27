// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Implementa uma estrutura de dados Pilha.
template<class Type>
class stack {
 public:
  // Cria uma pilha vazia em O(1).
  stack() {
  }

  // Cria uma pilha com os mesmos elementos de p em O(n).
  stack(stack<Type>& p) {
    list_ = p.list_;
  }

  // Testa se a pilha est� vazia em O(1).
  bool empty() {
    return list_.empty();
  }

  // Retorna o n�mero de elementos na pilha em O(1).
  int size() {
    return list_.size();
  }

  // Retorna o elemento que est� no topo da pilha em O(1).
  Type top() {
    return list_.front();
  }

  // Insere x no topo da pilha em O(1).
  void push(Type x) {
    list_.push_front(x);
  }

  // Remove o elemento que est� no topo da pilha em O(1).
  void pop() {
    list_.pop_front();
  }

  // Faz a pilha corrente ficar igual a p em O(n);
  void operator=(stack<Type>& p) {
    list_ = p.list_;
  }

 private:
  // Lista que representa a pilha.
  list<Type> list_;

  friend class Teste;
};  // end class stack.

#endif  // SET_SRC_SET_H_
