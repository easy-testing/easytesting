// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_PONTO_3D_SRC_PONTO_3D_H_
#define TRUNK_PONTO_3D_SRC_PONTO_3D_H_

#define PI 3.1415928

#include <ostream>

using std::ostream;

// Implementa um ponto num espaço tridimensional.
class Ponto3D {
 public:
  // Cria um ponto com coordenadas (0.0, 0.0, 0.0).
  Ponto3D();

  // Cria um ponto com coordenadas (x, y, z).
  Ponto3D(double x, double y, double z);

  // Retorna a coordenada x do ponto.
  double x() { return v_[0]; }

  // Retorna a coordenada y do ponto.
  double y() { return v_[1]; }

  // Retorna a coordenada z do ponto.
  double z() { return v_[2]; }

  // Faz com que as coordenadas do ponto corrente sejam iguais as de p.
  void operator=(Ponto3D p);

  // Translada o ponto em qualquer dos eixos.
  void Transladar(double dx, double dy, double dz);

  // Muda a escala do ponto em qualquer dos eixos.
  void MudarEscala(double fx, double fy, double fz);

  // Rotaciona o ponto 'rad' radianos em torno do eixo x.
  void RotacionarX(double rad);

  // Rotaciona o ponto 'rad' radianos em torno do eixo y.
  void RotacionarY(double rad);

  // Rotaciona o ponto 'rad' radianos em torno do eixo z.
  void RotacionarZ(double rad);

 private:
  // Deixa a matriz quadrada 'm'igual a uma matriz identidade.
  void Identizar(double m[4][4]);

  // Multiplina a matriz quadrada 'm' pelo vetor coluna 'v',
  // o resultado é armazenado no vetor 'u'.
  void Multiplicar(double m[4][4], double v[4], double u[4]);

  // Faz com que o vetor 'u' fique igual ao vetor 'v'.
  void Atribuir(double v[4], double u[4]);

  // Vetor coluna igual a {x, y, z, 1}.
  double v_[4];

  friend class Teste;
};

#endif  // TRUNK_PONTO_3D_SRC_PONTO_3D_H_
