// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre vetores - polinômios.
//
// Introdução: Um polinômio de grau n é uma função do tipo
// P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n, onde a0, a1, a2, ... , an pertencem
// ao conjunto dos números reais. Qualquer polinômio de grau n pode ser
// representado em um programa de computador por um vetor v com n + 1 posições,
// onde cada posição v[i] do vetor armazena o valor do coeficiente
// v[i], i = {0, ... , n}. Por exemplo: o polinômio de grau 4
// Q(x) = 5 + 3*x^2 + 2*x^4 = 5*x^0 + 0*x^1 + 3*x^2 + 0*x^3 + 2*x^4,
// pode ser representado pelo vetor "float q[5] = {5, 0, 3, 0, 2};"
//
// A derivada de um polinômio P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
// de grau n > 1, é um polinômio de grau n - 1 e pode ser calculada da
// seguinte forma: P'(x) = 1*a1 + 2*a2*x +3*a3*x^2 + ... + n*an*x^(n-1).
// Por exemplo: Q'(x) = 2*3*x^(2-1) + 4*2*x^(4-1) = 6x + 8x^3.
//
// A integral de um polinômio P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
// de grau n, é um polinômio de grau n + 1 e pode ser calculada da seguinte
// forma: integral[P(x)] = C + (a0)/1*x + (a1)/2*x^2 + (a2)/3*x^3 + ...
// + (an)/(n + 1)*x^(n + 1). Assuma que a constante C é igual a 0.
// Por exemplo: integral[Q(x)] = 5*x + 3/3*x^3 + 2/5*x^5 = 5*x + x^3 + 0.4*x^5.
//
// Questão 1.
// Implemente em polinomio.cc as funções de polinomio.h.
//
// Questão 2.
// Escreva um programa que lê um polinômio P(x) de um arquivo e indefinidamente
// lê um número x do teclado e exibe na tela o valor de P(x). Você pode assumir
// que o grau máximo do polinômio é 99.
//
// Questão 3.
// Escreva um programa que lê de um arquivo um polinômio P(x) e um intervalo
// [a, b] e exibe a área da figura definida por P(x) no intervalo[a, b].
// Você pode assumir que o grau máximo do polinômio é 99.

#include <fstream>
#include <iostream>

#include "polinomio/src/polinomio.h"

#define MAX 100

using namespace std;

// Gabarito da Questão 2.
int main_questao_2() {
  ifstream fin("input1.txt");
  int g;
  fin >> g;
  float v[MAX];
  for (int i = 0; i <= g; i++) {
    fin >> v[i];
  }
  Imprimir(g, v);
  while (true) {
    cout << "Digite o valor de x: ";
    float x;
    cin >> x;
    cout << "P(" << x << ") = " << Avaliar(g, v, x) << endl;
  }
  return 0;
}

// Gabarito da Questão 3.
float AreaPolinomio(int g, float v[], float a, float b) {
  float u[MAX];
  Integrar(g, v, u);
  Imprimir(g + 1, u);
  return Avaliar(g + 1, u, b) - Avaliar(g + 1, u, a);
}

int main_questao_3() {
  ifstream fin("input2.txt");
  int g;
  fin >> g;
  float v[MAX];
  for (int i = 0; i <= g; i++) {
    fin >> v[i];
  }
  float a;
  fin >> a;
  float b;
  fin >> b;
  cout << "Area = " << AreaPolinomio(g, v, a, b) << endl;
  return 0;
}

/* Escolhe qual das questões executar.
**************************************/

int main() {
  //return main_questao_2();
  return main_questao_3();
}
