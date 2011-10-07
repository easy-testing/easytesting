// copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES3_TEST_FUNCOES_TEST_H_
#define FUNCOES3_TEST_FUNCOES_TEST_H_

#include <math.h>
#include <sstream>
#include <string>

#include "funcoes3/src/funcoes.h"
#include "gtest/gtest.h"

namespace Teste {

TEST(Teste, Calculo_area_trapezio) {
  float entrada[3] = {2.5, 7.5, 1.1};
  float resposta = AreaTrapezio(entrada[0], entrada[1], entrada[2]);
  float esperado = 5.5;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float AreaTrapezio(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Retorna_maior_comum) {
  float entrada[3] = {-3.69, 1.50, -2.40};
  float resposta = Maior(entrada[0], entrada[1], entrada[2]);
  float esperado = 1.50;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Maior(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Retorna_maior_todos_iguais) {
  float entrada[3] = {1.0, 1.0, 1.0};
  float resposta = Maior(entrada[0], entrada[1], entrada[2]);
  float esperado = 1.0;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Maior(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Formam_triangulo_true) {
  float entrada[3] = { 1.5, 2.5, 3.9};
  bool resposta = FormamTriangulo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool FormamTriangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Formam_triangulo_false) {
  float entrada[3] = { 1.5, 2.5, 4.1};
  bool resposta = FormamTriangulo(entrada[0], entrada[1], entrada[2]);
  bool esperado = false;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool FormamTriangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Formam_triangulo_limite) {
  float entrada[3] = { 1.5, 2.5, 4.0};
  bool resposta = FormamTriangulo(entrada[0], entrada[1], entrada[2]);
  bool esperado = false;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool FormamTriangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_area_triangulo) {
  float entrada[3] = { 5.0, 7.0, 8.0};
  float resposta = AreaTriangulo(entrada[0], entrada[1], entrada[2]);
  float esperado = sqrt(10 * 5.0 * 3.0 * 2.0);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float AreaTriangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, GrausRadianos) {
  float entrada = 10.0;
  float resposta = GrausRadianos(entrada);
  float esperado = 10 * M_PI / 180.;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float GrausRadiano(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValor de entrada : " << entrada << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Converte_SexagenalDecimal) {
  float entrada[3] = {10.5, 25.5, 40.7};
  float resposta = SexagenalDecimal(entrada[0], entrada[1], entrada[2]);
  float esperado = entrada[0] + entrada[1] / 60.0 + entrada[2] / 3600.0;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float SexagenalDecimal(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, SomaMenoresOuIguais) {
  int entrada = 100;
  int resposta = SomaMenoresOuIguais(entrada);
  int esperado = 5050;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int SomaMenoresOuIguais(int) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValor de entrada : " << entrada << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_XParaYMaximo) {
  float entrada[3] = {-10.5, 20.1, 33.4};
  float resposta = XParaYMaximo(entrada[0], entrada[1], entrada[2]);
  float esperado = -entrada[1] / (2 * entrada[0]);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float XParaYMaximo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_YMaximo) {
  float entrada[3] = {-10.5, 20.1, 33.4};
  float resposta = YMaximo(entrada[0], entrada[1], entrada[2]);
  float auxiliar = 4 * entrada[0] * entrada[2] - entrada[1] * entrada[1];
  float esperado = auxiliar / (4*entrada[0]);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float YMaximo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_distancia_pontos) {
  float entrada[4] = { 1.2, 3.4, -5.6, -7.8};
  float resposta = DistanciaPontos(entrada[0],
                                   entrada[1],
                                   entrada[2],
                                   entrada[3]);
  float dx = entrada[2] - entrada[0];
  float dy = entrada[3] - entrada[1];
  float esperado = sqrt(dx * dx + dy * dy);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float DistanciaPontos(float, float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << ", " << entrada[3] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

}  // end namespace

#endif  // FUNCOES3_TEST_FUNCOES_TEST_H__
