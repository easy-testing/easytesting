// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "registros/src/circunferencia.h"

#include <math.h>

#include "registros/src/ponto.h"
#include "registros/src/retangulo.h"
#include "registros/src/triangulo.h"


float Perimetro(Circunferencia c) {
  return 2 * c.raio * M_PI;
}

float Area(Circunferencia c) {
  return c.raio * c.raio * M_PI;
}

bool Contem(Circunferencia c, Ponto p) {
  return Distancia(c.centro, p) <= c.raio;
}

bool Contem(Circunferencia c, Triangulo t) {
  return Contem(c, t.p1) && Contem(c, t.p2) && Contem(c, t.p3);
}

bool Contem(Circunferencia c, Retangulo r) {
  return Contem(c, r.se) && Contem(c, r.id);
}

bool Pertence(Circunferencia c, Ponto p) {
  return Distancia(c.centro, p) == c.raio;
}

bool Circunscrita(Circunferencia c, Triangulo t) {
  return Pertence(c, t.p1) && Pertence(c, t.p2) && Pertence(c, t.p3);
}

bool Circunscrita(Circunferencia c, Retangulo r) {
  return Pertence(c, r.se) && Pertence(c, r.id);
}
