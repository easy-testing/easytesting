// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_TEST_REGISTROS_TEST_H_
#define REGISTROS_TEST_REGISTROS_TEST_H_

#include <math.h>
#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "registros/src/registros.h"

using std::string;
using std::stringstream;

namespace Teste {

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
    t.p1.atribuir(x1, y1);
    t.p2.atribuir(x2, y2);
    t.p3.atribuir(x3, y3);
    return t;
  }

  // Retorna a circunferencia definida como raio r e centro (xc e yc)
  Circunferencia CriaCircunferencia(float r, float xc, float yc) {
    Circunferencia c;
    c.raio = r;
    c.centro.atribuir(xc, yc);
    return c;
  }

  // Retorna o retangulo definido por se e id
  Retangulo CriaRetangulo(float xse, float yse, float xid, float yid) {
    Retangulo r;
    r.se.atribuir(xse, yse);
    r.id.atribuir(xid, yid);
    return r;
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

TEST_F(Teste, PONTO_funcao_atribuir_em_ponto_sem_informacoes) {
  Ponto p;
  float a = 3.4;
  float b = 2.5;
  p.atribuir(a, b);
  ASSERT_FLOAT_EQ(a, p.x)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void PONTO::atribuir(int a, int b) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valor de x da cordenada do ponto esta incorreta apos atribuicao\n\n"
    << "  Valor atribuido: " << a << "\n"
    << " Valor encontrado: " << p.x << "\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_FLOAT_EQ(b, p.y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void PONTO::atribuir(int a, int b) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valor de y da cordenada do ponto esta incorreta apos atribuicao\n\n"
    << "  Valor atribuido: " << b << "\n"
    << " Valor encontrado: " << p.y << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_atribuir_em_ponto_atribuido_anteriormente) {
  Ponto p;
  float a = 3.4;
  float b = 2.5;
  p.atribuir(2, 3);
  p.atribuir(a, b);
  ASSERT_FLOAT_EQ(a, p.x)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void PONTO::atribuir(int a, int b) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valor de x da cordenada do ponto esta incorreta apos atribuicao\n\n"
    << "  Valor atribuido: " << a << "\n"
    << " Valor encontrado: " << p.x << "\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_FLOAT_EQ(b, p.y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void PONTO::atribuir(int a, int b) *\n"
    << "-------------------------------------------------------------------\n"
    << " Valor de y da cordenada do ponto esta incorreta apos atribuicao\n\n"
    << "  Valor atribuido: " << b << "\n"
    << " Valor encontrado: " << p.y << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_no_mesmo_lugar) {
  Ponto p1 = CriaPonto(0, 0);
  Ponto p2 = CriaPonto(0, 0);
  float distancia = p1.distancia(p2);
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_em_mesma_reta_horizontal) {
  Ponto p1 = CriaPonto(5, 0);
  Ponto p2 = CriaPonto(3, 0);
  float distancia = p1.distancia(p2);
  float esperado = 2;
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_em_mesma_reta_vertical) {
  Ponto p1 = CriaPonto(0, 5);
  Ponto p2 = CriaPonto(0, 3);
  float distancia = p1.distancia(p2);
  float esperado = 2;
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_em_qualquer_lugar) {
  Ponto p1 = CriaPonto(0, 1);
  Ponto p2 = CriaPonto(1, 0);
  float distancia = p1.distancia(p2);
  float esperado = sqrt(2);
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float PONTO::distancia(ponto) *\n"
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
    << "* float PONTO::distancia(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << " Ponto1 " << MostrarPonto(p1) << "\n\n"
    << " Ponto2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_perimetro_coordenadas_positivas) {
  Triangulo t = CriaTriangulo(0, 0, 0, 3, 4, 0);
  float perimetro = t.perimetro();
  float esperado = 12;
  ASSERT_FLOAT_EQ(esperado, perimetro)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float TRIANGULO::perimetro(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo : " << MostrarTriangulo(t) << "\n\n"
    << "Lado 1: " << t.p1.distancia(t.p2) << "\n"
    << "Lado 2: " << t.p2.distancia(t.p3) << "\n"
    << "Lado 3: " << t.p3.distancia(t.p1) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_perimetro_coordenadas_negativas) {
  Triangulo t = CriaTriangulo(0, 1, -2, -1, 2, -1);
  float perimetro = t.perimetro();
  float esperado = 4 + sqrt(8) + sqrt(8);
  ASSERT_FLOAT_EQ(esperado, perimetro)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float TRIANGULO::perimetro(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo : " << MostrarTriangulo(t) << "\n\n"
    << "Lado 1: " << t.p1.distancia(t.p2) << "\n"
    << "Lado 2: " << t.p2.distancia(t.p3) << "\n"
    << "Lado 3: " << t.p3.distancia(t.p1) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_area_triangulo_agudo) {
  Triangulo t = CriaTriangulo(0, 0, 1, 1, 2, 0);
  float esperado = 1;
  float area = t.area();
  ASSERT_FLOAT_EQ(esperado, area)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float TRIANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_area_triangulo_retangulo) {
  Triangulo t = CriaTriangulo(0, 0, 0, 3, 4, 0);
  float area = t.area();
  float esperado = 6;
  ASSERT_FLOAT_EQ(esperado, area)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float TRIANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_area_triangulo_obtuso) {
  Triangulo t = CriaTriangulo(0, 0, -1, 2, 2, 0);
  float esperado = 2;
  float area = t.area();
  ASSERT_FLOAT_EQ(esperado, area)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float TRIANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triângulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_equilatero_triangulo_equilatero) {
  Triangulo t = CriaTriangulo(1, 0, -1, 0, 0, sqrt(3));
  ASSERT_TRUE(t.equilatero())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool TRIANGULO::equilatero() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo: " << MostrarTriangulo(t) << " - Equilatero.\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_equilatero_triangulo_nao_equilatero) {
  Triangulo t = CriaTriangulo(0, 0, 0, 3, 4, 0);
  ASSERT_FALSE(t.equilatero())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool TRIANGULO::equilatero() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo: " << MostrarTriangulo(t) << " - Nao Equilatero.\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_semelhante_triangulos_nao_semelhantes) {
  Triangulo t1 = CriaTriangulo(0, 0, 0, 3, 4, 0);
  Triangulo t2 = CriaTriangulo(0, 0, 0, 1, 2, 0);
  ASSERT_FALSE(t1.semelhante(t2))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool TRIANGULO::semelhante() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo 1: " << MostrarTriangulo(t1) << "\n"
    << "Triangulo 2: " << MostrarTriangulo(t2) << "\n\n"
    << "  Esperado : FALSO\n"
    << "  Resultado: SEMELHANTES\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_semelhante_triangulos_semelhantes) {
  Triangulo t1 = CriaTriangulo(0, 0, 0, 4, 4, 0);
  Triangulo t2 = CriaTriangulo(0, 0, 0, 2, 2, 0);
  ASSERT_TRUE(t1.semelhante(t2))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool TRIANGULO::semelhante() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo 1: " << MostrarTriangulo(t1) << "\n"
    << "Triangulo 2: " << MostrarTriangulo(t2) << "\n\n"
    << "  Esperado : SEMELHANTES\n"
    << "  Resultado: FALSO\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_semelhante_triangulos_semelhantes_virados) {
  Triangulo t1 = CriaTriangulo(0, 0, 2, 2, 4, 0);
  Triangulo t2 = CriaTriangulo(0, 1, 2, -1, 4, 1);
  ASSERT_TRUE(t1.semelhante(t2))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool TRIANGULO::semelhante() *\n"
    << "-------------------------------------------------------------------\n"
    << "Triangulo 1: " << MostrarTriangulo(t1) << "\n"
    << "Triangulo 2: " << MostrarTriangulo(t2) << "\n\n"
    << "  Esperado : SEMELHANTES\n"
    << "  Resultado: FALSO\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_perimetro) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  float perimetro_r = r.perimetro();
  float esperado = 8;
  ASSERT_FLOAT_EQ(esperado, perimetro_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float RETANGULO::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
  r = CriaRetangulo(3, 3, 6, 1);
  perimetro_r = r.perimetro();
  esperado = 10;
  ASSERT_FLOAT_EQ(esperado, perimetro_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float RETANGULO::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
  r = CriaRetangulo(2, 2, 3, 1);
  perimetro_r = r.perimetro();
  esperado = 4;
  ASSERT_FLOAT_EQ(esperado, perimetro_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float RETANGULO::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_area) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  float areas = r.area();
  float esperado = 4;
  ASSERT_FLOAT_EQ(esperado, areas)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float RETANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
  r = CriaRetangulo(3, 3, 6, 1);
  areas = r.area();
  esperado = 6;
  ASSERT_FLOAT_EQ(esperado, areas)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float RETANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
  r = CriaRetangulo(2, 2, 3, 1);
  areas = r.area();
  esperado = 1;
  ASSERT_FLOAT_EQ(esperado, areas)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float RETANGULO::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_quadrado_retangulo_quadrado) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  ASSERT_TRUE(r.quadrado())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::quadrado() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_quadrado_retangulo_nao_quadrado) {
  Retangulo r = CriaRetangulo(2, 2, 3, 0);
  ASSERT_FALSE(r.quadrado())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::quadrado() *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_ponto_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  Ponto p = CriaPonto(1, -1);
  ASSERT_TRUE(r.contem(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_ponto_no_limite) {
  Retangulo r = CriaRetangulo(2, 2, 3, 0);
  Ponto p = CriaPonto(2, 2);
  ASSERT_TRUE(r.contem(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_ponto_fora) {
  Retangulo r = CriaRetangulo(2, 2, 3, 0);
  Ponto p = CriaPonto(1, 0);
  ASSERT_FALSE(r.contem(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  Triangulo t = CriaTriangulo(0.1, -0.1, 1.5, -1.5, 1, -1.5);
  ASSERT_TRUE(r.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_com_dois_pontos_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  Triangulo t = CriaTriangulo(1, 1, 1.5, -1.5, -1, -1.5);
  ASSERT_FALSE(r.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_com_um_ponto_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  Triangulo t = CriaTriangulo(1, 1, 1.5, -1.5, -3, -1.5);
  ASSERT_FALSE(r.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_fora) {
  Retangulo r = CriaRetangulo(0, 0, 2, -2);
  Triangulo t = CriaTriangulo(1, 1, 1.5, -2.5, -3, -1.5);
  ASSERT_FALSE(r.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool RETANGULO::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_perimetro_raio_inteiro) {
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  float esperado = 2 * kPi * c.raio;
  float perimetro_c = c.perimetro();
  ASSERT_FLOAT_EQ(esperado, perimetro_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_perimetro_raio_nao_inteiro) {
  Circunferencia c = CriaCircunferencia(1.5, 0, 0);
  float esperado = 2*kPi*c.raio;
  float perimetro_c = c.perimetro();
  ASSERT_FLOAT_EQ(esperado, perimetro_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_perimetro_raio_muito_pequeno) {
  Circunferencia c = CriaCircunferencia(0.01, 0, 0);
  float esperado = 2*kPi*c.raio;
  float perimetro_c = c.perimetro();
  ASSERT_FLOAT_EQ(esperado, perimetro_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_area_raio_inteiro) {
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  float esperado = kPi*c.raio*c.raio;
  float area_c = c.area();
  ASSERT_FLOAT_EQ(esperado, area_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_area_raio_nao_inteiro) {
  Circunferencia c = CriaCircunferencia(1.5, 0, 0);
  float esperado = kPi*c.raio*c.raio;
  float area_c = c.area();
  ASSERT_FLOAT_EQ(esperado, area_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_area_raio_muito_pequeno) {
  Circunferencia c = CriaCircunferencia(0.01, 0, 0);
  float esperado = kPi*c.raio*c.raio;
  float area_c = c.area();
  ASSERT_FLOAT_EQ(esperado, area_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << kPi << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_ponto_dentro) {
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  Ponto p = CriaPonto(1, 1);
  ASSERT_TRUE(c.contem(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_ponto_no_limite) {
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  Ponto p = CriaPonto(5, 0);
  ASSERT_TRUE(c.contem(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_ponto_fora) {
  Circunferencia c = CriaCircunferencia(1.5, 0, 0);
  Ponto p = CriaPonto(1, 2);
  ASSERT_FALSE(c.contem(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_triangulo_dentro) {
  Triangulo t = CriaTriangulo(0, 3, -2, 0, 3, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_TRUE(c.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_triangulo_com_um_ponto_dentro) {
  Triangulo t = CriaTriangulo(0, 3, -6, 0, 7, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_triangulo_com_dois_pontos_dentro) {
  Triangulo t = CriaTriangulo(0, 3, -3, 0, 7, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_triangulo_fora) {
  Triangulo t = CriaTriangulo(0, 8, -6, 0, 7, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_retangulo_dentro) {
  Retangulo r = CriaRetangulo(1, 1, 2, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_TRUE(c.contem(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_retangulo_com_um_ponto_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 6, -6);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_retangulo_com_dois_pontos_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 6, -4);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_retangulo_com_tres_pontos_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 5, -5);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_retangulo_fora) {
  Retangulo r = CriaRetangulo(-8, 8, 8, -8);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.contem(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::contem(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_pertence_ponto_na_circunferencia) {
  Ponto p = CriaPonto(0, 5);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_TRUE(c.pertence(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << p.distancia(c.centro) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_pertence_ponto_dentro) {
  Ponto p = CriaPonto(0, 2);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.pertence(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << p.distancia(c.centro) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_pertence_ponto_fora) {
  Ponto p = CriaPonto(0, 8);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.pertence(p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << p.distancia(c.centro) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_dentro) {
  Triangulo t = CriaTriangulo(0, 0, 1, 1, 2, 1);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.circunscrita(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(t.p1) << "\n"
    << "Vertice 2: " << c.centro.distancia(t.p2) << "\n"
    << "Vertice 3: " << c.centro.distancia(t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_um_ponto_nela) {
  Triangulo t = CriaTriangulo(5, 0, 1, 1, 2, 1);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.circunscrita(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(t.p1) << "\n"
    << "Vertice 2: " << c.centro.distancia(t.p2) << "\n"
    << "Vertice 3: " << c.centro.distancia(t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_dois_pontos_nela) {
  Triangulo t = CriaTriangulo(5, 0, 0, 5, -2, 1);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.circunscrita(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(t.p1) << "\n"
    << "Vertice 2: " << c.centro.distancia(t.p2) << "\n"
    << "Vertice 3: " << c.centro.distancia(t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_inscrito) {
  Triangulo t = CriaTriangulo(5, 0, 0, 5, -5, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_TRUE(c.circunscrita(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(t.p1) << "\n"
    << "Vertice 2: " << c.centro.distancia(t.p2) << "\n"
    << "Vertice 3: " << c.centro.distancia(t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_dentro) {
  Retangulo r = CriaRetangulo(0, 0, 1, -1);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.circunscrita(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(r.se) << "\n"
    << "Vertice 2: " << c.centro.distancia(r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_um_ponto_nela) {
  Retangulo r = CriaRetangulo(0, 10, 10, 5);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.circunscrita(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(r.se) << "\n"
    << "Vertice 2: " << c.centro.distancia(r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_dois_pontos_nela) {
  Retangulo r = CriaRetangulo(0, 10, 5, 0);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_FALSE(c.circunscrita(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(r.se) << "\n"
    << "Vertice 2: " << c.centro.distancia(r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_inscrito) {
  Retangulo r = CriaRetangulo(-2.5, 5 * sqrt(3) / 2, 2.5, -5 * sqrt(3) / 2);
  Circunferencia c = CriaCircunferencia(5, 0, 0);
  ASSERT_TRUE(c.circunscrita(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << c.centro.distancia(r.se) << "\n"
    << "Vertice 2: " << c.centro.distancia(r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

}  // Fim do namespace

#endif  // REGISTROS_TEST_REGISTROS_TEST_H_
