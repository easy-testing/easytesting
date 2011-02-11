// Copyright 2010 Thiago Ferreira de Noronha
// Lista de exercícios sobre estruturas de dados homogenias - Matrizes.
//
// QUESTÃO 1:
// Implemente em matrizes.cc as funções descritas em matrizes.h.
//
// QUESTÃO 2:
// Escreva um programa que lê de um arquivo o número de linhas, o número de
// colunas e todos os coeficientes de uma matriz
// e imprime esta matriz na tela.

#include <fstream>

#include "easytesting/matrizes/src/matrizes.h"

//1. Escreva um programa que lê de um arquivo o número de linhas, o número de
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

