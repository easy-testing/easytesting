// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/queue.h"

void queue::reserve(int m) {
  if (m > capacity_) {
    QType* aux = new QType[m];
    for (int i = 0; i < size_; i++) {
      aux[i] = array_[(i + first_) % capacity_];
    }
    first_ = 0;
    capacity_ = m;
    delete [] array_;
    array_ = aux;
  }
}

queue::queue() {
  first_ = size_ = 0;
  capacity_ = 16;
  array_ = new QType[capacity_];
}

bool queue::empty() {
  return size_ == 0;
}

int queue::size() {
  return size_;
}

QType queue::front() {
  return array_[first_];
}

QType queue::back() {
  return array_[(first_ + size_ - 1) % capacity_];
}

void queue::push(QType k) {
  if (size_ == capacity_) {
    reserve(2 * capacity_);
  }
  array_[(first_ + size_) % capacity_] = k;
  size_++;
}

void queue::pop() {
  first_ = (first_ + 1) % capacity_;
  size_--;
}

void queue::operator=(queue& q) {
  reserve(q.capacity_);
  size_ = q.size_;
  first_ = 0;
  for (int i = 0; i < q.size_; i++) {
    array_[i] = q.array_[(i + q.first_) % q.capacity_];
  }
}

queue::~queue() {
  delete [] array_;
}
