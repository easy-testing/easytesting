// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef NODE_H_
#define NODE_H_

typedef float ListType;

struct Node {
  ListType key;  // Valor associado ao no da lista.
  Node* prev;  // Ponteiro para o proximo no da lista.
  Node* next;  // Ponteiro para o no anterior da lista.
};

// Cria um no sentinela em O(1).
Node* NewSentinel();

// Cria um novo no em O(1).
Node* NewNode(ListType k, Node* l, Node* r);

#endif // NODE_H_
