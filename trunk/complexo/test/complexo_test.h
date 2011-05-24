// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef COMPLEXO_TEST_COMPLEXO_TEST_H_
#define COMPLEXO_TEST_COMPLEXO_TEST_H_

#include "complexo/src/complexo.h"

#include <math.h>

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  void Inicializar(double r, double i, Complexo* c) {
    c->real_ = r;
    c->imag_ = i;
  }

  double real(Complexo& x) {
    return x.real_;
  }

  double imag(Complexo& x) {
    return x.imag_;
  }

  bool Igual(Complexo x, Complexo y) {
    return fabs(x.real_ - y.real_) <= 1E-6 &&
           fabs(x.imag_ - y.imag_) <= 1E-6;
  }

  // Retorna string no formato [x + yi]
  string ToString(Complexo& z) {
    stringstream output;
    output << real(z);
    if (imag(z) >= 0.0) {
      output << " + " << imag(z) << "i";
    } else {
      output << " - " << -imag(z) << "i";
    }
    return output.str();
  }
};

TEST_F(Teste, Testa_funcao_real) {
  Complexo x;
  Inicializar(1.1, 2.2, &x);
  double esperado = 1.1;
  double atual = x.real();
  ASSERT_DOUBLE_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"double Complexo::real()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo: " << ToString(x) << "\n\n"
    << "  Parte real esperada: " << esperado << "\n"
    << "  Parte real retornada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_imag) {
  Complexo x(0.1, 3.2);
  Inicializar(0.1, 3.2, &x);
  double atual = x.imag();
  double esperado = 3.2;
  ASSERT_DOUBLE_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"double Complexo::imag()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo: " << ToString(x) << "\n\n"
    << "  Parte imaginaria esperada: " << esperado << "\n"
    << "  Parte imaginaria retornada: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_construtor_sem_parametros) {
  Complexo atual;
  Complexo esperado;
  Inicializar(0, 0, &esperado);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: \"Complexo::Complexo()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_construtor_com_um_paramentro) {
  Complexo atual(-13);
  Complexo esperado;
  Inicializar(-13, 0, &esperado);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: \"Complexo::Complexo(double a)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_construtor_com_dois_paramentros) {
  Complexo atual(3.14, -1.4142);
  Complexo esperado;
  Inicializar(3.14, -1.4142, &esperado);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: \"Complexo::Complexo(double a, double b)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_modulo_com_numero_complexo_nulo) {
  Complexo x(0, 0);
  double esperado = 0;
  double atual = x.modulo();
  ASSERT_DOUBLE_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"double Complexo::modulo()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo: " << ToString(x) << "\n\n"
    << "  Valor esperado: " << esperado << "\n"
    << "  Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_modulo_com_numero_complexo_nao_nulo) {
  Complexo x(3, 4);
  double esperado = 5;
  double atual = x.modulo();
  ASSERT_DOUBLE_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"double Complexo::modulo()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo: " << ToString(x) << "\n\n"
    << "  Valor esperado: " << esperado << "\n"
    << "  Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_igualdade_de_numeros_complexos_iguais) {
  Complexo x(3.14, -1.4142);
  Complexo y(3.14, -1.4142);
  ASSERT_TRUE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: true\n"
    << "  Resultado retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_igualdade_de_numeros_complexos_distintos) {
  Complexo x(6.1, 8.5);
  Complexo y(4.2, 3.03);
  ASSERT_FALSE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n"
    << "  Resultado esperado: false\n"
    << "  Resultado retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_igualdade_de_numeros_diferentes_com_mesma_parte_real) {
  Complexo x(-3.56, 8.5);
  Complexo y(-3.56, 3.03);
  ASSERT_FALSE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n"
    << "  Resultado esperado: false\n"
    << "  Resultado retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_igualdade_de_numeros_diferentes_com_mesma_parte_imag) {
  Complexo x(5.36, -8.5);
  Complexo y(1.34, -8.5);
  ASSERT_FALSE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"bool Complexo::operator==(Complexo x)\"          \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: false\n"
    << "  Resultado retornado: true\n\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_atribuicao_de_numeros_complexos) {
  Complexo esperado(1.4142, -3.14);
  Complexo atual = esperado;
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: \"void Complexo::operator=(Complexo x)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_conjugado_de_numero_complexo_nulo) {
  Complexo x(0.0, 0.0);
  Complexo atual;
  atual = x.conjugado();
  Complexo esperado(0.0, 0.0);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::conjugado()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_conjugado_de_numero_com_parte_imaginaria_negativa) {
  Complexo x(1.0, -3.14);
  Complexo atual;
  atual = x.conjugado();
  Complexo esperado(1.0, 3.14);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::conjugado()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_conjugado_de_numero_com_parte_imaginaria_positiva) {
  Complexo x(1.0, 3.14);
  Complexo atual;
  atual = x.conjugado();
  Complexo esperado(1.0, -3.14);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::conjugado()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_simetrico_complexo_positivo) {
  Complexo x(1, 1);
  Complexo esperado(-1, -1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::simetrico()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_simetrico_complexo_negativo) {
  Complexo x(-1, -1);
  Complexo esperado(1, 1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::simetrico()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_simetrico_complexo_real_nula) {
  Complexo x(0, -1);
  Complexo esperado(0, 1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::simetrico()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_simetrico_complexo_imaginario_nula) {
  Complexo x(-1);
  Complexo esperado(1);
  Complexo atual = x.simetrico().simetrico().simetrico();
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::simetrico()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_inverso_de_numero_complexo) {
  Complexo x(6, 8);
  Complexo atual;
  atual = x.inverso();
  Complexo esperado(0.06, -0.08);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::inverso()\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero complexo esperado: " << ToString(esperado) << "\n"
    << "  Numero complexo retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_soma_de_numeros_complexos_nulos) {
  Complexo x(2, 3);
  Complexo y;
  Complexo atual = x + y;
  Complexo esperado(2, 3);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_soma_de_numeros_complexos_positivos) {
  Complexo x(4.1, 2.4);
  Complexo y(3.6, 1.5);
  Complexo atual = x + y;
  Complexo esperado(7.7, 3.9);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_Numeros_Complexos_Negativos) {
  Complexo x(-4.1, -2.4);
  Complexo y(-3.6, -1.5);
  Complexo atual = x + y;
  Complexo esperado(-7.7, -3.9);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_Numeros_Complexos_de_sinais_opostos) {
  Complexo x(-4.1, 2.4);
  Complexo y(3.6, -1.5);
  Complexo atual = x + y;
  Complexo esperado(-0.5, 0.9);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator+(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}
TEST_F(Teste, Subtrair_Numeros_Complexos_Nulos) {
  Complexo x(2.4, 1.1);
  Complexo y;
  Complexo atual = x - y;
  Complexo esperado(2.4, 1.1);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_Positivos) {
  Complexo x(2.4, 1.1);
  Complexo y(3.5, 0.8);
  Complexo atual = x - y;
  Complexo esperado(-1.1, 0.3);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_Negativos) {
  Complexo x(-3.5, -0.1);
  Complexo y(-2.2, -4.7);
  Complexo atual = x - y;
  Complexo esperado(-1.3, 4.6);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_de_sinais_opostos) {
  Complexo x(-3.5, 0.1);
  Complexo y(3.5, -0.1);
  Complexo atual = x - y;
  Complexo esperado(-7.0, 0.2);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Complexo Complexo::operator-(Complexo y)\" \n"
    << "-------------------------------------------------------------------\n"
    << "  Numero Complexo 1: " << ToString(x) << "\n"
    << "  Numero Complexo 2: " << ToString(y) << "\n\n"
    << "  Resultado esperado: "  << ToString(esperado) << "\n"
    << "  Resultado retornado: " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicar_Numeros_Complexos_Nulos) {
  Complexo x(4.1, -2.4);
  Complexo y;
  Complexo z;
  x = y * z;
  Complexo esperado(0, 0);
  ASSERT_TRUE(Igual(esperado, x))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::operator*(Complexo)\"        \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << ToString(y) << "\n"
    << " Numero Complexo 2: " << ToString(z) << "\n\n"
    << " Resposta retornada: " << ToString(x) << "\n"
    << " Resposta esperada:  " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicar_Numeros_Complexos_mesmo_sinal) {
  Complexo y(4.1, 2.4);
  Complexo z(3.6, 1.5);
  Complexo atual = y * z;
  Complexo esperado(11.16, 14.79);
  ASSERT_TRUE(Igual(esperado, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::operator*(Complexo)\"        \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << ToString(y) << "\n"
    << " Numero Complexo 2: " << ToString(z) << "\n\n"
    << " Resposta retornada: " << ToString(atual) << "\n"
    << " Resposta esperada:  " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicar_Numeros_Complexos_sinais_contrarios) {
  Complexo x;
  Complexo y(3.1, -2.4);
  Complexo z(-3.6, 1.8);
  x = y * z;
  Complexo esperado(-6.84, 14.22);
  ASSERT_TRUE(Igual(esperado, x))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::operator*(Complexo)\"        \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << ToString(y) << "\n"
    << " Numero Complexo 2: " << ToString(z) << "\n\n"
    << " Resposta retornada: " << ToString(x) << "\n"
    << " Resposta esperada:  " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Dividir_Numeros_Complexos_mesmo_sinal) {
  Complexo x;
  Complexo y(8, 1);
  Complexo z(4, 2);
  x = y / z;
  Complexo esperado(1.7, -0.6);
  ASSERT_TRUE(Igual(esperado, x))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::operator/(Complexo)\"        \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << ToString(y) << "\n"
    << " Numero Complexo 2: " << ToString(z) << "\n\n"
    << " Resposta retornada: " << ToString(x) << "\n"
    << " Resposta esperada:  " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Dividir_Numeros_Complexos_sinais_contrarios) {
  Complexo x;
  Complexo y(8, 5);
  Complexo z(-4, -2);
  x = y / z;
  Complexo esperado(-2.1, -0.2);
  ASSERT_TRUE(Igual(esperado, x))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"Complexo Complexo::operator/(Complexo)\"        \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << ToString(y) << "\n"
    << " Numero Complexo 2: " << ToString(z) << "\n\n"
    << " Resposta retornada: " << ToString(x) << "\n"
    << " Resposta esperada:  " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}
#endif  // COMPLEXO_TEST_COMPLEXO_TEST_H_
