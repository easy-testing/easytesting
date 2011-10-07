// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "funcoes/src/funcoes.h"

#include <math.h>

float Media(float a, float b, float c) {
  return (a + b + c) / 3.0;
}

float MediaPonderada(float a, float b, float c) {
  return (3 * a + 4 * b + 5 * c) / 12.0;
}

float Perimetro(float r) {
  return 2 * M_PI * r;
}

float AreaCirculo(float r) {
  return M_PI * r * r;
}

float AreaTriangulo(float b, float c) {
  return b * c / 2.0;
}

float AreaCaixa(float a, float b, float c) {
  return 2 * (a * b + a * c + b * c);
}

float VolumeCaixa(float a, float b, float c) {
  return a * b * c;
}

float AreaCilindro(float r, float h) {
  return Perimetro(r) * h + 2 * AreaCirculo(r);
}

float VolumeCilindro(float r, float h) {
  return AreaCirculo(r) * h;
}

float Hipotenusa(float b, float c) {
  return sqrt( b * b + c * c);
}

float RaizPositiva(float a, float b, float c) {
  float delta = b*b - 4*a*c;
  return ((- b) + sqrt(delta)) / 2 * a;
}
