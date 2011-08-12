// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "complexo_polar/src/complexo.h"

#include <math.h>

Complexo::Complexo() {
  mod_ = 0.0;
  arg_ = 0.0;
}

Complexo::Complexo(double a) {
  mod_ = fabs(a);
  arg_ = atan2(0, a);
}

Complexo::Complexo(double a, double b) {
  mod_ = sqrt(a * a + b * b);
  arg_ = atan2(b, a);
}

double Complexo::real() {
  return mod_ * cos(arg_);
}

double Complexo::imag() {
  return mod_ * sin(arg_);
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
