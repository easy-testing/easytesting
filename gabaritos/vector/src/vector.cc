// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "vector/src/vector.h"

#include <cstdlib>

vector::vector() {
  size_ = 0;
  array_ = NULL;
}

vector::vector(int n) {
  size_ = n;
  array_ = new VType[size_];
}

vector::vector(vector& v) {
  size_ = v.size_;
  array_ = new VType[size_];
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

int vector::size() {
  return size_;
}

void vector::resize(int n) {
  VType* aux = new VType[n];
  for (int i = 0; i < size_ && i < n; i++) {
    aux[i] = array_[i];
  }
  delete [] array_;
  array_ = aux;
  size_ = n;
}

VType& vector::operator[](int i) {
  return array_[i];
}

void vector::operator=(vector& v) {
  resize(v.size_);
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

void vector::push_back(VType x) {
  resize(size_ + 1);
  array_[size_ - 1] = x;
}

void vector::pop_back() {
  resize(size_ - 1);
}

void vector::insert(int index, VType x) {
  resize(size_ + 1);
  for (int i = size_ - 1; i > index; i--) {
    array_[i] = array_[i - 1];
  }
  array_[index] = x;
}

void vector::erase(int index) {
  for (int i = index; i < size_ - 1; i++) {
    array_[i] = array_[i + 1];
  }
  resize(size_ - 1);
}

vector::~vector() {
  delete [] array_;
}
