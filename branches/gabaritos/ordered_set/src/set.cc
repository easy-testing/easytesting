// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set/src/set.h"

#include <iostream>

using namespace std;

// Implementação das funções auxiliares que operam sobre os nós da árvore.
////////////////////////////////////////////////////////////////////////////////

// Cria um nó sentinela.
node* NewSentinel(){
  node* aux = new node();
  aux->left = NULL;
  aux->right = NULL;
  aux->parent = NULL;
  return aux;
}

// Cria uma nó cuja chave é k, o nó a esquerda é l, e o nó a direita é r e
// o nó acima é p.
node* NewNode(type k, node* l, node* r, node* p) {
  node* aux = new node();
  aux->key = k;
  aux->left = l;
  aux->right = r;
  aux->parent = p;
  return aux;
}

// Retorna o nó da árvore x cuja chave é k em O(log n),
// ou NULL caso k não esteja na árvore x.
// PRECONDIÇÃO: x não é uma árvore vazia.
node* TreeSearch(node* x, type k) {
  while (x != NULL && k != x->key) {
    if ( k < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return x;
}

// Retorna o nó com o menor elemento da árvore x em O(log n).
// PRECONDIÇÃO: x não é uma árvore vazia.
node* TreeMinimum(node* x) {
  while (x->left != NULL) {
    x = x->left;
  }
  return x;
}

// Dado o nó x que pertence a uma árvore binária de busca qualquer,
// retorna o sucessor de x nesta árvore, ou seja, o nó cuja chave é o menor
// elemento maior que a chave de x.
node* TreeSuccerssor(node* x) {
  if (x->right != NULL) {
    return TreeMinimum(x->right);
  }
  node* y = x->parent;
  while (y != NULL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

// Conecta o nó z ao nó pai p de forma consistente.
// PRECONDIÇÃO: z não aponta para um árvore vazia.
void Connect(node* p, node* z) {
  if (p->parent == NULL || z->key < p->key) {
    p->left = z;
  } else  {
    p->right = z;
  }
  z->parent = p;
}

// Insere uma FOLHA z na árvore cujo nó sentinela é t de forma consistente.
// NOTA: Esta função NÃO aloca a memória para z.
void TreeInsert(node* t, node* z) {
  node* y = t;
  node* x = t->left;
  while (x != NULL) {
    y = x;
    x = (z->key < x->key) ? x->left : x->right;
  }
  Connect(y, z);
}

// Desconecta o nó z da árvore de forma consistente.
// PRECONDIÇÃO: pelo menos um dos filhos de z é vazio (possivelmente os dois).
void Disconnect(node* z) {
  node* p = z->parent;  // Pai de z.
  node* f = (z->left == NULL) ? z->right : z->left;  // Filho não vazio de z.
  if (z == p->left) {
    p->left = f;
  } else  {
    p->right = f;
  }
  if (f != NULL) {
    f->parent = p;
  }
}

// Desconecta o nó x da árvore de forma consistente e depois retorna x.
// NOTA: Esta função NÃO desaloca a memória alocada para x.
node* TreeDelete(node* z) {
  if (z->right == NULL) {
    Disconnect(z);  // Subárvore direita de x é vazia.
    return z;
  } else {
    node* y = TreeMinimum(z->right);
    Disconnect(y);  // Subárvore esquerda de y é vazia.
    z->key = y->key;
    return y;
  }
}

// Implementação das funções auxiliares.
////////////////////////////////////////////////////////////////////////////////

set::set() {
  end_ = NewSentinel();
  size_= 0;
}

set::set(set& s) {
  end_ = NewSentinel();
  size_ = 0;
  for (node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key);
  }
}

set::~set() {
  clear();
  delete end_;
}

node* set::begin() {
  if (empty()) {
    return end();
  } else {
    return TreeMinimum(end_->left);
  }
}

node* set::end() {
  return end_;
}

node* set::next(node* x) {
  return TreeSuccerssor(x);
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
return size_;
}

node* set::find(type k) {
  node* aux = TreeSearch(end_->left, k);
  if (aux != NULL) {
    return aux;
  } else {
    return end();
  }
}

node* set::insert(type k) {
  node* z = TreeSearch(end_->left, k);
  if (z != NULL) {
    return z;
  } else {
    z = NewNode(k, NULL, NULL, NULL);
    TreeInsert(end_, z);
    size_++;
  }
}

void set::erase(type k) {
  node* aux = TreeSearch(end_->left, k);
  if (aux != NULL) {
    delete TreeDelete(aux);
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
  for (node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key);
  }
}

