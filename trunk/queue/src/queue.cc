// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "queue/src/node.h"
#include "queue/src/queue.h"

queue::queue() {
  size_ = 0;
  end_ = NewSentinel();
}

queue::~queue() {
  // TODO.
}

bool queue::empty() {
  return false; // TODO.
}
int queue::size() {
  return -1;  // TODO.
}

type queue::front() {
  type x;
  return x;  // TODO.
}

type queue::back() {
  type x;
  return x;  // TODO.
}

void queue::push(type x) {
  // TODO.
}

void queue::pop() {
  // TODO.
}
