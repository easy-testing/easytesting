// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre estruturas de dados homogêneas - matrizes.
//
// QUESTÃO 1:
// Implemente em matrizes.cc as funções descritas em matrizes.h.
//
// QUESTÃO 2:
// Escreva uma função
// "void ResolverSistema(int n, float a[][MAX], float b[], float x[])"
// que recebe uma matriz triangular inferior 'a' e um vetor b de dimensão n
// representando um sistema de equações e armazena no vetor x, passado como
// parâmetro, a solução do sistema. A posição i do vetor solução deve armazenar
// o valor da variável representada pela coluna i da matriz a. Assuma que as
// linhas da matriz são linearmente independentes e que o sistema sempre tem
// solução única. Por exemplo:
//
// a = {{1, 0, 0, 0},
//      {2, 3, 0, 0},
//      {4, 5, 6, 0},
//      {7, 8, 9, 10}};
//
// b = {1, 0, 0, 0}
//
// A matriz 'a' e o vetor b a acima representam o seguinte sistema de equações:
//
// 1*x0 = 1
// 2*x0 + 3*x1 = 0
// 4*x0 + 5*x1 + 6*x2 = 0
// 7*x0 + 8*x1 + 9*x2 + 10*x3 = 0
//
// Consequentemente, o vetor x retornado por ResolverSistema deve ser
//
// x = {1.000, -0.6666, -0.1111, -0.0666}
//
// DICA:
// O sistema de equações deste exemplo pode ser reescrito da seguinte forma:
// x0 = (1 - 0) / 1
// x1 = (0 - (2*x0)) / 3
// x2 = (0 - (4*x0 + 5*x1)) / 6
// x3 = (0 - (7*x0 + 8*x1 + 9*x2)) / 10
//
// QUESTÃO 3.
// Utilizando a função da questão anterior, escreva um programa em C++ que
// lê de um arquivo uma matriz triangular inferior e um vetor que representam
// um sistema de equações e imprime na tela a solução deste sistema.

#include "matrizes/src/matrizes.h"

int main(void) {
  return 0;  // TODO.
}

