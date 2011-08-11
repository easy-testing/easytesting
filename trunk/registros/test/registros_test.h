// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_TEST_REGISTROS_TEST_H_
#define REGISTROS_TEST_REGISTROS_TEST_H_

#include <math.h>
#include <string>
#include <sstream>

#include "gtest/gtest.h"
#include "registros/src/circunferencia.h"
#include "registros/src/ponto.h"
#include "registros/src/retangulo.h"
#include "registros/src/triangulo.h"

using std::string;
using std::stringstream;

namespace Teste {

class Teste : public testing::Test {
 protected:
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

TEST_F(Teste, PONTO_funcao_distancia_pontos_no_mesmo_lugar) {
  Ponto p1 = {0, 0};
  Ponto p2 = {0, 0};
  float distancia = Distancia(p1, p2);
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Distancia(p1, p2) *\n"
    << "-------------------------------------------------------------------\n"
    << " p1 " << MostrarPonto(p1) << "\n\n"
    << " p2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_em_mesma_reta_horizontal) {
  Ponto p1 = {5, 0};
  Ponto p2 = {3, 0};
  float distancia = Distancia(p1, p2);
  float esperado = 2;
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Distancia(p1, p2) *\n"
    << "-------------------------------------------------------------------\n"
    << " p1 " << MostrarPonto(p1) << "\n\n"
    << " p2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_em_mesma_reta_vertical) {
  Ponto p1 = {0, 5};
  Ponto p2 = {0, 3};
  float distancia = Distancia(p1, p2);
  float esperado = 2;
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Distancia(p1, p2) *\n"
    << "-------------------------------------------------------------------\n"
    << " p1 " << MostrarPonto(p1) << "\n\n"
    << " p2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, PONTO_funcao_distancia_pontos_em_qualquer_lugar) {
  Ponto p1 = {0, 1};
  Ponto p2 = {1, 0};
  float distancia = Distancia(p1, p2);
  float esperado = sqrt(2);
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Distancia(p1, p2) *\n"
    << "-------------------------------------------------------------------\n"
    << " p1 " << MostrarPonto(p1) << "\n\n"
    << " p2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
  p1 = {0, 0};
  p2 = {1, 1};
  distancia = Distancia(p1, p2);
  esperado = sqrt(2);
  ASSERT_FLOAT_EQ(esperado, distancia)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Distancia(p1, p2) *\n"
    << "-------------------------------------------------------------------\n"
    << " p1 " << MostrarPonto(p1) << "\n\n"
    << " p2 " << MostrarPonto(p2) << "\n\n"
    << "   Distancia esperada : " << esperado << "\n"
    << "  Distancia retornada : " << distancia << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_perimetro_coordenadas_positivas) {
  Triangulo t = {{0, 0}, {0, 3}, {4, 0}};
  float perimetro = Perimetro(t);
  float esperado = 12;
  ASSERT_FLOAT_EQ(esperado, perimetro)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Perimetro(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "Lado 1: " << Distancia(t.p1, t.p2) << "\n"
    << "Lado 2: " << Distancia(t.p2, t.p3) << "\n"
    << "Lado 3: " << Distancia(t.p3, t.p1) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_perimetro_coordenadas_negativas) {
  Triangulo t = {{0, 1}, {-2, -1}, {2, -1}};
  float perimetro = Perimetro(t);
  float esperado = 4 + sqrt(8) + sqrt(8);
  ASSERT_FLOAT_EQ(esperado, perimetro)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Perimetro(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "Lado 1: " << Distancia(t.p1, t.p2) << "\n"
    << "Lado 2: " << Distancia(t.p2, t.p3) << "\n"
    << "Lado 3: " << Distancia(t.p3, t.p1) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_area_triangulo_agudo) {
  Triangulo t = {{0, 0}, {1, 1}, {2, 0}};
  float esperado = 1;
  float area = Area(t);
  ASSERT_FLOAT_EQ(esperado, area)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Area(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_area_triangulo_retangulo) {
  Triangulo t = {{0, 0}, {0, 3}, {4, 0}};
  float area = Area(t);
  float esperado = 6;
  ASSERT_FLOAT_EQ(esperado, area)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Area(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_area_triangulo_obtuso) {
  Triangulo t = {{0, 0}, {-1, 2}, {2, 0}};
  float esperado = 2;
  float area = Area(t);
  ASSERT_FLOAT_EQ(esperado, area)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Area(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado:  " << esperado << "\n"
    << "   Valor retornado: " << area << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_equilatero_triangulo_equilatero) {
  Triangulo t = {{1, 0}, {-1, 0}, {0, sqrt(3)}};
  ASSERT_TRUE(Equilatero(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Equilatero(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << " - Equilatero.\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_equilatero_triangulo_nao_equilatero) {
  Triangulo t = {{0, 0}, {0, 3}, {4, 0}};
  ASSERT_FALSE(Equilatero(t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Equilatero(Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "t = " << MostrarTriangulo(t) << " - Nao Equilatero.\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_semelhante_triangulos_nao_semelhantes) {
  Triangulo t1 = {{0, 0}, {0, 3}, {4, 0}};
  Triangulo t2 = {{0, 0}, {0, 1}, {2, 0}};
  ASSERT_FALSE(Semelhante(t1, t2))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Semelhante(Trinagulo t1, Trinagulo t2) *\n"
    << "-------------------------------------------------------------------\n"
    << "t1 = " << MostrarTriangulo(t1) << "\n"
    << "t2 = " << MostrarTriangulo(t2) << "\n\n"
    << "  Valor esperado: false\n"
    << "  Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_semelhante_triangulos_semelhantes) {
  Triangulo t1 = {{0, 0}, {0, 4}, {4, 0}};
  Triangulo t2 = {{0, 0}, {0, 2}, {2, 0}};
  ASSERT_TRUE(Semelhante(t1, t2))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Semelhante(Trinagulo t1, Trinagulo t2) *\n"
    << "-------------------------------------------------------------------\n"
    << "t1 = " << MostrarTriangulo(t1) << "\n"
    << "t2 = " << MostrarTriangulo(t2) << "\n\n"
    << "  Valor esperado: true\n"
    << "  Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, TRIANGULO_funcao_semelhante_triangulos_semelhantes_virados) {
  Triangulo t1 = {{0, 0}, {2,  2}, {4, 0}};
  Triangulo t2 = {{0, 1}, {2, -1}, {4, 1}};
  ASSERT_TRUE(Semelhante(t1, t2))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Semelhante(Trinagulo t1, Trinagulo t2) *\n"
    << "-------------------------------------------------------------------\n"
    << "t1 = " << MostrarTriangulo(t1) << "\n"
    << "t2 = " << MostrarTriangulo(t2) << "\n\n"
    << "  Valor esperado: true\n"
    << "  Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_perimetro) {
  Retangulo r = {{0, 0}, {2, -2}};
  float perimetro_r = Perimetro(r);
  float esperado = 8;
  ASSERT_FLOAT_EQ(esperado, perimetro_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Perimetro(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
  r = {{3, 3}, {6, 1}};
  perimetro_r = Perimetro(r);
  esperado = 10;
  ASSERT_FLOAT_EQ(esperado, perimetro_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Perimetro(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
  r = {{2, 2}, {3, 1}};
  perimetro_r = Perimetro(r);
  esperado = 4;
  ASSERT_FLOAT_EQ(esperado, perimetro_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Perimetro(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_r << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_area) {
  Retangulo r = {{0, 0}, {2, -2}};
  float areas = Area(r);
  float esperado = 4;
  ASSERT_FLOAT_EQ(esperado, areas)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Area(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
  r = {{3, 3}, {6, 1}};
  areas = Area(r);
  esperado = 6;
  ASSERT_FLOAT_EQ(esperado, areas)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Area(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
  r = {{2, 2}, {3, 1}};
  areas = Area(r);
  esperado = 1;
  ASSERT_FLOAT_EQ(esperado, areas)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float Area(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << areas << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_quadrado_retangulo_quadrado) {
  Retangulo r = {{0, 0}, {2, -2}};
  ASSERT_TRUE(Quadrado(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Quadrado(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_quadrado_retangulo_nao_quadrado) {
  Retangulo r = {{2, 2}, {3, 0}};
  ASSERT_FALSE(Quadrado(r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Quadrado(Retangulo r) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_ponto_dentro) {
  Retangulo r = {{0, 0}, {2, -2}};
  Ponto p = {1, -1};
  ASSERT_TRUE(Contem(r, p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Ponto p) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "p = " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_ponto_no_limite) {
  Retangulo r = {{2, 2}, {3, 0}};
  Ponto p = {2, 2};
  ASSERT_TRUE(Contem(r, p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Ponto p) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "p = " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_ponto_fora) {
  Retangulo r = {{2, 2}, {3, 0}};
  Ponto p = {1, 0};
  ASSERT_FALSE(Contem(r, p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Ponto p) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "p = " << MostrarPonto(p) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_dentro) {
  Retangulo r = {{0, 0}, {2, -2}};
  Triangulo t = {{0.1, -0.1}, {1.5, -1.5}, {1.0, -1.5}};
  ASSERT_TRUE(Contem(r, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_com_dois_pontos_dentro) {
  Retangulo r = {{0, 0}, {2, -2}};
  Triangulo t = {{1.0, 1.0}, {1.5, -1.5}, {-1.0, -1.5}};
  ASSERT_FALSE(Contem(r, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_com_um_ponto_dentro) {
  Retangulo r = {{0, 0}, {2, -2}};
  Triangulo t = {{1.0, 1.0}, {1.5, -1.5}, {-3.0, -1.5}};
  ASSERT_FALSE(Contem(r, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, RETANGULO_funcao_contem_triangulo_fora) {
  Retangulo r = {{0, 0}, {2, -2}};
  Triangulo t = {{1.0, 1.0}, {1.5, -2.5}, {-3.0, -1.5}};
  ASSERT_FALSE(Contem(r, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool Contem(Retangulo r, Triangulo t) *\n"
    << "-------------------------------------------------------------------\n"
    << "r = " << MostrarRetangulo(r) << "\n"
    << "t = " << MostrarTriangulo(t) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_perimetro_raio_inteiro) {
  Circunferencia c = {5, {0, 0}};
  float esperado = 2 * M_PI * c.raio;
  float perimetro_c = Perimetro(c);
  ASSERT_FLOAT_EQ(esperado, perimetro_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << M_PI << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_perimetro_raio_nao_inteiro) {
  Circunferencia c = {1.5, {0, 0}};
  float esperado = 2*M_PI*c.raio;
  float perimetro_c = Perimetro(c);
  ASSERT_FLOAT_EQ(esperado, perimetro_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << M_PI << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_perimetro_raio_muito_pequeno) {
  Circunferencia c = {0.01, {0, 0}};
  float esperado = 2*M_PI*c.raio;
  float perimetro_c = Perimetro(c);
  ASSERT_FLOAT_EQ(esperado, perimetro_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::perimetro() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << M_PI << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << perimetro_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_area_raio_inteiro) {
  Circunferencia c = {5, {0, 0}};
  float esperado = M_PI*c.raio*c.raio;
  float area_c = Area(c);
  ASSERT_FLOAT_EQ(esperado, area_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << M_PI << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_area_raio_nao_inteiro) {
  Circunferencia c = {1.5, {0, 0}};
  float esperado = M_PI*c.raio*c.raio;
  float area_c = Area(c);
  ASSERT_FLOAT_EQ(esperado, area_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << M_PI << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_area_raio_muito_pequeno) {
  Circunferencia c = {0.01, {0, 0}};
  float esperado = M_PI*c.raio*c.raio;
  float area_c = Area(c);
  ASSERT_FLOAT_EQ(esperado, area_c)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* float CIRCUNFERENCIA::area() *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Valor de PI: " << M_PI << "\n\n"
    << "   Valor esperado : " << esperado << "\n"
    << "   Valor retornado: " << area_c << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_contem_ponto_dentro) {
  Circunferencia c = {5, {0, 0}};
  Ponto p = {1, 1};
  ASSERT_TRUE(Contem(c, p))
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
  Circunferencia c = {5, {0, 0}};
  Ponto p = {5, 0};
  ASSERT_TRUE(Contem(c, p))
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
  Circunferencia c = {1.5, {0, 0}};
  Ponto p = {1, 2};
  ASSERT_FALSE(Contem(c, p))
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
  Triangulo t = {{0, 3}, {-2, 0}, {3, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_TRUE(Contem(c, t))
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
  Triangulo t = {{0, 3}, {-6, 0}, {7, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, t))
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
  Triangulo t = {{0, 3}, {-3, 0}, {7, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, t))
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
  Triangulo t = {{0, 8}, {-6, 0}, {7, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, t))
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
  Retangulo r = {{1, 1}, {2, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_TRUE(Contem(c, r))
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
  Retangulo r = {{0, 0}, {6, -6}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, r))
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
  Retangulo r = {{0, 0}, {6, -4}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, r))
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
  Retangulo r = {{0, 0}, {5, -5}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, r))
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
  Retangulo r = {{-8, 8}, {8, -8}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Contem(c, r))
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
  Ponto p = {0, 5};
  Circunferencia c = {5, {0, 0}};
  ASSERT_TRUE(Pertence(c, p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << Distancia(p, c.centro) << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_pertence_ponto_dentro) {
  Ponto p = {0, 2};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Pertence(c, p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << Distancia(p, c.centro) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_pertence_ponto_fora) {
  Ponto p = {0, 8};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Pertence(c, p))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::pertence(ponto) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia:\n" << MostrarCircunferencia(c) << "\n"
    << "Ponto: " << MostrarPonto(p) << "\n\n"
    << "Distancia entre o centro e o ponto: "
    << Distancia(p, c.centro) << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_dentro) {
  Triangulo t = {{0, 0}, {1, 1}, {2, 1}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Circunscrita(c, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, t.p1) << "\n"
    << "Vertice 2: " << Distancia(c.centro, t.p2) << "\n"
    << "Vertice 3: " << Distancia(c.centro, t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_um_ponto_nela) {
  Triangulo t = {{5, 0}, {1, 1}, {2, 1}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Circunscrita(c, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, t.p1) << "\n"
    << "Vertice 2: " << Distancia(c.centro, t.p2) << "\n"
    << "Vertice 3: " << Distancia(c.centro, t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_dois_pontos_nela) {
  Triangulo t = {{5, 0}, {0, 5}, {-2, 1}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Circunscrita(c, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, t.p1) << "\n"
    << "Vertice 2: " << Distancia(c.centro, t.p2) << "\n"
    << "Vertice 3: " << Distancia(c.centro, t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_triangulo_inscrito) {
  Triangulo t = {{5, 0}, {0, 5}, {-5, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_TRUE(Circunscrita(c, t))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(triangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Triangulo: " << MostrarTriangulo(t) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, t.p1) << "\n"
    << "Vertice 2: " << Distancia(c.centro, t.p2) << "\n"
    << "Vertice 3: " << Distancia(c.centro, t.p3) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_dentro) {
  Retangulo r = {{0, 0}, {1, -1}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Circunscrita(c, r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, r.se) << "\n"
    << "Vertice 2: " << Distancia(c.centro, r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_um_ponto_nela) {
  Retangulo r = {{0, 10}, {10, 5}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Circunscrita(c, r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, r.se) << "\n"
    << "Vertice 2: " << Distancia(c.centro, r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_dois_pontos_nela) {
  Retangulo r = {{0, 10}, {5, 0}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_FALSE(Circunscrita(c, r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, r.se) << "\n"
    << "Vertice 2: " << Distancia(c.centro, r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : false\n"
    << "   Valor retornado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, CIRCUNFERENCIA_funcao_circunscrita_retangulo_inscrito) {
  Retangulo r = {{-2.5, 5 * sqrt(3) / 2},
                 {2.5, -5 * sqrt(3) / 2}};
  Circunferencia c = {5, {0, 0}};
  ASSERT_TRUE(Circunscrita(c, r))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool CIRCUNFERENCIA::circunscrita(retangulo) *\n"
    << "-------------------------------------------------------------------\n"
    << "Circunferencia: " << MostrarCircunferencia(c)
    << "Retangulo: " << MostrarRetangulo(r) << "\n\n"
    << "Distancias entre o centro da circunferencia e o:\n"
    << "Vertice 1: " << Distancia(c.centro, r.se) << "\n"
    << "Vertice 2: " << Distancia(c.centro, r.id) << "\n"
    << "Para que a circunferencia seja circunscrita, as distancias acima\n"
    << "deveriam ser igual a " << c.raio << "\n\n"
    << "   Valor esperado : true\n"
    << "   Valor retornado: false\n"
    << "-------------------------------------------------------------------\n";
}

}  // Fim do namespace

#endif  // REGISTROS_TEST_REGISTROS_TEST_H_
