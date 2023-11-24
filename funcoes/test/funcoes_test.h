// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_FUNCOES_TEST_FUNCOES_TEST_H_
#define TRUNK_FUNCOES_TEST_FUNCOES_TEST_H_

#include "../doctest/doctest.h"
#include "src/funcoes.h"

#include <cmath>
#include <sstream>
#include <string>

namespace Teste {
  TEST_CASE("Testa media com soma positiva") {
    float entrada[3] = {2.50, 4.45, -1.25};
    float resposta = media(entrada[0], entrada[1], entrada[2]);
    float esperado = 1.9;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float media(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa media com soma negativa") {
    float entrada[3] = {-3.69, 1.50, -2.40};
    float resposta = media(entrada[0], entrada[1], entrada[2]);
    float esperado = -1.53;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float media(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa media com soma igual a zero") {
    float entrada[3] = {2.50, -1.20, -1.30};
    float resposta = media(entrada[0], entrada[1], entrada[2]);
    float esperado = 0;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float media(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa media ponderada com soma positiva") {
    float entrada[3] = {2.50, 4.45, -1.25};
    float resposta = media_ponderada(entrada[0], entrada[1], entrada[2]);
    float esperado = 1.5875;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float media_ponderada(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa media ponderada com soma negativa") {
    float entrada[3] = {-1.7, -4.1, -2.9};
    float resposta = media_ponderada(entrada[0], entrada[1], entrada[2]);
    float esperado = -3;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float media(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa media ponderada com soma igual a zero") {
    float entrada[3] = {3.5, 3, -4.5};
    float resposta = media_ponderada(entrada[0], entrada[1],  entrada[2]);
    float esperado = 0;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float media(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa perimetro circulo") {
    float entrada = 1000;
    float resposta = perimetro(entrada);
    float esperado = 2 * M_PI * entrada;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float perimetro(float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area circulo") {
    float entrada = 100;
    float resposta = area_circulo(entrada);
    float esperado = M_PI * entrada * entrada;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_circulo(float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area triangulo acutangulo") {
    float entrada[2] = {10.5, 20.1};
    float resposta = area_triangulo(entrada[0], entrada[1]);
    float esperado = 105.525;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_triangulo(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area triangulo retangulo") {
    float entrada[2] = {10.5, 10.5};
    float resposta = area_triangulo(entrada[0], entrada[1]);
    float esperado = 55.125;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_triangulo(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area triangulo obtusangulo") {
    float entrada[2] = {15.4, 7.5};
    float resposta = area_triangulo(entrada[0], entrada[1]);
    float esperado = 57.75;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_triangulo(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area caixa quadrada") {
    float entrada[3] = {3.5, 3.5, 3.5};
    float resposta = area_caixa(entrada[0], entrada[1], entrada[2]);
    float esperado = 73.5;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_caixa(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area caixa retangular") {
    float entrada[3] = {5.5, 7.5, 10.5};
    float resposta = area_caixa(entrada[0], entrada[1], entrada[2]);
    float esperado = 355.5;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_caixa(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa volume caixa quadrada") {
    float entrada[3] = {5.3, 5.3, 5.3};
    float resposta = volume_caixa(entrada[0], entrada[1], entrada[2]);
    float esperado = 148.877;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float volume_caixa(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa volume caixa retangular") {
    float entrada[3] = {4.2, 3.1, 8.4};
    float resposta = volume_caixa(entrada[0], entrada[1], entrada[2]);
    float esperado = 109.368;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float volume_caixa(float, float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << ", " << entrada[2] << "\n\n");
    INFO("\nResultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa area cilindro") {
    float raio = 2;
    float altura = 100;
    float resposta = area_cilindro(raio, altura);
    float esperado = (2 * M_PI * raio) * altura + 2 * (M_PI * raio * raio);
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float area_cilindro(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << raio << ", " << altura << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa volume cilindro") {
    float raio = 2;
    float altura = 100;
    float resposta = volume_cilindro(raio, altura);
    float esperado = (M_PI * raio * raio) * altura;
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float volume_cilindro(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << raio << ", " << altura << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa hipotenusa triângulo isósceles") {
    float entrada[2] = {100, 100};
    float resposta = hipotenusa(entrada[0], entrada[1]);
    float esperado = 100 * sqrt(2);
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float hipotenusa(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }

  TEST_CASE("Testa hipotenusa triângulo escaleno") {
    float entrada[2] = {100, 50};
    float resposta = hipotenusa(entrada[0], entrada[1]);
    float esperado = 50 * sqrt(5);
    CHECK_MESSAGE(resposta == doctest::Approx(esperado), "Erro na funcao: * float hipotenusa(float, float) *");
    INFO("-------------------------------------------------------------------");
    INFO("\nValores de entrada : " << entrada[0] << ", " << entrada[1] << "\n\n");
    INFO("   Resultado esperado:  " << esperado);
    INFO("   Resultado retornado: " << resposta);
    INFO("-------------------------------------------------------------------");
  }
}  // namespace Teste

#endif  // TRUNK_FUNCOES_TEST_FUNCOES_TEST_H_