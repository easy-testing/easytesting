// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_SRC_RETANGULO_H_
#define REGISTROS_SRC_RETANGULO_H_

#include "registros/src/ponto.h"
#include "registros/src/triangulo.h"

// Representa um retângulo no espaço euclidiano.
struct Retangulo {
  // Pontos superior esquerdo (se) e inferior direito (id) do retângulo.
  // Ponto se, id.
  Ponto se, id;
};

// Retorna o perímetro do retângulo r.
float Perimetro(Retangulo r);

// Retorna a área do retângulo r.
float Area(Retangulo r);

// Testa se o retângulo r é um quadrado.
bool Quadrado(Retangulo r);

// Testa se o ponto p está dentro do retângulo r.
bool Contem(Retangulo r, Ponto p);

// Testa se o triângulo t esta dentro do retângulo r.
bool Contem(Retangulo r, Triangulo t);

#endif  // REGISTROS_SRC_RETANGULO_H_
