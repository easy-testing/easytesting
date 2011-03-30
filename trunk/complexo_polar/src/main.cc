// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.
//
// QUESTÃO 1:
// Implemente em complexo.cc as funções descritas em complexo.h.
//
// QUESTÃO 2:
// Escreva uma função "void CalcularRaizes(float a, float b, float c,
// Complexo* r1, Complexo* r2)" que recebe os coeficientes
// de uma equação de segundo grau "a.x^2 + b.x + c = 0" e retorna por r1 e r2
// as raízes (possivelmente complexas) desta equação.

// QUESTÃO 3:
// Escreva um programa que lê do teclaso os coeficientes de uma equação de
// segundo grau e imprime na tela as raízes (possivelmente complexas) desta
// equação.

#include <math.h>
#include <iostream>
#include "complexo/src/complexo.h"

using namespace std;

void CalcularRaizes(float a, float b, float c, Complexo* r1, Complexo* r2) {
  float delta = b * b - 4 * a * c;
  if (delta >= 0.0) {
    *r1 = Complexo((-b + sqrt(delta)) / 2 * a, 0.0);
    *r2 = Complexo((-b - sqrt(delta)) / 2 * a, 0.0);
  } else {
    *r1 = Complexo(-b / 2 * a,   sqrt(-delta) / 2 * a);
    *r2 = Complexo(-b / 2 * a, - sqrt(-delta) / 2 * a);
  }
}

// Le os coeficientes de uma equacao de segundo grau do teclado e
// imprime na tela as raízes da equacao.
int main() {
    cout << "Digite os coeficientes da equacao de segundo grau";
    cout << " f(x) = a.x^2 + b.x + c" << endl;
    float a, b, c;
    cin >> a >> b >> c;
    Complexo raiz1, raiz2;
    CalcularRaizes(a, b, c, &raiz1, &raiz2);
    cout << "x'  = " << raiz1.real() << " + " << raiz1.imag() << "i\n";
    cout << "x'' = " << raiz2.real() << " + " << raiz2.imag() << "i\n";
    return 0;
}
