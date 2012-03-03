// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "polinomio/src/polinomio.h"

#include <cmath>
#include <iostream>

using namespace std;

bool nulo(int g, float v[]) {
  return g < 0;
}

float Avaliar(int g, float v[], float x) {
  float soma = 0;
  for (int i = 0; i <= g; i++) {
    soma += v[i] * pow(x, i);
  }
  return soma;
}

void Atribuir(int g, float v[], float u[]) {
  for (int i = 0; i <= g; i++) {
    u[i] = v[i];
  }
}

void Derivar(int g, float v[], float u[]) {
  for (int i = 0; i <= g - 1; i++) {
    u[i] = v[i + 1] * (i + 1);
  }
}

void Integrar(int g, float v[], float u[]) {
  u[0] = 0.0;
  for (int i = 1; i <= g + 1; i++) {
    u[i] = v[i - 1] / i;
  }
}

void ImprimirPrimeiro(float x, int i) {
  if (i == 0) {
    cout << x;
  } else if (x == 1) {
    cout << "";
  } else if (x == -1) {
    cout << "-";
  } else {
    cout << x;
  }
}

void ImprimirOutros(float x) {
  if (x == 1) {
    cout << " + ";
  } else if (x == -1) {
    cout << " - ";
  } else if (x > 0) {
    cout << " + " << x;
  } else if (x < 0) {
    cout << " - " << -x;
  }
}

void Imprimir(int g, float v[]) {
  bool primeiro = true;
  for (int i = 0; i <= g; i++) {
    if (v[i] != 0.0) {
      if (primeiro) {
        ImprimirPrimeiro(v[i], i);
        primeiro = false;
      } else {
        ImprimirOutros(v[i]);
      }
      if (i == 1) {
        cout << "x";
      } else if (i > 1) {
        cout << "x^" << i;
      }
    }
  }
  cout << endl;
}
