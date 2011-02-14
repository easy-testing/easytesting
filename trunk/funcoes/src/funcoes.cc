// Copyright 2010 Matheus Pacheco
#include<math.h>
#include "easytesting/funcoes/src/funcoes.h"

#define PI 3.1415

float media(float a, float b, float c) {
  return (a + b + c) / 3.0;
}

float media_ponderada(float a, float b, float c) {
  return (3 * a + 4 * b + 5 * c) / 12.0;
}

float perimetro(float r) {
  return 2 * PI * r;
}

float area_circulo(float r) {
  return PI * r * r;
}

float area_triangulo(float b, float c) {
  return b * c / 2.0;
}

float area_caixa(float a, float b, float c) {
  return 2 * (a * b + a * c + b * c);
}

float volume_caixa(float a, float b, float c) {
  return a * b * c;
}

float area_cilindro(float r, float h) {
  return perimetro(r) * h + 2 * area_circulo(r);
}

float volume_cilindro(float r, float h) {
  return area_circulo(r) * h;
}

float hipotenusa(float b, float c) {
  return sqrt( b * b + c * c);
}

float raiz_positiva(float a, float b, float c) {
  float delta = b*b - 4*a*c;
  return ((- b) + sqrt(delta)) / 2 * a;
}
