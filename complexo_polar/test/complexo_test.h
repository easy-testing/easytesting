// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_COMPLEXO_POLAR_TEST_COMPLEXO_TEST_H_
#define TRUNK_COMPLEXO_POLAR_TEST_COMPLEXO_TEST_H_

#include "src/complexo.h"

#include <cmath>
#include <sstream>
#include <string>

#include <../doctest/doctest.h>

using std::string;
using std::stringstream;



double realTest(const Complexo& x) {
  return x.real();
}

double imagTest(const Complexo& x) {
  return x.imag();
}

double moduloTest(const Complexo& x){
  return x.modulo();
}

double argumentoTest(const Complexo& x){
  return x.argumento();
}

bool igual(const Complexo& x, const Complexo& y) {
  return fabs(moduloTest(x) - moduloTest(y)) <= 1E-6 &&
          fabs(sin(argumentoTest(x)) - sin(argumentoTest(y))) <= 1E-6 &&
          fabs(cos(argumentoTest(x)) - cos(argumentoTest(y))) <= 1E-6;
}

// Retorna string no formato [x + yi]
string ToString(const Complexo& z) {
  stringstream output;
  output << realTest(z);
  if (imagTest(z) >= 0.0) {
    output << " + " << imagTest(z) << "i";
  } else {
    output << " - " << -imagTest(z) << "i";
  }
  output << " --- " << moduloTest(z) << " " << argumentoTest(z);
  return output.str();
}

TEST_CASE("Testa_funcao_real") {
  double a = 1.1, b = 2.2;
  Complexo x(a,b);
  double esperado = 1.1;
  double atual = realTest(x);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"double Complexo::real()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo: " << ToString(x) << "\n\n");
  INFO("  Parte real esperada: " << esperado << "\n");
  INFO("  Parte real retornada: " << atual << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_imag") {
  Complexo x(0.1, 3.2);
  double atual = imagTest(x);
  double esperado = 3.2;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"double Complexo::imag()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo: " << ToString(x) << "\n\n");
  INFO("  Parte imaginaria esperada: " << esperado << "\n");
  INFO("  Parte imaginaria retornada: " << atual << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_construtor_sem_parametros") {
  Complexo atual;
  Complexo esperado(0, 0);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: \"Complexo::Complexo()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_construtor_com_um_paramentro") {
  Complexo atual(-13);
  Complexo esperado(-13, 0);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: \"Complexo::Complexo(double a)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_construtor_com_dois_paramentros") {
  Complexo atual(3.14, -1.4142);
  Complexo esperado(3.14, -1.4142);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: \"Complexo::Complexo(double a, double b)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_modulo_com_numero_complexo_nulo") {
  Complexo x(0, 0);
  double esperado = 0;
  double atual = x.modulo();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"double Complexo::modulo()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo: " << ToString(x) << "\n\n");
  INFO("  Valor esperado: " << esperado << "\n");
  INFO("  Valor retornado: " << atual << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_modulo_com_numero_complexo_nao_nulo") {
  Complexo x(3, 4);
  double esperado = 5;
  double atual = x.modulo();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"double Complexo::modulo()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo: " << ToString(x) << "\n\n");
  INFO("  Valor esperado: " << esperado << "\n");
  INFO("  Valor retornado: " << atual << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_igualdade_de_numeros_complexos_iguais") {
  Complexo x(3.14, -1.4142);
  Complexo y(3.14, -1.4142);
  CHECK_UNARY(x == y);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: true\n");
  INFO("  Resultado retornado: false\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_igualdade_de_numeros_complexos_distintos") {
  Complexo x(6.1, 8.5);
  Complexo y(4.2, 3.03);
  CHECK_UNARY_FALSE(x == y);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n");
  INFO("  Resultado esperado: false\n");
  INFO("  Resultado retornado: true\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_igualdade_de_numeros_diferentes_com_mesma_parte_real") {
  Complexo x(-3.56, 8.5);
  Complexo y(-3.56, 3.03);
  CHECK_UNARY_FALSE(x == y);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n");
  INFO("  Resultado esperado: false\n");
  INFO("  Resultado retornado: true\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_igualdade_de_numeros_diferentes_com_mesma_parte_imag") {
  Complexo x(5.36, -8.5);
  Complexo y(1.34, -8.5);
  CHECK_UNARY_FALSE(x == y);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: false\n");
  INFO("  Resultado retornado: true\n\n");
  INFO("-------------------------------------------------------------------\n");
}


TEST_CASE("Testa_atribuicao_de_numeros_complexos") {
  Complexo esperado(1.4142, -3.14);
  Complexo atual = esperado;
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: \"void Complexo::operator=(Complexo x)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_conjugado_de_numero_complexo_nulo") {
  Complexo x(0.0, 0.0);
  Complexo atual;
  atual = x.conjugado();
  Complexo esperado(0.0, 0.0);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::conjugado()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_conjugado_de_numero_com_parte_imaginaria_negativa") {
  Complexo x(1.0, -3.14);
  Complexo atual;
  atual = x.conjugado();
  Complexo esperado(1.0, 3.14);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::conjugado()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_conjugado_de_numero_com_parte_imaginaria_positiva") {
  Complexo x(1.0, 3.14);
  Complexo atual;
  atual = x.conjugado();
  Complexo esperado(1.0, -3.14);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::conjugado()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_simetrico_complexo_positivo") {
  Complexo x(1, 1);
  Complexo esperado(-1, -1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::simetrico()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_simetrico_complexo_negativo") {
  Complexo x(-1, -1);
  Complexo esperado(1, 1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::simetrico()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_simetrico_complexo_real_nula") {
  Complexo x(0, -1);
  Complexo esperado(0, 1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::simetrico()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_simetrico_complexo_imaginario_nula") {
  Complexo x(-1);
  Complexo esperado(1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::simetrico()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_inverso_de_numero_complexo") {
  Complexo x(6, 8);
  Complexo atual;
  atual = x.inverso();
  Complexo esperado(0.06, -0.08);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::inverso()\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero complexo esperado: " << ToString(esperado) << "\n");
  INFO("  Numero complexo retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_soma_de_numeros_complexos_nulos") {
  Complexo x(2, 3);
  Complexo y;
  Complexo atual = x + y;
  Complexo esperado(2, 3);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_soma_de_numeros_complexos_positivos") {
  Complexo x(4.1, 2.4);
  Complexo y(3.6, 1.5);
  Complexo atual = x + y;
  Complexo esperado(7.7, 3.9);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Somar_Numeros_Complexos_Negativos") {
  Complexo x(-4.1, -2.4);
  Complexo y(-3.6, -1.5);
  Complexo atual = x + y;
  Complexo esperado(-7.7, -3.9);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Somar_Numeros_Complexos_de_sinais_opostos") {
  Complexo x(-4.1, 2.4);
  Complexo y(3.6, -1.5);
  Complexo atual = x + y;
  Complexo esperado(-0.5, 0.9);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}
TEST_CASE("Subtrair_Numeros_Complexos_Nulos") {
  Complexo x(2.4, 1.1);
  Complexo y;
  Complexo atual = x - y;
  Complexo esperado(2.4, 1.1);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Subtrair_Numeros_Complexos_Positivos") {
  Complexo x(2.4, 1.1);
  Complexo y(3.5, 0.8);
  Complexo atual = x - y;
  Complexo esperado(-1.1, 0.3);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Subtrair_Numeros_Complexos_Negativos") {
  Complexo x(-3.5, -0.1);
  Complexo y(-2.2, -4.7);
  Complexo atual = x - y;
  Complexo esperado(-1.3, 4.6);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Subtrair_Numeros_Complexos_de_sinais_opostos") {
  Complexo x(-3.5, 0.1);
  Complexo y(3.5, -0.1);
  Complexo atual = x - y;
  Complexo esperado(-7.0, 0.2);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n");
  INFO("-------------------------------------------------------------------\n");
  INFO("  Numero Complexo 1: " << ToString(x) << "\n");
  INFO("  Numero Complexo 2: " << ToString(y) << "\n\n");
  INFO("  Resultado esperado: "  << ToString(esperado) << "\n");
  INFO("  Resultado retornado: " << ToString(atual) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Multiplicar_Numeros_Complexos_Nulos") {
  Complexo x(4.1, -2.4);
  Complexo y;
  Complexo z;
  x = y * z;
  Complexo esperado(0, 0);
  CHECK_UNARY(igual(esperado, x));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::operator*(Complexo)\"        \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Numero Complexo 1: " << ToString(y) << "\n");
  INFO(" Numero Complexo 2: " << ToString(z) << "\n\n");
  INFO(" Resposta retornada: " << ToString(x) << "\n");
  INFO(" Resposta esperada:  " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Multiplicar_Numeros_Complexos_mesmo_sinal") {
  Complexo y(4.1, 2.4);
  Complexo z(3.6, 1.5);
  Complexo atual = y * z;
  Complexo esperado(11.16, 14.79);
  CHECK_UNARY(igual(esperado, atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::operator*(Complexo)\"        \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Numero Complexo 1: " << ToString(y) << "\n");
  INFO(" Numero Complexo 2: " << ToString(z) << "\n\n");
  INFO(" Resposta retornada: " << ToString(atual) << "\n");
  INFO(" Resposta esperada:  " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Multiplicar_Numeros_Complexos_sinais_contrarios") {
  Complexo x;
  Complexo y(3.1, -2.4);
  Complexo z(-3.6, 1.8);
  x = y * z;
  Complexo esperado(-6.84, 14.22);
  CHECK_UNARY(igual(esperado, x));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::operator*(Complexo)\"        \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Numero Complexo 1: " << ToString(y) << "\n");
  INFO(" Numero Complexo 2: " << ToString(z) << "\n\n");
  INFO(" Resposta retornada: " << ToString(x) << "\n");
  INFO(" Resposta esperada:  " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Dividir_Numeros_Complexos_mesmo_sinal") {
  Complexo x;
  Complexo y(8, 1);
  Complexo z(4, 2);
  x = y / z;
  Complexo esperado(1.7, -0.6);
  CHECK_UNARY(igual(esperado, x));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::operator/(Complexo)\"        \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Numero Complexo 1: " << ToString(y) << "\n");
  INFO(" Numero Complexo 2: " << ToString(z) << "\n\n");
  INFO(" Resposta retornada: " << ToString(x) << "\n");
  INFO(" Resposta esperada:  " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Dividir_Numeros_Complexos_sinais_contrarios") {
  Complexo x;
  Complexo y(8, 5);
  Complexo z(-4, -2);
  x = y / z;
  Complexo esperado(-2.1, -0.2);
  CHECK_UNARY(igual(esperado, x));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:  \"Complexo Complexo::operator/(Complexo)\"        \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Numero Complexo 1: " << ToString(y) << "\n");
  INFO(" Numero Complexo 2: " << ToString(z) << "\n\n");
  INFO(" Resposta retornada: " << ToString(x) << "\n");
  INFO(" Resposta esperada:  " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}
#endif  // TRUNK_COMPLEXO_POLAR_TEST_COMPLEXO_TEST_H_
