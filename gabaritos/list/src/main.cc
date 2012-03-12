// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre listas encadeadas - lista.
//
// Questão 1.
// Implemente em list.h e list.cc o TAD list, utilizando listas encadeadas.
//
// Questão 2.
// Escreva uam função "void Print(list& l)" que recebe uma lista como
// parâmetro e imprime na tela os elementos da lista no formato
// "[a1, a2, ..., an]".
//
// Questão 3: (DESAFIO)
// Escreva um programa que lê do teclado dois número naturais 'x' e 'd' e
// imprime na tela um numero 'y' que consiste no maior número que pode ser
// obtido removendo-se 'd' dígitos de 'x'. Por exemplo, para x = 6913274589 e
// d = 7, tem-se m = 989. Calcule a complexidade assintótica no pior caso
// do seu programa utilizando vetores e utilizando listas. 'x' pode ter entre
// 1 e 10^9 dígitos, ou seja, x nao pode ser representado por uma variável
// 'int'.

#include <fstream>
#include <iostream>
#include <string>

#include "list/src/list.h"

using namespace std;

void Print(list& l) {
  cout << "[";
  for (Node* i = l.begin(); i != l.end() ; i = l.next(i)) {
    cout << l[i];
    if (l.next(i) != l.end()) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

// Questao 3.
////////////////////////////////////////////////////////////////////////////////

// Apaga d digitos de l de forma que o numero resultante da concatenacao dos
// digitos remanescentes em l seja o maior possível. Por exemplo, para d = 7 e
// l = [6, 9, 1, 3, 2, 8, 4, 5, 8, 7] e tem-se l = [9, 8, 8].
void ApagaDigitos(int d, list& l) {
  // Para nao ter que tratar as condições de contorno do primeiro e do último
  // digito, insere-se o numero 10 antes do primeiro e depois
  // do último elemento da lista.
  l.insert(l.begin(), 10);
  l.insert(l.end(), 10);
  for (Node* i = l.next(l.begin()); i != l.end(); i = l.next(i)) {
    while (d > 0 && l[l.prev(i)] < l[i]) {
      l.erase(l.prev(i));
      d--;
    }
  }
  // Apaga os dois números iguais a 10 que foram inseridos antes do primeiro
  // elemento e depois do último elemento da lista.
  l.erase(l.begin());
  l.erase(l.prev(l.end()));
}

// Converte um caracter de '0' a '9' em um numero de 0 a 9.
int Char2Int(char c) {
  return c - 48;
}

int main() {
  // Lê 'x' e 'd' do teclado.
  cout << "x = ";
  string x;
  cin >> x;
  cout << "d = ";
  int d;
  cin >> d;

  // Insere os dígitos de x numa lista.
  list l;
  for (int i = 0; i < x.size(); i++) {
    l.insert(l.end(), Char2Int(x[i]));
  }

  // Apaga os d dígitos de l.
  ApagaDigitos(d, l);

  // Imprime na tela os digitos que restaram em l.
  cout << "y = ";
  for (Node* i = l.begin(); i != l.end() ; i = l.next(i)) {
    cout << l[i];
  }
  cout << endl;
  return 0;
}

