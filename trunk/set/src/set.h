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

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return tree_.empty();
  }

  // Retorna o n�mero de elementos no cojunto em O(1).
  int size() {
    return size_;
  }

  // Testa se x pertece ao conjunto em O(log n).
  bool find(Type x) {
    return !tree_.find(x)->empty();
  }

  // Insere x no conjunto em O(log n). Retorna false se x j� estava no conjunto
  // r true caso contr�rio.
  bool insert(Type x) {
    if (tree_.find(x)->empty()) {
      tree_.insert(x);
      size_++;
      return true;
    } else {
      return false;
    }
  }

  // Remove x do conjunto em O(1). Retorna o n�mero de elementos removidos.
  int erase(Type x) {
    if (!tree_.find(x)->empty()) {
      tree_.find(x)->erase();
      size_--;
      return 1;
    }
    return 0;
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
