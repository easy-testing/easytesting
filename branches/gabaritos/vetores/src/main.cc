// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados homogêneas - Vetores.
//
// QUESTÃO 1:
// Implemente em vetores.cc as funções descritas em vetores.h.
//
// QUESTÃO 2:
// Escreva um programa em C++ que lê uma sequência de números de um arquivo
// e armazena em um vetor. Assuma que a quantidade de numeros no arquivo
// não ultrapassa o limite máximo de elementos do vetor (e.g. 1000).
// Use este programa para testar as funções que você implementou na questão 1.

#include <fstream>

#include "vetores/src/vetores.h"

// Lê uma sequência de números de um arquivo, armazena em um vetor e os imprime
// na tela.
int main() {
  float x;
  int n = 0;
  float v[1000];
  std::ifstream input("input.txt");
  while (input >> x) {
    v[n] = x;
    n++;
  }
  MostraVetor(v, n);
  return 0;
}