//
// Algoritmos e Estruturas de Dados I
//
// Lista 10: Registros.
//
// Estruturas são tipo de dados criados pelo programador
// utilizados para melhorar a organização do código. É
// utilizada para unificar dados que possuem uma proximidade
// por exemplo, um aluno possui uma matrícula, seu nome e seu
// curso. Pode - se criar uma estrutura que possui um inteiro
// para armazenar sua matrícula, um char, para armazenar seu nome
// e um outro char para armazenar seu curso.
// Uma estrutura possui também seus métodos, funções que alteram
// os dados registrados na estrutura sem precisar incluí - los nos
// parâmetros. Nesse programa, entre várias estruturas a serem
// utilizadas, usaremos uma chamada Ponto, em que possui informações
// do x e y de um ponto, e possui por exemplo, o método distância, que
// calcula a distânia entre o ponto armazenado na estrutura e um outro
// dado por parâmetro.

#include "registros.h"
#include <stdio.h>

int main() {
  FILE* arq;
  Ponto bar[4000];
  char CNPJ[14];
  int num_bares = 0;
  float a , b;
  Ponto centro;
  float dist_max;

  printf("Digite as coordenadas x e y de onde voce se encontra: ");
  scanf("%f %f", &a, &b);
  centro.atribuir(a, b);
  printf("\nAgora digite a distancia maxima que esta disposta a caminhar: ");
  scanf("%f", &dist_max);

  arq = fopen("Bares.txt", "r");
  while (fscanf(arq , "%s %f %f" , CNPJ , &a , &b) == 3) {
    bar[num_bares].atribuir(a , b);
    if (dist_max >= bar[num_bares].distancia(centro)) {
      printf("CNPJ: ");
      puts(CNPJ);
    }
    num_bares++;
  }

  fclose(arq);

}
