// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef VETORES_TEST_VETORES_TEST_H_
#define VETORES_TEST_VETORES_TEST_H_

#include <sstream>
#include <string>
#include "vetores.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

namespace Teste {

// Classe base dos casos de teste.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string MostrarVetor(float v[], int n) {
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
  // Verifica se dois vetores sao iguas
  bool Iguais(float v1[], float v2[], int n){
    for(int i = 0;i < n;++i)
      if (v1[i] - v2[i] > 0.000001 || v1[i] - v2[i] < -0.000001)
        return false;
    return true;
  }
};


TEST_F(Teste, Testa_acesso_a_uma_posicao_invalida_do_vetor_na_funcao_Media) {
  int n = 3;
  float v[3 + 1] = {4.0, 8.0, 14.0, 1000.0};
  float atual = Media(v, n);
  float inesperado = (4.0 + 8.0 + 14.0 + 1000.0) / n;
  ASSERT_NE(atual, inesperado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao \"float Media(float v[], int n)\".                  \n"
    << "-------------------------------------------------------------------\n"
    << "  Sua função pode estar acessando a posição inválida v[n].         \n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Media_de_um_vetor_unitario) {
  int n = 1;
  float v[] = {5};
  float esperado = 5;
  float atual = Media(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "   v = " << MostrarVetor(v, n) << "\n"
    << "   n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Media_com_mais_de_um_valor) {
  int n = 4;
  float v[] = {4, 8, 12, 16};
  float esperado = 10;
  float atual = Media(v, n);
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

TEST_F(Teste, Testa_funcao_Media_com_numeros_nulos) {
  int n = 5;
  float v[] = {0, 0, 0, 0, 0};
  float esperado = 0;
  float atual = Media(v, n);
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

TEST_F(Teste, Testa_funcao_Media_numeros_positivos_e_negativos) {
  int n = 6;
  float v[] = {5.3, -4.1, 8.3, -1.5, 0.9, -8.9};
  float esperado = 0;
  float atual = Media(v, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_acesso_indevido_na_funcao_Variancia) {
  int n = 4;
  float v[] = {4, 8, 12, 16, 1000000};
  float esperado = 200008;
  float atual = Variancia(v, n);
  ASSERT_NE(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Variancia(float v[], int n)\".             \n"
    << "-------------------------------------------------------------------\n"
    << "  Sua funcao esta acessando um elemento do vetor nao               \n"
    << "definido. Veja se ela esta acessando no maximo o elemento n - 1 de \n"
    << "um vetor de n elementos.                                           \n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Variancia_com_numeros_nulos) {
  int n = 8;
  float v[] = {0, 0, 0, 0, 0, 0, 0, 0};
  float esperado = 0;
  float atual = Variancia(v, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Variancia(float v[], int n)\".             \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Variancia_numeros_positivos_distintos) {
  int n = 8;
  float v[] = {10, 5, 8, 12, 9, 4, 3, 7};
  float esperado = 8.4375;
  float atual = Variancia(v, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Variancia(float v[], int n)\".             \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Variancia_com_numeros_negativos_iguais) {
  int n = 8;
  float v[] = {-10, -10, -10, -10, -10, -10, -10, -10};
  float esperado = 0;
  float atual = Variancia(v, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Variancia(float v[], int n)\".             \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Variancia_com_numeros_negativos_distintos) {
  int n = 8;
  float v[] = {-10, -5, -8, -12, -9, -4, -3, -7};
  float esperado = 8.4375;
  float atual = Variancia(v, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  \"float Variancia(float v[], int n)\".            \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_acesso_indevido_na_funcao_Maior) {
  int n = 4;
  float v[] = {4, 8, 12, 16, 1000};
  float esperado = 1000;
  float atual = Maior(v, n);
  ASSERT_NE(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Maior(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  Sua funcao esta acessando um elemento do vetor nao               \n"
    << "definido. Veja se ela esta acessando no maximo o elemento n - 1 de \n"
    << "um vetor de n elementos.                                           \n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Maior_com_numeros_positivos_distintos) {
  int n = 7;
  float v[] = {21.21, 20.20, 65, 45.1, 78.02, 66.321, 9.87};
  float esperado = 78.02;
  float atual = Maior(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Maior(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Maior_com_numeros_positivos_com_repeticao) {
  int n = 7;
  float v[] = {21.21, 78.021, 65, 45.1, 78.02, 66.321, 78.0210};
  float esperado = 78.021;
  float atual = Maior(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Maior(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Maior_com_numeros_negativos_distintos) {
  int n = 7;
  float v[] = {-21.21, -20.20, -65, -45.1, -78.02, -66.321, -9.87};
  float esperado = -9.87;
  float atual = Maior(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Maior(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Maior_com_numeros_negativos_com_repeticao) {
  int n = 7;
  float v[] = {-21.21, -78.021, -65, -45.1, -78.02, -66.321, -21.210};
  float esperado = -21.21;
  float atual = Maior(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Maior(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Maior_com_numeros_positivos_e_negativos) {
  int n = 7;
  float v[] = {21.21, -78.021, -65, 45.1, -78.02, 66.321, -21.21};
  float esperado = 66.321;
  float atual = Maior(v, n);
 ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Maior(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_acesso_indevido_na_funcao_Menor) {
  float v[] = {4, 8, 12, 16, -1000};
  int n = 4;
  float esperado = -1000;
  float atual = Menor(v, n);
  ASSERT_NE(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"Menor(vetor,dimensao)\".                         \n"
    << "-------------------------------------------------------------------\n"
    << "  Sua funcao esta acessando um elemento do vetor nao               \n"
    << "definido. Veja se ela esta acessando no maximo o elemento n - 1 de \n"
    << "um vetor de n elementos.                                           \n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Menor_numeros_positivos_distintos) {
  int n = 7;
  float v[] = {21.21, 20.20, 65, 45.1, 78.02, 66.321, 9.87};
  float esperado = 9.87;
  float atual = Menor(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Menor(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Menor_com_numeros_positivos_com_repeticao) {
  int n = 7;
  float v[] = {9.871, 9.87, 65, 45.1, 78.02, 66.321, 9.87};
  float esperado = 9.87;
  float atual = Menor(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Menor(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Menor_com_numeros_negativos_distintos) {
  int n = 7;
  float v[] = {-21.21, -20.20, -65, -45.1, -78.02, -66.321, -9.87};
  float esperado = -78.02;
  float atual = Menor(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Menor(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Menor_com_numeros_negativos_com_repeticao) {
  int n = 7;
  float v[] = {-21.21, -78.02, -65, -45.1, -78.02, -66.321, -9.87};
  float esperado = -78.02;
  float atual = Menor(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Menor(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_Menor_com_numeros_positivos_e_negetivos) {
  int n = 7;
  float v[] = {-21.21, 20.20, -65, 45.1, 78.02, 66.321, -9.87};
  float esperado = -65;
  float atual = Menor(v, n);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Menor(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_numeros_positivos) {
  int n = 8;
  float v[] = {1.4, 5.2, 10, 7.1, 5.3, 2.03, 3.001, 4.1};
  float u[] = {1.1, 2.14, 3.01, 0, 0.02, 4.5, 2.65, 3.2};
  float esperado = 73.081657;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_numeros_positivos_e_negativos) {
  int n = 8;
  float v[] = {1.4, -5.2, -10, 7.1, -5.3, 2.03, 3.001, 4.1};
  float u[] = {1.1, 2.14, -3.01, 0, -0.02, -4.5, 2.65, 3.2};
  float esperado = 32.555653;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_com_vetores_unitarios) {
  int n = 1;
  float v[] = {1.4};
  float u[] = {1.1};
  float esperado = 1.54;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_com_vetores_nulos) {
  int n = 5;
  float v[] = {0, 0, 0, 0, 0};
  float u[] = {0, 0, 0, 0, 0};
  float esperado = 0;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_com_vetores_paralelos) {
  int n = 5;
  float v[] = {1, 2, 3, 4, 5};
  float u[] = {2, 4, 6, 8, 10};
  float esperado = 110;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_vetores_opostos) {
  int n = 3;
  float v[] = {3, 2, 4};
  float u[] = {-3, -2, -4};
  float esperado = -29;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_ProdutoEscalar_vetores_perpendiculares) {
  int n = 4;
  float v[] = {3.3, 0, 4.4, 0};
  float u[] = {0, 5.5, 0, 8.8};
  float esperado = 0.0;
  float atual = ProdutoEscalar(v, u, n);
  ASSERT_FLOAT_EQ(esperado, atual)
    << "--------------------------------------------------------------------\n"
    << "Erro na funcao: \"float ProdutoEscalar(float u[],float v[],int n)\".\n"
    << "--------------------------------------------------------------------\n"
    << "  v = " << MostrarVetor(v, n) << "\n"
    << "  u = " << MostrarVetor(u, n) << "\n"
    << "  n = " << n << "\n"
    << "Valor esperado: " << esperado << "\n"
    << "Valor retornado: " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

////////////////////////////////////////
//          Testes Adicionais         //
////////////////////////////////////////

TEST_F(Teste, Testa_Media_Ponderada_Peso_1) {
  int n = 4;
  float v[] = {3, 2, 5, 7};  // Valores
  float p[] = {1, 1, 1, 1};  // Peso
  float esperado = 4.25;
  float resultado = MediaPonderada(v, p, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaPonderada(float[],float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Peso    = " << MostrarVetor(p, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Ponderada_Valores_Positivos) {
  int n = 4;
  float v[] = {3, 2, 5, 7};  // Valores
  float p[] = {5, 1, 2, 3};  // Peso
  float esperado = 4.36363636;
  float resultado = MediaPonderada(v, p, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaPonderada(float[],float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Peso    = " << MostrarVetor(p, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Ponderada_Valores_Negativos) {
  int n = 4;
  float v[] = {-3, -2, -5, -7};  // Valores
  float p[] = {5, 1, 2, 3};  // Peso
  float esperado = -4.36363636;
  float resultado = MediaPonderada(v, p, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaPonderada(float[],float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Peso    = " << MostrarVetor(p, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Ponderada_Valores_Variados) {
  int n = 4;
  float v[] = {3, -2, 5, -7};  // Valores
  float p[] = {5, 1, 2, 3};  // Peso
  float esperado = 0.18181818;
  float resultado = MediaPonderada(v, p, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaPonderada(float[],float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Peso    = " << MostrarVetor(p, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Harmonica_Numeros_Positivos) {
  int n = 4;
  float v[] = {3, 2, 5, 7};  // Valores
  float esperado = 3.400809;
  float resultado = MediaHarmonica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaHarmonica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Harmonica_Numeros_Negativos) {
  int n = 4;
  float v[] = {-3, -2, -5, -7};  // Valores
  float esperado = -3.400809;
  float resultado = MediaHarmonica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaHarmonica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Harmonica_Um_Valor_Nulo) {
  int n = 4;
  float v[] = {7, 0, 3, 0};  // Valores
  float esperado = 0;
  float resultado = MediaHarmonica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaHarmonica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "  OBS: VERIFIQUE SE EXISTE UMA DIVISAO POR ZERO NO CALCULO DA MEDIA\n"
  << "  UMA  SOLUCAO EH  VERIFICAR SE UM  DOS VALORES  DO VETOR EH NULO E\n"
  << "  RETORNAR 0(zero) JAH QUE SE AO MENOS  UM VALOR DA MEDIA HARMONICA\n"
  << "  FOR NULO O RESULTADO EH ZERO.\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Geometrica_Numeros_Positivos) {
  int n = 4;
  float v[] = {3, 2, 5, 7};  // Valores
  float esperado = 3.806754;
  float resultado = MediaGeometrica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaGeometrica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Geometrica_Um_Valor_Nulo) {
  int n = 4;
  float v[] = {3, 0, 5, 7};  // Valores
  float esperado = 0;
  float resultado = MediaGeometrica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaGeometrica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Quadratica_Numeros_Positivos) {
  int n = 4;
  float v[] = {3, 2, 5, 7};  // Valores
  float esperado = 4.663689;
  float resultado = MediaQuadratica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaQuadratica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Quadratica_Numeros_Negativos) {
  int n = 4;
  float v[] = {-3, -2, -5, -7};  // Valores
  float esperado = 4.663689;
  float resultado = MediaQuadratica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaQuadratica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Media_Quadratica_Numeros_Positivos_E_Negativos) {
  int n = 4;
  float v[] = {-3, 2, -5, 7};  // Valores
  float esperado = 4.663689;
  float resultado = MediaQuadratica(v, n);
  ASSERT_FLOAT_EQ(esperado, resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"float MediaQuadratica(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  Valor esperado:  " << esperado << "\n"
  << "  Valor retornado: " << resultado << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Um_Valor) {
  int n = 1;
  float v[] = {7};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem um vetor com um unico valor nao\n"
  << "  eh possivel determinar uma progressao aritmetica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Dois_Valores) {
  int n = 2;
  float v[] = {7, 9};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem um vetor com dois valores sempre eh\n"
  << "  eh possivel determinar uma progressao aritmetica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Tres_Valores_Verdadeiro) {
  int n = 3;
  float v[] = {5, 25, 45};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao aritmetica: a1 = 5 e r = 20\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Tres_Valores_Falso) {
  int n = 3;
  float v[] = {5, 25, 46};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor nao corresponde a uma\n"
  << "  progressao aritmetica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Muitos_Valores_Verdadeiro) {
  int n = 8;
  float v[] = {1, 2, 3, 4, 5, 6, 7, 8};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor corresponde a uma\n"
  << "  progressao aritmetica: a1 = 1 e r = 1\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Muitos_Valores_Falso) {
  int n = 8;
  float v[] = {5, 25, 45, 65, 85, 105, 125, 125};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor nao corresponde a uma\n"
  << "  progressao aritmetica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Valores_Negativos) {
  int n = 5;
  float v[] = {-30, -24, -18, -12, -6};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao aritmetica: a1 = -30 e r = 6\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Razao_Negativa) {
  int n = 5;
  float v[] = {0, -2, -4, -6, -8};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao aritmetica: a1 = 0 e r = -2\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Valores_Constantes) {
  int n = 8;
  float v[] = {5, 5, 5, 5, 5, 5, 5, 5};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao aritmetica: a1 = 5 e r = 0\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Aritmetica_Valores_Nulos) {
  int n = 8;
  float v[] = {0, 0, 0, 0, 0, 0, 0, 0};  // Valores
  bool resultado = VerificaPA(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPA(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao aritmetica: a1 = 0 e r = 0\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Um_Valor) {
  int n = 1;
  float v[] = {7};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem um vetor com um unico valor nao\n"
  << "  eh possivel determinar uma progressao geometrica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Dois_Valores) {
  int n = 2;
  float v[] = {7, 9};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem um vetor com dois valores sempre eh\n"
  << "  eh possivel determinar uma progressao geometrica desde que a1!=0\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Tres_Valores_Verdadeiro) {
  int n = 3;
  float v[] = {5, 25, 125};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao geometrica: a1 = 5 e r = 5\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Tres_Valores_Falso) {
  int n = 3;
  float v[] = {5, 25, 126};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor nao corresponde a uma\n"
  << "  progressao aritmetica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Muitos_Valores_Verdadeiro) {
  int n = 5;
  float v[] = {1, 3, 9, 27, 81};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor corresponde a uma\n"
  << "  progressao geometrica: a1 = 1 e r = 3\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Muitos_Valores_Falso) {
  int n = 8;
  float v[] = {1, 2, 4, 8, 16, 32, 64, 125};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor nao corresponde a uma\n"
  << "  progressao geometrica\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Razao_Negativa) {
  int n = 8;
  float v[] = {1, -2, 4, -8, 16, -32, 64, -128};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao geometrica: a1 = 1 e r = -2\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Razao_Fracao) {
  int n = 5;
  float v[] = {1, 0.5, 0.25, 0.125, 0.0625};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao geometrica: a1 = 1 e r = 0.5\n"
  << "  (1)Verifique se a variavel que indica a razao aceita ponto\n"
  << "     flutuante.\n"
  << "  (2)Verifique o modo de comparacao de dois numeros ponto flutuante.\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Valores_Constantes) {
  int n = 8;
  float v[] = {5, 5, 5, 5, 5, 5, 5, 5};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao geometrica: a1 = 5 e r = 1\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Valores_Nulos) {
  int n = 8;
  float v[] = {0, 0, 0, 0, 0, 0, 0, 0};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_FALSE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou verdadeiro porem o vetor nao corresponde a uma\n"
  << "  progressao geometrica pois o a1 = 0, ou seja, nao eh possivel\n"
  << "  determinar uma razao para a progressao.\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Verifica_Progressao_Geometrica_Valores_Nulos_E_Primeiro_Nao_Nulo) {
  int n = 8;
  float v[] = {7, 0, 0, 0, 0, 0, 0, 0};  // Valores
  bool resultado = VerificaPG(v, n);
  ASSERT_TRUE(resultado)
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"bool VerificaPG(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores = " << MostrarVetor(v, n) << "\n"
  << "  A funcao retornou falso porem o vetor corresponde a uma\n"
  << "  progressao geometrica: a1 = 7 e r = 0\n"
  << "  DICA: Se na funcao existe uma comparacao do tipo: if(v[i+1]/v[i] != r\n"
  << "        entao ela nao se comporta bem quando v[i] = 0. Isso pode ser\n"
  << "        resolvido trocando a expressao por: if(v[i+1] != r*v[i]\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Ordena_Vetor_Valores_Positivos) {
  int n = 8;
  float entrada[] = {4, 3, 9, 1, 11, 5, 2, 7};
  float resposta[] = {4, 3, 9, 1, 11, 5, 2, 7};
  float esperado[] = {1, 2, 3, 4, 5, 7, 9, 11};
  OrdenaVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void OrdenaVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Ordena_Vetor_Valores_Negativos) {
  int n = 8;
  float entrada[] = {-4, -3, -9, -1, -11, -5, -2, -7};
  float resposta[] = {-4, -3, -9, -1, -11, -5, -2, -7};
  float esperado[] = {-11, -9, -7, -5, -4, -3, -2, -1};
  OrdenaVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void OrdenaVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Ordena_Vetor_Valores_Positivos_E_Negativos) {
  int n = 8;
  float entrada[] = {-4, 3, -9, 1, -11, 5, -2, 7};
  float resposta[] = {-4, 3, -9, 1, -11, 5, -2, 7};
  float esperado[] = {-11, -9, -4, -2, 1, 3, 5, 7};
  OrdenaVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void OrdenaVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Ordena_Vetor_Valores_Variados) {
  int n = 8;
  float entrada[] = {-4, 7, -4, 1, 1, 5, -2, 7};
  float resposta[] = {-4, 7, -4, 1, 1, 5, -2, 7};
  float esperado[] = {-4, -4, -2, 1, 1, 5, 7, 7};
  OrdenaVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void OrdenaVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Inverte_Vetor_Um_Elemento) {
  int n = 1;
  float entrada[] = {7};
  float resposta[] = {7};
  float esperado[] = {7};
  InverteVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void InverteVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Inverte_Vetor_Dois_Elementos) {
  int n = 2;
  float entrada[] = {7, 5};
  float resposta[] = {7, 5};
  float esperado[] = {5, 7};
  InverteVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void InverteVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Inverte_Vetor_Dez_Elementos) {
  int n = 10;
  float entrada[] = {1, 2, 2, 3, 4, 4, 5, 6, 6, 7};
  float resposta[] = {1, 2, 2, 3, 4, 4, 5, 6, 6, 7};
  float esperado[] = {7, 6, 6, 5, 4, 4, 3, 2, 2, 1};
  InverteVetor(resposta, n);
  ASSERT_TRUE(Iguais(esperado, resposta, n))
  << "--------------------------------------------------------------------\n"
  << "Erro na funcao: \"void InverteVetor(float[],int n)\".\n"
  << "--------------------------------------------------------------------\n"
  << "  Valores   = " << MostrarVetor(entrada, n) << "\n"
  << "  Resultado = " << MostrarVetor(resposta, n) << "\n"
  << "  Esperado  = " << MostrarVetor(esperado, n) << "\n"
  << "-------------------------------------------------------------------\n";
}

}  // Fim do namespace vazio.

#endif  // VETORES_TEST_VETORES_TEST_H_
