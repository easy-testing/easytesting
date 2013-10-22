// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "float_vector/src/float_vector.h"
#include "permutacoes/src/permutacoes.h"

using std::cout;
using std::endl;

void ImprimeVetor(FloatVector& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void Trocar(float* x, float* y) {
  float aux = *x;
  *x = *y;
  *y = aux;
}

void ImprimePermutacoesAux(FloatVector& v, int inicio) {
  if(inicio == v.size() - 1)   {
    ImprimeVetor(v);
  } else {
    FloatVector aux = v;
    for(int i = inicio; i < v.size(); i++) {
      Trocar(&aux[inicio], &aux[i]);
      ImprimePermutacoesAux(aux, inicio + 1);
    }
  }
}

void ImprimePermutacoes(FloatVector& v) {
  ImprimePermutacoesAux(v, 0);
}
