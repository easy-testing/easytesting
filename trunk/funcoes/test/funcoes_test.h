// copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_FUNCOES_TEST_FUNCOES_TEST_H_
#define TRUNK_FUNCOES_TEST_FUNCOES_TEST_H_

#include <cmath>
#include <sstream>
#include <string>

#include "funcoes/src/funcoes.h"
#include "gtest/gtest.h"

namespace Teste {

TEST(Teste, Testa_media_com_soma_positiva) {
  float entrada[3] = {2.50, 4.45, -1.25};
  float resposta = media(entrada[0], entrada[1], entrada[2]);
  float esperado = 1.9;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float media(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_media_com_soma_negativa) {
  float entrada[3] = {-3.69, 1.50, -2.40};
  float resposta = media(entrada[0], entrada[1], entrada[2]);
  float esperado = -1.53;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float media(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_media_com_soma_igual_a_zero) {
  float entrada[3] = {2.50, -1.20, -1.30};
  float resposta = media(entrada[0], entrada[1], entrada[2]);
  float esperado = 0;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float media(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_media_ponderada_com_soma_positiva) {
  float entrada[3] = {2.50, 4.45, -1.25};
  float resposta = media_ponderada(entrada[0], entrada[1], entrada[2]);
  float esperado = 1.5875;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float media_ponderada(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_media_ponderada_com_soma_negativa) {
  float entrada[3] = {-1.7, -4.1, -2.9};
  float resposta = media_ponderada(entrada[0], entrada[1], entrada[2]);
  float esperado = -3;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float media_ponderada(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_media_ponderada_com_soma_igual_a_zero) {
  float entrada[3] = {3.5, 3, -4.5};
  float resposta = media_ponderada(entrada[0], entrada[1], entrada[2]);
  float esperado = 0;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float media_ponderada(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_perimetro_circulo) {
  float entrada = 1000;
  float resposta = perimetro(entrada);
  float esperado = 2 * M_PI * entrada;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float perimetro(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_area_circulo) {
  float entrada = 100;
  float resposta = area_circulo(entrada);
  float esperado = M_PI * entrada * entrada;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_circulo(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_area_triangulo_acutangulo) {
  float entrada[2] = {10.5, 20.1};
  float resposta = area_triangulo(entrada[0], entrada[1]);
  float esperado = 105.525;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_triangulo(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0]
    << ", " << entrada[1] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_area_triangulo_retangulo) {
  float entrada[2] = {10.5, 10.5};
  float resposta = area_triangulo(entrada[0], entrada[1]);
  float esperado = 55.125;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_triangulo(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0]
    << ", " << entrada[1] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_area_triangulo_obtusangulo) {
  float entrada[2] = {15.4, 7.5};
  float resposta = area_triangulo(entrada[0], entrada[1]);
  float esperado = 57.75;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_triangulo(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0]
    << ", " << entrada[1] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_area_caixa_quadrada) {
  float entrada[3] = {3.5, 3.5, 3.5};
  float resposta = area_caixa(entrada[0], entrada[1], entrada[2]);
  float esperado = 73.5;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_caixa(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, testa_area_caixa_retangular) {
  float entrada[3] = {5.5, 7.5, 10.5};
  float resposta = area_caixa(entrada[0], entrada[1], entrada[2]);
  float esperado = 355.5;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_caixa(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_volume_caixa_quadrada) {
  float entrada[3] = {5.3, 5.3, 5.3};
  float resposta = volume_caixa(entrada[0], entrada[1], entrada[2]);
  float esperado = 148.877;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float volume_caixa(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_volume_caixa_retangular) {
  float entrada[3] = {4.2, 3.1, 8.4};
  float resposta = volume_caixa(entrada[0], entrada[1], entrada[2]);
  float esperado = 109.368;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float volume_caixa(float, float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0] << ", " << entrada[1]
    << ", " << entrada[2] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_area_cilindro) {
  float raio = 2;
  float altura = 100;
  float resposta = area_cilindro(raio, altura);
  float esperado = (2 * M_PI * raio) * altura + 2 * (M_PI * raio * raio);

  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float area_cilindro(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << raio
    << ", " << altura << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_volume_cilindro) {
  float raio = 2;
  float altura = 100;
  float resposta = volume_cilindro(raio, altura);
  float esperado = (M_PI * raio * raio) * altura;
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float volume_cilindro(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << raio << ", " << altura << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_hipotenusa_triagulo_isosceles) {
  float entrada[2] = {100, 100};
  float resposta = hipotenusa(entrada[0], entrada[1]);
  float esperado = 100 * sqrt(2);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float hipotenusa(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0]
    << ", " << entrada[1] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST(Teste, Testa_hipotenusa_triagulo_escaleno) {
  float entrada[2] = {100, 50};
  float resposta = hipotenusa(entrada[0], entrada[1]);
  float esperado = 50 * sqrt(5);
  ASSERT_FLOAT_EQ(resposta, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float hipotenusa(float, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "\nValores de entrada : " << entrada[0]
    << ", " << entrada[1] << "\n\n"
    << "   Resultado esperado:  " << esperado << "\n"
    << "   Resultado retornado: " << resposta << "\n\n"
    << "-------------------------------------------------------------------\n";
}

}  // end namespace

#endif  // TRUNK_FUNCOES_TEST_FUNCOES_TEST_H_
