// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "funcoes3/src/funcoes.h"

#include <math.h>

float area_trapezio(float B, float b, float h) {
  return (B+b)*h/2.;
}

float maior(float a, float b, float c) {
  float maior = a > b ? a : b;
  return maior > c?maior:c;
}

bool formam_triangulo(float a, float b, float c) {
  float max = maior(a, b, c);
  return 2*max < a+b+c;
}

float area_triangulo(float a, float b, float c) {
  float p=(a+b+c)/2.;
  return sqrt( p*(p-a)*(p-b)*(p-c) );
}


float graus_radianos(float g) {
  return g*M_PI/180.;
}

float grauminutosegundo_grau(float g, float m, float s) {
  return g+m/60.+ s/3600.;
}

float soma_progressao(int n) {
    return n*(n+1)/2;
}

float xy_maximo(float a, float b, float c) {
  return -b/(2.*a);
}

float y_maximo(float a, float b, float c) {
  return (4*a*c-b*b)/(4*a);
}

float distancia_pontos(float x1, float y1, float x2, float y2) {
  return sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)   );
}
