// Algoritmos e Estruturas de Dados I
//
// Lista de exercicio sobre estruturas de dados homogenias - Vetores.

#include "vetores.h"
#include <iostream>

// Escreva um programa em C++ que le uma sequencia de numeros de um arquivo
// e armazena em um vetor. Assuma que a quantidade de numeros no arquivo
// nao ultrapassa o limite maximo de elementos do vetor (e.g. 1000).
int main() {
  FILE* arq;
  float vetor[1000];
  float num;
  int n = 0;

  arq = fopen("Numeros.txt", "r");
  while (fscanf(arq, "%f", &num) == 1) {
    vetor[n] = num;
    n++;
  }
  fclose(arq);
  //cout << n ;
}
