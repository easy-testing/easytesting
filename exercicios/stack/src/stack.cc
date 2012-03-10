// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "stack/src/stack.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

stack::stack() {
  // TODO.
}

stack::~stack() {
  // TODO.
}

bool stack::empty() {
  return false;  // TODO.
}

int stack::size() {
  return 0;  // TODO.
}

LType stack::top() {
  return end_->key;  // TODO.
}

void stack::push(LType k) {
  // TODO.
}

void stack::pop() {
  // TODO.
}

void stack::operator=(stack& p) {
  // TODO.
}
