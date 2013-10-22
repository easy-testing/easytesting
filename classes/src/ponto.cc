// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "classes/src/ponto.h"

#include <math.h>

Ponto::Ponto() {
  x_ = 0.0;
  y_ = 0.0;
}

Ponto::Ponto(float x, float y) {
  x_ = x;
  y_ = y;
}

float Ponto::x() {
  return x_;
}

float Ponto::y() {
  return y_;
}
void Ponto::operator=(Ponto p) {
  x_ = p.x_;
  y_ = p.y_;
}

float Ponto::distancia(Ponto p) {
  return sqrt((x_ - p.x_) * (x_ - p.x_) + (y_ - p.y_) * (y_ - p.y_));
}

