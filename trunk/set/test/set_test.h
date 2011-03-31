// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_TEST_SET_TEST_H_
#define SET_TEST_SET_TEST_H_

#include "set/src/set.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaSet(set<int> &c, int n, int v[]) {
    for (int i = 0; i < n; ++i) {
      c.insert(v[i]);
    }
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string PrintSet(set<int> &c) {
    stringstream out;
    list<int> l;
    if (c.empty()) {
      return "Conjunto Vazio";
    } else {
      c.ToList(&l);
      out << "{ ";
      for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        out << *it << " ";
      }
      out << "}";
      return out.str();
    }
  }

  // Retorna uma string contendo os elementos da lista l
  // no formato [ l1 l2 l3 l4 ]
  string PrintList(list<int> &l) {
    stringstream out;
    if (l.empty()) {
      return "Lista Vazia";
    } else {
      out << "[ ";
      for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        out << *it << " ";
      }
      out << "]";
      return out.str();
    }
  }
};

TEST_F(Teste, Testar_metodo_empty_em_conjunto_vazio) {
  set<int> c;
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto esta vazio e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_empty_em_conjunto_unitario) {
  set<int> c;
  int v[] = {3};
  CriaSet(c, 1, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_com_varios_elementos) {
  set<int> c;
  int v[] = {3, 8, 5, 6, 4, 7};
  CriaSet(c, 6, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui varios elementos e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_vazio) {
  set<int> c;
  int esperado = 0;
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int set<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_unitario) {
  set<int> c;
  int esperado = 1;
  int v[] = {3};
  CriaSet(c, 1, v);
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int set<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_com_varios_elementos) {
  set<int> c;
  int esperado = 3;
  int v[] = {3, 0, 4};
  CriaSet(c, 3, v);
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int set<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_vazio) {
  set<int> c;
  bool atual = c.find(4);
  ASSERT_FALSE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set<Type>::find(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou TRUE para a procura de um elemento nao\n"
    << "contido no conjunto\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_com_varios_elementos) {
  set<int> c;
  int v[] = {3, 5, 8, 15};
  int procurado = 4;
  CriaSet(c, 4, v);
  bool atual = c.find(procurado);
  ASSERT_FALSE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set<Type>::find(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou TRUE para a procura de um elemento nao\n"
    << "contido no conjunto\n"
    << " Conjunto: " << PrintSet(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";

  procurado = 8;
  atual = c.find(procurado);
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool set<Type>::find(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou FALSE para a procura de um elemento\n"
    << "contido no conjunto\n"
    << " Conjunto: " << PrintSet(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_em_conjunto_vazio) {
  set<int> c;
  string esperado = "{ 4 }";
  c.insert(4);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 1;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_nao_contido_em_conjunto) {
  set<int> c;
  string esperado = "{ 4 5 7 8 }";
  int v[] = {4, 5, 7};
  CriaSet(c, 3, v);
  int inserir = 8;
  c.insert(inserir);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << " Elemento inserido: " << inserir << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 4;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_contido_em_conjunto) {
  set<int> c;
  string esperado = "{ 1 3 4 5 }";
  int v[] = {4, 5, 1, 3};
  CriaSet(c, 4, v);
  int inserir = 5;
  c.insert(inserir);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << " Elemento inserido: " << inserir << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 4;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função corretamente nao inseriu um elemento no conjunto pois ja\n"
    << " possuia o elemento porem alterou o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_unitario) {
  set<int> c;
  string esperado = "Conjunto Vazio";
  int v[] = {4};
  CriaSet(c, 1, v);
  int apagar = 4;
  c.erase(apagar);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos) {
  set<int> c;
  string esperado = "{ 6 7 8 }";
  int v[] = {4, 6, 7, 8};
  CriaSet(c, 4, v);
  int apagar = 4;
  c.erase(apagar);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  int size_esperado = 3;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_Tolist_em_conjunto_vazio) {
  set<int> c;
  list<int> l;
  string esperado = "Lista Vazia";
  c.ToList(&l);
  string atual = PrintList(l);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::ToList(list<Type>& l) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto inicial: " << PrintSet(c) << "\n"
    << "   Lista esperada: " << esperado << "\n"
    << "    Lista formada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_Tolist_em_conjunto_unitario) {
  set<int> c;
  list<int> l;
  string esperado = "[ 6 ]";
  int v[] = {6};
  CriaSet(c, 1, v);
  c.ToList(&l);
  string atual = PrintList(l);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::ToList(list<Type>& l) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto inicial: " << PrintSet(c) << "\n"
    << "   Lista esperada: " << esperado << "\n"
    << "    Lista formada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_Tolist_em_conjunto_com_varios_elementos) {
  set<int> c;
  list<int> l;
  string esperado = "[ 6 7 8 ]";
  int v[] = {6, 7, 8};
  CriaSet(c, 3, v);
  c.ToList(&l);
  string atual = PrintList(l);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::ToList(list<Type>& l) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto inicial: " << PrintSet(c) << "\n"
    << "   Lista esperada: " << esperado << "\n"
    << "    Lista formada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_vazio) {
  set<int> c;
  c.clear();
  int atual = c.empty();
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_com_varios_elementos) {
  set<int> c;
  int v[] = {10, 5, 9};
  CriaSet(c, 3, v);
  c.clear();
  int atual = c.empty();
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}
#endif  // SET_TEST_SET_TEST_H_
