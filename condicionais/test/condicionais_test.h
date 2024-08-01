// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_CONDICIONAIS_TEST_CONDICIONAIS_TEST_H_
#define TRUNK_CONDICIONAIS_TEST_CONDICIONAIS_TEST_H_

#include <cmath>
#include <sstream>
#include <string>

#include "src/condicionais.h"
#include "../doctest/doctest.h"

namespace Teste {
TEST_CASE("Testa_menor") {
  int entrada_x = 2;
  int entrada_y = 3;
  int resposta = menor(entrada_x, entrada_y);
  int esperado = 2;
  CHECK_EQ(resposta, esperado);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* int menor(int x, int y); *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_x << ", " << entrada_y << "\n\n");
  INFO("   Resultado esperado:  " << esperado);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

TEST_CASE("Testa_maior_entre_tres_numeros") {
  int entrada_x = 2;
  int entrada_y = 10;
  int entrada_z = 3;
  int resposta = maior(entrada_x, entrada_y, entrada_z);
  int esperado = 10;
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* int maior(int x, int y, int z); *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_x << ", "
       << entrada_y << ", " << entrada_z << "\n\n");
  INFO("   Resultado esperado:  " << esperado);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
  CHECK_EQ(resposta, esperado);

}

TEST_CASE("Testa_verifica_se_par") {
  int entrada_x = 2;
  bool resposta = par(entrada_x);
  bool esperado = true;
  CHECK(resposta == esperado);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* bool verifica_par_impar(int x) *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_x << "\n\n");
  INFO("   Resultado esperado:  " << esperado);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

TEST_CASE("Testa_verifica_se_impar") {
  int entrada_x = 1;
  bool resposta = par(entrada_x);
  bool esperado = false;
  CHECK(resposta == esperado);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* bool verifica_par_impar(int x) *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_x << "\n\n");
  INFO("   Resultado esperado:  " << esperado);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

TEST_CASE("Testa_triangulo_equilatero") {
  float entrada_a = 5;
  float entrada_b = 5;
  float entrada_c = 5;

  bool resposta = equilatero(entrada_a, entrada_b, entrada_c);
  CHECK(resposta == true);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* bool equilatero(float a, float b, float c) *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_a << ", "
       << entrada_b <<  ", " <<  entrada_c << "\n\n");
  INFO("   Resultado esperado:  " << true);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

TEST_CASE("Testa_triangulo_isosceles") {
  float entrada_a = 3;
  float entrada_b = 4;
  float entrada_c = 4;

  bool resposta = isosceles(entrada_a, entrada_b, entrada_c);
  CHECK(resposta == true);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* bool isosceles(float a, float b, float c) *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_a << ", "
       <<  entrada_b  << ", " <<  entrada_c << "\n\n");
  INFO("   Resultado esperado:  " << true);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

TEST_CASE("Testa_triangulo_escaleno") {
  float entrada_a = 2;
  float entrada_b = 3;
  float entrada_c = 4;

  bool resposta = escaleno(entrada_a, entrada_b, entrada_c);
  CHECK(resposta == true);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* bool escaleno(float a, float b, float c) *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << entrada_a << ", "
       <<  entrada_b << ", " <<  entrada_c << "\n\n");
  INFO("   Resultado esperado:  " << true);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

TEST_CASE("Testa_signo") {
  int dia = 3;
  int mes = 10;
  std::string resposta = signo(dia, mes);
  std::string esperado = "Libra";
  CHECK(resposta == esperado);
  INFO("-------------------------------------------------------------------");
  INFO("Erro na funcao:  ");
  INFO("* std::string signo(int dia, int mes) *");
  INFO("-------------------------------------------------------------------");
  INFO("\nValores de entrada : " << dia << ", " << mes << ", " << "\n\n");
  INFO("   Resultado esperado:  " << esperado);
  INFO("   Resultado retornado: " << resposta);
  INFO("-------------------------------------------------------------------");
}

}  // namespace Teste

#endif  // TRUNK_CONDICIONAIS_TEST_CONDICIONAIS_TEST_H_
