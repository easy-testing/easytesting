// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "linear_set/src/linear_set.h"

#include "linear_set/src/list.h"
#include "linear_set/src/node.h"

linear_set::linear_set() {
}

linear_set::linear_set(linear_set& s) {
  list_.clear();
  list_.merge(s.list_);
}

bool linear_set::empty() {
  return list_.empty();
}

int linear_set::size() {
  return list_.size();
}

type linear_set::min() {
  type m = list_.front();
  for (node* i = list_.begin(); i != list_.end(); i = i->next) {
    if (i->key < m) {
      m = i->key;
    }
  }
  return m;
}

bool linear_set::find(type x) {
  for (node* i = list_.begin(); i != list_.end(); i = i->next) {
    if (i->key == x) {
      return true;
    }
  }
  return false;  // i == list_.end().
}

bool linear_set::insert(type x) {
  if (find(x)) {
    return false;
  } else {
    list_.push_back(x);
    return true;
  }
}

bool linear_set::erase(type x) {
  for (node* i = list_.begin(); i != list_.end(); i = i->next) {
    if (i->key == x) {
      list_.erase(i);
      return true;
    }
  }
  return false;
}

void linear_set::clear() {
  list_.clear();
}

void linear_set::operator=(linear_set& c) {
  list_.clear();
  list_.merge(c.list_);
}
