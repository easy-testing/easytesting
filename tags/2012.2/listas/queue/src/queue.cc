// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "queue/src/queue.h"

// Implementa um nó da lista encadeada.
struct Node {
  QType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

queue::queue() {
  // TODO.
}

bool queue::empty() {
  return false;  // TODO.
}

int queue::size() {
  return 0;  // TODO.
}

QType queue::front() {
  return end_->key;  // TODO.
}

QType queue::back() {
  return end_->key;  // TODO.
}

void queue::push(QType k) {
  // TODO.
}

void queue::pop() {
  // TODO.
}

void queue::operator=(queue& q) {
  // TODO.
}

queue::~queue() {
  // TODO.
}
