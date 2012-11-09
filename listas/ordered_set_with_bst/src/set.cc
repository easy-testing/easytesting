// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set_with_bst/src/set.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

set::set() {
  // TODO.
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

bool set::empty() {
  return 0;  // TODO.
}

int set::size() {
  return 0;  // TODO.
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
