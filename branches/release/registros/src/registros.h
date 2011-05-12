// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef REGISTROS_SRC_REGISTROS_H_
#define REGISTROS_SRC_REGISTROS_H_

// Representa um ponto no espaço euclidiano.
struct Ponto {
  // Coordenadas x e y de um ponto no espaço euclidiano.
  float x;
  float y;

  // Retorna a distância euclidiana entre o ponto 'p' e o ponto corrente.
  float distancia(Ponto& p);

  // Redefine as coordenadas do ponto corrente para (a, b).
  void atribuir(float a, float b);
};

// Representa um triângulo no espaço euclidiano.
struct Triangulo {
  // Três pontos que definem o triângulo.
  Ponto p1, p2, p3;

  // Retorna o perímetro do triângulo.
  float perimetro();

  // Retorna a área do triângulo.
  float area();

  // Testa se o triângulo corrente é equilatero.
  bool equilatero();

  // Testa se o triângulo corrente é semelhante a 't'.
  bool semelhante(Triangulo& t);
};

// Representa um retângulo no espaço euclidiano.
struct Retangulo {
  // Pontos superior esquerdo (se) e inferior direito (id) do retângulo.
  // Ponto se, id.
  Ponto se, id;

  // Retorna o perímetro do retângulo.
  float perimetro();

  // Retorna a área do retângulo.
  float area();

  // Testa se o retângulo corrente é um quadrado.
  bool quadrado();

  // Testa se o ponto 'p' está dentro do retângulo corrente.
  bool contem(Ponto& p);

  // Testa se o triângulo 't' esta dentro do retângulo corrente.
  bool contem(Triangulo& t);
};

// Representa uma circunferência no espaco euclidiano.
struct Circunferencia {
  // A circunferência é definida pelo seu ponto central e o valor do raio.
  Ponto centro;
  float raio;

  static const float kPi = 3.1416;

  // Retorna o perímetro da circunferência.
  float perimetro();

  // Retorna a área da circunferência.
  float area();

  // Testa se o ponto 'p' está dentro da circunferência corrente.
  bool contem(Ponto& p);

  // Testa se o triângulo 't' está dentro da circunferência corrente.
  bool contem(Triangulo& t);

  // Testa se o retângulo 'r' está dentro da circunferência corrente.
  bool contem(Retangulo& r);

  // Testa se o ponto 'p' está na linha definida pela circunferência corrente.
  bool pertence(Ponto& p);

  // Testa se a circunferência corrente é circunscrita ao triângulo t.
  bool circunscrita(Triangulo& t);

  // Testa se a circunferência corrente é circunscrita ao retângulo r.
  bool circunscrita(Retangulo& r);
};

#endif  // REGISTROS_SRC_REGISTROS_H_
