// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <unordered_set>

#include "unordered_set_with_set/src/unordered_set.h"
#include "ordered_set_with_linked_list/src/set.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

unordered_set::unordered_set() {
  // TODO.
}

// Retorna o primeiro elemento do primeiro subconjunto não vazio.
Node* unordered_set::begin() {
  return NULL;  // TODO.
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela do último subconjunto da tabela.
Node* unordered_set::end() {
  return NULL;  // TODO.
}

// Se x não é o último elemento do subconjunto que o contém, retorna o elemento
// seguinte a x neste subconjunto. Caso contrário,
// retorna o primeiro elemento do próximo subconjunto não vazio da tabela.
Node* unordered_set::next(Node* x) {
  return NULL;  // TODO.
}

Node* unordered_set::prev(Node* x) {
  return NULL;  // TODO.
}

SType unordered_set::operator[](Node* x) {
  return SType();  // TODO.
}

bool unordered_set::empty() {
  return 0;  // TODO.
}

int unordered_set::size() {
  return size_;
}

Node* unordered_set::find(SType k) {
  return NULL;  // TODO.
}

void unordered_set::insert(SType k) {
  // TODO.
}

void unordered_set::erase(SType k) {
  // TODO.
}

void unordered_set::clear() {
  // TODO.
}

void unordered_set::operator=(unordered_set& s) {
  // TODO.
}

unordered_set::~unordered_set() {
  // TODO.
}

int unordered_set::hash(SType k) {
  std::unordered_set<SType>::hasher fh;
  return fh(k) % capacity_;
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
      insert(old_table[i][j]);
    }
  }
  delete [] old_table;
}
