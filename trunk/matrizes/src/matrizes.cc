// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "matrizes.h"

#include <iostream>

using namespace std;

/* Compara dois tipos float | true->iguais | falso->diferentes */
bool cmpfloat(float a, float b){
  if (a - b > 0.000001 || a - b < -0.000001)
    return false;
  return true;
}

float MediaMatriz(int n, float mat[][MAX]) {
  float ret = 0.;
  for(int i = 0;i < n;++i)
    for(int j = 0;j < n;++j)
      ret += mat[i][j];

  ret /= (double)n*n;

  return ret/n*n;
}

void Identidade(int n, float A[][MAX]) {
  for(int i = 0;i < n;++i){
    for(int j = 0;j < n;++j)
      A[i][j] = 0;
    A[i][i] = 1;
  }
}

void Transposta(int n, float A[][MAX], float T[][MAX]) {
  for(int i = 0;i < n;++i)
    for(int j = 0;j < n;++j)
      T[j][i] = A[i][j];
}

bool Simetrica(int n, float A[][MAX]) {
  for(int i = 0;i < n;++i)
    for(int j = i+1;j < n;++j)
      if(!cmpfloat(A[i][j], A[j][i]))
        return false;
  return true;
}

void SomaMatriz(int n, float A[][MAX], float B[][MAX], float S[][MAX]) {
  for(int i = 0;i < n;++i)
    for(int j = 0;j < n;++j)
      S[i][j] = A[i][j] + B[i][j];
}

void MultMatriz(int n, float A[][MAX], float B[][MAX], float P[][MAX]) {
  float t;
  for(int i = 0;i < n;++i)
    for(int j = 0;j < n;++j){
      t = 0.;
      for(int k = 0;k < n;++k){
        t += A[i][k]*B[k][j];
      }
      P[i][j] = t;
    }
}

void MostraMatriz(int n, int m, float a[][MAX]) {
  for(int i = 0;i < n;++i){
    cout << "| ";
    for(int j = 0;j < m;++j)
      cout << a[i][j] << " ";
    cout << "|\n";
  }
}

//////////////////////////////////////////
//         EXERCICIOS ADICIONAIS        //
//////////////////////////////////////////

void EscalarMatriz(int n, int m, int escalar, float A[][MAX], float Out[][MAX]){
  for(int i = 0;i < n;++i)
    for(int j = 0;j < m;++j)
      Out[i][j] = A[i][j] * escalar;
}

float DeterminanteMatriz(float A[][MAX]){
  float pos, neg;
  float det = 0;
  for(int i = 0;i < 3;++i){
    pos = neg = 1;
    for(int j = 0;j < 3;++j){
      pos *= A[ j ] [ (i+j)%3 ];      // Multiplica os elementos da parte positiva do det.
      neg *= A[ j ] [ 2 - (i+j)%3 ];  // Multiplica os elementos da parte negativa do det.
    }
    det += pos - neg;
  }
  return det;
}

bool VerificaTriangularInferior(int n, float A[][MAX]){
  for(int i = 0;i < n;++i)
    for(int j = i+1;j < n;++j)
      if(!cmpfloat(A[i][j], 0.)) // Verifica se algum elemento da parte diagonal superior nao eh nula
        return false;
  return true;
}

bool VerificaTriangularSuperior(int n, float A[][MAX]){
  for(int i = 0;i < n;++i)
    for(int j = 0;j < i;++j)
      if(!cmpfloat(A[i][j], 0)) // Verifica se algum elemento da parte diagonal inferior nao eh nula
        return false;
      return true;
}