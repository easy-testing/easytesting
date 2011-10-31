// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_NODE_H_
#define BRANCHES_GABARITOS_LIST_SRC_NODE_H_

#include<string>

using std::string;

// Tipo dos elementos contidos na fila.
typedef string type;

// Implementa um n�.
struct node {
  type key;  // Valor da chave do n�.
  node* prev;  // Ponteiro para o pr�ximo n�.
  node* next;  // Ponteiro para o n� anterior.
};

// Cria um n� sentinela.
node* NewSentinel();

// Cria uma n� cuja chave � k, o n� anterior � l, e o n� posterior � r.
node* NewNode(type k, node* l, node* r);

#endif  // BRANCHES_GABARITOS_LIST_SRC_NODE_H_
