// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "classes/src/circunferencia.h"

#include <math.h>

#include "classes/src/ponto.h"
#include "classes/src/retangulo.h"
#include "classes/src/triangulo.h"

Circunferencia::Circunferencia(float r, Ponto p) {
  raio_ = r;
  centro_ = p;
}

void Circunferencia::operator=(Circunferencia c) {
  raio_ = c.raio_;
  centro_ = c.centro_;
}

float Circunferencia::perimetro() {
  return 2 * raio_ * M_PI;
}

float Circunferencia::area() {
  return raio_ * raio_ * M_PI;
}

bool Circunferencia::contem(Ponto p) {
  return centro_.distancia(p) <= raio_;
}

bool Circunferencia::contem(Triangulo t) {
  return contem(t.primeiro()) && contem(t.segundo()) && contem(t.terceiro());
}

bool Circunferencia::contem(Retangulo r) {
  return contem(r.se()) && contem(r.id());
}

bool Circunferencia::pertence(Ponto p) {
  return centro_.distancia(p) == raio_;
}

bool Circunferencia::circunscrita(Triangulo t) {
  return pertence(t.primeiro()) &&
         pertence(t.segundo()) &&
         pertence(t.terceiro());
}

bool Circunferencia::circunscrita(Retangulo r) {
  return pertence(r.se()) && pertence(r.id());
}
