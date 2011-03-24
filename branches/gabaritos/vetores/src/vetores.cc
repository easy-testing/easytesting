// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "vetores/src/vetores.h"
#include <iostream>

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

float ProdutoEscalar(float u[], float v[], int n) {
  float pe = 0;
  for (int i = 0 ; i < n ; i++) {
    pe += u[i] * v[i];
  }
  return pe;
}

void MostraVetor(float v[], int n) {
  std::cout << "{";
  for (int i = 0 ; i < n-1 ; i++) {
    std::cout << v[i] << ", ";
  }
  if (n > 0) {
    std::cout << v[n-1] << "}";
  } else {
    std::cout << " }";
  }
}
