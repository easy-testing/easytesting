// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_CLASSES_SRC_PONTO_H_
#define TRUNK_CLASSES_SRC_PONTO_H_

// Representa um ponto no espaço euclidiano.
// Um ponto é definido por suas coordenadas x e y.
class Ponto {
 public:
  // Cria um ponto com coordenadas (0.0, 0.0).
  Ponto();

  // Cria um ponto com coordenadas (x, y).
  Ponto(float x, float y);

  // Retorna a coordenada x do ponto.
  float x();

  // Retorna a coordenada y do ponto.
  float y();

  // Faz com que o ponto corrente fique igual a p.
  void operator=(Ponto p);

  // Retorna a distância euclidiana entre o ponto corrente e p.
  float distancia(Ponto p);

 private:
  float x_;
  float y_;
};

#endif  // TRUNK_CLASSES_SRC_PONTO_H_
