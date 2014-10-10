// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_MATRIZES_SRC_MATRIZES_H_
#define TRUNK_MATRIZES_SRC_MATRIZES_H_

#define MAX 100  // Dimensão máxima de uma matriz.

// Recebe uma matriz quadrada de dimensão n e
// retorna a média dos elementos armazenados na matriz.
float MediaMatriz(int n, float a[][MAX]);

// Retorna através de 'a' uma matriz identidade de dimensão n.
void Identidade(int n, float a[][MAX]);

// Recebe uma matriz quadrada 'a' de dimensão n e
// retorna uma matriz t que é a transposta de 'a'.
void Transposta(int n, float a[][MAX], float T[][MAX]);

// Testa se uma matriz quadrada 'a' de dimensão n é simétrica.
bool Simetrica(int n, float a[][MAX]);

// Recebe duas matrizes quadradas 'a' e b de dimensão n
// e retorna uma matriz s que é a soma de 'a' e b.
void SomaMatriz(int n, float a[][MAX], float b[][MAX], float s[][MAX]);

// Recebe duas matrizes quadradas `a` e b de dimensão n
// e retorna uma matriz p que é o produto de a e b.
void MultMatriz(int n, float a[][MAX], float b[][MAX], float p[][MAX]);

// Mostra os coeficientes de uma matriz na tela no formato:
// | a[0][0] a[0][1] a[0][2] a[0][3] ...|
// | a[1][0] a[1][1] a[1][2] a[1][3] ...|
// | a[2][0] a[2][1] a[2][2] a[2][3] ...|
// |   ...     ...     ...     ...   ...|
void MostraMatriz(int n, int m, float a[][MAX]);

#endif  // TRUNK_MATRIZES_SRC_MATRIZES_H_
