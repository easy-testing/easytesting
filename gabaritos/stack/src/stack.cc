// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "stack/src/stack.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

stack::stack() {
  size_ = 0;
  end_ = new Node();
  end_->next = end_;
  end_->prev = end_;
}

stack::~stack() {
  while (!empty()) {
    pop();  // A função pop() libera a memórima de cada nó removido da pilha.
  }
  delete end_;
}

bool stack::empty() {
  return size_ == 0;
}

int stack::size() {
  return size_;
}

LType stack::top() {
  return end_->next->key;
}

void stack::push(LType k) {
  Node* i = end_->next;  // Ponteiro para o primeiro elemento na pilha.
  Node* node = new Node({k, i->prev, i});
  i->prev->next = node;
  i->prev = node;
  size_++;
}

void stack::pop() {
  Node* first = end_->next;  // Ponteiro para o primeiro elemento na pilha.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  delete first;
  size_--;
}

void stack::operator=(stack& p) {
  // Apaga todos os elementos na pilha corrente.
  while (!empty()) {
    pop();
  }
  // Insere os elementos de p de trás para frente na pilha corrente.
  for (Node* i = p.end_->prev; i != p.end_; i = i->prev) {
    push(i->key);
  }
}
