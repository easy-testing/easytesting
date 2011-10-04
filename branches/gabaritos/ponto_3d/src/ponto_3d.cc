#include "ponto_3d/src/ponto_3d.h"

#include <math.h>

#include <ostream>

Ponto3D::Ponto3D(float x, float y, float z) {
  v_[0] = x;
  v_[1] = y;
  v_[2] = z;
  v_[3] = 1;
}

Ponto3D::Ponto3D(Ponto3D& p) {
  v_[0] = p.x();
  v_[1] = p.y();
  v_[2] = p.z();
  v_[3] = 1;
}

void Ponto3D::operator=(Ponto3D& p) {
  v_[0] = p.x();
  v_[1] = p.y();
  v_[2] = p.z();
  v_[3] = 1;
}

void Ponto3D::Transladar(float dx, float dy, float dz) {
  float m[4][4];
  Identizar(m);
  m[0][3] = dx;
  m[1][3] = dy;
  m[2][3] = dz;
  float u[4];
  Multiplicar(m, v_, u);
  Atribuir(u, v_);
}

void Ponto3D::MudarEscalar(float fx, float fy, float fz) {
  float m[4][4];
  Identizar(m);
  m[0][0] = fx;
  m[1][1] = fy;
  m[2][2] = fz;
  float u[4];
  Multiplicar(m, v_, u);
  Atribuir(u, v_);
}

void Ponto3D::Rotacionar(char e, float ang) {
  if (e == 'X') {
    RotacionarEmX(ang);
  } else if (e == 'Y') {
    RotacionarEmY(ang);
  } else {  // e == 'z'
    RotacionarEmZ(ang);
  }
}

void Ponto3D::RotacionarEmX(float rad) {
  float m[4][4];
  Identizar(m);
  m[1][1] = cos(rad);
  m[1][2] = -sin(rad);
  m[2][1] = sin(rad);
  m[2][2] = cos(rad);
  float u[4];
  Multiplicar(m, v_, u);
  Atribuir(u, v_);
}

void Ponto3D::RotacionarEmY(float rad) {
  float m[4][4];
  Identizar(m);
  m[0][0] = cos(rad);
  m[0][2] = -sin(rad);
  m[2][0] = sin(rad);
  m[2][2] = cos(rad);
  float u[4];
  Multiplicar(m, v_, u);
  Atribuir(u, v_);
}

void Ponto3D::RotacionarEmZ(float rad) {
  float m[4][4];
  Identizar(m);
  m[0][0] = cos(rad);
  m[0][1] = -sin(rad);
  m[1][0] = sin(rad);
  m[1][1] = cos(rad);
  float u[4];
  Multiplicar(m, v_, u);
  Atribuir(u, v_);
}

void Ponto3D::Identizar(float m[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] = (i == j ? 1 : 0);
    }
  }
}

void Ponto3D::Multiplicar(float m[4][4], float v[4], float u[4]) {
  for (int i = 0; i < 4; i++) {
    float s = 0.0;
    for (int j = 0; j < 4; j++) {
      s += m[i][j] * v[j];
    }
    u[i] = s;
  }
}

void Ponto3D::Atribuir(float v[4], float u[4]) {
  for (int i = 0; i < 4; i++) {
    u[i] = v[i];
  }
}
