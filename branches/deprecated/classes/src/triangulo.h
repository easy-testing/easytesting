// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_CLASSES_SRC_TRIANGULO_H_
#define TRUNK_CLASSES_SRC_TRIANGULO_H_

#include "classes/src/ponto.h"

// Representa um triângulo no espaço euclidiano.
// Um triângulo é definido por três pontos.
class Triangulo {
 public:
  // Constrói um triângulo com os pontos p1, p2, p3.
  Triangulo(Ponto p1, Ponto p2, Ponto p3);

  // Retorna o primeiro ponto do triângulo.
  Ponto primeiro();

  // Retorna o segundo ponto do triângulo.
  Ponto segundo();

  // Retorna o terceiro ponto do triângulo.
  Ponto terceiro();

  // Faz com que o triângulo corrente fique igual a t.
  void operator=(Triangulo t);

  // Retorna o perímetro do triângulo.
  float perimetro();

  // Retorna a área do triângulo.
  float area();

  // Testa se o triângulo é equilatero.
  bool equilatero();

  // Testa se o triângulo corrente é semelhante a t.
  bool semelhante(Triangulo t);

 private:
  Ponto v[3];
};

#endif  // TRUNK_CLASSES_SRC_TRIANGULO_H_
