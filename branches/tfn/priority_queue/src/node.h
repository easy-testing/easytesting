// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_PRIORITY_QUEUE_SRC_NODE_H_
#define BRANCHES_GABARITOS_PRIORITY_QUEUE_SRC_NODE_H_

#include "type/type.h"

// Defite como os elementos do conjunto serão organizados na memória.
struct Node {
  Type key;  // Valor da chave do nó.
  Node* right;  // Ponteiro para o nó a direita.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* parent;  // Ponteiro para o nó acima.
};

#endif  // BRANCHES_GABARITOS_PRIORITY_QUEUE_SRC_NODE_H_
