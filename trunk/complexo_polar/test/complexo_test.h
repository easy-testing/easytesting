// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef COMPLEXO_TEST_COMPLEXO_TEST_H_
#define COMPLEXO_TEST_COMPLEXO_TEST_H_

#include "complexo/src/complexo.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

namespace Teste {

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna string no formato [x + yi]
  string MostrarComplexo(Complexo& z) {
    stringstream output;
    output << "[";
    if (z.imag() == 0) {
      output << z.real();
    } else if (z.real() == 0) {
      output << z.imag() << "i";
    } else {
      output << z.real();
      if (z.imag() > 0) output << " + " << z.imag();
      else
        output << " -" << -z.imag();
      output << "i";
    }
    output << "]";
    return output.str();
  }
};

// NOTA(Matheus): Chamei de Numero complexo nulo aquele que possui
// parte real e parte imaginaria nulas. Numero complexo positivo
// aquele que possui parte real e parte imaginaria positivas e
// negativo o que possui as duas partes negativas
TEST_F(Teste, Testar_Parte_Real) {
  Complexo x(1.1, 2.2);
  float esperado = 1.1;
  float atual = x.real();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"float real()\"                                  \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte real esperada : " << esperado << "\n"
    << "  Parte real retornada : " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Parte_Imaginaria) {
  Complexo x(0.1, 3.2);
  float esperado = 3.2;
  float atual = x.imag();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"float imag()\"                                  \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte imaginaria esperada: " << esperado << "\n"
    << "  Parte imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construcao_sem_parametro_Parte_Real) {
  Complexo x;
  float esperado = 0;
  float atual = x.real();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor:  \"complexo()\"                                \n"
    << "        Parte real                                                 \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte real esperada: " << esperado << "\n"
    << "  Parte real retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construcao_sem_parametro_Parte_Imaginaria) {
  Complexo x;
  float esperado = 0;
  float atual = x.imag();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor:  \"complexo()\"                                \n"
    << "        Parte imaginaria                                           \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte imaginaria esperada: " << esperado << "\n"
    << "  Parte imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construcao_com_um_parametro_Parte_Real) {
  Complexo x(2.25);
  float esperado = 2.25;
  float atual = x.real();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor:  \"complexo()\"                                \n"
    << "        Parte real                                                 \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte real esperada: " << esperado << "\n"
    << "  Parte real retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construcao_com_um_parametro_Parte_Imaginaria) {
  Complexo x(2.30);
  float esperado = 0;
  float atual = x.imag();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor:  \"complexo()\"                                \n"
    << "        Parte imaginaria                                           \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte imaginaria esperada: " << esperado << "\n"
    << "  Parte imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construcao_com_dois_parametros_Parte_Real) {
  Complexo x(2.54, 3.48);
  float esperado = 2.54;
  float atual = x.real();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor:  \"complexo()\"                                \n"
    << "        Parte real                                                 \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte real esperada: " << esperado << "\n"
    << "  Parte real retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construcao_com_dois_parametros_Parte_Imaginaria) {
  Complexo x(2.54, 3.48);
  float esperado = 3.48;
  float atual = x.imag();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor:  \"complexo()\"                                \n"
    << "        Parte imaginaria                                           \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte imaginaria esperada: " << esperado << "\n"
    << "  Parte imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Calculo_Modulo_Numero_Complexo_Nulo) {
  Complexo x;
  float esperado = 0;
  float atual = x.modulo();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"float modulo()\"                                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Modulo esperado: " << esperado << "\n"
    << "  Modulo retornado: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Calculo_Modulo_Numero_Complexo_Negativo) {
  Complexo x(-8, -6);
  float esperado = 10;
  float atual = x.modulo();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"float modulo()\"                                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Modulo esperado: " << esperado << "\n"
    << "  Modulo retornado: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Calculo_Modulo_Numero_Complexo_Positivo) {
  Complexo x(6, 8);
  float esperado = 10;
  float atual = x.modulo();
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"float modulo()\"                                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Modulo esperado: " << esperado << "\n"
    << "  Modulo retornado: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Igualdade_entre_Numeros_Complexos_Totalmente_Distintos) {
  Complexo x(6.1, 8.5);
  Complexo y(4.2, 3.03);
  ASSERT_FALSE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"bool igual()\"                                  \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(x) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(y) << "\n\n"
    << "   Resultado esperado: false\n"
    << "  Resultado retornado: true\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Igualdade_entre_Numeros_Complexos_com_mesma_Parte_Imaginaria) {
  Complexo x(6.1, 8.5);
  Complexo y(4.2, 8.5);
  ASSERT_FALSE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"bool igual()\"                                  \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(x) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(y) << "\n\n"
    << "   Resultado esperado: false\n"
    << "  Resultado retornado: true\n\n"
    << " *DICA*\n"
    << "         Verifique se seu programa esta comparando\n"
    << "         apenas a parte real do numero complexo\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Igualdade_entre_Numeros_Complexos_com_mesma_Parte_Real) {
  Complexo x(6.1, 4.5);
  Complexo y(6.1, 8.5);
  ASSERT_FALSE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"bool igual()\"                                  \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(x) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(y) << "\n\n"
    << "   Resultado esperado: false\n"
    << "  Resultado retornado: true\n\n"
    << " *DICA*\n"
    << "         Verifique se seu programa esta comparando\n"
    << "         apenas a parte imaginaria do numero complexo\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Igualdade_entre_Numeros_Complexos_Iguais) {
  Complexo x(6.1, 8.5);
  Complexo y(6.1, 8.5);
  ASSERT_TRUE(x == y)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"bool igual()\"                                  \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(x) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(y) << "\n\n"
    << "   Resultado esperado: true\n"
    << "  Resultado retornado: false\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Igualar_Numero_Complexo_Parte_Real) {
  Complexo x(2, 3.4);
  Complexo y;
  y = x;
  float atual = y.real();
  float esperado = 2;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void igualar()\"                                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << " Numero Complexo a ser igualado:\n"
    << "   Parte Real esperada: " << esperado << "\n"
    << "  Parte Real retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Igualar_Numero_Complexo_Parte_Imaginaria) {
  Complexo x(2, 3.4);
  Complexo y;
  y = x;
  float atual = y.imag();
  float esperado = 3.4;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void igualar()\"                                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << " Numero Complexo a ser igualado:\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Atribuir_Conjugado_de_Numero_Complexo_Nulo) {
  Complexo x;
  Complexo y(2, 3.5);
  y = x.conjugado();
  float atual = y.imag();
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void conjugar()\"                               \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Atribuir_Conjugado_de_Numero_Complexo_Positivo) {
  Complexo x(1, 10.3);
  Complexo y(2, 3.5);
  y = x.conjugado();
  float atual = y.imag();
  float esperado = -10.3;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void conjugar()\"                               \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Atribuir_Conjugado_de_Numero_Complexo_Negativo) {
  Complexo x(-2, -3.4);
  Complexo y(2, 3.5);
  y = x.conjugado();
  float atual = y.imag();
  float esperado = 3.4;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void conjugar()\"                               \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Inverter_Numero_Complexo_Parte_Real) {
  Complexo x(6, 8);
  Complexo y;
    y = x.inverso();
  float atual = y.real();
  float esperado = 0.06;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void inverter()\"                               \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte Real esperada: " << esperado << "\n"
    << "  Parte Real retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Inverter_Numero_Complexo_Parte_Imaginaria) {
  Complexo x(6, 8);
  Complexo y;
    y = x.inverso();
  float atual = y.imag();
  float esperado = -0.08;
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void inverter()\"                               \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo: " << MostrarComplexo(x) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_Numeros_Complexos_Nulos) {
  Complexo x(2, 3);
  Complexo y;
  Complexo z;
  x = y + z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_Numeros_Complexos_Positivos) {
  Complexo x;
  Complexo y(4.1, 2.4);
  Complexo z(3.6, 1.5);
  x = y + z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = 7.7;
  float esperado_i = 3.9;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_Numeros_Complexos_Negativos) {
  Complexo x;
  Complexo y(-4.1, -2.4);
  Complexo z(-3.6, -1.5);
  x = y + z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = -7.7;
  float esperado_i = -3.9;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Somar_Numeros_Complexos_de_sinais_opostos) {
  Complexo x;
  Complexo y(-4.1, 2.4);
  Complexo z(3.6, -1.5);
  x = y + z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = -0.5;
  float esperado_i = 0.9;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_Nulos) {
  Complexo x(2, 3);
  Complexo y;
  Complexo z;
  x = y - z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void subtrair(Complexo, Complexo)\"             \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void subtrair(Complexo, Complexo)\"             \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_Positivos) {
  Complexo x;
  Complexo y(4.1, 2.4);
  Complexo z(3.6, 1.5);
  x = y - z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = 0.5;
  float esperado_i = 0.9;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_Negativos) {
  Complexo x;
  Complexo y(-4.1, -2.4);
  Complexo z(-3.6, -1.5);
  x = y - z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = -0.5;
  float esperado_i = -0.9;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Subtrair_Numeros_Complexos_de_sinais_opostos) {
  Complexo x;
  Complexo y(4.1, -2.4);
  Complexo z(-3.6, 1.5);
  x = y - z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = 7.7;
  float esperado_i = -3.9;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void somar(Complexo, Complexo)\"                \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicar_Numeros_Complexos_Nulos) {
  Complexo x(4.1, -2.4);
  Complexo y;
  Complexo z;
  x = y * z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado = 0;
  ASSERT_FLOAT_EQ(esperado, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void multiplicar(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void multiplicar(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicar_Numeros_Complexos_mesmo_sinal) {
  Complexo x;
  Complexo y(4.1, 2.4);
  Complexo z(3.6, 1.5);
  x = y * z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = 11.16;
  float esperado_i = 2.49;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void multiplicar(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void multiplicar(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicar_Numeros_Complexos_sinais_contrarios) {
  Complexo x;
  Complexo y(3.1, -2.4);
  Complexo z(-3.6, 1.8);
  x = y * z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = -6.84;
  float esperado_i = 3.06;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void multiplicar(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void multiplicar(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Dividir_Numeros_Complexos_mesmo_sinal) {
  Complexo x;
  Complexo y(8, 1);
  Complexo z(4, 2);
  x = y / z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = 1.7;
  float esperado_i = 1;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void dividir(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void dividir(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Dividir_Numeros_Complexos_sinais_contrarios) {
  Complexo x;
  Complexo y(8, 5);
  Complexo z(-4, -2);
  x = y / z;
  float atual_r = x.real();
  float atual_i = x.imag();
  float esperado_r = -2.1;
  float esperado_i = -1.8;
  ASSERT_FLOAT_EQ(esperado_r, atual_r)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void dividir(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Real esperada: " << esperado_r << "\n"
    << "  Parte Real retornada: " << atual_r << "\n\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado_i, atual_i)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"void dividir(Complexo, Complexo)\"          \n"
    << "-------------------------------------------------------------------\n"
    << " Numero Complexo 1: " << MostrarComplexo(y) << "\n"
    << " Numero Complexo 2: " << MostrarComplexo(z) << "\n\n"
    << "   Parte Imaginaria esperada: " << esperado_i << "\n"
    << "  Parte Imaginaria retornada: " << atual_i << "\n\n"
    << "-------------------------------------------------------------------\n";
}

}  // end namespace

#endif  // COMPLEXO_TEST_COMPLEXO_TEST_H_
