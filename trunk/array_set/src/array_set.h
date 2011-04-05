// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Implementa um conjunto usando um vetor estático.
template<class Type>
class array_set {
 public:
  // Cria um conjunto vazio em O(1).
  array_set() {
    n_ = 0;
  }

  // Cria um conjunto com os mesmos elementos de c em O(n).
  array_set(array_set<Type>& c) {
    n_ = c.n_;
    for (int i = 0; i < c.n_; i++) {
      v_[i] = c.v_[i];
    }
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return n_ == 0;
  }

  // Retorna o número de elementos no cojunto em O(1).
  int size() {
    return n_;
  }

  // Testa se x pertece ao conjunto em O(n).
  bool find(Type x) {
    for (int i = 0; i < n_; i++) {
      if (v_[i] == x) {
        return true;
      }
    }
    return false;
  }

  // Insere x no conjunto em O(n).
  // Retorna false se x já estava no conjunto ou true caso contrário.
  bool insert(Type x) {
    if (find(x)) {
      return false;
    } else {
      v_[n_++] = x;
      return true;
    }
  }

  // Remove x do conjunto em O(n).
  // Retorna true se algum elemento foi removido ou falso caso contrário.
  bool erase(Type x) {
    for (int i = 0; i < n_; i++) {
      if (v_[i] == x) {
        v_[i] = v_[n_ - 1];
        n_--;
        return true;
      }
    }
    return false;
  }

  // Remove todos os elementos do conjunto em O(1).
  void clear() {
    n_ = 0;
  }

 private:
  // Número de elementos no conjunto.
  int n_;

  // Vetor que representa o conjunto.
  Type v_[1000];

  friend class Teste;
};  // end class array_set.

#endif  // SET_SRC_SET_H_
