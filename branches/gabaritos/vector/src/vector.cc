// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "vector/src/vector.h"

#include <stdlib.h>

vector::vector() {
  size_ = 0;
  array_ = NULL;
}

vector::vector(int m) {
  size_ = m;
  array_ = new type[size_];
}

vector::vector(vector& v) {
  size_ = v.size_;
  array_ = new type[size_];
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

bool vector::empty() {
  return size_ == 0;
}

int vector::size() {
  return size_;
}

void vector::resize(int m) {
  if (m > size_) {
    type* aux = new type[m];
    for (int i = 0; i < size_; i++) {
      aux[i] = array_[i];
    }
    delete [] array_;
    array_ = aux;
  }
  size_ = m;
}

type& vector::at(int i) {
  return array_[i];
}

void vector::assign(vector& v) {
  resize(v.size_);
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

void vector::push_back(type x) {
  resize(size_ + 1);
  array_[size_ - 1] = x;
}

void vector::pop_back() {
  size_--;
}

void vector::insert(int i, type x) {
  resize(size_ + 1);
  for (int j = size_ - 1; j > i; j--) {
    array_[i] = array_[j - 1];
  }
  array_[i] = x;
}

void vector::erase(int i) {
  for (int j = i; j < size_ - 1; j++) {
    array_[j] = array_[j + 1];
  }
  resize(size_ - 1);
}

void vector::clear() {
  size_ = 0;
}

vector::~vector() {
  delete [] array_;
}
