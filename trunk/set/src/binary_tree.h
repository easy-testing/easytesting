#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include <stdlib.h>

// Implementa uma árvore binária.
template<class Type>
class BinaryTree {
 public:
  // Cria uma arvore vazia em O(1).
  BinaryTree(BinaryTree* parent = NULL) {
    right_ = left_ = this;
    parent_ = parent;
  }

  // Testa se a árvore é vazia em O(1).
  bool empty() {
    return left_ == this || right_ == this;
  }

  // Retorna a a raiz da árvore em O(1).
  BinaryTree* root() {
    return this;
  }

  // Retorna a subárvore esquerda em O(1).
  BinaryTree* left() {
    return left_;
  }

  // Retorna a subarvore direita em O(1).
  BinaryTree* right() {
    return right_;
  }

  // Retorna o pai da subarvore em O(1).
  BinaryTree* parent() {
    return parent_;
  }

  // Retorna a chave da raiz da árvore em O(1).
  Type key() {
    return key_;
  }

  // Altera o valor da chave da raiz em O(1).
  void set_key(Type key) {
    // Se a árvore for vazia, ela passa então a ser uma folha.
    if (empty()) {
      left_ = new BinaryTree(this);
      right_ = new BinaryTree(this);
    }
    key_ = key;
  }

  // Apaga todos os elementos da árvore em O(n). Ao final, a arvore é vazia.
  void clear() {
    if (!empty()) {
      delete left_;
      delete right_;
      left_ = right_ = this;
    }
  }

  // Libera toda a memória alocada para a árvore em O(n).
  ~BinaryTree() {
    clear();
  }

 private:
  // Valor do nó raiz.
  Type key_;

  // Subarvore esquerda.
  BinaryTree* left_;

  // Subarvore direita.
  BinaryTree* right_;

  // Pai da subarvore. NULL se a subarvore for a raiz.
  BinaryTree* parent_;
};
#endif  // BINARY_TREE_H_
