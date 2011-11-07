// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef LIST_NODE_INCLUDED
#define LIST_NODE_INCLUDED

template<class Type>
struct Node {
  Type key;  // Valor associado ao no da lista.
  Node* prev;  // Ponteiro para o proximo no da lista.
  Node* next;  // Ponteiro para o no anterior da lista.

  // Cria um no sentinela em O(1).
  Node() {
    prev = next = this;
  }

 // Cria um novo no em O(1).
  Node(Type k, Node* l, Node* r) {
    key = k;
    prev = l;
    next = r;
  }
};  // end struct Node;

#endif // LIST_NODE_INCLUDED
