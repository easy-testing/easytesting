// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "src/complexo.h"

#include <cmath>

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
  return fabs(x.mod_ - mod_) <= 1E-6 &&
         fabs(sin(x.arg_) - sin(arg_)) <= 1E-6 &&
         fabs(cos(x.arg_) - cos(arg_)) <= 1E-6;
}

void Complexo::operator=(Complexo x) {
  mod_ = x.mod_;
  arg_ = x.arg_;
}

double Complexo::modulo() {
  return mod_;
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.mod_ = mod_;
  c.arg_ = -arg_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.mod_ = mod_;
  c.arg_ = arg_ + M_PI;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.mod_ = 1.0 / mod_;
  i.arg_ = -arg_;
  return i;
}

Complexo Complexo::operator+(Complexo y) {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) {
  return *this + y.simetrico();
}

Complexo Complexo::operator*(Complexo y) {
  Complexo p;
  p.mod_ = mod_ * y.mod_;
  p.arg_ = arg_ + y.arg_;
  return p;
}

Complexo Complexo::operator/(Complexo y) {
  Complexo q;
  q.mod_ = mod_ / y.mod_;
  q.arg_ = arg_ - y.arg_;
  return q;
}
