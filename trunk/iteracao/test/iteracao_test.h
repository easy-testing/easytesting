// copyright 2010 Thiago Ferreira de Noronha
#ifndef ITERACAO_TEST_ITERACAO_TEST_H_
#define ITERACAO_TEST_ITERACAO_TEST_H_

#include "easytesting/iteracao/src/iteracao.h"

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
  int esperado[] = {0, 1, 3};
  int  entrada[] = {0, 1, 4};
  int num_testes = 3;
  for (int i = 0; i < num_testes; i ++) {
  ASSERT_EQ(esperado[i], fib(entrada[i]))
    << "\n-------------------------------------------------------------------"
    << "\nErro na funcao:  "
    << "* int fib(int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << fib(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_do_Resto) {
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
  bool esperado[] = {false, true, false};
  int  entrada[] = {1, 2, 10};
  int num_testes = 3;
  for (int i = 0; i < num_testes; i ++) {
    ASSERT_EQ(esperado[i], primo(entrada[i]))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool primo(int) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valores de entrada : " << entrada[i] << "\n\n"
    << "   Resultado esperado : " << esperado[i] << "\n"
    << "  Resultado retornado : " << primo(entrada[i]) << "\n\n"
    << "-------------------------------------------------------------------\n";
  }
}

TEST_F(Teste, Calculo_da_Raiz_quadrada) {
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

#endif  // ITERACAO_TEST_ITERACAO_TEST_H_
