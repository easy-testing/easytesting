// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "queue/src/node.h"
#include "queue/src/queue.h"

queue::queue() {
  size_ = 0;
  end_ = NewSentinel();
}

queue::~queue() {
  // Primeiramente, remove todos os elementos da fila.
  while (!empty()) {
    pop();  // A fun��o pop() libera a mem�rima de cada n� removido da fila;
  }
  // Em seguida, libera a mem�ria alocada ao sentinela.
  delete end_;
}

bool queue::empty() {
  return size_ == 0;
}

int queue::size() {
  return size_;
}

type queue::front() {
  return end_->next->key;
}

type queue::back() {
  return end_->prev->key;
}

void queue::push(type x) {
  end_->prev = end_->prev->next = NewNode(x, end_->prev, end_);
  size_++;
}

void queue::pop() {
  node* first = end_->next;  // Ponteiro para o primeiro elemento na fila.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  delete first;
  size_--;
}
