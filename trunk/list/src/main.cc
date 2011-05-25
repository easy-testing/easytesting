// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Listas Encadeadas.
//
// Questão 1.
// Implemente o TAD list<Type> em list.h.
//
// Questão 2.
// Escreva uam função "void Print(list<float>& l)" que recebe uma lista como
// parâmetro e impreme na tela os elementos da lista no formato
// "[a1, a2, ..., an]".
//
// Questão 3.
// Escreva uma função "Node<float>* MinList(list<float>& l))" que recebe uma
// lista l como parâmetro e retorna um ponteiro para o nó que contém o menor
// elemento de l.
//
// Questão 4.
// Escreva uma função "void Sort(list<float>* l)" que recebe uma lista l como
// parâmetro e ordena os elementos de l do menor para o maior.
//
// Questão 5.
// Escreva um programa que (i) lê uma quantidade indeterminada de números de um
// arquivo, (ii) armazena estes números em uma lista, (iii) ordena os elementos
// da lista e (iv) imprime na tela os números ordenados.
// Nota: no arquivo não existe nenhuma indicação de quantos números estão
// contidos nele.

#include "list/src/list.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Impreme na tela os elementos da lista l no formato "[a1, a2, ..., an]".
void Print(list<float>& l) {
  cout << "[";
  for (Node<float>* i = l.begin(); i != l.end() ; i = i->next) {
    cout << i->key;
    if (i->next != l.end()) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

// Retorna um ponteiro para o nó que contém o menor elemento de l.
Node<float>* MinList(list<float>& l) {
  Node<float>* min = l.begin();
  for (Node<float>* i = l.begin(); i != l.end(); i = i->next) {
    if (i->key < min->key) {
      min = i;
    }
  }
  return min;
}

// Ordena os elementos de l do menor para o maior.
void Sort(list<float>* l) {
  list<float> aux(*l);
  l->clear();
  while (!aux.empty()) {
    Node<float>* min = MinList(aux);
    l->push_back(min->key);
    aux.erase(min);
  }
}

// Lê uma quantidade indeterminada de números de um e imprime na tela os
// números ordenados.
int main() {
  ifstream fin("input.txt");
  float x;
  list<float> l;
  while (fin >> x) {
    l.push_back(x);
  }
  Print(l);
  Sort(&l);
  Print(l);
  return 0;
}
