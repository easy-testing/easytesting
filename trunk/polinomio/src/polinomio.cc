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
  coeficientes = NULL; // TODO.
}

int Polinomio::grau() {
  return n - 1;
}

float& Polinomio::at(int i) {
  return coeficientes[i];
}

float Polinomio::Avaliar(float x) {
  return -1;  // TODO.
}

void Polinomio::Atribuir(Polinomio& q) {
  // TODO.
}

void Polinomio::Derivar(Polinomio& q) {
  // TODO.
}

void Polinomio::Integrar(Polinomio& q) {
  // TODO.
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
