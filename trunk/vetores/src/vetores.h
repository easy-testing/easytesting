// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef VETORES_SRC_VETORES_H_
#define VETORES_SRC_VETORES_H_

// Calcula a media dos numeros de um vetor.
float Media(float v[], int n);

// Calcula a variancia dos numeros de um vetor.
float Variancia(float v[], int n);

// Retorna o maior numero de um vetor.
float Maior(float v[], int n);

// Retorna o menor numero de um vetor.
float Menor(float v[], int n);

// Calcula o produto escalar dos vetores v e u.
float ProdutoEscalar(float u[], float v[], int n);

// Mostra os coeficientes de um vetor na tela
// no formato {v[0], v[1], ..., v[n-1]}.
void MostraVetor(float v[], int n);

// Calcula media ponderada de um vetor.
float MediaPonderada(float v[], float p[], int n);

// Calcula media harmonica de um vetor.
float MediaHarmonica(float v[], int n);

// Calcula media geometrica de um vetor.
float MediaGeometrica(float v[], int n);

// Calcula media quadratica de um vetor.
float MediaQuadratica(float v[], int n);

// Verifica se um vetor corresponde a uma progressao aritmetica.
bool VerificaPA(float v[], int n);

// Verifica se um vetor corresponde a uma progressao geometrica.
bool VerificaPG(float v[], int n);

// Ordena um vetor.
void OrdenaVetor(float v[], int n);

// Inverte um vetor.
void InverteVetor(float v[], int n);

#endif  // VETORES_SRC_VETORES_H_
