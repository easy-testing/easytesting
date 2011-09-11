// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "funcoes/src/funcoes.h"

#include <math.h>


float Destino_disparo(float xi, float a, float v) {
     return xi+v*v*sin(2*M_PI*a/180.)/10.0;
}

bool Pertence_intervalo(float x, float a, float b) {
     return ( x >= a && x <= b ) || fabs(a-x) <= 0.1 || fabs(b-x) <= 0.1;
}


