// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "deque/src/deque.h"

deque::deque() {
  size_ = 0;
  end_ = NewSentinel();
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

void deque::push_front(type x) {
  node* first = end_->next;
  node* aux = NewNode(x, first->prev, first);
  first->prev->next = aux;
  first->prev = aux;
  size_++;
}

void deque::pop_front() {
  node* first = end_->next;
  first->prev->next = first->next;
  first->next->prev = first->prev;
  size_--;
}

void deque::push_back(type x) {
  node* aux = NewNode(x, end_->prev, end_);
  end_->prev->next = aux;
  end_->prev = aux;
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
