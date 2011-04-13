// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.
//
// QUESTÃO 1:
// Implemente em complexo.cc as funções descritas em complexo.h.
//
// QUESTÃO 2:
// Escreva um programa que simula uma calculadora de números complexos.
// Ele deve apresentar um menu com as operações de soma, subtração,
// multiplicação, divisão, módulo e conjugado. Após o usuário escolher uma das
// funções, o programa deve ler o valor dos parâmetros e em seguida exibir o
// resultado da função.

#include <math.h>
#include <iostream>
#include <sstream>
#include "complexo/src/complexo.h"

using namespace std;

string ToString(Complexo& z) {
    stringstream output;
    output << z.real();
    if (z.imag() >= 0.0) {
      output << " + " << z.imag() << "i";
    } else {
      output << " - " << -z.imag() << "i";
    }
    return output.str();
}

int Menu() {
  const int num_op = 7;
  int op;

  cout << "                     Universidade Federal de Minas Gerais\n\n";
  cout << "\n\n                              MENU PRINCIPAL\n";
  cout << "                     Calculadora de Numeros Complexos\n\n\n";
  cout << "                              1.  Somar\n";
  cout << "                              2.  Subtrair\n";
  cout << "                              3.  Multiplicar\n";
  cout << "                              4.  Dividir\n";
  cout << "                              5.  Modulo\n";
  cout << "                              6.  Conjugado\n";
  cout << "                              7.  Sair\n\n\n";
  cout << "     Digite o numero da opcao desejada: ";
  cin >> op;
  while (!(op >= 1 && op <= num_op)) {
    cout << "     Opcao Invalida! Digite o numero da opcao desejada: ";
    cin >> op;
  }
  return op;
}

Complexo Leitura() {
  float real;
  float imag;

  cout << "Digite o valor da parte real do numero complexo: ";
  cin >> real;
  cout << "Digite o valor da parte imaginaria do numero complexo: ";
  cin >> imag;
  Complexo c(real, imag);
  return c;
}

void Resposta(Complexo c) {
  cout << "\nResposta : " << ToString(c) << "\n\n\n";
}

void Resposta(double x) {
  cout << "\nResposta : " << x << "\n\n\n";
}

void Operacao(int op) {
  Complexo c1;
  Complexo c2;
  c1 = Leitura();
  switch (op) {
    case 1: c2 = Leitura(); Resposta(c1 + c2); break;
    case 2: c2 = Leitura(); Resposta(c1 - c2); break;
    case 3: c2 = Leitura(); Resposta(c1 * c2); break;
    case 4: c2 = Leitura(); Resposta(c1 / c2); break;
    case 5: Resposta(c1.modulo()); break;
    case 6: Resposta(c1.conjugado()); break;
  }
}

int main() {
  int op = Menu();
  while (op != 7) {
    Operacao(op);
    op = Menu();
  }
  return 0;
}
