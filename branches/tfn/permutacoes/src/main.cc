// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <iostream>

#include "float_vector/src/float_vector.h"
#include "permutacoes/src/permutacoes.h"

using std::cin;

int main() {
    int n;
    cin >> n;
    FloatVector v(n);
    for (int i = 0; i < n; i++) {
      v[i] = i;
    }
    ImprimePermutacoes(v);
    return 0;
}
