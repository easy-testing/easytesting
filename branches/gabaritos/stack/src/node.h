// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_STACK_SRC_NODE_H_
#define BRANCHES_GABARITOS_STACK_SRC_NODE_H_

#include "stack/src/stack.h"

// Implementa um nó da lista encadeada.
struct node {
  type key;  // Valor da chave do nó.
  node* prev;  // Ponteiro para o nó anterior.
  node* next;  // Ponteiro para o próximo nó.
};

#endif  // BRANCHES_GABARITOS_STACK_SRC_NODE_H_
