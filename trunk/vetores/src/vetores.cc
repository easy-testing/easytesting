// Lista de exercicio sobre estruturas de dados homogenias - Vetores.

#include "vetores.h"

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
