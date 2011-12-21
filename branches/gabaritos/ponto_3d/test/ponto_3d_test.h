// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_PONTO_3D_TEST_PONTO_3D_TEST_H_
#define BRANCHES_GABARITOS_PONTO_3D_TEST_PONTO_3D_TEST_H_

#include <sstream>
#include <string>

#include "ponto_3d/src/ponto_3d.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos casos de teste.
class Teste : public testing::Test {
 protected:
  // Imprime as coordenadas de um ponto.
  string Imprime_Ponto(Ponto3D *p) {
    stringstream output;
    output << "(" << p->v_[0] << ", ";
    output << p->v_[1] << ", ";
    output << p->v_[2] << ")";
    return output.str();
  }
  void Inicializar(Ponto3D *p, double x, double y, double z)  {
    p->v_[0] = x;
    p->v_[1] = y;
    p->v_[2] = z;
  }
  bool Iguais(Ponto3D *p1, Ponto3D *p2) {
    if (p1->v_[0] - p2->v_[0] > 0.00001 || p1->v_[0] - p2->v_[0] < -0.00001)
      return false;
    if (p1->v_[1] - p2->v_[1] > 0.00001 || p1->v_[1] - p2->v_[1] < -0.00001)
      return false;
    if (p1->v_[2] - p2->v_[2] > 0.00001 || p1->v_[2] - p2->v_[2] < -0.00001)
      return false;
    return true;
  }
};

TEST_F(Teste, Mudar_escala_no_eixo_X) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 9.0, 2.0, 1.0);
  resultado.MudarEscala(3.0, 1.0, 1.0);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void MudarEscala(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Mudar escala para: x = 3.0 | y = 1.0 | z = 1.0\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Mudar_escala_no_eixo_Y) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 3.0, 5.0, 1.0);
  resultado.MudarEscala(1.0, 2.5, 1.0);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void MudarEscala(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Mudar escala para: x = 1.0 | y = 2.5 | z = 1.0\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Mudar_escala_no_eixo_Z) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 3.0, 2.0, 9.0);
  resultado.MudarEscala(1.0, 1.0, 9.0);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void MudarEscala(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Mudar escala para: x = 1.0 | y = 1.0 | z = 9.0\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Transladar_no_eixo_X) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 9.0, 2.0, 1.0);
  resultado.Transladar(6.0, 0.0, 0.0);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Transladar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Transladar coordenadas para: x = 6.0 | y = 0.0 | z = 0.0\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Transladar_no_eixo_Y) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 3.0, 7.5, 1.0);
  resultado.Transladar(0.0, 5.5, 0.0);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Transladar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Transladar coordenadas para: x = 0.0 | y = 5.5 | z = 0.0\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Transladar_no_eixo_Z) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 3.0, 2.0, -1.0);
  resultado.Transladar(0.0, 0.0, -2.0);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Transladar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Transladar coordenadas para: x = 0.0 | y = 0.0 | z = -2.0\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Rotacionar_no_eixo_X) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 3, -0.679529, 2.13031);
  resultado.Rotacionar('X', -30);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Rotacionar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Rotacionar no eixo X em -30 graus\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Rotacionar_no_eixo_Y) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, 0.725062, 2, 3.07803);
  resultado.Rotacionar('Y', 45);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Rotacionar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Rotacionar no eixo Y em 45 graus\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Rotacionar_no_eixo_Z) {
  Ponto3D resultado, entrada;
  Inicializar(&resultado, 3.0, 2.0, 1.0);
  Inicializar(&entrada, 3.0, 2.0, 1.0);
  Ponto3D esperado;
  Inicializar(&esperado, -0.193075, -3.60038, 1);
  resultado.Rotacionar('Z', 180);
  ASSERT_TRUE(Iguais(&resultado, &esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Rotacionar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto de Entrada: " << Imprime_Ponto(&entrada) << "\n"
    << "Rotacionar no eixo Z em 180 graus\n"
    << "Ponto esperado: " << Imprime_Ponto(&esperado) << "\n"
    << "Ponto retornado: " << Imprime_Ponto(&resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_PONTO_3D_TEST_PONTO_3D_TEST_H_
