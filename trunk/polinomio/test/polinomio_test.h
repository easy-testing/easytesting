// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
#ifndef POLINOMIO_TEST_POLINOMIO_TEST_H_
#define POLINOMIO_TEST_POLINOMIO_TEST_H_

#include <sstream>
#include <string>
#include "easytesting/polinomio/src/polinomio.h"
#include "easytesting/gtest/gtest.h"

using std::string;
using std::stringstream;

namespace Testes {

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato a + bx + cx^2 + dx^3 + ... + zx^n.
  string MostrarPorExtenso(Polinomio& p) {
    stringstream s;
    bool primeiro = true;
    for (int i = 0; i <= p.grau(); i++) {
      // TODO(tfn): Tratar o caso P(x) = 0.
      if (p.get(i) != 0.0) {
        if (primeiro) {
          s << p.get(i);
          primeiro = false;
        } else {
          if (p.get(i) == 1.0) {
            s << " + ";
          } else if (p.get(i) > 0.0) {
            s << " + " << p.get(i);
          } else if (p.get(i) < 0.0) {
            s << " - " << -p.get(i);
          }
        }
        if (i == 1) {
          s << "x";
        } else if (i > 1) {
          s << "x^" << i;
        }
      }
    }
    return s.str();
  }

  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string MostrarComoVetor(Polinomio& p) {
    stringstream output;
    output << "{" << p.get(0);
    for (int i = 1; i <= p.grau() ; i++) {
      output << ", " << p.get(i);
    }
    output << "}";
    return output.str();
  }
};


// TODO(tfn): Acrescentar o caso para P(x) = 0.
TEST_F(Teste, Testa_o_metodo_MostrarPorExtenso) {
  float coef_p[] = {4, -2.7, 3.8, -5, 1};
  Polinomio p(5, coef_p);
  ASSERT_EQ("4 - 2.7x + 3.8x^2 - 5x^3 + x^4", MostrarPorExtenso(p));

  float coef_q[] = {0, -0.2, 0, 3, -1};
  Polinomio q(5, coef_q);
  ASSERT_EQ("-0.2x + 3x^3 - 1x^4", MostrarPorExtenso(q));

  float coef_t[] = {0, 0, 0, 3, -1};
  Polinomio t(5, coef_t);
  ASSERT_EQ("3x^3 - 1x^4", MostrarPorExtenso(t));
}

TEST_F(Teste, Testar_Funcao_Grau_Polinomio_grau_um) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p(2, coef_p);
  int esperado = 1;
  int atual = p.grau();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int Polinomio::grau() *\n"
    << "-------------------------------------------------------------------\n"
    << "      Polinomio: " << MostrarPorExtenso(p) << "\n\n"
    << "  Grau esperado:  " << esperado << "\n"
    << "  Grau retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Funcao_Grau_Polinomio_grau_maior_que_um) {
  float coef_p[] = {5.5, 4.2, 3.1, 2.4};
  Polinomio p(4, coef_p);
  int esperado = 3;
  int atual = p.grau();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int Polinomio::grau() *\n"
    << "-------------------------------------------------------------------\n"
    << "      Polinomio: " << MostrarPorExtenso(p) << "\n\n"
    << "  Grau esperado:  " << esperado << "\n"
    << "  Grau retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Funcao_Get_coeficientes_quaiquer) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p(2, coef_p);
  int coeficiente = 0;
  float esperado = 5.5;
  float atual = p.get(coeficiente);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::get(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      Polinomio: " << MostrarPorExtenso(p) << "\n"
    << "      Coeficiente a[" << coeficiente << "]\n\n"
    << "  Valor esperado:  " << esperado << "\n"
    << "  Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  float coef_p2[] = {5.5, 4.2, 4.1, 8.1, 9.9};
  Polinomio p2(5, coef_p2);
  coeficiente = 3;
  esperado = 8.1;
  atual = p2.get(coeficiente);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::get(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      Polinomio: " << MostrarPorExtenso(p2) << "\n"
    << "      Coeficiente a[" << coeficiente << "]\n\n"
    << "  Valor esperado:  " << esperado << "\n"
    << "  Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Funcao_Set_coeficientes_quaiquer) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p(2, coef_p);
  int coeficiente = 1;
  float esperado = 12.12;
  p.set(coeficiente, 12.12);
  float atual = p.get(coeficiente);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::set(int, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      Polinomio: " << MostrarPorExtenso(p) << "\n"
    << "      Coeficiente a[" << coeficiente << "]\n\n"
    << "  Valor esperado:  " << esperado << "\n"
    << "  Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  float coef_p2[] = {5.5, 4.2, 4.1, 8.1, 9.9};
  Polinomio p2(5, coef_p2);
  coeficiente = 3;
  esperado = 4.258;
  p2.set(coeficiente, 4.258);
  atual = p2.get(coeficiente);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::set(int, float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      Polinomio: " << MostrarPorExtenso(p2) << "\n"
    << "      Coeficiente a[" << coeficiente << "]\n\n"
    << "  Valor esperado:  " << esperado << "\n"
    << "  Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Avaliar_polinomios_com_coeficientes_nao_nulos) {
  float coef_p[] = {4, -2.0, 3, -5, 1};  // P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4.
  Polinomio p(5, coef_p);

  // Avalia P(0.0).
  float x = 0.0;
  float esperado = 4;
  float atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(1.0)
  x = 1.0;
  esperado = 1;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(-1)
  x = -1.0;
  esperado = 15;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Avaliar_polinomios_com_alguns_coeficientes_nulos) {
  float coef_p[] = {5, 0, 3, 0, 2};  // P(x) = 5 + 3x^2 + 2x^4.
  Polinomio p(5, coef_p);

  // Avalia P(0).
  float x = 0.0;
  float esperado = 5;
  float atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(1)
  x = 1.0;
  esperado = 10;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(-1)
  x = -1.0;
  esperado = 10;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Avaliar_polinomios_nas_raizes) {
  float coef_p[] = {6, -5, 1};  // P(x) = 6 - 5x + x^2.
  Polinomio p(3, coef_p);

  // Avalia P(2).
  float x = 2.0;
  float esperado = 0;
  float atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(3)
  x = 3.0;
  esperado = 0;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Avaliar_polinomios_constantes) {
  float coef_p[] = {7};  // P(x) = 7.
  Polinomio p(1, coef_p);

  // Avalia P(0).
  float x = 0.0;
  float esperado = 7;
  float atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(x = 13)
  x = 13.0;
  esperado = 7;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  // Avalia P(x = -13)
  x = -13.0;
  esperado = 7;
  atual = p.Avaliar(x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Polinomio::Avaliar(float) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      x = " << x << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Atribuir_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p(5, coef_p);
  Polinomio novo;
  novo.Atribuir(p);
  ASSERT_EQ(MostrarComoVetor(p), MostrarComoVetor(novo))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Atribuir(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "   Polinomio a atribuir: " << MostrarPorExtenso(p) << "\n"
    << "   Polinomio atribuido: " << MostrarPorExtenso(novo) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_polinomios_com_coeficientes_nao_nulos) {
  float coef_p[] = {1, 2, 3, 4};
  Polinomio p(4, coef_p);
  float coef_q[] = {4, 3, 2, 1};
  Polinomio q(4, coef_q);
  float coef_esperado[] = {5, 5, 5, 5};
  Polinomio esperado(4, coef_esperado);
  Polinomio soma;
  soma.Somar(p, q);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(soma))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Somar(Polinomio, Polimonio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      q = " << MostrarPorExtenso(q) << "\n\n"
    << "   Soma esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Soma retornada: " << MostrarPorExtenso(soma) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, SomarPolinomios_com_alguns_coeficientes_nulos) {
  float coef_p[] = {0, 2, 0, 2};
  Polinomio p(4, coef_p);
  float coef_q[] = {1, 0, 3, 2};
  Polinomio q(4, coef_q);
  float coef_esperado[] = {1, 2, 3, 4};
  Polinomio esperado(4, coef_esperado);
  Polinomio soma;
  soma.Somar(p, q);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(soma))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Somar(Polinomio, Polimonio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n"
    << "      q = " << MostrarPorExtenso(q) << "\n\n"
    << "   Soma esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Soma retornada: " << MostrarPorExtenso(soma) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Derivar_polinomio_de_grau_um) {
  float coef_p[] = {1, 2};
  Polinomio p(2, coef_p);
  float coef_esperado[] = {2};
  Polinomio esperado(1, coef_esperado);
  Polinomio derivada;
  derivada.Derivar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Derivar(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Derivada esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Derivada retornada: " << MostrarPorExtenso(derivada) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Derivar_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p(5, coef_p);
  float coef_esperado[] = {0, 6, 0, 8};
  Polinomio esperado(4, coef_esperado);
  Polinomio derivada;
  derivada.Derivar(p);
    ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Derivar(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Derivada esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Derivada retornada: " << MostrarPorExtenso(derivada) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Integrar_polinomio_de_grau_zero) {
  float coef_p[] = {7};
  Polinomio p(1, coef_p);
  float coef_esperado[] = {0, 7};
  Polinomio esperado(2, coef_esperado);
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Integrar(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Integrar_polinomio_de_grau_um) {
  float coef_p[] = {1, 2};
  Polinomio p(2, coef_p);
  float coef_esperado[] = {0, 1, 1};
  Polinomio esperado(3, coef_esperado);
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Integrar(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Integrar_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p(5, coef_p);
  float coef_esperado[] = {0, 5, 0, 1, 0, 0.4};
  Polinomio esperado(6, coef_esperado);
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Integrar(Polinomio) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
    << "-------------------------------------------------------------------\n";
}

}  // Fim do namespace vazio.

#endif  // POLINOMIO_TEST_POLINOMIO_TEST_H_

