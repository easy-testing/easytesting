// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_NODE_H_
#define BRANCHES_GABARITOS_LIST_SRC_NODE_H_

#include "ordered_set/src/set.h"

// Defite como os elementos do conjunto serão organizados na memória.
struct node {
  type key;  // Valor da chave do nó.
  node* right;  // Ponteiro para o nó a direita.
  node* left;  // Ponteiro para o nó a esquerda.
  node* parent;  // Ponteiro para o nó acima.
};

#endif  // BRANCHES_GABARITOS_LIST_SRC_NODE_H_
