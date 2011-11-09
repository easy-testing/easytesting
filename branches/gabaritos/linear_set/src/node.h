// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_NODE_H_
#define BRANCHES_GABARITOS_LIST_SRC_NODE_H_

#include<string>

// Tipo dos elementos contidos na lista.
typedef std::string type;

// Implementa um nó.
struct node {
  type key;  // Valor da chave do nó.
  node* prev;  // Ponteiro para o nó anterior.
  node* next;  // Ponteiro para o próximo nó.
};

// Cria um nó sentinela.
node* NewSentinel();

// Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
node* NewNode(type k, node* l, node* r);

#endif  // BRANCHES_GABARITOS_LIST_SRC_NODE_H_