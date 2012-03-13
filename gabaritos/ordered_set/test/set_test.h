// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_TEST_SET_TEST_H_
#define TRUNK_ORDERED_SET_TEST_SET_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "ordered_set/src/set.h"

using std::string;
using std::stringstream;

// Defite como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  Node* NewNode(SType k, Node* l, Node* r, Node* p) {
    Node* aux = new Node();
    aux->key = k;
    aux->left = l;
    aux->right = r;
    aux->parent = p;
    return aux;
  }
    // Retorna um ponteiro para o primeiro elemento do conjunto.
  Node* begin(const set& s) {
    return s.root_;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento
  // do conjunto.
  Node* end(const set& s) {
    return NULL;
  }

  // Dado o nó x, retorna o sucessor de x, ou seja, o nó cuja chave é o menor
  // elemento maior que a chave de x. Caso x seja o maior elemento da árvore,
  // retorna o nó sentinela.
  Node* TreeSuccerssor(Node* x) {
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

  // Retorna o número de elementos no conjunto.
  int size(const set& s) {
    return s.size_;
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

  void insert(SType k, set* c) {
    Node* z = NewNode(k, NULL, NULL, NULL);
    TreeInsert(c->root_, z);
    c->size_++;
  }

  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaConjunto(SType x1, SType x2, SType x3, set* s) {
    insert(x2, s);
    insert(x1, s);
    insert(x3, s);
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string ToString(set& c) {
    stringstream out;
    out << "{ ";
    for (Node* i = c.begin(); i != c.end(); i = TreeSuccerssor(i)) {
      out << i->key << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  set atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_TRUE(begin(atual) == NULL)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, root_ = NULL.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_vazio) {
  set c;
  set s(c);
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set(set& s) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " Conjunto criado: " << atual << "\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_com_varios_elementos) {
  set c;
  CriaConjunto("1", "2", "3", &c);
  set s(c);
  string atual = ToString(s);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set(set& s) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " Conjunto criado: " << atual << "\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Find_em_conjunto_vazio) {
  set s;
  Node* atual = s.find("4");
  Node* esperado = NULL;
  ASSERT_TRUE(atual == esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " \"s.find(4)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Find_retorna_true) {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  Node* atual = s.find("3");
  Node* esperado = begin(s)->right->left;
  ASSERT_TRUE(atual == esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual->key << "\n"
    << " Valor esperado: ponteiro para " << esperado->key << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Find_retorna_false) {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("5", &s);
  insert("3", &s);
  Node* atual = s.find("4");
  Node* esperado = NULL;
  ASSERT_TRUE(atual == esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(4)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_Size_para_conjunto_vazio) {
  set s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  int esperado = 3;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_conjunto_vazio) {
  set s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Begin_com_conjunto_vazio) {
  set s;
  ASSERT_EQ(NULL, s.begin())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::begin() \n"
      << "------------------------------------------------------------------\n"
      << " begin() nao retorna NULL no conjunto vazio.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Begin_com_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  SType atual = s.begin()->key;
  SType esperado = "1";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.begin()]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_End_com_conjunto_vazio) {
  set s;
  ASSERT_EQ(NULL, s.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::end() \n"
      << "------------------------------------------------------------------\n"
      << " end() nao retorna end_ no conjunto vazio.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_End_com_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  ASSERT_EQ(NULL, s.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " end() nao retornou NULL.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Next_abaixo) {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  SType atual = s.next(s.find("2"))->key;
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"2\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_Next_acima) {
  set s;
  insert("3", &s);
  insert("1", &s);
  insert("4", &s);
  insert("2", &s);
  SType atual = s.next(s.find("2"))->key;
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"2\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta acima de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Prev_acima) {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  SType atual = s.prev(s.find("3"))->key;
  SType esperado = "2";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"3\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta acima de 'x'.\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_Prev_abaixo) {
  set s;
  insert("3", &s);
  insert("1", &s);
  insert("4", &s);
  insert("2", &s);
  SType atual = s.prev(s.find("3"))->key;
  SType esperado = "2";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"3\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_At) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  SType atual = s[s.begin()];
  SType esperado = "1";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType& set::operator[](Node* x)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << "{ 1 2 3 }" << "\n"
    << " \"s[s.begin()]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_em_conjunto_vazio) {
  set s;
  s.insert("10");
  string atual = ToString(s);
  string esperado("{ 10 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(10)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_em_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "3", "4", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " l = { 1 3 4 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Erase_em_conjunto_unitario) {
  set s;
  s.insert("10");
  s.erase("10");
  string atual = ToString(s);
  string esperado("{ }");
  ASSERT_TRUE(begin(s) == NULL)
    << "------------------------------------------------------------------\n"
    << "Erro na funcao: void set::erase(SType k) *\n"
    << "------------------------------------------------------------------\n"
    << " s = { 10 } \n"
    << " Resultado esperado: s = " << esperado << "\n"
    << " DICA: s.root_ deveria apontar para NULL num conjunto vazio.\n"
    << "------------------------------------------------------------------\n";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 10 } \n"
      << " \"s.erase(10)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta atualizando \"s.root_\".\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_em_no_sem_filhos) {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.erase("3");
  string atual = ToString(s);
  string esperado("{ 1 2 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.erase(3)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
      << " um no sem filhos.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_em_no_sem_subarvore_direita) {
  set s;
  insert("2", &s);
  insert("1", &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 } \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
      << " um no que nao tem a subarvore direita.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_em_no_sem_subarvore_esquerda) {
  set s;
  insert("2", &s);
  insert("3", &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 } \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
         " um no que nao tem a subarvore esquerda.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_em_no_com_os_dois_filhos) {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4} \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
         " um no que tem as duas subarvores nao vazias.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  s.clear();
  string atual = ToString(s);
  string esperado("{ }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 4 7 } \n"
      << " \"s.clear()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  set esperado;
  CriaConjunto("1", "2", "3", &esperado);
  set atual;
  atual = esperado;
  ASSERT_NE(begin(esperado), begin(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"root_\". \n"
    << " Você tem que copiar todos os elementos de s para o\n"
       " conjunto corrente.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(esperado) << "\n"
    << " \"u = s\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_ORDERED_SET_TEST_SET_TEST_H_
