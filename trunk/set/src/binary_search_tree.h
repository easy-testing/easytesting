#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdlib.h>

#include "easytesting/list/src/list.h"

// Implementa uma árvore binária de busca.
template<class Type>
class BinarySearchTree {
 public:
  // Cria uma árvore vazia em O(1).
  BinarySearchTree() {
    right_ = left_ = this;
  }

  // Testa se a árvore é vazia em O(1).
  bool empty() {
    return left_ == this || right_ == this;
  }

  // Testa se a árvore é uma folha em O(1).
  bool leaf() {
    if (empty()) {
      return false;
    } else {
      return left()->empty() && right()->empty();
    }
  }

  // Retorna a raiz da árvore em O(1).
  BinarySearchTree* root() {
    return this;
  }

  // Retorna a subárvore esquerda em O(1).
  // A árvore não pode ser vazia.
  BinarySearchTree* left() {
    return left_;
  }

  // Retorna a subarvore direita em O(1).
  // A árvore não pode ser vazia.
  BinarySearchTree* right() {
    return right_;
  }

  // Retorna a chave da árvore em O(1).
  // A árvore não pode ser vazia.
  Type key() {
    return key_;
  }

  // Altera a chave da árvore em O(1). Se a árvore for vazia,
  // ela passa então a ser uma folha.
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

  // Retorna o menor elemento da árvore em O(log n).
  // A árvore não pode ser vazia.
  BinarySearchTree* min() {
    if (left()->empty()) {
      return this;
    } else {
      return left()->min();
    }
  }

  // Retorna o menor elemento da árvore em O(log n).
  // A árvore não pode ser vazia.
  BinarySearchTree* max() {
    if (right()->empty()) {
      return this;
    } else {
      return right()->max();
    }
  }

  // Retorna a subárvore cuja chave é x, ou a árvore vazia onde x
  // estaria se estivesse na árvore em O(log n).
  BinarySearchTree* find(Type x) {
    if (empty() || x == key()) {
      return this;
    } else if (x < key()) {
      return left()->find(x);
    } else {  // x > key()
      return right()->find(x);
    }
  }

  // Insere x na árvore e retorna a subárvore que contém x em O(log n).
  BinarySearchTree* insert(Type x) {
    BinarySearchTree* node = find(x);
    node->set_key(x);
    return node;
  }

  // Apaga apenas a raiz da árvore em O(log n). A árvore não pode ser vazia.
  void erase() {
    if (leaf()) {
      clear();
    } else {
      BinarySearchTree* node = left()->empty() ? right()->min() : left()->max();
      set_key(node->key());
      node->erase();
    }
  }

  // Apaga todos os elementos da árvore em O(n). Ao final, a arvore é vazia.
  void clear() {
    if (!empty()) {
      delete left_;
      delete right_;
      left_ = right_ = this;
    }
  }

  // Insere os lementos da árvore em ordem no final da lista l.
  void ListInOrder(list<Type>* l) {
    if (!empty()) {
      left()->ListInOrder(l);
      l->push_back(key());
      right()->ListInOrder(l);
    }
  }

  // Libera toda a memória alocada para a árvore em O(n).
  ~BinarySearchTree() {
    clear();
  }

 private:
  // Valor do nó raiz.
  Type key_;

  // Subarvore esquerda.
  BinarySearchTree* left_;

  // Subarvore direita.
  BinarySearchTree* right_;
};
#endif  // BINARY_TREE_H_
