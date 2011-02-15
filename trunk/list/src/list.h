#ifndef LIST_H_
#define LIST_H_

#include "easytesting/list/src/list_iterator.h"
#include "easytesting/list/src/list_node.h"

template<class Type>
class list {
 public:
  typedef ListNode<Type> Node;  // Tipo dos nós da lista.
  typedef ListIterator<Type> iterator;  // Tipo do iterador da lista.

  // Cria uma lista vazia em O(1).
  list() {
    end_ = new Node();
  }

  // Remove todos os elementos da lista para liberar a memoria.
  ~list() {
    clear();
    delete end_;
  }

  // Retorna um iterador para o primeiro elemento da lista em O(1).
  iterator begin() {
    return iterator(end_->right);
  }

  // Retorna um iterador para "depois" do ultimo elemento da lista em O(1).
  iterator end() {
    return iterator(end_);
  }

   // Testa se a lista esta vazia em O(1).
  bool empty() {
    return end_->right == end_;
  }

  // Retorna o valor do primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type& front() {
    return end_->right->key;
  }

  // Retorna o valor do último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type& back() {
    return end_->left->key;
  }

  // Retorna o número de elementos da lista em O(n).
  int size() {
    int s = 0;
    for (iterator i = begin(); i != end(); ++i) {
      s++;
    }
    return s;
  }

  // Insere x no início da lista em O(1).
  void push_front(Type x) {
    insert(begin(), x);
  }

  // Remove o primeiro elemento da lista em O(1).
  void pop_front() {
    erase(begin());
  }

  // Insere x no final da lista em O(1).
  void push_back(Type x) {
    insert(end(), x);
  }

  // Remove o último elemento da lista em O(1).
  void pop_back() {
    erase(end_->left);
  }

  // Insere x antes do elemento identificado por posision em O(1).
  iterator insert(iterator position, Type x) {
    Node* node = position.current_;
    node->left = node->left->right = new Node(x, node->left, node);
  }

  // Apaga o elemento indicado por posision em O(1).
  void erase(iterator position) {
    Node* node = position.current_;
    node->left->right = node->right;
    node->right->left = node->left;
    delete node;
  }


  // Remove todos os elementos da lista corrente em O(n).
  void clear() {
    while (!empty()) {
      pop_back();
    }
  }

  // Atribui l a lista corrente em O(n).
  list& operator=(list& l) {
    clear();
    merge(l);
    return *this;
  }

  // Concatena os elementos de l no final da lista corrente em O(n).
  void merge(list& l) {
    for (iterator i = l.begin(); i != l.end(); ++i) {
      push_back(*i);
    }
  }

private:
  // Ponteiro para o nó sentinela da lista.
  Node* end_;
};

#endif  // LIST_H_
