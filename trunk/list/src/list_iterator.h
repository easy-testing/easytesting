#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

//#include "easytesting/list/src/list.h"

template<class Type> struct ListNode;

// Implementa um iterador para list<Type>.
template<class Type> class ListIterator {
 public:
  typedef ListNode<Type> Node;

  ListIterator(Node* node) {
    current_ = node;
  }

  Type& operator*() {
    return current_->key;
  }

  void operator++() {
    current_ = current_->right;
  }

  void operator--() {
    current_ = current_->left;
  }

  bool operator==(ListIterator i) {
    return current_ == i.current_;
  }

  bool operator!=(ListIterator i) {
    return current_ != i.current_;
  }

  Node* node() {
    return current_;
  }

 private:
  Node* current_;  // Posicao corrente do iterador.
};  // end class ListIterator;

#endif  // LIST_ITERATOR_H_
