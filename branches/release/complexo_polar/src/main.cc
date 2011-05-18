// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
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
// (ii) A constante M_PI, definida em math.h, armazena o valor de pi com
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
// (vi) O simétrico de z = p|t é dado por p|t+2pi.
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

#include <math.h>
#include <iostream>
#include "complexo_polar/src/complexo.h"

using namespace std;

// Le os coeficientes de uma equacao de segundo grau do teclado e
// imprime na tela as raízes da equacao.
int main() {
  return 0;  // TODO.
}
