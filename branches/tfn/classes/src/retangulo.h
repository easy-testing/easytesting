// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_CLASSES_SRC_RETANGULO_H_
#define TRUNK_CLASSES_SRC_RETANGULO_H_

#include "classes/src/ponto.h"
#include "classes/src/triangulo.h"

// Representa um retângulo no espaço euclidiano.
// Um retângulo é definido pelo seu ponto superior esquerdo e seu ponto
// inferior direito.
struct Retangulo {
 public:
  // Cria um retângulo com extremos se e id.
  Retangulo(Ponto se, Ponto id);

  // Retorna o perímetro do retângulo r.
  float perimetro();

  // Retorna a área do retângulo r.
  float area();

  // Retorna o ponto superior esquerdo do retangulo.
  Ponto se();

  // Retorna o ponto inferior direito do retangulo.
  Ponto id();

  // Retorna o ponto superior direiro do retangulo.
  Ponto sd();

  // Retorna o ponto inferior esquerdo do retangulo.
  Ponto ie();

  // Faz com que o retângulo corrente fique igual a r.
  void operator=(Retangulo r);

  // Testa se o retângulo r é um quadrado.
  bool quadrado();

  // Testa se o ponto p está dentro do retângulo r.
  bool contem(Ponto p);

  // Testa se o triângulo t esta dentro do retângulo r.
  bool contem(Triangulo t);

 private:
  // Ponto superior esquerdo.
  Ponto se_;

  // Ponto inferior direito.
  Ponto id_;
};
#endif  // TRUNK_CLASSES_SRC_RETANGULO_H_
