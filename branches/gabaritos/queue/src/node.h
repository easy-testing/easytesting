// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_QUEUE_SRC_NODE_H_
#define BRANCHES_GABARITOS_QUEUE_SRC_NODE_H_

#include "queue/src/queue.h"

// Implementa um nó da lista encadeada.
struct node {
  type key;  // Valor da chave do nó.
  node* prev;  // Ponteiro para o próximo nó.
  node* next;  // Ponteiro para o nó anterior.
};

#endif  // BRANCHES_GABARITOS_QUEUE_SRC_NODE_H_
