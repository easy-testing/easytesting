// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_NODE_H_
#define BRANCHES_GABARITOS_LIST_SRC_NODE_H_

#include "list/src/list.h"

struct Node {

  type key;  // Valor da chave do noh.
  Node* prev;  // Ponteiro para o proximo noh da lista.
  Node* next;  // Ponteiro para o noh anterior da lista.
};

Node* NewSentinel() {
  Node* node = new Node();
  node->prev = node->next = node;
  return node;
}

// Cria um novo no em O(1).
Node* NewNode(list::type k, Node* l, Node* r) {
  Node* node = new Node();
  node->key = k;
  node->prev = l;
  node->next = r;
  return node;
}

#endif  // BRANCHES_GABARITOS_LIST_SRC_NODE_H_
