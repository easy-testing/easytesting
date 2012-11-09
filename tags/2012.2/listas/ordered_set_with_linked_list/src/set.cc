// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set_with_linked_list/src/set.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  // TODO.
}

bool set::empty() {
  return true;  // TODO.
}

int set::size() {
  return 0;  // TODO.
}

Node* set::begin() {
  return NULL;  // TODO.
}

Node* set::end() {
  return NULL;  // TODO.
}

Node* set::next(Node* x) {
  return NULL;  // TODO.
}

Node* set::prev(Node* x) {
  return NULL;  // TODO.
}

SType set::operator[](Node* x) {
  return SType();  // TODO.
}

Node* set::find(SType k) {
  return NULL;  // TODO.
}

void set::insert(SType k) {
  // TODO.
}

void set::erase(SType k) {
  // TODO.
}

void set::clear() {
  // TODO.
}

void set::operator=(set& s) {
  // TODO.
}

set::~set() {
  // TODO.
}
