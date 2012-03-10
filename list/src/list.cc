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

list::list(list& l) {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
  merge(l);
}

list::~list() {
  clear();
  delete end_;
}

int list::size() {
  return size_;
}

bool list::empty() {
  return size_ == 0;
}

Node* list::begin() {
  return end_->next;
}

Node* list::end() {
  return end_;
}

Node* list::next(Node* i) {
  return i->next;
}

Node* list::prev(Node* i) {
  return i->prev;
}

LType& list::operator[](Node* i) {
  return i->key;
}

void list::operator=(list& l) {
  clear();
  merge(l);
}

void list::insert(Node* i, LType k) {
  Node* node = new Node;
  node->key = k;
  node->prev = i->prev;
  node->next = i;
  i->prev->next = node;
  i->prev = node;
  size_++;
}

void list::erase(Node* i) {
  i->prev->next = i->next;
  i->next->prev = i->prev;
  delete i;
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
