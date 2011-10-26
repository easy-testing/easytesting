// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Listas Ligadas.
//
// Questão 1.
// Implemente em list.h e list.cc o TAD list.
//
// Questão 2.
// Escreva uam funcao "void Imprimir(list& l)" que recebe uma lista como
// parametro e impreme na tela os elementos da lista no formato
// "[a1, a2, ..., an]".
//
// Questão 3.
// Escreva uma função "Node* MinList(list& l))" que recebe uma
// lista l como parametro e retorna um ponteiro para o noh que contem o menor
// elemento de l.
//
// Questão 4.
// Escreva uma funcao "void Sort(list* l)" que recebe uma lista l como
// parametro e ordena os elementos de l do menor para o maior.
//
// Questão 5.
// Escreva um programa que (i) le uma quantidade indeterminada de numeros de um
// arquivo, (ii) armazena estes numeros em uma lista, (iii) ordena os elementos
// da lista e (iv) imprime na tela os números ordenados.
// Nota: no arquivo não existe nenhuma indicação de quantos numeros estao
// contidos nele.
//
// Questão 6: (DESAFIO)
// Escreva um programa que le do teclado dois numero naturais 'x' e 'd' e
// imprime na tela um numero 'y' que consiste no maior numero que pode ser
// obtido removendo-se 'd' dígitos de 'x'. Por exemplo, para x = 6913284587 e
// d = 7, tem-se m = 988. Calcule a complexidade assintotica no pior caso
// do seu programa utilizando vetores e utilizando listas. 'x' pode ter entre
// 1 e 10^9 dígitos, ou seja, x nao pode ser representado por uma variavel
// 'int'.

#include <fstream>
#include <iostream>
#include <string>

#include "list/src/list.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Gabarito da questão 2.
// Impreme na tela os elementos da lista l no formato "[a1, a2, ..., an]".
void Imprimir(list& l) {
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
// Retorna um ponteiro para o noh que contem o menor elemento de l.
Node* MinList(list& l) {
  Node* min = l.begin();
  for (Node* i = l.begin(); i != l.end(); i = i->next) {
    if (i->key < min->key) {
      min = i;
    }
  }
  return min;
}

// Gabarito da questao 4.
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
// Le uma quantidade indeterminada de numeros de um arquivo e imprime na tela os
// numeros ordenados.
int Questao5() {
  ifstream fin("input.txt");
  float x;
  list l;
  while (fin >> x) {
    l.push_back(x);
  }
  Imprimir(l);
  Sort(&l);
  Imprimir(l);
  return 0;
}

// Gabarito da questao 6.
/////////////////////////

// Converte um caracter de '0' a '9' em um numero de 0 a 9.
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

// Apaga d digitos de l de forma que o numero resultante da concatenacao dos
// digitos remanescentes em l seja o maior possível. Por exemplo, para d = 7 e
// l = [6, 9, 1, 3, 2, 8, 4, 5, 8, 7] e tem-se l = [9, 8, 8].
void ApagaDigitos(int d, list* l) {
  // Para nao ter que tratar as condicoes de contorno do primeiro e do ultimo
  // digito, insere o numero 10 antes do primeiro e depois do ultimo digito.
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
  cout << "x = ";
  string x;
  cin >> x;
  cout << "d = ";
  int d;
  cin >> d;
  list l;
  for (int i = 0; i < x.size(); i++) {
    l.push_back(Char2Int(x[i]));
  }
  ApagaDigitos(d, &l);
  ImprimeDigitos(l);
}

int main() {
  // return Questao5();
  return Questao6();
}
