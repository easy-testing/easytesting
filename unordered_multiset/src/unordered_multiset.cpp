// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/unordered_multiset.h"

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
  long int hashVal = 0;  // NOLINT
  for (int i = 0; i < key.length(); i++) {
    hashVal = 37 * hashVal + key[i];
  }
  return hashVal % m;
}

unordered_multiset::unordered_multiset() {
  size_ = 0;  // Inicialmente, o multiconjunto não tem elementos.
  capacity_ = 1024;  // Inicia com uma tabela com 2^10 linhas.
  table_ = new multiset[capacity_];
}

// Retorna o primeiro elemento do primeiro subconjunto não vazio.
Node* unordered_multiset::begin() const {
  for (int i = 0; i < capacity_; i++) {
    if (!table_[i].empty()) {
      return table_[i].begin();
    }
  }
  return end();
}

// Retorna o "marcador de fim" do conjunto, ou seja,
// O sentinela do último subconjunto da tabela.
Node* unordered_multiset::end() const {
  return table_[capacity_ - 1].end();
}

// Se x não é o último elemento do subconjunto que o contém, retorna o elemento
// seguinte a x neste subconjunto. Caso contrário,
// retorna o primeiro elemento do próximo subconjunto não vazio da tabela.
Node* unordered_multiset::next(Node* x) const {
  int j = hash(x->key, capacity_);
  if (x->right != table_[j].end()) {
    return x->right;
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
Node* unordered_multiset::prev(Node* x) const {
  int j;
  if (x == end()) {
    j = capacity_;
  } else {
    j = hash(x->key, capacity_);
    if (x != table_[j].begin()) {
      return x->left;
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

int unordered_multiset::count(SType k) const {
  Node* x = find(k);
  if (x == end()) {
    return 0;
  } else {
    return x->count;
  }
}

SType unordered_multiset::key(Node* x) const {
  return x->key;
}

bool unordered_multiset::empty() const {
  return size_ == 0;
}

int unordered_multiset::size() const {
  return size_;
}

Node* unordered_multiset::find(SType k) const {
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    return x;
  } else {
    return end();
  }
}

void unordered_multiset::insert(SType k) {
  if (size_ == capacity_) {
    rehash(capacity_ * 2);
  }
  int j = hash(k, capacity_);
  table_[j].insert(k);
  size_++;
}

void unordered_multiset::erase(SType k) {
  int j = hash(k, capacity_);
  Node* x = table_[j].find(k);
  if (x != table_[j].end()) {
    table_[j].erase(k);
    size_--;
  }
}

void unordered_multiset::clear() {
  for (int i = 0; i < capacity_; i++) {
    table_[i].clear();
  }
  size_ = 0;
}

void unordered_multiset::operator=(const unordered_multiset& s) {
  clear();
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    for (int j = 0; j < i->count; j++) {
      insert(i->key);
    }
  }
}

unordered_multiset::~unordered_multiset() {
  delete [] table_;
}

void unordered_multiset::rehash(int m) {
  // Armazena temporariamente a tabela atual.
  multiset* old_table = table_;
  int old_capacity = capacity_;
  // Cria uma nova tabela vazia com 'm' linhas.
  table_ = new multiset[m];
  capacity_ = m;
  // Insere todos os elementos na nova tabela.
  for (int i = 0; i < old_capacity; i++) {
    for (Node* j = old_table[i].begin();
         j != old_table[i].end();
         j = old_table[i].next(j)) {
      for (int k = 0; k < j->count; k++) {
        insert(j->key);
      }
    }
  }
  delete [] old_table;
}
