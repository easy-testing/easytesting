// Copyright 2011 Matheus Pacheco
// Lista de exercícios sobre algoritmos recursivos.
//
// QUESTÃO 1:
// Implemente em recursao.cc as funções descritas em recursao.h.
//
// QUESTÃO 2:
// Escreva um programa que (i) apresenta um menu com as funções que você
// programou na questão anterior e após o usuário escolher uma das funções
// (ii) lê o valor dos parâmetros e (iii) exibe o resultado da função.

#include <stdio.h>

#include "easytesting/recursao/src/recursao.h"

// Retorna um numero inteiro indicando a opcao escolhida pelo usuario
int Menu() {
  int op;
  printf("*****************************************************************");
  printf("\n                        MENU PRINCIPAL\n");
  printf("*****************************************************************");
  printf("\n Opcoes:\n\n");
  printf("1.  Fatoracao\n");
  printf("2.  Potenciacao\n");
  printf("3.  MMC\n");
  printf("4.  MDC entre dois numeros\n");
  printf("5.  MDC entre tres numeros\n");
  printf("6.  Serie de Fibonacci\n");
  printf("7.  Resto da Divisao\n");
  printf("8.  Divisao Inteira\n");
  printf("9.  Soma dos Digitos\n");
  printf("10. Raiz Quadrada\n\n");
  printf("Escolha a operacao que deseja fazer: ");
  scanf("%d", &op);
  while (op < 1 || op > 10) {
    printf("Opcao invalida. Escolha uma das opcoes acima: ");
    scanf("%d", &op);
  }
  return op;
}

// Recebe como parametro a opcao escolhida pelo usuario e
// apos entrada de valores, imprime o resultado desejado
void Operacao(int op) {
  int n;
  int k;
  int a, b, c;
  switch (op) {
    case 1:  // Fatoracao
      printf("Digite o valor de um numero para o calculo do seu fatorial: ");
      scanf("%d", &n);
      printf("\nFatorial de %d: %d\n", n, fat(n));
      break;
    case 2:  // Potenciacao
      printf("Digite o valor da base da potencia: ");
      scanf("%d", &k);
      printf("Digite o valor do expoente da potencia: ");
      scanf("%d", &n);
      printf("\n%d elevado a %d: %d\n", k, n, pow(k, n));
      break;
    case 3:  // MMC
      printf("Digite o primeiro numero: ");
      scanf("%d", &a);
      printf("Digite o segundo numero: ");
      scanf("%d", &b);
      printf("\nMMC entre %d e %d: %d\n", a, b, mmc(a, b));
      break;
    case 4:  // MDC entre dois numeros
      printf("Digite o primeiro numero: ");
      scanf("%d", &a);
      printf("Digite o segundo numero: ");
      scanf("%d", &b);
      printf("\nMDC entre %d e %d: %d\n", a, b, mdc(a, b));
      break;
    case 5:  // MDC entre tres numeros
      printf("Digite o primeiro numero: ");
      scanf("%d", &a);
      printf("Digite o segundo numero: ");
      scanf("%d", &b);
      printf("Digite o terceiro numero: ");
      scanf("%d", &c);
      printf("\nMDC entre %d ,%d e %d: %d\n", a, b, c, mdc3(a, b, c));
      break;
    case 6:  // Serie de Fibonacci
      printf("Digite o numero do termo da serie de Fibonacci: ");
      scanf("%d", &n);
      printf("Termo numero %d da serie de Fibonacci: %d\n", n, fib(n));
      break;
    case 7:  // Resto da divisao
      printf("Digite o valor do dividendo: ");
      scanf("%d", &a);
      printf("Digite o valor do divisor: ");
      scanf("%d", &b);
      printf("Resto da divisao de %d por %d: %d\n", a, b, resto(a, b));
      break;
    case 8:  // Divisao inteira
      printf("Digite o valor do dividendo: ");
      scanf("%d", &a);
      printf("Digite o valor do divisor: ");
      scanf("%d", &b);
      printf("Valor da divisao inteira de %d por %d: %d\n", a, b, div_(a, b));
      break;
    case 9:  // Soma dos digitos
      printf("Digite um numero: ");
      scanf("%d", &n);
      printf("Soma dos algarismos de %d: %d\n", n, dig(n));
      break;
    case 10:  // Raiz quadrada
      double d;
      printf("Digite um valor para que se calcule a raiz quadrada: ");
      scanf("%lf", &d);
      printf("Raiz quadrada: %.2lf\n", sqrt_(d));
      break;
  }
}

// Executa diversar funções recursivas.
int main() {
  int opcao = Menu();
  Operacao(opcao);
  return 0;
}

