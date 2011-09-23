// Copyright 2011 Universidade Federal de Minas Gerais

#ifndef BRANCHES_GABARITOS_TSP_SRC_TSP_H_
#define BRANCHES_GABARITOS_TSP_SRC_TSP_H_

#include <iostream>
#include <string>

using std::string;

struct City {
  string name;
  float x;
  float y;
};

class TSPSolver {
 public:
  // Cria um resolvedor de TSP para a instancia contida em 'file_name'.
  explicit TSPSolver(const char* file_name);

  // Calcula o custo do ciclo definido pela permutacao 'p'.
  float PermutationCost(const int p[]);

  // Imprime o ciclo definido pela permutacao 'p' seguido do respectivo custo.
  void PrintTour(const int p[]);

  // Imprime o melhor ciclo conhecido.
  void PrintBestTour() {PrintTour(best_permutation_);}

  // Executa o algoritmo que procura o melhor ciclo.
  void Run();
  void RunBacktracking();

  // Desaloca memoria.
  ~TSPSolver();

 private:
  // Troca o conteudo de duas variaveis.
  void Swap(int& x, int& y);

  // Testa todas as permutacoes dos elementos contidos
  // a partir indice 'begin' vetor 'p'
  void Permute(const int p[], int begin);
  void Backtracking(const int p[], int begin, float acc_cost);

  // Atribui todos os 'n' elementos do vetor 'v' ao vetor 'u'.
  void Assign(int n, const int v[], int* u);

  // Calcula a distancia da cidade 'c1' para a cidade 'c2'.
  float Distance(const City& c1, const City& c2);

  // Calcula a menor distância entre duas cidades.
  float SmallestDistance();

  // Calcula um ciclo atraves da heuristica Nearest Neighbour.
  void NearestNeighbourheuristic(int p[]);

  int num_cities_;
  City* cities_;
  int* best_permutation_;
  float best_cost_;
  float smallest_distance_;
};

#endif  // BRANCHES_GABARITOS_TSP_SRC_TSP_H_

