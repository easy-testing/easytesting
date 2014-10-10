// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/deque.h"

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

deque::deque() {
  size_ = 0;
  end_ = new Node;
  end_->next = end_;
  end_->prev = end_;
}

deque::~deque() {
  // Primeiramente, remove todos os elementos do deque.
  while (!empty()) {
    pop_front();  // pop_front() libera a memórima de cada nó removido do deque.
  }
  // Em seguida, libera a memória alocada ao sentinela.
  delete end_;
}

bool deque::empty() const {
  return size_ == 0;
}

int deque::size() const {
  return size_;
}

LType deque::front() const {
  return end_->next->key;
}

LType deque::back() const {
  return end_->prev->key;
}

void deque::push_front(LType k) {
  Node* i = end_->next;  // Ponteiro para o primeiro elemento na fila.
  Node* node = new Node;
  node->key = k;
  node->prev = i->prev;
  node->next = i;

  i->prev->next = node;
  i->prev = node;
  size_++;
}

void deque::pop_front() {
  Node* first = end_->next;
  first->prev->next = first->next;
  first->next->prev = first->prev;
  size_--;
}

void deque::push_back(LType k) {
  Node* k_node = new Node;
  k_node->key = k;
  k_node->prev = end_->prev;
  k_node->next = end_;
  end_->prev->next = k_node;
  end_->prev = k_node;
  size_++;
}

void deque::pop_back() {
  Node* last = end_->prev;
  last->prev->next = last->next;
  last->next->prev = last->prev;
  size_--;
}

void deque::operator=(const deque& d) {
  // Apaga todos os elementos no deque corrente.
  while (!empty()) {
    pop_front();
  }
  // Insere os elementos de q no deque corrente.
  for (Node* i = d.end_->next; i != d.end_; i = i->next) {
    push_back(i->key);
  }
}
