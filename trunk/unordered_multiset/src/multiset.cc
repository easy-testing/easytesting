// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_multiset/src/multiset.h"

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  int count;  // Número de ocorrências da chave.
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

// Retorna o nó com o maior elemento da árvore x em O(log n).
// Precondição: x não é uma árvore vazia.
Node* TreeMaximum(Node* x) {
  while (x->right != NULL) {
    x = x->right;
  }
  return x;
}

// Dado o nó x, retorna o sucessor de x, ou seja, o nó cuja chave é o menor
// elemento maior que a chave de x. Caso x seja o maior elemento da árvore,
// retorna NULL.
Node* TreeSuccessor(Node* x) {
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

// Dado o nó x, retorna o predecessor de x, ou seja, o nó cuja chave é o maior
// elemento menor que a chave de x. Caso x seja o menor elemento da árvore,
// retorna NULL.
Node* TreePredecessor(Node* x) {
  if (x->left != NULL) {
    return TreeMaximum(x->left);
  } else {
    Node* y = x->parent;
    while (y != NULL && x == y->left) {
      x = y;
      y = y->parent;
    }
    return y;
  }
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
// NOTA: Esta função NÃO desaloca a memória alocada para z.
Node* TreeDelete(Node*& root, Node* z) {
  Node* y;  // Nó que será desconectado da árvore.
  if (z->left == NULL || z->right == NULL) {
    y = z;
  } else {
    y = TreeSuccessor(z);
  }
  Node* x;  // Nó que vai ser o novo filho do pai de y.
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
    z->count = y->count;
  }
  return y;
}

// Implementação das funções do TAD multiset.
////////////////////////////////////////////////////////////////////////////////

multiset::multiset() {
  root_ = NULL;
  size_= 0;
}

Node* multiset::begin() {
  if (empty()) {
    return end();
  } else {
    return TreeMinimum(root_);
  }
}

Node* multiset::end() {
  return NULL;
}

Node* multiset::next(Node* x) {
  return TreeSuccessor(x);
}

Node* multiset::prev(Node* x) {
  if (x == end()) {
    return TreeMaximum(root_);
  } else {
    return TreePredecessor(x);
  }
}

int multiset::count(SType k) {
  Node* x = find(k);
  if (x == end()) {
    return 0;
  } else {
    return x->count;
  }
}

SType multiset::key(Node* x) {
  return x->key;
}

bool multiset::empty() {
  return size_ == 0;
}

int multiset::size() {
  return size_;
}

Node* multiset::find(SType k) {
  return TreeSearch(root_, k);
}

void multiset::insert(SType k) {
  Node* x = find(k);
  if (x != end()) {
    x->count++;
  } else {
    Node* z = new Node;
    z->key = k;
    z->count = 1;
    z->parent = z->left = z->right = NULL;
    TreeInsert(root_, z);
  }
  size_++;
}

void multiset::erase(SType k) {
  Node* z = find(k);
  if (z != end()) {
    if (z->count > 1) {
      z->count--;
    } else {
      delete TreeDelete(root_, z);
    }
    size_--;
  }
}

void multiset::clear() {
  while (!empty()) {
    erase(begin()->key);
  }
}

void multiset::operator=(multiset& s) {
  clear();
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    for (int j = 0; j < i->count; j++) {
      insert(i->key);
    }
  }
}

multiset::~multiset() {
  clear();
}
