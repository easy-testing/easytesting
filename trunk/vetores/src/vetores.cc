// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "vetores/src/vetores.h"
#include <iostream>

using namespace std;

float Media(float v[], int n) {
  float ret = 0.;
  for(int i = 0;i < n;i++)
    ret += v[i];
  ret /= (float)n;
  return ret;
}

float Variancia(float v[], int n) {
  float ret = 0.;
  float media;
  for(int i = 0;i < n;i++)
    ret += v[i]*v[i];
  ret /= (float)n;
  media = Media(v, n);
  media *= media;
  ret -= media;
  return ret;
}

float Maior(float v[], int n) {
  int higher = 0;
  for(int i = 1;i < n;i++)
    if(v[i] > v[higher])
      higher = i;
  return v[higher];
}

float Menor(float v[], int n) {
  int lower = 0;
  for(int i = 1;i < n;i++)
    if(v[i] < v[lower])
      lower = i;
    return v[lower];
}

float ProdutoEscalar(float u[], float v[], int n) {
  float ret = 0.;
  for(int i = 0;i < n;i++)
    ret += v[i]*u[i];
  return ret;
}

void MostraVetor(float v[], int n) {
  if(n < 1)
    return;
  cout << "{" << v[0];
  for(int i = 1;i < n;i++)
    cout << ", " << v[i];
  cout << "}" << endl;
}
