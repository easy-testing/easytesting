// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "matrizes/src/matrizes.h"

#include <stdio.h>
#include <iostream>

using namespace std;

float MediaMatriz(int n, float mat[][MAX]) {
  float soma = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      soma = soma + mat[i][j];
    }
  }
  return soma /(n*n);
}

void Identidade(int n, float A[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    A[i][i] = 1;
  }
}

void Transposta(int n, float A[][MAX], float T[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      T[i][j] = A[j][i];
    }
  }
}

bool Simetrica(int n, float A[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] != A[j][i]) {
        return false;
      }
    }
  }
  return true;
}

void SomaMatriz(int n, float A[][MAX], float B[][MAX], float S[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      S[i][j] = A[i][j] + B[i][j];
    }
  }
}

void MultMatriz(int n, float A[][MAX], float B[][MAX], float P[][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      P[i][j]=0.0;
      for (int k = 0; k < n; k++) {
        P[i][j] = P[i][j] + A[i][k]*B[k][j];
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
