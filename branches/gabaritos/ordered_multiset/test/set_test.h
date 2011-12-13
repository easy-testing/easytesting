// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_ORDERED_MULTISET_TEST_MULTISET_TEST_H_
#define BRANCHES_GABARITOS_ORDERED_MULTISET_TEST_MULTISET_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "ordered_multiset/src/node.h"
#include "ordered_multiset/src/set.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
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

  void insert(Type k, multiset* c) {
    Node* z = NewNode(k, NULL, NULL, NULL);
    TreeInsert(c->end_, z);
    c->size_++;
  }

  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaSet(multiset& c, int n, string v[]) {
    for (int i = 0; i < n; ++i) {
      insert(v[i], &c);
    }
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string ToString(multiset& c) {
    stringstream out;
    out << "{ ";
    for (Node* i = c.begin(); i != c.end(); i = c.next(i)) {
      out << i->key << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testar_Construtor_por_copia_vazio) {
  multiset c;
  multiset d(c);
  string atual = ToString(c);
  string esperado = ToString(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* multiset::multiset(multiset c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_varios_elementos) {
  multiset c;
  string v[] = {"1", "3", "5", "8", "1", "2"};
  CriaSet(c, 5, v);
  multiset d(c);
  string atual = ToString(c);
  string esperado = ToString(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* multiset::multiset(multiset c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_vazio) {
  multiset c;
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool multiset::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto esta vazio e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_unitario) {
  multiset c;
  string v[] = {"3"};
  CriaSet(c, 1, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool multiset::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_com_varios_elementos) {
  multiset c;
  string v[] = {"3", "8", "5", "6", "4", "7"};
  CriaSet(c, 6, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool multiset::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui varios elementos e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_vazio) {
  multiset c;
  int atual = c.size();
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int multiset::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_unitario) {
  multiset c;
  string v[] = {"3"};
  CriaSet(c, 1, v);
  int atual = c.size();
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int multiset::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_com_varios_elementos) {
  multiset c;
  string v[] = {"3", "3", "3"};
  CriaSet(c, 3, v);
  int atual = c.size();
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int multiset::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto  : " << ToString(c)  << "\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_vazio) {
  multiset c;
  ASSERT_EQ(c.end(), c.find("4"))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::find(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou algo diferente de NULL para a procura de um \n"
    << "elemento nao contido no conjunto\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_find_em_conjunto_com_varios_elementos) {
  multiset c;
  string v[] = {"8", "5", "3", "5"};
  CriaSet(c, 4, v);
  ASSERT_EQ(c.end(), c.find("4"))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::find(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou algo diferente de NULL para a procura de um \n"
    << "elemento nao contido no conjunto\n"
    << "-------------------------------------------------------------------\n";

  string procurado = "8";
  string retornado = c.find(procurado)->key;
  ASSERT_EQ(procurado, retornado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::find(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto: " << ToString(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << " Elemento retornando: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_count_em_conjunto_vazio) {
  multiset c;
  string procurado = "6";
  int esperado = 0;
  int atual = c.count(procurado);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int multiset::count(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto: " << ToString(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << " Valor esperado: " << esperado << "\n"
    << " Valor atual: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_count_em_conjunto_que_contem_o_elemento) {
  multiset c;
  string v[] = {"8", "5", "8", "5"};
  CriaSet(c, 4, v);
  string procurado = "8";
  int esperado = 2;
  int atual = c.count(procurado);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int multiset::count(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto: " << ToString(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << " Valor esperado: " << esperado << "\n"
    << " Valor atual: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_count_em_conjunto_que_nao_contem_o_elemento) {
  multiset c;
  string v[] = {"8", "5", "8", "5"};
  CriaSet(c, 4, v);
  string procurado = "6";
  int esperado = 0;
  int atual = c.count(procurado);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int multiset::count(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto: " << ToString(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << " Valor esperado: " << esperado << "\n"
    << " Valor atual: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_em_conjunto_vazio) {
  multiset c;
  c.insert("4");
  string atual = ToString(c);
  string esperado = "{ 4 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::insert(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto esperado: " << esperado << "\n"
    << "Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 1;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::insert(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << " Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_nao_contido_em_conjunto) {
  multiset c;
  string v[] = {"5", "4", "5"};
  CriaSet(c, 3, v);
  c.insert("8");
  string atual = ToString(c);
  string esperado = "{ 4 5 5 8 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::insert(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << " Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 4;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::insert(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_contido_em_conjunto) {
  multiset c;
  string v[] = {"4", "5", "1", "3"};
  CriaSet(c, 4, v);
  c.insert("3");
  string atual = ToString(c);
  string esperado = "{ 1 3 3 4 5 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::insert(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 5;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* multiset::insert(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função corretamente nao inseriu um elemento no conjunto pois ja\n"
    << " possuia o elemento porem alterou o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_com_exito) {
  multiset c;
  string v[] = {"4", "6", "6", "8"};
  CriaSet(c, 4, v);
  c.erase("6");
  string atual = ToString(c);
  string esperado = "{ 4 6 8 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void multiset::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_sem_exito) {
  multiset c;
  string v[] = {"4", "6", "6", "8"};
  CriaSet(c, 4, v);
  c.erase("5");
  string atual = ToString(c);
  string esperado = "{ 4 6 6 8 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void multiset::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_vazio) {
  multiset c;
  c.clear();
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void multiset::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void multiset::clear(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "A função limpou corretamente o conteudo do conjunto porem\n"
    << "nao alterou corretamente o valor do tamanho do conjunto.\n\n"
    << "Tamanho Esperado: " << size_esperado << "\n"
    << "Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_com_varios_elementos) {
  multiset c;
  string v[] = {"10", "10", "10"};
  CriaSet(c, 3, v);
  c.clear();
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void multiset::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void multiset::clear(Type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << " Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_ORDERED_MULTISET_TEST_MULTISET_TEST_H_
