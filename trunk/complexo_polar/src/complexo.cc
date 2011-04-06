// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "complexo_polar/src/complexo.h"

#include <math.h>

Complexo::Complexo() {
  mod_ = 0.0;
  arg_ = 0.0;
}

Complexo::Complexo(double a) {
  mod_ = a;
  arg_ = 0.0;
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
  return mod_ == x.mod_ && arg_ == x.arg_;
}

void Complexo::operator=(Complexo x) {
  mod_ = x.mod_;
  arg_ = x.arg_;
}

double Complexo::modulo() {
  return mod_;
}

Complexo Complexo::conjugado() {
  Complexo c(real(), -imag());
  return c;
}

Complexo Complexo::inverso() {
  float mod2 = modulo() * modulo();
  Complexo i(real() / mod2, -imag() / mod2);
  return i;
}

Complexo Complexo::operator+(Complexo y) {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) {
  Complexo s(real() - y.real(), imag() - y.imag());
  return s;
}

Complexo Complexo::operator*(Complexo y) {
  Complexo p(real() * y.real() - imag() * y.imag(),
             imag() * y.real() - real() * y.imag());
  return p;
}

Complexo Complexo::operator/(Complexo y) {
  Complexo q = *this * y.inverso();
  return q;
}
