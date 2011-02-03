#include "iteracao.h"
#include <stdio.h>

// TODO(matheus): Trocar o printf por cout.
int main() {
   printf("%d\n", fat(5));
   printf("%d\n", mdc(42,24));
   printf("%d\n", mmc(5,12));
   printf("%d\n", fib(8));
   printf("%d\n", primo(5));
   printf("%d\n", resto(12, 4));
   printf("%d\n", div_(12, 4));
   printf("%f\n", sqrt_(2.0));
   printf("%d\n", dig(123));
   decrescente(5);
   crescente(4);
   return 0;
}

