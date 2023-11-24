// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
#include "../doctest/doctest.h"
#include "src/matrizes.h"

using std::string;
using std::stringstream;

namespace Teste {

// Classe base dos casos de teste.
class Teste {
 protected:
  // Imprime uma Matriz determinada.
  string Imprime_1_Matriz(int n, int m, int espacos, float A[][MAX]) {
    stringstream output;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < espacos; ++j) {
        output << " ";
      }
      output << "|";
      for (int j = 0; j < m; ++j) {
        output << "  " << A[i][j];
      }
      output << "  |\n";
    }
    return output.str();
  }

  // Imprime duas Matrizes determinadas
  string " " << Imprime_2_Matrizes(int n, int m, int espaco << "\n"s,
                            float A[][MAX], float B[][MAX]) {
    stringstream output;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < espacos; ++j) {
        output << " ";
      }
      output << "|";
      for (int j = 0; j < m; ++j) {
        output << "  " << A[i][j];
      }
      output << "  |        |";
      for (int j = 0; j < m; ++j) {
        output << "  " << B[i][j];
      }
      output << "  |\n";
    }
    return output.str();
  }
  // Funcao que testa duas matrizes sao iguais
  bool Iguais(int n, int m, float A[][MAX], float B[][MAX]) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (A[i][j] - B[i][j] > 0.000001) {
          return false;
        }
      }
    }
    return true;
  }
};

TEST_CASE("Tasta_MediaMatriz_com_matriz_1x1") {
  float mat[MAX][MAX] = {{3.52}};
  float resultado = MediaMatriz(1, mat);
  float esperado = 3.52;

  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(1, 1, 28, mat));
    INFO( "\nMedia esperada: " << esperado << "\n");
    INFO( "Media retornada: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_divisao_correta_na_MediaMatriz") {
  float mat[MAX][MAX] = {{1.0, 1.0, 1.0, 1.0},
                         {1.0, 1.0, 1.0, 1.0},
                         {1.0, 1.0, 1.0, 1.0},
                         {1.0, 1.0, 1.0, 1.0}};
  float inesperado = 4;
  float resultado = MediaMatriz(4, mat);
  REQUIRE(resultado != doctest::Approx(inesperado));
  CHECK(resultado != doctest::Approx(inesperado));
  if (resultado == doctest::Approx(inesperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 18, mat));
    INFO( "\nMedia esperada: " << 1.0 << "\n");
    INFO( "Media retornada: " << resultado << "\n");
    INFO( "  Provavelmente a divisao do seu somatorio eh por n, enquanto\n");
    INFO( "deveria ser por n*n\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_MediaMatriz_com_elementos_positivos") {
  float mat[MAX][MAX] = {{0.1, 1.5, 2.4, 3.1},
                         {1.1, 2.5, 3.3, 4.1},
                         {2.2, 3.2, 4.7, 5.8},
                         {3.9, 4.1, 5.5, 6.4}};
  float soma = 53.9;  // Soma dos elementos
  float esperado = 3.36875;
  float resultado = MediaMatriz(4, mat);

  REQUIRE(soma != doctest::Approx(resultado));
  CHECK(soma != doctest::Approx(resultado));
  if (soma == doctest::Approx(resultado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "  A funcao retornou a soma dos elementos da matriz.\n");
    INFO( "Verifique se esta funcao dividi a soma dos elementos\n");
    INFO( "da matriz pelo numero de elementos dela\n");
    INFO( "-------------------------------------------------------------------\n";);
  }

  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 20, mat));
    INFO( "\nMedia esperada: " << esperado << "\n");
    INFO( "Media retornada: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_MediaMatriz_com_elementos_negativos") {
  float mat[MAX][MAX] = {{-1.4, -1.1, -1.4, -1.3},
                         {-2.6, -1.2, -3.4, -4.5},
                         {-2.8, -1.1, -3.1, -4.6},
                         {-3.2, -5.5, -4.4, -6.4}};
  float esperado = -3;
  float resultado = MediaMatriz(4, mat);
  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"float Media(int n, float matriz[][])\".          \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 18, mat));
    INFO( "\nMedia esperada: " << esperado << "\n");
    INFO( "Media retornada: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Identidade_com_matriz_1x1") {
  float mat[MAX][MAX];
  float mat_esperada[MAX][MAX] = {{1}};
  Identidade(1, mat);
  bool resultado = mat[0][0] == 1;
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"void identidade(int n, float matriz[][])\".      \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(1, 1, 28, mat));
    INFO( "\n         Resposta incorreta        Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(1, 1, 20, mat, mat_esperada) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Identidade") {
  float mat[MAX][MAX];
  float mat_esperada[MAX][MAX] = {{1, 0, 0, 0},
                                  {0, 1, 0, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 1}};
  Identidade(4, mat);
  bool resultado = Iguais(4, 4, mat, mat_esperada);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"void identidade(int n, float matriz[][])\".      \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "\n           Resposta incorreta       Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 12, mat, mat_esperada) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Transposta_com_matriz_1x1") {
  float mat[MAX][MAX] = {{5}};
  float mat_resultado[MAX][MAX];
  Transposta(1, mat, mat_resultado);
  bool resultado = Iguais(1, 1, mat, mat_resultado);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"void transposta(int n, float [][], float [][]))\"\n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(1, 1, 28, mat));
    INFO( "\n         Resposta incorreta        Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(1, 1, 20, mat_resultado, mat) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Transposta_com_matriz_4x4") {
  float mat[MAX][MAX] = {{3.2, 2.1, 1.4, 0.5},
                         {4.6, 3.2, 2.1, 1.1},
                         {5.2, 4.3, 3.4, 2.5},
                         {6.6, 5.7, 4.8, 3.9}};
  float mat_esperada[MAX][MAX] = {{3.2, 4.6, 5.2, 6.6},
                                  {2.1, 3.2, 4.3, 5.7},
                                  {1.4, 2.1, 3.4, 4.8},
                                  {0.5, 1.1, 2.5, 3.9}};
  float mat_resultado[MAX][MAX];
  Transposta(4, mat, mat_resultado);
  bool resultado = Iguais(4, 4, mat_resultado, mat_esperada);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"void transposta(int n, float [][], float [][]))\"\n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 21, mat));
    INFO( "\n        Resposta incorreta               Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 5, mat_resultado, mat_esperada) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Simetrica_com_matrizes_nao_simetrica") {
  float mat[MAX][MAX] = {{0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 5, 0, 0},
                         {0, 0, 0, 0}};
  bool resultado = Simetrica(4, mat);
  REQUIRE(!resultado);
  CHECK(!resultado);
  if (resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na funcao: \"void simetrica(int n, float [][]))\"             \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 22, mat));
    INFO( "\n");
    INFO( "Matriz não simétrica, porém a função retornou true\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Simetrica_com_matrizes_simetricas") {
  float mat[MAX][MAX] = {{1.5, 7.4, 3.2, 0.1},
                         {7.4, 2.2, 0.1, 0.2},
                         {3.2, 0.1, 3.4, 6.5},
                         {0.1, 0.2, 6.5, 4.8}};
  bool resultado = Simetrica(4, mat);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"void simetrica(int n, float [][]))\"             \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 18, mat));
    INFO( "\nMatriz simétrica, porém a função retornou false\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_SomaMatriz_com_matrizes_arbitrarias") {
  float mat1[MAX][MAX] = {{1.2, 7.4, 3.1, 0.1},
                          {7.2, 2.3, 0.4, 0.1},
                          {3.2, 0.8, 3.2, 6.7},
                          {0.4, 0.5, 6.6, 4.1}};
  float mat2[MAX][MAX] = {{2.1, 1.3, 4.3, 3.5},
                          {0.6, 2.4, 1.1, 3.8},
                          {1.9, 2.7, 6.5, 2.6},
                          {1.4, 2.2, 2.3, 3.1}};
  float mat_esp[MAX][MAX] = {{3.3, 8.7, 7.4, 3.6},
                             {7.8, 4.7, 1.5, 3.9},
                             {5.1, 3.5, 9.7, 9.3},
                             {1.8, 2.7, 8.9, 7.2}};
  float mat_resultado[MAX][MAX];
  SomaMatriz(4, mat1, mat2, mat_resultado);
  bool resultado = Iguais(4, 4, mat_esp, mat_resultado);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"void soma_matriz\n");
    INFO( "                        (int n, float[][], float[][], float[][])\" \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "         Matriz de Entrada 1            Matriz de Entrada 2\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 6, mat1, mat2) << "\n");
    INFO( "\n         Resposta incorreta               Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 6, mat_resultado, mat_esp) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_SomaMatriz_com_matriz_nula") {
  float mat1[MAX][MAX] = {{1.2, 7.1, 3.2, 0.1},
                          {7.6, 2.4, 0.5, 0.4},
                          {3.3, 0.8, 3.4, 6.5},
                          {0.9, 0.7, 6.8, 4.9}};
  float mat2[MAX][MAX] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};
  float mat_esperada[MAX][MAX] = {{1.2, 7.1, 3.2, 0.1},
                                  {7.6, 2.4, 0.5, 0.4},
                                  {3.3, 0.8, 3.4, 6.5},
                                  {0.9, 0.7, 6.8, 4.9}};
  float mat_resultado[MAX][MAX];
  SomaMatriz(4, mat1, mat2, mat_resultado);
  bool resultado = Iguais(4, 4, mat_esperada, mat_resultado);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"void soma_matriz\n");
    INFO( "                        (int n, float[][], float[][], float[][])\" \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "           Matriz de Entrada 1         Matriz de Entrada 2\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 8, mat1, mat2) << "\n");
    INFO( "\n        Resposta incorreta               Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 5, mat_resultado, mat_esperada) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_MultMatriz_com_matrizes_arbitrarias") {
  float mat1[MAX][MAX] = {{1.2, 7.1, 3.2, 0.1},
                          {7.6, 2.4, 0.5, 0.4},
                          {3.3, 0.8, 3.4, 6.5},
                          {0.9, 0.7, 6.8, 4.9}};
  float mat2[MAX][MAX] = {{1.2, 0.3, 1.1, 0.9},
                          {2.5, 1.4, 0.2, 1.3},
                          {3.8, 2.1, 0.7, 2.5},
                          {0.5, 0.8, 1.7, 0.3}};
  float mat_esp[MAX][MAX] = {{20.31, 15.57, 6.68, 15.69},
                             {15.73, 13.17, 7.44, 13.33},
                             {31.64, 19.53, 23.84, 24.38},
                             {21.42, 12.94, 24.98, 17.42}};
  float mat_resultado[MAX][MAX];
  MultMatriz(4, mat1, mat2, mat_resultado);
  bool resultado = Iguais(4, 4, mat_esp, mat_resultado);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"void mult_matriz\n");
    INFO( "                        (int n, float[][], float[][], float[][])\" \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "         Matriz de Entrada 1            Matriz de Entrada 2\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 6, mat1, mat2) << "\n");
    INFO( "\n         Resposta incorreta               Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 15, mat_resultado, mat_esp) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_MultMatriz_com_matriz_identidade") {
  float mat1[MAX][MAX] = {{1.2, 7.1, 3.2, 0.1},
                          {7.6, 2.4, 0.5, 0.4},
                          {3.3, 0.8, 3.4, 6.5},
                          {0.9, 0.7, 6.8, 4.9}};
  float mat2[MAX][MAX];
  Identidade(4, mat2);
  float mat_esperada[MAX][MAX];
  CopiaMatriz(4, mat1, mat_esperada);
  float mat_resultado[MAX][MAX];
  MultMatriz(4, mat1, mat2, mat_resultado);
  bool resultado = Iguais(4, 4, mat_esperada, mat_resultado);
  REQUIRE(resultado);
  CHECK(resultado);
  if (!resultado) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"void mult_matriz\n");
    INFO( "                        (int n, float[][], float[][], float[][])\" \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "         Matriz de Entrada 1           Matriz Identidade\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 6, mat1, mat2) << "\n");
    INFO( "\n         Resposta incorreta               Resposta correta\n\n");
    INFO( " " << Imprime_2_Matrizes(4, 4, 10, mat_resultado, mat_esperada) << "\n");
    INFO( "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Determinante_com_matriz_1x1") {
  float mat[MAX][MAX] = {{4}};
  float esperado = 4;
  float resultado = Determinante(1, mat);
  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"float determinante\n");
    INFO( "                        (int n, float matriz[][])\"                \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(1, 1, 19, mat));
    INFO( "\nDeterminante esperado: " << esperado << "\n");
    INFO( "Determinante retornado: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Determinante_com_matriz_2x2") {
  float mat[MAX][MAX] = {{1.2, 3.4},
                         {4.5, 2.1}};
  float esperado = -14.49;
  float resultado = Determinante(2, mat);
  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"float determinante\n");
    INFO( "                        (int n, float matriz[][])\"                \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(2, 2, 19, mat));
    INFO( "\nDeterminante esperado: " << esperado << "\n");
    INFO( "Determinante retornado: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Determinante_com_matriz_3x3") {
  float mat[MAX][MAX] = {{1.1, 2.2, 3.3},
                         {4.4, 5.5, 6.6},
                         {7.7, 8.8, 9.9}};
  float esperado = 0;
  float resultado = Determinante(3, mat);
  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"float determinante\n");
    INFO( "                        (int n, float matriz[][])\"                \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(3, 3, 19, mat));
    INFO( "\nDeterminante esperado: " << esperado << "\n");
    INFO( "Determinante retornado: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

TEST_CASE("Testa_Determinante_com_matriz_4x4") {
  float mat[MAX][MAX] = {{1, 3, 1, 4},
                         {2, 4, 4, 2},
                         {1, 3, 3, 4},
                         {1, 2, 3, 2}};
  float esperado = -12;
  float resultado = Determinante(4, mat);
  REQUIRE(resultado == doctest::Approx(esperado));
  CHECK(resultado == doctest::Approx(esperado));
  if (resultado != doctest::Approx(esperado)) {
    std::cerr
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Erro na função: \"float determinante\n");
    INFO( "                        (int n, float matriz[][])\"                \n");
    INFO( "-------------------------------------------------------------------\n");
    INFO( "Matriz de Entrada:"<< Imprime_1_Matriz(4, 4, 19, mat));
    INFO( "\nDeterminante esperado: " << esperado << "\n");
    INFO( "Determinante retornado: " << resultado << "\n");
    INFO( "-------------------------------------------------------------------\n";);
  }
}

}  // namespace Teste.


