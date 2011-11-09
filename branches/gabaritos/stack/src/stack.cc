// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "stack/src/stack.h"

#include "stack/src/node.h"

stack::stack() {
  size_ = 0;
  end_ = new node();
  end_->next = end_;
  end_->prev = end_;
}

stack::~stack() {
  // Primeiramente, remove todos os elementos da pilha.
  while (!empty()) {
    pop();  // A função pop() libera a memórima de cada nó removido da pilha.
  }
  // Em seguida, libera a memória alocada ao sentinela.
  delete end_;
}

bool stack::empty() {
  return size_ == 0;
}

int stack::size() {
  return size_;
}

type stack::top() {
  return end_->next->key;
}

void stack::push(type k) {
  node* i = end_->next;  // Ponteiro para o primeiro elemento na fila.
  node* k_node = new node({k, i->prev, i});
  i->prev->next = k_node;
  i->prev = k_node;
  size_++;
}

void stack::pop() {
  node* first = end_->next;  // Ponteiro para o primeiro elemento na fila.
  first->prev->next = first->next;
  first->next->prev = first->prev;
  delete first;
  size_--;
}
