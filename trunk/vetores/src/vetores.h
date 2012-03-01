// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef VETORES_SRC_VETORES_H_
#define VETORES_SRC_VETORES_H_

// Calcula a média dos números de um vetor.
float Media(float v[], int n);

// Calcula a variância dos números de um vetor.
float Variancia(float v[], int n);

// Retorna o maior número de um vetor.
float Maior(float v[], int n);

// Retorna o menor número de um vetor.
float Menor(float v[], int n);

// Calcula o produto escalar dos vetores v e u.
float ProdutoEscalar(float u[], float v[], int n);

// Calcula o módulo do vetor v.
float Modulo(float v[], int n);

// Calcula o cosseno do ângulo entre dois vetores.
float CossenoVetores(float v[], float u[], int n);

// Mostra os coeficientes de um vetor na tela
// no formato {v[0], v[1], ..., v[n-1]}.
void MostraVetor(float v[], int n);

#endif  // VETORES_SRC_VETORES_H_
