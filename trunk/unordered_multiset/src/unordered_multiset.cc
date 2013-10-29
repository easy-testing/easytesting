// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "unordered_multiset/src/unordered_multiset.h"

#include "ordered_set_with_linked_list/src/set.h"

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

int hash(SType k, int m) {
  return m - 1;
}

unordered_set::unordered_set() {
  size_ = 0;  // Inicialmente, o conjunto não tem elementos.
  capacity_ = 1024;  // Inicia com uma tabela com 2^10 linhas.
  table_ = new set[capacity_];
}

// Retorna o primeiro elemento do primeiro subconjunto não vazio.
Node* unordered_set::begin() {
  for (int i = 0; i < capacity_; i++) {
    if (!table_[i].empty()) {
      return table_[i].begin();
    }
  }
  return end();
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela do último subconjunto da tabela.
Node* unordered_set::end() {
  return table_[capacity_ - 1].end();
}

// Se x não é o último elemento do subconjunto que o contém, retorna o elemento
// seguinte a x neste subconjunto. Caso contrário,
// retorna o primeiro elemento do próximo subconjunto não vazio da tabela.
Node* unordered_set::next(Node* x) {
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

// Se x não é o primeiro elemento do subconjunto que o contém,
// retorna o elemento anterior a x neste subconjunto. Caso contrário,
// retorna o último elemento do primeiro subconjunto não vazio anterior
// ao subconjunto de x .
Node* unordered_set::prev(Node* x) {
  int j = hash(x->key, capacity_);
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

SType unordered_set::key(Node* x) {
  return x->key;
}

bool unordered_set::empty() {
  return size_ == 0;
}

int unordered_set::size() {
  return size_;
}

Node* unordered_set::find(SType k) {
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    return x;
  } else {
    return end();
  }
}

void unordered_set::insert(SType k) {
  if (size_ == capacity_) {
    rehash(capacity_ * 2);
  }
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x == table_[j].end()) {
    table_[j].insert(k);
    size_++;
  }
}

void unordered_set::erase(SType k) {
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    table_[j].erase(k);
    size_--;
  }
}

void unordered_set::clear() {
  for (int i = 0; i < capacity_; i++) {
    table_[i].clear();
  }
  size_ = 0;
}

void unordered_set::operator=(unordered_set& s) {
  for (int i = 0; i < capacity_; i++) {
    table_[i] = s.table_[i];
  }
  size_ = s.size_;
}

unordered_set::~unordered_set() {
  delete [] table_;
}

void unordered_set::rehash(int m) {
  // Armazena a tabela atual.
  set* old_table = table_;
  int old_capacity = capacity_;
  // Cria uma nova tabela vazia com 'm' linhas.
  table_ = new set[m];
  capacity_ = m;
  // Insere todos os elementos na nova tabela.
  for (int i = 0; i < old_capacity; i++) {
    for (Node* j = old_table[i].begin();
         j != old_table[i].end();
         j = old_table[i].next(j)) {
      insert(old_table[i].key(j));
    }
  }
  delete [] old_table;
}
