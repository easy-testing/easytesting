// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "hash_set/src/hash_function.h"
#include "hash_set/src/set.h"
#include "list/src/list.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  size_ = 0;
}

set::set(set& s) {
  for (int i = 0; i < capacity_; i++) {
    table_[i] = s.table_[i];
  }
  size_ = s.size_;
}

// Retorna o primeiro elemento da primeira lista não vazia.
Node* set::begin() {
  for (int i = 0; i < capacity_; i++) {
    if (!table_[i].empty()) {
      return table_[i].begin();
    }
  }
  return end();
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela da última lista da tabela.
Node* set::end() {
  return table_[capacity_ - 1].end();
}

// Se x não é o último elemento da lista que o contém, retorna o elemento
// seguinte a x nesta lista. Caso contrário, retorna o primeiro elemento da
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

Node* set::prev(Node* x) {
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

SType set::operator[](Node* x) {
  return x->key;
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
  return size_;
}

Node* set::find(SType k) {
  // Procura pelo elemento k na lista onde k pode estar.
  int j = hash(k, capacity_);
  Node* i;
  for (i = table_[j].begin(); i != table_[j].end(); i = table_[j].next(i)) {
    if (i->key == k) {
       return i;
    }
  }
  return end();
}

void set::insert(SType k) {
  Node* x = find(k);
  if (x == end()) {
    int j = hash(k, capacity_);
    table_[j].insert(table_[j].begin(), k);
    size_++;
  }
}

void set::erase(SType k) {
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

set::~set() {
}
