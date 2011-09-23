// Copyright 2011 Universidade Federal de Minas Gerais

#include "tsp/src/tsp.h"

#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

/* FUNCOES PUBLICAS.
********************/

TSPSolver::TSPSolver(const char* file_name) {
  ifstream fin(file_name);
  fin >> num_cities_;
  // Inicializa o vetor 'cities_'.
  cities_ = new City[num_cities_];
  for (int i = 0; i < num_cities_; i++) {
    fin >> cities_[i].name >> cities_[i].x >> cities_[i].y;
  }
  // Inicializa o vetor 'best_permutation_'.
  best_permutation_ = new int[num_cities_];
  NearestNeighbourheuristic(best_permutation_);
  best_cost_ = PermutationCost(best_permutation_);
  smallest_distance_ = SmallestDistance();
}

float TSPSolver::PermutationCost(const int p[]) {
  float cost = 0.0;
  for (int i = 0; i < num_cities_ - 1; i++) {
    cost += Distance(cities_[p[i]], cities_[p[i + 1]]);
  }
  cost += Distance(cities_[p[num_cities_ - 1]], cities_[p[0]]);
  return cost;
}

void TSPSolver::PrintTour(const int p[]) {
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

void TSPSolver::RunBacktracking() {
  int* p = new int[num_cities_];
  for (int i = 0; i < num_cities_; i++) {
    p[i] = i;
  }
  Backtracking(p, 1, 0.0);
  delete [] p;
}

TSPSolver::~TSPSolver() {
  delete [] cities_;
  delete [] best_permutation_;
}

/* FUNCOES AUXILIARES (PRIVADAS).
*********************************/

float TSPSolver::Distance(const City& c1, const City& c2) {
  return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
}

float TSPSolver::SmallestDistance() {
  float smallest = Distance(cities_[0], cities_[1]);
  for (int i = 0; i < num_cities_ - 1; i++) {
    for (int j = i + 1; j < num_cities_; j++) {
      if (Distance(cities_[i], cities_[j]) < smallest) {
        smallest = Distance(cities_[i], cities_[j]);
        cout << smallest_distance_ << endl;
      }
    }
  }
  return smallest;
}

void TSPSolver::Swap(int& x, int& y) {
  int aux = x;
  x = y;
  y = aux;
}

void TSPSolver::Assign(int n, const int v[], int* u) {
  for (int i = 0; i < n; i++) {
    u[i] = v[i];
  }
}

void TSPSolver::Permute(const int p[], int begin) {
  if (begin == num_cities_ - 1)   {
    if (PermutationCost(p) <= best_cost_) {
      Assign(num_cities_, p, best_permutation_);
      best_cost_ = PermutationCost(p);
      PrintBestTour();
    }
  } else {
    int* aux = new int[num_cities_];
    Assign(num_cities_ , p, aux);
    for (int i = begin; i < num_cities_; i++) {
      Swap(aux[begin], aux[i]);
      Permute(aux, begin + 1);
    }
    delete [] aux;
  }
}

void TSPSolver::Backtracking(const int p[], int begin, float acc_cost) {
  // Retorna se o custo acumulado for maior do que o custo do melhor ciclo.
  if (acc_cost + (smallest_distance_ * (num_cities_ - begin + 1)) >=
      best_cost_) {
    return;
  }

  if (begin == num_cities_ - 1)   {
    if (PermutationCost(p) <= best_cost_) {
      Assign(num_cities_, p, best_permutation_);
      best_cost_ = PermutationCost(p);
    }
  } else {
    int* aux = new int[num_cities_];
    Assign(num_cities_ , p, aux);
    for (int i = begin; i < num_cities_; i++) {
      Swap(aux[begin], aux[i]);
      Backtracking(
          aux,
          begin + 1,
          acc_cost + Distance(cities_[aux[begin]], cities_[aux[begin - 1]]));
    }
    delete [] aux;
  }
}

void TSPSolver::NearestNeighbourheuristic(int p[]) {
  for (int i = 0; i < num_cities_; i++) {
    p[i] = i;
  }
  for (int i = 1; i < num_cities_ - 1; i++) {
    for (int j = i + 1; j < num_cities_; j++) {
      if (Distance(cities_[p[j]], cities_[p[i - 1]]) <
          Distance(cities_[p[i]], cities_[p[i - 1]])) {
        Swap(p[i], p[j]);
      }
    }
  }
}
