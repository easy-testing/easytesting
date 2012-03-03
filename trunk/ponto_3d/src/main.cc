// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include <cmath>
#include <fstream>
#include <iostream>

#include "ponto_3d/src/ponto_3d.h"

using namespace std;

int main() {
  ifstream fin("entrada.txt");
  int n;
  fin >> n;
  Ponto3D* pontos = new Ponto3D[n];
  double x, y, z;
  for (int i = 0; i < n; i++) {
    fin >> x >> y >> z;
    pontos[i] = Ponto3D(x, y, z);
  }
  char operacao;
  while (fin >> operacao) {
    if (operacao == 'T') {
      double dx, dy, dz;
      fin >> dx >> dy >> dz;
      for (int i = 0; i < n; i++) {
        pontos[i].Transladar(dx, dy, dz);
      }
    } else if (operacao == 'E') {
      double fx, fy, fz;
      fin >> fx >> fy >> fz;
      for (int i = 0; i < n; i++) {
        pontos[i].MudarEscala(fx, fy, fz);
      }
    } else {  // operacao == 'R'
      double graus;
      char eixo;
      fin >> eixo  >> graus;
      double ang = (graus * M_PI) / 180;
      for (int i = 0; i < n; i++) {
        if (eixo == 'X') {
          pontos[i].RotacionarX(ang);
        } else if (eixo == 'Y') {
          pontos[i].RotacionarY(ang);
        } else {  // eixo == 'Z'
          pontos[i].RotacionarZ(ang);
        }
      }
    }
  }
  ofstream fout("saida.txt");
  fout << n << endl;
  for (int i = 0; i < n; i++) {
    fout << pontos[i].x() << " "
         << pontos[i].y() << " "
         << pontos[i].z() << endl;
  }
  delete [] pontos;
  return 0;
}
