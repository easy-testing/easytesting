// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "stack_with_array/src/stack.h"

void stack::reserve(int m) {
  if (m > capacity_) {
    capacity_ = m;
    SType* aux = new SType[capacity_];
    for (int i = 0; i < size_; i++) {
      aux[i] = array_[i];
    }
    delete [] array_;
    array_ = aux;
  }
}

stack::stack() {
  // TODO.
}

bool stack::empty() {
  return false;  // TODO.
}

int stack::size() {
  return 0;  // TODO.
}

SType stack::top() {
  return SType();  // TODO.
}

void stack::push(SType k) {
  // TODO.
}

void stack::pop() {
  // TODO.
}

void stack::operator=(stack& p) {
  // TODO.
}

stack::~stack() {
  // TODO.
}
