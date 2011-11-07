// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_NODE_H__
#define BRANCHES_GABARITOS_LIST_SRC_NODE_H__

#include<string>


// Implementa um nó da árvore.
struct node {
  type key;  // Valor da chave do nó.
  node* right;  // Ponteiro para o nó a direita.
  node* left;  // Ponteiro para o nó a esquerda.
  node* parent;  // Ponteiro para o nó acima.
};

// Cria um nó sentinela.
node* NewSentinel();

// Cria uma nó cuja chave é k, o nó a esquerda é l, e o nó a direita é r e
// o nó acima é p.
node* NewNode(type k, node* l, node* r, node* p);

#endif  // BRANCHES_GABARITOS_LIST_SRC_NODE_H__
