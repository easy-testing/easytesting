
// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef _H_
#define _H_

#include <iostream>

#include "float_vector/src/float_vector.h"

// Imprime os elementos do vetor separados por espaco.
void ImprimeVetor(FloatVector& v);

// Troca o conteudo de duas variaveis.
void Trocar(float& x, float& y);

// Imprime todas as permutacoes dos elementos de 'v'.
void ImprimePermutacoes(FloatVector& v, int inicio);

// Imprime todas as permutacoes de numero entre zero e 'n - 1'.
void ImprimePermutacoesDeNumeroMenoresQueN(int n);

#endif  // _H_

