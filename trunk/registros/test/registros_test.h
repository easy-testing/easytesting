// Lista de exercicio sobre estruturas de dados heterogeneas - Registros.

#ifndef REGISTROS_TESTE_H_
#define REGISTROS_TESTE_H_

#include "../registros.h"

#include "../../gtest/gtest.h"
#include <math.h>


#include <string>
#include <sstream>

using std::string;
using std::stringstream;

namespace {

static const float kPi = 3.1416;

class Teste : public testing::Test {
 protected:
  // Retorna o ponto (a, b).
  Ponto CriaPonto(float a, float b) {
    Ponto p;
    p.x = a;
    p.y = b;
    return p;
  }

  // Retorna o triangulo definido pelos pontos (x1, y1), (x2, y12 e (x3, y3).
  Triangulo CriaTriangulo(float x1, float y1,
                          float x2, float y2,
                          float x3, float y3) {
    Triangulo t;
    t.p1.atribuir(x1,y1);
    t.p2.atribuir(x2,y2);
    t.p3.atribuir(x3,y3);
    return t;
  }

  // Retorna uma string no formato (x, y).
  string MostrarPonto(Ponto& p) {
    stringstream output;
    output << "(" << p.x << ", " << p.y << ")";
    return output.str();
  }

  // Retorna uma string no formato {(a,b), (c,d), (e,f)}.
  string MostrarTriangulo(Triangulo& t) {
    stringstream output;
    output << "{(" << t.p1.x << "," << t.p1.y << "), ";
    output << "(" << t.p2.x << "," << t.p2.y << "), ";
    output << "(" << t.p3.x << "," << t.p3.y << ")}";
    return output.str();
  }

  // Retorna uma string no formato retangulo {(x,y), (a,b)}.
  string MostrarRetangulo(Retangulo& r) {
    stringstream output;
    output << "{(" << r.se.x << "," << r.se.y << "), ";
    output << "(" << r.id.x << "," << r.id.y << ")} ";
    return output.str();
  }

  // Retorna string no formto '{centro = (x,y), raio = r}'.
  string MostrarCircunferencia(Circunferencia& c) {
    stringstream output;
    output << "{centro = (" << c.centro.x << "," << c.centro.y << "), ";
    output << "raio = " << c.raio << ")}\n";
    return output.str();
  }
};

TEST_F(Teste, Testa_funcao_distancia_de_Ponto) {
  Ponto p1 = CriaPonto(0, 0);
  Ponto p2 = CriaPonto(0, 0);
  float distancia = p1.distancia(p2);
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, distancia)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";

  p1 = CriaPonto(0, 5);
  p2 = CriaPonto(0, 3);
  distancia = p1.distancia(p2);
  esperado = 2;
  ASSERT_FLOAT_EQ(esperado, distancia)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";

  p1 = CriaPonto(5, 0);
  p2 = CriaPonto(3, 0);
  distancia = p1.distancia(p2);
  esperado = 2;
  ASSERT_FLOAT_EQ(esperado, distancia)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";

  p1 = CriaPonto(0, 1);
  p2 = CriaPonto(1, 0);
  distancia = p1.distancia(p2);
  esperado = sqrt(2);
  ASSERT_FLOAT_EQ(esperado, distancia)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";

  p1 = CriaPonto(0, 0);
  p2 = CriaPonto(1, 1);
  distancia = p1.distancia(p2);
  esperado = sqrt(2);
  ASSERT_FLOAT_EQ(esperado, distancia)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_perimetro_de_Triangulo) {
  Triangulo t = CriaTriangulo(0, 0, 0, 3, 4, 0);
  float perimetro = t.perimetro();
  float esperado = 12;
  ASSERT_FLOAT_EQ(esperado, perimetro)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::perimetro(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo : " << MostrarTriangulo(t) << "\n\n"
    << "Lado 1: " << t.p1.distancia(t.p2) << "\n"
    << "Lado 2: " << t.p2.distancia(t.p3) << "\n"
    << "Lado 3: " << t.p3.distancia(t.p1) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro << "\n"
    << "-------------------------------------------------------------------\n";

  t = CriaTriangulo(0, 1, -2, -1, 2, -1);
  perimetro = t.perimetro();
  esperado = 4 + sqrt(8) + sqrt(8);
  ASSERT_FLOAT_EQ(esperado, perimetro)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::perimetro(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo : " << MostrarTriangulo(t) << "\n\n"
    << "Lado 1: " << t.p1.distancia(t.p2) << "\n"
    << "Lado 2: " << t.p2.distancia(t.p3) << "\n"
    << "Lado 3: " << t.p3.distancia(t.p1) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro << "\n"
    << "-------------------------------------------------------------------\n";
}

// NOTA(Matheus) Como faço entao para definbir um triangulo?
TEST_F(Teste, Testa_funcao_area_de_Triangulo) {
  // Testa para triangulo retangulo.
  Triangulo t = CriaTriangulo(0, 0, 0, 3, 4, 0);
  float area = t.area();
  float esperado = 6;
  ASSERT_FLOAT_EQ(esperado, area)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";

  // Teste para triangulo agudo
  t = CriaTriangulo(0, 0, 1, 1, 2, 0);
  esperado = 1;
  area = t.area();
  ASSERT_FLOAT_EQ(esperado, area)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";

  // Teste para triangulo obtuso
  t = CriaTriangulo(0, 0, -1, 2, 2, 0);
  esperado = 2;
  area = t.area();
  ASSERT_FLOAT_EQ(esperado, area)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";

}

TEST_F(Teste, Testa_funcao_equilatero_de_Triangulo) {
  Triangulo t = CriaTriangulo(0, 0, 0, 3, 4, 0);
  ASSERT_FALSE(t.equilatero())

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::equilatero() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo: " << MostrarTriangulo(t) << " nao eh equilatero.\n\n"
    << "-------------------------------------------------------------------\n";

  t = CriaTriangulo(1, 0, -1, 0, 0, sqrt(3));
  ASSERT_TRUE(t.equilatero())

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::equilatero() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo: " << MostrarTriangulo(t) << " eh equilatero.\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_semelhante_de_Triangulo) {
  Triangulo t1 = CriaTriangulo(0, 0, 0, 3, 4, 0);
  Triangulo t2 = CriaTriangulo(0, 0, 0, 1, 2, 0);
  ASSERT_FALSE(t1.semelhante(t2))

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::semelhante() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo 1: " << MostrarTriangulo(t1) << "\n"
    << "Triangulo 2: " << MostrarTriangulo(t2) << "\n\n"
    << "  Esperado : FALSO\n"
    << "  Resultado: SEMELHANTES\n"
    << "-------------------------------------------------------------------\n";

  t1 = CriaTriangulo(0, 0, 0, 4, 4, 0);
  t2 = CriaTriangulo(0, 0, 0, 2, 2, 0);
  ASSERT_TRUE(t1.semelhante(t2))

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::semelhante() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo 1: " << MostrarTriangulo(t1) << "\n"
    << "Triangulo 2: " << MostrarTriangulo(t2) << "\n\n"
    << "  Esperado : SEMELHANTES\n"
    << "  Resultado: FALSO\n"
    << "-------------------------------------------------------------------\n";

  t1 = CriaTriangulo(0, 0, 2, 2, 4, 0);
  t2 = CriaTriangulo(0, 1, 2, -1, 4, 1);
  ASSERT_TRUE(t1.semelhante(t2))

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* TRIANGULO::semelhante() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo 1: " << MostrarTriangulo(t1) << "\n"
    << "Triangulo 2: " << MostrarTriangulo(t2) << "\n\n"
    << "  Esperado : SEMELHANTES\n"
    << "  Resultado: FALSO\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_Avaliar_calculo_de_perimetro) {
  Retangulo r;

  r.se.atribuir(0, 0);
  r.id.atribuir(2, -2);

  float perimetro_r = r.perimetro();
  float esperado = 8;

  ASSERT_FLOAT_EQ(esperado, perimetro_r)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(3, 3);
  r.id.atribuir(6, 1);

  perimetro_r = r.perimetro();
  esperado = 10;

  ASSERT_FLOAT_EQ(esperado, perimetro_r)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(2, 2);
  r.id.atribuir(3, 1);

  perimetro_r = r.perimetro();
  esperado = 4;

  ASSERT_FLOAT_EQ(esperado, perimetro_r)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_Avaliar_calculo_da_area) {
  Retangulo r;

  r.se.atribuir(0, 0);
  r.id.atribuir(2, -2);

  float areas = r.area();
  float esperado = 4;

  ASSERT_EQ(esperado, areas)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(3, 3);
  r.id.atribuir(6, 1);

  areas = r.area();
  esperado = 6;

  ASSERT_EQ(esperado, areas)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(2, 2);
  r.id.atribuir(3, 1);

  areas = r.area();
  esperado = 1;

  ASSERT_EQ(esperado, areas)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_Avaliar_teste_retangulo_quadrado) {
  Retangulo r;

  r.se.atribuir(0, 0);
  r.id.atribuir(2, -2);

  bool quadrados = r.quadrado();
  bool esperado = true;

  ASSERT_EQ(esperado, quadrados)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::quadrado() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << quadrados << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(2, 2);
  r.id.atribuir(3, 0);

  quadrados = r.quadrado();
  esperado = false;

  ASSERT_EQ(esperado, quadrados)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::quadrado() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << quadrados << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_Avaliar_teste_retangulo_contem_ponto) {
  Retangulo r;

  r.se.atribuir(0, 0);
  r.id.atribuir(2, -2);

  Ponto p;

  p.atribuir(1, -1);

  bool contem_ponto = r.contem(p);
  bool esperado = true;

  ASSERT_EQ(true, contem_ponto)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_ponto << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(2, 2);
  r.id.atribuir(3, 0);

  p.atribuir(1, 1);

  contem_ponto = r.contem(p);
  esperado = false;

  ASSERT_EQ(esperado, contem_ponto)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_ponto << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_Avaliar_teste_retangulo_contem_triangulo) {
  Retangulo r;

  r.se.atribuir(0, 0);
  r.id.atribuir(2, -2);

  Triangulo t;

  t.p1.atribuir(1.5, -0.1);
  t.p2.atribuir(0.5, -1.5);
  t.p3.atribuir(1.5, -1.5);

  bool contem_triangulo = r.contem(t);
  bool esperado = true;

  ASSERT_FLOAT_EQ(esperado, contem_triangulo)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_triangulo << "\n"
    << "-------------------------------------------------------------------\n";

  r.se.atribuir(2, 2);
  r.id.atribuir(3, 0);

  t.p1.atribuir(1.5, 0.1);
  t.p2.atribuir(0.5, -1.5);
  t.p3.atribuir(1.5, -1.5);

  contem_triangulo = r.contem(t);
  esperado = false;

  ASSERT_FLOAT_EQ(esperado, contem_triangulo)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* RETANGULO::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_triangulo << "\n"
    << "-------------------------------------------------------------------\n";
}
  // **FUNÇÕES QUE TESTAM A STRUCT CIRCUNFERENCIA**

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_calculo_do_perimetro) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  float esperado = 2 * kPi * c.raio;
  float perimetro_c = c.perimetro();

  ASSERT_FLOAT_EQ(esperado, perimetro_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(0, 0);
  c.raio = 1.5;

  esperado = 2*kPi*c.raio;
  perimetro_c = c.perimetro();

  ASSERT_FLOAT_EQ(esperado, perimetro_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(0, 0);
  c.raio = 0.01;

  esperado = 2*kPi*c.raio;
  perimetro_c = c.perimetro();

  ASSERT_FLOAT_EQ(esperado, perimetro_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_calculo_da_area) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  float esperado = kPi*c.raio*c.raio;
  float area_c = c.area();

  ASSERT_FLOAT_EQ(esperado, area_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(0, 0);
  c.raio = 1.5;

  esperado = kPi*c.raio*c.raio;
  area_c = c.area();

  ASSERT_FLOAT_EQ(esperado, area_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(0, 0);
  c.raio = 0.05;

  esperado = kPi*c.raio*c.raio;
  area_c = c.area();

  ASSERT_FLOAT_EQ(esperado, area_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

// NOTA(Matheus): Se o ponto estiver no circulo da circunferência devo
// considerar que essa circunferência contém o ponto, ou só contém
// se o ponto estiver dentro dela?
TEST_F(Teste, CIRCUNFERENCIA_Avaliar_teste_contem_ponto) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  Ponto p;

  p.atribuir(1, 1);

  bool esperado = true;
  bool contem_c = c.contem(p);

  ASSERT_EQ(esperado, contem_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(0, 0);
  c.raio = 1.5;

  p.atribuir(1, 2);

  esperado = false;
  contem_c = c.contem(p);

  ASSERT_EQ(esperado, contem_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_teste_contem_triangulo) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  Triangulo t;

  t.p1.atribuir(1, 1);
  t.p2.atribuir(2, 1);
  t.p3.atribuir(2, 2);

  bool esperado = true;
  bool contem_c = c.contem(t);

  ASSERT_EQ(esperado, contem_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(5, 0);
  c.raio = 5;

  t.p1.atribuir(1, -1);
  t.p2.atribuir(-2, 1);
  t.p3.atribuir(2, 2);

  esperado = false;
  contem_c = c.contem(t);

  ASSERT_EQ(esperado, contem_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_teste_contem_retangulo) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  Retangulo r;

  r.se.atribuir(1, 1);
  r.id.atribuir(2, 0);

  bool esperado = true;
  bool contem_c = c.contem(r);

  ASSERT_EQ(esperado, contem_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_c << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(5, 0);
  c.raio = 5;

  r.se.atribuir(-3, 3);
  r.id.atribuir(0, 0);

  esperado = false;
  contem_c = c.contem(r);

  ASSERT_EQ(esperado, contem_c)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << contem_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_teste_ponto_pertence) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  Ponto p;

  p.atribuir(0, 5);

  bool esperado = true;
  bool pertencer = c.pertence(p);

  ASSERT_EQ(esperado, pertencer)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << p.distancia(c.centro) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << pertencer << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(0, 0);
  c.raio = 5;

  p.atribuir(1, 3);

  esperado = false;
  pertencer = c.pertence(p);

  ASSERT_EQ(esperado, pertencer)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << p.distancia(c.centro) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << pertencer << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_teste_triangulo_circunscrito) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  Triangulo t;

  t.p1.atribuir(0, 5);
  t.p2.atribuir(5, 0);
  t.p3.atribuir(0, -5);

  bool esperado = true;
  bool circunscrever = c.circunscrita(t);

  ASSERT_EQ(esperado, circunscrever)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(t.p1) << "\n"
    << "Vertice 2: " << c.centro.distancia(t.p2) << "\n"
    << "Vertice 3: " << c.centro.distancia(t.p3) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << circunscrever << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(1, 3);
  c.raio = 2;


  t.p1.atribuir(0, 5);
  t.p2.atribuir(5, 0);
  t.p3.atribuir(0, -5);

  esperado = false;
  circunscrever = c.circunscrita(t);

  ASSERT_EQ(esperado, circunscrever)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(t.p1) << "\n"
    << "Vertice 2: " << c.centro.distancia(t.p2) << "\n"
    << "Vertice 3: " << c.centro.distancia(t.p3) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << circunscrever << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_Avaliar_teste_retangulo_circunscrito) {
  Circunferencia c;

  c.centro.atribuir(0, 0);
  c.raio = 5;

  Retangulo r;

  r.se.atribuir(-3, 4);
  r.id.atribuir(3, -4);

  bool esperado = true;
  bool circunscrever = c.circunscrita(r);

  ASSERT_EQ(esperado, circunscrever)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << circunscrever << "\n"
    << "-------------------------------------------------------------------\n";

  c.centro.atribuir(1, 3);
  c.raio = 2;


  r.se.atribuir(0, 2);
  r.id.atribuir(2, 0);

  esperado = false;
  circunscrever = c.circunscrita(r);

  ASSERT_EQ(esperado, circunscrever)

    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << circunscrever << "\n"
    << "-------------------------------------------------------------------\n";
}

}  // Fim do namespace

#endif  // REGISTROS_TESTE_H_
