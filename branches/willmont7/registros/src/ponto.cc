// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "registros/src/ponto.h"

#include <math.h>

float Distancia(Ponto p1, Ponto p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

