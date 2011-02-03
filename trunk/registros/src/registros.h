// Lista de exercicio sobre estruturas de dados heterogeneas - Registros.

#ifndef REGISTROS_H_
#define REGISTROS_H_

// Representa um ponto no espaco euclidiano.
struct Ponto {
  // Coordenadas x e y de um ponto no espaço euclidiano.
  float x;
  float y;

  // Retorna a distancia euclidiana entre o ponto 'p' e o ponto corrente.
  float distancia(Ponto& p);

  // Redefine as coordenadas do ponto corrente para (a, b).
  void atribuir(float a, float b);
};

// Representa um triangulo no espaco euclidiano.
struct Triangulo {
  // Tres pontos que definem o triângulo.
  Ponto p1, p2, p3;

  // Retorna o perimetro do triangulo.
  float perimetro();

  // Retorna a area do triângulo.
  float area();

  // Testa se o triangulo corrente eh equilatero.
  bool equilatero();

  // Testa se o triango corrente eh semelhante a 't'.
  bool semelhante(Triangulo& t);
};

// Representa um retangulo no espaco euclidiano.
struct Retangulo {
  // Pontos superior esquerdo (se) e inferior direito (id) do retangulo.
  // Ponto se, id.
  Ponto se, id;

  // Retorna o perimetro do retangulo.
  float perimetro();

  // Retorna a area do retangulo.
  float area();

  // Testa se o retangulo corrente eh um quadrado.
  bool quadrado();

  // Testa se o ponto 'p' esta dentro do retangulo corrente.
  bool contem(Ponto& p);

  // Testa se o triangulo 't' esta dentro do retangulo corrente.
  bool contem(Triangulo& t);
};

// Representa ua circunferencia no espaco euclidiano.
struct Circunferencia {
  // A circunferencia eh definida pelo seu ponto central e o valor do raio.
  Ponto centro;
  float raio;

  static const float kPi = 3.1416;

  // Retorna o perimetro da circunferencia.
  float perimetro();

  // Retorna a area da circunferencia.
  float area();

  // Testa se o ponto 'p' esta dentro da circunferencia corrente.
  bool contem(Ponto& p);

  // Testa se o triangulo 't' esta dentro da circunferencia corrente.
  bool contem(Triangulo& t);

  // Testa se o retangulo 'r' esta dentro da circunferencia corrente.
  bool contem(Retangulo& r);

  // Testa se o ponto 'p' esta na linha definida pela circunferencia corrente.
  bool pertence(Ponto& p);

  // Testa se a circunferencia corrente eh circunscrita ao triangulo t.
  bool circunscrita(Triangulo& t);

  // Testa se a circunferencia corrente eh circunscrita ao retangulo r.
  bool circunscrita(Retangulo& r);
};

#endif  // REGISTROS_H_
