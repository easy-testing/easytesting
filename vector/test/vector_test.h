// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_VECTOR_TEST_VECTOR_TEST_H_
#define TRUNK_VECTOR_TEST_VECTOR_TEST_H_

#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/vector.h"
#include "../doctest/doctest.h"

using std::string;
using std::stringstream;


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

TEST_CASE("Testa_construtor_vazio") {
  vector atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: vector::vector()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Número de elementos no vetor maior que zero.\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_construtor_unitario") {
  vector atual(10);
  CHECK_EQ(10, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: vector::vector(int n)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" O vetor criado tem menos que n elementos.\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_vetor_vazio") {
  vector v;
  int esperado = 0;
  int atual = v.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int vector::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" v.sise() resultou em: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_vetor_nao_vazio") {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;
  int esperado = 2;
  int atual = v.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int vector::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" v.sise() resultou em: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Resize_aumentando_o_tamanho_do_vetor") {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(4);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;

  vector atual;
  atual = v;
  atual.resize(esperado.size());

  CHECK_EQ(esperado.size(), atual.size());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::resize(int n)\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.resize(" << esperado.size() << ")\" resultou em: ");
  INFO("v = " << ToString(atual) <<"\n");
  INFO(" O vetor v deveria ter ficado com " << esperado.size());
  INFO(" elementos." << "\n");
  INFO("------------------------------------------------------------------\n");

  for (int i = 0; i < v.size(); i++) {
    CHECK_EQ(array(esperado)[i], array(atual)[i]);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void vector::resize(int n)\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" v = " << ToString(v) << "\n");
    INFO(" \"v.resize(" << esperado.size() << ")\" resultou em: ");
    INFO("v = " << ToString(atual) <<"\n");
    INFO(" Os elementos que ja estavam em v deveriam ter sido mantidos." << "\n");
    INFO("------------------------------------------------------------------\n");
  }
}

TEST_CASE("Testa_Resize_diminuindo_o_tamanho_do_vetor") {
  vector v(4);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;
  array(v)[3] = 40;

  vector esperado(2);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;

  vector atual;
  atual = v;
  atual.resize(esperado.size());

  CHECK_EQ(esperado.size(), atual.size());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::resize(int n)\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.resize(" << esperado.size() << ")\" resultou em: ");
  INFO("v = " << ToString(atual) <<"\n");
  INFO(" O vetor v deveria ter ficado com " << esperado.size());
  INFO(" elementos." << "\n");
  INFO("------------------------------------------------------------------\n");

  for (int i = 0; i < esperado.size(); i++) {
    CHECK_EQ(array(esperado)[i], array(atual)[i]);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void vector::resize(int n)\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" v = " << ToString(v) << "\n");
    INFO(" \"v.resize(" << esperado.size() << ")\" resultou em: ");
    INFO("v = " << ToString(atual) <<"\n");
    INFO(" Os elementos que ja estavam em v deveriam ter sido mantidos." << "\n");
    INFO("------------------------------------------------------------------\n");
  }
}

TEST_CASE("Testa_operador_At_para_acesso") {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;
  VType esperado = 20;
  VType atual = v[1];
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType& vector::operator[](int i)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v[1]\" retornou: " << atual << "\n");
  INFO(" Resultado esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_At_para_atribuicao") {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;
  VType esperado = -2;
  v[1] = -2;
  VType atual = array(v)[1];
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType& vector::operator[](int i)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << "{ 10 20 30 }" << "\n");
  INFO(" \"v[1] = -2\" resultou em: v[1] = " << atual << "\n");
  INFO(" Resultado esperado: v[1] = " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_Assign") {
  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = 30;
  vector atual;
  atual = esperado;

  CHECK_NE(array(esperado), array(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::operator=(vector& v)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Não basta apenas copiar o ponteiro para os elementos de v. \n");
  INFO(" Você tem que copiar todos os elementos v para o vetor corrente.\n");
  INFO("-------------------------------------------------------------------\n");

  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::operator=(vector& v)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(esperado) << "\n");
  INFO(" \"u = v\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_push_back") {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = 30;

  vector atual;
  atual = v;
  atual.push_back(30);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::push_back(VType x)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.push_back(30)\" resultou em: v = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: v = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_pop_back") {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;

  vector esperado(2);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;

  vector atual;
  atual = v;
  atual.pop_back();
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::pop_back()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.pop_back()\" resultou em: v = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: v = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Insert_no_meio") {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = -7;
  array(esperado)[2] = 20;

  vector atual;
  atual = v;
  atual.insert(1, -7);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::insert(int index, VType x)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.insert(1, -7)\" resultou em: v = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: v = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Insert_no_fim") {
  vector v(2);
  array(v)[0] = 10;
  array(v)[1] = 20;

  vector esperado(3);
  array(esperado)[0] = 10;
  array(esperado)[1] = 20;
  array(esperado)[2] = -7;

  vector atual;
  atual = v;
  atual.insert(v.size(), -7);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::insert(int index, VType x)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.insert(v.size(), -7)\" resultou em: v = " << ToString(atual) <<"\n");
  INFO(" Resultado esperado: v = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Erase") {
  vector v(3);
  array(v)[0] = 10;
  array(v)[1] = 20;
  array(v)[2] = 30;

  vector esperado(2);
  array(esperado)[0] = 10;
  array(esperado)[1] = 30;

  vector atual;
  atual = v;
  atual.erase(1);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void vector::erase(int index)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" v = " << ToString(v) << "\n");
  INFO(" \"v.erase(1)\" resultou em: v = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: v = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_VECTOR_TEST_VECTOR_TEST_H_
