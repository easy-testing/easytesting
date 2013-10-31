// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_map/src/map.h"

map::map() {
  // TODO.
}

Node* map::begin() {
  return end();  // TODO.
}

Node* map::end() {
  return NULL;  // TODO.
}

Node* map::next(Node* x) {
  return end();  // TODO.
}

Node* map::prev(Node* x) {
  return end();  // TODO.
}

VType& map::operator[](SType x) {
  VType k;
  return k;  // TODO.
}

SType map::key(Node* x) {
  return SType();  // TODO.
}

VType map::value(Node* x) {
  return VType();  // TODO.
}

bool map::empty() {
  return false;  // TODO.
}

int map::size() {
  return 0;  // TODO.
}

Node* map::find(SType k) {
  return end();  // TODO.
}

void map::insert(SType k, VType v) {
  // TODO.
}

void map::erase(SType k) {
  // TODO.
}

void map::clear() {
  // TODO.
}

void map::operator=(map& s) {
  // TODO.
}

map::~map() {
  // TODO.
}
