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
    list_.clear();
  }

  // Testa se o cojunto esta vazio em O(1).
  // Cria um conjunto vazio em O(1).
  linear_set() {
    list_.clear();
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return list_.empty();
  }

  // Retorna o número de elementos no cojunto em O(1).
  int size() {
    return list_.size();
  }

  // Testa se x pertece ao conjunto em O(n).
  bool find(Type x) {
    for (it_ = list.begin(); it_ != list_.end(); ++it_) {
      if (*it_ == x) return true;
      else if (*it > x) return false;  // Lista está ordenada
    }
    return false;
  }

  // Insere x no conjunto em O(1). Retorna false se x já estava no conjunto
  // r true caso contrário.
  bool insert(Type x) {
    for (it_ = begin(); it_ != list_.end(); ++it_) {
        if (*it_ == x) return false;
        else if (*it_ > x) {
             list_.insert(x);
             return true;
        }
    }
    return false;
  }

  // Remove x do conjunto em O(1). Retorna o número de elementos removidos.
  int erase(Type x) {
      list_.erase(x);
      return 1;  // Em conjuntos só há 1 elemento de cada valor
  }

  // Insere todos os elementos do conjunto no final de l em O(n)
  void ToList(list<Type>* l) {
       for (it_ = list_.begin(); it_ != list_.end(); ++it_) {
           l.push_back(*it);
       }
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
       list_.clear();
  }

 private:
  // Número de elementos no conjunto.
  int size_;

  // Lista que representa o conjunto.
  list<Type> list_;
  list<Type>::iterator it_;
};  // end class linear_set.

#endif  // SET_SRC_SET_H_
