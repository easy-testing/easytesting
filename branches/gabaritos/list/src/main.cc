// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Listas Encadeadas.
//
// Questão 1.
// Implemente o TAD list<Type> em list.h.
//
// Questão 2.
// Escreva uam função "void Print(list& l)" que recebe uma lista como
// parâmetro e impreme na tela os elementos da lista no formato
// "[a1, a2, ..., an]".
//
// Questão 3.
// Escreva uma função "Node* MinList(list& l))" que recebe uma
// lista l como parâmetro e retorna um ponteiro para o nó que contém o menor
// elemento de l.
//
// Questão 4.
// Escreva uma função "void Sort(list* l)" que recebe uma lista l como
// parâmetro e ordena os elementos de l do menor para o maior.
//
// Questão 5.
// Escreva um programa que (i) lê uma quantidade indeterminada de números de um
// arquivo, (ii) armazena estes números em uma lista, (iii) ordena os elementos
// da lista e (iv) imprime na tela os números ordenados.
// Nota: no arquivo não existe nenhuma indicação de quantos números estão
// contidos nele.
//
// Questão 6: (DESAFIO)
// Escreva um programa que lê do teclado dois número naturais 'n' e 'd' e
// imprime na tela um número 'm' que consiste no maior número que pode ser
// obtido removendo-se 'd' dígitos de 'n'. Por exemplo, para n = 6913284587 e
// d = 7, tem-se m = 988. Calcule a complexidade assintótica no pior caso
// do seu programa utilizando vetores e utilizando listas. 'n' pode ter entre
// 1 e 10^9 dígitos.

#include "list/src/list.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Gabarito da questão 2.
// Impreme na tela os elementos da lista l no formato "[a1, a2, ..., an]".
void Print(list& l) {
  cout << "[";
  for (Node* i = l.begin(); i != l.end() ; i = i->next) {
    cout << i->key;
    if (i->next != l.end()) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

// Gabarito da questão 3.
// Retorna um ponteiro para o nó que contém o menor elemento de l.
Node* MinList(list& l) {
  Node* min = l.begin();
  for (Node* i = l.begin(); i != l.end(); i = i->next) {
    if (i->key < min->key) {
      min = i;
    }
  }
  return min;
}

// Gabarito da questão 4.
// Ordena os elementos de l do menor para o maior.
void Sort(list* l) {
  list aux(*l);
  l->clear();
  while (!aux.empty()) {
    Node* min = MinList(aux);
    l->push_back(min->key);
    aux.erase(min);
  }
}

// Gabarito da questão 5.
// Lê uma quantidade indeterminada de números de um arquivo e imprime na tela os
// números ordenados.
int Questao5() {
  ifstream fin("input.txt");
  float x;
  list l;
  while (fin >> x) {
    l.push_back(x);
  }
  Print(l);
  Sort(&l);
  Print(l);
  return 0;
}

// Gabarito da questão 6.
/////////////////////////

// Converte um caracter de '0' a '9' em um número de 0 a 9.
int Char2Int(char c) {
  return c - 48;
}

// Imprime na tela os digitos contidos em l. Por exemplo, l = [3, 7, 1]
// resulta na impressão de 371.
void ImprimeDigitos(list& l) {
  for (Node* i = l.begin(); i != l.end() ; i = i->next) {
    cout << i->key;
  }
  cout << endl;
}

// Apaga d dígitos de l de forma que o número resultante da concatenação dos
// dígitos remanescentes em l seja o maior possível. Por exemplo, para d = 7 e
// l = [6, 9, 1, 3, 2, 8, 4, 5, 8, 7] e tem-se l = [9, 8, 8].
void ApagaDigitos(int d, list* l) {
  // Para não ter que tratar as condições de contorno do primeiro e do último
  // dígito, insere o número 10 antes do primeiro e depois do último digito.
  l->push_front(10);
  l->push_back(10);
  for (Node* i = l->begin()->next; i != l->end(); i = i->next) {
    while (d > 0 && i->prev->key < i->key) {
      l->erase(i->prev);
      d--;
    }
  }
  l->pop_front();
  l->pop_back();
}

int Questao6() {
  cout << "n = ";
  string n;
  cin >> n;
  cout << "d = ";
  int d;
  cin >> d;
  list l;
  for (int i = 0; i < n.size(); i++) {
    l.push_back(Char2Int(n[i]));
  }
  ApagaDigitos(d, &l);
  ImprimeDigitos(l);
}

int main() {
  //return Questao5();
  return Questao6();
}
