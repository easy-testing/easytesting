// Copyright 2011 Universidade Federal de Minas Gerais

#include <iostream>
#include <sstream>

#include "tsp/src/tsp.h"

using std::cin;
using std::cout;
using std::stringstream;
using std::endl;

int main(int argc, char** argv) {
  stringstream nome;
  if (argc == 2) {
    nome << "cidades_" << argv[1] << ".txt";
  } else {
    cout << "Numero de cidades: ";
    int n;
    cin >> n;
    nome << "cidades_" << n << ".txt";
  }
  TSPSolver solver(nome.str().c_str());
  cout << "Resolvendo instancia '" << nome.str() << "'." << endl;
  solver.PrintBestTour();
  cout << "------------------------------------------------------------\n";
  solver.RunBacktracking();
  solver.PrintBestTour();
  return 0;
}
