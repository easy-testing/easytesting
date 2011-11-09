// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "queue/src/node.h"
#include "queue/src/queue.h"

queue::queue() {
  size_ = 0;
  end_ = new node();
  end_->next = end_;
  end_->prev = end_;
}

queue::~queue() {
  // Primeiramente, remove todos os elementos da fila.
  while (!empty()) {
    pop();  // A função pop() libera a memórima de cada nó removido da fila;
  }
  // Em seguida, libera a memória alocada ao sentinela.
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

void queue::push(type k) {
  node* k_node = new node({k, end_->prev, end_});
  end_->prev->next = k_node;
  end_->prev = k_node;
  size_++;
}

void queue::pop() {
  node* first = end_->next;  // Ponteiro para o primeiro elemento na fila.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  delete first;
  size_--;
}
