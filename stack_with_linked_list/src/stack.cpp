// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/stack.h"

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

stack::stack() {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
}

bool stack::empty() const {
  return size_ == 0;
}

int stack::size() const {
  return size_;
}

Node* stack::end() const {
  return end_;
}

Node* stack::begin() const {
  return end_->next;
}

SType stack::top() const {
  return end_->next->key;
}

void stack::push(SType k) {
  // Ponteiro para o primeiro elemento na pilha.
  Node* first = end_->next;
  // Cria um novo nó e define o valor dos seus campos.
  Node* node = new Node;
  node->key = k;
  node->prev = first->prev;
  node->next = first;
  // Ajusta o valor dos ponteiros dos nós adjacentes ao novo nó.
  first->prev->next = node;
  first->prev = node;
  size_++;
}

void stack::pop() {
  Node* first = end_->next;  // Ponteiro para o primeiro elemento na pilha.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  delete first;
  size_--;
}

void stack::operator=(const stack& p) {
  // Apaga todos os elementos na pilha corrente.
  while (!empty()) {
    pop();
  }
  // Insere os elementos de p de trás para frente na pilha corrente.
  for (Node* i = p.end_->prev; i != p.end_; i = i->prev) {
    push(i->key);
  }
}

stack::~stack() {
  while (!empty()) {
    pop();  // A função pop() libera a memórima de cada nó removido da pilha.
  }
  delete end_;
}
