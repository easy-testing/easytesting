// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include <cmath>
#include <iostream>
#include "vetores/src/vetores.h"

using std::cout;
using std::endl;

/* Compara dois tipos float: true->iguais | falso->diferentes. */
bool cmpfloat(float a, float b) {
  if (a - b > 0.000001 || a - b < -0.000001)
    return false;
  return true;
}

float Media(float v[], int n) {
  float ret = 0.;
  for (int i = 0;i < n;++i)
    ret += v[i];
  ret /= static_cast<float>(n);
  return ret;
}

float Variancia(float v[], int n) {
  float ret = 0.;
  float media;
  for (int i = 0;i < n;++i)
    ret += v[i]*v[i];
  ret /= static_cast<float>(n);
  media = Media(v, n);
  media *= media;
  ret -= media;
  return ret;
}

float Maior(float v[], int n) {
  int higher = 0;
  for (int i = 1;i < n;++i)
    if (v[i] > v[higher])
      higher = i;
  return v[higher];
}

float Menor(float v[], int n) {
  int lower = 0;
  for (int i = 1;i < n;++i)
    if (v[i] < v[lower])
      lower = i;
    return v[lower];
}

float ProdutoEscalar(float u[], float v[], int n) {
  float ret = 0.;
  for (int i = 0;i < n;++i)
    ret += v[i]*u[i];
  return ret;
}

void MostraVetor(float v[], int n) {
  if (n < 1)
    return;
  cout << "{" << v[0];
  for (int i = 1;i < n;++i)
    cout << ", " << v[i];
  cout << "}" << endl;
}

//////////////////////////////////////////
//         EXERCICIOS ADICIONAIS        //
//////////////////////////////////////////

float MediaPonderada(float v[], float p[], int n) {
  float ret = 0;
  float div = 0;
  for (int i = 0;i < n;++i) {
    ret += v[i]*p[i];
    div += p[i];
  }
  return ret/div;
}

float MediaHarmonica(float v[], int n) {
  float temp = 0;
  for (int i = 0;i < n;++i) {
    /* Verifica se algum elemento da media eh nulo e retorna */
    /* para nao realizar DIVISAO POR ZERO.                   */
    if (cmpfloat(v[i], 0.))
      return 0;
    temp += 1/v[i];
  }
  return n/temp;
}

float MediaGeometrica(float v[], int n) {
  float temp = 1;
  for (int i = 0;i < n;++i)
    temp *= v[i];
  return pow(temp, 1./n);
}

float MediaQuadratica(float v[], int n) {
  float temp = 0;
  for (int i = 0;i < n;++i)
    temp += v[i]*v[i];
  return sqrt(temp/n);
}

bool VerificaPA(float v[], int n) {
  // P.A. indeterminada.
  if (n < 2)
    return false;
  // Calcula possivel razao.
  float r = v[1]-v[0];
  // Verifica se a progressao satisfaz com o razao.
  for (int i = 1;i < n-1;++i)
    if ( !cmpfloat(v[i+1], r + v[i]) )
      return false;
  return true;
}

bool VerificaPG(float v[], int n) {
  // P.A. indeterminada.
  if (n < 2 || v[0] == 0)
    return false;
  // Calcula possivel razao.
  float r = v[1]/v[0];
  // Verifica se a progressao satisfaz com a razao.
  for (int i = 1;i < n-1;++i)
    // Detalhe: v[i+1]/v[i] == r pode nao funcionar
    // se v[i] = 0.
    if ( !cmpfloat(v[i+1] , r*v[i]) )
      return false;
    return true;
}

// InsertionSort.
void OrdenaVetor(float v[], int n) {
  int i, j;
  float t;
  int min = 0;
  // Pesquisa o menor elemento na posicao correta.
  for (i = 1;i < n;++i)
    if (v[i] < v[min]) min = i;
  // Coloca o menor elemento na posicao correta.
  t = v[0];
  v[0] = v[min];
  v[min] = t;
  // Ordena elementos restantes
  for (i = 2;i < n;++i) {
    j = i;
    t = v[i];
    // Joga todos os valores que estao antes de
    // de v[i] e sao maiores que ele para frente
    // no vetor.
    while (t < v[j-1]) {
      v[j] = v[j-1];
      j--;
    }
    v[j] = t;
  }
}

void InverteVetor(float v[], int n) {
  int i, j;
  float t;
  int metade = n / 2;
  // Percorre ate a metade trocando os valores.
  for (int i = 0;i < metade;++i) {
    t = v[i];
    v[i] = v[n-1-i];
    v[n-1-i] = t;
  }
}
