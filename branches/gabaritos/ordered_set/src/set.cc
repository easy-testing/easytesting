// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "ordered_set/src/node.h"
#include "ordered_set/src/set.h"

// Implementação das funções auxiliares que operam sobre os nós da árvore.
////////////////////////////////////////////////////////////////////////////////

// Cria um nó sentinela.
Node* NewSentinel() {
  Node* aux = new Node();
  aux->left = NULL;
  aux->right = NULL;
  aux->parent = NULL;
  return aux;
}

// Cria uma nó cuja chave é k, o nó a esquerda é l, e o nó a direita é r e
// o nó acima é p.
Node* NewNode(Type k, Node* l, Node* r, Node* p) {
  Node* aux = new Node();
  aux->key = k;
  aux->left = l;
  aux->right = r;
  aux->parent = p;
  return aux;
}

// Retorna a raiz da árvore cujo nó sentinela é 'end'.
Node* Root(Node* end) {
  return end->left;
}


// Retorna true se p é o nó sentinela, ou false caso contrário.
bool IsEnd(Node* p) {
  return p->parent == NULL;
}

// Retorna o nó da árvore x cuja chave é k em O(log n),
// ou NULL caso k não esteja na árvore x.
// PRECONDIÇÃO: x não é uma árvore vazia.
Node* TreeSearch(Node* x, Type k) {
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
// PRECONDIÇÃO: x não é uma árvore vazia.
Node* TreeMinimum(Node* x) {
  while (x->left != NULL) {
    x = x->left;
  }
  return x;
}

// Dado o nó x que pertence a uma árvore binária de busca qualquer,
// retorna o sucessor de x nesta árvore, ou seja, o nó cuja chave é o menor
// elemento maior que a chave de x.
Node* TreeSuccerssor(Node* x) {
  if (x->right != NULL) {
    return TreeMinimum(x->right);
  }
  Node* y = x->parent;
  while (y != NULL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

// Insere uma FOLHA z na árvore cujo nó sentinela é t de forma consistente.
// NOTA: Esta função NÃO aloca a memória para z.
void TreeInsert(Node* end, Node* z) {
  Node* y = end;
  Node* x = Root(end);
  while (x != NULL) {
    y = x;
    x = (z->key < x->key) ? x->left : x->right;
  }
  z->parent = y;
  if (IsEnd(y)) {
    end->left = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
}

// Desconecta o nó z da árvore de forma consistente e depois retorna z.
// NOTA: Esta função NÃO desaloca a memória alocada para z.
// PRECONDIÇÃO: Um dos filhos de z é vazio (possivelmente os dois).
Node* RestrictedTreeDelete(Node* z) {
  // Seleciona qual o filho de z que vai substituir ele.
  Node* f;
  if (z->left == NULL) {
    f = z->right;
  } else {
    f = z->left;
  }
  // Troca o pai do filho de z.
  Node* p = z->parent;
  if (f != NULL) {
    f->parent = p;
  }
  // Troca o filho do pai de z.
  if (z == p->left) {
    p->left = f;
  } else  {
    p->right = f;
  }
  return z;
}

// Desconecta o nó z da árvore de forma consistente e depois retorna z.
// NOTA: Esta função NÃO desaloca a memória alocada para z.
Node* TreeDelete(Node* z) {
  if (z->right == NULL || z->left == NULL) {
    return RestrictedTreeDelete(z);  // Subárvore direita de z é vazia.
  } else {
    Node* y = TreeMinimum(z->right);
    z->key = y->key;
    return RestrictedTreeDelete(y);  // Subárvore esquerda de y é vazia.
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
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key);
  }
}

set::~set() {
  clear();
  delete end_;
}

Node* set::begin() {
  if (empty()) {
    return end();
  } else {
    return TreeMinimum(Root(end_));
  }
}

Node* set::end() {
  return end_;
}

Node* set::next(Node* x) {
  return TreeSuccerssor(x);
}

Type set::value(Node* x) {
  return x->key;
}

bool set::empty() {
  return size_ == 0;
}

int set::size() {
return size_;
}

Node* set::find(Type k) {
  Node* aux = TreeSearch(Root(end_), k);
  if (aux != NULL) {
    return aux;
  } else {
    return end();
  }
}

Node* set::insert(Type k) {
  Node* z = find(k);
  if (z != end()) {
    return z;
  } else {
    z = NewNode(k, NULL, NULL, NULL);
    TreeInsert(end_, z);
    size_++;
  }
}

void set::erase(Type k) {
  Node* aux = find(k);
  if (aux != end()) {
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
  for (Node* i = s.begin(); i != s.end(); i = s.next(i)) {
    insert(i->key);
  }
}

