// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set/src/set.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

set::set() {
  // TODO.
}

set::set(set& s) {
  // TODO.
}

// Implemente uma função "Node* TreeMinimum(Node* x)"
// que retorna o nó com o menor elemento da árvore x em O(log n).
// Vide livro "Algoritmos: Teoria e Prática".
Node* set::begin() {
  return NULL;  // TODO.
}

Node* set::end() {
  return NULL;
}

// DICA: Implemente uma função "Node* TreeSuccessor(Node* x)"
// que retorna um ponteiro para o sucessor de x e caso x seja o maior
// elemento da árvore, retorna NULL.
// Vide livro "Algoritmos: Teoria e Prática".
Node* set::next(Node* x) {
  return NULL;  // TODO.
}

// DICA: Implemente uma função "Node* TreePredecessor(Node* x)"
// que retorna um ponteiro para o predecessor de x e caso x seja o menor
// elemento da árvore, retorna NULL.
// Vide livro "Algoritmos: Teoria e Prática".
Node* set::prev(Node* x) {
  return NULL;  // TODO.
}

SType set::operator[](Node* x) {
  return x->key;
}

bool set::empty() {
  return false;  // TODO.
}

int set::size() {
  return 0;  // TODO.
}

// DICA: Implemente uma função "Node* TreeSearch(Node* x, SType k)"
// que retorna o nó da árvore x cuja chave é k em O(log n),
// ou NULL caso k não esteja na árvore x.
// Vide livro "Algoritmos: Teoria e Prática".
Node* set::find(SType k) {
  return NULL;  // TODO.
}

// Dica: Implemente uma função "void TreeInsert(Node*& root, Node* z)"
// que insere uma FOLHA z na árvore cujo nó raiz é 'root' de forma consistente.
// Vide livro "Algoritmos: Teoria e Prática".
// Não esqueça de alocar a memória para o nó z.
void set::insert(SType k) {
  // TODO.
}

// Dica: Use a função "Node* TreeSearch(Node* x, SType k)" e
// implemente uma função "Node* TreeDelete(Node*& root, Node* z)"
// que desconecta o nó z da árvore de forma consistente e depois retorna z.
// Vide livro "Algoritmos: Teoria e Prática".
// Não esqueça de desalocar a memória alocada para z.
void set::erase(SType k) {
  // TODO.
}

void set::clear() {
  // TODO.
}

void set::operator=(set& s) {
  // TODO.
}

set::~set() {
  // TODO.
}
