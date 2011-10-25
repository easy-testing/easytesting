// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "vector/src/vector.h"

#include <stdlib.h>

vector::vector() {
  size_ = 0;
  array_ = NULL;
}

vector::vector(int n) {
  size_ = n;
  array_ = new VectorType[size_];
}

vector::vector(vector& v) {
  size_ = v.size_;
  array_ = new VectorType[size_];
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

void vector::resize(int n) {
  if (n > size_) {
    VectorType* aux = new VectorType[n];
    for (int i = 0; i < size_; i++) {
      aux[i] = array_[i];
    }
    delete [] array_;
    array_ = aux;
  }
  size_ = n;
}

VectorType& vector::at(int i) {
  return array_[i];
}

VectorType& vector::front() {
  return array_[0];
}

VectorType& vector::back() {
  return array_[size_ - 1];
}

void vector::assign(vector& v) {
  resize(v.size_);
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

void vector::push_back(VectorType x) {
  resize(size_ + 1);
  array_[size_ - 1] = x;
}

void vector::pop_back() {
  size_--;
}

void vector::insert(int index, VectorType x) {
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

void vector::clear() {
  size_ = 0;
}

vector::~vector() {
  delete [] array_;
}
