// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_STACK_SRC_NODE_H_
#define BRANCHES_GABARITOS_STACK_SRC_NODE_H_

#include "type/type.h"

// Implementa um nó da lista encadeada.
struct Node {
  Type key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

#endif  // BRANCHES_GABARITOS_STACK_SRC_NODE_H_
