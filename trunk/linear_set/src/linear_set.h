// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Implementa um conjunto usando listas.
template<class Type>
class set {
 public:

  // Cria um conjunto vazio em O(1).
  set() {
  }

  // Cria um conjunto com os mesmos elementos de c em O(n).
  set(set<Type>& c) {
    list_.clear();
    list_.merge(c.list_);
  }


  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return list_.empty();
  }

  // Retorna o número de elementos no cojunto em O(1).
  int size() {
    return list_.size();
  }

  // Retorna o menor elemento do cojunto em O(n).
  Type min() {
    Type min = list_.begin()->key;
    for (Node<Type>* i = list_.begin()->next; i != list_.end(); i = i->next) {
      if (i->key < min) {
        min = i->key;
      }
    }
    return min;
  }

  // Testa se x pertece ao conjunto em O(n).
  bool find(Type x) {
    for (Node<Type>* i = list_.begin(); i != list_.end(); i = i->next) {
      if (i->key == x) {
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
      list_.push_back(x);
      return true;
    }
  }

  // Remove x do conjunto em O(n).
  // Retorna true se algum elemento foi removido ou falso caso contrário.
  bool erase(Type x) {
    for (Node<Type>* i = list_.begin(); i != list_.end(); i = i->next) {
      if (i->key == x) {
        list_.erase(i);
        return true;
      }
    }
    return false;
  }

  // Insere todos os elementos do conjunto (em qualquer ordem)
  // no final da lista l em O(n).
  // NOTA: Esta função é usada quando precisa-se percorrer os elementos
  // de um conjunto.
  void ToList(list<Type>* l) {
    l->merge(list_);
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
    list_.clear();
  }

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto c.
  void operator=(set<Type>& c) {
    list_.clear();
    list_.merge(c.list_);
  }

 private:
  // Lista que representa o conjunto.
  list<Type> list_;
};  // end class set.

#endif  // SET_SRC_SET_H_
