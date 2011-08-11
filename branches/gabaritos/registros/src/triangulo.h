// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_SRC_TRIANGULO_H_
#define REGISTROS_SRC_TRIANGULO_H_

#include "registros/src/ponto.h"

// Representa um triângulo no espaço euclidiano.
struct Triangulo {
  // Três pontos que definem o triângulo.
  Ponto p1, p2, p3;
};

// Retorna o perímetro do triângulo.
float Perimetro(Triangulo t);

// Retorna a área do triângulo.
float Area(Triangulo t);

// Testa se o triângulo corrente é equilatero.
bool Equilatero(Triangulo t);

// Testa se o triângulo t1 é semelhante a t2.
bool Semelhante(Triangulo t1, Triangulo t2);

#endif  // REGISTROS_SRC_TRIANGULO_H_
