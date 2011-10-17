// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "polinomio/src/polinomio.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// No caso de um polinomio nulo, n_ = 0 e coeficientes_ = NULL.
Polinomio::Polinomio() {
  n_ = 0;
  coeficientes_ = NULL;
}

Polinomio::Polinomio(int g) {
  n_ = g + 1;
  coeficientes_ = new float[n_];
  for (int i = 0; i < n_ - 1; i++) {
    coeficientes_[i] = 0;
  }
  coeficientes_[n_ - 1] = 1;
}

Polinomio::Polinomio(Polinomio& q) {
  coeficientes_ = new float[q.n_];
  n_ = q.n_;
  for (int i = 0; i < n_; i++) {
    coeficientes_[i] = q.coeficientes_[i];
  }
}

bool Polinomio::nulo() {
  return n_ == 0;
}

int Polinomio::grau() {
  return n_ - 1;
}

float& Polinomio::at(int i) {
  return coeficientes_[i];
}

float Polinomio::Avaliar(float x) {
  float soma = 0;
  for (int i = 0; i < n_; i++) {
    soma += coeficientes_[i] * pow(x, i);
  }
  return soma;
}

void Polinomio::Atribuir(Polinomio& q) {
  Realocar(q.n_);
  n_ = q.n_;
  for (int i = 0; i < n_; i++) {
    coeficientes_[i] = q.coeficientes_[i];
  }
}

void Polinomio::Derivar(Polinomio& q) {
  Realocar(q.n_ - 1);
  n_ = q.n_ - 1;
  for (int i = 0; i < n_; i++) {
    coeficientes_[i] = q.coeficientes_[i + 1] * (i + 1);
  }
}

void Polinomio::Integrar(Polinomio& q) {
  Realocar(q.n_ + 1);
  n_ = q.n_ + 1;
  coeficientes_[0] = 0.0;
  for (int i = 1; i < n_; i++) {
    coeficientes_[i] = q.coeficientes_[i - 1] / i;
  }
}

Polinomio::~Polinomio() {
  delete [] coeficientes_;
}

void Polinomio::Realocar(int m) {
    if (m <= n_) {
      n_ = m;
    } else {
      float* aux = new float[m];
      for (int i = 0; i < n_; i++) {
        aux[i] = coeficientes_[i];
      }
      delete [] coeficientes_;
      coeficientes_ = aux;
    }
  }
