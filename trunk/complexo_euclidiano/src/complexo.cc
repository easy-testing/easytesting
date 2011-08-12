// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "complexo_euclidiano/src/complexo.h"

#include <math.h>

Complexo::Complexo() {
  real_ = 0.0;
  imag_ = 0.0;
}

Complexo::Complexo(double a) {
  real_ = a;
  imag_ = 0.0;
}

Complexo::Complexo(double a, double b) {
  real_ = a;
  imag_ = b;
}

double Complexo::real() {
  return real_;
}

double Complexo::imag() {
  return imag_;
}

bool Complexo::operator==(Complexo x) {
  // TODO.
}

void Complexo::operator=(Complexo x) {
  // TODO.
}

double Complexo::modulo() {
  // TODO.
}

Complexo Complexo::conjugado() {
  // TODO.
}

Complexo Complexo::simetrico() {
  // TODO.
}

Complexo Complexo::inverso() {
  // TODO.
}

Complexo Complexo::operator+(Complexo y) {
  // TODO.
}

Complexo Complexo::operator-(Complexo y) {
  // TODO.
}

Complexo Complexo::operator*(Complexo y) {
  // TODO.
}

Complexo Complexo::operator/(Complexo y) {
  // TODO.
}
