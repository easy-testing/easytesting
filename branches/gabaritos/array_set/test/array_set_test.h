// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_TEST_SET_TEST_H_
#define SET_TEST_SET_TEST_H_

#include "array_set/src/array_set.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaSet(array_set<int> &c, int n, int v[]) {
    for (int i = 0; i < n; ++i) {
      c.insert(v[i]);
    }
  }

  void ToList(array_set<int> &c, list<int>*l) {
    for (int i = 0; i < c.size(); i++) {
      l->push_back(c.v_[i]);
    }
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string PrintSet(array_set<int> &c) {
    stringstream out;
    list<int> l;
    if (c.empty()) {
      return "Conjunto Vazio";
    } else {
      ToList(c, &l);
      SortList(&l);
      out << "{ ";
      for (Node<int>* it = l.begin(); it != l.end(); it = it->next) {
        out << it->key << " ";
      }
      out << "}";
      return out.str();
    }
  }

  void SortList(list<int>* l) {
    list<int> aux = *l;
    l->clear();
    while (aux.size() > 0) {
      Node<int>* min = aux.begin();
      for (Node<int>* it = aux.begin(); it != aux.end(); it = it->next) {
        if (it->key < min->key) {
          min = it;
        }
      }
      l->push_back(min->key);
      aux.erase(min);
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
      for (Node<int>* it = l.begin(); it != l.end(); it = it->next) {
        out << it->key << " ";
      }
      out << "]";
      return out.str();
    }
  }
};

TEST_F(Teste, Testar_Construtor_por_copia_vazio) {
  array_set<int> c;
  c.clear();
  array_set<int> d(c);
  string atual = PrintSet(c);
  string esperado = PrintSet(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* ~array_set<Type>::array_set(array_set<Type> c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_varios_elementos) {
  array_set<int> c;
  int v[5] = {1, 3, 5, 8, 2};
  CriaSet(c, 5, v);
  array_set<int> d(c);
  string atual = PrintSet(c);
  string esperado = PrintSet(d);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* ~array_set<Type>::array_set(array_set<Type> c) *\n"
    << "-------------------------------------------------------------------\n"
    << "Construtor por copia nao criou conjunto igual ao parametro passado\n\n"
    << "  Conjunto esperado: " << esperado << "\n"
    << "  Conjunto criado:   " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_vazio) {
  array_set<int> c;
  ASSERT_TRUE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto esta vazio e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_empty_em_conjunto_unitario) {
  array_set<int> c;
  int v[] = {3};
  CriaSet(c, 1, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_empty_em_conjunto_com_varios_elementos) {
  array_set<int> c;
  int v[] = {3, 8, 5, 6, 4, 7};
  CriaSet(c, 6, v);
  ASSERT_FALSE(c.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "O conjunto possui varios elementos e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_vazio) {
  array_set<int> c;
  int esperado = 0;
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int array_set<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_unitario) {
  array_set<int> c;
  int esperado = 1;
  int v[] = {3};
  CriaSet(c, 1, v);
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int array_set<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_conjunto_com_varios_elementos) {
  array_set<int> c;
  int esperado = 3;
  int v[] = {3, 0, 4};
  CriaSet(c, 3, v);
  int atual = c.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int array_set<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_min_conjunto_unitario) {
  array_set<int> c;
  c.insert(3);
  int esperado = 3;
  int atual = c.min();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Type array_set<Type>::min() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto : " << PrintSet(c) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_min_conjunto_com_varios_elementos_iguais) {
  array_set<int> c;
  int v[4] = {2, 2, 2, 2};
  CriaSet(c, 4, v);
  int esperado = 2;
  int atual = c.min();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Type array_set<Type>::min() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto : " << PrintSet(c) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_min_conjunto_com_varios_elementos_distintos) {
  array_set<int> c;
  int v[4] = {2, 4, 8, -2};
  CriaSet(c, 4, v);
  int esperado = -2;
  int atual = c.min();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Type array_set<Type>::min() *\n"
    << "-------------------------------------------------------------------\n"
    << "Conjunto : " << PrintSet(c) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_vazio) {
  array_set<int> c;
  bool atual = c.find(4);
  ASSERT_FALSE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::find(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou TRUE para a procura de um elemento nao\n"
    << "contido no conjunto\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_find_em_conjunto_com_varios_elementos) {
  array_set<int> c;
  int v[] = {3, 5, 8, 15};
  int procurado = 4;
  CriaSet(c, 4, v);
  bool atual = c.find(procurado);
  ASSERT_FALSE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::find(Type x) *\n"
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
    << "* bool array_set<Type>::find(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Funcao retornou FALSE para a procura de um elemento\n"
    << "contido no conjunto\n"
    << " Conjunto: " << PrintSet(c) << "\n"
    << " Elemento procurado: " << procurado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_em_conjunto_vazio) {
  array_set<int> c;
  string esperado = "{ 4 }";
  c.insert(4);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 1;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_nao_contido_em_conjunto) {
  array_set<int> c;
  string esperado = "{ 4 5 7 8 }";
  int v[] = {4, 5, 7};
  CriaSet(c, 3, v);
  int inserir = 8;
  c.insert(inserir);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::insert(Type x) *\n"
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
    << "* void array_set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função inseriu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_para_elemento_contido_em_conjunto) {
  array_set<int> c;
  string esperado = "{ 1 3 4 5 }";
  int v[] = {4, 5, 1, 3};
  CriaSet(c, 4, v);
  int inserir = 5;
  c.insert(inserir);
  string atual = PrintSet(c);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::insert(Type x) *\n"
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
    << "* void array_set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função corretamente nao inseriu um elemento no conjunto pois ja\n"
    << " possuia o elemento porem alterou o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_unitario_com_exito) {
  array_set<int> c;
  int apagar = 4;
  c.insert(apagar);
  string anterior = PrintSet(c);
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = "Conjunto Vazio";
  int size_esperado = 0;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_TRUE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
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
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_unitario_elemento_sem_exito) {
  array_set<int> c;
  int apagar = 4;
  c.insert(apagar + 1);
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
    << "* bool array_set<Type>::erase(Type x) *\n"
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
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_com_exito) {
  array_set<int> c;
  int v[] = {4, 6, 7, 8};
  CriaSet(c, 4, v);
  string anterior = PrintSet(c);
  int apagar = 4;
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = "{ 6 7 8 }";
  int size_esperado = 3;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_TRUE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
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
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_conjunto_com_varios_elementos_sem_exito) {
  array_set<int> c;
  int v[] = {4, 6, 7, 8};
  CriaSet(c, 4, v);
  string anterior = PrintSet(c);
  int apagar = 5;
  bool teste = c.erase(apagar);
  string atual = PrintSet(c);
  string esperado = anterior;
  int size_esperado = 4;
  int size_atual = c.size();

  // Testa retorno da função
  ASSERT_FALSE(teste)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
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
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "  Conjunto formado: " << atual << "\n"
    << "  Elemento apagado: " << apagar << "\n"
    << "-------------------------------------------------------------------\n";

  // Testar tamanho do novo conjunto
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool array_set<Type>::erase(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função removeu corretamente um elemento no conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_Tolist_em_conjunto_vazio) {
  array_set<int> c;
  list<int> l;
  string esperado = "Lista Vazia";
  ToList(c, &l);
  string atual = PrintList(l);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::ToList(list<Type>& l) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto inicial: " << PrintSet(c) << "\n"
    << "   Lista esperada: " << esperado << "\n"
    << "    Lista formada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_Tolist_em_conjunto_unitario) {
  array_set<int> c;
  list<int> l;
  string esperado = "[ 6 ]";
  int v[] = {6};
  CriaSet(c, 1, v);
  ToList(c, &l);
  string atual = PrintList(l);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::ToList(list<Type>& l) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto inicial: " << PrintSet(c) << "\n"
    << "   Lista esperada: " << esperado << "\n"
    << "    Lista formada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_Tolist_em_conjunto_com_varios_elementos) {
  array_set<int> c;
  list<int> l;
  string esperado = "[ 6 7 8 ]";
  int v[] = {6, 7, 8};
  CriaSet(c, 3, v);
  ToList(c, &l);
  string atual = PrintList(l);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::ToList(list<Type>& l) *\n"
    << "-------------------------------------------------------------------\n"
    << " Conjunto inicial: " << PrintSet(c) << "\n"
    << "   Lista esperada: " << esperado << "\n"
    << "    Lista formada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_vazio) {
  array_set<int> c;
  c.clear();
  int atual = c.empty();
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_em_conjunto_com_varios_elementos) {
  array_set<int> c;
  int v[] = {10, 5, 9};
  CriaSet(c, 3, v);
  c.clear();
  int atual = c.empty();
  ASSERT_TRUE(atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Apos executar a funcao clear() o teste acusou haver\n"
    << "um ou mais elementos no conjunto\n"
    << "-------------------------------------------------------------------\n";
  int size_esperado = 0;
  int size_atual = c.size();
  ASSERT_EQ(size_esperado, size_atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void array_set<Type>::insert(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << " A função limpou corretamente o conteudo do conjunto porem\n"
    << " nao alterou corretamente o valor do tamanho do conjunto\n\n"
    << "  Tamanho Esperado: " << size_esperado << "\n"
    << " Tamanho Retornado: " << size_atual << "\n"
    << "-------------------------------------------------------------------\n";
}
#endif  // SET_TEST_SET_TEST_H_
