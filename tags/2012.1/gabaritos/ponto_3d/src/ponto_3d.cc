// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "ponto_3d/src/ponto_3d.h"

#include <cmath>

Ponto3D::Ponto3D() {
  v_[0] = 0.0;
  v_[1] = 0.0;
  v_[2] = 0.0;
}

Ponto3D::Ponto3D(double x, double y, double z) {
  v_[0] = x;
  v_[1] = y;
  v_[2] = z;
}

void Ponto3D::operator=(Ponto3D p) {
  v_[0] = p.x();
  v_[1] = p.y();
  v_[2] = p.z();
}

void Ponto3D::Transladar(double dx, double dy, double dz) {
  v_[0] += dx;
  v_[1] += dy;
  v_[2] += dz;
}

void Ponto3D::MudarEscala(double fx, double fy, double fz) {
  v_[0] *= fx;
  v_[1] *= fy;
  v_[2] *= fz;
}

// O valor de v_[0] não se altera.
void Ponto3D::RotacionarX(double rad) {
  double aux = v_[1];
  v_[1] = v_[1] * cos(rad) - v_[2] * sin(rad);
  v_[2] = aux * sin(rad) + v_[2] * cos(rad);
}

// O valor de v_[1] não se altera.
void Ponto3D::RotacionarY(double rad) {
  double aux = v_[0];
  v_[0] = v_[0] * cos(rad) + v_[2] * sin(rad);
  v_[2] = -1 * aux * sin(rad) + v_[2] * cos(rad);
}

// O valor de v_[2] não se altera.
void Ponto3D::RotacionarZ(double rad) {
  double aux = v_[0];
  v_[0] = v_[0] * cos(rad) - v_[1] * sin(rad);
  v_[1] = aux * sin(rad) + v_[1] * cos(rad);
}


