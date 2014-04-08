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
  size_ = 0;
  capacity_ = 16;
  array_ = new SType[capacity_];
}

bool stack::empty() {
  return size_ == 0;
}

int stack::size() {
  return size_;
}

SType stack::top() {
  return array_[size_ - 1];
}

void stack::push(SType k) {
  if (size_ == capacity_) {
    reserve(2 * capacity_);
  }
  array_[size_] = k;
  size_++;
}

void stack::pop() {
  size_--;
}

void stack::operator=(stack& p) {
  reserve(p.capacity_);
  size_ = p.size_;
  for (int i = 0; i < p.size_; i++) {
    array_[i] = p.array_[i];
  }
}

stack::~stack() {
  delete [] array_;
}
