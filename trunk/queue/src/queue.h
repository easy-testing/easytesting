// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Implementa uma estrutura de dados Fila.
template<class Type>
class queue {
 public:
  // Cria uma fila vazia em O(1).
  queue() {
  }

  // Testa se a fila está vazia em O(1).
  bool empty() {
    return list_.empty();
  }

  // Retorna o número de elementos na fila em O(1).
  int size() {
    return list_.size();
  }

  // Retorna o elemento que está no início da fila em O(1).
  Type& front() {
    return list_.front();
  }

  // Retorna o elemento que está no final da fila em O(1).
  Type& back() {
    return list_.back();
  }

  // Insere x no final da fila em O(1).
  void push(Type x) {
    list_.push_back(x);
  }

  // Remove o elemento que está no início da fila em O(1).
  void pop() {
    list_.pop_front();
  }

 private:
  friend class Teste;
  // Lista que representa a fila.
  list<Type> list_;

};  // end class queue.

#endif  // SET_SRC_SET_H_
