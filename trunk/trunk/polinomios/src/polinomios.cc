#include "easytesting/polinomios/src/polinomios.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

Polinomio::Polinomio() {
  n = 1;
  a[0] = 0.0;
}

Polinomio::Polinomio(int m, float* q) {
  n = m;
  for (int i = 0; i <= m; i++) {
    a[i] = q[i];
  }
}

int Polinomio::grau() {
  return n - 1;
}

float Polinomio::get(int i) {
  return a[i];
}

void Polinomio::set(int i, float b) {
  a[i] = b;
}

float Polinomio::Avaliar(float x) {
  float soma = 0;
  for (int i = 0; i < n; i++) {
    soma += a[i] * pow(x, i);
  }
  return soma;
}

void Polinomio::Atribuir(Polinomio& q) {
  n = q.grau() + 1;
  for (int i = 0; i < n; i++) {
    a[i] = q.a[i];
  }
}

void Polinomio::Somar(Polinomio& p1, Polinomio &p2) {
  n = p1.grau() + 1;
  for (int i = 0; i < n; i++) {
    a[i] = p1.get(i) + p2.get(i);
  }
}

void Polinomio::Derivar(Polinomio& q) {
  n = q.grau();
  for (int i = 0; i < n; i++) {
    a[i] = q.get(i + 1) * (i + 1);
  }
}

void Polinomio::Integrar(Polinomio& q) {
  n = q.grau() + 2;
  a[0] = 0.0;
  for (int i = 0; i < n; i++) {
    a[i + 1] = q.get(i) / (i + 1);
  }
}
