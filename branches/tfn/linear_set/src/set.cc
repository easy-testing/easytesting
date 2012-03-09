// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "linear_set/src/set.h"

#include "list/src/list.h"

set::set() {
}

set::set(set& s) {
  list_.clear();
  list_.merge(s.list_);
}

set::~set() {
  // O destrutor de list_ desaloca toda a memória alocada para ela.
}

Node* set::begin() {
  if (empty()) {
    return list_.end();
  } else {
    return list_.begin();
  }
}

Node* set::end() {
  return list_.end();
}

Node* set::next(Node* x) {
  return list_.next(x);
}

Type set::value(Node* x) {
  return list_.value(x);
}

bool set::empty() {
  return list_.empty();
}

int set::size() {
  return list_.size();
}

Node* set::find(Type k) {
  for (Node* i = list_.begin(); i != list_.end(); i = list_.next(i)) {
    if (list_.value(i) == k) {
      return i;
    }
  }
  return list_.end();
}

Node* set::insert(Type k) {
  for (Node* i = list_.begin(); i != list_.end(); i = list_.next(i)) {
    if (list_.value(i) == k) {
      return i;
    } else if (list_.value(i) > k) {
      return list_.insert(i, k);
    }
  }
  return list_.insert(list_.end(), k);  // k é o maior elemento do conjunto.
}

void set::erase(Type k) {
  Node* aux = find(k);
  if (aux != end()) {
    list_.erase(aux);
  }
}

void set::clear() {
  list_.clear();
}

void set::operator=(set& c) {
  list_.clear();
  list_.merge(c.list_);
}
