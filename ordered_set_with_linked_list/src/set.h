// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_TEMPLATED_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_
#define BRANCHES_TEMPLATED_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_

#include <string>

// Define como os elementos da lista encadeada serão organizados na memória.
template <class Type> struct Node {
  Type key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Implementa um iterador sobre os elementos da lista encadeada
template <class Type> class SetIterator {
 private:
  Node<Type>* node_;

  SetIterator(Node<Type>* x) {  // NOLINT
    node_ = x;
  }

 public:
  SetIterator(const SetIterator& it) {
    node_ = it.node_;
  }

  void operator++(int) {
    node_ = node_->next;
  }

  void operator--(int) {
    node_ = node_->prev;
  }

  Type operator*() const {
    return node_->key;
  }

  bool operator==(const SetIterator& it) {
    return node_ == it.node_;
  }

  bool operator!=(const SetIterator& it) {
    return node_ != it.node_;
  }

  friend class Teste;
  template <class T> friend class set;
};

// Implementa um conjunto de elementos utilizando listas encadeadas.
// NOTA1: Nesta implementão, os elementos do conjunto estão ordenados na lista
// encadeada do menor para o maior.
// Para simplificar as funções de complexidade, denota-se n = size_.
template <class Type> class set {
 private:
  // Número de elementos no conjunto.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node<Type>* end_;

 public:
  typedef SetIterator<Type> iterator;

  // Cria um conjunto vazio em O(1).
  set() {
    size_ = 0;
    end_ = new Node<Type>;
    end_->next = end_;
    end_->prev = end_;
  }

  // Testa se o cojunto está vazio em O(1).
  bool empty() const {
    return size_ == 0;
  }

  // Retorna o número de elementos no conjunto em O(1).
  int size() const {
    return size_;
  }

  // Retorna um ponteiro para o primeiro (menor) elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  iterator begin() const {
    return iterator(end_->next);
  }

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  iterator end() const {
    return iterator(end_);
  }

  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  iterator find(Type k) const {
    for (iterator i = begin(); i != end(); i++) {
      if (*i == k) {
        return i;
      } else if (*i > k) {
        return end();
      }
    }
    return end();  // k é maior que todos os elementos contidos no conjunto.
  }

  // Insere k no conjunto em O(n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(Type k) {
    // Encontra o primeiro elemento que não é menor que k na lista encadeada.
    iterator it = begin();
    while (it != end() && *it < k) {
      it++;
    }
    // Caso k já não esteja no conjunto, cria um novo nó para armazenar k.
    if (it == end() || *it != k) {
      // Cria um novo nó e define o valor dos seus campos.
      Node<Type>* x = it.node_;
      Node<Type>* node = new Node<Type>;
      node->key = k;
      node->prev = x->prev;
      node->next = x;
      // Ajusta o valor dos ponteiros dos nós adjacentes ao novo nó.
      x->prev->next = node;
      x->prev = node;
      size_++;
    }
  }

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(Type k) {
    iterator it = find(k);
    if (it != end()) {
      Node<Type>* x = it.node_;
      x->prev->next = x->next;
      x->next->prev = x->prev;
      delete x;
      size_--;
    }
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
    while (!empty()) {
      erase(*begin());
    }
  }

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m), onde m = s.size().
  void operator=(const set& s) {
    clear();
    if (!s.empty()) {
      for (Node<Type>* i = s.end_->prev; i != s.end_; i = i->prev) {
        insert(i->key);
      }
    }
  }

  // Libera toda a memória alocada para o conjunto em O(n).
  ~set() {
    clear();
    delete end_;
  }

  friend class Teste;
};

#endif  // BRANCHES_TEMPLATED_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_
