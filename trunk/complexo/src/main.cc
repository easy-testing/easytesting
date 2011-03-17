// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include <math.h>
#include <iostream>
#include "easytesting/complexo/src/complexo.h"

using namespace std;

void CalcularRaizes(float a, float b, float c, Complexo* r1, Complexo* r2) {
  float delta = b * b - 4 * a * c;
  if (delta >= 0.0) {
    r1->Atribuir((-b + sqrt(delta)) / 2 * a, 0.0);
    r2->Atribuir((-b - sqrt(delta)) / 2 * a, 0.0);
  } else {
    r1->Atribuir(-b / 2 * a,   sqrt(-delta) / 2 * a);
    r2->Atribuir(-b / 2 * a, - sqrt(-delta) / 2 * a);
  }
}

// Le os coeficientes de uma equacao de segundo grau do teclado e
// imprime na tela as raizes da equacao.
int main() {
    cout << "Digite os coeficientes da equacao de segundo grau"
    cout << " f(x) = a.x^2 + b.x + c" << endl;
    float a, b, c;
    cin >> a >> b >> c;
    Complexo raiz1, raiz2;
    CalcularRaizes(a, b, c, &raiz1, &raiz2);
    cout << "x'  = " << raiz1.real() << " + " << raiz1.imag() << "i\n";
    cout << "x'' = " << raiz2.real() << " + " << raiz2.imag() << "i\n";
    return 0;
}
