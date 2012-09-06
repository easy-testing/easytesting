// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_VECTOR_TEST_VECTOR_TEST_H_
#define TRUNK_VECTOR_TEST_VECTOR_TEST_H_

#include <sstream>
#include <string>
#include "vector/src/vector.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
  protected:
    string ToString(const vector& v) {
      stringstream s;
      s << "{ ";
      for (int i = 0; i < v.size_; i++) {
        s << v.array_[i] << " ";
      }
      s << "}";
      return s.str();
    }

    int size(const vector& v) {
      return v.size_;
    }

    VType* array(const vector& v) {
      return v.array_;
    }
};

TEST_F(Teste, Testa_construtor_vazio) {
  vector atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: vector::vector()\n"
    << "-------------------------------------------------------------------\n"
    << " Número de elementos no vetor maior que zero.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_construtor_unitario) {
  vector atual(10);
  ASSERT_EQ(10, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: vector::vector(int n)\n"
    << "-------------------------------------------------------------------\n"
    << " O vetor criado tem menos que n elementos.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_construtor_por_copia) {
  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = 30;
  vector atual(esperado);
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: vector::vector(vector& v)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(esperado) << "\n"
    << " vetor esperado = " << ToString(esperado) << "\n"
    << " vetor criado = " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_vetor_vazio) {
  vector v;
  int esperado = 0;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int vector::size()\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " v.sise() resultou em: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_vetor_nao_vazio) {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;
  int esperado = 2;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int vector::size()\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " v.sise() resultou em: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Resize_aumentando_o_tamanho_do_vetor) {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(4);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;

  vector atual(v);
  atual.resize(esperado.size());

  ASSERT_EQ(esperado.size(), atual.size())
    << "------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::resize(int n)\n"
    << "------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.resize(" << esperado.size() << ")\" resultou em: "
    << "v = " << ToString(atual) <<"\n"
    << " O vetor v deveria ter ficado com " << esperado.size()
    << " elementos." << "\n"
    << "------------------------------------------------------------------\n";

  for (int i = 0; i < v.size(); i++) {
    ASSERT_EQ(array(esperado)[i], array(atual)[i])
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void vector::resize(int n)\n"
      << "------------------------------------------------------------------\n"
      << " v = " << ToString(v) << "\n"
      << " \"v.resize(" << esperado.size() << ")\" resultou em: "
      << "v = " << ToString(atual) <<"\n"
      << " Os elementos que ja estavam em v deveriam ter sido mantidos." << "\n"
      << "------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Testa_Resize_diminuindo_o_tamanho_do_vetor) {
  vector v(4);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;
  array(v)[3] = 40;

  vector esperado(2);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;

  vector atual(v);
  atual.resize(esperado.size());

  ASSERT_EQ(esperado.size(), atual.size())
    << "------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::resize(int n)\n"
    << "------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.resize(" << esperado.size() << ")\" resultou em: "
    << "v = " << ToString(atual) <<"\n"
    << " O vetor v deveria ter ficado com " << esperado.size()
    << " elementos." << "\n"
    << "------------------------------------------------------------------\n";

  for (int i = 0; i < esperado.size(); i++) {
    ASSERT_EQ(array(esperado)[i], array(atual)[i])
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void vector::resize(int n)\n"
      << "------------------------------------------------------------------\n"
      << " v = " << ToString(v) << "\n"
      << " \"v.resize(" << esperado.size() << ")\" resultou em: "
      << "v = " << ToString(atual) <<"\n"
      << " Os elementos que ja estavam em v deveriam ter sido mantidos." << "\n"
      << "------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Testa_operador_At_para_acesso) {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;
  VType esperado = 20;
  VType atual = v[1];
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType& vector::operator[](int i)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v[1]\" retornou: " << atual << "\n"
    << " Resultado esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_At_para_atribuicao) {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;
  VType esperado = -2;
  v[1] = -2;
  VType atual = array(v)[1];
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType& vector::operator[](int i)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << "{ 10 20 30 }" << "\n"
    << " \"v[1] = -2\" resultou em: v[1] = " << atual << "\n"
    << " Resultado esperado: v[1] = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = 30;
  vector atual;
  atual = esperado;

  ASSERT_NE(array(esperado), array(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::operator=(vector& v)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para os elementos de v. \n"
    << " Você tem que copiar todos os elementos v para o vetor corrente.\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::operator=(vector& v)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(esperado) << "\n"
    << " \"u = v\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_push_back) {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = 30;

  vector atual(v);
  atual.push_back(30);
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::push_back(VType x)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.push_back(30)\" resultou em: v = " << ToString(atual) << "\n"
    << " Resultado esperado: v = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_pop_back) {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;

  vector esperado(2);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;

  vector atual(v);
  atual.pop_back();
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::pop_back()\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.pop_back()\" resultou em: v = " << ToString(atual) << "\n"
    << " Resultado esperado: v = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_no_meio) {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = -7;
  array(esperado)[2] = 20;

  vector atual(v);
  atual.insert(1, -7);
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::insert(int index, VType x)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.insert(1, -7)\" resultou em: v = " << ToString(atual) << "\n"
    << " Resultado esperado: v = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_no_fim) {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = -7;

  vector atual(v);
  atual.insert(v.size(), -7);
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::insert(int index, VType x)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.insert(v.size(), -7)\" resultou em: v = " << ToString(atual) <<"\n"
    << " Resultado esperado: v = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Erase) {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;

  vector esperado(2);
  array(esperado)[0] = 10;
  array(esperado)[1] = 30;

  vector atual(v);
  atual.erase(1);
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void vector::erase(int index)\n"
    << "-------------------------------------------------------------------\n"
    << " v = " << ToString(v) << "\n"
    << " \"v.erase(1)\" resultou em: v = " << ToString(atual) << "\n"
    << " Resultado esperado: v = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_VECTOR_TEST_VECTOR_TEST_H_
