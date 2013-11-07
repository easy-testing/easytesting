// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue/src/priority_queue.h"

// Define como os elementos da �rvore ser�o organizados na mem�ria.
struct Node {
  SType key;  // Valor da chave do n�.
  int copies;  // N�mero de c�pia da chave na fila.
  Node* left;  // Ponteiro para o n� a esquerda.
  Node* right;  // Ponteiro para o n� a direita.
  Node* parent;  // Ponteiro para o n� acima.
};

// Implementa��o das fun��es auxiliares que operam sobre os n�s da �rvore.
////////////////////////////////////////////////////////////////////////////////

// Retorna o n� da �rvore x cuja chave � k em O(log n),
// ou NULL caso k n�o esteja na �rvore x.
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

// Retorna o n� com o menor elemento da �rvore x em O(log n).
// Precondi��o: x n�o � uma �rvore vazia.
Node* TreeMinimum(Node* x) {
  while (x->left != NULL) {
    x = x->left;
  }
  return x;
}

// Insere uma FOLHA z na �rvore cujo n� raiz � 'root' de forma consistente.
// NOTA: Esta fun��o N�O aloca a mem�ria para z.
void TreeInsert(Node*& root, Node* z) {
  // Procura qual vai ser o pai y de z na �rvore.
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
  // Insere z em baixo do n� y.
  z->parent = y;
  if (y == NULL) {
    root = z;  // z se torna a raiz da �rvore.
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
}

// Desconecta o n� z da �rvore de forma consistente e depois retorna z.
// Precondi��o: A sub�rvore esquerda de z � vazia.
// NOTA: Esta fun��o N�O desaloca a mem�ria alocada para z.
Node* TreeDeleteMin(Node*& root, Node* z) {
  Node* x = z->right;  // N� que vai ser o novo filho do pai de z.
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

// Implementa��o das fun��es do TAD set.
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
