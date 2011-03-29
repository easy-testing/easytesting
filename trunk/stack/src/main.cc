// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <iostream>
#include <fstream>
#include "stack/src/stack.h"

using namespace std;

// TODO(tfn): Escrever enunciado.
int main() {
  // Lê os dados de um arquivo.
  ifstream fin("input.txt");
  stack<float> pilha;
  float x;
  while (fin >> x) {
    pilha.push(x);
  }

  // Imprime-os em ordem inversa a do arquivo.
  while (!pilha.empty()) {
    cout << pilha.top() << endl;
    pilha.pop();
  }
  return 0;
}
