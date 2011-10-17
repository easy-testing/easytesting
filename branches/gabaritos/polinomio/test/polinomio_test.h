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
  // Retorna uma string no formato a + bx + cx^2 + dx^3 + ... + zx^n.
  string MostrarPorExtenso(Polinomio& p) {
    stringstream s;
    // Trata o caso P(x) = 0.
    if (p.n_ == 0) {
      return "0";
    }

    bool primeiro = true;
    for (int i = 0; i <= p.grau(); i++) {
      if (p.coeficientes_[i] != 0.0) {
        if (primeiro) {
          s << p.coeficientes_[i];
          primeiro = false;
        } else {
          if (p.coeficientes_[i] == 1.0) {
            s << " + ";
          } else if (p.coeficientes_[i] > 0.0) {
            s << " + " << p.coeficientes_[i];
          } else if (p.coeficientes_[i] < 0.0) {
            s << " - " << -p.coeficientes_[i];
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

  void Inicializar(int n, float v[], Polinomio* p) {
    p->n_ = n;
    delete [] p->coeficientes_;
    p->coeficientes_ = new float[n];
    for (int i = 0; i < n; i++) {
      p->coeficientes_[i] = v[i];
    }
  }

  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string MostrarComoVetor(Polinomio& p) {
    stringstream output;
    output << "{" << p.coeficientes_[0];
    for (int i = 1; i <= p.grau() ; i++) {
      output << ", " << p.coeficientes_[i];
    }
    output << "}";
    return output.str();
  }
};


TEST_F(Teste, Testa_o_metodo_MostrarPorExtenso) {
  Polinomio nulo;
  ASSERT_EQ("0", MostrarPorExtenso(nulo));

  float coef_p[] = {4, -2.7, 3.8, -5, 1};
  Polinomio p;
  Inicializar(5, coef_p, &p);
  ASSERT_EQ("4 - 2.7x + 3.8x^2 - 5x^3 + x^4", MostrarPorExtenso(p));

  float coef_q[] = {0, -0.2, 0, 3, -1};
  Polinomio q;
  Inicializar(5, coef_q, &q);
  ASSERT_EQ("-0.2x + 3x^3 - 1x^4", MostrarPorExtenso(q));

  float coef_t[] = {0, 0, 0, 3, -1};
  Polinomio t;
  Inicializar(5, coef_t, &t);
  ASSERT_EQ("3x^3 - 1x^4", MostrarPorExtenso(t));
}

TEST_F(Teste, Testar_Funcao_Grau_Polinomio_grau_um) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
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
  Polinomio p;
  Inicializar(4, coef_p, &p);
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

TEST_F(Teste, Testar_funcao_at_coeficientes_quaisquer) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
  int coeficiente = 0;
  float esperado = 5.5;
  float atual = p.at(coeficiente);
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
  Polinomio p2(4);
  Inicializar(5, coef_p2, &p2);
  coeficiente = 3;
  esperado = 8.1;
  atual = p2.at(coeficiente);
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

TEST_F(Teste, Testar_Funcao_at_em_atribuicao_de_valores) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
  int coeficiente = 1;
  float esperado = 12.12;
  p.at(coeficiente) = 12.12;
  float atual = p.at(coeficiente);
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
  Polinomio p2;
  Inicializar(5, coef_p2, &p2);
  Inicializar(5, coef_p2, &p2);
  coeficiente = 3;
  esperado = 4.258;
  p2.at(coeficiente) = 4.258;
  atual = p2.at(coeficiente);
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

TEST_F(Teste, Testar_operador_at_coeficientes_quaisquer) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
  int coeficiente = 0;
  float esperado = 5.5;
  float atual = p[coeficiente];
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
  Polinomio p2(4);
  Inicializar(5, coef_p2, &p2);
  coeficiente = 3;
  esperado = 8.1;
  atual = p2[coeficiente];
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

TEST_F(Teste, Testar_operador_at_em_atribuicao_de_valores) {
  float coef_p[] = {5.5, 4.2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
  int coeficiente = 1;
  float esperado = 12.12;
  p.at(coeficiente) = 12.12;
  float atual = p[coeficiente];
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
  Polinomio p2(4);
  Inicializar(5, coef_p, &p2);
  coeficiente = 3;
  esperado = 4.258;
  p2.at(coeficiente) = 4.258;
  atual = p2[coeficiente];
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
  Polinomio p;
  Inicializar(5, coef_p, &p);

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
  Polinomio p;
  Inicializar(5, coef_p, &p);

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
  Polinomio p;
  Inicializar(3, coef_p, &p);

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
  Polinomio p(0);
  Inicializar(1, coef_p, &p);

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

TEST_F(Teste, Operador_avaliar_polinomios_com_coeficientes_nao_nulos) {
  float coef_p[] = {4, -2.0, 3, -5, 1};  // P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4.
  Polinomio p;
  Inicializar(5, coef_p, &p);

  // Avalia P(0.0).
  float x = 0.0;
  float esperado = 4;
  float atual = p(x);
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
  atual = p(x);
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
  atual = p(x);
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

TEST_F(Teste, Operador_avaliar_polinomios_com_alguns_coeficientes_nulos) {
  float coef_p[] = {5, 0, 3, 0, 2};  // P(x) = 5 + 3x^2 + 2x^4.
  Polinomio p;
  Inicializar(5, coef_p, &p);

  // Avalia P(0).
  float x = 0.0;
  float esperado = 5;
  float atual = p(x);
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
  atual = p(x);
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
  atual = p(x);
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

TEST_F(Teste, Operador_avaliar_polinomios_nas_raizes) {
  float coef_p[] = {6, -5, 1};  // P(x) = 6 - 5x + x^2.
  Polinomio p;
  Inicializar(3, coef_p, &p);

  // Avalia P(2).
  float x = 2.0;
  float esperado = 0;
  float atual = p(x);
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
  atual = p(x);
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

TEST_F(Teste, Operador_avaliar_polinomios_constantes) {
  float coef_p[] = {7};  // P(x) = 7.
  Polinomio p(0);
  Inicializar(1, coef_p, &p);

  // Avalia P(0).
  float x = 0.0;
  float esperado = 7;
  float atual = p(x);
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
  atual = p(x);
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
  atual = p(x);
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
  Polinomio p;
  Inicializar(5, coef_p, &p);
  Polinomio novo;
  novo.Atribuir(p);
  ASSERT_EQ(MostrarComoVetor(p), MostrarComoVetor(novo))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Atribuir(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "   Polinomio a atribuir: " << MostrarPorExtenso(p) << "\n"
    << "   Polinomio atribuido: " << MostrarPorExtenso(novo) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Operador_atribuicao_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p;
  Inicializar(5, coef_p, &p);
  Polinomio novo;
  novo = p;
  ASSERT_EQ(MostrarComoVetor(p), MostrarComoVetor(novo))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Atribuir(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "   Polinomio a atribuir: " << MostrarPorExtenso(p) << "\n"
    << "   Polinomio atribuido: " << MostrarPorExtenso(novo) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Derivar_polinomio_de_grau_um) {
  float coef_p[] = {1, 2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
  float coef_esperado[] = {2};
  Polinomio esperado;
  Inicializar(1, coef_esperado, &esperado);
  Polinomio derivada;
  derivada.Derivar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Derivar(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Derivada esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Derivada retornada: " << MostrarPorExtenso(derivada) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Derivar_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p;
  Inicializar(5, coef_p, &p);
  float coef_esperado[] = {0, 6, 0, 8};
  Polinomio esperado;
  Inicializar(4, coef_esperado, &esperado);
  Polinomio derivada;
  derivada.Derivar(p);
    ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Derivar(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Derivada esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Derivada retornada: " << MostrarPorExtenso(derivada) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Integrar_polinomio_de_grau_zero) {
  float coef_p[] = {7};
  Polinomio p;
  Inicializar(1, coef_p, &p);
  float coef_esperado[] = {0, 7};
  Polinomio esperado;
  Inicializar(2, coef_esperado, &esperado);
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Integrar(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Integrar_polinomio_de_grau_um) {
  float coef_p[] = {1, 2};
  Polinomio p;
  Inicializar(2, coef_p, &p);
  float coef_esperado[] = {0, 1, 1};
  Polinomio esperado;
  Inicializar(3, coef_esperado, &esperado);
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Integrar(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Integrar_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p;
  Inicializar(5, coef_p, &p);
  float coef_esperado[] = {0, 5, 0, 1, 0, 0.4};
  Polinomio esperado;
  Inicializar(6, coef_esperado, &esperado);
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void Polinomio::Integrar(Polinomio& q) *\n"
    << "-------------------------------------------------------------------\n"
    << "      p = " << MostrarPorExtenso(p) << "\n\n"
    << "   Integral esperada : " << MostrarPorExtenso(esperado) << "\n"
    << "   Integral retornada: " << MostrarPorExtenso(integral) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // POLINOMIO_TEST_POLINOMIO_TEST_H_

