// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ITERACAO_TEST_ITERACAO_TEST_H_
#define TRUNK_ITERACAO_TEST_ITERACAO_TEST_H_

#include <sstream>
#include <string>

#include "src/iteracao.h"
#include "../doctest/doctest.h"

using std::string;
using std::stringstream;

namespace Teste {
TEST_CASE("Teste_Fatorial") {
  int esperado[] = {1, 1, 720};
  int entrada[] = {1, 0, 6};
  int num_testes = 3;

  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int fat(int)\n");
    INFO("\nValor de entrada: " << entrada[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << fat(entrada[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == fat(entrada[i]));
  }
}

TEST_CASE("Teste_Potenciacao") {
  // Casos analisados:
  // Expoente igual a 0,
  // Base negativa com expoente par,
  // Base negativa com expoente ímpar,
  // Base positiva com expoente não nulo.
  int esperado[] = {1, 16, -1, 9};
  int entrada1[] = {5, -2, -1, 3};
  int entrada2[] = {0, 4, 3, 2};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int pow(int, int)\n");
    INFO("\nValores de entrada: " << entrada1[i]
         << " elevado a " << entrada2[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << pow(entrada1[i], entrada2[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == pow(entrada1[i], entrada2[i]));
  }
}

TEST_CASE("Teste_MDC_entre_dois_numeros") {
  // Casos analisados:
  // a e b iguais,
  // a e b proporcionais (a = k * b),
  // a e b primos, em que mdc = 1,
  // valores comuns.
  int esperado[] = {11, 9, 1, 4};
  int entrada1[] = {11, 9, 11, 28};
  int entrada2[] = {11, 27, 13, 20};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int mdc(int, int)\n");
    INFO("\nValores de entrada: " << entrada1[i]
         << " e " << entrada2[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << mdc(entrada1[i], entrada2[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == mdc(entrada1[i], entrada2[i]));
  }
}

TEST_CASE("Teste_MDC_entre_tres_numeros") {
  // Casos analisados:
  // a, b e c iguais,
  // a e b iguais e c proporcional a um deles (c = k * b),
  // a, b e c primos, em que mdc = 1,
  // a primo e b e c com divisor comum,
  // valores comuns.
  int esperado[] = {10, 10, 1, 1, 3};
  int entrada1[] = {10, 10, 17, 23, 9};
  int entrada2[] = {10, 10, 41, 27, 6};
  int entrada3[] = {10, 50, 13, 45, 12};
  int num_testes = 5;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int mdc3(int, int, int)\n");
    INFO("\nValores de entrada: " << entrada1[i]
         << ",  " << entrada2[i] << " e " << entrada3[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << mdc3(entrada1[i], entrada2[i], entrada3[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == mdc3(entrada1[i], entrada2[i], entrada3[i]));
  }
}

TEST_CASE("Teste_MMC") {
  // Casos analisados:
  // a e b iguais
  // a e b proporcionais (a = k*b)
  // a igual a 1
  // valores comuns
  int esperado[] = {10, 27, 21, 30};
  int entrada1[] = {10, 3, 1, 6};
  int entrada2[] = {10, 27, 21, 10};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int mmc(int, int)\n");
    INFO("\nValores de entrada: " << entrada1[i]
         << " e " << entrada2[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << mmc(entrada1[i], entrada2[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == mmc(entrada1[i], entrada2[i]));
  }
}

TEST_CASE("Teste_sequencia_de_Fibonacci") {
  // Casos analisados:
  // n igual a 0,
  // n igual a 1,
  // valor qualquer.
  int esperado[] = {0, 1, 3};
  int entrada[] = {0, 1, 4};
  int num_testes = 3;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int fib(int)\n");
    INFO("\nValores de entrada: " << entrada[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << fib(entrada[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == fib(entrada[i]));
  }
}

TEST_CASE("Teste_do_Resto") {
  // Casos analisados:
  // a menor que b,
  // a igual a b (resto 0),
  // a proporcional a b (resto 0),
  // a maior que b (resto diferente de 0).
  int esperado[] = {3, 0, 0, 5};
  int entrada1[] = {3, 4, 9, 15};
  int entrada2[] = {4, 4, 3, 10};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int resto(int, int)\n");
    INFO("\nValores de entrada: " << entrada1[i]
         << " dividido por " << entrada2[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << resto(entrada1[i], entrada2[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == resto(entrada1[i], entrada2[i]));
  }
}

TEST_CASE("Teste_da_Divisao_inteira") {
  // Casos analisados:
  // a menor que b,
  // a igual a b,
  // a proporcional a b (a = k * b),
  // a maior que b.
  int esperado[] = {0, 1, 3, 1};
  int entrada1[] = {3, 4, 9, 15};
  int entrada2[] = {4, 4, 3, 10};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int div_(int, int)\n");
    INFO("\nValores de entrada: " << entrada1[i]
         << " dividido por " << entrada2[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << div_(entrada1[i], entrada2[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == div_(entrada1[i], entrada2[i]));
  }
}

TEST_CASE("Teste_da_Soma_dos_digitos") {
  // Casos analisados:
  // numero igual a 0,
  // numeros menores que 10,
  // numeros maiores que 10 e menor que 100,
  // numeros maiores que 100.
  int esperado[] = {0, 7, 9, 9, 10, 14, 17};
  int entrada[] = {0, 7, 9, 45, 82, 428, 980};
  int num_testes = 7;
  for (int i = 0; i < num_testes; i++) {
    INFO("-------------------------------------------------------------------");
    INFO("\nErro na função: int dig(int)\n");
    INFO("\nValores de entrada: " << entrada[i] << "\n\n");
    INFO("   Resultado esperado: " << esperado[i]);
    INFO("   Resultado retornado: " << dig(entrada[i]));
    INFO("-------------------------------------------------------------------");

    CHECK(esperado[i] == dig(entrada[i]));
  }
}
}  // namespace Teste

#endif  // TRUNK_ITERACAO_TEST_ITERACAO_TEST_H_
