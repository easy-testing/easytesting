// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

#include "list/src/node.h"

list::list() {
  size_ = 0;
  end_ = new Node();
  end_->next = end_;
  end_->prev = end_;
}

list::list(list& l) {
  size_ = 0;
  end_ = new Node();
  end_->next = end_;
  end_->prev = end_;
  merge(l);
}

list::~list() {
  clear();
  delete end_;
}

Node* list::begin() {
  return end_->next;
}

Node* list::end() {
  return end_;
}

Node* list::next(Node* i) {
  return i->next;
}

Node* list::prev(Node* i) {
  return i->prev;
}

Type list::value(Node* i) {
  return i->key;
}

bool list::empty() {
  return size_ == 0;
}

Type list::front() {
  return end_->next->key;
}

Type list::back() {
  return end_->prev->key;
}

int list::size() {
  return size_;
}

void list::push_front(Type k) {
  insert(begin(), k);
}

void list::pop_front() {
  erase(begin());
}

void list::push_back(Type k) {
  insert(end(), k);
}

void list::pop_back() {
  erase(end_->prev);
}

Node* list::insert(Node* i, Type k) {
  Node* node = new Node({k, i->prev, i});
  i->prev->next = node;
  i->prev = node;
  size_++;
  return node;
}

void list::erase(Node* i) {
  i->prev->next = i->next;
  i->next->prev = i->prev;
  delete i;
  size_--;
}

void list::clear() {
  while (!empty()) {
    pop_back();
  }
}

void list::merge(list& l) {
  for (Node* i = l.begin(); i != l.end(); i = i->next) {
    push_back(i->key);
  }
}

void list::operator=(list& l) {
  clear();
  merge(l);
}
