#ifndef _H_
#define _H_

#define PI 3.1415928

#include <ostream>

using std::ostream;

// Implementa um ponto num espaco tridimensional.
class Ponto3D {
 public:
  // Cria um ponto com coordenadas (x, y, z).
  Ponto3D(float x, float y, float z);

  // Cria um ponto com as mesmas coordenadas de p.
  Ponto3D(Ponto3D& p);

  // Retorna a coordenada x do ponto.
  float x() { return v_[0]; }

  // Retorna a coordenada y do ponto.
  float y() { return v_[1]; }

  // Retorna a coordenada z do ponto.
  float z() { return v_[2]; }

  // Faz com que as coordenadas do ponto corrente sejam igual as de p.
  void operator=(Ponto3D& p);

  // Translada o ponto em qualquer dos eixos.
  void Transladar(float dx, float dy, float dz);

  // Muda a escala do ponto em qualquer dos eixos.
  void MudarEscalar(float fx, float fy, float fz);

  // Rotaciona o ponto 'ang' radianos em torno do eixo 'e'.
  // Os valores válidos para 'e' são 'X', 'Y', ou 'Z'.
  void Rotacionar(char e, float ang);

 private:
  // Rotaciona o ponto em torno do eixo x. 'rad' é dado em radianos.
  void RotacionarEmX(float rad);

  // Rotaciona o ponto em torno do eixo y. 'rad' é dado em radianos.
  void RotacionarEmY(float rad);

  // Rotaciona o ponto em torno do eixo z. 'rad' é dado em radianos.
  void RotacionarEmZ(float rad);

  // Deixa a matriz quadrada 'm'igual a uma matriz identidade.
  void Identizar(float m[4][4]);

  // Multiplina a matriz quadrada 'm' pelo vetor coluna 'v',
  // o resultado é armazenado no vetor 'u'.
  void Multiplicar(float m[4][4], float v[4], float u[4]);

  // Faz com que o vetor 'u' fique igual ao vetor 'v'.
  void Atribuir(float v[4], float u[4]);

  // Vetor coluna igual a {x, y, z, 1}.
  float v_[4];



};



#endif  // _H_
