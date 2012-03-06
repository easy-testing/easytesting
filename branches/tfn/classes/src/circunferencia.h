// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_CLASSES_SRC_CIRCUNFERENCIA_H_
#define TRUNK_CLASSES_SRC_CIRCUNFERENCIA_H_

#include "classes/src/ponto.h"
#include "classes/src/retangulo.h"
#include "classes/src/triangulo.h"

// Representa uma circunferência no espaco euclidiano.
// A circunferência é definida pelo seu ponto central e o valor do raio.
class Circunferencia {
 public:
  // Constrói uma circunferência de raio 'r' e centro p.
  Circunferencia(float r, Ponto p);

  // Retorna o perímetro da circunferência.
  float perimetro();

  // Retorna a área da circunferência.
  float area();

  // Faz com que a circunferência corrente fique igual a c.
  void operator=(Circunferencia c);

  // Testa se o ponto 'p' está dentro da circunferência.
  bool contem(Ponto p);

  // Testa se o triângulo 't' está dentro da circunferência.
  bool contem(Triangulo t);

  // Testa se o retângulo 'r' está dentro da circunferência.
  bool contem(Retangulo r);

  // Testa se o ponto 'p' está na linha definida pela circunferência.
  bool pertence(Ponto p);

  // Testa se a circunferência é circunscrita ao triângulo t.
  bool circunscrita(Triangulo t);

  // Testa se a circunferência é circunscrita ao retângulo r.
  bool circunscrita(Retangulo r);

 private:
  float raio_;
  Ponto centro_;
};
#endif  // TRUNK_CLASSES_SRC_CIRCUNFERENCIA_H_
