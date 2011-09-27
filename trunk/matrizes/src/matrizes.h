// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef MATRIZES_SRC_MATRIZES_H_
#define MATRIZES_SRC_MATRIZES_H_

#define MAX 100  // Dimensao maxima de uma matriz.

// Recebe uma matriz quadrada de dimensao n e
// retorna a media dos elementos armazenados na matriz.
float MediaMatriz(int n, float mat[][MAX]);

// Retorna atraves de A uma matriz identidade de dimensao n.
void Identidade(int n, float A[][MAX]);

// Recebe uma matriz quadrada A de dimensao n e
// retorna uma matriz T que eh a transposta de A.
void Transposta(int n, float A[][100], float T[][MAX]);

// Testa se uma matriz quadrada A de dimensao n eh simetrica.
bool Simetrica(int n, float A[][MAX]);

// Recebe duas matrizes quadradas A e B de dimensao n
// e retorna uma matriz S que eh a soma de A e B.
void SomaMatriz(int n, float A[][MAX], float B[][MAX], float S[][MAX]);

// Recebe duas matrizes quadradas A e B de dimensao n
// e retorna uma matriz P que eh o produto de A e B.
void MultMatriz(int n, float A[][MAX], float B[][MAX], float P[][MAX]);

// Mostra os coeficientes de uma matriz na tela no formato:
// | a[0][0] a[0][1] a[0][2] a[0][3] ...|
// | a[1][0] a[1][1] a[1][2] a[1][3] ...|
// | a[2][0] a[2][1] a[2][2] a[2][3] ...|
// |   ...     ...     ...     ...   ...|
void MostraMatriz(int n, int m, float a[][MAX]);

// Multiplica a matriz A por uma escalar k e armazena o resultado em Out.
void EscalarMatriz(int n, int m, int k, float A[][MAX], float Out[][MAX]);

// Calcula o determinante de uma matriz 3x3.
float DeterminanteMatriz(float A[][MAX]);

// Verifica se uma matriz eh triangular inferior.
bool VerificaTriangularInferior(int n, float A[][MAX]);

// Verifica se uma matriz eh triangular superior.
bool VerificaTriangularSuperior(int n, float A[][MAX]);

#endif  // MATRIZES_SRC_MATRIZES_H_
