
#include "tsp/src/tsp.h"

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

using namespace std;

/* FUNCOES PUBLICAS.
********************/

TSPSolver::TSPSolver(char file_name[]) {
  ifstream fin(file_name);
  fin >> num_cities_;
  // Inicializa o vetor 'cities_'.
  cities_ = new City[num_cities_];
  for (int i = 0; i < num_cities_; i++) {
    fin >> cities_[i].name >> cities_[i].x >> cities_[i].y;
  }
  // Inicializa o vetor 'best_permutation_'.
  best_permutation_ = new int[num_cities_];
  for (int i = 0; i < num_cities_; i++) {
    best_permutation_[i] = i;
  }
  best_cost_ = PermutationCost(best_permutation_);
}

float TSPSolver::PermutationCost(int p[]) {
  float cost = 0.0;
  for (int i = 0; i < num_cities_ - 1; i++) {
    cost += Distance(cities_[p[i]], cities_[p[i + 1]]);
  }
  cost += Distance(cities_[p[num_cities_ - 1]], cities_[p[0]]);
  return cost;
}

void TSPSolver::PrintTour(int p[]) {
  cout << "{";
  for (int i = 0; i < num_cities_; i++) {
    cout << cities_[p[i]].name << ", ";
  }
  cout << cities_[p[0]].name << "} = "
       << PermutationCost(p) << endl;
}

void TSPSolver::Run() {
  int* p = new int[num_cities_];
  for (int i = 0; i < num_cities_; i++) {
    p[i] = i;
  }
  Permute(p, 1);
  delete [] p;
}

TSPSolver::~TSPSolver() {
  delete [] cities_;
  delete [] best_permutation_;
}

/* FUNCOES AUXILIARES (PRIVADAS).
*********************************/

float TSPSolver::Distance(City& c1, City& c2) {
  return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
}

void TSPSolver::Swap(int& x, int& y) {
  int aux = x;
  x = y;
  y = aux;
}

void TSPSolver::Assign(int n, int v[], int u[]) {
  for (int i = 0; i < n; i++) {
    u[i] = v[i];
  }
}

void TSPSolver::Permute(int p[], int begin) {
  if(begin == num_cities_ - 1)   {
    if(PermutationCost(p) <= best_cost_) {
      Assign(num_cities_, p, best_permutation_);
      best_cost_ = PermutationCost(p);
    }
  } else {
    int* aux = new int[num_cities_];
    Assign(num_cities_ , p, aux);
    for(int i = begin; i < num_cities_; i++) {
      Swap(aux[begin], aux[i]);
      Permute(aux, begin + 1);
    }
    delete [] aux;
  }
}
