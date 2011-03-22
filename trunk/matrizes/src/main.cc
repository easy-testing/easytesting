// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exerc�cios sobre estruturas de dados homogenias - Matrizes.
//
// QUEST�O 1:
// Implemente em matrizes.cc as fun��es descritas em matrizes.h.
//
// QUEST�O 2:
// Escreva um programa que l� de um arquivo o n�mero de linhas, o n�mero de
// colunas e todos os coeficientes de uma matriz e imprime esta matriz na tela.
// Use este programa para testar se as fun��es que voc� implementou na quest�o 1
// est�o corretas.

#include <fstream>

#include "matrizes/src/matrizes.h"

// L� de um arquivo o n�mero de linhas, o n�mero de
// colunas e todos os coeficientes de uma matriz
// e imprime esta matriz na tela.
int main(void) {
  std::ifstream input;
  float a[100][100], entrada_arq;
  int n, m;
  input.open("input.txt");
  input >> n >> m;
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < m ; j++) {
      input >> entrada_arq;
      a[i][j] = entrada_arq;
    }
  }
  MostraMatriz(n, m, a);
  input.close();
  return 0;
}

