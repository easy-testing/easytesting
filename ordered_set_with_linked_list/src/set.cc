// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/set.h"

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
}

bool set::empty() const {
  return size_ == 0;
}

int set::size() const {
  return size_;
}

Node* set::begin() const {
  return end_->next;
}

Node* set::end() const {
  return end_;
}

Node* set::next(Node* x) const {
  return x->next;
}

Node* set::prev(Node* x) const {
  return x->prev;
}

SType set::key(Node* x) const {
  return x->key;
}

Node* set::find(SType k) const {
  for (Node* i = begin(); i != end(); i = next(i)) {
    if (i->key == k) {
      return i;
    } else if (i->key > k) {
      return end();
    }
  }
  return end();  // k é maior que todos os elementos contidos no conjunto.
}

void set::insert(SType k) {
  // Encontra o primeiro elemento que não é menor que k na lista encadeada.
  Node* x = begin();
  while (x != end() && x->key < k) {
    x = next(x);
  }
  // Caso k já não esteja no conjunto, cria um novo nó para armazenar k.
  if (x == end() || x->key != k) {
    // Cria um novo nó e define o valor dos seus campos.
    Node* node = new Node;
    node->key = k;
    node->prev = x->prev;
    node->next = x;
    // Ajusta o valor dos ponteiros dos nós adjacentes ao novo nó.
    x->prev->next = node;
    x->prev = node;
    size_++;
  }
}

void set::erase(SType k) {
  Node* x = find(k);
  if (x != end()) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    delete x;
    size_--;
  }
}

void set::clear() {
  while (!empty()) {
    erase(begin()->key);
  }
}

void set::operator=(const set& s) {
  clear();
  if (!s.empty()) {
    for (Node* i = s.end_->prev; i != s.end_; i = i->prev) {
      insert(i->key);
    }
  }
}

set::~set() {
  clear();
  delete end_;
}
