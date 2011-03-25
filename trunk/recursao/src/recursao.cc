// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "recursao/src/recursao.h"
#include <math.h>

int fat(int n) {
  if ((n == 1) or (n == 0))
    return 1;
  else
    return n * fat(n-1);
}

int pow(int k, int n) {
  if (n == 0)
    return 1;
  else
    return k * pow(k, n - 1);
}

int mdc(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return mdc(b, a%b);
}

int mdc3(int a, int b, int c) {
  return mdc(mdc(a, b), c);
}

int mmc(int a, int b) {
  return (a * b) / mdc(a, b);
}

int fib(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}


int resto(int a, int b) {
  if (a < b)
    return a;
  else
    return resto(a - b, b);
}

int div_(int a, int b) {
  if (a < b)
    return 0;
  else
    return 1 + div_(a - b, b);
}

int dig(int n) {
  if (n < 10)
    return n;
  else
    return n % 10 + dig(n / 10);
}

// Utilizado por "bool primo(int n)"
// Verifica se o resto da divisao de n por k tem resto diferente de zero
bool resto_nzero(int n, int k) {
  if (k < 2)
    return true;
  else if (n % k == 0)
    return false;
  else
    return resto_nzero(n, k - 1);
}

bool primo(int n) {
  if (n == 1)
    return false;
  else if (n == 2)
    return true;
  else
    return resto_nzero(n, n - 1);
}

double sqrt_aux(double n, double x) {
  if (fabs(x * x - n) < 0.001) {
    return x;
  } else {
    return  sqrt_aux(n, x - (x * x - n) / (2 * x));
  }
}

double sqrt_(double n) {
  return sqrt_aux(n, n);
}
