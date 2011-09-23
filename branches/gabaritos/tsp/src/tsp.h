
// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef _H2_
#define _H2_

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
  TSPSolver(char file_name[]);

  // Calcula o custo do ciclo definido pela permutacao 'p'.
  float PermutationCost(int p[]);

  // Imprime o ciclo definido pela permutacao 'p' seguido do respectivo custo.
  void PrintTour(int p[]);

  // Imprime o melhor ciclo conhecido.
  void PrintBestTour() {PrintTour(best_permutation_);}

  // Executa o algoritmo que procura o melhor ciclo.
  void Run();

  // Desaloca memoria.
  ~TSPSolver();

 private:
  // Troca o conteudo de duas variaveis.
  void Swap(int& x, int& y);

  // Testa todas as permutacoes dos elementos contidos
  // a partir indice 'begin' vetor 'p'
  void Permute(int p[], int begin);

  // Atribui todos os 'n' elementos do vetor 'v' ao vetor 'u'.
  void Assign(int n, int v[], int u[]);

  // Calcula a distancia da cidade 'c1' para a cidade 'c2'.
  float Distance(City& c1, City& c2);

  // Vetor de cidades.
  int num_cities_;
  City* cities_;
  int* best_permutation_;
  int best_cost_;
};

#endif  // _H2_

