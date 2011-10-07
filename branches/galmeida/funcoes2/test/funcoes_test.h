// copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES2_TEST_FUNCOES_TEST_H_
#define FUNCOES2_TEST_FUNCOES_TEST_H_

#include <math.h>
#include <sstream>
#include <string>

#include "funcoes2/src/funcoes.h"
#include "gtest/gtest.h"

namespace Teste {

TEST(Teste, Destino_disparo_vertical) {
  float entrada[3] = {0.0, 90.0, 10.0};
  float resposta = DestinoDisparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 0.0000;
  ASSERT_LE(fabs(resposta - esperado), 0.001)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float DestinoDisparo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Destino_disparo_positivo) {
  float entrada[3] = {0.0, 45.0, 10.0};
  float resposta = DestinoDisparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 10.0000;
  ASSERT_LE(fabs(resposta - esperado), 0.001)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float DestinoDisparo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Destino_disparo_negativo) {
  float entrada[3] = {0.0, 135.0, 10.0};
  float resposta = DestinoDisparo(entrada[0], entrada[1], entrada[2]);
  float esperado = -10.0000;
  ASSERT_LE(fabs(resposta - esperado), 0.001)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float DestinoDisparo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Destino_disparo_solo1) {
  float entrada[3] = {0.0, 0.0, 10.0};
  float resposta = DestinoDisparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 0.0000;
  ASSERT_LE(fabs(resposta - esperado), 0.001)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float DestinoDisparo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Destino_disparo_solo2) {
  float entrada[3] = {0.0, 180.0, 10.0};
  float resposta = DestinoDisparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 0.0000;
  ASSERT_LE(fabs(resposta - esperado), 0.001)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float DestinoDisparo(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Pertence_intervalo_limite_externo) {
  float entrada[3] = {-0.001, 0.0, 1.0};
  float resposta = PertenceIntervalo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool PertenceIntervalo(float , float , float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Pertence_intervalo_limite_interno) {
  float entrada[3] = {0.001, 0.0, 1.0};
  float resposta = PertenceIntervalo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool PertenceIntervalo(float , float , float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Pertence_intervalo_pontual) {
  float entrada[3] = {0.0, 0.0, 0.0};
  float resposta = PertenceIntervalo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool PertenceIntervalo(float , float , float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}
}  // end namespace
#endif  // FUNCOES2_TEST_FUNCOES_TEST_H_
