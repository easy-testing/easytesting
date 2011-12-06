// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "priority_queue/src/node.h"
#include "priority_queue/src/priority_queue.h"

// Implementação das funções auxiliares que operam sobre os nós da árvore.
////////////////////////////////////////////////////////////////////////////////

// Cria um nó sentinela.
Node* NewSentinel() {
  Node* aux = new Node;
  aux->left = NULL;
  aux->right = NULL;
  aux->parent = NULL;
  return aux;
}

// Cria uma nó cuja chave é k, o nó a esquerda é l, o nó a direita é r e
// o nó acima é p.
Node* NewNode(Type k, Node* l, Node* r, Node* p) {
  Node* aux = new Node;
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

// Retorna true se p é o nó sentinela da árvore, ou false caso contrário.
bool IsSentinel(Node* p) {
  return p->parent == NULL;
}

// Retorna o nó com o menor elemento da árvore x em O(log n).
// PRECONDIÇÃO: x não é uma árvore vazia.
Node* TreeMinimum(Node* x) {
  while (x->left != NULL) {
    x = x->left;
  }
  return x;
}

// Insere uma FOLHA z na árvore cujo nó sentinela é t de forma consistente.
// NOTA: Esta função NÃO aloca a memória para z.
void TreeInsert(Node* end, Node* z) {
  // Procura qual vai ser o pai y de z na árvore.
  Node* y = end;
  Node* x = Root(end);
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
  if (IsSentinel(y)) {
    end->left = z;  // z se torna a raiz da árvore.
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
}

// Desconecta o nó z da árvore de forma consistente e depois retorna z.
// NOTA: Esta função NÃO desaloca a memória alocada para z.
// PRECONDIÇÃO: o filho ESQUERDO de z é vazio.
Node* RestrictedTreeDelete(Node* z) {
  // Troca o pai do filho direito de z (se este não for vazio).
  if (z->right != NULL) {
    z->right->parent = z->parent;
  }
  // Troca o filho do pai de z.
  if (z == z->parent->left) {
    z->parent->left = z->right;
  } else  {
    z->parent->right = z->right;
  }
  return z;
}

// Implementação das funções do TAD priority_queue.
////////////////////////////////////////////////////////////////////////////////

priority_queue::priority_queue() {
  end_ = NewSentinel();
  size_= 0;
}

priority_queue::~priority_queue() {
  while (!empty()) {
    pop();
  }
  delete end_;
}

bool priority_queue::empty() {
  return size_ == 0;
}

int priority_queue::size() {
  return size_;
}

Type priority_queue::top() {
  return (TreeMinimum(Root(end_))->key);
}

void priority_queue::push(Type k) {
  Node* z = NewNode(k, NULL, NULL, NULL);
  TreeInsert(end_, z);
  size_++;
}

void priority_queue::pop() {
  delete RestrictedTreeDelete(TreeMinimum(Root(end_)));
  size_--;
}
