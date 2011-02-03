/*****************************************************************
* Algoritmos e Estruturas de Dados II
*
* Lista 1: Recursao
*
* Escreva as seguintes funções recursivas em C++:
*******************************************************************/

#ifndef RECURSAO_H_

#define RECURSAO_H_

// Retorna o valor do fatorial de n.
int fat(int n);

// Retorna k elevado a n.
int pow(int k, int n);

// Retorna o menor múltiplo comum de a e b.
int mmc(int a, int b);

// Retorna o máximo divisor comum entre a e b.
int mdc(int a, int b);

// Retorna o máximo divisor comum entre a, b e c.
int mdc3(int a, int b, int c);

// Retorna o n-ésimo termo da série de Fibonacci.
int fib(int n);

// Retorna o resto da divisão de a por b.
int resto(int a, int b);

// Retorna o resultado da divisão inteira de a por b.
int div_(int a, int b);

// Retorna a soma dos dígitos de um inteiro positivo n.
// Por exemplo: dig(123) retorna 6.
int dig(int n);

// Retorna a raiz quadrada de n (com precisão de 0.001).
double sqrt_(double n);

#endif  // RECURSAO_H_
