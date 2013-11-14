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
  //TODO.
}

Node* unordered_map::begin() {
  return end();  //TODO.
}

Node* unordered_map::end() {
  return NULL;  //TODO.
}

Node* unordered_map::next(Node* x) {
  return end();  //TODO.
}

Node* unordered_map::prev(Node* x) {
  return end();  //TODO.
}

VType& unordered_map::operator[](SType x) {
  return find(x)->value;
}

SType unordered_map::key(Node* x) {
  return SType();  //TODO.
}

VType unordered_map::value(Node* x) {
  return VType();  //TODO.
}

bool unordered_map::empty() {
  return false;  //TODO.
}

int unordered_map::size() {
  return 0;  //TODO.
}

Node* unordered_map::find(SType k) {
  return end();  //TODO.
}

void unordered_map::insert(SType k, VType v) {
  //TODO.
}

void unordered_map::erase(SType k) {
  //TODO.
}

void unordered_map::clear() {
  //TODO.
}

void unordered_map::operator=(unordered_map& s) {
  //TODO.
}

unordered_map::~unordered_map() {
  //TODO.
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
