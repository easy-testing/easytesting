// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_POLINOMIO_TEST_POLINOMIO_TEST_H_
#define TRUNK_POLINOMIO_TEST_POLINOMIO_TEST_H_

#include <sstream>
#include <string>
#include "polinomio/src/polinomio.h"
#include "gtest/gtest.h"

#define MAX 100

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


TEST_F(Teste, Testa_ToString) {
  float v[] = {7};
  ASSERT_EQ("7", Imprimir(0, v))
      << Imprimir(0, v);

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

TEST_F(Teste, Testa_Avaliar_com_polinomio_com_coeficientes_nao_nulos) {
  float v[] = {4, -2.0, 3, -5, 1};  // P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4.
  float g = 4;
  float x = 0;
  float esperado = 4;
  float atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = 1;
  esperado = 1;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = -1;
  esperado = 15;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Avaliar_com_polinomio_com_alguns_coeficientes_nulos) {
  float v[] = {5, 0, 3, 0, 2};  // P(x) = 5 + 3x^2 + 2x^4.
  int g = 4;

  float x = 0;
  float esperado = 5;
  float atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = 1;
  esperado = 10;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = -1;
  esperado = 10;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Avaliar_nas_raizes_do_polinomio) {
  float v[] = {6, -5, 1};  // P(x) = 6 - 5x + x^2.
  int g = 2;

  float x = 2;
  float esperado = 0;
  float atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = 3;
  esperado = 0;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
  }

TEST_F(Teste, Testa_Avaliar_com_polinomio_de_grau_zero) {
  float v[] = {7};  // P(x) = 7.
  int g = 0;

  float x = 0;
  float esperado = 7;
  float atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = 13;
  esperado = 7;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";

  x = -13;
  esperado = 7;
  atual = Avaliar(g, v, x);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: float Avaliar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << Imprimir(g, v) << "\n"
    << "  x = " << x << "\n"
    << "Valor esperado : " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Atribuir_com_polinomio_de_grau_zero) {
  int g = 0;
  float inicial[] = {-5};
  float esperado[] = {-5};
  float atual[MAX];
  Atribuir(g, inicial, atual);
  ASSERT_EQ(ToString(g, esperado), ToString(g, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Atribuir(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g, esperado) << "\n"
    << "Retornado = " << Imprimir(g, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Atribuir_com_polinomio_de_grau_maior_que_zero) {
  int g = 4;
  float inicial[] = {5, 0, 3, 0, 2};
  float esperado[] =  {5, 0, 3, 0, 2};
  float atual[MAX];
  Atribuir(g, inicial, atual);
  ASSERT_EQ(ToString(g, esperado), ToString(g, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Atribuir(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g, esperado) << "\n"
    << "Retornado = " << Imprimir(g, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Derivar_com_polinomio_de_grau_um) {
  int g = 1;
  float inicial[] = {-1, 5};
  float esperado[] = {5};
  float atual[MAX];
  Derivar(g, inicial, atual);
  ASSERT_EQ(ToString(g - 1, esperado), ToString(g - 1, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Derivar(int g, float v[], float u[]) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g - 1, esperado) << "\n"
    << "Retornado = " << Imprimir(g - 1, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Derivar_com_polinomio_de_grau_maior_que_um) {
  int g = 4;
  float inicial[] = {5, 0, 3, 0, 2};
  float esperado[] = {0, 6, 0, 8};
  float atual[MAX];
  Derivar(g, inicial, atual);
  ASSERT_EQ(ToString(g - 1, esperado), ToString(g - 1, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Derivar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g - 1, esperado) << "\n"
    << "Retornado = " << Imprimir(g - 1, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Integrar_com_polinomio_de_grau_zero) {
  int g = 0;
  float inicial[] = {7};
  float esperado[] = {0, 7};
  float atual[MAX];
  Integrar(g, inicial, atual);
  ASSERT_EQ(ToString(g + 1, esperado), ToString(g + 1, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Derivar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g + 1, esperado) << "\n"
    << "Retornado = " << Imprimir(g + 1, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Integrar_com_polinomio_de_grau_um) {
  int g = 1;
  float inicial[] = {1, 2};
  float esperado[] = {0, 1, 1};
  float atual[MAX];
  Integrar(g, inicial, atual);
  ASSERT_EQ(ToString(g + 1, esperado), ToString(g + 1, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Derivar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g + 1, esperado) << "\n"
    << "Retornado = " << Imprimir(g + 1, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}
TEST_F(Teste, Testa_Integrar_com_polinomio_de_grau_maior_que_um) {
  int g = 4;
  float inicial[] = {5, 0, 3, 0, 2};
  float esperado[] = {0, 5, 0, 1, 0, 0.4};
  float atual[MAX];
  Integrar(g, inicial, atual);
  ASSERT_EQ(ToString(g + 1, esperado), ToString(g + 1, atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void Derivar(int g, float v[], float x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Inicial = " << Imprimir(g, inicial) << "\n"
    << "Esperado = " << Imprimir(g + 1, esperado) << "\n"
    << "Retornado = " << Imprimir(g + 1, atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_POLINOMIO_TEST_POLINOMIO_TEST_H_

