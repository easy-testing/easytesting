// copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES_TEST_FUNCOES_TEST_H_
#define FUNCOES_TEST_FUNCOES_TEST_H_

#include <math.h>
#include <sstream>
#include <string>

#include "funcoes/src/funcoes.h"
#include "gtest/gtest.h"

namespace Teste {

TEST(Teste, Destino_disparo_vertical) {
  float entrada[3] = {0.0, 90.0, 10.0};
  float resposta = Destino_disparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 0.0000;
  ASSERT_LE( fabs(resposta-esperado) , 0.0001 )
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}



TEST(Teste, Destino_disparo_positivo) {
  float entrada[3] = {0.0, 45.0, 10.0};
  float resposta = Destino_disparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 10.0000;
  ASSERT_LE( fabs(resposta-esperado) , 0.0001 )
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}



TEST(Teste, Destino_disparo_negativo) {
  float entrada[3] = {0.0, 135.0, 10.0};
  float resposta = Destino_disparo(entrada[0], entrada[1], entrada[2]);
  float esperado = -10.0000;
  ASSERT_LE( fabs(resposta-esperado) , 0.0001 )
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}


TEST(Teste, Destino_disparo_solo1) {
  float entrada[3] = {0.0, 0.0, 10.0};
  float resposta = Destino_disparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 0.0000;
  ASSERT_LE( fabs(resposta-esperado) , 0.0001 )
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}

TEST(Teste, Destino_disparo_solo2) {
  float entrada[3] = {0.0, 180.0, 10.0};
  float resposta = Destino_disparo(entrada[0], entrada[1], entrada[2]);
  float esperado = 0.0000;
  ASSERT_LE( fabs(resposta-esperado) , 0.0001 )
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}


TEST(Teste, Pertence_intervalo_limite_externo) {
  float entrada[3] = {-0.1, 0.0, 1.0};
  float resposta = Pertence_intervalo(entrada[0], entrada[1], entrada[2]);
  bool esperado = false;
  ASSERT_EQ(resposta,esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}


TEST(Teste, Pertence_intervalo_limite_interno) {
  float entrada[3] = {-0.09, 0.0, 1.0};
  float resposta = Pertence_intervalo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_EQ(resposta,esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}



TEST(Teste, Pertence_intervalo_pontual) {
  float entrada[3] = {0.0, 0.0, 0.0};
  float resposta = Pertence_intervalo(entrada[0], entrada[1], entrada[2]);
  bool esperado = true;
  ASSERT_EQ(resposta,esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Destino_disparo(float xi, float a, float v) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";



}



}  // end namespace


#endif  // FUNCOES_TEST_FUNCOES_TEST_H_
