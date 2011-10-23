#include <math.h>

#include <iostream>
#include <fstream>
#include <ostream>

#include "ponto_3d/src/ponto_3d.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostream;

int main() {
  ifstream fin("entrada.txt");
  int n;
  fin >> n;
  Ponto3D* pontos = new Ponto3D[n];
  for (int i = 0; i < n; i++) {
    fin >> pontos[i].x() >> pontos[i].y() >> pontos[i].z();
  }
  char operacao;
  while (fin >> operacao) {
    if (operacao == 'T') {
      float dx, dy, dz;
      fin >> dx >> dy >> dz;
      for (int i = 0; i < n; i++) {
        pontos[i].Transladar(dx, dy, dz);
      }
    } else if (operacao == 'E') {
      float fx, fy, fz;
      fin >> fx >> fy >> fz;
      for (int i = 0; i < n; i++) {
        pontos[i].MudarEscala(fx, fy, fz);
      }
    } else {  // operacao == 'R'
      float graus;
      char eixo;
      fin >> eixo  >> graus;
      for (int i = 0; i < n; i++) {
        pontos[i].Rotacionar(eixo, (graus * M_PI) / 180);
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
