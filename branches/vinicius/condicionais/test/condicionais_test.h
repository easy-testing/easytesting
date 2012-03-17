// copyright 2012 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_FUNCOES_TEST_CONDICIONAIS_TEST_H_
#define TRUNK_FUNCOES_TEST_CONDICIONAIS_TEST_H_

#include <cmath>
#include <sstream>
#include <string>

#include "condicionais/src/condicionais.h"
#include "gtest/gtest.h"

namespace Teste {
TEST(Teste, Testa_menor) {
  int entrada_x = 2;
  int entrada_y = 3;
  int resposta = menor(entrada_x, entrada_y);
  int esperado = 2;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int menor(int x, int y); *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " << entrada_y << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_maior_entre_dois_numeros) {
  int entrada_x = 2;
  int entrada_y = 3;
  int resposta = maior(entrada_x, entrada_y);
  int esperado = 3;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int maior(int x, int y); *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " <<  entrada_y << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_maior_entre_tres_numeros) {
  int entrada_x = 2;
  int entrada_y = 3;
  int entrada_z = 10;
  int resposta = maior(entrada_x, entrada_y, entrada_z);
  int esperado = 10;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int maior(int x, int y, int z); *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", "
    << entrada_y << ", " << entrada_z << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_verifica_se_par) {
  int entrada_x = 2;
  bool resposta = par(entrada_x);
  bool esperado = true;
  ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool verifica_par_impar(int x) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

//
TEST(Teste, Testa_verifica_se_impar) {
  int entrada_x = 1;
  bool resposta = par(entrada_x);
  bool esperado = false;
  ASSERT_FALSE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool verifica_par_impar(int x) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_potenciacao) {
  int entrada_x = 2;
  int entrada_y = 3;
  int resposta = potenciacao(entrada_x, entrada_y);
  int esperado = 9;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int potenciacao(int x, int y) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " << entrada_y  << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_triangulo_equilatero) {
  float entrada_a = 5;
  float entrada_b = 5;
  float entrada_c = 5;

  bool resposta = equilatero(entrada_a, entrada_b, entrada_c);
  ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool equilatero(float a, float b, float c) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_a << ", "
    <<  entrada_b <<  ", " <<  entrada_c << "\n\n"
    << "   Resultado esperado:  " << true << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_triangulo_isosceles) {
  float entrada_a = 3;
  float entrada_b = 4;
  float entrada_c = 4;

  bool resposta = isosceles(entrada_a, entrada_b, entrada_c);
  ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* boll isosceles(float a, float b, float c) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_a << ", "
    <<  entrada_b  << ", " <<  entrada_c << "\n\n"
    << "   Resultado esperado:  " << true << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_triangulo_escaleno) {
  float entrada_a = 2;
  float entrada_b = 3;
  float entrada_c = 4;

  bool resposta = escaleno(entrada_a, entrada_b, entrada_c);

  ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool escaleno(float a, float b, float c) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_a << ", "
    <<  entrada_b << ", " <<  entrada_c << "\n\n"
    << "   Resultado esperado:  " << true << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_signo) {
  int dia = 3;
  int mes = 10;
  bool respo_bool;
  std::string resposta = signo(dia, mes);
  std::string esperado = "Libra";
  respo_bool = false;
  if (resposta == esperado) {
    respo_bool = true;
  }
  ASSERT_TRUE(respo_bool)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* string signo(int dia, int mes); *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << dia << ", " << mes << ", " << "\n\n"
    << "   Resultado esperado:  " << true << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
}  // end namespace

#endif  // TRUNK_FUNCOES_TEST_CONDICIONAIS_TEST_H_
