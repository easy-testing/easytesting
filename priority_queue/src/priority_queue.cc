// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/priority_queue.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  int copies;  // Número de cópia da chave na fila.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

// Implementação das funções auxiliares que operam sobre os nós da árvore.
////////////////////////////////////////////////////////////////////////////////

// Retorna o nó da árvore x cuja chave é k em O(log n),
// ou NULL caso k não esteja na árvore x.
Node* TreeSearch(Node* x, SType k) {
  while (x != NULL && k != x->key) {
    if (k < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return x;
}

// Retorna o nó com o menor elemento da árvore x em O(log n).
// Precondição: x não é uma árvore vazia.
Node* TreeMinimum(Node* x) {
  while (x->left != NULL) {
    x = x->left;
  }
  return x;
}

// Insere uma FOLHA z na árvore cujo nó raiz é 'root' de forma consistente.
// NOTA: Esta função NÃO aloca a memória para z.
void TreeInsert(Node*& root, Node* z) {
  // Procura qual vai ser o pai y de z na árvore.
  Node* y = NULL;
  Node* x = root;
  while (x != NULL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  // Insere z em baixo do nó y.
  z->parent = y;
  if (y == NULL) {
    root = z;  // z se torna a raiz da árvore.
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
}

// Desconecta o nó z da árvore de forma consistente e depois retorna z.
// Precondição: A subárvore esquerda de z é vazia.
// NOTA: Esta função NÃO desaloca a memória alocada para z.
Node* TreeDeleteMin(Node*& root, Node* z) {
  Node* x = z->right;  // Nó que vai ser o novo filho do pai de z.
  if (x != NULL) {
    x->parent = z->parent;
  }
  if (z->parent == NULL) {
    root = x;
  } else {
    z->parent->left = x;
  }
  return z;
}

// Implementação das funções do TAD set.
////////////////////////////////////////////////////////////////////////////////

priority_queue::priority_queue() {
  root_ = NULL;
  size_= 0;
}

bool priority_queue::empty() {
  return size_ == 0;
}

int priority_queue::size() {
  return size_;
}

SType priority_queue::top() {
  return TreeMinimum(root_)->key;
}

void priority_queue::push(SType k) {
  Node* x = TreeSearch(root_, k);
  if (x != NULL) {
    x->copies++;
  } else {
    Node* z = new Node;
    z->key = k;
    z->copies = 1;
    z->parent = z->left = z->right = NULL;
    TreeInsert(root_, z);
  }
  size_++;
}

void priority_queue::pop() {
  Node* z = TreeMinimum(root_);
  if (z->copies > 1) {
    z->copies--;
  } else {
    delete TreeDeleteMin(root_, z);
  }
  size_--;
}

priority_queue::~priority_queue() {
  while (root_ != NULL) {
    delete TreeDeleteMin(root_, TreeMinimum(root_));
  }
}
