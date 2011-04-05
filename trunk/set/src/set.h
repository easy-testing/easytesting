// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "set/src/binary_search_tree.h"

template<class Type> class BinarySearchTree;

// Implementa um conjunto. O calculo da complexidade das fun��es assume que a
// �rvore esta sempre balanceada, o que n�o � garantido nesta implenta��o.
// Ou seja, considera-se que a altura da arvore eh O(log n),
// onde n eh o numero de elementos no conjunto.
template<class Type>
class set {
 public:
  // Tipo da �rvore que representa o conjunto.
  typedef BinarySearchTree<Type> Tree;

  // Cria um conjunto vazio em O(1).
  set() {
    size_ = 0;
  }

  // Cria um conjunto com os mesmos elementos de c em O(n).
  set(set<Type>& c) {
    list<Type> l;
    c.ToList(&l);
    for (Node<Type>* i = l.begin(); i != l.end(); i = i->next) {
      insert(i->key);
    }
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return tree_.empty();
  }

  // Retorna o n�mero de elementos no cojunto em O(1).
  int size() {
    return size_;
  }

  // Retorna o menor elemento do cojunto em O(log n).
  Type min() {
    return tree_.min();
  }

  // Testa se x pertece ao conjunto em O(log n).
  bool find(Type x) {
    return !tree_.find(x)->empty();
  }

  // Insere x no conjunto em O(log n).
  // Retorna false se x j� estava no conjunto ou true caso contr�rio.
  bool insert(Type x) {
    if (find(x)) {
      return false;
    } else {
      tree_.insert(x);
      size_++;
      return true;
    }
  }

  // Remove x do conjunto em O(log n).
  // Retorna true se algum elemento foi removido ou falso caso contr�rio.
  bool erase(Type x) {
    if (find(x)) {
      tree_.find(x)->erase();
      size_--;
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
    size_ = 0;
  }

 private:
  // N�mero de elementos no conjunto.
  int size_;

  // �rvore bin�ria de busca que representa o conjunto.
  Tree tree_;
};  // end class set.

#endif  // SET_SRC_SET_H_
