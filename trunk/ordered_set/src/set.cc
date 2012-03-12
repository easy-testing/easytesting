// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set/src/set.h"

// Defite como os elementos da �rvore ser�o organizados na mem�ria.
struct Node {
  SType key;  // Valor da chave do n�.
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
// PRECONDI��O: x n�o � uma �rvore vazia.
Node* TreeMinimum(Node* x) {
  while (x->left != NULL) {
    x = x->left;
  }
  return x;
}

// Dado o n� x, retorna o sucessor de x, ou seja, o n� cuja chave � o menor
// elemento maior que a chave de x. Caso x seja o maior elemento da �rvore,
// retorna o n� sentinela.
Node* TreeSuccerssor(Node* x) {
  if (x->right != NULL) {
    return TreeMinimum(x->right);
  } else {
    Node* y = x->parent;
    while (y != NULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }
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
// NOTA: Esta fun��o N�O desaloca a mem�ria alocada para z.
Node* TreeDelete(Node*& root, Node* z) {
  Node* y;  // N� que ser� desconectado da �rvore.
  if (z->left == NULL || z->right == NULL) {
    y = z;
  } else {
    y = TreeSuccerssor(z);
  }
    Node* x; // N� que vai ser o novo filho do pai de y.
  if (y->left != NULL) {
    x = y->left;
  } else {
    x = y->right;
  }

  if (x != NULL) {
    x->parent = y->parent;
  }
  if (y->parent == NULL) {
    root = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }
    if (y->key != z->key) {
    z->key = y->key;
  }
    return y;
}

// Implementa��o das fun��es do TAD set.
////////////////////////////////////////////////////////////////////////////////

set::set() {
  root_ = NULL;
  size_= 0;
}

set::set(set& s) {
  root_ = NULL;
  size_ = 0;
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key);
  }
}

Node* set::begin() {
  if (empty()) {
    return end();
  } else {
    return TreeMinimum(root_);
  }
}

Node* set::end() {
  return NULL;
}

Node* set::next(Node* x) {
  return TreeSuccerssor(x);
}

SType set::operator[](Node* x) {
  return x->key;
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
return size_;
}

Node* set::find(SType k) {
  return TreeSearch(root_, k);
}

void set::insert(SType k) {
  if (find(k) == end()) {
    Node* z = new Node;
    z->key = k;
    z->parent = z->left = z->right = NULL;
    TreeInsert(root_, z);
    size_++;
  }
}

void set::erase(SType k) {
  Node* z = find(k);
  if (z != NULL) {
    delete TreeDelete(root_, z);
    size_--;
  }
}

void set::clear() {
  while (!empty()) {
    erase(begin()->key);
  }
}

void set::operator=(set& s) {
  clear();
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key);
  }
}

set::~set() {
  clear();
}
