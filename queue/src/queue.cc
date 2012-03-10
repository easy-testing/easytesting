// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "queue/src/queue.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

queue::queue() {
  size_ = 0;
  end_ = new Node();
  end_->next = end_;
  end_->prev = end_;
}

queue::~queue() {
  // Primeiramente, remove todos os elementos da fila.
  while (!empty()) {
    pop();  // A função pop() libera a memórima de cada nó removido da fila;
  }
  // Em seguida, libera a memória alocada ao sentinela.
  delete end_;
}

bool queue::empty() {
  return size_ == 0;
}

int queue::size() {
  return size_;
}

LType queue::front() {
  return end_->next->key;
}

LType queue::back() {
  return end_->prev->key;
}

void queue::push(LType k) {
  Node* node = new Node({k, end_->prev, end_});
  end_->prev->next = node;
  end_->prev = node;
  size_++;
}

void queue::pop() {
  Node* first = end_->next;  // Ponteiro para o primeiro elemento na fila.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  delete first;
  size_--;
}

void queue::operator=(queue& q) {
  // Apaga todos os elementos na fila corrente.
  while (!empty()) {
    pop();
  }
  // Insere os elementos de q de trás para frente na pilha corrente.
  for (Node* i = q.end_->next; i != q.end_; i = i->next) {
    push(i->key);
  }
}
