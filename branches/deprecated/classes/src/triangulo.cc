// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "classes/src/triangulo.h"

#include <math.h>

#include "classes/src/ponto.h"

Triangulo::Triangulo(Ponto p1, Ponto p2, Ponto p3) {
  v[0] = p1;
  v[1] = p2;
  v[3] = p3;
}

Ponto Triangulo::primeiro() {
  return v[0];
}

Ponto Triangulo::segundo() {
  return v[1];
}

Ponto Triangulo::terceiro() {
  return v[2];
}

void Triangulo::operator=(Triangulo t) {
  v[0] = t.v[0];
  v[1] = t.v[1];
  v[2] = t.v[2];
}

float Triangulo::perimetro() {
  return v[0].distancia(v[1]) +
         v[1].distancia(v[2]) +
         v[2].distancia(v[0]);
}

// Calcula a área em função do semi-perímetro s.
// Área = sqrt(s * (s - a) * (s - b) * (s - c)).
float Triangulo::area() {
  float a = v[0].distancia(v[1]);
  float b = v[1].distancia(v[2]);
  float c = v[2].distancia(v[0]);
  float s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool Triangulo::equilatero() {
  return v[0].distancia(v[1]) == v[1].distancia(v[2]) &&
         v[1].distancia(v[2]) == v[2].distancia(v[0]);
}

float maior(float a, float b) {
  return a > b ? a : b;
}

float menor(float a, float b) {
  return a < b ? a : b;
}

// Dois triângulos são semelhantes s.s.s. a razão entre o maior e o menor
// lado de cada triângulo é igual.
bool Triangulo::semelhante(Triangulo t) {
    // Armazenam o comprimento os lados do triângulo t1.
    float a1 = v[0].distancia(t.v[1]);
    float b1 = v[1].distancia(t.v[2]);
    float c1 = v[2].distancia(t.v[0]);

    // Armazenam o comprimento dos lados do triângulo t2.
    float a2 = v[0].distancia(t.v[1]);
    float b2 = v[1].distancia(t.v[2]);
    float c2 = v[2].distancia(t.v[0]);

    // Seleciona o maior lado de cada triângulo.
    float maiorLado = maior(maior(a1, b1),  c1);
    float maiorLadoDeT = maior(maior(a2, b2), c2);

    // Seleciona o menor lado de cada triângulo.
    float menorLado = menor(menor(a1, b1),  c1);
    float menorLadoDeT = menor(menor(a2, b2), c2);

    return maiorLado/maiorLadoDeT == menorLado/menorLadoDeT;
}
