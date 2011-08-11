// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "registros/src/retangulo.h"

#include "registros/src/ponto.h"
#include "registros/src/triangulo.h"

float Perimetro(Retangulo r) {
  float d1 = r.se.y - r.id.y;
  float d2 = r.id.x - r.se.x;
  return 2 * d1 + 2 * d2;
}

float Area(Retangulo r) {
  float d1 = r.se.y - r.id.y;
  float d2 = r.id.x - r.se.x;
  return d1 * d2;
}

bool Quadrado(Retangulo r) {
  float d1 = r.se.y - r.id.y;
  float d2 = r.id.x - r.se.x;
  return d1 == d2;
}

bool Contem(Retangulo r, Ponto p) {
  return p.x >= r.se.x &&
         p.y <= r.se.y &&
         p.y >= r.id.y &&
         p.x <= r.id.x;
}

bool Contem(Retangulo r, Triangulo t) {
  return Contem(r, t.p1) && Contem(r, t.p2) && Contem(r, t.p3);
}
