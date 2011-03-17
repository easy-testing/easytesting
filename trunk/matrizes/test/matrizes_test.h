// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
#ifndef MATRIZES_TEST_MATRIZES_TEST_H_
#define MATRIZES_TEST_MATRIZES_TEST_H_

#include <sstream>
#include <string>
#include "easytesting/matrizes/src/matrizes.h"
#include "easytesting/gtest/gtest.h"

// Definir dimensao maxima da matriz quadrada
#define DM 100

using std::string;
using std::stringstream;

namespace Teste {

// Classe base dos casos de teste.
class Teste : public testing::Test {
 protected:
  // Imprime uma Matriz determinada
  string Imprime_1_Matriz(int n, int m, int espacos, float A[][DM]) {
    stringstream output;
    int i;
    int j;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < espacos; ++j) output << " ";
      output << "|";
      for (j = 0; j < m; ++j) {
        output << "  " << A[i][j];
      }
      output << "  |\n";
    }
    return output.str();
  }
  // Imprime duas Matrizes determinadas
  string Imprime_2_Matrizes(int n, int m, int espacos,
                            float A[][DM], float B[][DM]) {
    stringstream output;
    int i;
    int j;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < espacos; ++j) output << " ";
      output << "|";
      for (j = 0; j < m; ++j) {
        output << "  " << A[i][j];
      }
      output << "  |        |";
      for (j = 0; j < m; ++j) {
        output << "  " << B[i][j];
      }
      output << "  |\n";
    }
    return output.str();
  }
  // Funcao que testa duas matrizes sao iguais
  bool Iguais(int n, int m, float A[][DM], float B[][DM]) {
    int i;
    int j;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        if (A[i][j] - B[i][j] > 0.000001) return false;
      }
    }
    return true;
  }
};

TEST_F(Teste, Media_Matriz_1x1) {
  float mat[DM][DM] = { {3.52} };
  float resultado = MediaMatriz(1, mat);
  float esperado = 3.52;

  ASSERT_FLOAT_EQ(esperado, resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(1, 1, 28,  mat)
    << "\n    Media esperada: " << esperado << "\n"
    << "   Media retornada: " << resultado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Media_Matriz_Quadrada_elementos_positivos) {
  float mat[DM][DM] = { {0.1, 1.5, 2.4, 3.1}, {1.1, 2.5, 3.3, 4.1},
                      {2.2, 3.2, 4.7, 5.8}, {3.9, 4.1, 5.5, 6.4} };
  float soma = 53.9;  // Soma dos elementos
  float esperado = 3.36875;
  float resultado = MediaMatriz(4, mat);

  ASSERT_NE(soma, resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n"
    << "-------------------------------------------------------------------\n"
    << "   A funcao retornou a soma dos elementos da matriz.\n"
    << "Verifique se esta funcao dividi a soma dos elementos\n"
    << "da matriz pelo numero de elementos dela\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_FLOAT_EQ(esperado, resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(4, 4, 20, mat)
    << "\n    Media esperada: " << esperado << "\n"
    << "   Media retornada: " << resultado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Media_Matriz_Quadrada_elementos_negativos) {
  float mat[DM][DM] = { {-1.4, -1.1, -1.4, -1.3}, {-2.6, -1.2, -3.4, -4.5},
                       {-2.8, -1.1, -3.1, -4.6}, {-3.2, -5.5, -4.4, -6.4} };
  float esperado = -3;
  float resultado = MediaMatriz(4, mat);
  ASSERT_FLOAT_EQ(esperado, resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(4, 4, 18, mat)
    << "\n    Media esperada: " << esperado << "\n"
    << "   Media retornada: " << resultado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Identidade_Matriz_1x1) {
  float mat[DM][DM];
  float mat_esperada[DM][DM] = { {1} };

  Identidade(1, mat);

  bool resultado = mat[0][0] == 1;

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void identidade(int n, float matriz[][])\".      \n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(1, 1, 28,  mat)
    << "\n         Resposta incorreta        Resposta correta\n\n"
    << Imprime_2_Matrizes(1, 1, 20,  mat, mat_esperada)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Identidade_Matriz_Quadrada) {
  float mat[DM][DM];
  float mat_esperada[DM][DM] = { {1, 0, 0, 0}, {0, 1, 0, 0},
                                {0, 0, 1, 0}, {0, 0, 0, 1} };

  Identidade(4, mat);

  bool resultado = Iguais(4, 4, mat, mat_esperada);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void identidade(int n, float matriz[][])\".      \n"
    << "-------------------------------------------------------------------\n"
    << "\n           Resposta incorreta       Resposta correta\n\n"
    << Imprime_2_Matrizes(4, 4, 12, mat, mat_esperada)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Transposta_Matriz_1x1) {
  float mat[DM][DM] = { {5} };
  float mat_resultado[DM][DM];

  Transposta(1, mat,  mat_resultado);

  bool resultado = Iguais(1, 1, mat, mat_resultado);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void transposta(int n, float [][], float [][]))\"\n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(1, 1, 28,  mat)
    << "\n         Resposta incorreta        Resposta correta\n\n"
    << Imprime_2_Matrizes(1, 1, 20,  mat_resultado, mat)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Transposta_Matriz_Quadrada) {
  float mat[DM][DM] = { {3.2, 2.1, 1.4, 0.5}, {4.6, 3.2, 2.1, 1.1},
                       {5.2, 4.3, 3.4, 2.5}, {6.6, 5.7, 4.8, 3.9} };
  float mat_esperada[DM][DM] = { {3.2, 4.6, 5.2, 6.6}, {2.1, 3.2, 4.3, 5.7},
                                {1.4, 2.1, 3.4, 4.8}, {0.5, 1.1, 2.5, 3.9} };
  float mat_resultado[DM][DM];

  Transposta(4, mat, mat_resultado);

  bool resultado = Iguais(4, 4,  mat_resultado, mat_esperada);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void transposta(int n, float [][], float [][]))\"\n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(4, 4, 21,  mat)
    << "\n        Resposta incorreta               Resposta correta\n\n"
    << Imprime_2_Matrizes(4, 4, 5,  mat_resultado, mat_esperada)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Simetria_matriz_nao_simetrica) {
  float mat[DM][DM] = { {0, 0, 0, 0}, {0, 0, 0, 0},
                      {0, 5, 0, 0}, {0, 0, 0, 0} };
  bool resultado = Simetrica(4, mat);

  ASSERT_FALSE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void simetrica(int n, float [][]))\"             \n"
    << "-------------------------------------------------------------------\n"
    << "                       Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(4, 4, 22,  mat)
    << "\n"
    << " Matriz nao simetrica, porem a funcao retornou true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Simetria_matriz_simetrica) {
  float mat[DM][DM] = { {1.5, 7.4, 3.2, 0.1}, {7.4, 2.2, 0.1, 0.2},
                       {3.2, 0.1, 3.4, 6.5}, {0.1, 0.2, 6.5, 4.8} };
  bool resultado = Simetrica(4, mat);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void simetrica(int n, float [][]))\"             \n"
    << "-------------------------------------------------------------------\n"
    << "                     Matriz de Entrada:\n\n"
    << Imprime_1_Matriz(4, 4, 18,  mat)
    << "\nMatriz simetrica, porem a funcao retornou false\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Soma_matrizes_positivas) {
  float mat1[DM][DM] = { {1.2, 7.4, 3.1, 0.1}, {7.2, 2.3, 0.4, 0.1},
                      {3.2, 0.8, 3.2, 6.7}, {0.4, 0.5, 6.6, 4.1} };
  float mat2[DM][DM] = { {2.1, 1.3, 4.3, 3.5}, {0.6, 2.4, 1.1, 3.8},
                      {1.9, 2.7, 6.5, 2.6}, {1.4, 2.2, 2.3, 3.1} };
  float mat_esp[DM][DM] = { {3.3, 8.7, 7.4, 3.6}, {7.8, 4.7, 1.5, 3.9},
                           {5.1, 3.5, 9.7, 9.3}, {1.8, 2.7, 8.9, 7.2} };
  float mat_resultado[DM][DM];

  SomaMatriz(4, mat1, mat2, mat_resultado);

  bool resultado = Iguais(4, 4, mat_esp, mat_resultado);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void soma_matriz\n"
    << "                        (int n, float[][], float[][], float[][])\" \n"
    << "-------------------------------------------------------------------\n"
    << "         Matriz de Entrada 1            Matriz de Entrada 2\n\n"
    << Imprime_2_Matrizes(4, 4, 6, mat1, mat2)
    << "\n         Resposta incorreta               Resposta correta\n\n"
    << Imprime_2_Matrizes(4, 4, 6, mat_resultado, mat_esp)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Soma_matrizes_com_uma_nula) {
  float mat1[DM][DM] = { {1.2, 7.1, 3.2, 0.1}, {7.6, 2.4, 0.5, 0.4},
                        {3.3, 0.8, 3.4, 6.5}, {0.9, 0.7, 6.8, 4.9} };
  float mat2[DM][DM] = { {0, 0, 0, 0}, {0, 0, 0, 0},
                        {0, 0, 0, 0}, {0, 0, 0, 0} };
  float mat_esperada[DM][DM] = { {1.2, 7.1, 3.2, 0.1}, {7.6, 2.4, 0.5, 0.4},
                           {3.3, 0.8, 3.4, 6.5}, {0.9, 0.7, 6.8, 4.9} };
  float mat_resultado[DM][DM];

  SomaMatriz(4, mat1, mat2, mat_resultado);

  bool resultado = Iguais(4, 4, mat_esperada, mat_resultado);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void soma_matriz\n"
    << "                        (int n, float[][], float[][], float[][])\" \n"
    << "-------------------------------------------------------------------\n"
    << "           Matriz de Entrada 1         Matriz de Entrada 2\n\n"
    << Imprime_2_Matrizes(4, 4, 8,  mat1, mat2)
    << "\n        Resposta incorreta               Resposta correta\n\n"
    << Imprime_2_Matrizes(4, 4, 5,  mat_resultado, mat_esperada)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicacao_Matrizes_diversas) {
  float mat1[DM][DM] = { {1.3, 1.4, 2.5, 0.1}, {1.2, 2.3, 0.4, 1.6},
                        {1.7, 2.5, 0.4, 0.5}, {1.2, 0.1, 2.6, 0.4} };
  float mat2[DM][DM] = { {2.4, 1.1, 0.2, 0.8}, {1.7, 1.4, 1.5, 1.2},
                        {2.1, 2.3, 1.2, 1.4}, {0.9, 0.6, 2.2, 0.1} };
  float mat_resultado[DM][DM];
  float mat_esperada[DM][DM] = { {10.84, 9.2, 5.58, 6.23},
                                {9.07, 6.42, 7.69, 4.44},
                                {9.62, 6.59, 5.67, 4.97},
                                {8.87, 7.68, 4.39, 4.76} };

  MultMatriz(4, mat1, mat2, mat_resultado);

  bool resultado = Iguais(4, 4, mat_resultado, mat_esperada);

  ASSERT_TRUE(resultado)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void mult_matriz\n"
    << "                        (int n, float[][], float[][], float[][])\" \n"
    << "-------------------------------------------------------------------\n"
    << "        Matriz de Entrada 1            Matriz de Entrada 2\n\n"
    << Imprime_2_Matrizes(4, 4, 5,  mat1, mat2)
    << "\n       Resposta incorreta                   Resposta correta\n\n"
    << Imprime_2_Matrizes(4, 4, 2,  mat_resultado, mat_esperada)
    << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Multiplicacao_Matrizes_resposta_nula) {
  float mat1[DM][DM] = { {2, 0, 0, 4}, {1, 0, 0, 0},
                        {5, 0, 0, 7}, {4, 0, 0, 7} };
  float mat2[DM][DM] = { {0, 0, 0, 0}, {0, 0, 0, 5},
                        {8, 4, 3, 9}, {0, 0, 0, 0} };
  float mat_resultado[DM][DM];
  float mat_esperada[DM][DM] = { {0, 0, 0, 0}, {0, 0, 0, 0},
                                {0, 0, 0, 0}, {0, 0, 0, 0} };

  MultMatriz(4, mat1, mat2, mat_resultado);

  bool resposta = Iguais(4, 4, mat_resultado, mat_esperada);

  ASSERT_TRUE(resposta)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: \"void mult_matriz\n"
    << "                        (int n, float[][], float[][], float[][])\" \n"
    << "-------------------------------------------------------------------\n"
    << "           Matriz de Entrada 1     Matriz de Entrada 2\n\n"
    << Imprime_2_Matrizes(4, 4, 13,  mat1, mat2)
    << "\n            Resposta incorreta       Resposta correta\n\n"
    << Imprime_2_Matrizes(4, 4, 13,  mat_resultado, mat_esperada)
    << "\n"
    << "-------------------------------------------------------------------\n";
}
}  // Fim do namespace vazio.

#endif  // MATRIZES_TEST_MATRIZES_TEST_H_
