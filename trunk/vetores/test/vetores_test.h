#ifndef VETORES_TESTE_H_
#define VETORES_TESTE_H_

#include "easytesting/vetores/src/vetores.h"

#include "easytesting/gtest/gtest.h"

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

namespace {

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
};

TEST_F(Teste, Testa_acesso_indevido_na_funcao_Media) {
  int n = 4;
  float v[] = {4, 8, 12, 16, 1000000};
  float esperado = 200008;
  float atual = Media(v, n);
  ASSERT_NE(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(float v[], int n)\".                 \n"
    << "-------------------------------------------------------------------\n"
    << "  Sua funcao esta acessando um elemento do vetor nao               \n"
    << "definido. Veja se ela esta acessando no maximo o elemento n - 1 de \n"
    << "um vetor de n elementos.                                           \n"
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
    << "Erro na funcao: \"float Variancia(float v[], int n)\               \n"
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
    << "Erro na funcao: \"float Variancia(float v[], int n)\               \n"
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
    << "Erro na funcao: \"float Variancia(float v[], int n)\               \n"
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
    << "Erro na funcao:  \"float Variancia(float v[], int n)\              \n"
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

}  // Fim do namespace vazio.

#endif // VETORES_TESTE_H_
