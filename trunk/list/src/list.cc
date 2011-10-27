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
  // TODO.
}

node* list::end() {
  // TODO.
}

bool list::empty() {
  // TODO.
}

list::type list::front() {
  // TODO.
}

list::type list::back() {
  // TODO.
}

int list::size() {
  // TODO.
}

void list::push_front(type x) {
  // TODO.
}

void list::pop_front() {
  // TODO.
}

void list::push_back(type x) {
  // TODO.
}

void list::pop_back() {
  // TODO.
}

node* list::insert(node* node, type x) {
  // TODO.
}

void list::erase(node* node) {
  // TODO.
}

void list::clear() {
  // TODO.
}

void list::merge(list& l) {
  // TODO.
}

void list::operator=(list& l) {
  // TODO.
}

node* list::NewSentinel() {
  node* aux = new node();
  aux->prev = aux->next = aux;
  return aux;
}

node* list::NewNode(list::type k, node* l, node* r) {
  node* aux = new node();
  aux->key = k;
  aux->prev = l;
  aux->next = r;
  return aux;
}
