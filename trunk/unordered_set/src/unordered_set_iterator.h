#ifndef IN_ORDER_ITERATOR_H_
#define IN_ORDER_ITERATOR_H_

#include "easytesting/list/src/list_iterator.h"
#include "easytesting/list/src/list.h"

template<class Type> class list;
template<class Type> class ordered_set;
template<class Type> class ListIterator;

// Implementa um iterador de tabelas de dispersão.
template<class Type>
class UnorderedSetIterator {
 public:
  // Tipo da lista que representa as linhas da tabela de dispersão.
  typedef list<Type> List;

  // Tipo do iterador da lista.
  typedef ListIterator<Type> list_iterator;

  UnorderedSetIterator(List* line, list_iterator* node, list_iterator* end) {
    //current_line_ = line;
    //current_node_ = *node;
    //end_ = *end;
  }

  Type operator*() {
    return *current_node_;
  }

  void operator++() {
    ++current_node_;
    if (current_node_ == current_line_->end()) {
      while (current_line_->empty() && current_node_ != end_) {
        current_line_++;
        current_node_ = current_line_->begin();
      }
    }
  }

  bool operator==(UnorderedSetIterator<Type> i) {
    return current_node_ == i.current_node_;
  }

  bool operator!=(UnorderedSetIterator i) {
    return current_node_ != i.current_node_;
  }

  list_iterator node() {
    return current_node_;
  }

 private:
  friend class ordered_set<Type>;

  // Linha corrente do iterador.
  List* current_line_;

  // Elemento corrente do iterador.
  list_iterator current_node_;

  // Iterador para "depois" do último elemento da última linha da tabela.
  list_iterator end_;
};  // end class UnorderedSetIterator.
#endif  // IN_ORDER_ITERATOR_H_
