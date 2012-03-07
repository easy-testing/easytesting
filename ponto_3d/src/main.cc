// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados (TAD) - Ponto3D
//
// QUESTÃO 1:
// Implemente em ponto_3d.cc o TAD Ponto3D que está em ponto_3d.h.
//
// QUESTÃO 2:
// Utilizando o TAD Ponto3D, escreva um programa que lê de um arquivo de texto
// entrada.txt (i) o número de pontos tridimensionais,
// (ii) as coordenadas destes pontos e
// (iii) uma sequência de transformações que devem ser aplicadas a estes pontos.
// Nas linhas que especificam as transformações, T representa uma transformação
// de translação, R denota uma transformação de rotação e E se refere a uma
// transformação de mudança de escala. Para as transformações do tipo T e E são
// informados os valores dos deslocamentos ou fatores de escala para os
// eixos X, Y e Z, respectivamente. Para transformações do tipo R são
// informados o eixo de rotação (X, Y, ou Z) e o ângulo de rotação (EM GRAUS).
// Um exemplo do arquivo de entrada é apresentado a seguir.
//
// ---------------------------
// 8
// 0 0 0
// 15 0 0
// 15 15 0
// 0 15 0
// 0 0 15
// 15 0 15
// 15 15 15
// 0 15 15
// T -7.5 -7.5 0
// R Z 30
// E 3.0 3.0 3.0
// ---------------------------
//
// A saída do programa deve ser gravada no arquivo saida.txt.
// A primeira linha deste arquivo deve conter o número n de pontos
// tridimensionais. As n linhas seguintes devem conter as coordenadas dos
// pontos após todas as transformações serem executadas.
// Use três casas decimais na saída e separe as coordenadas com um único espaço.
// Um exemplo do arquivo da saída (dada a entrada acima) é apresentado a seguir.
//
// ---------------------------
// 8
// -8.236 -30.736 0.000
// 30.736 -8.236 0.000
// 8.236 30.736 0.000
// -30.736 8.236 0.000
// -8.236 -30.736 45.000
// 30.736 -8.236 45.000
// 8.236 30.736 45.000
// -30.736 8.236 45.000
// ---------------------------

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
