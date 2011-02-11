#ifndef IN_ORDER_ITERATOR_H_
#define IN_ORDER_ITERATOR_H_

#include "easytesting/set/src/binary_tree.h"

template<class Type> class BinaryTree;

// Implementa um iterador de árvore do tipo in-order.
template<class Type>
class SetIterator {
  typedef BinaryTree<Type> Tree;  // Tipo da árvore no qual o iterador itera.
 public:

  SetIterator<Type>(Tree* t) {
    if (t == NULL || t->empty()) {
      current_ = NULL;
    } else {
      current_ = t;
    }
  }

  Type operator*() {
    return current_->key();
  }

  void operator++() {
    current_ = SearchNext(current_->right(), current_);
  }

  bool operator==(SetIterator<Type> i) {
    return current_ == i.current_;
  }

  bool operator!=(SetIterator i) {
    return current_ != i.current_;
  }

  Tree* node() {
    return current_;
  }

 private:
  // Busca qual é o próximo nó da árvore no qual o iterador vai se posicionar.
  Tree* SearchNext(Tree* c, Tree* l) {
    if (c == NULL || l == c->left()) {
      return c;
    } else if (c->empty() || l == c->right()) {
      return SearchNext(c->parent(), c);
    } else {  // l == c->parent
      return SearchNext(c->left(), c);
    }
  }

  // Posição corrente do iterador.
  Tree* current_;
};  // end class SetIterator.
#endif  // IN_ORDER_ITERATOR_H_
