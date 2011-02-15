// Copyright 2010 Thiago Noronha

#ifndef ITERACAO_SRC_ITERACAO_H_
#define ITERACAO_SRC_ITERACAO_H_

// Retorna o valor do fatorial de n.
int fat(int n);

// Retorna k elevado a n.
int pow(int k, int n);

// Retorna o máximo divisor comum entre a e b.
int mdc(int a, int b);

// Retorna o maximo divisor comum entre a, b e c.
int mdc3(int a, int b, int c);

// Retorna o menor múltiplo comum de a e b.
int mmc(int a, int b);

// Retorna o n-esimo termo da serie de Fibonacci
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

#endif  // ITERACAO_SRC_ITERACAO_H_
