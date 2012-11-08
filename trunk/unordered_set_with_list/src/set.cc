// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <unordered_set>

#include "hash_set/src/set.h"
#include "list/src/list.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  size_ = 0;  // Inicialmente, o conjunto não tem elementos.
  capacity_ = 1024; // Inicia com uma tabela com 2^10 linhas.
  table_ = new list[capacity_];
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
  int j = hash(x->key);
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

// Se x não é o primeiro elemento da lista que o contém, retorna o elemento
// anterior a x nesta lista. Caso contrário, retorna o último elemento da
// primeira lista não vazia anterior a lista de x .
Node* set::prev(Node* x) {
  int j = hash(x->key);
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

Node* set::find(SType k) {
  // Procura pelo elemento k na lista onde k pode estar.
  int j = hash(k);
  Node* i;
  for (i = table_[j].begin(); i != table_[j].end(); i = table_[j].next(i)) {
    if (i->key == k) {
       return i;
    }
  }
  return end();
}

void set::insert(SType k) {
  if (size_ == capacity_) {
    rehash(capacity_ * 2);
  }
  Node* x = find(k);
  if (x == end()) {
    int j = hash(k);
    table_[j].insert(table_[j].begin(), k);
    size_++;
  }
}

void set::erase(SType k) {
  Node* x = find(k);
  if (x != end()) {
    int j = hash(k);
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
  delete [] table_;
}

int set::hash(SType k) {
  std::unordered_set<SType>::hasher fh;
  return fh(k) % capacity_;
}

void set::rehash(int m) {
  // Armazena a tabela atual.
  list* old_table = table_;
  int old_capacity = capacity_;
  // Cria uma nova tabela vazia com 'm' linhas.
  table_ = new list[m];
  capacity_ = m;
  // Insere todos os elementos na nova tabela.
  for (int i = 0; i < old_capacity; i++) {
    for (Node* j = old_table[i].begin();
         j != old_table[i].end();
         j = old_table[i].next(j)) {
      insert(old_table[i][j]);
    }
  }
  delete [] old_table;
}
