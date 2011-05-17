// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Polares.
//
// QUESTÃO 1:
// Implemente em complexo.cc as funções descritas em complexo.h.
// Você pode querer usar a função atan2 da biblioteca math.h.
// Note que os ângulos neste biblioteca são medidos em radianos
// e não em graus.
//
// QUESTÃO 2:
// Copie e cole os programas que você escreveu para as lista de exercício sobre
// "Números Complexos - Coordenadas Euclidianas" e observe que este programas
// são executados sem nenhuma alteração.

#include <math.h>
#include <iostream>
#include "complexo_polar/src/complexo.h"

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
