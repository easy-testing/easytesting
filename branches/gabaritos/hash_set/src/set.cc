// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include<string>

#include "hash_set/src/hash_function.h"
#include "hash_set/src/set.h"
#include "list/src/list.h"
#include "list/src/node.h"

set::set() {
  table_ = new list[capacity_];
  size_ = 0;
}

set::set(set& s) {
  table_ = new list[capacity_];
  for (int i = 0; i < capacity_; i++) {
    table_[i] = s.table_[i];
  }
  size_ = s.size_;
}

set::~set() {
  delete [] table_;
}

// Retorna o primeiro elemento da primeira lista não fazia.
Node* set::begin() {
  for (int i = 0; i < capacity_; i++) {
    if (!table_[i].empty()) {
      return table_[i].begin();
    }
  }
  return end();
}

// Retorna o "marcador de fim" da última lista da tabela.
Node* set::end() {
  return table_[capacity_ - 1].end();
}

// Se x não é o último elemento da lista que o contém, retorna o elemento
// seguinte a x nesta lista. Caso contrãrio, retorna o primeiro elemento da
// próxima lista não vazia da tabela.
Node* set::next(Node* x) {
  int j = hash(x->key, capacity_);
  if (x->next != table_[j].end()) {
    return x->next;
  } else {
    for (int i = j + 1; i < capacity_; i++) {
      if (!table_[i].empty()) {
        return table_[i].begin();
      }
    }
    return end();
  }
}

Type set::value(Node* x) {
  return x->key;
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
  return size_;
}

Node* set::find(Type k) {
  // Procura pelo elemento k na lista onde k pode estar.
  int j = hash(k, capacity_);
  for (Node* i = table_[j].begin(); i != table_[j].end(); i = i->next) {
    if (i->key == k) {
       return i;
    }
  }
  return end();
}

Node* set::insert(Type k) {
  Node* x = find(k);
  if (x != end()) {
    return x;
  } else {
    size_++;
    int j = hash(k, capacity_);
    table_[j].push_front(k);
    return table_[j].begin();
  }
}

void set::erase(Type k) {
  Node* x = find(k);
  if (x != end()) {
    int j = hash(k, capacity_);
    table_[j].erase(x);
    size_--;
  }
}

void set::clear() {
  for (int i = 0; i < capacity_; i++) {
    table_[i].clear();
  }
  size_ = 0;
}

void set::operator=(set& s) {
  for (int i = 0; i < capacity_; i++) {
    table_[i] = s.table_[i];
  }
  size_ = s.size_;
}
