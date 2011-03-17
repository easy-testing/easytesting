// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
#include "easytesting/complexo/src/complexo.h"

#include <math.h>

Complexo::Complexo() {
  Atribuir(0.0, 0.0);
}

Complexo::Complexo(float a) {
  Atribuir(a, 0.0);
}

Complexo::Complexo(float a, float b) {
  Atribuir(a, b);
}

float Complexo::real() {
  return real_;
}

float Complexo::imag() {
  return imag_;
}

void Complexo::Atribuir(float a, float b) {
  real_ = a;
  imag_ = b;
}

bool Complexo::igual(Complexo x) {
  return real_ == x.real_ && imag_ == x.imag_;
}

float Complexo::modulo() {
  return sqrt(real_*real_ + imag_*imag_);
}

void Complexo::Igualar(Complexo x) {
  Atribuir(x.real_, x.imag_);
}

void Complexo::Conjugar(Complexo x) {
  Atribuir(x.real_, -x.imag_);
}

void Complexo::Inverter(Complexo x) {
  float mod2 = pow(x.modulo(), 2.0);
  Atribuir(x.real_ / mod2, -x.imag_ / mod2);
}

void Complexo::Somar(Complexo x, Complexo y) {
  Atribuir(x.real_ + y.real_, x.imag_ + y.imag_);
}

void Complexo::Subtrair(Complexo x, Complexo y) {
  Atribuir(x.real_ - y.real_, x.imag_ - y.imag_);
}

void Complexo::Multiplicar(Complexo x, Complexo y) {
  Atribuir(x.real_*y.real_ - x.imag_*y.imag_,
           x.imag_*y.real_ - x.real_*y.imag_);
}

void Complexo::Dividir(Complexo x, Complexo y) {
  Complexo inverso_y;
  inverso_y.Inverter(y);
  Multiplicar(x, inverso_y);
}
