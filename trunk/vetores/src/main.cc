// Copyright 2010 Thiago Ferreira de Noronha
// Lista de exercicio sobre estruturas de dados homogenias - Vetores.
//
// QUESTÃO 1:
// Implemente em vetores.cc as funções descritas em vetores.h.
//
// QUESTÃO 2:
// Escreva um programa em C++ que le uma sequencia de numeros de um arquivo
// e armazena em um vetor. Assuma que a quantidade de numeros no arquivo
// nao ultrapassa o limite maximo de elementos do vetor (e.g. 1000).

#include <fstream>

#include "easytesting/vetores/src/vetores.h"

// Lê uma sequencia de números de um arquivo
// e armazena em um vetor. Assuma que a quantidade de números no arquivo
// não ultrapassa o limite máximo de elementos do vetor (e.g. 1000).

int main() {
  std::ifstream input;
  float numero_arq;
  int v[1000];
  input.open("numeros.txt");
  for (int i = 0 ; input >> numero_arq ; i++) {
    v[i] = numero_arq;
  }
  input.close();
  return 0;
}
