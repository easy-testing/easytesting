// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_PONTO_3D_TEST_PONTO_3D_TEST_H_
#define TRUNK_PONTO_3D_TEST_PONTO_3D_TEST_H_


#include <cmath>
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
  string ToString(const Ponto3D& p) {
    stringstream output;
    output << "(" << p.v_[0] << ", ";
    output << p.v_[1] << ", ";
    output << p.v_[2] << ")";
    return output.str();
  }

  void SetX(double val, Ponto3D* p) {
    p->v_[0] = val;
  }

  void SetY(double val, Ponto3D* p) {
    p->v_[1] = val;
  }

  void SetZ(double val, Ponto3D* p) {
    p->v_[2] = val;
  }

  bool iguais(const Ponto3D& p1, const Ponto3D& p2) {
    if (p1.v_[0] - p2.v_[0] > 0.00001 || p1.v_[0] - p2.v_[0] < -0.00001)
      return false;
    if (p1.v_[1] - p2.v_[1] > 0.00001 || p1.v_[1] - p2.v_[1] < -0.00001)
      return false;
    if (p1.v_[2] - p2.v_[2] > 0.00001 || p1.v_[2] - p2.v_[2] < -0.00001)
      return false;
    return true;
  }
};

TEST_F(Teste, Testa_funcao_que_retorna_x) {
  Ponto3D corrente;
  SetX(2, &corrente);
  double esperado = 2;
  double atual = corrente.x();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Ponto3D::x()\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "Valor esperado = " << esperado << "\n"
    << "Valor retornado = " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_que_retorna_y) {
  Ponto3D corrente;
  SetY(3, &corrente);
  double esperado = 3;
  double atual = corrente.y();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Ponto3D::y()\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "Valor esperado = " << esperado << "\n"
    << "Valor retornado = " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_que_retorna_z) {
  Ponto3D corrente;
  SetZ(5, &corrente);
  double esperado = 5;
  double atual = corrente.z();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Ponto3D::z()\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "Valor esperado = " << esperado << "\n"
    << "Valor retornado = " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_costrutor_vazio) {
  Ponto3D corrente;
  ASSERT_TRUE(corrente.x() == 0 && corrente.y() == 0 && corrente.z() == 0)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Ponto3D::Ponto3D()\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto esperado = " << "(0, 0, 0)" << "\n"
    << "Ponto retornado = " << ToString(corrente) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_costrutor_com_tres_parametros) {
  Ponto3D corrente(2, 3, 5);
  ASSERT_TRUE(corrente.x() == 2 && corrente.y() == 3 && corrente.z() == 5)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Ponto3D::Ponto3D(double x, double y, double z)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto esperado = " << "(2, 3, 4)" << "\n"
    << "Ponto retornado = " << ToString(corrente) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Transladar) {
  Ponto3D corrente(3.0, 2.0, 1.0);
  Ponto3D esperado(5.0, 5.0, 6.0);
  Ponto3D resultado;
  resultado = corrente;
  resultado.Transladar(2.0, 3.0, 5.0);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::Transladar(double dx, double dy,\n"
    << "                                                      double dz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "dx = 2.0\n"
    << "dy = 3.0\n"
    << "dz = 5.0\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_MudarEscala) {
  Ponto3D corrente(3.0, 2.0, 1.0);
  Ponto3D esperado(6.0, 6.0, 5.0);
  Ponto3D resultado;
  resultado = corrente;
  resultado.MudarEscala(2.0, 3.0, 5.0);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::MudarEscala(double fx, double fy,\n"
    << "                                                      double fz)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "fx = 2.0\n"
    << "fy = 3.0\n"
    << "fz = 5.0\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_RoatacionarX_no_sentido_horario) {
  double rad = M_PI / 4.0;
  Ponto3D corrente(13.0, 1.0, 1.0);
  Ponto3D esperado(13.0, 0.0, sqrt(2.0));
  Ponto3D resultado;
  resultado = corrente;
  resultado.RotacionarX(rad);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::RotacionarX(double rad)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "rad = " << rad << "\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_RoatacionarX_no_sentido_antihorario) {
  double rad = - M_PI / 4.0;
  Ponto3D corrente(13.0, 1.0, 1.0);
  Ponto3D esperado(13.0, sqrt(2.0), 0.0);
  Ponto3D resultado;
  resultado = corrente;
  resultado.RotacionarX(rad);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::RotacionarX(double rad)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "rad = " << rad << "\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_RoatacionarY_no_sentido_horario) {
  double rad = M_PI / 4.0;
  Ponto3D corrente(1.0, 13.0, 1.0);
  Ponto3D esperado(sqrt(2.0), 13.0, 0.0);
  Ponto3D resultado;
  resultado = corrente;
  resultado.RotacionarY(rad);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::RotacionarY(double rad)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "rad = " << rad << "\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_RoatacionarY_no_sentido_antihorario) {
  double rad = - M_PI / 4.0;
  Ponto3D corrente(1.0, 13.0, 1.0);
  Ponto3D esperado(0.0, 13.0, sqrt(2.0));
  Ponto3D resultado;
  resultado = corrente;
  resultado.RotacionarY(rad);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::RotacionarY(double rad)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "rad = " << rad << "\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_RoatacionarZ_no_sentido_horario) {
  double rad = M_PI / 4.0;
  Ponto3D corrente(1.0, 1.0, 13.0);
  Ponto3D esperado(0.0, sqrt(2.0), 13.0);
  Ponto3D resultado;
  resultado = corrente;
  resultado.RotacionarZ(rad);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::RotacionarX(double rad)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "rad = " << rad << "\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_RoatacionarZ_no_sentido_antihorario) {
  double rad = - M_PI / 4.0;
  Ponto3D corrente(1.0, 1.0, 13.0);
  Ponto3D esperado(sqrt(2.0), 0.0, 13.0);
  Ponto3D resultado;
  resultado = corrente;
  resultado.RotacionarZ(rad);
  ASSERT_TRUE(iguais(resultado, esperado))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void Ponto3D::RotacionarX(double rad)\".\n"
    << "-------------------------------------------------------------------\n"
    << "Ponto corrente = " << ToString(corrente) << "\n"
    << "rad = " << rad << "\n"
    << "Ponto esperado = " << ToString(esperado) << "\n"
    << "Ponto retornado = " << ToString(resultado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_PONTO_3D_TEST_PONTO_3D_TEST_H_
