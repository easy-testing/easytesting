// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados homogêneas - Vetores.
//
// QUESTÃO 1:
// Implemente em vetores.cc as funções descritas em vetores.h.
//
// QUESTÃO 2:
// Escreva um programa em C++ que lê um conjunto de números de um arquivo e
// imprime na tela a média e o desvio padrão destes números.

#include <cmath>
#include <fstream>
#include <iostream>

#include "src/vetores.h"

using std::cout;
using std::endl;
using std::ifstream;

// Lê uma sequência de números de um arquivo, armazena em um vetor e os imprime
// na tela.
int main() {
  float x;
  int n = 0;
  float v[1000];
  ifstream input("input.txt");
  while (input >> x) {
    v[n] = x;
    n++;
  }
  MostraVetor(v, n);
  cout << "\nMedia: " << Media(v, n) << endl;
  cout << "Desvio Padrao: " << sqrt(Variancia(v, n)) << endl;
  return 0;
}
