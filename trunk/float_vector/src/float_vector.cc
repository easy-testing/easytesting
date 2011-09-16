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
  // TODO.
}

int FloatVector::size() {
  // TODO.
}

void FloatVector::resize(int n) {
  // TODO.
}

float& FloatVector::at(int i) {
  // TODO.
}

float& FloatVector::front() {
  // TODO.
}

float& FloatVector::back() {
  // TODO.
}

void FloatVector::assign(FloatVector& v) {
  // TODO.
}

void FloatVector::push_back(float x) {
  // TODO.
}

void FloatVector::pop_back() {
  // TODO.
}

void FloatVector::insert(int index, float x) {
  // TODO.
}

void FloatVector::erase(int index) {
  // TODO.
}

void FloatVector::clear() {
  // TODO.
}

FloatVector::~FloatVector() {
  delete [] array_;
}
