// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list_set/src/set.h"

set::set() {
  // Nada a fazer, já que o construtor list::list() já inicializa a
  // lista encadeada.
}

bool set::empty() {
  return list_.empty();
}

int set::size() {
  return list_.size();
}

Node* set::begin() {
  return list_.begin();
}

Node* set::end() {
  return list_.end();
}

Node* set::next(Node* x) {
  return list_.next(x);
}

Node* set::prev(Node* x) {
  return list_.prev(x);
}

SType set::operator[](Node* x) {
  return list_[x];
}


Node* set::find(SType k) {
  for (Node* i = list_.begin();
       i != list_.end() && list_[i] <= k;
       i = list_.next(i)) {
    if (list_[i] == k) {
      return i;
    }
  }
  return list_.end();
}

void set::insert(SType k) {
  Node* i = list_.begin();
  while (i != list_.end() && list_[i] < k) {
    i = list_.next(i);
  }
  if (i == list_.end() || list_[i] != k) {
    list_.insert(i, k);
  }
}

void set::erase(SType k) {
  Node* x = find(k);
  if (x != list_.end()) {
    list_.erase(x);
  }
}

void set::clear() {
  list_.clear();
}

void set::operator=(set& s) {
  list_ = s.list_;
}

set::~set() {
  // Nada a fazer, já que o destrutor list::~list() já desaloca a memória da
  // lista encadeada.
}
