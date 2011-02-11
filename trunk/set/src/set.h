#ifndef BINARY_SEARCH_TREE_SET_H_
#define BINARY_SEARCH_TREE_SET_H_

#include "easytesting/set/src/set.h"
#include "easytesting/set/src/binary_tree.h"
#include "easytesting/set/src/set_iterator.h"

template<class Type> class BinaryTree;

// Implementa um conjunto. O calculo da complexidade das funções assume que a
// árvore esta sempre balanceada, o que não é garantido nesta implentação.
// Ou seja, considera-se que a altura da arvore eh O(log n),
// onde n eh o numero de elementos no conjunto.
template<class Type>
class set {
 public:
  typedef BinaryTree<Type> Tree;  // Tipo da árvore que representa o conjunto.
  typedef SetIterator<Type> iterator;  // Tipo do iterador de conjuntos.

  // Cria um conjunto vazio em O(1).
  set() {
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return tree_->empty();
  }

  // Retorna o número de elementos no cojunto em O(n).
  int size() {
    int s = 0;
    for (iterator i = begin(); i != end(); ++i) {
      s++;
    }
    return s;
  }

  iterator begin() {
    Tree* node = tree_.root();
    while(!node->left()->empty()) {
      node = node->left();
    }
    return iterator(node);
  }

  // Retorna um iterados para "depois" do último elemento do conjunto em O(1).
  iterator end() {
    return iterator(NULL);
  }

  // Retorna um iterador para x em O(log n).
  // Caso x não pertença ao conjunto, retora set::end();
  iterator find(Type x) {
    Tree* node = tree_.root();
    while (!node->empty()) {
      if (node->key() == x) {
        return iterator(node);
      }
      node = x < node->key() ? node->left() : node->right();
    }
    return end();
  }

  // Insere x no conjunto e retorna um iterador para x em O(log n).
  iterator insert(Type x) {
    Tree* node = tree_.root();
    while (!node->empty() && node->key() != x) {
      node = x < node->key() ? node->left() : node->right();
    }
    node->set_key(x);
    return iterator(node);
  }

  // Apaga o elemento identificado por position em O(log n).
  // position deve ser um iterador válido para o conjunto.
  // Após esta operação, position é um iterador inválido.
  void erase(iterator position) {
    Tree* node = position.node();
    if (node->left()->empty() && node->right()->empty()) {
      node->clear();
    } else if (node->left()->empty()) {
      Tree* min = node->right();
      while(!min->left()->empty()) {
        min = min->left();
      }
      node->set_key(min->key());
      erase(iterator(min));
    } else {  // node->right()->empty() == true
      Tree* max = node->left();
      while(!max->right()->empty()) {
        max = max->right();
      }
      node->set_key(max->key());
      erase(iterator(max));
    }
  }

  // Remove todos os elementos do conjunto corrente em O(n).
  void clear() {
    tree_.clear();
  }

 private:
  Tree tree_;
};  // end class set.

#endif  // BINARY_SEARCH_TREE_SET_H_
