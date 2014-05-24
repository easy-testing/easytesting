// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "unordered_multiset/src/unordered_multiset.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  int count;  // Número de ocorrências da chave.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

int hash(int key, int m) {
  return key % m;
}

int hash(std::string key, int m) {
  long int hashVal = 0;
  for (int i = 0; i < key.length(); i++) {
    hashVal = 37 * hashVal + key[i];
  }
  return hashVal % m;
}

unordered_multiset::unordered_multiset() {
  // TODO.
}

// Retorna o primeiro elemento do primeiro subconjunto não vazio.
Node* unordered_multiset::begin() {
  return end();  // TODO.
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela do último subconjunto da tabela.
Node* unordered_multiset::end() {
  return NULL;  // TODO.
}

// Se x não é o último elemento do subconjunto que o contém, retorna o elemento
// seguinte a x neste subconjunto. Caso contrário,
// retorna o primeiro elemento do próximo subconjunto não vazio da tabela.
Node* unordered_multiset::next(Node* x) {
  return end();  // TODO.
}

// Se x não é o primeiro elemento do subconjunto que o contém,
// retorna o elemento anterior a x neste subconjunto. Caso contrário,
// retorna o último elemento do primeiro subconjunto não vazio anterior
// ao subconjunto de x.
Node* unordered_multiset::prev(Node* x) {
  return end();  // TODO.
}

int unordered_multiset::count(SType k) {
  return 0;  // TODO.
}

SType unordered_multiset::key(Node* x) {
  return x->key;
}

bool unordered_multiset::empty() {
  return false;
}

int unordered_multiset::size() {
  return 0;
}

Node* unordered_multiset::find(SType k) {
  return end();  // TODO.
}

void unordered_multiset::insert(SType k) {
  // TODO.
}

void unordered_multiset::erase(SType k) {
  // TODO.
}

void unordered_multiset::clear() {
  // TODO.
}

void unordered_multiset::operator=(unordered_multiset& s) {
  // TODO.
}

unordered_multiset::~unordered_multiset() {
  // TODO.
}

void unordered_multiset::rehash(int m) {
  // TODO.
}
