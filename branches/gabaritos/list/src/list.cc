// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

list::list() {
  size_ = 0;
  end_ = NewSentinel();
}

list::list(list& l) {
  size_ = 0;
  end_ = NewSentinel();
  merge(l);
}

list::~list() {
  clear();
  delete end_;
}

node* list::begin() {
  return end_->next;
}

node* list::end() {
  return end_;
}

bool list::empty() {
  return size_ == 0;
}

list::type list::front() {
  return end_->next->key;
}

list::type list::back() {
  return end_->prev->key;
}

int list::size() {
  return size_;
}

void list::push_front(list::type x) {
  insert(begin(), x);
}

void list::pop_front() {
  erase(begin());
}

void list::push_back(list::type x) {
  insert(end(), x);
}

void list::pop_back() {
  erase(end_->prev);
}

node* list::find(list::type x) {
  node* iter = begin();
  while (iter != end() && iter->key != x) {
    iter = iter->next;
  }
  return iter;
}

node* list::insert(node* node, list::type x) {
  node->prev = node->prev->next = NewNode(x, node->prev, node);
  size_++;
  return node->prev;
}

void list::erase(node* node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  delete node;
  size_--;
}

void list::clear() {
  while (!empty()) {
    pop_back();
  }
}

void list::merge(list& l) {
  for (node* i = l.begin(); i != l.end(); i = i->next) {
    push_back(i->key);
  }
}

void list::operator=(list& l) {
  clear();
  merge(l);
}

// Funcoes do struct node.
//////////////////////////

node* NewSentinel() {
  node* aux = new node();
  aux->prev = aux->next = aux;
  return aux;
}

node* NewNode(list::type k, node* l, node* r) {
  node* aux = new node();
  aux->key = k;
  aux->prev = l;
  aux->next = r;
  return aux;
}
