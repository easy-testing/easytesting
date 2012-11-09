// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_
#define TRUNK_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "priority_queue/src/priority_queue.h"

using std::string;
using std::stringstream;

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna a raiz da árvore de s.
  Node* root(const priority_queue& s) {
    return s.root_;
  }

  // Retorna um ponteiro para o primeiro elemento da fila de prioridades.
  Node* begin(const priority_queue& s) {
    Node* x = s.root_;
    if (x != NULL) {
      while (x->left != NULL) {
        x = x->left;
      }
    }
    return x;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento
  // da fila de prioridades.
  Node* end(const priority_queue& s) {
    return NULL;
  }

  // Dado o nó x, retorna o sucessor de x, ou seja, o nó cuja chave é o menor
  // elemento maior que a chave de x. Caso x seja o maior elemento da árvore,
  // retorna o nó sentinela.
  Node* next(Node* x) {
    if (x->right != NULL) {
      x = x->right;
      while (x->left != NULL) {
        x = x->left;
      }
      return x;
    } else {
      Node* y = x->parent;
      while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
      }
      return y;
    }
  }

  // Retorna o número de elementos na fila de prioridades.
  int size(const priority_queue& s) {
    return s.size_;
  }

  // Insere uma FOLHA z na árvore cujo nó raiz é 'root' de forma consistente.
  // NOTA: Esta função NÃO aloca a memória para z.
  void TreePush(Node*& root, Node* z) {
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

  void Push(SType k, priority_queue* c) {
    Node* z = new Node;
    z->key = k;
    z->left = z->right = z->parent = NULL;
    TreePush(c->root_, z);
    c->size_++;
  }

  // Cria uma fila de prioridades com três elementos.
  void CriaFila(SType x1, SType x2, SType x3, priority_queue* s) {
    Push(x2, s);
    Push(x1, s);
    Push(x3, s);
  }

  // Retorna uma string contendo os elementos da fila de prioridades s
  // no formato [ c1 c2 c3 c4 ]
  string ToString(priority_queue& s) {
    stringstream out;
    out << "[ ";
    for (Node* i = begin(s); i != end(s); i = next(i)) {
      out << i->key << " ";
    }
    out << "]";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  priority_queue atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: priority_queue::priority_queue()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um fila de prioridades vazia, size_ = 0.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_TRUE(root(atual) == NULL)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: priority_queue::priority_queue()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um fila de prioridades vazia, root_ = NULL.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_fila_de_prioridades_vazia) {
  priority_queue s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int priority_queue::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_fila_de_prioridades_nao_vazia) {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  int esperado = 3;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int priority_queue::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_fila_de_prioridades_vazia) {
  priority_queue s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool priority_queue::empty() \n"
      << "------------------------------------------------------------------\n"
      << " a fila de prioridades esta vazia e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_fila_de_prioridades_nao_vazio) {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool priority_queue::empty() \n"
      << "------------------------------------------------------------------\n"
      << " a fila de prioridades tem pelo menos um elemento\n"
      << " e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Top_na_raiz) {
  priority_queue s;
  Push("10", &s);
  SType atual = s.top();
  SType esperado = "10";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType priority_queue::top()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << "[ 10 ]" << "\n"
    << " \"s.top()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Top_nao_raiz) {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  SType atual = s.top();
  SType esperado = "1";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType priority_queue::top()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << "[ 1 2 3 ]" << "\n"
    << " \"s.top()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_em_fila_de_prioridades_vazia) {
  priority_queue s;
  s.push("10");
  string atual = ToString(s);
  string esperado("[ 10 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void priority_queue::push(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = [ ] \n"
      << " \"s.push(10)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_em_fila_de_prioridades_nao_vazia) {
  priority_queue s;
  CriaFila("1", "3", "4", &s);
  s.push("2");
  string atual = ToString(s);
  string esperado("[ 1 2 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void priority_queue::push(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = [ 1 3 4 ] \n"
      << " \"s.push(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_com_elemento_que_ja_esta_la) {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  s.push("2");
  string atual = ToString(s);
  string esperado("[ 1 2 2 3 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void priority_queue::push(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = [ 1 2 3 ] \n"
      << " \"s.push(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_fila_de_prioridades_unitaria) {
  priority_queue s;
  s.push("10");
  s.pop();
  string atual = ToString(s);
  string esperado("[ ]");
  ASSERT_EQ(0, size(s))
    << "------------------------------------------------------------------\n"
    << "Erro na funcao: void priority_queue::pop() *\n"
    << "------------------------------------------------------------------\n"
    << " s = [ 10 ] \n"
    << " Resultado esperado: s = " << esperado << "\n"
    << " Ao apagar um elemento, você tem que decrementar size_"
    << "------------------------------------------------------------------\n";
  ASSERT_TRUE(root(s) == NULL)
    << "------------------------------------------------------------------\n"
    << "Erro na funcao: void priority_queue::pop() *\n"
    << "------------------------------------------------------------------\n"
    << " s = [ 10 ] \n"
    << " Resultado esperado: s = " << esperado << "\n"
    << " DICA: root_ deveria apontar para NULL num fila de prioridades vazia.\n"
    << "------------------------------------------------------------------\n";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void priority_queue::pop() *\n"
      << "------------------------------------------------------------------\n"
      << " s = [ 10 ] \n"
      << " \"s.pop()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta atualizando \"sroot_\".\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_no_sem_a_subarvore_direita) {
  priority_queue s;
  Push("2", &s);
  Push("1", &s);
  Push("3", &s);
  s.pop();
  string atual = ToString(s);
  string esperado("[ 2 3 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void priority_queue::pop() *\n"
      << "------------------------------------------------------------------\n"
      << " s = [ 1 2 3 ] \n"
      << " \"s.pop()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
      << " um no sem filhos.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_no_com_subarvore_direita) {
  priority_queue s;
  Push("2", &s);
  Push("4", &s);
  Push("3", &s);
  s.pop();
  string atual = ToString(s);
  string esperado("[ 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void priority_queue::pop() *\n"
      << "------------------------------------------------------------------\n"
      << " s = [ 2 3 4 ] \n"
      << " \"s.pop()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
         " um no que tem as duas subarvores nao vazias.\n"
      << "------------------------------------------------------------------\n";
}

#endif  // TRUNK_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_
