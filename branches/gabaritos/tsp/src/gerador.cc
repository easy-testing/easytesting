#include <math.h>

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
  int y = (int) x * 100;
  return y / 100.0;
}

void GerarInstanciacircular(int n, float raio, vector<Cidade>* v) {
  v->resize(n);
  float passo = (2.0 * M_PI) / n;
  float angulo = 0;
  for (int i = 0; i < n; i++) {
    v->at(i).x = Trunca(raio * cos(angulo) + raio);
    v->at(i).y = Trunca(raio * sin(angulo) + raio);
    angulo = angulo + passo;
  }
}

void GravaInstancia(const vector<Cidade>& cidades, const string& nome) {
  ofstream fout(nome.c_str());
  fout << cidades.size() << endl;

  // Imprime as cidades de indice par.
  int j = 0;
  for (int i = 0; i < cidades.size(); i +=2) {
    fout << "c" << j++ << " " << cidades[i].x << " " << cidades[i].y << endl;
  }
  for (int i = 1; i < cidades.size(); i +=2) {
    fout << "c" << j++ << " " << cidades[i].x << " " << cidades[i].y << endl;
  }
}

int main() {
    cout << "Numero de pontos: ";
    int n;
    cin >> n;
    float r = 1000 / (2.0 * M_PI);  // Perímero da circunferencia igual a 1000.
    vector<Cidade> v;
    GerarInstanciacircular(n, r, &v);
    stringstream nome;
    nome << "cidades_" << n << ".txt";
    GravaInstancia(v, nome.str());
    return 0;

}
