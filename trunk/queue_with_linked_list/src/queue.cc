// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/queue.h"

// Implementa um nó da lista encadeada.
struct Node {
  QType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

queue::queue() {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
}

bool queue::empty() const {
  return size_ == 0;
}

int queue::size() const {
  return size_;
}

QType queue::front() const {
  return end_->next->key;
}

QType queue::back() const {
  return end_->prev->key;
}

void queue::push(QType k) {
  // Cria um novo nó e define o valor dos seus campos.
  Node* node = new Node;
  node->key = k;
  node->prev = end_->prev;
  node->next = end_;
  // Ajusta o valor dos ponteiros dos nós adjacentes ao novo nó.
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

void queue::operator=(const queue& q) {
  // Apaga todos os elementos na fila corrente.
  while (!empty()) {
    pop();
  }
  // Insere os elementos de q na fila corrente.
  for (Node* i = q.end_->next; i != q.end_; i = i->next) {
    push(i->key);
  }
}

queue::~queue() {
  // Primeiramente, remove todos os elementos da fila.
  while (!empty()) {
    pop();  // A função pop() libera a memórima de cada nó removido da fila;
  }
  // Em seguida, libera a memória alocada ao sentinela.
  delete end_;
}
