// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Tipos Abstratos de Dados - TAD: Polinômios.
//
// Introdução: Um polinômio de grau n é uma função do tipo
// P(x) = a0 + a1*x + a2*x2 + ... + an*xn, onde a0, a1, a2, ... , an pertencem
// ao conjunto dos números reais. Qualquer polinômio de grau n pode ser
// representado em um programa de computador por um vetor p com n + 1 posições,
// onde cada posição p[i] do vetor armazena o valor do coeficiente
// ai, i = {0, ... , n}. Por exemplo: o polinômio de grau 4
// Q(x) = 5 + 3x2 + 2x4 = 5x0 + 0x1 + 3x2 + 0x3 + 2x4,
// pode ser representado pelo vetor "float q[5] = {5, 0, 3, 0, 2};"
//
// Questão 1.
// Implemente em polinomio.h e polinomio.cc um TAD Polinomio.
//
// Questão 2.
// Escreva um programa que lê um polinômio P(x) de um arquivo e indefinidamente
// lê um número x do teclado e exibe na tela o valor de P(x).
//
// Questão 3.
// Escreva um programa que lê de um arquivo um polinômio P(x) e um intervalo
// [a, b] e exibe a lista com TODAS as raízes REAIS de P(x) neste intervalo.
// (3a) Implemente uma versão "força bruta" que testa "todos os pontos" com
// precisão 1E-6.
// (3b) Implemente uma versão utilizando o método de Newton.
// (3c) Compare o tempo de execução e a precisão dos dois métodos.
//
// Questão 4.
// Escreva um programa que lê de um arquivo um polinômio P(x) e um intervalo
// [a, b] e exibe os pontos de valor máximo e mínimo de P(x) no intervalo[a, b].
// (4a) Implemente uma versão "força bruta" que testa "todos os pontos" com
// precisão 1E-6.
// (4b) Implemente uma versão utilizando o método de Newton.
// (4c) Compare o tempo de execução e a precisão dos dois métodos.
//
// Questão 5.
// Escreva um programa que lê de um arquivo um polinômio P(x) e um intervalo
// [a, b] e exibe a área da figura definida por P(x) no intervalo[a, b].
// (5a) Implemente uma versão "força bruta" baseada em integração numérica.
// (5b) Implemente uma versão baseada em integração analítica.
// (5c) Compare o tempo de execução e a precisão dos dois métodos.

#include <iostream>
#include <fstream>
#include "polinomio/src/polinomio.h"

using namespace std;

int main() {
  ifstream fin("input.txt");
  int n;
  fin >> n;
  float* v = new float[n + 1];
  for (int i = 0; i <= n; i++) {
    fin >> v[i];
  }
  Polinomio p(n + 1, v);
  delete [] v;

  while (true) {
    cout << "Digite o valor de x: ";
    float x;
    cin >> x;
    cout << "P(" << x << ") = " << p.Avaliar(x) << endl;
  }
  return 0;
}