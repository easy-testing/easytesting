// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef VETORES_TEST_VETORES_TEST_H_
#define VETORES_TEST_VETORES_TEST_H_

#include <sstream>
#include <string>
#include <cmath>
#include "vetores2/src/vetores.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

namespace Teste {

// Classe base dos casos de teste.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string MostrarVetor(int v[], int n) {
    stringstream output;
    output << "{";
    for (int i = 0; i < n ; i++) {
      output << v[i];
      if (i < n - 1) {
        output << ", ";
      }
    }
    output << "}";
    return output.str();
  }
};

TEST_F(Teste, Teste_modulo_componentes_positivas) {
  int n = 3;
  int v[3 + 1] = { 1 , 2, 3, 4};
  float atual = Modulo(v, n);
  float inesperado = sqrt(1+4+9+16);
  ASSERT_NE(atual, inesperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao \"float Modulo(int v[],int n)\".                  \n"
    << "-------------------------------------------------------------------\n"
    << "  Sua função pode estar acessando a posição inválida v[n].         \n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Teste_Modulo_acesso_correto) {
  int n = 3;
  int v[3] = { 1 , 2, 3};
  float atual = Modulo(v, n);
  float esperado = sqrt(1+4+9);
  ASSERT_EQ(atual, esperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao \"float Modulo(int v[],int n)\".                  \n"
    << "-------------------------------------------------------------------\n"
    << "   v = " << MostrarVetor(v, n) << "\n"
    << "   n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Modulo_uma_componente_negativa) {
  int n = 1;
  int v[] = {-5};
  float esperado = 5;
  float atual = Modulo(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
     << "Erro na funcao \"float Modulo(int v[],int n)\".                  \n"
    << "-------------------------------------------------------------------\n"
    << "   v = " << MostrarVetor(v, n) << "\n"
    << "   n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Modulo_com_componentes_nulas) {
  int n = 5;
  int v[] = {0, 0, 0, 0, 0};
  float esperado = 0;
  float atual = Modulo(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_ProdutoEscalar_perpendicular) {
  int n = 2;
  int v[] = {0, 2};
  int u[] = {2, 0};
  float esperado = 0;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(int v[], int u[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  v = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_ProdutoEscalar_aleatorio) {
  int n = 3;
  int v[] = {3, 7, 2};
  int u[] = {1, 1, 9};
  float esperado = 28;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(int v[], int u[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  v = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Cosseno_perpendicular) {
  int n = 2;
  int v[] = {0, 2};
  int u[] = {2, 0};
  float esperado = 0;
  float atual = CossenoVetores(v, u, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Cosseno_Vetores(int v[], int u[], int n);\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  v = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Cosseno_antiparalelo) {
  int n = 2;
  int v[] = {0, 2};
  int u[] = {0, -2};
  float esperado = -1;
  float atual = CossenoVetores(v, u, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Cosseno_Vetores(int v[], int u[], int n);\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  v = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_Cosseno_45) {
  int n = 2;
  int v[] = {0, 1};
  int u[] = {1, 1};
  float esperado = sqrt(2)/2.;
  float atual = CossenoVetores(v, u, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Cosseno_Vetores(int v[], int u[], int n);\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  v = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

}  // Fim do namespace vazio.

#endif  // VETORES_TEST_VETORES_TEST_H_
