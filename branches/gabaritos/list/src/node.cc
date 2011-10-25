// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/node.h"

Node* NewSentinel() {
  Node* node = new Node();
  node->prev = node->next = node;
  return node;
}

// Cria um novo no em O(1).
Node* NewNode(ListType k, Node* l, Node* r) {
  Node* node = new Node();
  node->key = k;
  node->prev = l;
  node->next = r;
  return node;
}
