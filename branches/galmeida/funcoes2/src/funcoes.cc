// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "funcoes2/src/funcoes.h"

#include <math.h>

float DestinoDisparo(float xi, float a, float v) {
  return xi + v * v * sin(2 * M_PI * a /  180.0) / 10.0;
}

bool PertenceIntervalo(float x, float a, float b) {
  return ( x >= a && x <= b ) || fabs(a - x) <= 0.002 || fabs(b - x) <= 0.002;
}


