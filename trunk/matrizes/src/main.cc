// Copyright 2010 Thiago Ferreira de Noronha
// Lista de exerc�cios sobre estruturas de dados homogenias - Matrizes.
//
// QUEST�O 1:
// Implemente em matrizes.cc as fun��es descritas em matrizes.h.
//
// QUEST�O 2:
// Escreva um programa que l� de um arquivo o n�mero de linhas, o n�mero de
// colunas e todos os coeficientes de uma matriz
// e imprime esta matriz na tela.

#include <fstream>

#include "easytesting/matrizes/src/matrizes.h"

//1. Escreva um programa que l� de um arquivo o n�mero de linhas, o n�mero de
//colunas e todos os coeficientes de uma matriz.
int main(void) {
  std::ifstream input ;
  float a[100][100], entrada_arq;
  int n, m;
  input.open("matriz.txt");
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

