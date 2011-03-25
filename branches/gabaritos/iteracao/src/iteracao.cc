// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "iteracao/src/iteracao.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
  int f = 1;
  while (n > 1) {
    f = f * n;
    n = n - 1;
  }
  return f;
}

int pow(int k, int n) {
  int p = 1;
  while (n > 0) {
    p *= k;
    n--;
  }
  return p;
}

int mdc(int a, int b) {
  int r = a%b;
  while (r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

int mdc3(int a, int b, int c) {
  return mdc(mdc(a, b), c);
}

int mmc(int a, int b) {
  return (a * b) / mdc(a, b);
}

int fib(int n) {
  if (n <= 1) {
    return n;
  } else {
      int a = 0;
      int b = 1;
      int c;
      for (int i = 2; i <= n ; i++) {
         c = a + b;
         a = b;
         b = c;
      }
      return c;
  }
}

int resto(int a, int b) {
  while (a >= b) {
    a = a - b;
  }
  return a;
}

int div_(int a, int b) {
  int soma = 0;
  while (a >= b) {
    a = a - b;
    soma++;
  }
  return soma;
}

int dig(int n) {
  int soma = 0;
  while (n > 0) {
    soma = soma + n % 10;
    n = n / 10;
  }
  return soma;
}

bool primo(int n) {
  if (n < 2) {
    return false;
  } else {
      for (int i = 2; i < n; i++) {
         if (n % i == 0) {
            return false;
         }
      }
      return true;
  }
}

double sqrt_(double n) {
  double x = n;
  while (fabs(x * x - n) >= 0.001) {
    x = x - (x * x - n) / (2 * x);
  }
  return x;
}
