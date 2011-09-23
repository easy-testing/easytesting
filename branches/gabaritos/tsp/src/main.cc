#include <iostream>

#include "tsp/src/tsp.h"

using namespace std;

int main() {
    TSPSolver solver("cidades_15.txt");
    solver.Run();
    solver.PrintBestTour();
    return 0;
}
