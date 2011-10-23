// copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_FUNCOES3_TEST_FUNCOES_TEST_H_
#define BRANCHES_GABARITOS_FUNCOES3_TEST_FUNCOES_TEST_H_

#include <math.h>
#include <sstream>
#include <string>

#include "funcoes3/src/funcoes.h"
#include "gtest/gtest.h"

namespace Teste {

TEST(Teste, Calculo_area_trapezio) {
  float entrada[3] = {2.5, 7.5, 1.1};
  float resposta = area_trapezio(entrada[0], entrada[1], entrada[2]);
  float esperado = 5.5;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_trapezio(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Retorna_maior_comum) {
  float entrada[3] = {-3.69, 1.50, -2.40};
  float resposta = maior(entrada[0], entrada[1], entrada[2]);
  float esperado = 1.50;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float maior(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Retorna_maior_todos_iguais) {
  float entrada[3] = {1., 1., 1.};
  float resposta = maior(entrada[0], entrada[1], entrada[2]);
  float esperado = 1.;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float maior(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Formam_triangulo_true) {
  float entrada[3] = { 1.5, 2.5, 3.9};
  bool resposta = formam_triangulo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float formam_triangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Formam_triangulo_false) {
  float entrada[3] = { 1.5, 2.5, 4.1};
  bool resposta = formam_triangulo(entrada[0], entrada[1], entrada[2]);
  bool esperado = false;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float formam_triangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Formam_triangulo_limite) {
  float entrada[3] = { 1.5, 2.5, 4.0};
  bool resposta = formam_triangulo(entrada[0], entrada[1], entrada[2]);
  bool esperado = false;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float formam_triangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_area_triangulo) {
  float entrada[3] = { 5., 7., 8.};
  float resposta = area_triangulo(entrada[0], entrada[1], entrada[2]);
  float esperado = sqrt(10*(5.)*(3.)*(2.));
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_triangulo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Converte_grau_radianos) {
  float entrada = 10.;
  float resposta = graus_radianos(entrada);
  float esperado = 10*M_PI/180.;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float grau_radiano(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Converte_grauminutosegundo_grau) {
  float entrada[3] = {10.5, 25.5, 40.7};
  float resposta = grauminutosegundo_grau(entrada[0], entrada[1], entrada[2]);
  float esperado = entrada[0] + entrada[1]/60. + entrada[2]/3600.;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float grauminutosegundo_grau(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Soma_inteiros_ate_n) {
  float entrada = 100;
  float resposta = soma_progressao(entrada);
  float esperado = 5050;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float soma_progressao(int) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_x_do_y_maximo) {
  float entrada[3] = {-10.5, 20.1, 33.4};
  float resposta = xy_maximo(entrada[0], entrada[1], entrada[2]);
  float esperado = -entrada[1]/(2*entrada[0]);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float xy_maximo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0]
    << ", " << entrada[1] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_y_maximo) {
  float entrada[3] = {-10.5, 20.1, 33.4};
  float resposta = y_maximo(entrada[0], entrada[1], entrada[2]);
  float esperado = (4*entrada[0]*entrada[2]-entrada[1]*entrada[1])/(4*entrada[0]);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float y_maximo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Calculo_distancia_pontos) {
  float entrada[4] = { 1.2, 3.4, -5.6, -7.8};
  float resposta = distancia_pontos(entrada[0], entrada[1], entrada[2], entrada[3]);
  float dx = entrada[2]-entrada[0];
  float dy = entrada[3]-entrada[1];
  float esperado = sqrt(dx*dx + dy*dy);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float distancia_pontos(float, float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << ", " << entrada[3] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

}  // end namespace

#endif  // BRANCHES_GABARITOS_FUNCOES3_TEST_FUNCOES_TEST_H_
