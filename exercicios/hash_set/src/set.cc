// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "hash_set/src/set.h"
#include "hash_set/src/list.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  // TODO.
}

set::set(set& s) {
  // TODO.
}

// Retorna o primeiro elemento da primeira lista não vazia.
Node* set::begin() {
  return NULL;  // TODO.
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela da última lista da tabela.
Node* set::end() {
  return NULL;  // TODO.
}

// Se x não é o último elemento da lista que o contém, retorna o elemento
// seguinte a x nesta lista. Caso contrário, retorna o primeiro elemento da
// próxima lista não vazia da tabela.
Node* set::next(Node* x) {
  return NULL;  // TODO.
}

// Se x não é o primeiro elemento da lista que o contém, retorna o elemento
// anterior a x nesta lista. Caso contrário, retorna o último elemento da
// primeira lista não vazia anterior a lista de x .
Node* set::prev(Node* x) {
  return NULL;  // TODO.
}

SType set::operator[](Node* x) {
  return x->key;  // TODO.
}

bool set::empty() {
  return false;  // TODO.
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
}
