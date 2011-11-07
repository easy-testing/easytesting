// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "deque/src/node.h"

node* NewSentinel() {
  node* aux = new node();
  aux->prev = aux->next = aux;
  return aux;
}

node* NewNode(type k, node* l, node* r) {
  node* aux = new node();
  aux->key = k;
  aux->prev = l;
  aux->next = r;
  return aux;
}
