#include "easytesting/matrizes/src//matrizes.h"

#include<stdio.h>

float media_matriz(int n, float mat[][100]) {
   float soma=0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          soma = soma + mat[i][j];
      }
   }
   return soma /(n*n);
}

void identidade(int n, float A[][100]) {
   float soma=0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         A[i][j] = 0;
      }
   }
   for (int i = 0; i < n; i++) {
      A[i][i] = 1;
   }
}

void transposta(int n, float A[][100], float T[][100]) {
   float soma=0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         T[i][j] = A[j][i];
      }
   }
}

bool simetrica(int n, float A[][100]) {
   float soma=0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if(A[i][j]!=A[j][i]) {
            return false;
         }
      }
   }
   return true;
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100]) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         S[i][j] = A[i][j] + B[i][j];
      }
   }
}

void mult_matriz(int n, float A[][100], float B[][100], float P[][100]) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         P[i][j]=0.0;
         for (int k = 0; k < n; k++) {
            P[i][j] = P[i][j] + A[i][k]*B[k][j];
         }
      }
   }
}

void mostra_matriz(int n,int m, float a[][100]) {
  // TODO(gabriel): implementar esta função.
}
