// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "classes/src/retangulo.h"

#include "classes/src/ponto.h"
#include "classes/src/triangulo.h"

Retangulo::Retangulo(Ponto se, Ponto id) {
  se_ = se;
  id_ = id;
}

Ponto Retangulo::se() {
  return se_;
}

Ponto Retangulo::id() {
  return id_;
}

Ponto Retangulo::sd() {
  return Ponto(id_.x(), se_.y());
}

Ponto Retangulo::ie() {
  return Ponto(se_.x(), id_.y());
}

void Retangulo::operator=(Retangulo r) {
  se_ = r.se_;
  id_ = r.id_;
}

float Retangulo::perimetro() {
  float d1 = se_.y() - id_.y();
  float d2 = id_.x() - se_.x();
  return 2 * d1 + 2 * d2;
}

float Retangulo::area() {
  float d1 = se_.y() - id_.y();
  float d2 = id_.x() - se_.x();
  return d1 * d2;
}

bool Retangulo::quadrado() {
  float d1 = se_.y() - id_.y();
  float d2 = id_.x() - se_.x();
  return d1 == d2;
}

bool Retangulo::contem(Ponto p) {
  return p.x() >= se_.x() &&
         p.y() <= se_.y() &&
         p.y() >= id_.y() &&
         p.x() <= id_.x();
}

bool Retangulo::contem(Triangulo t) {
  return contem(t.primeiro()) && contem(t.segundo()) && contem(t.terceiro());
}
