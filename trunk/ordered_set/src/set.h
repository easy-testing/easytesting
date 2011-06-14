// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "ordered_set/src/binary_search_tree.h"

template<class Type> class BinarySearchTree;

// Implementa um conjunto. O calculo da complexidade das funções assume que a
// árvore esta sempre balanceada, o que não é garantido nesta implentação.
// Ou seja, considera-se que a altura da arvore eh O(log n),
// onde n eh o numero de elementos no conjunto.
template<class Type>
class set {
 public:
  // Tipo da árvore que representa o conjunto.
  typedef BinarySearchTree<Type> Tree;

  // Cria um conjunto vazio em O(1).
  set() {
    size_ = 0;
  }

  // Cria um conjunto com os mesmos elementos de c em O(n).
  set(set<Type>& c) {
    tree_ = c.tree_;
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return tree_.empty();
  }

  // Retorna o número de elementos no conjunto em O(1).
  int size() {
    return tree_.size();
  }

  // Retorna o menor elemento do conjunto em O(log n).
  Type min() {
    return tree_.min()->key();
  }

  // Testa se x pertece ao conjunto em O(log n).
  bool find(Type x) {
    return !tree_.find(x)->empty();
  }

  // Insere x no conjunto em O(log n).
  // Retorna false se x já estava no conjunto ou true caso contrário.
  bool insert(Type x) {
    if (find(x)) {
      return false;
    } else {
      tree_.insert(x);
      return true;
    }
  }

  // Remove x do conjunto em O(log n).
  // Retorna true se algum elemento foi removido ou falso caso contrário.
  bool erase(Type x) {
    if (find(x)) {
      tree_.find(x)->erase();
      return true;
    } else {
      return false;
    }
  }

  // Insere todos os elementos do conjunto no final de l em O(n)
  void ToList(list<Type>* l) {
    tree_.ListInOrder(l);
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
    tree_.clear();
  }

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto c.
  void operator=(set<Type>& c) {
    tree_ = c.tree_;
  }

 private:
  // Árvore binária de busca que representa o conjunto.
  Tree tree_;
};  // end class set.

#endif  // SET_SRC_SET_H_
