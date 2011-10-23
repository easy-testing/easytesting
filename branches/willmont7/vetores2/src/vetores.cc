// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "vetores2/src/vetores.h"

#include <iostream>
#include <cmath>

using namespace std;


float Modulo(int v[], int n) {
    int q = 0;
    for (int i = 0;i < n;i++) {
        q += v[i]*v[i];
    }
    return sqrt(q);
}

float ProdutoEscalar(int u[], int v[], int n) {
  float pe = 0;
  for (int i = 0 ; i < n ; i++) {
    pe += u[i] * v[i];
  }
  return pe;
}

float Cosseno_Vetores(int v[], int u[], int n) {
  return ProdutoEscalar(v, u, n)/(Modulo(v, n)*Modulo(u, n));
}
