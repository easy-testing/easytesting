#ifndef TEST_H_
#define TEST_H_

#include "easytesting/polinomio/src/polinomio.h"
#include "easytesting/gtest/gtest.h"

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

namespace {

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
      	    s << " + ";       ;
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


TEST_F(Teste, Avaliar_polinomios_com_coeficientes_nao_nulos) {
  float coef_p[] = {4, -2.0, 3, -5, 1};  // P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4.
  Polinomio p(5, coef_p);

  // Avalia P(x = 0.0).
  float x = 0.0;
  ASSERT_EQ(4, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 4 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4\n"
    << "P(0.0) = 4 - 2*0 + 3*0^2 - 5*0^3 + 0^4 = 4.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = 1.0)
  x = 1.0;
  ASSERT_EQ(1, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 1.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4\n"
    << "P(1.0) = 4 - 2*1 + 3*1^2 - 5*1^3 + 1^4 = 1.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = -1)
  x = -1.0;
  ASSERT_EQ(15, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 15.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 4 - 2x + 3x^2 - 5x^3 + x^4\n"
    << "P(-1.0) = 4 - 2*(-1) + 3*(-1)^2 - 5*(-1)^3 + (-1)^4 = 15.0\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Avaliar_polinomios_com_alguns_coeficientes_nulos) {
  float coef_p[] = {5, 0, 3, 0, 2};  // P(x) = 5 + 3x^2 + 2x^4.
  Polinomio p(5, coef_p);

  // Avalia P(x = 0).
  float x = 0.0;
  ASSERT_EQ(5, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 5.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 5 + 3x^2 + 2x^4\n"
    << "P(0.0) = 5 + 3*0^2 + 2*0^4 = 5.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = 1)
  x = 1.0;
  ASSERT_EQ(10, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 10.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 5 + 3x^2 + 2x^4\n"
    << "P(1.0) = 5 + 3*1^2 + 2*1^4 = 10.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = -1)
  x = -1.0;
  ASSERT_EQ(10, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 10.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 5 + 3x^2 + 2x^4\n"
    << "P(-1.0) = 5 + 3*(-1)^2 + 2*(-1)^4 = 10.0\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Avaliar_polinomios_nas_raizes) {
  float coef_p[] = {6, -5, 1};  // P(x) = 6 - 5x + x^2.
  Polinomio p(3, coef_p);

  // Avalia P(x = 2).
  float x = 2.0;
  ASSERT_EQ(0, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 0.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 6 - 5x + x^2\n"
    << "P(2.0) = 6 - 5*2 + 2^2 = 0.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = 3)
  x = 3.0;
  ASSERT_EQ(0, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(x)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      x = " << x << "\n"
    << "   Valor esperado : " << 0.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 6 - 5x + x^2\n"
    << "P(3.0) = 6 - 5*3 + 3^2 = 0.0\n"
    << "------------------------------------------------------------\n";
}


// TODO(tfn): Padronizar mensagem de erro.
TEST_F(Teste, Avaliar_polinomios_constantes) {
  float coef_p[] = {7};  // P(x) = 7.
  Polinomio p(1, coef_p);

  // Avalia P(x = 0).
  float x = 0.0;
  ASSERT_EQ(7, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(0.0)\n"
    << "   Valor esperado : " << 7.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 7.0\n"
    << "P(0.0) = 7.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = 13)
  x = 13.0;
  ASSERT_EQ(7, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "p.Avaliar(0.0)\n"
    << "   Valor esperado : " << 7.0 << "\n"
    << "   Valor retornado: " << p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 7.0\n"
    << "P(13.0) = 7.0\n"
    << "------------------------------------------------------------\n";

  // Avalia P(x = -13)
  x = -13.0;
  ASSERT_EQ(7, p.Avaliar(x))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "AvaliarPolinomio(0, {7}, 0.0)\n"
    << "   Valor esperado : " << 7.0 << "\n"
    << "   Valor retornado: " <<  p.Avaliar(x) << "\n"
    << "Exemplo:\n"
    << "P(x) = 7.0\n"
    << "P(-13.0) = 7.0\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Atribuir_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p(5, coef_p);

  float coef_esperado[] = {5, 0, 3, 0, 2};
  Polinomio esperado(5, coef_esperado);

  // Calcula a deriva de p.
  Polinomio novo;
  novo.Atribuir(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(novo))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "novo.Atribuir(p)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      'novo' eh o polinomio que deve ficar igual a p.\n"
    << "   Resultado esperado : novo == "
    << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: novo == "
    << MostrarComoVetor(novo) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   Q(x) = P(X) = " << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(novo) << "\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Somar_polinomios_com_coeficientes_nao_nulos) {
  float coef_p[] = {1, 2, 3, 4};
  Polinomio p(4, coef_p);

  float coef_q[] = {4, 3, 2, 1};
  Polinomio q(4, coef_q);

  float coef_esperado[] = {5, 5, 5, 5};
  Polinomio esperado(4, coef_esperado);

  // Soma p1 e p2.
  Polinomio soma;
  soma.Somar(p, q);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(soma))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "soma.Somar(p, q)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      q = " << MostrarComoVetor(q) << "\n"
    << "      'soma' eh o polinomio que armazena a soma.\n"
    << "   Resultado esperado : soma == " << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: soma == " << MostrarComoVetor(soma) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   Q(x) = " << MostrarPorExtenso(q) << "\n"
    << "   P(x) + Q(x) = "
    << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(soma) << "\n"
    << "------------------------------------------------------------\n";

}


TEST_F(Teste, SomarPolinomios_com_alguns_coeficientes_nulos) {
  float coef_p[] = {0, 2, 0, 2};
  Polinomio p(4, coef_p);

  float coef_q[] = {1, 0, 3, 2};
  Polinomio q(4, coef_q);

  float coef_esperado[] = {1, 2, 3, 4};
  Polinomio esperado(4, coef_esperado);

  // Soma p1 e p2.
  Polinomio soma;
  soma.Somar(p, q);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(soma))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "soma.Somar(p, q)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      q = " << MostrarComoVetor(q) << "\n"
    << "      'soma' eh o polinomio que armazena a soma.\n"
    << "   Resultado esperado : soma == " << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: soma == " << MostrarComoVetor(soma) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   Q(x) = " << MostrarPorExtenso(q) << "\n"
    << "   P(x) + Q(x) = "
    << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(soma) << "\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Derivar_polinomio_de_grau_um) {
  float coef_p[] = {1, 2};
  Polinomio p(2, coef_p);

  float coef_esperado[] = {2};
  Polinomio esperado(1, coef_esperado);

  // Calcula a deriva de p.
  Polinomio derivada;
  derivada.Derivar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "derivada.Derivar(p)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      'derivada' eh o polinomio que armazena a derivada de p.\n"
    << "   Resultado esperado : derivada == "
    << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: derivada == "
    << MostrarComoVetor(derivada) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   P'(x) = " << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(derivada) << "\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Derivar_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p(5, coef_p);

  float coef_esperado[] = {0, 6, 0, 8};
  Polinomio esperado(4, coef_esperado);

  // Calcula a deriva de p.
  Polinomio derivada;
  derivada.Derivar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(derivada))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "derivada.Derivar(p)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      'derivada' eh o polinomio que armazena a derivada de p.\n"
    << "   Resultado esperado : derivada == "
    << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: derivada == "
    << MostrarComoVetor(derivada) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   P'(x) = " << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(derivada) << "\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Integrar_polinomio_de_grau_zero) {
  float coef_p[] = {7};
  Polinomio p(1, coef_p);

  float coef_esperado[] = {0, 7};
  Polinomio esperado(2, coef_esperado);

  // Calcula a integral de p.
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "integral.Integrar(p)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      'integral' eh o polinomio que armazena a integral de p.\n"
    << "   Resultado esperado : integral == "
    << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: integral == "
    << MostrarComoVetor(integral) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   integral[P](x) = " << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(integral) << "\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Integrar_polinomio_de_grau_um) {
  float coef_p[] = {1, 2};
  Polinomio p(2, coef_p);

  float coef_esperado[] = {0, 1, 1};
  Polinomio esperado(3, coef_esperado);

  // Calcula a integral de p.
  Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "integral.Integrar(p)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      'integral' eh o polinomio que armazena a integral de p.\n"
    << "   Resultado esperado : integral == "
    << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: integral == "
    << MostrarComoVetor(integral) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   integral[P](x) = " << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(integral) << "\n"
    << "------------------------------------------------------------\n";
}


TEST_F(Teste, Integrar_polinomio_de_grau_maior_que_um) {
  float coef_p[] = {5, 0, 3, 0, 2};
  Polinomio p(5, coef_p);

  float coef_esperado[] = {0, 5, 0, 1, 0, 0.4};
  Polinomio esperado(6, coef_esperado);

  // Calcula a integral de p.
 Polinomio integral;
  integral.Integrar(p);
  ASSERT_EQ(MostrarComoVetor(esperado), MostrarComoVetor(integral))
    << "------------------------------------------------------------\n"
    << "Erro na chamada da funcao: "
    << "integral.Integrar(p)\n"
    << "   onde:\n"
    << "      p = " << MostrarComoVetor(p) << "\n"
    << "      'integral' eh o polinomio que armazena a integral de p.\n"
    << "   Resultado esperado : integral == "
    << MostrarComoVetor(esperado) << "\n"
    << "   Resultado da funcao: integral == "
    << MostrarComoVetor(integral) << "\n"
    << "Exemplo:\n"
    << "   P(x) = " << MostrarPorExtenso(p) << "\n"
    << "   integral[P](x) = " << MostrarPorExtenso(esperado) << "\n"
    << "   Sua funcao retornou o polinomio: "
    << MostrarPorExtenso(integral) << "\n"
    << "------------------------------------------------------------\n";
}


} // Fim do namespace vazio.

#endif  // TEST_H_


