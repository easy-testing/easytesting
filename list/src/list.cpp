// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/list.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

list::list() {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
}

bool list::empty() const {
  return size_ == 0;
}

int list::size() const {
  return size_;
}

Node* list::begin() const {
  return end_->next;
}

Node* list::end() const {
  return end_;
}

Node* list::next(Node* x) const {
  return x->next;
}

Node* list::prev(Node* x) const {
  return x->prev;
}

LType list::key(Node* x) const {
  return x->key;
}

void list::operator=(const list& l) {
  clear();
  merge(l);
}

void list::insert(Node* x, LType k) {
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

void list::erase(Node* x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  delete x;
  size_--;
}

void list::clear() {
  while (!empty()) {
    erase(begin());
  }
}

void list::merge(const list& l) {
  for (Node* i = l.begin(); i != l.end(); i = l.next(i)) {
    insert(end(), l.key(i));
  }
}

list::~list() {
  clear();
  delete end_;
}
