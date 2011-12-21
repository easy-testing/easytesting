// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_RECURSAO_SRC_RECURSAO_H_
#define BRANCHES_GABARITOS_RECURSAO_SRC_RECURSAO_H_

// Retorna o valor do fatorial de n.
int fat(int n);

// Retorna k elevado a n.
int pow(int k, int n);

// Retorna o maximo divisor comum entre a e b.
int mdc(int a, int b);

// Retorna o maximo divisor comum entre a, b e c.
int mdc3(int a, int b, int c);

// Retorna o menor multiplo comum de a e b.
int mmc(int a, int b);

// Retorna o n-ésimo termo da serie de Fibonacci.
// Por exemplo: fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2, fib(4) = 3, ...
int fib(int n);

// Retorna o resto da divisao inteira de a por b.
int resto(int a, int b);

// Retorna o resultado da divisao inteira de a por b.
int div_(int a, int b);

// Retorna a soma dos digitos de um inteiro positivo n.
// Por exemplo: dig(123) retorna 6.
int dig(int n);

// Retorna verdadeiro se n eh primo e false caso contrario.
bool primo(int n);

// Retorna a raiz quadrada de n >= 1 (com precisão de 0.001).
double sqrt_(double n);

#endif  // BRANCHES_GABARITOS_RECURSAO_SRC_RECURSAO_H_
