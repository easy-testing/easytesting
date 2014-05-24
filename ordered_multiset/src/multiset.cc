// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_multiset/src/multiset.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  int count;  // Número de ocorrências da chave.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

multiset::multiset() {
  // TODO.
}

Node* multiset::begin() {
  return NULL;  // TODO.
}

Node* multiset::end() {
  return NULL;  // TODO.
}

Node* multiset::next(Node* x) {
  return NULL;  // TODO.
}

Node* multiset::prev(Node* x) {
  return NULL;  // TODO.
}

int multiset::count(SType k) {
  return 0;  // TODO.
}

SType multiset::key(Node* x) {
  return x->key;  //TODO.
}

bool multiset::empty() {
  return false;  // TODO.
}

int multiset::size() {
  return 0;  // TODO.
}

Node* multiset::find(SType k) {
  return NULL;  // TODO.
}

void multiset::insert(SType k) {
  // TODO.
}

void multiset::erase(SType k) {
  // TODO.
}

void multiset::clear() {
  // TODO.
}

void multiset::operator=(multiset& s) {
  // TODO.
}

multiset::~multiset() {
  // TODO.
}
