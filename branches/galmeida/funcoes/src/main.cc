// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre funções em C++.
//
// QUESTÃO 1:
// Implemente em funcoes.cc as funções descritas em funcoes.h.
//
// QUESTÃO 2:
// Escreva um programa que (i) Recebe do teclado a posição
// de um canhao no eixo X em metros. (ii) Recebe do teclado
// um angulo de disparo(sentido anti-horario a partir do solo)
// em graus, minutos e segundos. (iii) Recebe do teclado a
// velocidade inicial da bala em metros por segundo.
// (iv) Imprime na tela a posicao final do projetil no eixo
// X (v) Imprima na tela as coordenadas X e Y da bala no
// momento em que atingiu a altura maxima (vi) Imprima na
// tela a distancia entre o canhao e a bala no momento em que
// ela atinge a altura maxima. Considere a g = 10 m/s2

#include <iostream>
#include <cmath>
#include "funcoes/src/funcoes.h"

using namespace std;

// Calcula a posicao final do disparo.
float DestinoDisparo(float xi, float a, float v) {
  return xi + v * v * sin(2 * a) / 10.0;
}

// Calcula a posicao final do disparo.
float AlturaMaxima(float a, float v) {
  return v * v * sin(a) * sin(a) / (2.0 * 10.0);
}



int main() {
  cout << "Digite a posicao do canhao no eixo X (metros): ";
  float xi;
  cin >> xi;
  cout << "Digite o numero de graus do angulo de disparo: ";
  float g;
  cin >> g;
  cout << "Digite o numero de minutos do angulo de disparo: ";
  float m;
  cin >> m;
  cout << "Digite o numero de segundos do angulo de disparo: ";
  float s;
  cin >> s;
  cout << "Digite a velocidade inicial da bala(m/s): ";
  float v;
  cin >> v;
  float ang_graus = SexagenalDecimal(g, m, s);
  float ang_radianos = GrausRadianos(ang_graus);
  float xf = DestinoDisparo(xi, ang_radianos, v);
  cout << "Posicao final da bala: X = " << xf << " metros.\n";
  float hmax = AlturaMaxima(ang_radianos, v);
  float x_hmax = (xi + xf) / 2.0;
  cout << "Posicao de altura maxima: (" << x_hmax << ", " << hmax << ")\n";
  float d = DistanciaPontos(xi, 0, x_hmax, hmax);
  cout << "Distancia canhao-bala na posicao de altura maxima:" << d << " m.\n";
  return 0;
}


