// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "deque/src/deque.h"

#include "deque/src/node.h"

deque::deque() {
  size_ = 0;
  end_ = new Node();
  end_->next = end_;
  end_->prev = end_;
}

deque::~deque() {
  clear();  // Primeiramente, remove todos os elementos da dequea.
  delete end_;  // Em seguida, libera a memória alocada ao sentinela.
}

bool deque::empty() {
  return size_ == 0;
}

int deque::size() {
  return size_;
}

Type deque::front() {
  return end_->next->key;
}

Type deque::back() {
  return end_->prev->key;
}

void deque::push_front(Type k) {
  Node* i = end_->next;  // Ponteiro para o primeiro elemento na fila.
  Node* k_node = new Node({k, i->prev, i});
  i->prev->next = k_node;
  i->prev = k_node;
  size_++;
}

void deque::pop_front() {
  Node* first = end_->next;
  first->prev->next = first->next;
  first->next->prev = first->prev;
  size_--;
}

void deque::push_back(Type k) {
  Node* k_node = new Node({k, end_->prev, end_});
  end_->prev->next = k_node;
  end_->prev = k_node;
  size_++;
}

void deque::pop_back() {
  Node* last = end_->prev;
  last->prev->next = last->next;
  last->next->prev = last->prev;
  size_--;
}

void deque::clear() {
  while (!empty()) {
    pop_back();
  }
}
