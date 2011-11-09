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

node* set::begin() {
  if (empty()) {
    return list_.end();
  } else {
    return list_.begin();
  }
}

node* set::end() {
  return list_.end();
}

node* set::next(node* x) {
  return list_.next(x);
}

type set::value(node* x) {
  return list_.value(x);
}

bool set::empty() {
  return list_.empty();
}

int set::size() {
  return list_.size();
}

node* set::find(type k) {
  for (node* i = list_.begin(); i != list_.end(); i = list_.next(i)) {
    if (list_.value(i) == k) {
      return i;
    }
  }
  return list_.end();
}

node* set::insert(type k) {
  for (node* i = list_.begin(); i != list_.end(); i = list_.next(i)) {
    if (list_.value(i) == k) {
      return i;
    } else if (list_.value(i) > k) {
      return list_.insert(i, k);
    }
  }
  return list_.insert(list_.end(), k);  // k é o maior elemento do conjunto.
}

void set::erase(type k) {
  node* aux = find(k);
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
