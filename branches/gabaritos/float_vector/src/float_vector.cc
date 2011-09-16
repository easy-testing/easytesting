// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "float_vector/src/float_vector.h"

#include <stdlib.h>

FloatVector::FloatVector() {
  size_ = 0;
  array_ = NULL;
}

FloatVector::FloatVector(int n) {
  size_ = n;
  array_ = new float[size_];
}

FloatVector::FloatVector(FloatVector& v) {
  size_ = v.size_;
  array_ = new float[size_];
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

bool FloatVector::empty() {
  return size_ == 0;
}

int FloatVector::size() {
  return size_;
}

void FloatVector::resize(int n) {
  if (n > size_) {
    float* aux = new float[n];
    for (int i = 0; i < size_; i++) {
      aux[i] = array_[i];
    }
    delete [] array_;
    array_ = aux;
  }
  size_ = n;
}

float& FloatVector::at(int i) {
  return array_[i];
}

float& FloatVector::front() {
  return array_[0];
}

float& FloatVector::back() {
  return array_[size_ - 1];
}

void FloatVector::operator=(FloatVector& v) {
  resize(v.size_);
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

void FloatVector::push_back(float x) {
  resize(size_ + 1);
  array_[size_ - 1] = x;
}

void FloatVector::pop_back() {
  size_--;
}

void FloatVector::insert(int index, float x) {
  resize(size_ + 1);
  for (int i = size_ - 1; i > index; i--) {
    array_[i] = array_[i - 1];
  }
  array_[index] = x;
}

void FloatVector::erase(int index) {
  for (int i = index; i < size_ - 1; i++) {
    array_[i] = array_[i + 1];
  }
  resize(size_ - 1);
}

void FloatVector::clear() {
  size_ = 0;
}

FloatVector::~FloatVector() {
  delete [] array_;
}
