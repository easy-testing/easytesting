// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef POLINOMIO_TEST_POLINOMIO_TEST_H_
#define POLINOMIO_TEST_POLINOMIO_TEST_H_

#include <sstream>
#include <string>
#include "polinomio/src/polinomio.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:


  string ImprimirPrimeiro(float x, int i) {
    stringstream sout;
    if (i == 0) {
      sout << x;
    } else if (x == 1) {
      sout << "";
    } else if (x == -1) {
      sout << "-";
    } else {
      sout << x;
    }
    return sout.str();
  }

  string ImprimirOutros(float x) {
    stringstream sout;
    if (x == 1) {
      sout << " + ";
    } else if (x == -1) {
      sout << " - ";
    } else if (x > 0) {
      sout << " + " << x;
    } else if (x < 0) {
      sout << " - " << -x;
    }
    return sout.str();
  }

  // Retorna uma string no formato a + bx + cx^2 + dx^3 + ... + zx^g.
  string Imprimir(int g, float v[]) {
    stringstream sout;
    // Trata o caso P(x) = 0.
    if (g < 0) {
      return "0";
    }
    bool primeiro = true;
    for (int i = 0; i <= g; i++) {
      if (v[i] != 0.0) {
        if (primeiro) {
          sout << ImprimirPrimeiro(v[i], i);
          primeiro = false;
        } else {
          sout << ImprimirOutros(v[i]);
        }
        if (i == 1) {
          sout << "x";
        } else if (i > 1) {
          sout << "x^" << i;
        }
      }
    }
    return sout.str();
  }

  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string ToString(int g, float v[]) {
    stringstream sout;
    sout << "{" << v[0];
    for (int i = 1; i <= g ; i++) {
      sout << ", " << v[i];
    }
    sout << "}";
    return sout.str();
  }
};


TEST_F(Teste, ToString) {
  float v1[]={7};
  ASSERT_EQ("7", Imprimir(0, v1))
      << Imprimir(0, v1);

  float v2[] = {4, -2.7, 3.8, -5, 1};
  ASSERT_EQ("4 - 2.7x + 3.8x^2 - 5x^3 + x^4", Imprimir(4, v2))
      << Imprimir(4, v2);

  float v3[] = {0, -0.2, 0, 3, -1};
  ASSERT_EQ("-0.2x + 3x^3 - x^4", Imprimir(4, v3))
      << Imprimir(4, v3);

  float v4[] = {0, 0, 3, -1};
  ASSERT_EQ("3x^2 - x^3", Imprimir(3, v4))
      << Imprimir(3, v4);

  float v5[] = {-5, 0, 1};
  ASSERT_EQ("-5 + x^2", Imprimir(2, v5))
      << Imprimir(2, v5);

  float v6[] = {0, -1, 1};
  ASSERT_EQ("-x + x^2", Imprimir(2, v6))
      << Imprimir(2, v6);

  float v7[] = {0, 1, -1};
  ASSERT_EQ("x - x^2", Imprimir(2, v7))
      << Imprimir(2, v7);
}

//TEST_F(Teste, Verificar_termos_em_avaliar_polinomios) {
//  float coef_p[] = {1, 2, 3};  // P(x) = 1 + 2x + 3x^2.
//  Polinomio p;
//  Inicializar(3, coef_p, &p);
//
//  // Avalia P(2) verificando se faltou 'x^i'.
//  float x = 2.0;
//  float inesperado = 6;
//  float esperado = 17;
//  float atual = p.Avaliar(x);
//  ASSERT_NE(inesperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "   Verifique se utilizou o valor do 'x^i' no somatorio do\n"
//    << "   polinomio.\n"
//    << "-------------------------------------------------------------------\n";
//
//  float coef_p2[] = {1, 2, 3};  // P(x) = 1 + 2x + 3x^2.
//  Polinomio p2;
//  Inicializar(3, coef_p2, &p2);
//
//  // Avalia P(2) verificando se faltou coeficiente.
//  x = 2.0;
//  inesperado = 7;
//  esperado = 17;
//  atual = p2.Avaliar(x);
//  ASSERT_NE(inesperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p2) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "   Verifique se utilizou o valor do coeficiente no somatorio do\n"
//    << "   polinomio.\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Avaliar_polinomios_com_coeficientes_nao_nulos) {
//  float coef_p[] = {4, -2.0, 3, -5, 1};  // P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4.
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//
//  // Avalia P(0.0).
//  float x = 0.0;
//  float esperado = 4;
//  float atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(1.0)
//  x = 1.0;
//  esperado = 1;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(-1)
//  x = -1.0;
//  esperado = 15;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Avaliar_polinomios_com_alguns_coeficientes_nulos) {
//  float coef_p[] = {5, 0, 3, 0, 2};  // P(x) = 5 + 3x^2 + 2x^4.
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//
//  // Avalia P(0).
//  float x = 0.0;
//  float esperado = 5;
//  float atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(1)
//  x = 1.0;
//  esperado = 10;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(-1)
//  x = -1.0;
//  esperado = 10;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Avaliar_polinomios_nas_raizes) {
//  float coef_p[] = {6, -5, 1};  // P(x) = 6 - 5x + x^2.
//  Polinomio p;
//  Inicializar(3, coef_p, &p);
//
//  // Avalia P(2).
//  float x = 2.0;
//  float esperado = 0;
//  float atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(3)
//  x = 3.0;
//  esperado = 0;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Avaliar_polinomios_constantes) {
//  float coef_p[] = {7};  // P(x) = 7.
//  Polinomio p(0);
//  Inicializar(1, coef_p, &p);
//
//  // Avalia P(0).
//  float x = 0.0;
//  float esperado = 7;
//  float atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(x = 13)
//  x = 13.0;
//  esperado = 7;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(x = -13)
//  x = -13.0;
//  esperado = 7;
//  atual = p.Avaliar(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Operador_avaliar_polinomios_com_coeficientes_nao_nulos) {
//  float coef_p[] = {4, -2.0, 3, -5, 1};  // P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4.
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//
//  // Avalia P(0.0).
//  float x = 0.0;
//  float esperado = 4;
//  float atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(1.0)
//  x = 1.0;
//  esperado = 1;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(-1)
//  x = -1.0;
//  esperado = 15;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Operador_avaliar_polinomios_com_alguns_coeficientes_nulos) {
//  float coef_p[] = {5, 0, 3, 0, 2};  // P(x) = 5 + 3x^2 + 2x^4.
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//
//  // Avalia P(0).
//  float x = 0.0;
//  float esperado = 5;
//  float atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(1)
//  x = 1.0;
//  esperado = 10;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(-1)
//  x = -1.0;
//  esperado = 10;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Operador_avaliar_polinomios_nas_raizes) {
//  float coef_p[] = {6, -5, 1};  // P(x) = 6 - 5x + x^2.
//  Polinomio p;
//  Inicializar(3, coef_p, &p);
//
//  // Avalia P(2).
//  float x = 2.0;
//  float esperado = 0;
//  float atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(3)
//  x = 3.0;
//  esperado = 0;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Operador_avaliar_polinomios_constantes) {
//  float coef_p[] = {7};  // P(x) = 7.
//  Polinomio p(0);
//  Inicializar(1, coef_p, &p);
//
//  // Avalia P(0).
//  float x = 0.0;
//  float esperado = 7;
//  float atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(x = 13)
//  x = 13.0;
//  esperado = 7;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//
//  // Avalia P(x = -13)
//  x = -13.0;
//  esperado = 7;
//  atual = p(x);
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* float Polinomio::Avaliar(float) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n"
//    << "      x = " << x << "\n\n"
//    << "   Valor esperado : " << esperado << "\n"
//    << "   Valor retornado: " << atual << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Verifica_grau_em_atribuicao_de_polinomio) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  int esperado = 4;
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  Polinomio novo;
//  novo.Atribuir(p);
//  int atual = novo.grau();
//  ASSERT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Atribuir(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "   Polinomio a atribuir tem grau: " << esperado << "\n"
//    << "   Polinomio atribuido tem grau: " << atual << "\n"
//    << "   Verifique se esta lembrando de atualizar o grau do polinomio    \n"
//    << "   atribuido.\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Atribuir_polinomio_de_grau_maior_que_um) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  Polinomio novo;
//  novo.Atribuir(p);
//  ASSERT_EQ(MostrarComoVetor(p), MostrarComoVetor(novo))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Atribuir(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "   Polinomio a atribuir: " << MostrarPorExtenso(p) << "\n"
//    << "   Polinomio atribuido: " << MostrarPorExtenso(novo) << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Operador_atribuicao_polinomio_de_grau_maior_que_um) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  Polinomio novo;
//  novo = p;
//  ASSERT_EQ(MostrarComoVetor(p), MostrarComoVetor(novo))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Atribuir(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "   Polinomio a atribuir: " << MostrarPorExtenso(p) << "\n"
//    << "   Polinomio atribuido: " << MostrarPorExtenso(novo) << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Verifica_grau_em_derivada_de_polinomio) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  int esperado = 3;
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  Polinomio derivada;
//  derivada.Derivar(p);
//  int atual = derivada.grau();
//    ASSERT_EQ(esperado, atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Derivar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Grau da derivada esperada : " << esperado << "\n"
//    << "   Grau da derivada retornada: " << atual << "\n"
//    << "   Verifique se esta lembrando de atualizar o grau do polinomio    \n"
//    << "   derivado.\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Derivar_polinomio_de_grau_um) {
//  float coef_p[] = {1, 2};
//  Polinomio p;
//  Inicializar(2, coef_p, &p);
//  float coef_esperado[] = {2};
//  Polinomio esperado;
//  Inicializar(1, coef_esperado, &esperado);
//  Polinomio derivada;
//  derivada.Derivar(p);
//  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Derivar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Derivada esperada : " << MostrarPorExtenso(esperado) << "\n"
//    << "   Derivada retornada: " << MostrarPorExtenso(derivada) << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Derivar_polinomio_de_grau_maior_que_um) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  float coef_esperado[] = {0, 6, 0, 8};
//  Polinomio esperado;
//  Inicializar(4, coef_esperado, &esperado);
//  Polinomio derivada;
//  derivada.Derivar(p);
//    ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Derivar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Derivada esperada : " << MostrarPorExtenso(esperado) << "\n"
//    << "   Derivada retornada: " << MostrarPorExtenso(derivada) << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Derivar_polinomio_constante) {
//  float coef_p[] = {1};
//  Polinomio p;
//  Inicializar(1, coef_p, &p);
//  Polinomio derivada;
//  derivada.Derivar(p);
//  bool atual = derivada.nulo();
//  ASSERT_TRUE(atual)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Derivar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   A derivada do polinomio constante eh um polinomio nulo, porem a\n"
//    << "   funcao nao retorna true.\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Verifica_grau_integral_de_polinomio) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  int esperado = 5;
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  Polinomio integral;
//  integral.Integrar(p);
//  int atual = integral.grau();
//  ASSERT_EQ(atual, esperado)
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Integrar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Grau da integral esperada : " << esperado << "\n"
//    << "   Grau da integral retornada: " << atual << "\n"
//    << "   Verifique se esta lembrando de atualizar o grau do polinomio    \n"
//    << "   integrado.\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Integrar_polinomio_de_grau_zero) {
//  float coef_p[] = {7};
//  Polinomio p;
//  Inicializar(1, coef_p, &p);
//  float coef_esperado[] = {0, 7};
//  Polinomio esperado;
//  Inicializar(2, coef_esperado, &esperado);
//  Polinomio integral;
//  integral.Integrar(p);
//  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Integrar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
//    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Integrar_polinomio_de_grau_um) {
//  float coef_p[] = {1, 2};
//  Polinomio p;
//  Inicializar(2, coef_p, &p);
//  float coef_esperado[] = {0, 1, 1};
//  Polinomio esperado;
//  Inicializar(3, coef_esperado, &esperado);
//  Polinomio integral;
//  integral.Integrar(p);
//  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Integrar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
//    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Integrar_polinomio_de_grau_maior_que_um) {
//  float coef_p[] = {5, 0, 3, 0, 2};
//  Polinomio p;
//  Inicializar(5, coef_p, &p);
//  float coef_esperado[] = {0, 5, 0, 1, 0, 0.4};
//  Polinomio esperado;
//  Inicializar(6, coef_esperado, &esperado);
//  Polinomio integral;
//  integral.Integrar(p);
//  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
//    << "-------------------------------------------------------------------\n"
//    << "Erro na funcao:  "
//    << "* void Polinomio::Integrar(Polinomio& q) *\n"
//    << "-------------------------------------------------------------------\n"
//    << "      p = " << MostrarPorExtenso(p) << "\n\n"
//    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
//    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
//    << "-------------------------------------------------------------------\n";
//}

#endif  // POLINOMIO_TEST_POLINOMIO_TEST_H_

