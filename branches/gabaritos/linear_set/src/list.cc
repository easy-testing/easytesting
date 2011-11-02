// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "linear_set/src/list.h"

list::list() {
  size_ = 0;
  end_ = NewSentinel();
}

list::list(list& l) {
  size_ = 0;
  end_ = NewSentinel();
  merge(l);
}

list::~list() {
  clear();  // Primeiramente, remove todos os elementos da lista.
  delete end_;  // Em seguida, libera a memória alocada ao sentinela.
}

node* list::begin() {
  return end_->next;
}

node* list::end() {
  return end_;
}

bool list::empty() {
  return size_ == 0;
}

type list::front() {
  return end_->next->key;
}

type list::back() {
  return end_->prev->key;
}

int list::size() {
  return size_;
}

void list::push_front(type x) {
  insert(begin(), x);
}

void list::pop_front() {
  erase(begin());
}

void list::push_back(type x) {
  insert(end(), x);
}

void list::pop_back() {
  erase(end_->prev);
}

node* list::insert(node* p, type x) {
  node* aux = NewNode(x, p->prev, p);
  p->prev->next = aux;
  p->prev = aux;
  size_++;
  return p;
}

void list::erase(node* p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;
  size_--;
}

void list::clear() {
  while (!empty()) {
    pop_back();
  }
}

void list::merge(list& l) {
  for (node* i = l.begin(); i != l.end(); i = i->next) {
    push_back(i->key);
  }
}

void list::operator=(list& l) {
  clear();
  merge(l);
}
