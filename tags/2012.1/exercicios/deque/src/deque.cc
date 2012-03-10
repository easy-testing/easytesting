// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "deque/src/deque.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

deque::deque() {
  // TODO.
}

deque::~deque() {
  // TODO.
}

bool deque::empty() {
  return false;  // TODO.
}

int deque::size() {
  return 0;  // TODO.
}

LType deque::front() {
  return end_->key;  // TODO.
}

LType deque::back() {
  return end_->key;  // TODO.
}

void deque::push_front(LType k) {
  // TODO.
}

void deque::pop_front() {
  // TODO.
}

void deque::push_back(LType k) {
  // TODO.
}

void deque::pop_back() {
  // TODO.
}

void deque::operator=(deque& d) {
  // TODO.
}
