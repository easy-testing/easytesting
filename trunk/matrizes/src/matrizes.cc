// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/matrizes.h"

#include <iostream>

using std::cout;
using std::endl;

float MediaMatriz(int n, float a[][MAX]) {
  float soma = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      soma = soma + a[i][j];
    }
  }
  return soma /(n*n);
}

void Identidade(int n, float a[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i][i] = 1;
  }
}

void Transposta(int n, float a[][MAX], float T[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      T[i][j] = a[j][i];
    }
  }
}

bool Simetrica(int n, float a[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != a[j][i]) {
        return false;
      }
    }
  }
  return true;
}

void SomaMatriz(int n, float a[][MAX], float b[][MAX], float s[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      s[i][j] = a[i][j] + b[i][j];
    }
  }
}

void MultMatriz(int n, float a[][MAX], float b[][MAX], float p[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p[i][j]=0.0;
      for (int k = 0; k < n; k++) {
        p[i][j] = p[i][j] + a[i][k]*b[k][j];
      }
    }
  }
}

void MostraMatriz(int n, int m, float a[][MAX]) {
  for (int i = 0 ; i < n ; i++) {
    cout << "| ";
    for (int j = 0 ; j < m ; j++) {
      cout << a[i][j] << " ";
    }
    cout << "| " << endl;
  }
}
