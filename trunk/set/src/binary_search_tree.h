#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdlib.h>

#include "easytesting/list/src/list.h"

// Implementa uma �rvore bin�ria de busca.
template<class Type>
class BinarySearchTree {
 public:
  // Cria uma �rvore vazia em O(1).
  BinarySearchTree() {
    right_ = left_ = this;
  }

  // Testa se a �rvore � vazia em O(1).
  bool empty() {
    return left_ == this || right_ == this;
  }

  // Testa se a �rvore � uma folha em O(1).
  bool leaf() {
    if (empty()) {
      return false;
    } else {
      return left()->empty() && right()->empty();
    }
  }

  // Retorna a raiz da �rvore em O(1).
  BinarySearchTree* root() {
    return this;
  }

  // Retorna a sub�rvore esquerda em O(1).
  // A �rvore n�o pode ser vazia.
  BinarySearchTree* left() {
    return left_;
  }

  // Retorna a subarvore direita em O(1).
  // A �rvore n�o pode ser vazia.
  BinarySearchTree* right() {
    return right_;
  }

  // Retorna a chave da �rvore em O(1).
  // A �rvore n�o pode ser vazia.
  Type key() {
    return key_;
  }

  // Altera a chave da �rvore em O(1). Se a �rvore for vazia,
  // ela passa ent�o a ser uma folha.
  void set_key(Type key) {
    if (empty()) {
      left_ = new BinarySearchTree();
      right_ = new BinarySearchTree();
    }
    key_ = key;
  }

  int size() {
    if (empty()) {
      return 0;
    } else {
      return 1 + left()->size() + right()->size();
    }
  }

  // Retorna o menor elemento da �rvore em O(log n).
  // A �rvore n�o pode ser vazia.
  BinarySearchTree* min() {
    if (left()->empty()) {
      return this;
    } else {
      return left()->min();
    }
  }

  // Retorna o menor elemento da �rvore em O(log n).
  // A �rvore n�o pode ser vazia.
  BinarySearchTree* max() {
    if (right()->empty()) {
      return this;
    } else {
      return right()->max();
    }
  }

  // Retorna a sub�rvore cuja chave � x, ou a �rvore vazia onde x
  // estaria se estivesse na �rvore em O(log n).
  BinarySearchTree* find(Type x) {
    if (empty() || x == key()) {
      return this;
    } else if (x < key()) {
      return left()->find(x);
    } else {  // x > key()
      return right()->find(x);
    }
  }

  // Insere x na �rvore e retorna a sub�rvore que cont�m x em O(log n).
  BinarySearchTree* insert(Type x) {
    BinarySearchTree* node = find(x);
    node->set_key(x);
    return node;
  }

  // Apaga apenas a raiz da �rvore em O(log n). A �rvore n�o pode ser vazia.
  void erase() {
    if (leaf()) {
      clear();
    } else {
      BinarySearchTree* node = left()->empty() ? right()->min() : left()->max();
      set_key(node->key());
      node->erase();
    }
  }

  // Apaga todos os elementos da �rvore em O(n). Ao final, a arvore � vazia.
  void clear() {
    if (!empty()) {
      delete left_;
      delete right_;
      left_ = right_ = this;
    }
  }

  // Insere os lementos da �rvore em ordem no final da lista l.
  void ListInOrder(list<Type>* l) {
    if (!empty()) {
      left()->ListInOrder(l);
      l->push_back(key());
      right()->ListInOrder(l);
    }
  }

  // Libera toda a mem�ria alocada para a �rvore em O(n).
  ~BinarySearchTree() {
    clear();
  }

 private:
  // Valor do n� raiz.
  Type key_;

  // Subarvore esquerda.
  BinarySearchTree* left_;

  // Subarvore direita.
  BinarySearchTree* right_;
};
#endif  // BINARY_TREE_H_
