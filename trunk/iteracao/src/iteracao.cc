#include "easytesting/iteracao/src/iteracao.h"

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

int mdc (int x, int y) {
   int r = x%y ;
   while (r != 0) {
      x = y;
      y = r;
      r = x%y ;
   }
   return y;
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
      for(int i = 2; i <= n ; i++) {
         c = a + b;
         a = b ;
         b = c ;
      }
      return c ;
   }
}

bool primo(int n) {
   if (n < 2) {
      return false;
   } else {
      for (int i = 2; i < n; i++) {
         if (n % i == 0) {
            return 0;
         }
      }
      return true;
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

float sqrt_(float n) {
  float a = 0;
  float b = n;
	float m = (a + b) / 2;
	while (fabs(m*m - n) > 0.001) {
  	if (m * m > n)
      b = m;
    else
      a = m;
    m = (a + b) / 2;
  }
  return m;
}

int dig(int n) {
  int soma = 0;
	while (n > 0) {
    soma = soma + n % 10;
    n = n / 10;
  }
  return soma;
}

void decrescente(int x) {
  for (int i = x - 1; i > 0; i--) {
		printf("%d\n", i);
	}
}

void crescente(int x) {
  for (int i = 1; i <= x; i++) {
		printf("%d\n", i);
	}
}
