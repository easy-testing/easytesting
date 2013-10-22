// Copyright 2011 Universidade Federal de Minas Gerais

#include <math.h>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

struct Cidade {
  string nome;
  float x;
  float y;
};

float Distancia(Cidade p1, Cidade p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Trunca 'x' na segunda casa decimal.
float Trunca(float x) {
  int y = static_cast<int>(x * 100);
  return y / 100.0;
}

void GerarInstanciacircular(int n, float raio, vector<Cidade>* v) {
  v->resize(n);
  v->at(0).x = raio;
  v->at(0).y = raio;
  float passo = (2.0 * M_PI) / (n - 1);
  float angulo = 0;
  for (int i = 1; i < n; i++) {
    v->at(i).x = Trunca(raio * cos(angulo) + raio);
    v->at(i).y = Trunca(raio * sin(angulo) + raio);
    angulo = angulo + passo;
  }
}

void GravaInstancia(const vector<Cidade>& cidades, const string& nome) {
  // Embaralha as cidades.
  vector<Cidade> rand_cidades = cidades;
  random_shuffle(rand_cidades.begin(), rand_cidades.end());

  ofstream fout(nome.c_str());
  fout << rand_cidades.size() << endl;
  for (int i = 0; i < rand_cidades.size(); i++) {
    fout << "c" << i << " "
         << rand_cidades[i].x << " "
         << rand_cidades[i].y << endl;
  }
}

int main() {
    cout << "Numero de cidades: ";
    int n;
    cin >> n;
    float r = (n - 1) * 1000 / (2.0 * M_PI);  // Perímero = a '(n - 1) * 1000'.
    vector<Cidade> v;
    GerarInstanciacircular(n, r, &v);
    stringstream nome;
    nome << "cidades_" << n << ".txt";
    GravaInstancia(v, nome.str());
    return 0;
}
