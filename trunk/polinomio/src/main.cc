// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Tipos Abstratos de Dados - TAD: Polinômios.
//
// Introdução: Um polinômio de grau n é uma função do tipo
// P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n, onde a0, a1, a2, ... , an pertencem
// ao conjunto dos números reais. Qualquer polinômio de grau n pode ser
// representado em um programa de computador por um vetor p com n + 1 posições,
// onde cada posição p[i] do vetor armazena o valor do coeficiente
// ai, i = {0, ... , n}. Por exemplo: o polinômio de grau 4
// Q(x) = 5 + 3*x^2 + 2*x^4 = 5x^0 + 0*x^1 + 3*x^2 + 0*x^3 + 2*x^4,
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
// Implemente em polinomio.h e polinomio.cc um TAD Polinomio.
//
// Questão 2.
// Escreva um programa que lê um polinômio P(x) de um arquivo e indefinidamente
// lê um número x do teclado e exibe na tela o valor de P(x).
//
// Questão 3.
// Escreva um programa que lê de um arquivo um polinômio P(x) e um intervalo
// [a, b] e exibe a área da figura definida por P(x) no intervalo[a, b].

#include <fstream>
#include <iostream>

#include "polinomio/src/polinomio.h"

using namespace std;

int main() {

  int* v = new int[5];
  int p[6];

  printf("%d\n", sizeof(v));

  return 0;

  Polinomio f(4);
  Polinomio g;
  
  f.at(0) = 6;
  f.at(1) = 5;
  f.at(2) = 1;
  f.at(3) = 3;
  f.at(4) = 2;
  
  
  
  /*
  float* p;
  
  p = &(g.at(0));
  
  printf("%p\n", p);
  g.Atribuir(f);
  printf("%p\n", &(g.at(0)));
  */
  
  g.Integrar(f);  
  for(int i = 0;i < g.grau()+1;i++)
    printf("%lf\n", g.at(i));
  printf("\n");

  return 0;
}
