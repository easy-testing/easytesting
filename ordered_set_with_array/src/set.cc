// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set_with_array/src/set.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

set::set() {
  size_ = 0;
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
  return size_;
}

bool set::belongs(SType k) {
  for (int i = 0; i < size_; i++){
    if (array_[i] == k) {
      return true;
    }
  }
  return false;
}

void set::insert(SType k) {
  if (!belongs(k)) {
    // Aumenta o tamanho do vetor antes de inserir k.
    resize(size_ + 1);
    // Insere k na no vetor de forma que o vetor continue ordenado.
    int i;
    for (i = size_ - 1; i > 0 && array_[i - 1] > k; i--) {
      array_[i] = array_[i - 1];
    }
    array_[i] = k;
  }
}

void set::erase(SType k) {
  if (belongs(k)) {
    // Copia todos os elementos maiores que k para a esquerda.
    for (int i = 0; i < size_ ; i++) {
      if (array_[i] > k) {
        array_[i - 1] = array_[i];
      }
    }
    // Diminui o tamanho do vetor em uma unidade.
    resize(size_ - 1);
  }
}

void set::clear() {
  resize(0);
}

void set::operator=(set& s) {
  resize(s.size_);
  for (int i = 0; i < size_; i++) {
    array_[i] = s.array_[i];
  }
}

set::~set() {
  resize(0);
}

void set::resize(int n) {
  SType* aux = new SType[n];
  for (int i = 0; i < size_ && i < n; i++) {
    aux[i] = array_[i];
  }
  if (size_ > 0) {
    delete [] array_;
  }
  array_ = aux;
  size_ = n;
}
