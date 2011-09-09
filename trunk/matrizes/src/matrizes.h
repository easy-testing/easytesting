// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef MATRIZES_SRC_MATRIZES_H_
#define MATRIZES_SRC_MATRIZES_H_

#define MAX 100 // Dimensao máxima de uma matriz.

// Recebe uma matriz quadrada de dimensão n e
// retorna a média dos elementos armazenados na matriz.
float MediaMatriz(int n, float mat[][MAX]);

// Retorna através de A uma matriz identidade de dimensão n.
void Identidade(int n, float A[][MAX]);

// Recebe uma matriz quadrada A de dimensão n e
// retorna uma matriz T que é a transposta de A.
void Transposta(int n, float A[][100], float T[][MAX]);

// Testa se uma matriz quadrada A de dimensão n é simétrica.
bool Simetrica(int n, float A[][MAX]);

// Recebe duas matrizes quadradas A e B de dimensão n
// e retorna uma matriz S que é a soma de A e B.
void SomaMatriz(int n, float A[][MAX], float B[][MAX], float S[][MAX]);

// Recebe duas matrizes quadradas A e B de dimensão n
// e retorna uma matriz P que é o produto de A e B.
void MultMatriz(int n, float A[][MAX], float B[][MAX], float P[][MAX]);

// Mostra os coeficientes de uma matriz na tela no formato:
// | a[0][0] a[0][1] a[0][2] a[0][3] ...|
// | a[1][0] a[1][1] a[1][2] a[1][3] ...|
// | a[2][0] a[2][1] a[2][2] a[2][3] ...|
// |   ...     ...     ...     ...   ...|
void MostraMatriz(int n, int m, float a[][MAX]);

// Multiplica a matriz A por uma escalar e armazena oresultado em Out
void EscalarMatriz(int n, int m, int escalar, float A[][MAX], float Out[][MAX]);

// Calcula o determinante de uma matriz 3x3
float DeterminanteMatriz(float A[][MAX]);

// Verifica se uma matriz é triangular inferior
bool VerificaTriangularInferior(int n, float A[][MAX]);

// Verifica se uma matriz é triangular superior
bool VerificaTriangularSuperior(int n, float A[][MAX]);

#endif  // MATRIZES_SRC_MATRIZES_H_
