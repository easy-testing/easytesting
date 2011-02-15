// Copyright 2010 Matheus Pacheco
#ifndef RECURSAO_TEST_RECURSAO_TEST_H_
#define RECURSAO_TEST_RECURSAO_TEST_H_

#include "easytesting/recursao/src/recursao.h"

#include <sstream>
#include <string>

#include "easytesting/gtest/gtest.h"

using std::string;
using std::stringstream;

namespace Teste {

// Classe base dos casos de teste.
class Teste : public testing::Test {
 protected:
};

TEST_F(Teste, Calculo_do_Fatorial) {
  int esperado[] = {1, 1, 720};
  int entrada[] =  {1, 0,   6};
  int num_testes = 3;

  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], fat(entrada[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int fat(int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valor de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << fat(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_da_Potenciacao) {
  // Casos analisados:
  // Expoente igual a 0
  // Base negativa com expoente par
  // Base negativa com expoente impar
  // Base positiva com expoente nao nulo
  int esperado[] = {1, 16, -1, 9};
  int entrada1[] = {5, -2, -1, 3};
  int entrada2[] = {0,  4,  3, 2};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], pow(entrada1[i], entrada2[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int pow(int, int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada1[i]
    << " elevado a " << entrada2[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << pow(entrada1[i], entrada2[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_do_MDC_entre_dois_numeros) {
  // Casos analisados:
  // a e b iguais
  // a e b proporcionais (a = k*b)
  // a e b primos, em que mdc = 1
  // valores comuns
  int esperado[] = {11,  9,  1,  4};
  int entrada1[] = {11,  9, 11, 28};
  int entrada2[] = {11, 27, 13, 20};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], mdc(entrada1[i], entrada2[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int mdc(int, int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada1[i]
    << " e " << entrada2[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << mdc(entrada1[i], entrada2[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_do_MDC_entre_tres_numeros) {
  // Casos analisados:
  // a, b e c iguais
  // a e b iguais e c proporcional a um deles (c = k*b)
  // a, b e c primos, em que mdc = 1
  // a primo e b e c com divisor comum
  // valores comuns
  int esperado[] = {10, 10,  1,  1,  3};
  int entrada1[] = {10, 10, 17, 23,  9};
  int entrada2[] = {10, 10, 41, 27,  6};
  int entrada3[] = {10, 50, 13, 45, 12};
  int num_testes = 5;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], mdc3(entrada1[i], entrada2[i], entrada3[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int mdc3(int, int, int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada1[i]
    << ",  " << entrada2[i] << " e " << entrada3[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : "
    << mdc3(entrada1[i], entrada2[i], entrada3[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_do_MMC) {
  // Casos analisados:
  // a e b iguais
  // a e b proporcionais (a = k*b)
  // a igual a 1
  // valores comuns
  int esperado[] = {10, 27, 21, 30};
  int entrada1[] = {10,  3,  1,  6};
  int entrada2[] = {10, 27, 21, 10};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], mmc(entrada1[i], entrada2[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int mmc(int, int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada1[i]
    << " e " << entrada2[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << mmc(entrada1[i], entrada2[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_da_sequencia_de_Fibonacci) {
  // Casos analisados:
  // n igual a 0
  // n igual a 1
  // valor qualquer
  int esperado[] = {0, 1, 3};
  int  entrada[] = {0, 1, 4};
  int num_testes = 3;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], fib(entrada[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int fib(int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << fib(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_do_Resto) {
  // Casos analisados:
  // a menor que b
  // a igual a b (resto 0)
  // a proporcional a b (resto 0)
  // a maior que b (resto diferente de 0)
  int esperado[] = {3, 0, 0,  5};
  int entrada1[] = {3, 4, 9, 15};
  int entrada2[] = {4, 4, 3, 10};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], resto(entrada1[i], entrada2[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int resto(int, int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada1[i]
    << " dividido por " << entrada2[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << resto(entrada1[i], entrada2[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_da_Divisao_inteira) {
  // Casos analisados:
  // a menor que b
  // a igual a b
  // a proporcional a b (a = k*b)
  // a maior que b
  int esperado[] = {0, 1, 3,  1};
  int entrada1[] = {3, 4, 9, 15};
  int entrada2[] = {4, 4, 3, 10};
  int num_testes = 4;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], div_(entrada1[i], entrada2[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int div_(int, int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada1[i]
    << " dividido por " << entrada2[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << div_(entrada1[i], entrada2[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_da_Soma_dos_digitos) {
  // Casos analisados:
  // numero igual a 0
  // numeros menores que 10
  // numeros maiores que 10 e menor que 100
  // numeros maiores que 100
  int esperado[] = {0, 7, 9,  9, 10,  14,  17};
  int entrada[] = {0, 7, 9, 45, 82, 428, 980};
  int num_testes = 7;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], dig(entrada[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int dig(int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << dig(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Numero_Primo) {
  // Casos analisados:
  // n igual a 1
  // n igual a primo
  // n igual a nao primo
  bool esperado[] = {false, true, false};
  int  entrada[] = {1, 2, 10};
  int num_testes = 3;
  for (int i = 0; i < num_testes; i ++) {
    ASSERT_EQ(esperado[i], primo(entrada[i]))
    << "\n-------------------------------------------------------------------"
    << "\nErro na funcao:  "
    << "* bool primo(int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << primo(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_da_Raiz_quadrada) {
  // Casos analisados:
  // raiz de 0
  // raiz de 1
  // raiz exata
  // raiz inexata de numero inteiro
  // raiz inexata de numero nao inteiro
  double esperado[] = {0, 1,  9,  4.795,   3.937};
  double  entrada[] = {0, 1, 81, 23,      15.5};
  int num_testes = 5;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_NEAR(esperado[i], sqrt_(entrada[i]), 0.001)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* double sqrt_double) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << sqrt_(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

}  // end namespace

#endif  // RECURSAO_TEST_RECURSAO_TEST_H_
