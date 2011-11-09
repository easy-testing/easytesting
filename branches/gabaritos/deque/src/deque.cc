// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "deque/src/deque.h"

#include "deque/src/node.h"

deque::deque() {
  size_ = 0;
  end_ = new node();
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

type deque::front() {
  return end_->next->key;
}

type deque::back() {
  return end_->prev->key;
}

void deque::push_front(type k) {
  node* i = end_->next;  // Ponteiro para o primeiro elemento na fila.
  node* k_node = new node({k, i->prev, i});
  i->prev->next = k_node;
  i->prev = k_node;
  size_++;
}

void deque::pop_front() {
  node* first = end_->next;
  first->prev->next = first->next;
  first->next->prev = first->prev;
  size_--;
}

void deque::push_back(type k) {
  node* k_node = new node({k, end_->prev, end_});
  end_->prev->next = k_node;
  end_->prev = k_node;
  size_++;
}

void deque::pop_back() {
  node* last = end_->prev;
  last->prev->next = last->next;
  last->next->prev = last->prev;
  size_--;
}

void deque::clear() {
  while (!empty()) {
    pop_back();
  }
}
