// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "polinomio/src/polinomio.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Polinomio::Polinomio() {
  n = 1;
  coeficientes = new float[1];
  coeficientes[0] = 0;
}

Polinomio::Polinomio(int g) {
  n = g + 1;
  coeficientes = new float[n];
  for (int i = 0; i < n - 1; i++) {
    coeficientes[i] = 0;
  }
  coeficientes[n - 1] = 1;
}

int Polinomio::grau() {
  return n - 1;
}

float& Polinomio::at(int i) {
  return coeficientes[i];
}

float Polinomio::Avaliar(float x) {
  float soma = 0;
  for (int i = 0; i < n; i++) {
    soma += coeficientes[i] * pow(x, i);
  }
  return soma;
}

void Polinomio::Atribuir(Polinomio& q) {
  Realocar(q.n);
  n = q.n;
  for (int i = 0; i < n; i++) {
    coeficientes[i] = q.coeficientes[i];
  }
}

void Polinomio::Derivar(Polinomio& q) {
  Realocar(q.n - 1);
  n = q.n - 1;
  for (int i = 0; i < n; i++) {
  }
}

void Polinomio::Integrar(Polinomio& q) {
  Realocar(q.n + 1);
  n = q.n + 1;
  coeficientes[0] = 0.0;
  for (int i = 1; i < n ; i++) {
    coeficientes[i] = q.coeficientes[i - 1] / i;
  }
}

Polinomio::~Polinomio() {
  delete [] coeficientes;
}

void Polinomio::Realocar(int m) {
  float* aux = new float[m];
  int min = n < m ? n : m;
  for (int i = 0; i < min; i++) {
    coeficientes[i] = aux[i];
  }
  delete [] coeficientes;
  coeficientes = aux;
}
