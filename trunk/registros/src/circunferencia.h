// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_SRC_CIRCUNFERENCIA_H_
#define REGISTROS_SRC_CIRCUNFERENCIA_H_

#include "registros/src/ponto.h"
#include "registros/src/retangulo.h"
#include "registros/src/triangulo.h"

// Representa uma circunferência no espaco euclidiano.
struct Circunferencia {
  // A circunferência é definida pelo seu ponto central e o valor do raio.
  float raio;
  Ponto centro;
};

// Retorna o perímetro da circunferência c.
float Perimetro(Circunferencia c);

// Retorna a área da circunferência c.
float Area(Circunferencia c);

// Testa se o ponto 'p' está dentro da circunferência c.
bool Contem(Circunferencia c, Ponto p);

// Testa se o triângulo 't' está dentro da circunferência c.
bool Contem(Circunferencia c, Triangulo t);

// Testa se o retângulo 'r' está dentro da circunferência c.
bool Contem(Circunferencia c, Retangulo r);

// Testa se o ponto 'p' está na linha definida pela circunferência c.
bool Pertence(Circunferencia c, Ponto p);

// Testa se a circunferência c é circunscrita ao triângulo t.
bool Circunscrita(Circunferencia c, Triangulo t);

// Testa se a circunferência c é circunscrita ao retângulo r.
bool Circunscrita(Circunferencia c, Retangulo r);

#endif  // REGISTROS_SRC_CIRCUNFERENCIA_H_
