// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_PERMUTACOES_SRC_PERMUTACOES_H_
#define BRANCHES_GABARITOS_PERMUTACOES_SRC_PERMUTACOES_H_

#include <iostream>

#include "float_vector/src/float_vector.h"

// Imprime os elementos do vetor separados por espaco.
void ImprimeVetor(FloatVector& v);

// Imprime todas as permutacoes dos elementos de 'v'
// a partir do indice 'inicio'.
void ImprimePermutacoesAux(FloatVector& v, int inicio);

// Imprime todas as permutacoes dos elementos de 'v'
void ImprimePermutacoes(FloatVector& v);

#endif  // BRANCHES_GABARITOS_PERMUTACOES_SRC_PERMUTACOES_H_

