#include "matrizes.h"
#include <stdio.h>

//1. Escreva um programa que l� de um arquivo o n�mero de linhas, o n�mero de
//colunas e todos os coeficientes de uma matriz.
int main(void)
{
   FILE* f = fopen("matriz.txt", "r");
   float matPrincipal[100][100];
   int n;
   fscanf(f, "%d", &n);
   int m;
   fscanf(f, "%d", &m);
   for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         fscanf(f, "%f", &matPrincipal[i][j]);
      }
   }
   fclose(f);
   printf("Matriz principal: \n");
   mostra_matriz(n, m, matPrincipal);
   /* Fim da quest�o 1 */

   //Testando a quest�o 2
   printf("Media = %f\n", media_matriz(n, matPrincipal));

   //Testando a quest�o 3
   float matIdentidade[100][100];
   identidade(n, matIdentidade);
   printf("Identidade: \n");
   mostra_matriz(n, m, matIdentidade);

   //Testando a quest�o 4
   float matTransposta[100][100];
   transposta(n, matPrincipal, matTransposta);
   printf("Transposta: \n");
   mostra_matriz(n, m, matTransposta);

   //Testando a quest�o 5
   if(simetrica(n, matPrincipal)) {
      printf("A matriz lida do arquivo eh simetrica\n");
   } else {
      printf("A matriz lida do arquivo nao eh simetrica\n");
   }

   //Testando a quest�o 6
   float matSoma[100][100];
   soma_matriz(n, matPrincipal, matTransposta, matSoma);
   printf("Soma: \n");
   mostra_matriz(n, m, matSoma);

   //Testando a quest�o 7
   float matProduto[100][100];
   mult_matriz(n, matPrincipal, matTransposta, matProduto);
   printf("Produto: \n");
   mostra_matriz(n, m, matProduto);
   return 0;
}

