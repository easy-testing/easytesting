// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre algoritmos recursivos.
//
// QUESTÃO 1:
// Implemente em recursao.cc as funções descritas em recursao.h.
//
// QUESTÃO 2:
// Escreva um programa que (i) apresenta um menu com as funções que você
// programou na questão anterior e após o usuário escolher uma das funções
// (ii) lê o valor dos parâmetros e (iii) exibe o resultado da função.

#include <iostream>

#include "src/recursao.h"

using std::cin;
using std::cout;
using std::endl;

// Retorna um numero inteiro indicando a opcao escolhida pelo usuario
int LerOpcaoDoMenu() {
  int op;
  cout << "*****************************************************************";
  cout << "\n                        MENU PRINCIPAL\n";
  cout << "*****************************************************************";
  cout << "\n Opcoes:\n\n";
  cout << "1.  Fatoracao\n";
  cout << "2.  Potenciacao\n";
  cout << "3.  MMC\n";
  cout << "4.  MDC entre dois numeros\n";
  cout << "5.  MDC entre tres numeros\n";
  cout << "6.  Serie de Fibonacci\n";
  cout << "7.  Resto da Divisao\n";
  cout << "8.  Divisao Inteira\n";
  cout << "9.  Soma dos Digitos\n";
  cout << "Escolha a operacao que deseja fazer: ";
  cin >> op;
  while (op < 1 || op > 11) {
    cout << "Opcao invalida. Escolha uma das opcoes acima: ";
    cin >> op;
  }
  return op;
}

// Recebe como parâmetro a opção escolhida pelo usuário e
// após a entrada de valores, imprime o resultado desejado.
void ExecutarOperacao(int op) {
  int n;
  int k;
  int a, b, c;
  switch (op) {
    case 1:  // Fatoração
      cout << "Digite o valor de um numero para o calculo do seu fatorial: ";
      cin >> n;
      cout << "\nResposta: " << fat(n) << endl;
      break;
    case 2:  // Potenciação
      cout << "Digite o valor da base da potencia: ";
      cin >> k;
      cout << "Digite o valor do expoente da potencia: ";
      cin >> n;
      cout << "\nResposta: " << pow(k, n) << endl;
      break;
    case 3:  // MMC
      cout << "Digite o primeiro numero: ";
      cin >> a;
      cout << "Digite o segundo numero: ";
      cin >> b;
      cout << "\nResposta: " << mmc(a, b) << endl;
      break;
    case 4:  // MDC entre dois números
      cout << "Digite o primeiro numero: ";
      cin >> a;
      cout << "Digite o segundo numero: ";
      cin >> b;
      cout << "\nResposta: " << mdc(a, b) << endl;
      break;
    case 5:  // MDC entre três números
      cout << "Digite o primeiro numero: ";
      cin >> a;
      cout << "Digite o segundo numero: ";
      cin >> b;
      cout << "Digite o terceiro numero: ";
      cin >> c;
      cout << "\nResposta: " << mdc3(a, b, c) << endl;
      break;
    case 6:  // Serie de Fibonacci
      cout << "Digite o numero do termo da serie de Fibonacci: ";
      cin >> n;
      cout << "\nResposta: " << fib(n) << endl;
      break;
    case 7:  // Resto da divisão
      cout << "Digite o valor do dividendo: ";
      cin >> a;
      cout << "Digite o valor do divisor: ";
      cin >> b;
      cout << "\nResposta: " << resto(a, b) << endl;
      break;
    case 8:  // Divisão inteira
      cout << "Digite o valor do dividendo: ";
      cin >> a;
      cout << "Digite o valor do divisor: ";
      cin >> b;
      cout << "\nResposta: " << div_(a, b) << endl;
      break;
    case 9:  // Soma dos dígitos
      cout << "Digite um numero: ";
      cin >> n;
      cout << "\nResposta: " << dig(n) << endl;
      break;
  }
}

// Executa diversar funções.
int main() {
  int opcao = LerOpcaoDoMenu();
  ExecutarOperacao(opcao);
  return 0;
}

