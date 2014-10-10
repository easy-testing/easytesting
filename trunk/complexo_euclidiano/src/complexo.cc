// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/complexo.h"

#include <cmath>

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

double Complexo::real() const {
  return real_;
}

double Complexo::imag() const {
  return imag_;
}

bool Complexo::operator==(Complexo x) const {
  return real_ == x.real_ && imag_ == x.imag_;
}

void Complexo::operator=(Complexo x) {
  real_ = x.real_;
  imag_ = x.imag_;
}

double Complexo::modulo() const {
  return sqrt(real_*real_ + imag_*imag_);
}

Complexo Complexo::conjugado() const {
  Complexo c(real_, -imag_);
  return c;
}

Complexo Complexo::simetrico() const {
  Complexo c(-real_, -imag_);
  return c;
}

Complexo Complexo::inverso() const {
  double mod2 = modulo() * modulo();
  Complexo i(real_ / mod2, -imag_ / mod2);
  return i;
}

Complexo Complexo::operator+(Complexo y) {
  Complexo s(real_ + y.real_, (imag_ + y.imag_));
  return s;
}

Complexo Complexo::operator-(Complexo y) {
  return (*this) + y.simetrico();
}

Complexo Complexo::operator*(Complexo y) {
  Complexo p(real_ * y.real_ - imag_ * y.imag_, real_*y.imag_ + imag_*y.real_);
  return p;
}

Complexo Complexo::operator/(Complexo y) {
  return (*this) * y.inverso();
}
