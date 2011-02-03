// Lista de exercicio sobre estruturas de dados homogenias - Matrizes.

#ifndef MATRIZES_H_
#define MATRIZES_H_

//2. Escreva uma função que recebe uma matriz quadrada de dimensão n e que
//retorna a média dos elementos armazenados na matriz.
float media_matriz(int n, float mat[][100]);

//3. Escreva uma função que recebe uma matriz quadrada A de dimensão n e que
//transforma A em uma matriz identidade.
void identidade(int n, float A[][100]);

//4. Escreva uma função que recebe uma matriz quadrada A de dimensão n e que
//retorna uma matriz T que é a transposta de A.
void transposta(int n, float A[][100], float T[][100]);

//5. Escreva uma função que testa se uma matriz quadrada A de dimensão n é
//simétrica.
bool simetrica(int n, float A[][100]);

//6. Escreva uma função que recebe duas matrizes quadradas A e B de dimensão n
//e que retorna uma matriz S que é a soma de A e B.
void soma_matriz(int n, float A[][100], float B[][100], float S[][100]);

//7. Escreva uma função que recebe duas matrizes quadradas A e B de dimensão n
//e que retorna uma matriz P que é o produto de A e B.
void mult_matriz(int n, float A[][100], float B[][100], float P[][100]);

// Mostra os coeficientes de uma matriz na tela.
void mostra_matriz(int n,int m, float mat[][100]);

#endif // MATRIZES_H_
