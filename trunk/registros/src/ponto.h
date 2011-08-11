// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_SRC_PONTO_H_
#define REGISTROS_SRC_PONTO_H_

// Representa um ponto no espaço euclidiano.
struct Ponto {
  // Coordenadas x e y de um ponto no espaço euclidiano.
  float x;
  float y;
};

// Retorna a distância euclidiana entre o ponto p1 e o ponto p2.
float Distancia(Ponto p1, Ponto p2);

#endif  // REGISTROS_SRC_PONTO_H_
