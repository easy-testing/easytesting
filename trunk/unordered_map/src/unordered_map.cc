// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "unordered_map/src/unordered_map.h"

#include "ordered_map/src/map.h"

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Chave do nó.
  VType value; // Valor do nó
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

int hash(int key, int m) {
  return key % m;
}

int hash(std::string key, int m) {
  int hashVal = 0;
  for (int i = 0; i < key.length(); i++) {
    hashVal = 37 * hashVal + key[i];
  }
  return hashVal % m;
 }

unordered_map::unordered_map() {
  size_ = 0;  // Inicialmente, o conjunto não tem elementos.
  capacity_ = 1024;  // Inicia com uma tabela com 2^10 linhas.
  table_ = new map[capacity_];
}

// Retorna o primeiro elemento do primeiro subconjunto não vazio.
Node* unordered_map::begin() {
  for (int i = 0; i < capacity_; i++) {
    if (!table_[i].empty()) {
      return table_[i].begin();
    }
  }
  return end();
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela do último subconjunto da tabela.
Node* unordered_map::end() {
  return table_[capacity_ - 1].end();
}

// Se x não é o último elemento do subconjunto que o contém, retorna o elemento
// seguinte a x neste subconjunto. Caso contrário,
// retorna o primeiro elemento do próximo subconjunto não vazio da tabela.
Node* unordered_map::next(Node* x) {
  int j = hash(x->key, capacity_);
  if (x->next != table_[j].end()) {
    return x->next;
  } else {
    // Retorna o primeiro elemento da primeira linha da tabela não vazia cujo
    // índice é maior que j.
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
// ao subconjunto de x.
Node* unordered_map::prev(Node* x) {
  int j;
  if (x == end()) {
    j = capacity_;
    printf("%d\n", j);
  } else {
    j = hash(x->key, capacity_);
    if (x != table_[j].begin()) {
      return x->prev;
    }
  }
  // Retorna o último elemento da primeira linha da tabela não vazia cujo
  // índice é menor que j.
  for (int i = j - 1; i >= 0; i--) {
    if (!table_[i].empty()) {
      return table_[i].prev(table_[i].end());
    }
  }
}

VType& unordered_map::operator[](SType x) {
  return find(x)->value;
}

SType unordered_map::key(Node* x) {
  return x->key;
}

VType unordered_map::value(Node* x) {
  return x->value;
}

bool unordered_map::empty() {
  return size_ == 0;
}

int unordered_map::size() {
  return size_;
}

Node* unordered_map::find(SType k) {
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    return x;
  } else {
    return end();
  }
}

void unordered_map::insert(SType k, VType v) {
  if (size_ == capacity_) {
    rehash(capacity_ * 2);
  }
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    x->value = v;
  } else {
    table_[j].insert(k,v);
    size_++;
  }
}

void unordered_map::erase(SType k) {
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    table_[j].erase(k);
    size_--;
  }
}

void unordered_map::clear() {
  for (int i = 0; i < capacity_; i++) {
    table_[i].clear();
  }
  size_ = 0;
}

void unordered_map::operator=(unordered_map& s) {
  clear();
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key, i->value);
  }
}

unordered_map::~unordered_map() {
  delete [] table_;
}

void unordered_map::rehash(int m) {
  // Armazena temporariamente a tabela atual.
  map* old_table = table_;
  int old_capacity = capacity_;
  // Cria uma nova tabela vazia com 'm' linhas.
  table_ = new map[m];
  capacity_ = m;
  // Insere todos os elementos na nova tabela.
  for (int i = 0; i < old_capacity; i++) {
    for (Node* j = old_table[i].begin();
         j != old_table[i].end();
         j = old_table[i].next(j)) {
      insert(j->key, j->value);
    }
  }
  delete [] old_table;
}
