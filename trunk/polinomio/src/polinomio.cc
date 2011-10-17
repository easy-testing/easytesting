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
}

int Polinomio::grau() {
  return n - 1;
}

float& Polinomio::at(int i) {
  return coeficientes[i];
}

float Polinomio::Avaliar(float x) {
  float soma = 0;
  for (int i = 0;i < n;i++)
    soma += coeficientes[i]*pow(x, i);
  return soma;
}

void Polinomio::Atribuir(Polinomio& q) {
  Realocar(q.n);
  n = q.n;
  for (int i = 0;i < n;i++)
    coeficientes[i] = q.coeficientes[i];
}

void Polinomio::Derivar(Polinomio& q) {
  // Derivada de constante.
  if (q.n == 1) {
    Realocar(1);
    n = 1;
    at(0) = 0;
    return;
  }

  Realocar(q.n-1);
  n = q.n-1;

  for (int i = 0;i < n;i++)
    coeficientes[i] = q.at(i+1)*(i+1);
}

void Polinomio::Integrar(Polinomio& q) {
  // Integral de 0.
  if (q.n == 1 && q.at(0) == 0) {
    Realocar(1);
    n = 1;
    at(0) = 0;
    return;
  }

  Realocar(q.n+1);
  n = q.n+1;

  coeficientes[0] = 0.;
  for (int i = 1;i < n;i++)
    coeficientes[i] = q.at(i-1)/(i);
}

Polinomio::~Polinomio() {
  delete [] coeficientes;
}

void Polinomio::Realocar(int m) {
  if (m <= n)
    return;

  float* temp = new float[m];
  for (int i = 0;i < n;i++)
    temp[i] = coeficientes[i];
  delete[] coeficientes;
  coeficientes = temp;

  return;
}
