// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Implementa um conjunto usando listas.
template<class Type>
class linear_set {
 public:
  // Cria um conjunto vazio em O(1).
  linear_set() {
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return false;
  }

  // Retorna o número de elementos no cojunto em O(1).
  int size() {
    return 0;
  }

  // Testa se x pertece ao conjunto em O(n).
  bool find(Type x) {
    return false;
  }

  // Insere x no conjunto em O(1). Retorna false se x já estava no conjunto
  // r true caso contrário.
  bool insert(Type x) {
    return false;
  }

  // Remove x do conjunto em O(1). Retorna o número de elementos removidos.
  int erase(Type x) {
  }

  // Insere todos os elementos do conjunto no final de l em O(n)
  void ToList(list<Type>* l) {
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
  }

 private:
  // Lista que representa o conjunto.
  list<Type> list_;
};  // end class linear_set.

#endif  // SET_SRC_SET_H_
