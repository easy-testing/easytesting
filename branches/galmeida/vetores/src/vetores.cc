// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "vetores/src/vetores.h"
#include <cmath>
#include <iostream>

using namespace std;

float Media(float v[], int n) {
  float soma = 0;
  for (int i = 0 ; i < n ; i++) {
    soma += v[i];
  }
  return soma / n;
}

float Variancia(float v[], int n) {
  float m = Media(v, n);
  float soma = 0;
  for (int i = 0 ; i < n ; i++) {
    soma += (v[i] - m) * (v[i] - m);
  }
  return soma / n;
}

float Maior(float v[], int n) {
  float maior = v[0];
  for (int i = 1 ; i < n ; i++) {
    if (v[i] > maior) {
      maior = v[i];
    }
  }
  return maior;
}

float Menor(float v[], int n) {
  float menor = v[0];
  for (int i = 1 ; i < n ; i++) {
    if (v[i] < menor) {
      menor = v[i];
    }
  }
  return menor;
}

float Modulo(float v[], int n) {
  int q = 0;
  for (int i = 0; i < n; i++) {
    q += v[i] * v[i];
  }
  return sqrt(q);
}

float ProdutoEscalar(float u[], float v[], int n) {
  float pe = 0;
  for (int i = 0 ; i < n ; i++) {
    pe += u[i] * v[i];
  }
  return pe;
}

float CossenoVetores(float v[], float u[], int n) {
  return ProdutoEscalar(v, u, n) / (Modulo(v, n) * Modulo(u, n));
}

void MostraVetor(float v[], int n) {
  cout << "{";
  for (int i = 0 ; i < n; i++) {
    cout << v[i];
    if (i < n - 1) {
      cout << ", ";
    }
  }
  cout << "}";
}
