// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Implementação do TAD list utilizando Listas Encadeadas.
//
// Questão 1.
// Implemente em list.h e list.cc o TAD list, utilizando listas encadeadas.
//
// Questão 2.
// Escreva uam função "void Print(list& l)" que recebe uma lista como
// parâmetro e imprime na tela os elementos da lista no formato
// "[a1, a2, ..., an]".
//
// Questão 3.
// Escreva uma função "node* Min(list& l))" que recebe uma
// lista l como parametro e retorna um ponteiro para o nó que contém o menor
// elemento de l.
//
// Questão 4.
// Escreva uma função "void Sort(list* l)" que recebe uma lista l como
// parametro e ordena os elementos de l do menor para o maior.
// DESAFIO: Implemente esta função em O(n*log n).
//
// Questão 5.
// Escreva um programa que (i) lê uma quantidade indeterminada de números de um
// arquivo, (ii) armazena estes numeros em uma lista, (iii) ordena os elementos
// da lista e (iv) imprime na tela os números ordenados.
//
// Questão 6: (DESAFIO)
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

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Questão 2.
////////////////////////////////////////////////////////////////////////////////

void Print(list& l) {
  cout << "[";
  for (node* i = l.begin(); i != l.end() ; i = l.next(i)) {
    cout << l.value(i);
    if (l.next(i) != l.end()) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

// Questão 3.
////////////////////////////////////////////////////////////////////////////////

node* Min(list& l) {
  node* min = l.begin();
  for (node* i = l.begin(); i != l.end(); i = l.next(i)) {
    if (l.value(i) < l.value(min)) {
      min = i;
    }
  }
  return min;
}

// Questao 4.
////////////////////////////////////////////////////////////////////////////////

void Sort(list* l) {
  list aux(*l);
  l->clear();
  while (!aux.empty()) {
    node* min = Min(aux);
    l->push_back(l->value(min));
    aux.erase(min);
  }
}

// Questao 4 (DESAFIO).
////////////////////////////////////////////////////////////////////////////////

// Recebe duas listas ordenadas l1 e l2 e retorna uma lista ordenada com todos
// os elementos de l1 e l2.
void Merge(list& l1, list& l2, list* r) {
  int n = l1.size() + l2.size();
  for (int i = 0; i < n; i++) {
    if (l1.empty()) {
      r->push_back(l2.front());
      l2.pop_front();
    } else if (l2.empty()) {
      r->push_back(l1.front());
      l1.pop_front();
    } else if (l2.front() < l1.front()) {
      r->push_back(l2.front());
      l2.pop_front();
    } else {  // l2.front() >= l1.front()
      r->push_back(l1.front());
      l1.pop_front();
    }
  }
}

void MergeSort(list* l) {
  if (l->size() > 1) {
    list v[2];
    for (int i = 0; !l->empty(); i++) {
      v[i % 2].push_back(l->front());
      l->pop_front();
    }
    MergeSort(&v[0]);
    MergeSort(&v[1]);
    Merge(v[0], v[1], l);
  }
}


// Questão 5.
////////////////////////////////////////////////////////////////////////////////

int main_questao5() {
  ifstream fin("input.txt");
  float x;
  list l;
  while (fin >> x) {
    l.push_back(x);
  }
  Print(l);
  MergeSort(&l);
  Print(l);
  return 0;
}

// Questao 6.
////////////////////////////////////////////////////////////////////////////////

// Converte um caracter de '0' a '9' em um numero de 0 a 9.
int Char2Int(char c) {
  return c - 48;
}

// Imprime na tela os digitos contidos em l. Por exemplo, l = [3, 7, 1]
// resulta na impressão de 371.
void ImprimeDigitos(list& l) {
  for (node* i = l.begin(); i != l.end() ; i = l.next(i)) {
    cout << l.value(i);
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
  for (node* i = l->next(l->begin()); i != l->end(); i = l->next(i)) {
    while (d > 0 && l->value(l->prev(i)) < l->value(i)) {
      l->erase(l->prev(i));
      d--;
    }
  }
  l->pop_front();
  l->pop_back();
}

int main_questao6() {
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
  return main_questao6();
}
