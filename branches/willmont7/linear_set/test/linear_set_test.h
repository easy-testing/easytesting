// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef LINEAR_SET_TEST_H_
#define LINEAR_SET_TEST_H_

#include "linear_set/src/linear_set.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaSet(linear_set& c, int n, string v[]) {
    for (int i = 0; i < n; ++i) {
      c.insert(v[i]);
    }
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string PrintSet(linear_set &c) {
    stringstream out;
    linear_set aux = c;
    out << "{ ";
    while (!aux.empty()) {
      type x = aux.min();
      out << x << " ";
      aux.erase(x);
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testar_Construtor_por_copia_vazio) {
  linear_set c;
  c.clear();
  linear_set d(c);
  string atual = PrintSet(c);
  string esperado = PrintSet(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* ~linear_set::linear_set(linear_set c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_varios_elementos) {
  linear_set c;
  string v[5] = {"1", "3", "5", "8", "2"};
  CriaSet(c, 5, v);
  linear_set d(c);
  string atual = PrintSet(c);
  string esperado = PrintSet(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* ~linear_set::linear_set(linear_set c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_vazio) {
  linear_set c;
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto esta vazio e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_empty_em_conjunto_unitario) {
  linear_set c;
  string v[] = {"3"};
  CriaSet(c, 1, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_com_varios_elementos) {
  linear_set c;
  string v[] = {"3", "8", "5", "6", "4", "7"};
  CriaSet(c, 6, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui varios elementos e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_vazio) {
  linear_set c;
  int esperado = 0;
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int linear_set::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_unitario) {
  linear_set c;
  int esperado = 1;
  string v[] = {"3"};
  CriaSet(c, 1, v);
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int linear_set::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_com_varios_elementos) {
  linear_set c;
  int esperado = 3;
  string v[] = {"3", "0", "4"};
  CriaSet(c, 3, v);
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int linear_set::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_min_conjunto_unitario) {
  linear_set c;
  c.insert("3");
  string esperado = "3";
  string atual = c.min();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* type linear_set::min() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto : " << PrintSet(c) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_min_conjunto_com_varios_elementos_iguais) {
  linear_set c;
  string v[] = {"2", "2", "2", "2"};
  CriaSet(c, 4, v);
  string esperado = "2";
  string atual = c.min();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* type linear_set::min() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto : " << PrintSet(c) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_min_conjunto_com_varios_elementos_distintos) {
  linear_set c;
  string v[] = {"2", "4", "8", "-2"};
  CriaSet(c, 4, v);
  string esperado = "-2";
  string atual = c.min();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* type linear_set::min() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto : " << PrintSet(c) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_vazio) {
  linear_set c;
  bool atual = c.find("4");
  ASSERT_FALSE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::find(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou TRUE para a procura de um elemento nao\n"
    << "contido no conjunto\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_com_varios_elementos) {
  linear_set c;
  string v[] = {"3", "5", "8", "15"};
  string procurado = "4";
  CriaSet(c, 4, v);
  bool atual = c.find(procurado);
  ASSERT_FALSE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::find(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou TRUE para a procura de um elemento nao\n"
    << "contido no conjunto\n"
    << " Conjunto: " << PrintSet(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";

  procurado = "8";
  atual = c.find(procurado);
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::find(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou FALSE para a procura de um elemento\n"
    << "contido no conjunto\n"
    << " Conjunto: " << PrintSet(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_em_conjunto_vazio) {
  linear_set c;
  string esperado = "{ 4 }";
  c.insert("4");
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::insert(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 1;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::insert(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_nao_contido_em_conjunto) {
  linear_set c;
  string esperado = "{ 4 5 7 8 }";
  string v[] = {"4", "5", "7"};
  CriaSet(c, 3, v);
  string inserir = "8";
  c.insert(inserir);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::insert(type x) *\n"
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
    << "* void linear_set::insert(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_contido_em_conjunto) {
  linear_set c;
  string esperado = "{ 1 3 4 5 }";
  string v[] = {"1", "3", "4", "5"};
  CriaSet(c, 4, v);
  string inserir = "5";
  c.insert(inserir);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::insert(type x) *\n"
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
    << "* void linear_set::insert(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função corretamente nao inseriu um elemento no conjunto pois ja\n"
    << " possuia o elemento porem alterou o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_unitario_com_exito) {
  linear_set c;
  string apagar = "4";
  c.insert(apagar);
  string anterior = PrintSet(c);
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = "{ }";
  int size_esperado = 0;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_TRUE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A funcao retornou false, mesmo sendo possivel apagar o elemento\n"
    << " proposto:\n\n"
    << " Conjunto: " << anterior << "\n"
    << " Elemento a ser apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testa apagar numero
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_unitario_elemento_sem_exito) {
  linear_set c;
  string apagar = "4";
  c.insert("5");
  string anterior = PrintSet(c);
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = anterior;
  int size_esperado = 1;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_FALSE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A funcao retornou true, mesmo nao sendo possivel apagar o elemento\n"
    << " proposto:\n\n"
    << " Conjunto: " << anterior << "\n"
    << " Elemento a ser apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testa apagar numero
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_com_exito) {
  linear_set c;
  string v[] = {"4", "6", "7", "8"};
  CriaSet(c, 4, v);
  string anterior = PrintSet(c);
  string apagar = "4";
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = "{ 6 7 8 }";
  int size_esperado = 3;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_TRUE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A funcao retornou false, mesmo sendo possivel apagar o elemento\n"
    << " proposto:\n\n"
    << " Conjunto: " << anterior << "\n"
    << " Elemento a ser apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testa apagar numero
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_sem_exito) {
  linear_set c;
  string v[] = {"4", "6", "7", "8"};
  CriaSet(c, 4, v);
  string anterior = PrintSet(c);
  string apagar = "5";
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = anterior;
  int size_esperado = 4;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_FALSE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A funcao retornou true, mesmo sendo possivel apagar o elemento\n"
    << " proposto:\n\n"
    << " Conjunto: " << anterior << "\n"
    << " Elemento a ser apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testa apagar numero
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool linear_set::erase(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_vazio) {
  linear_set c;
  c.clear();
  int atual = c.empty();
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::insert(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_com_varios_elementos) {
  linear_set c;
  string v[] = {"10", "5", "9"};
  CriaSet(c, 3, v);
  c.clear();
  int atual = c.empty();
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void linear_set::insert(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}
#endif  // LINEAR_SET_TEST_H_
