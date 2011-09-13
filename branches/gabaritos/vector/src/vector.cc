// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "vector/src/vector.h"

#include <stdlib.h>
#include <algorithm>

using namespace std;

vector::vector() {
  size_ = 0;
  array_ = NULL;
}

vector::vector(int n) {
  size_ = n;
  array_ = new float[size_];
}

vector::vector(vector& v) {
  size_ = v.size_;
  array_ = new float[size_];
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
    float* aux = new float[n];
    for (int i = 0; i < size_; i++) {
      aux[i] = array_[i];
    }
    for (int i = size_; i < n; i++) {
      aux[i] = 0.0;
    }
    delete [] array_;
    array_ = aux;
  }
  size_ = n;
}

float& vector::at(int i) {
  return array_[i];
}

float& vector::front() {
  return array_[0];
}

float& vector::back() {
  return array_[size_ - 1];
}

void vector::operator=(vector& v) {
  resize(v.size_);
  for (int i = 0; i < size_; i++) {
    array_[i] = v.array_[i];
  }
}

void vector::push_back(float x) {
  resize(size_ + 1);
  array_[size_ - 1] = x;
}

void vector::pop_back() {
  size_--;
}

bool vector::insert(int index, float x) {
  resize(size_ + 1);
  float aux = x;
  for (int i = index; i < size_; i++) {
    swap(aux, array_[i]);
  }
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
