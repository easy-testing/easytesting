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
TEST(Teste, Testa_verifica_sinal_negativo) {
  int entrada_x = -1;
  bool resposta = verifica_sinal(entrada_x);
  bool esperado = false;
  ASSERT_FALSE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool verifica_sinal(int x) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_verifica_sinal_positivo) {
  int entrada_x = 10;
  bool resposta = verifica_sinal(entrada_x);
  bool esperado = true;
  ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool verifica_sinal(int x) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_verifica_se_par) {
  int entrada_x = 2;
  bool resposta = verifica_par_impar(entrada_x);
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
  bool resposta = verifica_par_impar(entrada_x);
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
TEST(Teste, Testa_divisao) {
  int entrada_x = 8;
  int entrada_y = 2;
  int r;
  int resposta = divisao(entrada_x, entrada_y, r);
  int resposta2 = r;
  int esperado = 4;
  int esperado2 = true;
  ASSERT_EQ(resposta2, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool divisao(int a, int b, int &r) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " <<entrada_y  << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";

ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool divisao(int a, int b, int &r) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " << entrada_y  << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_divisao_por_zero) {
  int entrada_x = 8;
  int entrada_y = 0;
  int r = -1;
  int resposta = divisao(entrada_x, entrada_y, r);
  int resposta2 = r;
  int esperado = -1;
  bool esperado2 = false;
  ASSERT_EQ(resposta2, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool divisao(int a, int b, int &r) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " << entrada_y  << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";

ASSERT_FALSE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool divisao(int a, int b, int &r) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_x << ", " << entrada_y  << "\n\n"
    << "   Resultado esperado:  " << esperado2 << "\n"
    << "   Resultado retornado: " << resposta2 << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_triangulo_equilatero) {
  int entrada_a = 4;
  int entrada_b = 4;
  int entrada_c = 4;

   int resposta = tipo_triangulo(entrada_a, entrada_b, entrada_c);
  int esperado = 1;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int tipo_triangulo(int a, int b, int c) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_a << ", "
    <<  entrada_b <<  ", " <<  entrada_c << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_triangulo_isosceles) {
  int entrada_a = 3;
  int entrada_b = 4;
  int entrada_c = 4;

  int resposta = tipo_triangulo(entrada_a, entrada_b, entrada_c);
  int esperado = 2;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int tipo_triangulo(int a, int b, int c) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_a << ", "
    <<  entrada_b  << ", " <<  entrada_c << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
//
TEST(Teste, Testa_triangulo_escaleno) {
  int entrada_a = 2;
  int entrada_b = 3;
  int entrada_c = 4;

  int resposta = tipo_triangulo(entrada_a, entrada_b, entrada_c);
  int esperado = 3;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int tipo_triangulo(int a, int b, int c) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada_a << ", "
    <<  entrada_b << ", " <<  entrada_c << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
}  // end namespace

#endif  // TRUNK_FUNCOES_TEST_CONDICIONAIS_TEST_H_
