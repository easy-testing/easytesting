// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef VECTOR_TEST_VECTOR_TEST_H_
#define VECTOR_TEST_VECTOR_TEST_H_

#include <sstream>
#include <string>
#include "vector/src/vector.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
  protected:
    string MostrarPorExtenso(vector& fv) {
      stringstream s;
      for (int i = 0; i < fv.size_; i++) {
        s << fv.array_[i] << " ";
      }
      return s.str();
    }
    void Inicializar(int n, float v[], vector* fv) {
      fv->size_ = n;
      delete [] fv->array_;
      fv->array_ = new float[n];
      for (int i = 0; i < n; i++) {
        fv->array_[i] = v[i];
      }
    }
    float at(vector* fv, int i) {
      return fv->array_[i];
    }
};

TEST_F(Teste, Testa_funcao_size_vetor_tamanho_um) {
  float vetor_v[] = {6.2};
  vector v;
  Inicializar(1, vetor_v, &v);
  int esperado = 1;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int vector::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 6.2\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_vetor_tamanho_cinco) {
  float vetor_v[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  vector v;
  Inicializar(5, vetor_v, &v);
  int esperado = 5;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int vector::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0 2.0 3.0 4.0 5.0\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_tamanho_vetor_iniciado_vazio) {
  vector v;
  int esperado = 0;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* vector::vector() *\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: (vazio) \n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "      Certifique-se de que o vetor eh inicializado com tamanho 0\n"
    << "      quando nao houver parametro.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_tamanho_vetor_iniciado_nao_vazio) {
  vector v(5);
  int esperado = 5;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* vector::vector(int n) *\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: (cinco elementos indefinidos)\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "      Certifique-se de que o vetor eh inicializado com tamanho n\n"
    << "      quando houver parametro n elementos.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_tamanho_vetor_iniciado_parametro_outro_vetor) {
  float vetor_v[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  vector v2;
  Inicializar(5, vetor_v, &v2);
  vector v(v2);
  int esperado = 5;
  int atual = v.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* vector::vector(vector& v) *\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0 2.0 3.0 4.0 5.0\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "      Certifique-se de que o vetor eh inicializado com tamanho igual\n"
    << "      ao tamanho do vetor parametro.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Verifica_se_na_funcao_resize_valores_sao_mantidos) {
  float vetor_v[] = {2.0};
  vector v;
  Inicializar(1, vetor_v, &v);
  int esperado = 2;
  v.resize(4);
  ASSERT_EQ(esperado, at(&v, 0))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void vector::resize(int n) *\n"
    << "-------------------------------------------------------------------\n"
    << "      A funcao resize nao manteve os valores antigos do vetor.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Verifica_tamanho_em_push_back) {
  float vetor_v[] = {1.0, 2.0};
  vector v;
  Inicializar(2, vetor_v, &v);
  int esperado = 3;
  v.push_back(3.0);
  int atual = v.size();
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void vector::push_back(float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0 2.0 3.0\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "      Certifique-se de que o tamanho é atualizado depois de dar um\n"
    << "      push_back.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Verifica_tamanho_em_pop_back) {
  float vetor_v[] = {1.0, 2.0};
  vector v;
  Inicializar(2, vetor_v, &v);
  int esperado = 1;
  v.pop_back();
  int atual = v.size();
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void vector::pop_back() *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "      Certifique-se de que o tamanho é atualizado depois de dar um\n"
    << "      pop_back.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Verifica_tamanho_em_clear) {
  float vetor_v[] = {1.0, 2.0};
  vector v;
  Inicializar(2, vetor_v, &v);
  int esperado = 0;
  v.clear();
  int atual = v.size();
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void vector::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: (vazio)\n\n"
    << "      Tamanho esperado: " << esperado << "\n"
    << "      Tamanho retornado: " << atual << "\n"
    << "      Certifique-se de que o tamanho é atualizado depois de dar um\n"
    << "      clear.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_novos_valores_nas_posicoes) {
  float vetor_v[] = {1.0, 2.0, 3.0};
  vector v;
  Inicializar(3, vetor_v, &v);
  int esperado = 3;
  v.erase(1);
  ASSERT_EQ(at(&v, 1), esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void vector::erase(int index) *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0 3.0\n\n"
    << "      Valor na posicao 1 esperado: " << esperado << "\n"
    << "      Valor na posicao 1 retornado: " << at(&v, 1) << "\n"
    << "      Certifique-se de atualizar os valores nas posicoes corretas.\n"
    << "      O novo valor da posicao 1 corresponde a 3.0 nesse exemplo.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_novos_valores_nas_posicoes) {
  float vetor_v[] = {1.0, 3.0, 4.0};
  vector v;
  Inicializar(3, vetor_v, &v);
  int esperado = 3.0;
  v.insert(1, 2.0);
  ASSERT_EQ(at(&v, 2), esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void vector::insert(int index, float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0 2.0 3.0 4.0\n\n"
    << "      Valor na posicao 2 esperado: " << esperado << "\n"
    << "      Valor na posicao 2 retornado: " << at(&v, 2) << "\n"
    << "      Certifique-se de atualizar os valores nas posicoes corretas.\n"
    << "      O novo valor da posicao 2 corresponde a 3.0 nesse exemplo.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty) {
  float vetor_v[] = {1.0, 2.0, 3.0};
  vector v1;
  Inicializar(3, vetor_v, &v1);
  vector v2;
  ASSERT_FALSE(v1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool vector::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: 1.0 2.0 3.0\n\n"
    << "      O vetor nao esta vazio porem a funcao empty retorna true.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_TRUE(v2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool vector::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "-------------------------------------------------------------------\n"
    << "      Vetor Float: (vazio)\n\n"
    << "      O vetor esta vazio porem a funcao empty retorna false.\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // VECTOR_TEST_VECTOR_TEST_H_
