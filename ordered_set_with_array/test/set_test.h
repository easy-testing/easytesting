// Copyright 2013 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_WITH_ARRAY_TEST_SET_TEST_H_
#define TRUNK_ORDERED_SET_WITH_ARRAY_TEST_SET_TEST_H_

#include <cmath>
#include <cstdlib>
#include <queue>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "ordered_set_with_array/src/set.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  int size(set* s) {
    return s->size_;
  }

  SType* array(set* s) {
    return s->array_;
  }

  SType* begin(set* s) {
    return &(s->array_[0]);
  }

  SType* end(set* s) {
    return &(s->array_[s->size_ - 1]) + 1;
  }

  set* New0() {
    set* s = new set;
    s->size_ = 0;
    s->array_ = NULL;
    return s;
  }

  set* New1(SType a) {
    set* s = new set;
    s->size_ = 1;
    s->array_ = new SType[s->size_];
    s->array_[0] = a;
    return s;
  }

  set* New2(SType a, SType b) {
    set* s = new set;
    s->size_ = 2;
    s->array_ = new SType[s->size_];
    s->array_[0] = a;
    s->array_[1] = b;
    return s;
  }

  set* New3(SType a, SType b, SType c) {
    set* s = new set;
    s->size_ = 3;
    s->array_ = new SType[s->size_];
    s->array_[0] = a;
    s->array_[1] = b;
    s->array_[2] = c;
    return s;
  }

  set* New4(SType a, SType b, SType c, SType d) {
    set* s = new set;
    s->size_ = 4;
    s->array_ = new SType[s->size_];
    s->array_[0] = a;
    s->array_[1] = b;
    s->array_[2] = c;
    s->array_[3] = d;
    return s;
  }

  void DeleteSet(set* s) {
    delete [] s->array_;
    s->size_ = 0;
    s->array_ = NULL;
    delete s;
  }

  // Retorna uma string contendo os elementos do conjunto
  // no formato { c1 c2 c3 c4 } e ordenados do maior para o menor.
  string ToString(set* s) {
    stringstream out;
    out << "{ ";
    for (int i = 0; i < s->size_; i++) {
      out << s->array_[i] << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  set* s = New0();
  ASSERT_EQ(0, size(s))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_vazio) {
  set* s = New0();
  ASSERT_TRUE(s->empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_nao_vazio) {
  set* s = New3("1", "2", "3");
  ASSERT_FALSE(s->empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_vazio) {
  set* s = New0();
  int esperado = 0;
  int atual = size(s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_nao_vazio) {
  set* s = New3("1", "2", "3");
  int atual = size(s);
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_belongs_em_conjunto_vazio) {
  set* s = New0();
  bool atual = s->belongs("3");
  bool esperado = false;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: bool set::belongs(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.belongs(3)\" retornou: true \n"
    << " Valor esperado: false\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_belongs_retornando_true) {
  set* s = New4("1", "2", "3", "4");
  bool atual = s->belongs("3");
  bool esperado = true;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: bool set::belongs(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.belongs(3)\" retornou: false \n"
    << " Valor esperado: true \n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_belongs_retornando_false) {
  set* s = New4("1", "2", "4", "5");
  bool atual = s->belongs("3");
  bool esperado = false;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: bool set::belongs(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.belongs(3)\" retornou: true \n"
    << " Valor esperado: false\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert) {
  set* s = New0();
  s->insert("9");
  int atual = size(s);
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
   DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_vazio) {
  set* s = New0();
  s->insert("9");
  string atual = ToString(s);
  string esperado = "{ 9 }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_nao_vazio) {
  set* s = New3("1", "3", "4");
  s->insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 3 4 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_insert_com_elemento_repetido) {
  set* s = New3("1", "2", "3");
  s->insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_decremento_do_size_na_funcao_erase) {
  set* s = New1("9");
  s->erase("9");
  int atual = size(s);
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_unitario) {
  set* s = New1("9");
  s->erase("9");
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_com_mais_de_um_elemento) {
  set* s = New4("1", "2", "3", "4");
  s->erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4} \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_pertence_ao_conjunto) {
  set* s = New4("1", "2", "3", "4");
  s->erase("5");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4 } \n"
      << " \"s.erase(5)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_valor_dos_membros_apos_clear) {
  set* s = New3("1", "2", "3");
  s->clear();
  ASSERT_EQ(0, size(s))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::clear() \n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_clear) {
  set* s = New3("1", "2", "3");
  s->clear();
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.clear()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
  DeleteSet(s);
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_vazio) {
  set* s = New3("1", "2", "3");
  set* u = New0();
  *u = *s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
  DeleteSet(u);
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_nao_vazio) {
  set* s = New3("1", "2", "3");
  set* u = New3("4", "5", "6");
  *u = *s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ 4 5 6 }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
  DeleteSet(s);
  DeleteSet(u);
}

#endif  // TRUNK_ORDERED_SET_WITH_ARRAY_TEST_SET_TEST_H_
