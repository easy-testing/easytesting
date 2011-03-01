// Copyright 2010 Thiago Ferreira de Noronha

#ifndef MATRIZES_SRC_MATRIZES_H_
#define MATRIZES_SRC_MATRIZES_H_

// Recebe uma matriz quadrada de dimensão n e
// retorna a média dos elementos armazenados na matriz.
float MediaMatriz(int n, float mat[][100]);

// Retorna através de A uma matriz identidade de dimensão n.
void Identidade(int n, float A[][100]);

// Recebe uma matriz quadrada A de dimensão n e
// retorna uma matriz T que é a transposta de A.
void Transposta(int n, float A[][100], float T[][100]);

// Testa se uma matriz quadrada A de dimensão n é simétrica.
bool Simetrica(int n, float A[][100]);

// Recebe duas matrizes quadradas A e B de dimensão n
// e retorna uma matriz S que é a soma de A e B.
void SomaMatriz(int n, float A[][100], float B[][100], float S[][100]);

// Recebe duas matrizes quadradas A e B de dimensão n
// e retorna uma matriz P que é o produto de A e B.
void MultMatriz(int n, float A[][100], float B[][100], float P[][100]);

// Mostra os coeficientes de uma matriz na tela no formato:
// | a[0][0] a[0][1] a[0][2] a[0][3] |
// | a[1][0] a[1][1] a[1][2] a[1][3] |
// | a[2][0] a[2][1] a[2][2] a[2][3] |
void MostraMatriz(int n, int m, float a[][100]);

#endif  // MATRIZES_SRC_MATRIZES_H_
