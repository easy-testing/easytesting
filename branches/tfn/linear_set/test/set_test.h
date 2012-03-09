// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LINEAR_SET_TEST_SET_TEST_H_
#define BRANCHES_GABARITOS_LINEAR_SET_TEST_SET_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "linear_set/src/set.h"
#include "list/src/node.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  string Value(Node* x) {
    return x->key;
  }

  Node* insert(string k, set* c) {
    for (Node* i = c->list_.begin();
         i != c->list_.end();
         i = c->list_.next(i)) {
      if (c->list_.value(i) == k) {
        return i;
      } else if (c->list_.value(i) > k) {
        return c->list_.insert(i, k);
      }
    }
    return c->list_.insert(c->list_.end(), k);
  }

  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaSet(set& c, int n, string v[]) {
    for (int i = 0; i < n; ++i) {
      insert(v[i], &c);
    }
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string ToString(set& c) {
    stringstream out;
    out << "{ ";
    for (Node* i = c.begin(); i != c.end(); i = c.next(i)) {
      out << c.list_.value(i) << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testar_Construtor_por_copia_vazio) {
  set c;
  set d(c);
  string atual = ToString(c);
  string esperado = ToString(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* set::set(set c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_varios_elementos) {
  set c;
  string v[] = {"1", "3", "5", "8", "2"};
  CriaSet(c, 5, v);
  set d(c);
  string atual = ToString(c);
  string esperado = ToString(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* set::set(set c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_vazio) {
  set c;
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto esta vazio e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_unitario) {
  set c;
  string v[] = {"3"};
  CriaSet(c, 1, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_com_varios_elementos) {
  set c;
  string v[] = {"3", "8", "5", "6", "4", "7"};
  CriaSet(c, 6, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui varios elementos e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_vazio) {
  set c;
  int atual = c.size();
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int set::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_unitario) {
  set c;
  string v[] = {"3"};
  CriaSet(c, 1, v);
  int atual = c.size();
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int set::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_com_varios_elementos) {
  set c;
  string v[] = {"3", "0", "4"};
  CriaSet(c, 3, v);
  int atual = c.size();
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int set::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto  : " << ToString(c)  << "\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_vazio) {
  set c;
  ASSERT_EQ(c.end(), c.find("4"))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::find(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou algo diferente de NULL para a procura de um \n"
    << "elemento nao contido no conjunto\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_com_varios_elementos) {
  set c;
  string v[] = {"8", "5", "3", "15"};
  CriaSet(c, 4, v);
  ASSERT_EQ(c.end(), c.find("4"))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::find(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou algo diferente de NULL para a procura de um \n"
    << "elemento nao contido no conjunto\n"
    << "-------------------------------------------------------------------\n";

  string procurado = "8";
  string retornado = Value(c.find(procurado));
  ASSERT_EQ(procurado, retornado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::find(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto: " << ToString(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << " Elemento retornando: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_em_conjunto_vazio) {
  set c;
  c.insert("4");
  string atual = ToString(c);
  string esperado = "{ 4 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::insert(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto esperado: " << esperado << "\n"
    << "Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 1;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::insert(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << " Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_nao_contido_em_conjunto) {
  set c;
  string v[] = {"5", "4", "7"};
  CriaSet(c, 3, v);
  c.insert("8");
  string atual = ToString(c);
  string esperado = "{ 4 5 7 8 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::insert(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << " Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 4;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::insert(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_contido_em_conjunto) {
  set c;
  string v[] = {"4", "5", "1", "3"};
  CriaSet(c, 4, v);
  c.insert("5");
  string atual = ToString(c);
  string esperado = "{ 1 3 4 5 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::insert(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 4;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* set::insert(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função corretamente nao inseriu um elemento no conjunto pois ja\n"
    << " possuia o elemento porem alterou o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_com_exito) {
  set c;
  string v[] = {"4", "6", "7", "8"};
  CriaSet(c, 4, v);
  c.erase("6");
  string atual = ToString(c);
  string esperado = "{ 4 7 8 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_sem_exito) {
  set c;
  string v[] = {"4", "6", "7", "8"};
  CriaSet(c, 4, v);
  c.erase("5");
  string atual = ToString(c);
  string esperado = "{ 4 6 7 8 }";
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_vazio) {
  set c;
  c.clear();
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set::clear(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << "A função limpou corretamente o conteudo do conjunto porem\n"
    << "nao alterou corretamente o valor do tamanho do conjunto.\n\n"
    << "Tamanho Esperado: " << size_esperado << "\n"
    << "Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_com_varios_elementos) {
  set c;
  string v[] = {"10", "5", "9"};
  CriaSet(c, 3, v);
  c.clear();
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set::clear(type k) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << " Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_LINEAR_SET_TEST_SET_TEST_H_
