// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "funcoes3/src/funcoes.h"

#include <math.h>

float AreaTrapezio(float B, float b, float h) {
      return (B + b) * h / 2.;
      }

float Maior(float a, float b, float c) {
  float maior = a > b ? a : b;
  return maior > c ? maior : c;
}

bool FormamTriangulo(float a, float b, float c) {
  float max = Maior(a, b, c);
  return 2 * max < a + b + c;
}

float AreaTriangulo(float a, float b, float c) {
  float p = (a + b + c) / 2.0;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

float GrausRadianos(float g) {
  return g * M_PI / 180.0;
}

float SexagenalDecimal(float g, float m, float s) {
  return g + m / 60.0 + s / 3600.0;
}

float SomaMenoresOuIguais(int n) {
  return n * (n + 1) / 2;
}

float XParaYMaximo(float a, float b, float c) {
  return - b / (2.0 * a);
}

float YMaximo(float a, float b, float c) {
  return (4 * a * c - b * b)/(4 * a);
}

float DistanciaPontos(float x1, float y1, float x2, float y2) {
   return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
