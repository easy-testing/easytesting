// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_
#define BRANCHES_GABARITOS_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "priority_queue/src/node.h"
#include "priority_queue/src/priority_queue.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
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

  // Dado o nó x, retorna o sucessor de x, ou seja, o nó cuja chave é o menor
  // elemento maior que a chave de x. Caso x seja o maior elemento da árvore,
  // retorna o nó sentinela.
  Node* TreeSuccerssor(Node* x) {
    if (x->right != NULL) {
      return TreeMinimum(x->right);
    } else {
      Node* y = x->parent;
      while (!IsSentinel(y) && x == y->right) {
        x = y;
        y = y->parent;
      }
      return y;
    }
  }

  Node* NewNode(Type k, Node* l, Node* r, Node* p) {
    Node* aux = new Node();
    aux->key = k;
    aux->left = l;
    aux->right = r;
    aux->parent = p;
    return aux;
  }
  // Conecta o nó z ao nó pai p de forma consistente.
  // PRECONDIÇÃO: z não aponta para um árvore vazia.
  void Connect(Node* p, Node* z) {
    if (p->parent == NULL || z->key < p->key) {
      p->left = z;
    } else  {
      p->right = z;
    }
    z->parent = p;
  }

  // Insere uma FOLHA z na árvore cujo nó sentinela é t de forma consistente.
  // NOTA: Esta função NÃO aloca a memória para z.
  void TreeInsert(Node* t, Node* z) {
    Node* y = t;
    Node* x = t->left;
    while (x != NULL) {
      y = x;
      x = (z->key < x->key) ? x->left : x->right;
    }
    Connect(y, z);
  }
  void insert(Type k, priority_queue* c) {
    Node* z = NewNode(k, NULL, NULL, NULL);
    TreeInsert(c->end_, z);
    c->size_++;
  }

  Node* begin(priority_queue& q) {
    if (q.size_ == 0)
      return q.end_;
    else
      return TreeMinimum(Root(q.end_));
  }

  Node* end(priority_queue& q) {
    return q.end_;
  }

  Node* next(Node* x) {
    return TreeSuccerssor(x);
  }

  // Preenche a priority_queue passada como parametro com 1 numero.
  // 'f' deve ser uma priority_queue vazia.
  void CriaQueue1(string x, priority_queue& f) {
    insert(x, &f);
  }

  // Preenche a priority_queue passada como parametro com "3" numeros.
  // 'f' deve ser uma lista vazia.
  void CriaQueue3(string x1, string x2, string x3, priority_queue& f) {
    insert(x1, &f);
    insert(x2, &f);
    insert(x3, &f);
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string PrintQueue(priority_queue& q) {
    stringstream output;
    output << "{";
    for (Node* i = begin(q) ; i != end(q) ; i = next(i)) {
      if (i == begin(q))
        output << i->key;
      else
        output << " " << i->key;
    }
    output << "}";
    return output.str();
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  priority_queue f1;
  ASSERT_TRUE(f1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool priority_queue::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A priority_queue esta vazia e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";

  priority_queue f2;
  CriaQueue3("12", "14", "15", f2);
  ASSERT_FALSE(f2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool priority_queue::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A priority_queue tem pelo menos um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_top_em_priority_queue_com_um_elemento) {
  priority_queue f;
  CriaQueue1("2", f);
  string esperado = "2";
  string atual = f.top();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type priority_queue::top() *\n"
  << "-------------------------------------------------------------------\n"
  << "fila = " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_top_em_priority_queue_com_mais_de_um_elemento) {
  priority_queue f;
  CriaQueue3("7", "3", "8", f);
  string esperado = "3";
  string atual = f.top();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type priority_queue::top() *\n"
  << "-------------------------------------------------------------------\n"
  << "fila = " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_priority_queue_vazia) {
  priority_queue f;
  int esperado = 0;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* string priority_queue::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "fila = " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_priority_queue_com_um_elemento) {
  priority_queue f;
  CriaQueue1("2", f);
  int esperado = 1;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int priority_queue::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "fila = " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_priority_queue_com_varios_elementos) {
  priority_queue f;
  CriaQueue3("10", "3", "0", f);
  int esperado = 3;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int priority_queue::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "fila = " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

// Para realizar a comparacao da priority_queue esperada para a priority_queue
// do aluno, foi necessario utilizar a comparacao da classe string (imprimir a
// priority_queue do aluno em uma string).
TEST_F(Teste, Testar_metodo_push_em_priority_queue_vazia) {
  priority_queue f;
  f.push("10");
  string esperado("{10}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void priority_queue::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_priority_queue_com_um_elemento_menor) {
  priority_queue f;
  CriaQueue1("22", f);
  f.push("12");
  string esperado("{12 22}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void priority_queue::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_priority_queue_com_um_elemento_maior) {
  priority_queue f;
  CriaQueue1("22", f);
  f.push("32");
  string esperado("{22 32}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void priority_queue::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_priority_queue_com_varios_elementos) {
  priority_queue f;
  CriaQueue3("13", "50", "49", f);
  f.push("17");
  string esperado("{13 17 49 50}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void priority_queue::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_priority_queue_com_um_elemento) {
  priority_queue f;
  CriaQueue1("8", f);
  f.pop();
  string esperado("{}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void priority_queue::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_priority_queue_com_varios_elemento) {
  priority_queue f;
  CriaQueue3("8", "0", "3", f);
  f.pop();
  string esperado("{3 8}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void priority_queue::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_
