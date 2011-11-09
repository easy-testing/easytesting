// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

#include "list/src/node.h"

list::list() {
  size_ = 0;
  end_ = new node();
  end_->next = end_;
  end_->prev = end_;
}

list::list(list& l) {
  size_ = 0;
  end_ = new node();
  end_->next = end_;
  end_->prev = end_;
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

node* list::next(node* i) {
  return i->next;
}

node* list::prev(node* i) {
  return i->prev;
}

type list::value(node* i) {
  return i->key;
}

bool list::empty() {
  return size_ == 0;
}

type list::front() {
  return end_->next->key;
}

type list::back() {
  return end_->prev->key;
}

int list::size() {
  return size_;
}

void list::push_front(type x) {
  insert(begin(), x);
}

void list::pop_front() {
  erase(begin());
}

void list::push_back(type x) {
  insert(end(), x);
}

void list::pop_back() {
  erase(end_->prev);
}

node* list::insert(node* i, type k) {
  node* k_node = new node({k, i->prev, i});
  i->prev->next = k_node;
  i->prev = k_node;
  size_++;
  return k_node;
}

void list::erase(node* x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  delete x;
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
