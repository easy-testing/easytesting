// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

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

bool list::empty() {
  return size_ == 0;
}

int list::size() {
  return size_;
}

Node* list::begin() {
  return end_->next;
}

Node* list::end() {
  return end_;
}

Node* list::next(Node* x) {
  return x->next;
}

Node* list::prev(Node* x) {
  return x->prev;
}

LType& list::operator[](Node* x) {
  return x->key;
}

void list::operator=(list& l) {
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

void list::merge(list& l) {
  for (Node* i = l.begin(); i != l.end(); i = l.next(i)) {
    insert(end(), l[i]);
  }
}

list::~list() {
  clear();
  delete end_;
}
