// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "unordered_multiset_with_list/src/multiset.h"
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
  for (int i = 0; i < kCapacity_; i++) {
    table_[i] = s.table_[i];
  }
  size_ = s.size_;
}

// Retorna o primeiro elemento da primeira lista não vazia.
Node* set::begin() {
  for (int i = 0; i < kCapacity_; i++) {
    if (!table_[i].empty()) {
      return table_[i].begin();
    }
  }
  return end();
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela da última lista da tabela.
Node* set::end() {
  return table_[kCapacity_ - 1].end();
}

// Se x não é o último elemento da lista que o contém, retorna o elemento
// seguinte a x nesta lista. Caso contrário, retorna o primeiro elemento da
// próxima lista não vazia da tabela.
Node* set::next(Node* x) {
  int j = hash(x->key, kCapacity_);
  if (x->next != table_[j].end()) {
    return x->next;
  } else {
    for (int i = j + 1; i < kCapacity_; i++) {
      if (!table_[i].empty()) {
        return table_[i].begin();
      }
    }
    return end();
  }
}

// Se x não é o primeiro elemento da lista que o contém, retorna o elemento
// anterior a x nesta lista. Caso contrário, retorna o último elemento da
// primeira lista não vazia anterior a lista de x .
Node* set::prev(Node* x) {
  int j = hash(x->key, kCapacity_);
  if (x != table_[j].begin()) {
    return x->prev;
  } else {
    for (int i = j - 1; i >= 0; i--) {
      if (!table_[i].empty()) {
        return table_[i].end()->prev;
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

bool set::find(SType k) {
  return count(k) > 0;
}

int set::count(SType k) {
  int j = hash(k, kCapacity_);
  int d = 0; // Número de ocorrências de k no conjunto.
  Node* i;
  for (i = table_[j].begin(); i != table_[j].end(); i = table_[j].next(i)) {
    if (i->key == k) {
       d++;
    }
  }
  return d;
}

void set::insert(SType k) {
  int j = hash(k, kCapacity_);
  table_[j].insert(table_[j].end(), k);
  size_++;
}

void set::erase(SType k) {
  int j = hash(k, kCapacity_);
  Node* i;
  for (i = table_[j].begin(); i != table_[j].end(); i = table_[j].next(i)) {
    if (i->key == k) {
      table_[j].erase(i);
      size_--;
      return;
    }
  }
}

void set::clear() {
  for (int i = 0; i < kCapacity_; i++) {
    table_[i].clear();
  }
  size_ = 0;
}

void set::operator=(set& s) {
  for (int i = 0; i < kCapacity_; i++) {
    table_[i] = s.table_[i];
  }
  size_ = s.size_;
}

set::~set() {
}
