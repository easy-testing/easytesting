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
  clear();  // Primeiramente, remove todos os elementos da lista.
  delete end_;  // Em seguida, libera a memória alocada ao sentinela.
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

type list::front() {
  // TODO.
}

type list::back() {
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

node* list::insert(node* p, type x) {
  // TODO.
}

void list::erase(node* p) {
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
