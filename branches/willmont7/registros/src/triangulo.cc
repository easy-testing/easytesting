// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "registros/src/triangulo.h"

#include <math.h>

#include "registros/src/ponto.h"

float Perimetro(Triangulo t) {
  return Distancia(t.p1, t.p2) + Distancia(t.p2, t.p3) + Distancia(t.p3, t.p1);
}

// Calcula a área em função do semi-perímetro s.
// Área = sqrt(s * (s - a) * (s - b) * (s - c)).
float Area(Triangulo t) {
  float a = Distancia(t.p1, t.p2);
  float b = Distancia(t.p2, t.p3);
  float c = Distancia(t.p3, t.p1);
  float s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool Equilatero(Triangulo t) {
  return Distancia(t.p1, t.p2) == Distancia(t.p2, t.p3) &&
         Distancia(t.p2, t.p3) == Distancia(t.p3, t.p1);
}

float Maior(float a, float b) {
  return a > b ? a : b;
}

float Menor(float a, float b) {
  return a < b ? a : b;
}

// Dois triângulos são semelhantes s.s.s. a razão entre o maior e o menor
// lado de cada triângulo é igual.
bool Semelhante(Triangulo t1, Triangulo t2) {
    // Armazenam o comprimento os lados do triângulo t1.
    float a1 = Distancia(t1.p1, t1.p2);
    float b1 = Distancia(t1.p2, t1.p3);
    float c1 = Distancia(t1.p3, t1.p1);

    // Armazenam o comprimento dos lados do triângulo t2.
    float a2 = Distancia(t2.p1, t2.p2);
    float b2 = Distancia(t2.p2, t2.p3);
    float c2 = Distancia(t2.p3, t2.p1);

    // Seleciona o maior lado de cada triângulo.
    float maiorLado = Maior(Maior(a1, b1),  c1);
    float MaiorLadoDeT = Maior(Maior(a2, b2), c2);

    // Seleciona o menor lado de cada triângulo.
    float menorLado = Menor(Menor(a1, b1),  c1);
    float MenorLadoDeT = Menor(Menor(a2, b2), c2);

    return maiorLado/MaiorLadoDeT == menorLado/MenorLadoDeT;
}
