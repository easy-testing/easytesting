// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue/src/priority_queue.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

priority_queue::priority_queue() {
  // TODO.
}

bool priority_queue::empty() {
  return false;  // TODO.
}

int priority_queue::size() {
  return 0;  // TODO.
}

// Implemente uma função "Node* TreeMinimum(Node* x)"
// que retorna o nó com o menor elemento da árvore x em O(log n).
// Vide livro "Algoritmos: Teoria e Prática".
SType priority_queue::top() {
  return root_->key;  // TODO.
}

// Dica: Implemente uma função "void TreeInsert(Node*& root, Node* z)"
// que insere uma FOLHA z na árvore cujo nó raiz é 'root' de forma consistente.
// Vide livro "Algoritmos: Teoria e Prática".
// Não esqueça de alocar a memória para o nó z.
void priority_queue::push(SType k) {
  // TODO.
}

// Dica: Use a função "Node* TreeMinimum(Node* x)" e
// implemente uma função "Node* TreeDelete(Node*& root, Node* z)"
// que desconecta o nó com o menor elemento da árvore de forma consistente
// e depois retorna z. Lembre que o menor elemento da árvore sempre tem
// a sua subárvore esquerda vazia.
// Vide livro "Algoritmos: Teoria e Prática".
// Não esqueça de desalocar a memória alocada para z.
void priority_queue::pop() {
  // TODO.
}

priority_queue::~priority_queue() {
  // TODO.
}
