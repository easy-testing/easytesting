// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ITERACAO_SRC_ITERACAO_H_
#define TRUNK_ITERACAO_SRC_ITERACAO_H_

// Retorna o valor do fatorial de n.
int fat(int n);

// Retorna k elevado a n.
int pow(int k, int n);

// Retorna o máximo divisor comum entre a e b.
int mdc(int a, int b);

// Retorna o máximo divisor comum entre a, b e c.
int mdc3(int a, int b, int c);

// Retorna o menor múltiplo comum de a e b.
int mmc(int a, int b);

// Retorna o n-ésimo termo da serie de Fibonacci.
// Por exemplo: fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2, fib(4) = 3, ...
int fib(int n);

// Retorna o resto da divisão inteira de a por b.
int resto(int a, int b);

// Retorna o resultado da divisão inteira de a por b.
int div_(int a, int b);

// Retorna a soma dos digitos de um inteiro positivo n.
// Por exemplo: dig(123) retorna 6.
int dig(int n);

#endif  // TRUNK_ITERACAO_SRC_ITERACAO_H_
