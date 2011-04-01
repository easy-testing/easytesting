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

  // Testa se a pilha está vazia em O(1).
  bool empty() {
    return list_.empty();
  }

  // Retorna o número de elementos na pilha em O(1).
  int size() {
    return list_.size();
  }

  // Retorna o elemento que está no topo da pilha em O(1).
  Type& top() {
    return list_.front();
  }

  // Insere x no topo da pilha em O(1).
  void push(Type x) {
    list_.push_front(x);
  }

  // Remove o elemento que está no topo da pilha em O(1).
  void pop() {
    list_.pop_front();
  }

 private:
  // Lista que representa a pilha.
  friend class Teste;
  list<Type> list_;
};  // end class stack.

#endif  // SET_SRC_SET_H_
