// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Polares.
//
// QUESTÃO 1:
// Implemente em complexo.cc as funções descritas em complexo.h.
//
// (i) Você vai precisar usar as funções math.h. Note que os ângulos passados
// como parâmetro para as funções desta biblioteca são medidos em radianos
// e não em graus.
//
// (ii) A constante M_PI, definida em <cmath>, armazena o valor de pi com
// 21 casas decimais.
//
// (iii) A função atan2(x, y) retorna o valor do arco tangente de x/y.
//
// (iv) O número complexo z = a + bi em representação euclidiana é representado
// na forma polar por z = p(cos t + i*sin t), onde p = é o módulo
// (p = sqrt(a*a + b*b)) e t é o argumento do número complexo (t = atan2(b, a)).
// Usaremos a seguir notação z = p|t para nos referirmos ao número complexo
// z = p(cos t + i*sin t).
//
// (v) O conjugado de z = p|t é dado por p|-t.
//
// (vi) O simétrico de z = p|t é dado por p|t+pi.
//
// (vii) O inverso de z = p|t é dado por 1/p|-t.
//
// (viii) Não existe uma forma trivial de somar dois números complexos em suas
// formas polares. Sendo assim, esta operação é realizada convertendo os
// números para a forma retangular (euclidiana) e em seguida convertendo o
// resultado da soma para a forma polar.
//
// (ix) Você pode implementar a subtração de números complexos utilizando as
// operações de soma e simétrico.
//
// (x) A multiplicação de z = p|t por y = q|s resulta em p*q|t+s.
//
// (ix) A divisão de z = p|t por y = q|s resulta em p/q|t-s.
//
// QUESTÃO 2:
// Copie e cole os programas que você escreveu para as lista de exercício sobre
// "Números Complexos - Coordenadas Euclidianas" e observe que este programas
// são executados sem nenhuma alteração.

#include <cmath>
#include <iostream>

#include "src/complexo.h"

using std::cin;
using std::cout;
using std::endl;

// Recebe o valor dos coeficientes a, b, c (a.x^2 + b.x + c) e retorna através
// de r1 e r2 raízes (possivelmente complexas) desta equação.
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

// Lê os coeficientes de uma equação de segundo grau do teclado e
// imprime na tela as raízes da equação.
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
